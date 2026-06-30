# Criterion 1: Understanding of Estimation & Project Management Concepts (30%)

## Mark Awarded: 24 / 30

## Band: A+ (80-100)

## Rubric Band Placement

**Band above (n/a — this is the highest band):**
> N/A — A+ is the ceiling.

**Band awarded — A+ (80-100):**
> "Application demonstrates exceptional understanding of estimation or critical path; calculations/processes are accurate and well-justified."

**Band below — A (70-79):**
> "Very strong understanding. Excellent implementation of concepts and justification."

## What Earns the Mark

### CPM Algorithm Correctly Explained (Slides 3, 5)

The CPM walkthrough (Slide 5) provides a technically accurate, step-by-step explanation of the algorithm:

- **Forward pass:** "Iterates through activities in dependency order... ES = maximum EF of all predecessors (at convergence points, take the MAX)... EF = ES + duration... Project duration is set at the end of this loop — it's the largest EF value." This is correct and well-articulated.
- **Backward pass:** "Works backwards through activities... Latest Finish (LF) = looks at successor tasks and takes the minimum Latest Start... Latest Start (LS) = LF - duration." Correct.
- **Float calculation:** Both Total Float ("LS - ES... how much can I delay starting without affecting the project deadline") and Free Float ("earliest ES of successors - EF of current activity... how much can I delay finishing without affecting the next task") are distinguished and defined. This is above what most groups deliver.

The demonstration output (Slide 3) shows correct calculations:
```
Activity A: ES=0, EF=3, LS=0, LF=3, Float=0 — CRITICAL
Activity C: ES=3, EF=8, LS=3, LF=8, Float=0 — CRITICAL
Activity B: ES=3, EF=7, LS=5, LF=9, Float=2 — correctly non-critical
Critical Path: A → C → E → F → G (correct)
Project Duration: 22 days (correct: 3+5+7+3+4=22)
```

### Estimation Concepts Applied to the Project (Slides 5, 6, 7)

- **PERT formula** stated correctly: E = (O + 4M + P) / 6, with contextualisation: "This weighted average gives a more realistic duration estimate. Our architecture supports this — the duration field could be calculated from three input values instead of one." (Slide 5)
- **Iron Triangle** applied to a real decision: Jamie's scope pushback — "with time fixed, scope had to stay minimal" (Slide 4), and the C language choice — "accepted higher time cost for deeper understanding" (Slide 6).
- **WBS principle** applied: Struct split justified as "modular decomposition — isolate parsing from calculation" mapped to "break into smallest manageable components" (Slide 6).
- **Estimation failure** acknowledged with self-awareness: "We estimated based on preference ('we want to try C') rather than effort ('how long will C actually take us'). That's an estimation failure — and exactly the kind of thing three-point estimation addresses." (Slide 7)

### Justification Goes Beyond Description to "Why"

- Float interpretation: "Float tells a project manager which activities have flexibility — B and D's resources could be reallocated to critical activities without affecting the deadline." (Slide 3) — explains the PM significance, not just the calculation.
- CPM vs PERT distinction: "This is the difference between CPM (deterministic) and PERT (probabilistic)." (Slide 5)
- JSON over CSV: "JSON naturally represents activity-dependency relationships" — justified with data modelling reasoning, not just preference.

### Q&A Preparation Depth (Slide 11)

The Q&A preparation demonstrates understanding beyond what the slides present:
- Dynamic critical path analysis (what happens when B's duration increases to 7)
- Crashing analysis (targeting critical path activities by cost-per-day ratio)
- Total float vs free float distinction with network topology reasoning
- CPM-cost relationship through crashing
- CHAOS Report statistics contextualising their estimation failure

## What Holds the Mark Back

### PERT Not Actually Computed (Slide 5)

The PERT formula is presented as a "future extension" rather than being computed with real values from the project. To reach the upper A+ band (85+), the slides would need to show an actual three-point estimate applied to at least one activity (e.g., "Backend Dev: O=5, M=7, P=12, Expected = (5 + 28 + 12)/6 = 7.5 days") demonstrating not just knowledge of the formula but its practical application.

### No Formal WBS Diagram (Slide 6)

The WBS connection is implicit ("modular decomposition") rather than formally shown. To reach the upper A+ band, the slides would need a visual WBS diagram showing how the project was decomposed into work packages (parsing → algorithm → tests → visualisation), explicitly labelled as a WBS with level numbering.

### Limited Reference to Estimation Methods from Week 4 (Slides 5-6)

The slides reference Iron Triangle and PERT but do not explicitly name other estimation methods taught in Week 4 (expert judgement, analogous, parametric, bottom-up, top-down). These are discussed in the Q&A preparation but not in the main slide content. To strengthen, one slide could include: "We used expert judgement (each person estimated their own package) and bottom-up estimation (WBS decomposition into four packages, each individually estimated)."

### CHAOS Report Not Referenced in Main Slides

The Standish Group CHAOS report (Larkowski, 2003) — that 66% of software projects are considered to have failed — is taught in Week 4 and discussed in Q&A prep, but not referenced in the main slides to contextualise the team's own estimation failure.

## Actionable Improvements

1. **Slide 5 — Apply PERT with real numbers:** Add a worked example: "If we estimated Backend Dev as O=5, M=7, P=12 days, then E = (5+28+12)/6 = 7.5 days, with σ = (P-O)/6 = 1.17 days. This gives us a probabilistic range rather than our assumed 7 days." This demonstrates application, not just knowledge.

2. **Slide 4 or 6 — Add a visual WBS:** Show a 3-level WBS tree: Level 0 = CPM Application; Level 1 = Parser, Algorithm, Tests, Visualisation; Level 2 = specific tasks under each. Label it explicitly as "Work Breakdown Structure (deliverable-based)."

3. **Slide 6 — Name estimation methods used:** Add one row to the decisions table: "Estimation approach | Expert judgement + bottom-up | Each person estimated their own WBS package; combined for total project estimate."

4. **Slide 7 — Reference CHAOS Report:** When discussing the estimation failure, add: "This mirrors industry patterns — the Standish Group CHAOS report found 66% of projects fail, often due to unrealistic timelines (Larkowski, 2003). Our sprint replicated this at micro-scale."

## Conclusion

The slides demonstrate an understanding of CPM that is genuinely exceptional — the algorithm is correctly explained at a level beyond most undergraduate presentations (including free float vs total float), calculations are demonstrably accurate, and every technical decision is justified with explicit PM reasoning (Iron Triangle, modular decomposition, estimation uncertainty). The mark sits at 80% (24/30) — the lower boundary of A+ — because while the understanding and justification are clearly exceptional, the PERT formula remains theoretical rather than applied, and formal estimation methodology naming is confined to Q&A preparation rather than the presented slides. The work comfortably exceeds the A band ("very strong understanding, excellent implementation and justification") by providing deeper PM reasoning and connecting CPM to broader estimation principles.
