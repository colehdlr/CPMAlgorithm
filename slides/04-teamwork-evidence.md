# Slide 4: Teamwork and Collaboration Evidence

**Time:** 2 minutes | **Speaker:** [Speaker D]

---

## On the Slide

Multiple evidence artefacts (minimum 3 of the following):

1. **Kanban board screenshot** — showing To Do, In Progress, Done columns with assigned tasks
2. **Commit log timeline** — table or visual showing who committed what and when
3. **Meeting notes excerpt** — showing a decision point or conflict resolution
4. **Role allocation table** — who did what and WHY (strengths-based)
5. **Code review evidence** — team members reviewing each other's work
6. **Test suite summary** — 5 automated tests including edge cases

| Evidence | What It Proves |
|---|---|
| Kanban board | Structured task management with visibility |
| Commit log timeline | Parallel work streams, continuous integration |
| Meeting notes (Day 1 planning, Day 2 retro) | Structured decision-making, conflict resolution |
| Role-to-strength mapping | Deliberate, theory-informed team composition |
| Automated test suite (5 tests) | Proactive quality management — tests written BEFORE demo |

---

## Speaker Script

"Now let me show you how we worked together as a team. This evidence directly addresses K8 — demonstrating how our team worked effectively to produce a digital technology solution.

APM research shows 40% of project teams are dysfunctional and only 10% are high-performing (APM, 2022). Our evidence demonstrates the deliberate practices that moved us from average toward high-performing within a compressed timeline.

We used a Kanban board to manage our two-day sprint. You can see it here — columns for To Do, In Progress, and Done, with each task assigned to a specific team member. We chose Kanban over Scrum because our compressed timeline could not accommodate sprint ceremonies. Kanban's pull-based model let us rebalance work as we discovered that some tasks — like JSON parsing — took longer than expected, without the overhead of formal replanning.

Before beginning work, we established a team contract — what Week 2 calls a social contract — defining our commitments: code review before merge, 15-minute stand-ups at midday, and the shared Activity struct as our interface agreement. This contract moved us rapidly through Tuckman's Forming stage because expectations were explicit from the start.

We allocated roles based on individual strengths, informed by Belbin's Team Roles theory (Belbin, 2010). [A] operated as Specialist — deep algorithmic expertise — so they led the CPM computation. [B] as Implementer — systematic parser construction — so they owned the parser. [C] as Completer Finisher — analytical mindset and detail focus — suited to testing. And I took the Co-ordinator role, clarifying goals and delegating integration tasks, combined with Resource Investigator, exploring raylib for visualization.

Our role allocation also considered motivation. In McClellan's terms, [A] has a high need for achievement — complex algorithmic challenges satisfy this. I have a high need for affiliation — the integration coordinator role placed me at the centre of team interaction. Matching roles to motivational drivers increased engagement.

Here is our commit log showing parallel development — [A] and [B] were committing to cpm.c and parse.c simultaneously on Day 1, while [C] was writing the test suite. This parallel work was only possible because we agreed on the Activity struct as our interface contract before splitting. Research on effective teams shows that 'everyone in the team talked and listened in roughly equal measure' and 'members connected directly with one another, not just with the team leader.' Our commit log and code review evidence shows all four members contributing and reviewing each other's work — no single gatekeeper.

Wilemon and Thamhain (1983) identify 'Differing Outlooks, Priorities, Interests and Judgments' as a major barrier to effective teams. We addressed this proactively: the JSON vs CSV debate on Day 1 morning was an example of differing technical judgements. Rather than letting it fester, we resolved it through structured discussion — comparing each format against our requirements — within 20 minutes. This is precisely what Wilemon and Thamhain recommend: 'Early in the project life cycle, discover any conflicting differences.'

We anticipated that integrating separately developed modules would be risky. So on Day 1 morning, before writing any code, we defined the Activity struct in parse.h as our shared contract. When we integrated on Day 2, it worked on the first attempt. This was proactive risk management — we identified integration as our highest risk and mitigated it before it became a problem.

On Day 2, team members self-directed — picking up tasks from the Kanban board without being assigned. This aligns with McGregor's Theory Y: individuals are naturally motivated when given autonomy and meaningful work. Our approach was coaching and enabling, not directive — consistent with Theory Y management style. This demonstrates distributed leadership — no single PM, but shared ownership aligned with Agile leadership principles (K9).

