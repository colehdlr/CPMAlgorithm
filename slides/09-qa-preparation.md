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

## Area 6: Teamwork Barriers and Motivation

### Must-Know

- **Wilemon & Thamhain (1983):** 11 barriers to effective teams (role conflicts, communication problems, dynamic environments, etc.)
- **McClellan's Theory of Needs:** Three drivers — achievement, power, affiliation
- **APM stats:** 40% of teams are dysfunctional, only 10% are high performing, 50% average

### Likely Questions

**Q: "What barriers to effective teamwork did you identify, referencing the literature?"**

A: "Wilemon and Thamhain (1983) identify 11 barriers to building effective teams. In our sprint, we encountered three: (1) 'Role Conflicts' — initially unclear who owned the interface between parser and algorithm, which we resolved by defining the Activity struct together. (2) 'Communication Problems' — the knowledge silo issue where the tester couldn't write assertions without understanding the backward pass. (3) 'Dynamic Project Environments' — our estimation was wrong on Day 1 requiring a replan. We addressed these through proactive interface definition, a 15-minute algorithm walkthrough, and a mid-sprint replanning session."

**Q: "How did you motivate team members during the sprint?"**

A: "McClellan's Theory of Needs identifies three drivers: achievement, power, and affiliation. Our strengths-based role allocation tapped into achievement motivation — each person worked on what they could excel at. Our shared Kanban board and pair-programming addressed affiliation — everyone felt connected to the team's progress. And rotating who led each stand-up gave each member a sense of power and ownership over the process."

---

## Area 7: Management Style and Leadership

### Must-Know

- **Theory X:** Workers are lazy, need coercion — command-and-control
- **Theory Y:** Workers are self-motivated, thrive with autonomy — coaching style
- **Theory Z (Ouchi):** Long-term employment, consensus decision-making, holistic concern
- **Servant Leadership (Greenleaf):** Leader serves the team, removes blockers
- **Agile Leadership:** Context-dependent, relational, adaptive (APM BOK)

### Likely Questions

**Q: "What management style did your team adopt?"**

A: "We operated under a Theory Y assumption — that team members are naturally motivated and self-directing. This meant coaching and mentoring rather than top-down task assignment. Our Kanban board was pull-based — people chose tasks — rather than having a manager push work. This connects to McGregor's Theory Y and also to Agile Leadership principles from the course, where good leadership is 'context-dependent and relational' (APM BOK)."

**Q: "What leadership style did your team use?"**

A: "We adopted a distributed, servant leadership approach (Greenleaf) — rather than one person directing, each member led their domain. The person integrating the modules served others by removing blockers. This connects to Agile Leadership — adapting to change and fostering collaboration. The APM BOK principle that 'good leadership is context-dependent and relational' applied directly: in our compressed sprint, the context demanded shared leadership rather than hierarchical control."

---

## Area 8: Team Contracts and Ways of Working

### Must-Know

- **Team Contract:** Explicit agreement about how the team operates (norms, responsibilities, commitments)
- **Social Contract (Belbin):** Defining commitments, expectations, and responsibilities
- Purpose: Reduces ambiguity, accelerates Norming, provides reference point during Storming

### Likely Questions

**Q: "Did you establish any team agreements or working conventions?"**

A: "Yes — on Day 1 morning we informally established what Week 2 calls a 'team contract': an agreement about how the team would operate. Ours included: (1) the Activity struct as our shared interface contract, (2) Kanban with pull-based task selection, (3) 15-minute check-ins at start and end of each day, (4) pair-programming as the default response to blockers. This is also related to the concept of a 'social contract' from Belbin — defining commitments, expectations, and responsibilities towards each other and the project."

---

## Area 9: Agile Communication Practices

### Must-Know

- **Stand-ups:** 15-minute synchronisation (what did, what will do, blockers) — Schwaber & Sutherland, 2020
- **Sprint Review:** Demonstrating working software to stakeholders
- **Retrospective:** "What went well, what could improve" — Derby & Larsen, 2006
- **Communication per Tuckman stage:** Each stage requires a different communication approach

### Likely Questions

