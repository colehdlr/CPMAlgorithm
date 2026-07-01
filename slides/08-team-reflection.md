# Slide 8: Team Reflection

**Speaker:** Jamie (introduces), then each member delivers their own reflection | **Time:** 2 minutes 30 seconds

---

## On the Slide

| Member | Assumption Challenged | Theory | Future Action |
|--------|----------------------|--------|---------------|
| Jamie | Consensus = rigour | ADKAR (Hiatt, 2006) | Spike before committing when reversibility is low |
| Samuel | Tests only need I/O specs | Schön (1983) reflection-in-action | 15-min knowledge-sharing session before testing |
| Cole | Looks right = is correct | Wilemon & Thamhain: Communication Problems | Pair visual feedback with automated tests |
| Hamza | Shared spec ≠ shared understanding | Psychological safety (Edmondson, 1999) | Assign interface ownership separately |

- **Team insight:** We decomposed work but not knowledge — WBS needs a knowledge map alongside it

---

## Speaker Notes

**Jamie (introduction):** Each of us identified a specific mistake we made and what it cost the team.

**Jamie:** I assumed consensus meant the decision was settled. We had ADKAR's Awareness and Desire for C, but not Knowledge or Ability. My mistake: my implicit authority as Product Owner delayed Samuel's pushback. I only noticed when he stopped challenging testing scope. In future, spike before committing when reversibility is low.

**Samuel:** I assumed I could write tests from inputs and outputs alone. My mistake: I didn't ask for help early enough because I felt incompetent at something I owned. I thought I was stuck on syntax, but actually I didn't understand what correct looks like for the backward pass. Jamie explaining the logic — not the code — unlocked me. That's Schön's reflection-in-action: reframing the problem while you're in it. In future, a 15-minute knowledge-sharing before testing begins.

**Cole:** I assumed my visualisation was correct because it looked right. My mistake: Activity D rendered wrong, and I nearly sent Jamie chasing a phantom bug. That's Wilemon and Thamhain's 'Communication Problems' — through artefacts, not words. I'm used to UI work where if it looks right, it is right. CPM is maths — looking right means nothing if the numbers are wrong. In future, pair visual output with automated verification.

**Hamza:** I nearly didn't flag the type mismatch because it felt like criticising their work. My mistake: I hesitated for about 20 minutes before saying anything — time the team could have used. I spoke up only because existing trust overrode my discomfort. In future, assign interface ownership separately from module ownership so flagging mismatches is a role responsibility, not a personal confrontation.

**Jamie (capstone):** Common thread: we split up the work but not the understanding. Next time, a knowledge map alongside the WBS. One collective gap: we chose C unanimously but none of us challenged it — in future, assign a Devil's Advocate for irreversible decisions.
