# Slide 5: Reflection on Team Dynamics

**Time:** 2 minutes | **Speakers:** [A], [B], and [C] (one reflection each)

**KSBs addressed:** K8 (how teams work effectively), K9 (concepts and principles of leadership), B2 (independent vs team working), B5 (presenting conclusions truthfully)

---

## Framing (Opening Sentence Before Reflections)

> "These reflections follow the retrospective format from Week 3: 'The team reflects on process, not product. What went well? What could improve?' (Derby and Larsen, 2006). We are examining our team process, not our code. Week 5 asks: 'How did your team approach planning and estimation? Did everyone contribute equally? Have there been disagreements? How were they handled?' Our three reflections address these questions directly — not descriptively, but critically, examining assumptions against outcomes."

---

## On the Slide (Brief — Verbal Elaboration Does the Work)

- Reflection 1: Role assumptions and knowledge silos (Storming phase)
- Reflection 2: Planning rigidity vs adaptive response (Storming → Norming transition)
- Reflection 3: Proactive interface definition (servant leadership)

---

## The Five-Part Reflection Formula (MUST USE)

> "I assumed [X] -> [Y] happened -> I learned [Z] -> This connects to [theory] -> In future I would [action]."

This is the ONLY structure that scores 80-100%. Descriptive reflection ("we used Kanban") caps at 50-59.

---

## Reflection 1 — [Speaker A]: Role Assumptions and Knowledge Silos

**Tuckman stage:** Storming — "disagreements, competing priorities, and informal subgroups emerge" (Week 3, Page 8). Our subgroups were knowledge-based rather than interpersonal, but the effect was the same: blocked progress.

"I assumed that dividing work strictly by module — algorithm, parser, tests, visualization — would maximize efficiency. What actually happened was that when [C] started writing test cases, they could not write meaningful assertions without understanding how the backward pass updates predecessor LF values. We had created knowledge silos. Wilemon and Thamhain (1983) identify 'Communication Problems' as a major barrier to effective teams — not a lack of talking, but a lack of shared technical understanding across module boundaries. Their solution — 'provide a vehicle for timely sessions to encourage communications among individual team contributors' — is what we lacked. A 15-minute knowledge-sharing session on Day 1 afternoon would have prevented this. I learned that modular decomposition of work must be paired with cross-module knowledge sharing — what project risk management calls reducing the 'bus factor.' Belbin would say we over-indexed on Specialist roles and needed more Resource Investigators bridging across modules. McClellan's Theory of Needs helps explain why the silo formed: as Specialist, [A]'s achievement motivation was satisfied by solving the algorithm independently, but this created a knowledge barrier for [C], whose achievement in testing depended on understanding the algorithm. Individual achievement motivation must be balanced against team interdependence. In future, I would pair team members at integration boundaries, even when roles are formally separated."

**Formula breakdown:**
- Assumed: Strict module division = maximum efficiency
- Happened: Tester couldn't write assertions without algorithm knowledge
- Learned: Modular work decomposition ≠ modular knowledge; knowledge must bridge
- Theory: Belbin (Specialist vs Resource Investigator), bus factor risk, Wilemon and Thamhain (1983) communication barriers, McClellan's Theory of Needs (achievement motivation)
- Future: Pair team members at integration boundaries
- **KSB K8:** Understanding why knowledge silos form — and how to prevent them — is central to how teams work effectively

---

## Reflection 2 — [Speaker B]: Planning Rigidity

**Tuckman stage:** This replanning moment was our transition from Storming to Norming — moving from rigid individual plans to shared adaptive planning. Tuckman describes Norming as when "team members share information more freely and begin to coordinate expectations."

"I assumed we should plan everything on Day 1 morning to avoid wasting time. Our initial plan had the parser and algorithm both complete by end of Day 1. By 3pm, the parser worked but the algorithm was incomplete. We held a 15-minute stand-up and replanned — moving the visualization to a stretch goal and prioritizing algorithm completion and testing. Through Lewin's change model (1951), our rigid Day 1 plan was the 'frozen' state; the 3pm stand-up was our 'unfreeze' moment — we recognised the plan was failing and created dissatisfaction with the status quo; replanning was the 'change' stage; and embedding checkpoints going forward was 'refreeze' — making adaptive planning our new norm. Through ADKAR (Hiatt, 2006): we gained Awareness that the plan was failing (parser complete, algorithm incomplete), Desire came from deadline pressure, Knowledge was understanding what to reprioritise, Ability was having the Kanban board to visualise and reorder, and Reinforcement was the successful Day 2 integration validating our revised approach. I learned that in uncertain, time-constrained projects, rigid upfront planning creates an illusion of control. The Agile principle of 'responding to change over following a plan' is not just a philosophy — it is a survival strategy for short sprints. In future, I would build explicit replanning checkpoints into any compressed timeline."

