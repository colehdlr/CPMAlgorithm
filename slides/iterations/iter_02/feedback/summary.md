# Rubric Assessment — Reflective Development Showcase

**Slides assessed:** 01-title.md through 11-qa-preparation.md

## Overall Mark: 78 / 100

## Summary Table

| Criterion | Weight | Mark | Band |
|-----------|--------|------|------|
| 1. Understanding of Estimation & PM Concepts | 30% | 24/30 | A+ (80%) |
| 2. Teamwork and Collaboration | 30% | 23/30 | A (77%) |
| 3. Reflection on Team Dynamics | 20% | 16/20 | A+ (80%) |
| 4. Presentation Quality | 20% | 15/20 | A (75%) |
| **TOTAL** | **100%** | **78/100** | **A (high)** |

## Overall Strengths

1. **Technically accurate CPM implementation with PM reasoning:** The algorithm explanation (forward/backward pass, free/total float, critical path identification) is correct and consistently connected to PM significance — float as resource flexibility, critical path as risk focus. This goes beyond technical demonstration to show genuine understanding of WHY CPM matters to project managers.

2. **Critically evaluative reflections that interrogate assumptions:** The five-part reflection structure (assumption → event → learning → theory → future action) produces genuinely insightful reflections, particularly Jamie's ("consensus ≠ thoroughness") and Samuel's ("separating modules doesn't separate knowledge dependencies"). These demonstrate critical evaluation, not description.

3. **Specific, actionable lessons with transferable value:** Every reflection ends with a concrete future behaviour (not "communicate better" but "schedule a 15-minute knowledge-sharing session before testing begins"). These are implementable in any future team context.

4. **Clear role allocation with Belbin mapping and honest attribution:** The retrospective Belbin mapping ("which we discovered after the fact, not by planning around the theory") is more credible than forced theory application, and shows academic maturity.

5. **Multiple examples of proactive team support:** The type-mismatch catch, edge-case test, and visual-as-validation are specific, concrete instances of team members proactively supporting each other — not manufactured examples.

6. **Exceptional Q&A preparation:** 11 topic areas with specific questions, model answers, and techniques for uncertainty. This preparation is significantly above average and demonstrates depth of understanding beyond the presentation slides.

7. **Professional presentation structure:** Logical flow matching brief requirements, explicit timing, backup plans for demo failure, and natural-language speaker notes.

## Overall Weaknesses

1. **Missing critical analysis of WHY team strategies were effective in this context:** The slides describe strategies and outcomes but rarely analyse WHY a particular approach worked given the specific constraints of a 2-day sprint with 4 people. This is the single factor preventing Criterion 2 from reaching A+.

2. **PERT formula presented but not applied:** The formula E = (O + 4M + P) / 6 is correctly stated and contextualised, but never computed with actual numbers from the project. A worked example would demonstrate application, not just knowledge.

3. **TODO items indicate incomplete preparation:** Slides 4 and 7 contain explicit TODO markers for evidence artefacts (commit logs, chat screenshots, meeting notes). These should be completed before submission.

4. **Incomplete reference list:** Only 4 references listed despite citing Iron Triangle, PERT, McClelland, Greenleaf, WBS, Kanban, CHAOS Report, and Agile practices across the slides. Harvard style requires all in-text citations to appear in the reference list.

5. **Some theory connections are vague:** Cole's "quality management" and Hamza's "integration risk management" are generic descriptions rather than specific named frameworks with citations. Compare to Samuel's specific "Wilemon & Thamhain's 'Communication Problems' barrier."

6. **No formal WBS diagram:** The WBS concept is referenced and implicitly applied (modular decomposition) but never visually shown as a hierarchical breakdown structure.

7. **Engagement and feedback response cannot be assessed from slides:** Two of the four A+ criteria for Criterion 4 depend on live performance (engaging delivery, confident response to feedback). The preparation suggests strong performance is likely, but cannot be confirmed.

## Top Priority Improvements

### 1. Add Critical Analysis of WHY Strategies Worked (Criterion 2 — Slide 7 or 8)

**Impact:** Moves Criterion 2 from A to A+ (potential +2 to +4 marks)

