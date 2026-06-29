# Slide 6: Lessons Learned and Future Application

**Time:** 1 minute | **Speaker:** [Speaker D]

---

## On the Slide

A table with 3 lessons:

| Lesson | Theory Connection | Future Application |
|---|---|---|
| Methodology selection should be constraint-driven | Agile vs predictive planning; Iron Triangle (Week 4); Agile change management (Highsmith, 2002) | Match methodology to uncertainty level, not default to one |
| Separation of concerns requires explicit interface management | Modular decomposition; scope baseline; bottom-up estimation (Week 4) | Define shared contracts before parallel development begins |
| Asking for help is risk mitigation, not weakness | Risk response strategies (transfer); Wilemon & Thamhain (1983); Theory Y; Agile Leadership | Normalise help-seeking as team protocol from Day 1 |

---

## Speaker Script

"APM reports that only 10% of teams are high-performing. These three lessons represent the structural decisions that distinguish the 10% from the 50% who are merely average — not heroic individual effort, but methodology, architecture, and team protocols that enable collective performance.

First: methodology selection should be constraint-driven. Week 1 taught us that iterative approaches suit 'dynamic requirements and fast-changing needs' while linear approaches suit 'stable requirements and regulated industries.' Our lesson adds nuance: even within iterative, you must choose based on constraints. This is fundamentally an Iron Triangle decision — with time fixed at two days, we could not expand scope or reduce quality. Kanban was the methodology that let us manage within those fixed constraints by making scope flexible through the pull-based model. It also connects to Week 3's concept of Agile change management: 'rather than a single, disruptive transition, change is delivered incrementally' — each Kanban pull was an opportunity to inspect and adapt. In a longer project — say, a six-month construction schedule — we would use a more predictive approach because task durations would be better understood. The lesson is not that Kanban is always right, but that you match methodology to uncertainty level. This demonstrates S5: we did not just apply a methodology, we critically evaluated which methodology was appropriate for our constraints.

Second: separating concerns enables parallel work but requires explicit interface management. Our parse.c and cpm.c worked independently, but only because we invested 30 minutes on Day 1 defining the shared struct. This also has estimation implications — by defining clear module boundaries, we enabled bottom-up estimation: each team member could estimate their module independently. Without clear interfaces, estimation would require understanding the entire system, making it analogous estimation at best. Separation without interface planning creates integration risk — a lesson we now understand through experience, not just theory.

Third: asking for help is risk mitigation. When [A] was stuck on the backward pass, [D]'s pair-programming suggestion unblocked two hours of stalled work in 30 minutes. In PM terms, this is a risk response — we transferred the risk of delay from one person to the team. Wilemon and Thamhain (1983) identify 'lack of team member commitment' as a barrier, advising leaders to 'intervene and mediate any conflict quickly.' Our lesson extends this: it is not just about commitment problems, but about normalising help-seeking before problems escalate. A team protocol that says 'if stuck for 30 minutes, ask' prevents the commitment erosion that comes from isolation. This aligns with Theory Y management: if individuals are naturally motivated, then asking for help is not a sign of inadequacy but a sign of engagement — they want to solve the problem, they just need a different perspective. It also embodies Agile leadership — 'adapting to change, fostering collaboration' — where the leader's role is not to have all answers but to create conditions where the team can unblock itself. Pair programming as risk response IS Agile leadership in action. In future, I would normalise asking for help as a team protocol, not an admission of weakness."

---

## Key Points to Hit

- Each lesson must feel EARNED from experience, not quoted from a textbook
- Each has: what we learned + theory it connects to + what we'd do differently
- Keep it concise — 20 seconds per lesson
- These will be probed in Q&A, so understand them deeply
- Frame opening with APM high-performing teams statistic (only 10% are high-performing)
- First lesson: Iron Triangle (time fixed, scope flexible) + Agile change management (Highsmith, 2002) + S5 signal
- Second lesson: Bottom-up estimation enabled by modular boundaries (Week 4, Page 7)
- Third lesson: Wilemon & Thamhain (1983) on conflict intervention + Theory Y (coaching, not directing) + Agile Leadership (Week 2, Pages 20-21)
- Collectively these lessons answer K8: how do teams work effectively? Through structural decisions — methodology selection, interface management, and help-seeking protocols — not just good intentions

---

## What Makes Lessons Score 80%+

| Level | Example | Band |
|---|---|---|
| Descriptive | "We used Kanban" | 50-59 |
| Analytical | "We chose Kanban because our short sprint made Scrum impractical" | 60-69 |
| Critically evaluative | "The lesson is not that Kanban is always right, but that you match methodology to uncertainty level — in a 6-month project with understood scope, we would choose differently" | 80-100 |

---

## DO NOT

- Introduce new reflections (those belong on Slide 5)
- Give generic lessons ("teamwork is important")
- Spend more than 1 minute total
- Over-explain — these are summaries, not deep dives

---

## KSBs Addressed

| KSB | How Addressed |
|-----|---------------|
| **K8** | Strongly — lessons directly address how teams work effectively (methodology selection, interface management, help-seeking protocols) |
| **K9** | Moderately — third lesson demonstrates leadership principle (enabling, not directing) |
| **K15** | Moderately — methodology choice and modular decomposition connect to estimation principles |
| **S5** | Strongly — critical evaluation of methodology choice demonstrates ability to apply appropriate methods |
| **S6** | Strongly — lessons about managing deviations (replanning) and applying appropriate methodology |
| **B1** | Moderately — lessons show commitment to continuous improvement |
| **B2** | Strongly — all three lessons balance independent capability with team interdependence |

---

## Academic References to Cite if Probed in Q&A

- Anderson, D.J. (2010) *Kanban: Successful Evolutionary Change for Your Technology Business*
- Wilemon, D.L. and Thamhain, H.J. (1983) on team commitment barriers and conflict mediation
- Highsmith, J. (2002) on Agile change management: incremental delivery with inspect-and-adapt cycles
- APM (2022): "40% of teams are dysfunctional, only 10% are high performing"
- Week 1, Pages 16-19: Life cycle comparison (iterative vs linear vs hybrid)
- Week 2, Page 7: Theory Y — assumes individuals are naturally motivated; management style is coaching and mentoring
- Week 2, Pages 20-21: Agile Leadership — adapting to change, fostering collaboration
- Week 3, Page 19: Agile change management — change delivered incrementally, each sprint offering opportunity to inspect, adapt, and refine
- Week 4, Page 5: Iron Triangle — constraint-driven decisions
- Week 4, Page 7: Bottom-up estimation — breakdown the project into smallest manageable components

---

## Transition to Next Slide

"To close, [A] will bring everything together."
