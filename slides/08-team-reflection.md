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

**Jamie:** I assumed consensus meant the decision was settled. We had ADKAR's Awareness and Desire for C, but not Knowledge or Ability. My mistake: as Product Owner, my implicit authority delayed Samuel's pushback — he deferred to me, and I only noticed when he stopped challenging testing scope. That cost us a day of mounting frustration that could have been surfaced in hour one. In future, spike before committing when reversibility is low.

**Samuel:** I assumed I could write tests from inputs and outputs alone. My mistake: I didn't ask for help early enough because I felt incompetent at something I owned. I thought I was stuck on syntax, but actually I didn't understand what the right answer should look like for the backward pass. Jamie explaining the logic — not the code — unlocked me. That matches Schön's reflection-in-action: reframing the problem while you're in it. But I couldn't have reframed alone — I needed someone to validate my new understanding. In future, a 15-minute knowledge-sharing before testing begins.

**Cole:** I assumed my visualisation was correct because it looked right. My mistake: Activity D rendered wrong, and I nearly sent Jamie chasing a phantom bug in his algorithm. That's Wilemon and Thamhain's 'Communication Problems' — but through artefacts, not words. I'm used to UI work where if it looks right, it is right. But CPM is maths — looking right means nothing if the numbers are wrong. In future, pair visual output with automated verification.

**Hamza:** I nearly didn't flag the type mismatch because it felt like criticising their work. My mistake: I hesitated for 20 minutes before saying anything — time the team could have used. The real conflict was specification ambiguity — what the struct said versus what each person assumed. I spoke up only because existing trust overrode my discomfort. In future, assign interface ownership separately from module ownership so flagging mismatches is a role responsibility, not a personal confrontation.

**Jamie (capstone):** The common thread: we split up the work but not the understanding. Next time, we'd build a knowledge map alongside the WBS — who needs to know what from whom. One collective gap: we chose C unanimously but none of us challenged it. In future, assign a Devil's Advocate for irreversible decisions. And as we move to new teams — the processes we built here will transfer, but the trust won't. That's the harder thing to rebuild.
