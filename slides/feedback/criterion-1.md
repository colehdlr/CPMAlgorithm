# Criterion 1: Understanding of Estimation & PM Concepts (30%)

## Mark Awarded: 26 / 30

## Band: A+ (80-100)

## Rubric Band Placement

**Band above (N/A — this is the highest band):** N/A

**Band awarded — A+ (80-100):**
> "Application demonstrates exceptional understanding of estimation or critical path; calculations/processes are accurate and well-justified."

**Band below — A (70-79):**
> "Very strong understanding. Excellent implementation of concepts and justification."

## What Earns the Mark

**CPM algorithm correctly explained with forward/backward pass logic:**
- Slide 5 demonstrates convergence logic: "Activity F: ES = max(EF_E, EF_D) = max(15, 13) = **15**" — correct application of the maximum rule at merge nodes.
- Slide 5 demonstrates divergence logic: "Activity A: LF = min(LS_B, LS_C) = min(5, 3) = **3**" — correct application of the minimum rule at burst nodes.
- Float calculation explicitly defined: "Float equals latest start minus earliest start. Zero float means critical."
- Free float distinguished from total float in Speaker Notes (Slide 5): "Free float — delay without affecting the next task, not just the project end."
- Slide 3 demo output shows accurate ES, EF, LS, LF, and Float values for all 7 activities — verified correct.

**PERT applied with accurate calculations:**
- PERT formula stated and applied: "Expected time = (O + 4M + P) / 6" (Slide 5).
- Standard deviation formula: "σ = (P − O) / 6" with beta distribution assumption stated.
- Full PERT comparison table (Slide 5) shows all 7 activities with O, M, P, Expected, and σ values — all calculations verified correct (e.g., Activity E: (5 + 28 + 12)/6 = 7.5 ✓).
- Critical path variance: 0.25 + 0.69 + 1.37 + 0.45 + 0.45 = 3.21 ✓. σ = √3.21 = 1.79 ✓.
- 95% confidence interval: 23.8 ± 1.96(1.79) = [20.3, 27.3] — slide states [20.2, 27.4], minor rounding difference, acceptable.
- PM application articulated: "A PM commits at 25, not 22. That's PERT's value: a range instead of false precision" (Slide 5 Speaker Notes).

**Estimation concepts APPLIED to the project, not just defined:**
- Slide 6 compares expert judgement, PERT, and analogous estimation against actual outcomes for three WBS packages — not textbook definitions but real comparison with error percentages.
- Estimation hierarchy referenced with justification: "analogous first, parametric, PERT, then expert judgement as fallback" (Slide 6 Speaker Notes), citing Week 4 lecture ordering.
- Green's (2006) estimation process applied: "scope, deliverables, tasks, then what history tells us."
- CHAOS report contextualisation: "Our 25% cost overrun beat the CHAOS report's 43% average" (Slide 6).

**Iron Triangle genuinely applied:**
- Slide 6: "Iron Triangle: accepted higher time cost for deeper understanding" — C language decision justified as a conscious trade-off.
- MoSCoW as scope management: "Fixed time → scope must flex" (Slide 6) — correctly identifies time as the fixed constraint and scope as the flex lever.

**WBS with justification:**
- Responsibility-based WBS chosen with explicit reasoning: "chosen because our challenge was four people coding in parallel, satisfying the 100% rule" (Slide 4).
- Alternative types named and rejected: "over deliverable-based or phase-based" (Slide 4).
- Level 2 decomposition shown with all packages mapped to owners.

**EVA applied as monitoring tool:**
- Two-checkpoint EVA (Slide 6) with PV, EV, SPI, CPI, and EAC calculations.
- EAC formula shown: "EAC = BAC ÷ CPI = £800 ÷ 0.75 = £1,067."
- Budget basis justified: "4 developers × 8 hours × £25/hr opportunity cost = £800."
- EVA linked to decision-making: "SPI 0.75 at Day 1 end... triggering our MoSCoW replan" (Slide 6 Speaker Notes).

**Resource levelling identified:**
- Slide 4 Speaker Notes: "Samuel was blocked on testing until Algorithm completed — a resource constraint that converted his float into a sequential dependency. That's resource levelling."
- Slide 6 Speaker Notes: "CPM assumes unlimited resources, but Samuel couldn't test until Jamie's algorithm was done."

**Critical limitation identified:**
- PERT independence assumption violation: "Samuel's parser struggle correlated with his testing confidence — violating PERT's independence assumption" (Slide 5 Speaker Notes). This demonstrates understanding beyond the formula.

**Justification for WHY with reference to PM principles:**
- Every major decision (language, estimation method, scope prioritisation, WBS type, monitoring approach) is justified with explicit reference to a PM principle or lecture concept.

## What Holds the Mark Back

1. **PERT applied retrospectively rather than prospectively:** The PERT comparison in Slide 6 is retrospective analysis ("PERT Would Give" column compared against actuals). While the Q&A preparation (Slide 11) mentions "We applied PERT during our Day 1 replan," this real-time application isn't shown on the presentation slides themselves. To reach 90+, the slides would need to show PERT being used as a live planning tool (e.g., the Day 1 replan decision with O/M/P estimates made before outcomes were known).

2. **No explicit critical path network diagram description on slides:** Slide 5 says "Diagram showing forward pass → backward pass → float calculation" as a placeholder rather than showing the actual AON network topology with node boxes. The demo output (Slide 3) shows text output. To reach 90+, the slide content would include or describe the visual network representation with node structure (ES/EF/LS/LF boxes).

3. **Gantt chart is simplified:** The Sprint Gantt Chart (Slide 4) uses block characters rather than showing dependencies with arrows. The critical path through the Gantt is stated but the dependency relationships between non-critical and critical tasks could be visually clearer.

4. **EVA limitations not discussed in main slides:** The limitations of EVA (subjective percentage-complete for knowledge work) appear only in Q&A preparation (Slide 11), not in the presented material.

## Actionable Improvements

1. **Slide 6:** Add one row to the Estimation vs Reality table showing a *prospective* PERT estimate made before work began (e.g., "Day 1 AM estimate for Algorithm: O=2h, M=3h, P=5h → Expected 3.2h") to demonstrate PERT as a planning tool, not just retrospective validation.

2. **Slide 5:** Replace the "Diagram showing forward pass → backward pass → float calculation" bullet with a description of the AON node format (e.g., "Each node shows: Activity Name | ES EF | Duration | LS LF | Float") to demonstrate understanding of network diagram conventions.

3. **Slide 6 Speaker Notes:** Add one sentence acknowledging EVA's limitation: "EVA relies on objective percentage-complete — our WBS packages were countable deliverables, which made Day 1's checkpoint reliable."

4. **Slide 4:** Add dependency arrows notation to the Gantt chart or add a brief note in Speaker Notes explaining how dependencies were tracked (e.g., "Critical path dependencies shown by sequential scheduling; parallel tasks have explicit float noted").

## Conclusion

The work demonstrates exceptional understanding of both CPM and estimation concepts. Calculations are accurate throughout — forward/backward pass logic, PERT formulas, EVA metrics, and variance calculations are all correct. Crucially, concepts are not merely defined but applied to the team's own sprint with genuine analytical insight (e.g., identifying PERT's independence assumption violation, using EVA to trigger scope replanning). The justification consistently references PM principles. The mark sits at 26/30 (87%) rather than higher because PERT is primarily used retrospectively in the presented material, and some depth (EVA limitations, AON diagram conventions) is reserved for Q&A rather than the main presentation.
