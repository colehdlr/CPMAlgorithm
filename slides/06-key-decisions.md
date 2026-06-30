# Slide 6: Key Decisions

**Speaker:** Hamza | **Time:** 2 minutes

---

## On the Slide

| Decision | What We Did | PM Justification |
|----------|-------------|------------------|
| Struct split | Activity → Activity + CPMResult (separate input from output) | Modular decomposition — isolate parsing from calculation |
| Data format | JSON over CSV and TXT | JSON naturally represents activity-dependency relationships |
| Language | C over Python & JS (after debate) | Iron Triangle: accepted higher time cost for deeper understanding |
| Estimation | PERT formula for future extension | Three-point estimation accounts for duration uncertainty |

---

## Speaker Notes

### 1. Splitting the Activity struct

- "We separated the Activity struct into an input struct and a CPMResult output struct."
- "Before: one Activity held everything. After: Activity (input data) + CPMResult (calculated values)."
- "This meant the parser and CPM algorithm could be developed independently — modular decomposition from systems engineering."
- 30 seconds max on this.

### 2. CSV vs JSON vs TXT

- "JSON won because its nested structure naturally maps to activity-dependency relationships. CSV would need a comma-separated list inside a comma-separated file — fragile. TXT has no structure at all."
- ONE sentence. Move on.

### 3. Python & JS vs C

- "This was our biggest debate — genuine storming."
- "Strong advocacy for and against. We really had to use our team skills to reach a decision."
- "We accepted higher development time (cost) to work with explicit data structures that forced us to understand the CPM graph model deeply. That's an Iron Triangle trade-off — accepting higher cost to protect scope and quality."
- "We decided to stick with C and delegate refactors to team members who were struggling — that was our move from storming to performing."
- This transitions into slide 7 (Challenges).

### 4. PERT / Three-Point Estimation

- "Our CPM uses fixed durations. If we were extending this, we'd use:"
- **Expected time = (O + 4M + P) / 6**
- "This accounts for uncertainty in task durations — something our own sprint demonstrated when parsing took 3x longer than estimated."

---

## PM Connections

- Struct split = **modular decomposition** (WBS principle — break into smallest manageable components)
- JSON choice = **data model maps to WBS** (each activity = work package with dependencies)
- C choice = **Iron Triangle trade-off** (time vs scope/quality)
- PERT = **K15 estimation principles** (three-point estimation from Week 4)

---

## KSBs Signalled

- **K15** — estimation principles (PERT, Iron Triangle trade-offs)
- **S6** — applying appropriate PM methodologies (justified methodology decisions)
- **K8** — the C debate required effective teamwork to resolve
