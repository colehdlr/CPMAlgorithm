# Slide 3: Development Process and Key Decisions

**Time:** 2 minutes | **Speaker:** [Speaker C]

---

## On the Slide

A visual table (NOT bullet-point paragraphs):

| Decision | PM Justification |
|---|---|
| C language | Working with explicit data structures forced deep understanding of CPM's graph model |
| JSON input format | Nested structure mirrors WBS decomposition — each activity is a work package with dependencies |
| Separated parse.c from cpm.c | Modular decomposition reduces integration risk, enables parallel development |
| AON network model | Industry-standard CPM notation; JSON objects map directly to nodes |
| Dual implementation (C + Python) | Cross-validation applies verification & validation principle from quality management |

Optional: One small screenshot of the app handling invalid input (10 seconds maximum).

---

## Speaker Script

"Let me walk you through the key decisions we made and why each connects to project management.

First, we chose C over Python. Python would have been faster to develop, but C required us to define explicit data structures — our Activity struct contains fields for ES, EF, LS, LF, slack, and is_critical — which forced us to deeply understand how CPM data flows through the forward and backward passes. The trade-off was slower development velocity. We mitigated this by defining shared header files as interface contracts on Day 1, enabling parallel development.

Second, we used JSON for input because its nested structure naturally represents the activity-dependency relationship that CPM requires. Each activity object contains an ID, name, duration, and a dependencies array. CSV would have required flattening this structure — a comma-separated list inside a comma-separated file — which is fragile and harder to validate.

Third, we separated our parser from our algorithm — parse.c handles JSON, cpm.c handles the forward and backward passes. This is modular decomposition from systems engineering. It reduced our integration risk because each module could be developed and tested independently. It also enabled parallel development — [B] built the parser while I built the algorithm, and we integrated on Day 2 against our shared Activity struct.

Finally, we built two independent implementations — one in C and one in Python — to cross-validate our calculations. When both produced identical ES, EF, LS, LF, and float values, we had high confidence in our algorithm's accuracy. This is analogous to independent estimation in project management, where two separate estimates increase confidence in the result."

---

## Sentence Templates Used

Every decision MUST connect to PM in the same sentence:

- **C over Python:** "We chose C over Python. The benefit was that working with explicit data structures forced us to deeply understand the CPM graph model. The trade-off was slower development velocity. We mitigated this by defining shared header files as interface contracts."
- **JSON over CSV:** "We adopted JSON because its nested structure naturally represents the activity-dependency relationship, reflecting the WBS principle."
- **Modular separation:** "We separated data parsing from the CPM algorithm to enable parallel development, applying modular decomposition to reduce integration risk."
- **Dual implementation:** "We built two independent implementations to cross-validate, applying the verification and validation principle from quality management."

---

## Key Points to Hit

- Each decision gets 30 seconds MAXIMUM
- EVERY decision fused with PM in the same sentence
- JSON vs CSV: ONE sentence only, then move on
- Validation screenshot: show for 10 seconds, say one sentence, move on
- Mention the trade-off for at least one decision (C over Python is ideal)

---

## DO NOT

- Spend more than one sentence on JSON vs CSV
- Lecture about what CPM is (panel knows)
- Show or explain source code
- Narrate validation/error handling for more than 10 seconds

---

## Transition to Next Slide

"That covers the technical decisions. [D] will now walk through the teamwork evidence that shows how we executed on those decisions."
