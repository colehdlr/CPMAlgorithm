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

**Jamie (introduction):** Peer feedback pushed us from description to challenged assumptions. Each of us identified a specific mistake we made and what it cost the team.

**Jamie:** I assumed consensus meant the decision was settled. We had ADKAR's Awareness and Desire for C, but not Knowledge or Ability. My mistake: as Product Owner, my implicit authority delayed Samuel's pushback — he deferred to me, and I only noticed when he stopped challenging testing scope. That cost us a day of mounting frustration that could have been surfaced in hour one. In future, spike before committing when reversibility is low.

**Samuel:** I assumed I could write tests from inputs and outputs alone. My mistake: I didn't ask for help early enough because I felt incompetent at something I owned. The frustration wasn't just syntax — it was not understanding what correct looks like for the backward pass. That shift from 'this is hard' to 'I don't know what right looks like' is Schön's reflection-in-action — but I could only reframe because Jamie validated my new understanding. Alone, I'd have stayed stuck. In future, a 15-minute knowledge-sharing before testing begins.

**Cole:** I assumed my visualisation was correct because it looked right. My mistake: Activity D rendered wrong, and I nearly sent Jamie chasing a phantom bug in his algorithm. That's Wilemon and Thamhain's 'Communication Problems' — but through artefacts, not words. My confidence comes from UI work where 'looks right' usually is right. CPM exposed that limit: correctness here is mathematical, not perceptual. In future, pair visual output with automated verification.

**Hamza:** I nearly didn't flag the type mismatch because it felt like criticising their work. My mistake: I hesitated for 20 minutes before saying anything — time the team could have used. The real conflict was specification ambiguity — what the struct said versus what each person assumed. I spoke up only because existing trust overrode my discomfort. In future, assign interface ownership separately from module ownership so flagging mismatches is a role responsibility, not a personal confrontation.

**Jamie (capstone):** Same root across all four: we decomposed work but not understanding. Next time, a knowledge map alongside our WBS. One collective gap: we chose C unanimously but none of us challenged it — we confused agreement with due diligence. Countermeasure: a Devil's Advocate role for irreversible decisions. As we Adjourn — processes transfer but the trust enabling them does not. That's our next challenge: rebuilding relational foundations in new teams.
