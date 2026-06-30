# Criterion 2: Teamwork and Collaboration (30%)

## Mark Awarded: 23 / 30

## Band: A (70-79)

## Rubric Band Placement

**Band above — A+ (80-100):**
> "Exceptional collaboration and leadership; clear role allocation; team supported each other; challenges handled proactively. The approaches put in place to manage team dynamics are effective, and there is clear evidence of not only learning that informs future team working environments, but also critical analysis of why such strategies were effective in this context."

**Band awarded — A (70-79):**
> "Excellent collaboration and leadership; roles clear; minor challenges managed. The approaches put in place to manage team dynamics are effective, and there is clear evidence of learning that informs future team working environments."

**Band below — B (60-69):**
> "Good collaboration; some role clarity issues; evidence of leadership and moderate handling of challenges. The approaches put in place to manage team dynamics are effective and well-thought-out."

## What Earns the Mark

### Clear Role Allocation (Slide 2)

Role allocation is explicit, justified, and mapped to theory:

| Name | Role | Justification | Belbin Role |
|------|------|---------------|-------------|
| Samuel | Dev + Scrum Master | "Knowledge of team member strengths, able to delegate effectively" | Co-ordinator |
| Jamie | Dev + Product Owner | "Strong understanding of CPM from additional research" | Specialist |
| Cole | Dev + UI | "Prior RayLib experience, UX seminar attendance" | Implementer |
| Hamza | Dev + QA | "Critical views on projects, experienced at finding issues" | Monitor Evaluator |

The speaker notes add: "These map to Belbin's team roles — Co-ordinator, Specialist, Implementer, and Monitor Evaluator — which we discovered after the fact, not by planning around the theory." This is honest and credible — the Belbin mapping is retrospective, not forced.

### Evidence Team Supported Each Other (Slides 4, 7, 8)

Multiple specific instances of mutual support:

1. **Cole's visual output provided immediate feedback to Jamie:** "My visual output also gave Jamie immediate feedback on whether the CPM calculation was correct — the rendering became an extra test surface." (Slide 4) — One member's work directly supported another's quality.

2. **Samuel's tests caught an edge case, fixed as a team:** "My tests caught an edge case with duration values that would have broken the calculation. We fixed it together as a team." (Slide 4) — Support through collective problem-solving.

3. **Hamza flagged type mismatch before integration:** "I spotted that Jamie's CPM implementation was using different types to Cole's rendering engine. I flagged this before it caused integration bugs." (Slide 4) — Proactive support preventing problems.

4. **C language resolution:** "We reached a mutual understanding: stick with C, but delegate specific refactors to team members who could handle them fastest." (Slide 7) — Support through redistribution based on capability.

### Challenges Handled Proactively (Slides 4, 7)

The rubric requires challenges handled *proactively* (not reactively) for A+. The evidence is:

- **Proactive:** Hamza's type mismatch catch — "flagged this before it caused integration bugs" (Slide 4). This IS proactive — the problem was identified before it manifested.
- **Proactive:** Samuel's edge-case test — tests were "built into the process" not "bolted on" (Slide 4). Proactive quality management.
- **Partially reactive:** The C language debate (Slide 7) — friction emerged DURING implementation, and the resolution came AFTER the problem surfaced. The slide acknowledges: "Further into implementation, Hamza and Samuel found that C was slowing us down." This is reactive conflict resolution (good, but not proactive).

### Team Dynamics Strategies (Slides 2, 4, 7, 8)

Strategies identified:
- Strengths-based role allocation (Slide 2)
- Kanban with pull-based task selection (referenced in Q&A prep, Slide 11)
- Pair-programming as default response to blockers (Q&A prep)
- 15-minute check-ins at start and end of day (Q&A prep)
- Structured discussion for conflict resolution — "everyone got equal airtime" (Slide 7)

These strategies appear effective — the team delivered a working application with all members contributing.

### Learning That Informs Future Team Working (Slide 8)

Each reflection ends with a specific, actionable future behaviour:
- Jamie: "I would push for a short spike or prototype before committing the whole team to a technology choice."
- Samuel: "I would schedule a 15-minute knowledge-sharing session before testing begins."
- Cole: "I would build visual feedback earlier in the development cycle."
- Hamza: "I would schedule a mid-sprint alignment check specifically for cross-module type consistency."

These are specific enough to be implementable in a future team context.

## What Holds the Mark Back

