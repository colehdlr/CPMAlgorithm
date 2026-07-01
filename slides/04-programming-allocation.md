# Slide 4: Programming Allocation

**Speaker:** Cole | **Time:** 1 minute

---

## On the Slide

**Work Breakdown Structure (responsibility-based):**

```
CPM Application
├── Parser (Samuel) — JSON schema, I/O, struct population, validation
├── Algorithm (Jamie) — Forward pass, backward pass, float, critical path ID
├── Tests (Samuel) — Golden path, edge cases, error cases
├── Visualisation (Cole) — Node layout, edge rendering, CP highlighting
└── Integration (Hamza) — Type alignment, build system, orchestration
```

**Sprint Schedule (2 Days):**

| Task | Day 1 AM | Day 1 PM | Day 2 AM | Day 2 PM | Path |
|------|:---:|:---:|:---:|:---:|------|
| Parser (Samuel) | ■■■■ | ■■■■ | | | **CRITICAL** |
| Algorithm (Jamie) | ■■■■ | ■■■■ | ■■ | | **CRITICAL** |
| Visualisation (Cole) | ■■■■ | ■■■■ | ■■■■ | ■■ | Float: 4.5h |
| Integration (Hamza) | | | ■■■■ | ■■■■ | **CRITICAL** |

**Critical Path:** Parser → Algorithm → Integration = 10 hours sequential

**Resource constraint:** Testing blocked until Algorithm output available — float converted to sequential dependency

---

## Speaker Notes

We split work using a responsibility-based WBS — chosen because our challenge was four people coding in parallel. Critical path: Parser, Algorithm, Integration — 10 hours sequential. Cole's visualisation ran in parallel with 4.5 hours of float.

That float created support capacity. Cole tested Jamie's edge cases because his track was ahead. When Samuel struggled, Jamie pair-programmed on the parser. If everything sat on the critical path, nobody could have helped.

Day 1 PM, Samuel was blocked on testing until Algorithm completed — a resource constraint visible on the schedule. CPM assumes unlimited resources; resource levelling shows the real schedule once you account for people.
