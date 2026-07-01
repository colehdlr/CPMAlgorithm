# Slide 6: Key Decisions

**Speaker:** Hamza | **Time:** 1 minute

---

## On the Slide

| Decision | What We Did | PM Justification |
|----------|-------------|------------------|
| Struct split | Activity → Activity + CPMResult | Modular decomposition — isolate parsing from calculation (WBS principle) |
| Language | C over Python & JS (after debate) | Iron Triangle: accepted higher time cost for deeper understanding |
| Estimation approach | Expert judgement + bottom-up | Each person estimated their own WBS package |
| Scope prioritisation | MoSCoW: Must (CPM calc, parser), Should (visualisation), Could (PERT), Won't (GUI input) | Fixed time → scope must flex |
| Cost outcome | Estimated: £800 → Actual: £1,000 (25% overrun) | Below CHAOS report's 43% average |

**Estimation vs Reality:**

| WBS Package | Estimated | Actual | Expert Error | PERT Would Give | PERT Error |
|-------------|-----------|--------|--------------|-----------------|------------|
| Parser (Samuel) | 1h | 3h | +200% | 1.4h | +114% |
| Algorithm (Jamie) | 3h | 4h | +33% | 3.3h | +21% |
| Visualisation (Cole) | 2h | 2.5h | +25% | 2.3h | +9% |

**Earned Value Analysis (Two Checkpoints):**

| Metric | Day 1 End | Day 2 Morning (post-replan) |
|--------|-----------|---------------------------|
| PV (Planned Value) | £400 | £600 |
| EV (Earned Value) | £300 | £550 |
| SPI | 0.75 (behind) | 0.92 (recovering) |
| CPI | 0.75 | 0.88 |
| EAC | £1,067 | £1,023 |

**EAC = BAC ÷ CPI = £800 ÷ 0.75 = £1,067** (Day 1 — 33% over budget forecast)
**Budget basis:** 4 developers × 8 hours × £25/hr opportunity cost = £800

---

## Speaker Notes

Before I show the numbers — what would you estimate the parser at? One hour? That's what we said. Actual: three — 200% error. PERT would have given 1.4 hours, halving the error. Analogous data from Python coursework scaled 2× for C gave 3 hours — matching actual. Week 4's hierarchy: analogous first, parametric, PERT, then expert judgement as fallback. Our estimation followed Green's (2006) process: scope, deliverables, tasks, then what history tells us.

With time fixed, we applied MoSCoW. When the parser overran, we knew what to protect. Our 25% cost overrun beat the CHAOS report's 43% average (Larkowski, 2003) because MoSCoW stopped scope expanding.

EVA: SPI 0.75 at Day 1 end. EAC = BAC ÷ CPI = £800 ÷ 0.75 = £1,067 — triggering our MoSCoW replan. Day 2 morning SPI recovered to 0.92. Resource levelling (Week 4) also hit us — CPM assumes unlimited resources, but Samuel couldn't test until Jamie's algorithm was done.
