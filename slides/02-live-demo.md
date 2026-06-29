# Slide 2: Live Demo

**Time:** 90 seconds MAXIMUM | **Speaker:** [Speaker B]

---

## On the Slide

- Terminal screenshot or live terminal showing the app running on `activities.json`
- Output showing: ES, EF, LS, LF, float, critical path, project duration
- Interactive AON network diagram (raylib visualization from `render.c`):
  - Critical path nodes in **red** (A, C, E, F, G)
  - Non-critical nodes in **grey** (B, D)
  - Each node displays: Activity ID, name, duration, ES, EF, LS, LF, Slack
  - Pan, zoom, and reset controls
  - HUD overlay with total project duration and colour legend

---

## Expected Output to Show

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

## Speaker Script

"CPM answers a fundamental question of project success: will we deliver within the timeline? It addresses the TIME vertex of the Iron Triangle directly — by identifying the critical path, a project manager knows which activities constrain the schedule, and can then make informed trade-offs against cost and scope.

The seven activities you see correspond to a deliverable-based Work Breakdown Structure — Requirements, Design, Database Setup, Frontend, Backend, Integration, and Testing — decomposed to the work-package level that CPM requires. The WBS sets the foundation for scheduling; CPM then analyses the dependencies between those work packages.

Let me run our application on the test scenario from the brief. [Runs app.] You can see two outputs. First, the terminal shows the full CPM table — earliest start and finish, latest start and finish, float, and whether each activity is critical. Activity A has an earliest start of 0 and earliest finish of 3. When we reach activity F — Integration — notice its earliest start is 15, not 13. That is because F depends on both D and E, and E does not finish until day 15. The forward pass takes the maximum, which is the core logic of CPM at convergence points.

Second, our application opens this interactive network diagram — an Activity-on-Node representation. Critical path activities — A, C, E, F, G — are highlighted in red. B and D appear in grey with their 2 days of float. We built this because CPM is fundamentally a visual concept — it is the longest path through the network — and a project manager needs to see that path, not just read a table. The AON diagram shows dependencies and critical path — information a Gantt chart alone does not inherently reveal. In practice, both would be used together: the AON for path analysis, the Gantt for schedule communication to stakeholders.

The critical path is A, C, E, F, G. Project duration: 22 days. Activities B and D have 2 days of float — meaning a project manager could delay Design or Frontend Development by up to 2 days, or reallocate their resources to critical activities, without affecting the deadline.

In practice, a project manager would derive these durations using estimation techniques such as three-point estimation — combining optimistic, most likely, and pessimistic values — rather than single-point estimates. Our application currently uses deterministic durations, which assumes estimation has already occurred. This demonstrates K15 — understanding the principles of estimating time constraints within digital and technology solutions activities."

---

## Demo Backup Plan (CRITICAL)

Have THREE levels of fallback ready:

1. **Live demo** — run the app on the presentation machine
2. **Screen recording** — 30-second pre-recorded video of the app running
3. **Screenshot** — embedded in the slide as a static image

If live demo fails, switch IMMEDIATELY. Say: "We have prepared a recording of the application running" and continue without apology. Do NOT waste time troubleshooting.

---

## Key Points to Hit

- Run the app ONCE only
- Frame CPM within the Iron Triangle (time vertex) and project success measurement
- Mention the WBS decomposition that underpins the activity list
- Point to the convergence at activity F (ES=15 because max of D's EF=13 and E's EF=15)
- Mention the visualization shows critical path visually (red vs grey)
- Distinguish AON from Gantt — AON reveals dependencies, Gantt communicates schedule
- Connect to PM: "a project manager needs to see the path, not just read a table"
- State the critical path and duration explicitly
- Mention float means flexibility for resource reallocation
- Reference estimation methods (three-point estimation) and acknowledge deterministic assumption
- Explicitly signal K15 (estimating time constraints) and S6 (managing digital technology projects)

---

## DO NOT

- Explain the code
- Show the source files
- Debug anything live
- Spend more than 90 seconds

---

## KSBs Addressed in This Slide

| KSB | How Addressed |
|-----|---------------|
| **K15** | Directly — demo shows estimation outputs (durations, float, critical path duration) informing time planning; three-point estimation referenced |
| **S6** | Directly — demonstrates a tool for managing digital technology projects by identifying scheduling constraints |
| **S5** | Partially — demonstrates application of standard PM techniques (CPM/AON) in a digital solution |
| **B5** | Partially — presenting data concisely and truthfully through terminal output and visual diagram |
| **S15** | Partially — cycle detection and input validation apply professional standards to prevent incorrect scheduling outputs |

---

## Course Theory and References

- Iron Triangle / Triple Constraint (Week 4, Page 5): time, cost, scope trade-offs
- Work Breakdown Structure (Week 4, Pages 13-14): hierarchical decomposition to work-package level
- Three-point estimation (Week 4, Page 7): optimistic, most likely, pessimistic weighted average
- Gantt chart relationship to AON (Week 4, Pages 15-16)
- Project success measurement (Week 4, Page 5): "Is the project within the timeline?"
- Kelley, J.E. and Walker, M.R. (1959) 'Critical-path planning and scheduling', Proceedings of the Eastern Joint Computer Conference, pp. 160-173.
- Green, C. (2006) 'Estimating as an art — what it takes to make good art', PMI Global Congress 2006.
- Larkowski (2003) as cited in Week 4, Page 4 — project failure statistics.

---

## Transition to Next Slide

"With the demo complete, let me hand over to [C] to discuss the development decisions behind what you just saw."
