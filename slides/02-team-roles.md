# Slide 2: Team Roles / Introductions

**Speaker:** Samuel | **Time:** 55 seconds

---

## On the Slide

| Name | Role | Why | Belbin Role |
|------|------|-----|-------------|
| Samuel | Dev + Scrum Master | Knowledge of team member strengths, able to delegate effectively | Co-ordinator |
| Jamie | Dev + Product Owner | Strong understanding of CPM from additional research | Specialist |
| Cole | Dev + UI | Prior RayLib experience, UX seminar attendance | Implementer |
| Hamza | Dev + QA | Critical views on projects, experienced at finding issues | Monitor Evaluator |

**RACI Matrix — WBS Packages:**

| WBS Package | Samuel | Jamie | Cole | Hamza |
|-------------|--------|-------|------|-------|
| Parser | R, A | C | I | I |
| Algorithm | C | R, A | I | C |
| Tests | R, A | C | C | C |
| Visualisation | I | I | R, A | C |
| Integration | I | C | C | R, A |

*(R = Responsible, A = Accountable, C = Consulted, I = Informed)*

**Team Contract (Day 1 verbal → documented retrospectively):**

| # | Agreement | Status by Day 2 |
|---|-----------|-----------------|
| 1 | Shared Activity struct before coding | Worked silently |
| 2 | 15-min stand-ups (3-question format) | Adapted (25 min → 12 min) |
| 3 | Kanban board, WIP limit = 1 | Worked silently |
| 4 | Pair-programming as default blocker response | Tested |
| 5 | 15-min escalation rule → round-robin | Tested |
| 6 | Cross-module testing before integration (added Day 2) | New |

**Belbin Gap:** No Completer Finisher → identified Day 2 PM → Hamza shifted to Completer Finisher mode, running full integration test suite.

---

## Speaker Notes

We allocated by strengths — I took Scrum Master knowing the team, Jamie owned the algorithm from his CPM research, Cole brought RayLib experience, Hamza was strongest at spotting cross-module issues.

Each person working where they'd succeed — McClelland's achievement motivation. It worked because our 2-day timeline made speed essential, but nobody stretches. Longer projects need rotation for growth.

My role was servant leadership — facilitating, not directing. That fit because all four were self-motivated — directive leadership would have undermined ownership. The RACI formalised accountability: Integration had three Consulted because cross-module risk sat there.

When Samuel's parser took 3× estimate, Cole absorbed some testing scope Day 2 — keeping workload equitable. And once we spotted our missing Completer Finisher, Hamza shifted to running full integration rather than just type checks.
