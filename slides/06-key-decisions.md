# Slide 6: Key Decisions

**Speaker:** Hamza | **Time:** 1 minute

---

## On the Slide

| Decision | What We Did | PM Justification |
|----------|-------------|------------------|
| Language | C over Python & JS (after debate) | Iron Triangle: accepted higher time cost for deeper understanding |
| Scope | MoSCoW: Must (CPM calc, parser), Should (visualisation), Could (PERT), Won't (GUI input) | Fixed time → scope must flex |
| Estimation | Expert judgement + bottom-up | Each person estimated their own WBS package |

**Estimation vs Reality:**

| WBS Package | Estimated | Actual | Expert Error | PERT (used in Day 1 replan) |
|-------------|-----------|--------|--------------|-----------------|
| Parser (Samuel) | 1h | 3h | +200% | 1.4h |
| Algorithm (Jamie) | 3h | 4h | +33% | 3.3h |
| Visualisation (Cole) | 2h | 2.5h | +25% | 2.3h |


---

## Speaker Notes

Three decisions to highlight. Language: we chose C over Python — an Iron Triangle trade-off. Fixed time meant scope had to flex, and we accepted higher time cost for deeper understanding. Estimation: each person estimated their own package using expert judgement.

What would you estimate the parser at? One hour? That's what we said. Actual: three — 200% error. When it overran, we re-estimated remaining work using PERT three-point estimates. That told us visualisation was still achievable but PERT mode was a stretch — so we applied MoSCoW: protect the Musts, keep the Should, drop the Could if needed.

By Day 1 end we were clearly behind — that's when MoSCoW kicked in. We protected the Musts, confirmed the Should was still achievable, and accepted the Could might get dropped.