**Formula breakdown:**
- Assumed: Plan everything upfront to avoid wasting time
- Happened: By 3pm, plan was already off-track
- Learned: Rigid planning creates illusion of control in uncertain contexts
- Theory: Agile Manifesto — responding to change over following a plan, Lewin's Change Model (Unfreeze → Change → Refreeze), ADKAR (Awareness, Desire, Knowledge, Ability, Reinforcement)
- Future: Build explicit replanning checkpoints into compressed timelines
- **KSB B5:** Presenting what went wrong honestly demonstrates presenting data and conclusions in an evidently truthful manner

---

## Reflection 3 — [Speaker C]: Proactive Interface Definition

**Tuckman stage:** Norming/Performing — proactive coordination indicates the team has moved beyond Storming into productive, self-organising work.

"We anticipated that integration would be our highest-risk moment, so we agreed on the Activity struct before writing any code and I wrote a test that exercised the full pipeline — parse, validate, topological sort, CPM compute — against the brief's expected values. This decision to write the integration test before any code was written is an example of servant leadership (Greenleaf) — removing barriers for others before they encounter them. Greenleaf's model positions the leader as someone who serves the team's ability to perform, not as a directive authority (Week 2, Page 20). When integration happened on Day 2, all five tests passed immediately. I learned that proactive interface definition — which is essentially scope baseline management applied to code — has disproportionate impact on integration risk. This connects directly to CPM itself: just as we identified critical activities in our application, we needed to identify critical dependencies in our team process."

**Formula breakdown:**
- Assumed/Anticipated: Integration would be highest-risk moment
- Happened: Proactive struct definition + pre-written tests → Day 2 integration passed first time
- Learned: Interface definition has disproportionate impact on integration risk
- Theory: Scope baseline management; CPM critical dependency concept applied to team process; Servant Leadership (Greenleaf — leading by supporting others)
- Future: Always define interface contracts before parallel development begins
- **KSB K9:** This reflection demonstrates understanding of leadership concepts — specifically, that leadership in short sprints is about removing barriers and enabling team performance, not directive control

---

## Key Points to Hit

- Each team member owns at least one reflection
- Speak in first person: "I assumed...", "I learned...", "I would..."
- Reflections must be SPECIFIC to your project (reference file names, specific moments)
- Connect every reflection to a named PM theory/framework
- End each with a concrete, actionable future behaviour
- Name the Tuckman stage each reflection occurred in
- Signal KSBs explicitly (K8, K9, B2, B5) where relevant

## Academic References to Cite

- Tuckman, B. (1965) — Forming, Storming, Norming, Performing and Adjourning (Week 2, Pages 10-11)
- Wilemon, D. and Thamhain, H. (1983) — Communication barriers in project teams (Week 2, Pages 14, 17)
- Lewin, K. (1951) Field Theory in Social Science. New York: Harper & Row — Unfreeze, Change, Refreeze (Week 3, Page 18)
- Hiatt, J. (2006) ADKAR: A Model for Change in Business, Government and Our Community — Awareness, Desire, Knowledge, Ability, Reinforcement (Week 3, Page 17)
- McClellan — Theory of Needs: achievement, power, affiliation (Week 2, Page 6)
- Greenleaf — Servant Leadership: "Leading by supporting others" (Week 2, Page 20)
- Belbin, R.M. (2010) Team Roles at Work. 2nd edn. Oxford: Butterworth-Heinemann.
- Derby, E. and Larsen, D. (2006) Agile Retrospectives: Making Good Teams Great. Raleigh: Pragmatic Bookshelf.

---

## The Specificity Test

> If another team doing a different project could say the same reflection, it is TOO GENERIC. Rewrite until only YOUR team could have said it.

**GENERIC (bad):** "We learned that communication is important for teamwork."
**SPECIFIC (good):** "We learned that defining the Activity struct in types.h before splitting into parse.c and cpm.c prevented integration failure, because both developers coded against the same data contract."

---

## DO NOT

- Use descriptive-only reflection ("We used Kanban. We divided tasks.")
- Give generic lessons ("communication is key", "teamwork matters")
- Skip the theory connection
- Give vague future actions ("I would communicate better")

---

## Transition to Next Slide

"Those reflections lead naturally to our key lessons. [D] will summarise what we're taking forward from this experience."
