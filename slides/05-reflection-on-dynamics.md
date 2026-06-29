# Slide 5: Reflection on Team Dynamics

**Time:** 2 minutes | **Speakers:** [A], [B], and [C] (one reflection each)

---

## On the Slide (Brief — Verbal Elaboration Does the Work)

- Reflection 1: Role assumptions and knowledge silos
- Reflection 2: Planning rigidity vs adaptive response
- Reflection 3: Proactive interface definition

---

## The Five-Part Reflection Formula (MUST USE)

> "I assumed [X] -> [Y] happened -> I learned [Z] -> This connects to [theory] -> In future I would [action]."

This is the ONLY structure that scores 80-100%. Descriptive reflection ("we used Kanban") caps at 50-59.

---

## Reflection 1 — [Speaker A]: Role Assumptions and Knowledge Silos

"I assumed that dividing work strictly by module — algorithm, parser, tests, visualization — would maximize efficiency. What actually happened was that when [C] started writing test cases, they could not write meaningful assertions without understanding how the backward pass updates predecessor LF values. We had created knowledge silos. I learned that modular decomposition of work must be paired with cross-module knowledge sharing — what project risk management calls reducing the 'bus factor.' Belbin would say we over-indexed on Specialist roles and needed more Resource Investigators bridging across modules. In future, I would pair team members at integration boundaries, even when roles are formally separated."

**Formula breakdown:**
- Assumed: Strict module division = maximum efficiency
- Happened: Tester couldn't write assertions without algorithm knowledge
- Learned: Modular work decomposition ≠ modular knowledge; knowledge must bridge
- Theory: Belbin (Specialist vs Resource Investigator), bus factor risk
- Future: Pair team members at integration boundaries

---

## Reflection 2 — [Speaker B]: Planning Rigidity

"I assumed we should plan everything on Day 1 morning to avoid wasting time. Our initial plan had the parser and algorithm both complete by end of Day 1. By 3pm, the parser worked but the algorithm was incomplete. We held a 15-minute stand-up and replanned — moving the visualization to a stretch goal and prioritizing algorithm completion and testing. I learned that in uncertain, time-constrained projects, rigid upfront planning creates an illusion of control. The Agile principle of 'responding to change over following a plan' is not just a philosophy — it is a survival strategy for short sprints. In future, I would build explicit replanning checkpoints into any compressed timeline."

**Formula breakdown:**
- Assumed: Plan everything upfront to avoid wasting time
- Happened: By 3pm, plan was already off-track
- Learned: Rigid planning creates illusion of control in uncertain contexts
- Theory: Agile Manifesto — responding to change over following a plan
- Future: Build explicit replanning checkpoints into compressed timelines

---

## Reflection 3 — [Speaker C]: Proactive Interface Definition

"We anticipated that integration would be our highest-risk moment, so we agreed on the Activity struct before writing any code and I wrote a test that exercised the full pipeline — parse, validate, topological sort, CPM compute — against the brief's expected values. When integration happened on Day 2, all five tests passed immediately. I learned that proactive interface definition — which is essentially scope baseline management applied to code — has disproportionate impact on integration risk. This connects directly to CPM itself: just as we identified critical activities in our application, we needed to identify critical dependencies in our team process."

**Formula breakdown:**
- Assumed/Anticipated: Integration would be highest-risk moment
- Happened: Proactive struct definition + pre-written tests → Day 2 integration passed first time
- Learned: Interface definition has disproportionate impact on integration risk
- Theory: Scope baseline management; CPM critical dependency concept applied to team process
- Future: Always define interface contracts before parallel development begins

---

## Key Points to Hit

- Each team member owns at least one reflection
- Speak in first person: "I assumed...", "I learned...", "I would..."
- Reflections must be SPECIFIC to your project (reference file names, specific moments)
- Connect every reflection to a named PM theory/framework
- End each with a concrete, actionable future behaviour

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