We held daily stand-ups following the Agile format: What did I do? What will I do? Any blockers? Our Day 1 midday stand-up surfaced the backward pass blocker, enabling rapid impediment removal — exactly the purpose Schwaber and Sutherland (2020) describe in The Scrum Guide. These 15-minute synchronisation events promoted transparency and kept our compressed timeline on track.

Our test suite contains five automated tests, including edge cases like single-activity projects, parallel paths, cycle detection, and duplicate ID rejection. These tests ran before every integration, applying the quality management principle of building verification into the process."

---

## Key Points to Hit

- Do NOT just describe artefacts — explain what they PROVE
- Connect to rubric language: "parallel streams required clear interface agreements — integration management"
- Show PROACTIVE challenge handling: "We anticipated... so we... which prevented..."
- Mention Kanban choice justified by context (compressed timeline, uncertain durations)
- Strengths-based roles connected to Belbin — name the specific roles (Specialist, Implementer, Completer Finisher, Co-ordinator, Resource Investigator)
- McClellan's Theory of Needs — match motivational drivers to role allocation
- Test suite as proactive quality assurance, not afterthought
- Social contract / team contract established on Day 1 — explicit expectations
- Theory Y — self-direction on Day 2 demonstrates natural motivation with autonomy
- Wilemon and Thamhain barriers — show how differing judgements were resolved early
- APM statistic — 40% dysfunctional, only 10% high-performing — frame why deliberate practices matter
- Agile stand-ups (Schwaber & Sutherland, 2020) — surfacing blockers for rapid impediment removal
- **K8** — this slide IS K8; say it explicitly
- **K9** — name distributed leadership explicitly

---

## Proactive Framing (CRITICAL for 80%+)

The rubric requires "challenges handled proactively" for top marks. Frame it as:

> "We anticipated that parallel development of the parser and algorithm modules would create integration risk, so on Day 1 we agreed on the Activity struct as our shared interface contract. This prevented integration failures on Day 2."

NOT: "We had integration problems so we fixed them." (This is reactive = capped at 60-69.)

---

## Tuckman Mapping (Weave In if Time Allows)

Reference: Tuckman, B.W. (1965) 'Developmental sequence in small groups', Psychological Bulletin, 63(6), pp. 384-399.

| Stage | When | Evidence |
|---|---|---|
| Forming | Day 1, first hour | Assigning roles, agreeing on tools; social contract established to accelerate this stage |
| Storming | JSON vs CSV debate, backward pass blocker | Disagreement channelled through structured discussion (Wilemon & Thamhain barrier resolution) |
| Norming | After mid-sprint replan | Shared board, agreed interfaces, clear ownership; team contract enforced |
| Performing | Day 2 integration | Self-directing (Theory Y), picking tasks, reviewing code; all members contributing equally |

---

## DO NOT

- Show only one evidence source (caps you at 60-69)
- Describe artefacts without explaining what they prove
- Use reactive language ("we had a problem, then we fixed it")
- Spend too long on any single artefact

---

---

## KSBs Addressed by This Slide

| KSB | How Addressed |
|---|---|
| **K8** | Primary slide — "how teams work effectively to produce digital and technology solutions" |
| **K9** | Distributed leadership, self-direction (Theory Y), coordination role, structured decision-making |
| **B1** | Proactive risk management, test suite, structured workflow demonstrate strong work ethic |
| **B2** | Evidence of both independent work (parallel modules) and team working (code review, integration) |
| **B5** | Presenting evidence concisely and objectively |
| **S6** | Kanban methodology applied to manage the project |

---

## Academic References for This Slide

- APM (2022) — 40% dysfunctional teams statistic (Week 2, Page 14)
- Belbin, R.M. (2010) Team Roles at Work. 2nd edn. Oxford: Butterworth-Heinemann.
- McClellan, D. — Theory of Needs: achievement, power, affiliation (Week 2, Page 6)
- McGregor, D. — Theory Y: naturally motivated individuals, coaching management style (Week 2, Page 7)
- Schwaber, K. and Sutherland, J. (2020) The Scrum Guide.
- Tuckman, B.W. (1965) 'Developmental sequence in small groups', Psychological Bulletin, 63(6), pp. 384-399.
- Wilemon, D.L. and Thamhain, H.J. (1983) 'Team Building in Project Management', Project Management Quarterly, 14(2), pp. 73-81.

---

## Transition to Next Slide

"Having covered how we structured our collaboration, [A] will now reflect on what we learned about ourselves as a team through this process."
