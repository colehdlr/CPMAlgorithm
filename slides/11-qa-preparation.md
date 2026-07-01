# Q&A Preparation Guide

**INTERNAL PREP ONLY — DO NOT INCLUDE IN SUBMITTED SLIDE DECK**

**Time:** 5 minutes after presentation | **All members must answer at least one question**

---

## Technique

1. **Pause** for 2 seconds — rushed answers sound memorised
2. **Connect to your project:** "We encountered this when..."
3. **Name the principle** if relevant
4. **Give the specific answer**
5. **If you don't know:** "That's outside what we explored, but based on [principle], I'd expect [reasoned guess]."

**Participation:** If any member hasn't answered by minute 3, the next responder says "I'd like [Name] to add their perspective."

---

## Area 1: CPM Mechanics

| Question | Answer | Project Link |
|----------|--------|--------------|
| Why does B have float of 2? | B-D path = 13 days, C-E path = 15 days. B can slip 2 days before it affects F's start. | "You can see it in our demo output — B and D are grey, not red." |
| What if B's duration increased to 7? | B-D path becomes 14, then 17 with D. Still under 22, so CP unchanged. But at B=8, B-D=18 and D-F path = 23 > 22 — CP shifts. | "Critical path isn't fixed. It changes when durations change." |
| Total float vs free float? | Total = delay before project end slips. Free = delay before the NEXT task slips. Both are 2 for B here because B's successor (D) feeds only into F alongside E. | "Free float is what the downstream person cares about." |
| Resource constraints in CPM? | CPM assumes unlimited resources. If one person handled both B and C (both start Day 3), one becomes sequential. Schedule extends. | "Resource levelling adjusts the schedule; CPM alone doesn't model people." |
| How would you crash to 18 days? | Only crash critical activities. Shorten E or G — whichever has the better cost-per-day ratio. Once one path is shortened enough that another becomes critical, you crash both. | "Never crash non-critical activities." |

---

## Area 2: PERT and Estimation

| Question | Answer | Project Link |
|----------|--------|--------------|
| Walk me through the PERT variance calculation. | Expected = (O+4M+P)/6. Variance = ((P-O)/6)². Sum variances along critical path. Square root gives project σ. Our critical path variance = 3.21, σ = 1.79. 95% CI = mean ± 1.96σ. | "That's how we get 23.8 ± ~3.5 days, so [20.2, 27.4]." |
| CPM vs PERT — when use which? | CPM when durations are well-known. PERT when uncertainty matters — forces you to think about optimistic and pessimistic scenarios. | "PERT told us 23.8 vs 22 — a PM commits at 25, not 22." |
| Which estimation method worked best for you? | Expert judgement was worst (+200% on parser). Analogous (Python coursework scaled 2× for C) matched actual. PERT halved the error vs expert. Hierarchy: analogous → parametric → PERT → expert as fallback. | "We had directly comparable past work — that's when analogous shines." |
| How did you use PERT during the sprint? | When parser overran Day 1, we re-estimated remaining work with O/M/P. That told us visualisation was still achievable but the stretch goal was at risk. It informed a real-time scope decision. | "PERT isn't just retrospective — we used it to decide what to protect." |
| Iron Triangle — what was your trade-off? | Time was fixed (2 days). Team size was fixed (4). So scope had to flex. We used MoSCoW to decide what to protect when we fell behind. | "Scope is your only control lever when time is fixed." |

---

## Area 3: Teamwork

| Question | Answer | Project Link |
|----------|--------|--------------|
| What Tuckman stage did you reach? | Norming by Day 1 evening — shared processes, roles clear. Glimpses of Performing Day 2 when people self-directed without checking in. True Performing takes longer than two days. | "Norming on process happened Day 1; norming on knowledge took until Day 2." |
| Did RACI actually change behaviour? | Yes — Hamza was Consulted on both Algorithm and Visualisation. That's why he caught the type mismatch between Jamie's output and Cole's renderer. Without that explicit role, he might have assumed it wasn't his business. | "The C/I distinction told him it was his job to look." |
| What if a team member wasn't contributing? | Address it directly — suppressing it prolongs Storming. Understand why first (blocked? unclear task? disengaged?), then reference the allocation and offer support. Our escalation rule would apply. | "We'd use the same 15-min rule — surface it, don't avoid it." |
| Why strengths-based allocation? Risk? | Speed — 2-day timeline meant we needed people where they'd succeed immediately. The risk is nobody grows. Longer projects need rotation. | "It worked here because of the timeline, not because it's always right." |
| Why Kanban over Scrum? | 2-day timeline — sprint ceremonies would eat working time. Uncertain task durations suited continuous flow. WIP limit of 1 matched single-person packages. | "Continuous flow beat fixed-length sprints for this timeline." |

