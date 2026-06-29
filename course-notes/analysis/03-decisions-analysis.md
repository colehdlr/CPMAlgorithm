# Analysis: Slide 03 — Development Process and Key Decisions

## 1. Course Concepts Already Referenced

- **WBS principle**: JSON structure described as mirroring "WBS decomposition — each activity is a work package with dependencies" — directly references Week 4 content.
- **Modular decomposition / parallel development**: Separating parse.c from cpm.c to "enable parallel development" and "reduce integration risk" — connects to systems engineering and risk management.
- **Verification and validation**: Dual implementation (C + Python) described as cross-validation — references quality management principles.
- **Interface contracts**: Shared header files defined on Day 1 as contracts — connects to scope baseline management.
- **Trade-off analysis**: C over Python articulated as benefit (deeper understanding) vs cost (slower velocity) with mitigation — this is decision-making under constraints.

## 2. Course Concepts MISSING — With Specific Suggestions

### A. Iron Triangle — Explicit Naming (Week 4, Page 5)

**Where to add:** When discussing the C vs Python trade-off.

**Suggested script enhancement:** Replace the mitigation sentence with:
> "This is an Iron Triangle trade-off: we accepted higher cost (development time) to protect scope (algorithmic correctness). We mitigated the time impact through interface contracts that enabled parallel development."

### B. Project Life Cycle — Iterative vs Linear Choice (Week 1, Pages 16-18)

**Where to add:** As a framing decision before the technical decisions.

**Suggested addition (new row in the table on the slide):**

| Decision | PM Justification |
|---|---|
| Iterative (Kanban) over Linear (Waterfall) | Short timeline with uncertain task durations; adaptive planning over predictive planning (Agile Manifesto principle 2) |

**Script addition:**
> "Before any technical decisions, we chose an iterative approach. Week 1 taught us that iterative life cycles suit 'dynamic requirements and fast-changing needs.' Our two-day sprint had uncertain durations — we did not know how long the parser or backward pass would take — making predictive planning inappropriate."

### C. Estimation Approaches — Bottom-Up and Expert Judgement (Week 4, Page 7)

**Where to add:** When discussing how the team broke down the project.

**Suggested script addition:**
> "Our decision to separate parse.c from cpm.c was also an estimation decision. By decomposing into modules, we could estimate each component's effort independently — this is bottom-up estimation. We combined this with expert judgement: [A] estimated the algorithm at one day based on prior experience with graph algorithms."

### D. Agile Manifesto Principles (Week 3, Page 10)

**Where to add:** When justifying modular separation and parallel work.

**Suggested script addition:**
> "The Agile Manifesto values 'individuals and interactions over processes and tools' and 'working software over comprehensive documentation.' Our interface contract was deliberately minimal — a single struct definition — because we valued a working integration over exhaustive specification documents."

Reference: Beck, K. et al. (2001) Manifesto for Agile Software Development.

### E. Risk Response Strategies — Named (Week 2 context, Q&A slide content)

**Where to add:** When discussing mitigation of integration risk.

**Suggested script enhancement:**
> "Separating modules introduced integration risk. Our response was mitigation — reducing probability through interface contracts — rather than avoidance, which would have meant a monolithic single-file approach that eliminated parallelism."

### F. Scope Baseline and Scope Creep Prevention (Week 4, Page 13)

**Where to add:** When discussing the Activity struct as a contract.

**Suggested script addition:**
> "The struct definition served as our scope baseline for the internal interface. Any change to it required team agreement — this prevented scope creep at the integration boundary, which the WBS literature identifies as essential for avoiding 'budget and schedule overruns' (Institute of Project Management, 2022)."

## 3. Exact Terminology and Academic References to Cite

- "Bottom-up estimation: Breakdown the project into the smallest, most manageable components (packages) and each component is individually estimated" (Week 4, Page 7)
- "Expert judgement: based on past experience or the expertise of other team members" (Week 4, Page 7)
- "Iterative Life Cycle: Repeated cycles to refine outputs... Advantages: adaptability, user feedback, faster value delivery" (Week 1, Page 17)
- "The Agile Manifesto explicitly values 'individuals and interactions over processes and tools'" (Week 3, Page 10)
- "Both [PBS and WBS] are helpful for monitoring and control: helps to avoid scope creep, budget and schedule overruns" (Week 4, Page 13)
- Beck, K. et al. (2001) Manifesto for Agile Software Development.
- Institute of Project Management (2022) — referenced in Week 4 WBS discussion.
- Green, C. (2006) Estimating as an art, PMI Global Congress.

## 4. KSBs Addressed

| KSB | How Addressed |
|-----|---------------|
| **K15** | Strongly — decisions about decomposition directly relate to estimation principles (bottom-up estimation enabled by modular separation) |
| **S5** | Strongly — applying Agile methodology, standard processes (modular design, V&V) in a digital technology solution |
| **S6** | Strongly — managing the project by identifying deviations (trade-off analysis) and applying appropriate methodology |
| **S15** | Partially — verification/validation connects to professional standards for correctness |
| **B1** | Partially — the decision rigour demonstrates strong work ethic and commitment to standards |

**KSBs to explicitly signal:**
- **K15** — name it when discussing estimation: "This decomposition enabled bottom-up estimation, directly applying K15 principles"
- **S5** — name it: "We applied ISO-aligned verification and validation through dual implementation"
