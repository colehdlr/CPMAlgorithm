# Slide 5: CPM Walkthrough

**Speaker:** Jamie | **Time:** 1 minute 20 seconds

---

## On the Slide

- Diagram showing forward pass → backward pass → float calculation
- **Forward pass (convergence):** Activity F: ES = max(EF_E, EF_D) = max(15, 13) = **15**
- **Backward pass (divergence):** Activity A: LF = min(LS_B, LS_C) = min(5, 3) = **3**
- **PERT worked example:** Activity E — optimistic 5, most likely 7, pessimistic 12 → expected **7.5 days**
- Key insight: PERT duration = 23.8 days vs 22 deterministic → 95% range [20.2, 27.4] days
- A PM commits at 25, not 22

---

## Speaker Notes

Peer feedback said we explained code not concepts, so we rebuilt this section.

Forward pass: earliest start and finish — at convergence points, take the maximum. Activity F depends on both E and D. ES of F equals max of EF_E and EF_D — max of 15 and 13 is 15. D finishes early but F waits for E.

Backward pass reverses it. Activity A feeds both B and C. LF of A equals min of LS_B and LS_C — min of 5 and 3 is 3. The tightest successor constrains you. Float equals latest start minus earliest start. Zero float means critical.

PERT mode: Activity E — optimistic 5, most likely 7, pessimistic 12, expected 7.5 days. Critical path sums to 23.8 days with a 95% range of 20.2 to 27.4 days. A PM commits at 25, not 22. That's PERT's value: a range instead of false precision.

One limitation from our sprint: Samuel's parser struggle correlated with his testing confidence — violating PERT's independence assumption.
