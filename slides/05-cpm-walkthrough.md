# Slide 5: CPM Walkthrough

**Speaker:** Jamie | **Time:** 1 minute 20 seconds

---

## On the Slide

- Diagram showing forward pass → backward pass → float calculation
- **Worked example — Forward pass (convergence):** Activity F: ES = max(EF_E, EF_D) = max(15, 13) = **15**
- **Worked example — Backward pass (divergence):** Activity A: LF = min(LS_B, LS_C) = min(5, 3) = **3**
- The PERT formula: **Expected time = (O + 4M + P) / 6**
- Standard deviation: **σ = (P − O) / 6** (assumes beta distribution)
- Key insight: PERT project duration = 23.8 days vs 22 deterministic
- 95% confidence interval: [20.2, 27.4] days

**PERT Comparison Table — All 7 Activities:**

| Activity | Deterministic | O | M | P | PERT Expected | σ |
|----------|:---:|:---:|:---:|:---:|:---:|:---:|
| A (Requirements) | 3 | 2 | 3 | 5 | 3.2 | 0.50 |
| B (Design) | 4 | 3 | 4 | 7 | 4.3 | 0.67 |
| C (Database Setup) | 5 | 4 | 5 | 9 | 5.5 | 0.83 |
| D (Frontend Dev) | 6 | 4 | 6 | 10 | 6.3 | 1.00 |
| E (Backend Dev) | 7 | 5 | 7 | 12 | 7.5 | 1.17 |
| F (Integration) | 3 | 2 | 3 | 6 | 3.3 | 0.67 |
| G (Testing) | 4 | 3 | 4 | 7 | 4.3 | 0.67 |

**PERT Critical Path:** A(3.2) + C(5.5) + E(7.5) + F(3.3) + G(4.3) = **23.8 days**
**Critical Path Variance:** 0.25 + 0.69 + 1.37 + 0.45 + 0.45 = 3.21 | σ = 1.79 days

---

## Speaker Notes

Peer feedback said we explained code not concepts, so we rebuilt this section.

Forward pass: earliest start and finish — at convergence points, take the maximum. Activity F depends on both E and D. ES of F equals max of EF_E and EF_D — max of 15 and 13 is 15. D finishes early but F waits for E.

Backward pass reverses it. Activity A feeds both B and C. LF of A equals min of LS_B and LS_C — min of 5 and 3 is 3. The tightest successor constrains you. Float equals latest start minus earliest start. Zero float means critical. Free float — delay without affecting the next task, not just the project end.

Standard deviation for each activity: σ equals P minus O divided by 6. Assumes a beta distribution.

PERT mode: Activity E — optimistic 5, most likely 7, pessimistic 12, expected 7.5 days. Critical path variance sums to 3.21, giving a 95% range of 20.2 to 27.4 days. A PM commits at 25, not 22. That's PERT's value: a range instead of false precision.

One limitation from our sprint: Samuel's parser struggle correlated with his testing confidence — violating PERT's independence assumption.
