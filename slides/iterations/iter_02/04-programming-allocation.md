# Slide 4: Programming Allocation

**Speaker:** Cole | **Time:** 2 minutes

---

## On the Slide

| Person | Area | Why | Outcome |
|--------|------|-----|---------|
| Cole | RayLib UI / Rendering | Built projects in RayLib before | Built UI quickly, provided visual feedback that increased test surface for Jamie's CPM implementation |
| Jamie | CPM Implementation | Additional research into CPM | Identified input UI was out of scope for MVP; persuaded team to keep MVP minimal |
| Samuel | Parsing + Tests | Experience writing unit tests | Tests caught an edge case around duration values, fixed as a team |
| Hamza | Orchestration | Strong overall technical understanding assists QA | Spotted type mismatches between Jamie's CPM and Cole's rendering, unified the codebase |

**Work Breakdown Structure (responsibility-based):**

```
CPM Application (Level 0)
├── Parser (Samuel)        — JSON reading, struct population
├── Algorithm (Jamie)      — Forward/backward pass, float
├── Tests (Samuel)         — Unit tests, edge cases
└── Visualisation (Cole)   — RayLib AON diagram
    └── Integration (Hamza) — Type alignment, orchestration
```

---

## Speaker Notes

- "We needed to decide who would work on what. We split based on existing strengths and experience — effectively creating a responsibility-based Work Breakdown Structure. Each person owned a discrete package with defined inputs and outputs, which let us develop in parallel."
- **Cole:** "I'd built RayLib projects before, so I could deliver the UI quickly. My visual output also gave Jamie immediate feedback on whether the CPM calculation was correct — the rendering became an extra test surface."
- **Jamie:** "I had the deepest understanding of CPM from my research. During development, I identified that adding input UI was out of scope for the MVP and pushed back against team consensus to keep us focused. That's scope management — with time fixed, scope had to stay minimal." (Iron Triangle)
- **Samuel:** "I had experience writing unit tests. My tests caught an edge case with duration values that would have broken the calculation. We fixed it together as a team." (Proactive quality management — tests weren't an afterthought, they were built into the process.)
- **Hamza:** "I had the strongest overview of the full system, which suited QA. I spotted that Jamie's CPM implementation was using different types to Cole's rendering engine. I flagged this before it caused integration bugs." (Proactive integration risk management — caught before it became a problem.)

---

## PM Connections

- The module split = **Work Breakdown Structure** (responsibility-based, Week 4) — each person owned a discrete work package with defined inputs/outputs, enabling parallel development
- Jamie's scope pushback = **Iron Triangle** (time fixed → scope must flex)
- Samuel's test catching edge case = **proactive quality management**
- Hamza's type mismatch catch = **proactive integration risk management** (rubric requires "challenges handled proactively" for 80%+)
- Estimation approach: **Expert judgement + bottom-up** — each person estimated their own WBS package based on experience; combined for total project estimate

---

## Evidence Artefacts

> **[INSERT]** Commit log screenshot showing parallel development across branches (Cole's UI commits, Jamie's algorithm commits, Samuel's test commits overlapping on same afternoon)
> **[INSERT]** Group chat screenshot where Hamza flagged the type mismatch: "Jamie your CPMResult uses int for float values but Cole's renderer expects double — can we align before merge?"

---

## KSBs Signalled

- **K8** — how teams work effectively (parallel development, mutual support)
- **B2** — independent and team working (each person owned their area, but helped each other)
- **K15** — Jamie's scope decision connects to estimation/constraint management
