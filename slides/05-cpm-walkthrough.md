# Slide 5: CPM Walkthrough

**Speaker:** Jamie | **Time:** 2 minutes

---

## On the Slide

- Diagram showing forward pass → backward pass → float calculation
- The PERT formula: **Expected time = (O + 4M + P) / 6**
- Brief table showing one activity's values as example

---

## Speaker Notes

### The Algorithm

- "I started by identifying the input — activities from the parser — and the output needed for the rendering engine."
- **Forward pass (first for loop):**
  - "Iterates through activities in dependency order"
  - "Calculates Earliest Start (ES) and Earliest Finish (EF) for each task"
  - "ES = maximum EF of all predecessors (at convergence points, take the MAX)"
  - "EF = ES + duration"
  - "Project duration is set at the end of this loop — it's the largest EF value"
- **Backward pass (second for loop):**
  - "Works backwards through activities"
  - "Latest Finish (LF) = looks at successor tasks and takes the minimum Latest Start"
  - "Latest Start (LS) = LF - duration"
  - "Initialises all LF to project duration, then walks backwards"
- **Float calculation (final forward pass):**
  - "Free Float = earliest ES of successors - EF of current activity"
  - "In plain English: how much can I delay finishing without affecting the next task?"
  - "Total Float = LS - ES"
  - "In plain English: how much can I delay starting without affecting the project deadline?"
  - "Zero total float = critical activity"

### PM Connection

- "Float is what makes CPM useful to a project manager — it shows where there's flexibility. Activities with zero float are the ones that will delay the entire project if they slip."
- "B and D have 2 days of float — a PM could reallocate those resources to critical activities, or absorb a 2-day delay on those tasks without consequence."

### PERT Extension

- "Our application supports both deterministic durations and PERT three-point estimation. The user can provide optimistic, most likely, and pessimistic values, and the system calculates the expected duration using:"
- **Expected time = (O + 4M + P) / 6**
  - O = Optimistic duration
  - M = Most likely duration
  - P = Pessimistic duration
- "Take our Backend Dev activity (E) as an example. If we estimated: Optimistic = 5 days, Most Likely = 7 days, Pessimistic = 12 days. Then Expected = (5 + 28 + 12) / 6 = 7.5 days, with standard deviation σ = (12 - 5) / 6 = 1.17 days."
- "Our deterministic estimate was 7 days — slightly optimistic. That pattern played out in our actual sprint too: the parser took roughly 3x longer than our single-point estimate. Three-point estimation would have flagged that risk."
- "This is the difference between CPM (deterministic) and PERT (probabilistic). We implemented both so the user can see how uncertainty changes the critical path and project duration."

---

## KSBs Signalled

- **K15** — directly demonstrates understanding of estimation principles (three-point estimation, float, scheduling)
- **S5** — applying standard PM techniques (CPM/PERT) in a digital solution
