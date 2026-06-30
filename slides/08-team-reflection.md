# Slide 8: Team Reflection

**Speaker:** Jamie (introduces), then each member delivers their own reflection | **Time:** 2 minutes

---

## On the Slide

- Brief bullet per person (verbal elaboration does the work):
  - Jamie: Language decision and estimation
  - Samuel: Testing and knowledge sharing
  - Cole: UI as validation tool
  - Hamza: Integration oversight

---

## The Five-Part Reflection Formula

> "I assumed [X] → [Y] happened → I learned [Z] → This connects to [theory] → In future I would [action]"

This is the ONLY structure that scores 80%+. Descriptive reflection ("we used Kanban") caps at 50-59%.

---

## Jamie's Reflection: Language Decision

- "I assumed that because we all agreed on C initially, the language decision was settled."
- "In practice, Hamza and Samuel found C significantly slowed their implementation — what seemed like consensus was actually untested assumption."
- "I learned that agreement at the start doesn't mean the decision was thorough. We estimated based on enthusiasm, not effort."
- "This connects to estimation principles (K15) — we should have applied something like three-point estimation to the language choice itself: best case, worst case, most likely development time in each language."
- "In future, I would push for a short spike or prototype before committing the whole team to a technology choice. A spike costs time — in a 2-day sprint, half a day is 25% of our budget. But the cost of NOT spiking was higher: half a day of rework plus team friction. The lesson isn't 'always spike' — it's 'spike when reversibility is low and the whole team gets locked in.'"

---

## Samuel's Reflection: Testing and Knowledge Silos

- "I assumed that writing tests independently of the algorithm would be straightforward — I just needed to know the expected outputs."
- "In practice, I couldn't write meaningful test assertions without understanding how the backward pass updates LF values. I had to interrupt Jamie for an explanation."
- "I learned that separating code modules doesn't separate knowledge dependencies — the tester needs to understand the algorithm's logic, not just its outputs."
- "This connects to Wilemon & Thamhain's 'Communication Problems' barrier (Week 2) — not a lack of talking, but a lack of shared technical understanding. It also revealed that our Norming was incomplete — we'd agreed on workflow ('who does what') but not on knowledge flow ('who needs to understand what'). Tuckman's model treats Norming as a single transition, but we Normed at different layers at different speeds."
- "In future, I would schedule a 15-minute knowledge-sharing session before testing begins, so everyone understands the data flow."

---

## Cole's Reflection: Visual Feedback as Validation

- "I assumed my role was just to render the output — take the CPM results and draw them."
- "In practice, my visualisation became a validation tool. When the diagram showed a clearly wrong layout, it surfaced bugs in the CPM calculation that the unit tests hadn't caught yet."
- "I learned that visual output has disproportionate value in catching errors — it's a form of verification that complements automated testing."
- "This connects to the principle of visual management — making problems visible in real-time rather than waiting for formal inspection. My graph served the same function as a build radiator in continuous integration: an immediate, unambiguous signal of whether the system is healthy. You don't need to run a test suite to know something's wrong when the diagram looks broken."
- "In future, I would build visual feedback earlier in the development cycle, not treat it as a final polish step."

---

## Hamza's Reflection: Integration Oversight

- "I assumed that if everyone followed the same spec, integration would be straightforward."
- "In practice, Jamie's CPM implementation was using different types to Cole's rendering engine — they'd interpreted the struct differently."
- "I learned that a written spec isn't enough. Someone needs to actively check alignment between modules during development, not just at integration time."
- "This connects to Wilemon & Thamhain's (1983) 'Role Conflicts' barrier — the ambiguity wasn't in who owned which module, but in who owned the interface between modules. Nobody was explicitly responsible for type consistency across boundaries. My QA role ended up filling that gap, but it happened reactively rather than by design."
- "In future, I would explicitly assign interface ownership as a separate responsibility from module ownership, and schedule a mid-sprint alignment check specifically for cross-module type consistency."

---

## Key Rules for Delivery

- Each person speaks in FIRST PERSON: "I assumed...", "I learned..."
- Each reflection must be SPECIFIC to your project (reference actual files, actual moments)
- 30 seconds per reflection maximum
- End each with a concrete, actionable future behaviour — not "I'd communicate better"

---

## KSBs Signalled

- **K8** — understanding how teams work (knowledge silos, integration challenges)
- **K9** — leadership (proactive oversight, servant leadership through unblocking)
- **B5** — presenting conclusions truthfully (admitting what went wrong)
- **B2** — independent and team working (where independence caused friction)
