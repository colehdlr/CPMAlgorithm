# Q&A Preparation Guide

**Time:** 5 minutes after presentation | **All members must answer at least one question**

---

## General Q&A Technique

When asked a question:

1. **Pause** for 2 seconds (rushed answers sound memorised)
2. **Connect to your experience:** "In our project, we encountered this when..."
3. **Name the principle:** "This relates to [PM concept]..."
4. **Give the specific answer**
5. **If you don't know:** "That is outside what we explored, but based on [principle], I would expect [reasoned guess]."

---

## Area 1: CPM Mechanics

### Must-Know

- Forward pass = earliest start/finish (take MAX of predecessors at convergence)
- Backward pass = latest start/finish (take MIN of successors, working backwards)
- Float = LS - ES (or LF - EF)
- Critical path = all activities with zero float
- Any delay to critical activity = project delay

### Likely Questions

**Q: "Why does B have float of 2 but C has float of 0?"**

A: "B's path to F is A(3) + B(4) + D(6) = 13 days. C's path to F is A(3) + C(5) + E(7) = 15 days. Since F needs both, and C's path is longer by 2 days, B can slip by 2 days without affecting F's start. C cannot slip at all — it drives when F can start."

**Q: "What if B's duration increases from 4 to 7?"**

A: "The path through B-D becomes A(3) + B(7) + D(6) + F(3) + G(4) = 23 days, exceeding the current critical path of 22. B-D becomes the new critical path. The critical path is dynamic — it shifts when durations change."

**Q: "What if E's duration changed to 10?"**

A: "Critical path remains A-C-E-F-G. Project duration becomes 3+5+10+3+4 = 25 days. B-D path is 3+4+6+3+4 = 20, so B-D float increases to 5 days."

**Q: "How would you crash this project to 18 days?"**

A: "Target the critical path activity with the best cost-per-day ratio. E (Backend Dev, 7 days) is the largest critical activity and likely the best candidate. We'd need to reduce the critical path by 4 days. This connects to the PM concept of crashing — spending additional resources to compress the critical path."

**Q: "Difference between total float and free float?"**

A: "Total float is how much an activity can slip without delaying the project end. Free float is how much it can slip without delaying any successor. In our project, B has total float of 2 and free float of 2 (since D only depends on B). But in networks where non-critical activities share successors, these can differ."

---

## Area 2: Agile vs Predictive Planning

### Must-Know

- Kanban: pull-based, no fixed iterations, WIP limits, continuous flow
- Scrum: fixed sprints, ceremonies (planning, review, retro), defined roles
- Gantt: predictive, schedule-based, works best with known durations
- Your choice (Kanban): justified by short timeline + uncertain task durations

### Likely Questions

**Q: "Why Kanban over Scrum?"**

A: "Two-day timeline. Scrum ceremonies — sprint planning, daily standups, review, retrospective — would consume a disproportionate percentage of our available time. Kanban gave us task visibility and flow management without ceremony overhead."

**Q: "Why Kanban over a Gantt chart?"**

A: "Our task durations were uncertain — we didn't know how long JSON parsing would take until we started. A Gantt chart assumes known durations. Kanban adapts to discovered reality."

**Q: "When would Kanban NOT be right?"**

A: "A large project with multiple teams, well-understood scope, and stakeholders who need predictable delivery dates. A construction project scheduling, for example, benefits from predictive planning because task durations are well-estimated from historical data."

**Q: "What WIP limit did you set?"**

