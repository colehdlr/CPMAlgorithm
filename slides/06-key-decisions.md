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

**EVA (reconstructed retrospectively to demonstrate understanding):**
Budget: 4 devs × 8h × £25/hr = £800 | PV at Day 1 end = £400 (half timeline elapsed) | EV = £320 (2 of 5 packages complete) | SPI = 320÷400 = **0.80** → triggered MoSCoW replan. Day 2 AM: recovered to 0.92.

---

## Speaker Notes

Three decisions to highlight. Language: we chose C over Python — an Iron Triangle trade-off. Fixed time meant scope had to flex, and we accepted higher time cost for deeper understanding. Estimation: each person estimated their own package using expert judgement.

What would you estimate the parser at? One hour? That's what we said. Actual: three — 200% error. When it overran, we re-estimated remaining work using PERT three-point estimates. That told us visualisation was still achievable but PERT mode was a stretch — so we applied MoSCoW: protect the Musts, keep the Should, drop the Could if needed.

We reconstructed EVA after the sprint. Budget was £800, Planned Value at Day 1 end was £400, Earned Value was £320 — only two packages complete. SPI = 0.80. What actually triggered our replan was noticing we were behind; EVA gives us the vocabulary to quantify it. By Day 2 morning, SPI recovered to 0.92.