**What to add (Slide 7, after resolution description):** "Strengths-based allocation worked because our 2-day timeline eliminated learning curves as an option — there was no time to develop new skills. The structured discussion resolved our conflict because it surfaced asymmetric information: Cole and Jamie knew progress was near-complete, while Hamza and Samuel knew difficulty was mounting. Equal airtime made the decision data-driven rather than personality-driven. These strategies were effective specifically because of our compressed timeline — in a longer project, we might choose rotation-based allocation to build broader capability, even at the cost of initial velocity."

---

### 2. Apply PERT Formula with Actual Numbers (Criterion 1 — Slide 5)

**Impact:** Strengthens A+ evidence for Criterion 1 (potential +1 to +2 marks)

**What to add:** "For example, our Backend Dev activity: Optimistic = 5 days, Most Likely = 7 days, Pessimistic = 12 days. Expected = (5 + 28 + 12) / 6 = 7.5 days, with standard deviation σ = (12 - 5) / 6 = 1.17 days. Our deterministic estimate of 7 days was slightly optimistic — a pattern consistent with our sprint experience where the parser took 3x longer than our single-point estimate."

---

### 3. Complete TODO Evidence Artefacts (Criterion 4 — Slides 4, 7)

**Impact:** Strengthens professionalism and evidence base (potential +1 to +2 marks across Criteria 2 and 4)

**What to add:** At minimum one commit log screenshot showing parallel development (Slide 4) and one group chat screenshot showing the C language debate or resolution (Slide 7). These provide verifiable evidence and visual variety.

---

### 4. Strengthen Cole's and Hamza's Theory Connections (Criterion 3 — Slide 8)

**Impact:** Strengthens A+ evidence for Criterion 3 (potential +1 mark)

**Cole — replace "quality management" with:** "This connects to the principle of 'visual management' — making problems visible in real-time rather than waiting for formal inspection. My visualisation functioned as what continuous integration calls a 'build radiator': an immediate, unambiguous signal of system health."

**Hamza — replace "integration risk management" with:** "This connects to Wilemon & Thamhain's (1983) 'Role Conflicts' barrier — the ambiguity wasn't in who owned which module, but in who owned the interface between modules. Explicit interface ownership is a separate responsibility from module ownership."

---

### 5. Complete the Reference List (Criterion 4 — Slide 10)

**Impact:** Addresses academic integrity requirement (potential +1 mark)

**Add:** Schwaber, K. and Sutherland, J. (2020); Highsmith, J. (2002); Larkowski, K. (2003); McGregor, D. (1960); PMI (2021); McClelland, D. (1961); Greenleaf, R.K. (1970); APM (2022); Derby, E. and Larsen, D. (2006).

---

### 6. Add a Visual WBS Diagram (Criterion 1 — Slide 4 or 6)

**Impact:** Provides formal PM artefact evidence (potential +1 mark)

**What to add:** A 3-level hierarchical diagram: Level 0 = "CPM Application"; Level 1 = "Parser", "Algorithm", "Tests", "Visualisation"; Level 2 = specific sub-tasks under each. Label explicitly as "Work Breakdown Structure (deliverable-based, Week 4)." This demonstrates formal application of a PM tool to the project.

---

### 7. Add Tuckman Staging to One Reflection (Criterion 3 — Slide 8)

**Impact:** Strengthens theoretical grounding of reflection (potential +0.5 to +1 mark)

**What to add (Samuel's reflection):** "This revealed that our Norming was incomplete — we'd agreed on workflow ('who does what') but not on knowledge flow ('who needs to understand what'). Tuckman's model treats Norming as a single transition, but in practice our team Normed at different layers at different speeds."

---

### 8. Name Leadership Model in Main Slides (Criterion 2 — Slide 2 or 4)

**Impact:** Explicitly addresses leadership element of Criterion 2 (potential +0.5 mark)

**What to add:** "Our leadership model was distributed and servant-oriented (Greenleaf) — each domain lead served others by removing their blockers rather than directing their work. Samuel's Scrum Master role focused on facilitation and obstacle removal, not task assignment."
