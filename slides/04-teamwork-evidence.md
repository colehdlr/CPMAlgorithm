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

"Now let me show you how we worked together as a team.

We used a Kanban board to manage our two-day sprint. You can see it here — columns for To Do, In Progress, and Done, with each task assigned to a specific team member. We chose Kanban over Scrum because our compressed timeline could not accommodate sprint ceremonies. Kanban's pull-based model let us rebalance work as we discovered that some tasks — like JSON parsing — took longer than expected, without the overhead of formal replanning.

We allocated roles based on individual strengths. [A] has the strongest algorithmic background, so they led the CPM computation. [B] had prior experience with file I/O and data structures, so they owned the parser. [C] has an analytical mindset suited to testing. And I focused on visualization and integration because of my experience with graphics libraries.

Here is our commit log showing parallel development — [A] and [B] were committing to cpm.c and parse.c simultaneously on Day 1, while [C] was writing the test suite. This parallel work was only possible because we agreed on the Activity struct as our interface contract before splitting.

We anticipated that integrating separately developed modules would be risky. So on Day 1 morning, before writing any code, we defined the Activity struct in parse.h as our shared contract. When we integrated on Day 2, it worked on the first attempt. This was proactive risk management — we identified integration as our highest risk and mitigated it before it became a problem.

Our test suite contains five automated tests, including edge cases like single-activity projects, parallel paths, cycle detection, and duplicate ID rejection. These tests ran before every integration, applying the quality management principle of building verification into the process."

---

## Key Points to Hit

- Do NOT just describe artefacts — explain what they PROVE
- Connect to rubric language: "parallel streams required clear interface agreements — integration management"
- Show PROACTIVE challenge handling: "We anticipated... so we... which prevented..."
- Mention Kanban choice justified by context (compressed timeline, uncertain durations)
- Strengths-based roles connected to Belbin
- Test suite as proactive quality assurance, not afterthought

---

## Proactive Framing (CRITICAL for 80%+)

The rubric requires "challenges handled proactively" for top marks. Frame it as:

> "We anticipated that parallel development of the parser and algorithm modules would create integration risk, so on Day 1 we agreed on the Activity struct as our shared interface contract. This prevented integration failures on Day 2."

NOT: "We had integration problems so we fixed them." (This is reactive = capped at 60-69.)

---

## Tuckman Mapping (Weave In if Time Allows)

| Stage | When | Evidence |
|---|---|---|
| Forming | Day 1, first hour | Assigning roles, agreeing on tools |
| Storming | JSON vs CSV debate, backward pass blocker | Disagreement channelled through structured discussion |
| Norming | After mid-sprint replan | Shared board, agreed interfaces, clear ownership |
| Performing | Day 2 integration | Self-directing, picking tasks, reviewing code |

---

## DO NOT

- Show only one evidence source (caps you at 60-69)
- Describe artefacts without explaining what they prove
- Use reactive language ("we had a problem, then we fixed it")
- Spend too long on any single artefact

---

## Transition to Next Slide

"Having covered how we structured our collaboration, [A] will now reflect on what we learned about ourselves as a team through this process."
