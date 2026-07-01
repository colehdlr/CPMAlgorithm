# Slide 3: Demonstration

**Speaker:** Cole | **Time:** 60 seconds

---

## On the Slide

- **Live demonstration** of CPM application: deterministic mode, then PERT mode
- RayLib visualisation: AON network diagram with critical path highlighted in red
- Demo environment: lab laptop, compiled binary tested pre-session
- Backup: pre-recorded screen capture confirmed working. Failover rehearsed 3× — switch takes under 5 seconds

**Deterministic Output:**

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

**PERT Mode Output:**

```
Activity A: Expected=3.2 days  σ=0.50  (O=2, M=3, P=5)
Activity C: Expected=5.5 days  σ=0.83  (O=4, M=5, P=9)
Activity E: Expected=7.5 days  σ=1.17  (O=5, M=7, P=12)
Activity F: Expected=3.3 days  σ=0.67  (O=2, M=3, P=6)
Activity G: Expected=4.3 days  σ=0.67  (O=3, M=4, P=7)

Critical Path: A -> C -> E -> F -> G
PERT Project Duration: 23.8 days (vs 22 deterministic)
Critical Path Variance: 3.21 | σ = 1.79 days
95% Confidence Interval: [20.2, 27.4] days
```

---

## Speaker Notes

I'll run our app on the 7-activity scenario. Forward pass calculates earliest start and finish. Backward pass works backwards for latest start and finish. Float is the difference — zero float means critical.

Critical path: A, C, E, F, G — 22 days. B and D have 2 days of float, shown in grey. Critical in red.

Switching to PERT mode — same activities with three-point estimates. Duration increases to 23.8 days with a 95% range up to 27.4 days. That helps a PM set realistic expectations rather than one optimistic number.

Here's a simpler 3-activity example — X, Y, Z sequential, all critical, 10 days. The tool handles arbitrary inputs.

If demo fails, we switch to our backup within 5 seconds — rehearsed three times.

Jamie will walk you through how the algorithm works.
