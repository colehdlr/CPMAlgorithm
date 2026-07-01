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

**Jamie (introduction):** Peer feedback pushed us from description to challenged assumptions. Each assumption surfaced at a different Tuckman stage — mine during Storming, Samuel's at the Storming-Norming transition, Cole's during Norming, Hamza's throughout.

**Jamie:** I assumed consensus meant the decision was settled. We had ADKAR's Awareness and Desire for C, but not Knowledge or Ability. As Product Owner, my implicit authority delayed Samuel's pushback — he deferred to me more after, and I only noticed when he stopped challenging testing scope. In future, spike before committing when reversibility is low.

**Samuel:** I assumed I could write tests from inputs and outputs alone. But I needed to understand how the backward pass updates LF values. The frustration wasn't just syntax — it was feeling incompetent at something I owned. That real-time shift from 'this is hard' to 'I don't understand what correct looks like' is Schön's reflection-in-action. But Schön assumes I can reframe alone — I could only do it because Jamie validated my new understanding. Without that, reflection-in-action risks confident misunderstanding. In future, a 15-minute knowledge-sharing before testing.

**Cole:** I assumed my visualisation was correct because it looked right — Activity D rendered wrong, nearly sending Jamie chasing a phantom bug. That's Wilemon and Thamhain's 'Communication Problems' through artefacts, not words. My confidence comes from UI work where 'looks right' usually is right — CPM exposed that limit, correctness here is mathematical, not perceptual. In future, pair visual feedback with automated verification.

**Hamza:** I nearly didn't flag the type mismatch because it felt like criticising their work. The real conflict was specification ambiguity — what the struct said versus what each person assumed. Psychological safety isn't binary — I spoke up only because existing trust overrode that discomfort. In future, assign interface ownership separately from module ownership.

**Jamie (capstone):** Same root across all four: we decomposed work but not understanding. Next time, a knowledge map alongside our WBS. One collective gap: we chose C unanimously but all underestimated it — groupthink at Forming stage, prioritising affiliation over critical evaluation. Countermeasure: a Devil's Advocate role for irreversible decisions. As we Adjourn — processes transfer but the trust enabling them does not. That's our next challenge: rebuilding relational foundations in new teams.
