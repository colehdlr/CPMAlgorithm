#!/bin/bash
set -uo pipefail

# =============================================================================
# Marker / Improver Feedback Loop — Reflective Development Showcase Slides
# =============================================================================
# Two sequential claude -p calls per iteration:
#   1. Marker:   Reads slides + brief, grades against the rubric (unbiased)
#   2. Improver: Reads marker feedback, improves the slides
#
# The marker has NO knowledge of the target score — it just marks honestly.
# Stops when score >= TARGET or max iterations reached.
#
# Usage: bash orchestrate.sh [max_iterations]
# =============================================================================

PROJECT="$(cd "$(dirname "$0")" && pwd)"
MARKER_PROMPT="$PROJECT/.prompts-resolved/marker.md"
IMPROVER_PROMPT="$PROJECT/.prompts-resolved/improver.md"
RUBRIC="$PROJECT/feedback/summary.md"
ITERATIONS_DIR="$PROJECT/iterations"
LOG_FILE="$PROJECT/feedback_loop.log"

TARGET_SCORE=95
MAX_ITERATIONS=${1:-100}
MODEL="opus"

# ---------------------------------------------------------------------------
# Logging
# ---------------------------------------------------------------------------

log() {
    local msg="[$(date '+%H:%M:%S')] $*"
    echo "$msg"
    echo "$msg" >> "$LOG_FILE"
}

# ---------------------------------------------------------------------------
# Score extraction (macOS compatible — no GNU grep -P)
# ---------------------------------------------------------------------------

extract_score() {
    local score=""

    # Format: ## Overall Mark: XX / 100
    score=$(grep -i 'Overall Mark:' "$RUBRIC" 2>/dev/null \
        | sed 's/[^0-9]/ /g' \
        | awk '{for(i=1;i<=NF;i++) if($i+0==$i && $i>=0 && $i<=100) {print $i; exit}}')

    echo "${score:-0}"
}

# ---------------------------------------------------------------------------
# Save iteration artifacts
# ---------------------------------------------------------------------------

save_iteration() {
    local i=$1 score=$2
    local dir="$ITERATIONS_DIR/iter_$(printf '%02d' "$i")"
    mkdir -p "$dir"

    for f in "$PROJECT"/*.md; do
        [ -f "$f" ] && cp "$f" "$dir/" 2>/dev/null || true
    done

    # Save feedback files
    if [ -d "$PROJECT/feedback" ]; then
        cp -r "$PROJECT/feedback" "$dir/feedback" 2>/dev/null || true
    fi

    echo "$score" > "$dir/score.txt"
}

print_scores() {
    echo ""
    echo "  +-----------------+-------+"
    echo "  | Iteration       | Score |"
    echo "  +-----------------+-------+"
    for f in "$ITERATIONS_DIR"/iter_*/score.txt; do
        [ -f "$f" ] || continue
        local n=$(basename "$(dirname "$f")" | sed 's/iter_//')
        local s=$(cat "$f")
        printf "  | %-15s | %5s |\n" "Iteration $n" "$s"
    done
    echo "  +-----------------+-------+"
    echo ""
}

# ---------------------------------------------------------------------------
# JSONL parser — extracts human-readable output from stream-json
# ---------------------------------------------------------------------------

parse_jsonl() {
    while IFS= read -r line || [[ -n "$line" ]]; do
        [[ -z "$line" ]] && continue

        if ! echo "$line" | jq -e . >/dev/null 2>&1; then
            echo "$line"
            continue
        fi

        local event_type=$(echo "$line" | jq -r '.type // empty')

        case "$event_type" in
            "assistant")
                local content=$(echo "$line" | jq -r '.message.content // empty')
                if [[ -n "$content" ]]; then
                    echo "$content" | jq -r '.[] |
                        if .type == "text" then
                            .text
                        elif .type == "tool_use" then
                            ">> \(.name): \(.input | keys | join(", "))"
                        else
                            empty
                        end' 2>/dev/null || true
                fi
                ;;

            "result")
                local result=$(echo "$line" | jq -r '.result // empty')
                if [[ -n "$result" ]]; then
                    echo ""
                    echo "=== RESULT: $result"
                fi

                local input_tokens=$(echo "$line" | jq -r '.cost.inputTokens // empty')
                local output_tokens=$(echo "$line" | jq -r '.cost.outputTokens // empty')
                if [[ -n "$input_tokens" && -n "$output_tokens" ]]; then
                    echo "   Tokens: ${input_tokens} in / ${output_tokens} out"
                fi
                ;;

            "error")
                local error_msg=$(echo "$line" | jq -r '.error.message // .error // "Unknown error"')
                echo "ERROR: $error_msg"
                ;;
        esac
    done
}

