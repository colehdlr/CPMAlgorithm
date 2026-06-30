# Slide 3: Demonstration

**Speaker:** Cole | **Time:** 60-90 seconds

---

## On the Slide

- Screenshot of terminal output showing CPM table (ES, EF, LS, LF, float, critical path)
- Screenshot of RayLib visualisation (AON network diagram with critical path in red)
- Backup: pre-recorded screen capture if live demo fails

---

## Expected Output

```
Activity A (Requirements):   ES=0  EF=3  LS=0  LF=3   Float=0  CRITICAL
Activity B (Design):         ES=3  EF=7  LS=5  LF=9   Float=2
Activity C (Database Setup): ES=3  EF=8  LS=3  LF=8   Float=0  CRITICAL
Activity D (Frontend Dev):   ES=7  EF=13 LS=9  LF=15  Float=2
Activity E (Backend Dev):    ES=8  EF=15 LS=8  LF=15  Float=0  CRITICAL
Activity F (Integration):    ES=15 EF=18 LS=15 LF=18  Float=0  CRITICAL
Activity G (Testing):        ES=18 EF=22 LS=18 LF=22  Float=0  CRITICAL

Critical Path: A -> C -> E -> F -> G
Project Duration: 22 days
```

---

## Speaker Notes

- Run the app once on the test scenario
- Point at output: "The forward pass calculates earliest start and finish. The backward pass calculates latest start and finish. Float is the difference. Zero float = critical."
- State the critical path: "A, C, E, F, G — project duration 22 days."
- Point at the visualisation: "Critical path in red, non-critical in grey. B and D have 2 days of float."
- One PM sentence: "Float tells a project manager which activities have flexibility — B and D's resources could be reallocated to critical activities without affecting the deadline."
- If demo fails: switch to screenshot immediately. Say "We've prepared a screenshot of the output" and continue. No debugging live.

---

## DO NOT

- Explain the code
- Show source files
- Debug anything live
- Spend more than 90 seconds

---

## KSBs Signalled

- **K15** — estimation and time constraints (CPM output proves understanding)
- **S6** — managing digital projects (tool identifies scheduling constraints)
