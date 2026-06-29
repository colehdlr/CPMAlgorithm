# Analysis: Slide 02 — Live Demo

## 1. Course Concepts Already Referenced

- **CPM scheduling concepts**: The demo directly demonstrates forward pass (ES/EF), backward pass (LS/LF), float calculation, and critical path identification — all core to Week 4's content on project planning, estimation, and scheduling.
- **Project estimation relevance**: The output demonstrates how duration drives project timeline — connects to Week 4's "Principles of estimating cost, and time resource constraints" (K15).
- **Float as PM resource**: The script explicitly states "a project manager could delay Design or Frontend Development by up to 2 days, or reallocate their resources" — this frames float as a management tool, not just a number.
- **Convergence point logic**: Calling out "ES=15 because F depends on both D and E, and E does not finish until day 15" demonstrates understanding of the MAX operation at merge nodes.

## 2. Course Concepts MISSING — With Specific Suggestions

### A. Iron Triangle / Triple Constraint (Week 4, Page 5)

**Where to add:** When explaining what CPM tells a project manager.

**Suggested script addition:** After "Project duration: 22 days", add:
> "CPM addresses the TIME vertex of the Iron Triangle directly. By identifying the critical path, a project manager knows which activities constrain the schedule — and can then make informed trade-offs against cost and scope."

### B. Work Breakdown Structure (Week 4, Pages 13-14)

**Where to add:** When showing the activity list in the terminal output.

**Suggested script addition:** Before running the demo, add:
> "The seven activities you see correspond to a deliverable-based WBS — Requirements, Design, Database Setup, Frontend, Backend, Integration, and Testing — decomposed to the work-package level that CPM requires."

### C. Estimation Methods — Three-Point and Analogous (Week 4, Page 7)

**Where to add:** When discussing what a PM would do with this output.

**Suggested script addition:** After mentioning float and resource reallocation:
> "In practice, a project manager would derive these durations using estimation techniques such as three-point estimation — combining optimistic, most likely, and pessimistic values — rather than single-point estimates. Our application currently uses deterministic durations, which assumes estimation has already occurred."

### D. Gantt Chart Relationship (Week 4, Pages 15-16)

**Where to add:** When showing the AON network diagram.

**Suggested script addition:**
> "The AON diagram shows dependencies and critical path — information a Gantt chart alone does not inherently reveal. In practice, both would be used together: the AON for path analysis, the Gantt for schedule communication to stakeholders."

### E. Project Success Measurement (Week 4, Page 5)

**Where to add:** As framing for why CPM matters.

**Suggested opening line enhancement:**
> "CPM answers the fundamental question of project success: will we deliver within the timeline? The Standish Group's CHAOS report found 66% of software projects fail — often because critical dependencies were not identified and managed."

Reference: Larkowski (2003) as cited in Week 4, Page 4.

## 3. Exact Terminology and Academic References to Cite

- "Principles of estimating cost, and time resource constraints within digital and technology solutions activities" — K15 verbatim
- "How do we measure a project's success? Is the project within budget? Is the project within the timeline? Is the project within scope?" (Week 4, Page 5) — the Iron Triangle framing
- "Work Breakdown Structure: a hierarchical structure of project activity... its focus is on 'work' not 'things'" (Week 4, Page 13)
- "Sets the foundation for creating a Gantt chart" (Week 4, Page 13)
- "Three-point estimation: using a weighted average that considers the best-case, worst-case and most likely durations" (Week 4, Page 7)
- Kelley, J.E. and Walker, M.R. (1959) 'Critical-path planning and scheduling', Proceedings of the Eastern Joint Computer Conference, pp. 160-173.
- Green, C. (2006) 'Estimating as an art — what it takes to make good art', PMI Global Congress 2006.

## 4. KSBs Addressed

| KSB | How Addressed |
|-----|---------------|
| **K15** | Strongly — the demo directly shows estimation outputs (durations, float, critical path duration) that inform cost/time planning |
| **S6** | Strongly — demonstrates a tool for managing digital technology projects by identifying scheduling deviations |
| **S5** | Partially — demonstrates application of standard PM techniques (CPM) in a digital solution |
| **B5** | Partially — presenting data concisely and truthfully through terminal output and visual diagram |

**KSBs that SHOULD be explicitly signalled:**
- **K15** — explicitly name the KSB: "This demonstrates K15 — understanding principles of estimating time constraints"
- **S15** — if the demo shows error handling (cycle detection, invalid input), mention: "Our validation applies professional standards to prevent incorrect scheduling outputs that could mislead a project manager"