# ---------------------------------------------------------------------------
# Run a claude -p call with live streamed output
# ---------------------------------------------------------------------------

run_agent() {
    local prompt_file=$1
    local label=$2

    log "  Starting $label..."

    claude -p "Read the file ${prompt_file} and follow every single instruction in it. Edit the files it tells you to edit. Be thorough. Complete the ENTIRE task before stopping." \
        --output-format stream-json \
        --verbose \
        --model "$MODEL" \
        --dangerously-skip-permissions 2>&1 | tee >(parse_jsonl)

    local exit_code=${PIPESTATUS[0]}
    if [ $exit_code -ne 0 ]; then
        log "  $label exited with code $exit_code"
        return 1
    fi

    log "  $label finished."
    return 0
}

# =============================================================================
# MAIN
# =============================================================================

echo ""
echo "============================================="
echo "  SLIDES FEEDBACK LOOP ORCHESTRATOR"
echo "============================================="
echo "  Model:          $MODEL"
echo "  Target score:   $TARGET_SCORE / 100"
echo "  Max iterations: $MAX_ITERATIONS"
echo "  Log:            $LOG_FILE"
echo "============================================="
echo ""

{
    echo ""
    echo "==========================================="
    echo "  Run started: $(date)"
    echo "==========================================="
} >> "$LOG_FILE"

mkdir -p "$ITERATIONS_DIR"

# Resolve {{PROJECT}} placeholders in prompt templates
mkdir -p "$PROJECT/.prompts-resolved"
sed "s|{{PROJECT}}|$PROJECT|g" "$PROJECT/prompts/marker.md" > "$MARKER_PROMPT"
sed "s|{{PROJECT}}|$PROJECT|g" "$PROJECT/prompts/improver.md" > "$IMPROVER_PROMPT"
log "Resolved prompt templates for $PROJECT"

# ---- Main feedback loop ----
for i in $(seq 1 "$MAX_ITERATIONS"); do

    echo ""
    log "============================================="
    log "  ITERATION $i / $MAX_ITERATIONS"
    log "============================================="

    # Clean feedback from previous iteration so marker starts fresh
    rm -rf "$PROJECT/feedback"
    mkdir -p "$PROJECT/feedback"

    # ---- PHASE 1: MARK ----
    if [ "$i" -eq 1 ]; then
        log "PHASE 1: Initial marking of slides..."
    else
        log "PHASE 1: Re-marking improved slides..."
    fi

    if ! run_agent "$MARKER_PROMPT" "Marker"; then
        log "Marker failed. Stopping."
        exit 1
    fi

    # ---- EVALUATE ----
    score=$(extract_score)
    log ""
    log ">>> ITERATION $i MARK: $score / 100 <<<"
    log ""

    save_iteration "$i" "$score"

    # Commit after marking
    cd "$PROJECT"
    git add -A
    git diff --cached --quiet || {
        git commit -m "Marker iteration $i: score $score/100"
    }

    print_scores

    if [ "$score" -ge "$TARGET_SCORE" ] 2>/dev/null; then
        echo ""
        log "============================================="
        log "  TARGET REACHED! Score: $score / 100"
        log "  Iterations: $i"
        log "============================================="
        echo ""
        exit 0
    fi

    # ---- PHASE 2: IMPROVE ----
    log "PHASE 2: Improving slides based on feedback..."
    if ! run_agent "$IMPROVER_PROMPT" "Improver"; then
        log "Improver failed. Stopping."
        exit 1
    fi

    # Commit after improving
    git add -A
    git diff --cached --quiet || {
        git commit -m "Improver iteration $i: $(date '+%Y-%m-%d %H:%M')"
    }

    log "Improvement complete. Starting next marking cycle..."
    sleep 3
done

echo ""
log "============================================="
log "  MAX ITERATIONS ($MAX_ITERATIONS) REACHED"
log "  Final score: $(extract_score) / 100"
log "============================================="
print_scores
exit 1