A: [If you set one] "We set a WIP limit of [X] per person because..."
[If you didn't] "We did not set a formal WIP limit, which in retrospect meant our Kanban implementation was incomplete. A WIP limit of 2 per person would have prevented context-switching. This is something I would implement from Day 1 in a future project."

---

## Area 3: Team Theory

### Must-Know

- **Tuckman:** Forming → Storming → Norming → Performing (→ Adjourning)
- **Belbin:** 9 team roles (Plant, Resource Investigator, Coordinator, Shaper, Monitor Evaluator, Teamworker, Implementer, Completer Finisher, Specialist)
- Your team likely reached Norming; Performing requires longer

### Likely Questions

**Q: "What Tuckman stage did your team reach?"**

A: "We reached Norming by end of Day 1 — we had established shared processes, agreed interfaces, and clear ownership. We showed glimpses of Performing on Day 2 when team members self-directed tasks without being asked. But true Performing typically requires longer than two days to fully develop."

**Q: "How would you handle a non-contributing member?"**

A: "I would recognise this as part of the Storming phase and address it directly but constructively. First, understand why — are they stuck, disengaged, or unclear on their role? Then discuss openly, reference the agreed role allocation, and offer support. Suppressing the issue prolongs Storming; addressing it moves toward Norming."

**Q: "Why might strengths-based allocation NOT work?"**

A: "If everyone has the same strength, you get competition for one role and reluctant assignment to others. Or if the team is too small and one person's 'strength area' is trivially small — you create idle capacity. In those cases, a more balanced rotation approach builds broader capability."

---

## Area 4: Risk and Quality Management

### Must-Know

- **Risk responses:** Avoid, Mitigate, Transfer, Accept
- **Your risks:** Integration risk (mitigated by interface contracts), Time risk (mitigated by replanning), Scope risk (mitigated by stretch goals)
- **Quality management:** Testing as verification, dual implementation as validation

### Likely Questions

**Q: "What risks did you identify?"**

A: "Three primary risks: (1) Integration risk — mitigated by defining shared structs before parallel development. (2) Time risk — mitigated by building replanning checkpoints and designating stretch goals. (3) Accuracy risk — mitigated by cross-validation with an independent Python implementation and 5 automated tests."

**Q: "How does your testing relate to quality management?"**

A: "Our test suite applies the 'build quality in' principle — verification is embedded in our process, not bolted on at the end. The 5 tests cover the golden path (textbook scenario), edge cases (single activity, parallel paths), and error cases (cycles, duplicates). This is proactive quality management."

**Q: "Difference between risk avoidance, mitigation, transfer, acceptance?"**

A: "Avoidance: eliminate the risk entirely (e.g., don't use a technology you don't understand). Mitigation: reduce probability or impact (e.g., interface contracts reduce integration failure probability). Transfer: shift the risk to someone else (e.g., pair programming transfers 'stuck' risk to the team). Acceptance: acknowledge the risk and have a contingency (e.g., we accepted the risk of the raylib visualization not being completed by making it a stretch goal)."

---

## Area 5: Estimation and Broader Context

### Must-Know

- **CPM vs PERT:** CPM = deterministic durations; PERT = probabilistic (optimistic, most likely, pessimistic)
- **CPM vs Gantt:** CPM identifies critical path; Gantt visualises schedule but doesn't inherently identify it
- **Crashing:** Spending more resources to reduce critical path duration
- **Fast-tracking:** Overlapping activities that would normally be sequential (increases risk)

### Likely Questions

**Q: "CPM vs PERT?"**

A: "CPM assumes each activity has a single, deterministic duration. PERT uses three estimates — optimistic, most likely, pessimistic — to calculate expected duration with variance. PERT is more appropriate when task durations are uncertain. Our architecture could accommodate PERT by extending the Activity struct with three duration fields and calculating expected duration using the PERT formula."

**Q: "How does CPM relate to cost estimation?"**

A: "Through crashing. If you need to shorten the project, you target critical path activities — spending more resources (overtime, more staff, better tools) to reduce their duration. The cost-time trade-off analysis identifies which activities give the most schedule compression per unit cost."

---

## Handling Difficult Moments

**If you genuinely don't know:**
"That is outside what we explored in this sprint, but based on [principle], I would expect [reasoned guess]. I would want to verify by [action]."

**If asked about someone else's area:**
Give a brief answer showing cross-team knowledge, then: "[Name] can add detail on this."

**If asked a calculation you need to think through:**
"Let me work through that. [Pause. Think aloud briefly.] The new path would be... which means..."

---

## Hard-Mode Questions to Practise

1. "If you had 3 more days, what would you add to the application?"
2. "How would your process change with a 6-person team?"
3. "What's the limitation of your JSON input format?"
4. "How would you handle resource constraints in CPM?"
5. "What would you do if two team members wanted the same role?"
6. "How does your experience relate to managing a real construction project?"
