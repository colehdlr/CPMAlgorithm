# Slide 4: Programming Allocation

**Speaker:** Cole | **Time:** 1 minute

---

## On the Slide

| Person | Area | Why | Outcome |
|--------|------|-----|---------|
| Cole | RayLib UI / Rendering | Built projects in RayLib before | Visual feedback that increased test surface for Jamie's CPM implementation |
| Jamie | CPM Implementation | Additional research into CPM | Identified input UI was out of scope for MVP |
| Samuel | Parsing + Tests | Experience writing unit tests | Tests caught an edge case around duration values |
| Hamza | Orchestration | Strong overall technical understanding | Spotted type mismatches between Jamie's CPM and Cole's rendering |

**Work Breakdown Structure (responsibility-based, Level 2):**

```
CPM Application (Level 0)
├── Parser (Samuel) — JSON schema, I/O, struct population, validation
├── Algorithm (Jamie) — Forward pass, backward pass, float, critical path ID
├── Tests (Samuel) — Golden path, edge cases, error cases
├── Visualisation (Cole) — Node layout, edge rendering, CP highlighting
└── Integration (Hamza) — Type alignment, build system, orchestration
```

*Responsibility-based chosen over deliverable-based or phase-based because our challenge was four people coding in parallel. Satisfies 100% rule — no orphan tasks.*

**Sprint Gantt Chart (2 Days):**

| Task | Day 1 AM (0–2h) | Day 1 PM (2–4h) | Day 2 AM (4–6h) | Day 2 PM (6–8h) | Owner | Path |
|------|:-----------:|:-----------:|:-----------:|:-----------:|-------|------|
| Parser | ■■■■ | ■■■■ | | | Samuel | **CRITICAL** |
| Algorithm | ■■■■ | ■■■■ | ■■ | | Jamie | **CRITICAL** |
| Tests | | ■■ | ■■■■ | ■■ | Samuel | Float: 1h |
| Visualisation | ■■■■ | ■■■■ | ■■■■ | ■■ | Cole | Float: 4.5h |
| Integration | | | ■■■■ | ■■■■ | Hamza | **CRITICAL** |

**Critical Path:** Parser → Algorithm → Integration = 10 hours sequential

**Dependencies:**
```
Parser ──→ Algorithm ──→ Integration
                ↗ Tests (needs Algorithm output)
Visualisation (parallel, float: 4.5h)
```

> **Evidence — Commit Log (Day 1 afternoon):**
> `14:32 Cole: "feat: node rendering with position calc"` | `14:45 Jamie: "feat: forward pass complete"` | `15:10 Samuel: "test: golden path assertions for 3-activity network"`

> **Evidence — Teams Message (Day 1, 16:22):**
> Hamza: *"Jamie your CPMResult uses int for float values but Cole's renderer expects double — can we align before merge?"*

---

## Speaker Notes

We split work using a responsibility-based WBS — chosen because our challenge was four people coding in parallel, satisfying the 100% rule. Critical path: Parser, Algorithm, Integration — 10 hours sequential. Cole's visualisation ran in parallel with 4.5 hours of float.

That float created support capacity. Cole tested Jamie's edge cases because his track was ahead. When Samuel struggled, Jamie pair-programmed on the parser. That support wasn't accidental — the WBS gave some packages slack. If everything sat on the critical path, nobody could have helped.

Day 1 PM, Samuel was blocked on testing until Algorithm completed — a resource constraint that converted his float into a sequential dependency. That's resource levelling: the schedule extends regardless of what CPM says.

The shared struct definition worked because it forced a design conversation upfront — compile-time type checking then caught mismatches automatically rather than surfacing them at integration.
