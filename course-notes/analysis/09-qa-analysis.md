# Analysis: Slide 09 — Q&A Preparation

## 1. Course Concepts Already Referenced

- **CPM Mechanics** (forward/backward pass, float, critical path) — from Week 4/5
- **Agile vs Predictive Planning** (Kanban vs Scrum vs Gantt) — from Week 1
- **Tuckman's stages** (Forming, Storming, Norming, Performing) — from Week 2
- **Belbin's team roles** — from Week 2 (9 roles mentioned)
- **Risk responses** (avoid, mitigate, transfer, accept) — general PM
- **CPM vs PERT vs Gantt** — from Week 4/5
- **Crashing/fast-tracking** — general PM scheduling

## 2. Course Concepts MISSING — With Suggested Q&A Additions

### A. Wilemon and Thamhain (1983) Barriers — HIGH PRIORITY

From Week 2, Page 14. The panel may ask "What barriers did your team face?" and expect you to name these from the course:

**Add this Q&A entry:**

> **Q: "What barriers to effective teamwork did you identify, referencing the literature?"**
>
> A: "Wilemon and Thamhain (1983) identify 11 barriers to building effective teams. In our sprint, we encountered three: (1) 'Role Conflicts' — initially unclear who owned the interface between parser and algorithm, which we resolved by defining the Activity struct together. (2) 'Communication Problems' — the knowledge silo issue where the tester couldn't write assertions without understanding the backward pass. (3) 'Dynamic Project Environments' — our estimation was wrong on Day 1 requiring a replan. We addressed these through proactive interface definition, a 15-minute algorithm walkthrough, and a mid-sprint replanning session."

### B. McClellan's Theory of Needs — MEDIUM PRIORITY

From Week 2, Page 6. Could be asked about motivation.

**Add this Q&A entry:**

> **Q: "How did you motivate team members during the sprint?"**
>
> A: "McClellan's Theory of Needs identifies three drivers: achievement, power, and affiliation. Our strengths-based role allocation tapped into achievement motivation — each person worked on what they could excel at. Our shared Kanban board and pair-programming addressed affiliation — everyone felt connected to the team's progress. And rotating who led each stand-up gave each member a sense of power and ownership over the process."

### C. Theory X, Y, Z (McGregor) — MEDIUM PRIORITY

From Week 2, Page 7. Could be asked about management/leadership approach.

**Add this Q&A entry:**

> **Q: "What management style did your team adopt?"**
>
> A: "We operated under a Theory Y assumption — that team members are naturally motivated and self-directing. This meant coaching and mentoring rather than top-down task assignment. Our Kanban board was pull-based — people chose tasks — rather than having a manager push work. This connects to McGregor's Theory Y and also to Agile Leadership principles from the course, where good leadership is 'context-dependent and relational' (APM BOK)."

### D. Team Contract / Social Contract — HIGH PRIORITY

From Week 2, Page 5. The panel may ask about how you established ways of working.

**Add this Q&A entry:**

> **Q: "Did you establish any team agreements or working conventions?"**
>
> A: "Yes — on Day 1 morning we informally established what Week 2 calls a 'team contract': an agreement about how the team would operate. Ours included: (1) the Activity struct as our shared interface contract, (2) Kanban with pull-based task selection, (3) 15-minute check-ins at start and end of each day, (4) pair-programming as the default response to blockers. This is also related to the concept of a 'social contract' from Belbin — defining commitments, expectations, and responsibilities towards each other and the project."

### E. Agile Communication Practices — HIGH PRIORITY

From Week 3, Pages 11-14. The panel WILL ask about your communication approach.

**Add this Q&A entry:**

> **Q: "What Agile communication practices did you use?"**
>
> A: "We adapted three Agile ceremonies to our compressed timeline: (1) Daily stand-ups — 15-minute synchronisation events where each member shared what they did, what they'll do, and any blockers (Schwaber & Sutherland, 2020). We held these at start and end of each day. (2) An informal sprint review on Day 2 — demonstrating working code to each other before final integration. (3) A retrospective discussion at the end — 'what went well, what could improve' (Derby & Larsen, 2006). We chose not to use formal sprint planning because our Kanban approach with a shared board made a separate planning ceremony redundant in a 2-day timeline."

### F. Change Management (Lewin / ADKAR) — MEDIUM PRIORITY

From Week 3, Pages 16-19. If asked about how you handled the mid-sprint replan.

**Add this Q&A entry:**

> **Q: "How did you manage the change when your plan needed to be revised on Day 1?"**
>
> A: "Our mid-sprint replan can be framed through Lewin's Change Model: we 'unfroze' our original plan by acknowledging it wasn't working (the parser took longer than expected), 'changed' by reprioritising (moving visualization to stretch goal), and 'refroze' by committing to the new priorities on the Kanban board. This also connects to the Agile Change Management principle from Week 3 — change is delivered incrementally, each sprint offering an opportunity to inspect, adapt, and refine (Highsmith, 2002)."

### G. Communication Needs per Tuckman Stage — HIGH PRIORITY

From Week 3, Pages 8-9. The course explicitly teaches that each Tuckman stage requires different communication approaches.

**Add this Q&A entry:**