### Critical Analysis of WHY Strategies Were Effective — Insufficient for A+

This is the distinguishing criterion between A and A+. The rubric requires "critical analysis of why such strategies were effective in this context."

**What's present:** The slides explain WHAT strategies were used and WHAT was learned. The reflections analyse what went wrong and what would be done differently.

**What's missing:** A meta-level analysis of WHY the specific strategies (strengths-based allocation, Kanban, pair-programming as blocker response) worked in THIS particular context. For example:

- Why did strengths-based allocation work here but might not elsewhere? The slides don't analyse: "Strengths-based allocation worked because our two-day timeline made learning curves unacceptable — there was no time for anyone to develop a new skill. In a longer project, rotation-based allocation might build broader team capability at the cost of initial velocity."
- Why did Kanban work over Scrum in this context? The Q&A prep has this reasoning, but it doesn't appear in the main presentation slides.
- Why did the structured discussion resolve the C language conflict? The slides describe the process ("everyone got equal airtime") but don't critically analyse WHY equal airtime produced consensus — was it because the dissenting members felt heard, or because the data (proximity to completion) was compelling, or both?

To reach A+, the slides would need explicit statements connecting strategy effectiveness to contextual factors.

### Some Evidence Is in Q&A Prep Rather Than Presentation (Slide 11)

Several strong teamwork examples (team contract, McClelland's needs, Wilemon & Thamhain barriers) are thoroughly prepared in Q&A but not presented in the main slides. The Q&A preparation is exemplary, but the marker can only credit what is presented.

### TODO Items Suggest Incomplete Evidence (Slides 4, 7)

Slide 4: "TODO: Add at least 2 of these as small visuals" (commit log, test screenshot, group chat message).
Slide 7: "TODO: Add at least 1 of these" (group chat screenshot, meeting notes).

These artefacts would provide concrete evidence of collaboration beyond verbal claims. Their absence weakens the evidence base.

### Servant Leadership Not Explicitly Named in Main Slides

The Q&A preparation references servant leadership (Greenleaf), but the main slides don't explicitly name the leadership model adopted. Slide 2 shows a Co-ordinator role, but doesn't connect this to a leadership theory beyond Belbin.

## Actionable Improvements

1. **Slide 7 or 8 — Add critical analysis of WHY strategies worked:** After describing the structured discussion resolution, add: "This worked because our two-day timeline meant there was no 'next sprint' to defer the decision to — the constraint forced immediate resolution. Wilemon & Thamhain's recommendation to 'discover conflicting differences early' was effective precisely because our project lifecycle was so compressed that 'early' and 'late' were separated by hours, not weeks. In a longer project, the same conflict might have been deferred and festered."

2. **Slide 2 — Add WHY strengths-based allocation was effective here:** Add to speaker notes: "Strengths-based allocation (Belbin, 2010) was effective in our context because our 2-day timeline eliminated the option of learning on the job. In a longer project, rotation-based allocation might build broader capability — our approach traded team development for immediate velocity, which was the right trade-off given time constraints."

3. **Slides 4 and 7 — Complete the TODO items:** Add at least one concrete artefact (commit log, chat screenshot, or meeting notes) per slide to provide verifiable evidence of collaboration claims.

4. **Slide 4 or 7 — Name leadership model explicitly:** Add one sentence: "Our approach maps to Servant Leadership (Greenleaf) — each domain lead served others by removing their blockers rather than directing their work."

5. **Slide 7 — Analyse WHY equal airtime produced resolution:** Add to speaker notes: "The structured discussion worked because it addressed what Wilemon & Thamhain (1983) identify as the root of 'Differing Outlooks' — each member had different information (Cole and Jamie knew progress was near-complete; Hamza and Samuel knew difficulty was mounting). Equal airtime surfaced this asymmetric information, making the decision data-driven rather than personality-driven."

## Conclusion

The slides demonstrate excellent collaboration with clear role allocation, multiple specific instances of mutual support, and some genuinely proactive challenge management. The learning that informs future work is specific and actionable. The mark sits at 77% (23/30) — solidly in the A band — because the work clearly demonstrates effective team dynamics and learning, but stops short of the critical meta-analysis required for A+. The distinguishing gap is explicit reasoning about WHY particular strategies were effective in THIS two-day sprint context as opposed to other contexts. The Q&A preparation shows this depth of thinking exists within the team; it simply needs to be surfaced in the presented slides.