---

## Area 4: Reflection and Learning

| Question | Answer | Project Link |
|----------|--------|--------------|
| How did you structure your reflections? | Each person identified an assumption they held, the specific moment it was challenged, the theory that explains why, and a concrete future action. | "It's roughly Kolb's cycle — experience, reflect, theorise, plan — but messier in reality." |
| Schön vs Kolb? | Kolb is retrospective — you reflect after the event. Schön's reflection-in-action happens in real time. Samuel's was Schön — he reframed "I'm stuck on syntax" to "I don't know what correct looks like" while still working. | "Schön doesn't require stopping to reflect formally." |
| What's your biggest team-level lesson? | We decomposed work but not understanding. The WBS split responsibilities but didn't ensure people knew enough about adjacent modules to do their own work well. | "Next time: a knowledge map alongside the WBS." |
| What transfers to a new team? What doesn't? | Processes transfer — escalation rules, RACI, stand-up format. Trust doesn't — that came from a shared failure in a prior module. A new team would need to build relational foundations deliberately. | "We'd need to invest in trust-building before the processes become useful." |
| Counter-arguments on your future actions? | Jamie: spiking only matters for irreversible decisions. Samuel: knowledge-sharing depends on the tester knowing enough to ask good questions. Cole: automated verification only works when correctness is measurable. Hamza: interface ownership adds overhead — unnecessary for tiny interfaces. | "Each action has boundary conditions where it stops being worth it." |

---

## Area 5: Challenges and Conflict

| Question | Answer | Project Link |
|----------|--------|--------------|
| How did you resolve the C language debate? | Escalation rule triggered — unresolved after 15 mins, structured round-robin. Each person spoke in turn. Decision: stick with C, support each other. Jamie then pair-programmed Samuel's parser for 45 minutes. | "The round-robin prevented anyone dominating the conversation." |
| Why did the round-robin work? | Because we already trusted each other. A previous module failure taught us blame destroys speed. The structure gave urgency and prevented dominance — but only because trust made honesty safe. | "A new team using the same process without that trust would get politeness, not honesty." |
| What would you do differently with the C decision? | Spike it. We spent 20 minutes spiking JSON vs CSV but zero time testing whether C was feasible for everyone. We confused shared enthusiasm with shared capability. | "Spike the risky decisions, not just the easy ones." |
| Hamza — without existing trust, what structural mechanism would you use? | Assign interface ownership as a formal role on Day 1 — separate from module ownership. Make it someone's explicit job to review contracts between modules. Then flagging mismatches is a role responsibility, not a personal confrontation. | "Structure can substitute for trust when trust hasn't been built yet." |

---

## Area 6: Scope and Decisions

| Question | Answer | Project Link |
|----------|--------|--------------|
| MoSCoW — how did you decide categories? | Must = core deliverable (CPM calc + parser — without these, nothing works). Should = visualisation (adds value but app functions without it). Could = PERT mode (stretch). Won't = GUI input (explicitly descoped Day 1). | "Must is 'does the thing exist', Should is 'is it good', Could is 'is it impressive'." |
| PERT is implemented — why was it a "Could"? | It started as Could. When parser overran, we re-assessed: Musts were on track, Should was achievable given Cole's float. PERT survived because we found time — but it was genuinely at risk of being cut. | "MoSCoW isn't static — it told us what to sacrifice IF we needed to." |
| If you had 3 more days, what would you add? | Monte Carlo simulation (random sampling instead of single PERT estimate), GUI input (currently JSON file), and resource-constrained scheduling. | "Monte Carlo would give a probability distribution rather than one confidence interval." |
| How does this relate to managing a real project? | Same principles at different scale. CPM/PERT apply to construction, software, any multi-activity project. The difference: real projects have hundreds of activities, external dependencies, and resource constraints CPM doesn't model. | "The maths scales; what changes is the number of unknowns." |

---

## Hard Questions to Practise

1. "Walk me through how you'd add a new activity to your network and recalculate."
2. "How would your process change with 6 people instead of 4?"
3. "What's the limitation of your JSON input format?"
4. "What would happen if your critical path shifted mid-project?"
5. "Why didn't you implement Monte Carlo simulation?"
6. "What would you do if two team members wanted the same role?"
7. "How did you test that your algorithm gives correct results?"
8. "What's the difference between resource levelling and resource smoothing?"

---

## Handling Difficult Moments

**If you don't know:**
"That's outside what we explored, but based on [principle], I'd expect [reasoned guess]."

**If asked about someone else's area:**
Brief answer showing cross-team knowledge, then: "[Name] can add more detail on this."

**If asked a calculation:**
"Let me work through that." [Pause. Think aloud.] "The new path would be... which means..."
