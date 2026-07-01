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

What would you estimate the parser at? One hour? That's what we said. Actual: three — 200% error. When the parser overran Day 1 PM, we re-estimated remaining work using PERT three-point estimates — that told us visualisation was still achievable but PERT mode was a stretch. That's when we applied MoSCoW: protect the Musts, keep the Should, drop the Could if needed.

PERT retrospectively would have given 1.4 hours for the parser — halving the error. Analogous data from Python coursework scaled 2× for C gave 3 hours — matching actual. The hierarchy: analogous first, parametric, PERT, then expert judgement as fallback (Green, 2006).

Our 25% cost overrun is below the CHAOS report's 43% average for software projects (Larkowski, 2003) — the scale is different but the principle is the same: scope control limits overrun.

We reconstructed EVA after the sprint to understand what happened. Budget was £800 — four people, two days, at £25/hr opportunity cost. Planned Value at Day 1 end was £400 — half the timeline done. Earned Value was £320 — only Parser and Visualisation were complete. SPI = 320 ÷ 400 = 0.80. In reality, what triggered our replan wasn't a formal SPI calculation — it was simply noticing we were behind. EVA gives us the vocabulary to quantify how far behind.
