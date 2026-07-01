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

| WBS Package | Estimated | Actual | Expert Error | PERT Would Give |
|-------------|-----------|--------|--------------|-----------------|
| Parser (Samuel) | 1h | 3h | +200% | 1.4h |
| Algorithm (Jamie) | 3h | 4h | +33% | 3.3h |
| Visualisation (Cole) | 2h | 2.5h | +25% | 2.3h |

**Cost outcome:** Estimated £800 → Actual £1,000 (25% overrun). SPI hit 0.75 at Day 1 end — triggered MoSCoW replan. Recovered to 0.92 by Day 2 morning.

---

## Speaker Notes

What would you estimate the parser at? One hour? That's what we said. Actual: three — 200% error. PERT would have given 1.4 hours, halving the error. Analogous data from Python coursework scaled 2× for C gave 3 hours — matching actual. The hierarchy: analogous first, parametric, PERT, then expert judgement as fallback (Green, 2006).

With time fixed, we applied MoSCoW. When the parser overran, we knew what to protect. Our 25% cost overrun beat the CHAOS report's 43% average (Larkowski, 2003) because MoSCoW stopped scope expanding.

SPI 0.75 at Day 1 end told us we were 25% behind — triggering the replan. Day 2 morning recovered to 0.92. Resource levelling also hit us — CPM assumes unlimited resources, but Samuel couldn't test until Jamie's algorithm was done.