**Q: "What Agile communication practices did you use?"**

A: "We adapted three Agile ceremonies to our compressed timeline: (1) Daily stand-ups — 15-minute synchronisation events where each member shared what they did, what they'll do, and any blockers (Schwaber & Sutherland, 2020). We held these at start and end of each day. (2) An informal sprint review on Day 2 — demonstrating working code to each other before final integration. (3) A retrospective discussion at the end — 'what went well, what could improve' (Derby & Larsen, 2006). We chose not to use formal sprint planning because our Kanban approach with a shared board made a separate planning ceremony redundant in a 2-day timeline."

**Q: "How did your communication approach change as the team developed?"**

A: "In Forming (Day 1 morning), communication was formal and directive — we clarified objectives, established norms, and created psychological safety. During Storming (the JSON vs CSV debate), communication became confrontational so we facilitated structured dialogue, keeping discussion task-focused. In Norming (after the replan), communication became more open and collaborative — information shared freely. By Performing (Day 2), communication was efficient and autonomous — information flowed quickly with minimal intervention. This maps directly to the Tuckman-Communication bridge from Week 3, which shows that teams require distinct communication approaches at each stage (Highsmith, 2002)."

---

## Area 10: Change Management

### Must-Know

- **Lewin's Change Model:** Unfreeze → Change → Refreeze
- **ADKAR:** Awareness, Desire, Knowledge, Ability, Reinforcement
- **Agile Change Management:** Change delivered incrementally, each sprint an opportunity to inspect and adapt (Highsmith, 2002)

### Likely Questions

**Q: "How did you manage the change when your plan needed to be revised on Day 1?"**

A: "Our mid-sprint replan can be framed through Lewin's Change Model: we 'unfroze' our original plan by acknowledging it wasn't working (the parser took longer than expected), 'changed' by reprioritising (moving visualization to stretch goal), and 'refroze' by committing to the new priorities on the Kanban board. This also connects to the Agile Change Management principle from Week 3 — change is delivered incrementally, each sprint offering an opportunity to inspect, adapt, and refine (Highsmith, 2002)."

---

## Area 11: Iron Triangle and Estimation

### Must-Know

- **Iron Triangle:** Cost, Time, Scope — fix two, flex one
- **Estimation methods:** Expert judgement, bottom-up, analogous, three-point (PERT)
- **CHAOS Report (Larkowski, 2003):** 66% of projects considered to have failed, often due to unrealistic timelines
- **WBS:** Deliverable-based decomposition of work into assignable, testable packages

### Likely Questions

**Q: "How did you manage the triple constraint in your sprint?"**

A: "The Iron Triangle of cost, time, and scope applied directly. Our time was fixed (2 days). Our cost was fixed (4 team members). So scope was our flexible variable. When we realised on Day 1 that the CPM algorithm was more complex than estimated, we reduced scope — moving visualization from 'must have' to 'stretch goal.' This is exactly the trade-off the Iron Triangle describes: with fixed time and cost, scope must flex. Interestingly, because we managed scope proactively, we actually delivered the stretch goal too."

**Q: "How did you estimate task durations for your sprint?"**

A: "We used a combination of expert judgement and bottom-up estimation from Week 4. We broke the project into work packages (parser, algorithm, tests, visualization), then each team member estimated their own package based on their experience — that's expert judgement. In retrospect, our estimates were optimistic — the parser took 3 hours instead of 1 — which is consistent with the industry insight from the CHAOS report that 66% of projects are considered to have failed, often due to unrealistic timelines (Larkowski, 2003). In future, I would apply three-point estimation (optimistic, most likely, pessimistic) to account for uncertainty."

**Q: "Did you use a Work Breakdown Structure?"**

A: "Implicitly, yes. Our JSON data model is itself a WBS — each activity in the project network is a discrete work package with defined dependencies. For our own sprint, we decomposed work into four packages: parsing, algorithm, testing, and visualization. This is a deliverable-based WBS. Each package was independently assignable and testable, which enabled parallel development. The WBS fed directly into our Kanban board — each card represented a work package at the lowest level of decomposition."

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