> **Q: "How did your communication approach change as the team developed?"**
>
> A: "In Forming (Day 1 morning), communication was formal and directive — we clarified objectives, established norms, and created psychological safety. During Storming (the JSON vs CSV debate), communication became confrontational so we facilitated structured dialogue, keeping discussion task-focused. In Norming (after the replan), communication became more open and collaborative — information shared freely. By Performing (Day 2), communication was efficient and autonomous — information flowed quickly with minimal intervention. This maps directly to the Tuckman-Communication bridge from Week 3, which shows that teams require distinct communication approaches at each stage (Highsmith, 2002)."

### H. Iron Triangle (Cost, Time, Scope) — MEDIUM PRIORITY

From Week 4, Page 6. Fundamental PM concept.

**Add this Q&A entry:**

> **Q: "How did you manage the triple constraint in your sprint?"**
>
> A: "The Iron Triangle of cost, time, and scope applied directly. Our time was fixed (2 days). Our cost was fixed (4 team members). So scope was our flexible variable. When we realised on Day 1 that the CPM algorithm was more complex than estimated, we reduced scope — moving visualization from 'must have' to 'stretch goal.' This is exactly the trade-off the Iron Triangle describes: with fixed time and cost, scope must flex. Interestingly, because we managed scope proactively, we actually delivered the stretch goal too."

### I. Estimation Methods — HIGH PRIORITY

From Week 4, Pages 7-8. The panel may ask how you estimated task durations.

**Add this Q&A entry:**

> **Q: "How did you estimate task durations for your sprint?"**
>
> A: "We used a combination of expert judgement and bottom-up estimation from Week 4. We broke the project into work packages (parser, algorithm, tests, visualization), then each team member estimated their own package based on their experience — that's expert judgement. In retrospect, our estimates were optimistic — the parser took 3 hours instead of 1 — which is consistent with the industry insight from the CHAOS report that 66% of projects are considered to have failed, often due to unrealistic timelines (Larkowski, 2003). In future, I would apply three-point estimation (optimistic, most likely, pessimistic) to account for uncertainty."

### J. WBS (Work Breakdown Structure) — MEDIUM PRIORITY

From Week 4, Pages 12-14. May be asked about how you decomposed the project.

**Add this Q&A entry:**

> **Q: "Did you use a Work Breakdown Structure?"**
>
> A: "Implicitly, yes. Our JSON data model is itself a WBS — each activity in the project network is a discrete work package with defined dependencies. For our own sprint, we decomposed work into four packages: parsing, algorithm, testing, and visualization. This is a deliverable-based WBS. Each package was independently assignable and testable, which enabled parallel development. The WBS fed directly into our Kanban board — each card represented a work package at the lowest level of decomposition."

### K. APM Statistics on Teams — LOW PRIORITY (but impressive if used)

From Week 2, Page 14. Good for demonstrating you've read the literature.

**Use in any answer about teamwork:**

> "APM (2022) reports that 40% of teams are dysfunctional, only 10% are high performing, and 50% are merely average. We aimed to be in that top 10% by proactively addressing the barriers Wilemon and Thamhain (1983) identify — particularly role clarity, communication, and team structure."

### L. Contemporary Leadership Styles — LOW PRIORITY

From Week 2, Page 22. If asked about leadership in your team.

**Add this Q&A entry:**

> **Q: "What leadership style did your team use?"**
>
> A: "We adopted a distributed, servant leadership approach (Greenleaf) — rather than one person directing, each member led their domain. The person integrating the modules served others by removing blockers. This connects to Agile Leadership — adapting to change and fostering collaboration. The APM BOK principle that 'good leadership is context-dependent and relational' applied directly: in our compressed sprint, the context demanded shared leadership rather than hierarchical control."

## 3. KSBs Addressed by Q&A Preparation

| KSB | How Addressed |
|-----|---------------|
| **K8** | Strongly — demonstrates understanding of how teams work effectively |
| **K9** | Strongly — demonstrates understanding of leadership concepts |
| **K15** | Strongly — demonstrates understanding of estimation principles |
| **K19** | Moderately — ethical/professional standards in decision-making |
| **S5** | Strongly — demonstrates ability to apply standard processes (Agile, Kanban) |
| **S6** | Strongly — demonstrates ability to manage projects and resolve deviations |
| **B1** | Moderately — demonstrated through preparation quality |
| **B2** | Strongly — demonstrates both independent and team working capability |
| **B5** | Strongly — presenting data and conclusions professionally |

## 4. Priority Summary

| Priority | Topic | Why |
|----------|-------|-----|
| **CRITICAL** | Wilemon & Thamhain barriers | Explicitly taught, panel expects this |
| **CRITICAL** | Agile Communication Practices (stand-ups, retros) | Week 3 core content |
| **CRITICAL** | Communication per Tuckman stage | Week 3 core content, directly applicable |
| **HIGH** | Team Contract / Social Contract | Week 2 core concept, easy to apply |
| **HIGH** | Iron Triangle | Fundamental PM, directly demonstrated |
| **HIGH** | Estimation methods + why yours was wrong | Week 4 core content |
| **MEDIUM** | McClellan's Theory of Needs | Enriches motivation discussion |
| **MEDIUM** | Theory X/Y/Z | Enriches management style discussion |
| **MEDIUM** | Change Management (Lewin/ADKAR) | Week 3, applicable to your replan |
| **MEDIUM** | WBS | Week 4, directly maps to your JSON model |
| **LOW** | APM statistics (40%/10%/50%) | Impressive stat to drop in |
| **LOW** | Contemporary leadership styles | Only if directly asked |
