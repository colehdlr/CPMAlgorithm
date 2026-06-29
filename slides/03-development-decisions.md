# Slide 3: Development Process and Key Decisions

**Time:** 2 minutes | **Speaker:** [Speaker C]

---

## On the Slide

A visual table (NOT bullet-point paragraphs):

| Decision | PM Justification |
|---|---|
| Iterative (Kanban) over Linear (Waterfall) | Uncertain task durations suit adaptive over predictive planning (Agile Manifesto principle 2; Week 1 Iterative Life Cycle) |
| C language | Iron Triangle trade-off: accepted higher cost (time) to protect scope (algorithmic correctness) |
| JSON input format | Nested structure mirrors WBS decomposition — each activity is a work package with dependencies |
| Separated parse.c from cpm.c | Modular decomposition enables bottom-up estimation (K15) and reduces integration risk via mitigation strategy |
| AON network model | Industry-standard CPM notation; JSON objects map directly to nodes |
| Dual implementation (C + Python) | Cross-validation applies ISO-aligned verification & validation (S5); analogous to independent estimation |

Optional: One small screenshot of the app handling invalid input (10 seconds maximum).

---

## Speaker Script

"Let me walk you through the key decisions we made and why each connects to project management.

Before any technical decisions, we chose an iterative approach. Week 1 taught us that iterative life cycles suit 'dynamic requirements and fast-changing needs.' Our two-day sprint had uncertain durations — we did not know how long the parser or backward pass would take — making predictive planning inappropriate. This is why we adopted Kanban-style adaptive planning over a linear Waterfall model.

First, we chose C over Python. Python would have been faster to develop, but C required us to define explicit data structures — our Activity struct contains fields for ES, EF, LS, LF, slack, and is_critical — which forced us to deeply understand how CPM data flows through the forward and backward passes. This is an Iron Triangle trade-off: we accepted higher cost in development time to protect scope — algorithmic correctness and deep understanding of the graph model. We mitigated the time impact through interface contracts that enabled parallel development, directly applying the Agile Manifesto value of 'working software over comprehensive documentation' — our contract was deliberately minimal, a single struct definition, because we valued a working integration over exhaustive specification documents.

Second, we used JSON for input because its nested structure naturally represents the activity-dependency relationship that CPM requires. Each activity object contains an ID, name, duration, and a dependencies array. CSV would have required flattening this structure — a comma-separated list inside a comma-separated file — which is fragile and harder to validate.

Third, we separated our parser from our algorithm — parse.c handles JSON, cpm.c handles the forward and backward passes. This is modular decomposition from systems engineering. It reduced our integration risk because each module could be developed and tested independently — our risk response was mitigation, reducing probability through interface contracts, rather than avoidance, which would have meant a monolithic single-file approach that eliminated parallelism. This decomposition also enabled bottom-up estimation: by breaking the project into its smallest manageable components, we could estimate each module's effort independently. We combined this with expert judgement — [A] estimated the algorithm at one day based on prior experience with graph algorithms. This directly applies K15 estimation principles. The struct definition itself served as our scope baseline for the internal interface; any change required team agreement, preventing scope creep at the integration boundary. It also enabled parallel development — [B] built the parser while I built the algorithm, and we integrated on Day 2 against our shared Activity struct.

Finally, we built two independent implementations — one in C and one in Python — to cross-validate our calculations. When both produced identical ES, EF, LS, LF, and float values, we had high confidence in our algorithm's accuracy. We applied ISO-aligned verification and validation through this dual implementation (S5), which is analogous to independent estimation in project management, where two separate estimates increase confidence in the result."

---

## Sentence Templates Used

Every decision MUST connect to PM in the same sentence:

- **Iterative over Linear:** "We chose an iterative life cycle because uncertain task durations made predictive planning inappropriate — adaptive planning suited our two-day sprint with unknown effort per module."
- **C over Python:** "We chose C over Python. This is an Iron Triangle trade-off: we accepted higher cost (development time) to protect scope (algorithmic correctness). We mitigated the time impact through interface contracts enabling parallel development."
- **JSON over CSV:** "We adopted JSON because its nested structure naturally represents the activity-dependency relationship, reflecting the WBS principle."
- **Modular separation:** "We separated data parsing from the CPM algorithm to enable bottom-up estimation (K15) and parallel development, applying a mitigation risk response strategy to reduce integration risk."
- **Dual implementation:** "We built two independent implementations to cross-validate, applying ISO-aligned verification and validation (S5) from quality management."

---

## Key Points to Hit

- Each decision gets 30 seconds MAXIMUM
- EVERY decision fused with PM in the same sentence
- JSON vs CSV: ONE sentence only, then move on
- Validation screenshot: show for 10 seconds, say one sentence, move on
- Mention the trade-off for at least one decision (C over Python is ideal)
- Name the **Iron Triangle** explicitly when discussing the C vs Python cost/scope trade-off
- Name **bottom-up estimation** and **expert judgement** when discussing modular decomposition (K15)
- Name the **risk response strategy** (mitigation vs avoidance) when discussing integration risk
- Signal **S5** when discussing verification & validation through dual implementation
- Reference the **Agile Manifesto** value when justifying the minimal interface contract
- Mention **scope baseline** when discussing the Activity struct as a contract preventing scope creep

## Course References to Signal

| Concept | Source | Where to Use |
|---|---|---|
| Iron Triangle | Week 4, Page 5 | C vs Python trade-off |
| Iterative Life Cycle | Week 1, Pages 16-18 | Framing decision |
| Bottom-up estimation | Week 4, Page 7 | Modular separation |
| Expert judgement | Week 4, Page 7 (Green, 2006) | Effort estimation |
| Agile Manifesto values | Week 3, Page 10 (Beck et al., 2001) | Minimal interface contract |
| Risk mitigation strategy | Week 2 | Integration risk response |
| Scope baseline / scope creep prevention | Week 4, Page 13 (IPM, 2022) | Activity struct as contract |

## KSBs Addressed

| KSB | How Signalled |
|-----|---------------|
| **K15** | Decomposition enables bottom-up estimation; name explicitly during modular separation |
| **S5** | ISO-aligned V&V through dual implementation; standard processes in a digital technology solution |
| **S6** | Managing the project by identifying deviations (trade-off analysis) and applying appropriate methodology |
| **S15** | Verification/validation connects to professional standards for correctness |
| **B1** | Decision rigour demonstrates strong work ethic and commitment to standards |

---

## DO NOT

- Spend more than one sentence on JSON vs CSV
- Lecture about what CPM is (panel knows)
- Show or explain source code
- Narrate validation/error handling for more than 10 seconds

---

## Transition to Next Slide

"That covers the technical decisions. [D] will now walk through the teamwork evidence that shows how we executed on those decisions."
