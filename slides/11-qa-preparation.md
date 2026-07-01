# Q&A Preparation Guide

**Time:** 5 minutes after presentation | **All members must answer at least one question**

---

## General Q&A Technique

When asked a question:

1. **Pause** for 2 seconds (rushed answers sound memorised)
2. **Connect to your experience:** "In our project, we encountered this when..."
3. **Name the principle:** "This relates to [PM concept]..."
4. **Give the specific answer**
5. **If you don't know:** "That is outside what we explored, but based on [principle], I would expect [reasoned guess]."

**Natural delivery:** Do NOT recite these answers word-for-word. Internalise the key point and the theory reference, then phrase it naturally. It's fine to pause and think.

**Participation check:** If any member hasn't answered by minute 3 of Q&A, the next responder says "I'd like [Name] to add their perspective on [related aspect]."

---

## Area 1: CPM Mechanics

### Likely Questions

| Question | Theory Anchor | Project Example | Key Line |
|----------|---------------|-----------------|----------|
| Why does B have float of 2? | Float = path difference at merge | B-D=13, C-E=15, gap=2 | "C drives F's start; B can slip 2 days" |
| What if B's duration = 7? | Critical path shifts dynamically | B-D becomes 23 > current 22 | "Critical path isn't fixed — it changes when durations change" |
| How crash to 18 days? | Best cost-per-day ratio on critical | E first at £2,500/day | "Never crash non-critical activities" |
| Total vs free float? | Total=project end; Free=next task | Both 2 for B here; diverge at shared merges | "Free float is what the downstream person cares about" |
| Resource constraints in CPM? | CPM assumes unlimited resources | B and C both start day 3 — one person = sequential | "Resource levelling adjusts schedule to resolve conflicts" |

### Extended CPM Detail

- "CPM assumes unlimited resources. If one developer handled both B and C, B follows C rather than running in parallel — pushing D to finish at day 18 and the project to 24 days. That's a 2-day hit from one resource constraint."
- "Resource levelling adjusts the schedule to resolve resource conflicts while keeping duration minimal. Resource smoothing only moves activities within their float."
- "The PERT formula σ = (P - O) / 6 assumes a consistent beta distribution. In reality, some tasks have highly skewed risk profiles where this breaks down."
- "Activity independence is the bigger practical issue. Samuel's C struggle affected both parser and testing confidence — correlated activities mean our confidence interval is probably too narrow."
- "If our deadline was 20 days, we'd crash Activity E first — it's critical with the best cost-per-day ratio at £2,500/day versus G at £3,000/day. You never crash non-critical activities. Once you crash E enough that B-D becomes critical too, you'd need to crash both paths simultaneously."
- "Fast-tracking — overlapping Algorithm and Integration — was rejected because Integration literally needs Algorithm's compiled output. Fast-tracking only works with soft dependencies."

---

## Area 2: Estimation and Iron Triangle

### Likely Questions

| Question | Theory Anchor | Project Example | Key Line |
|----------|---------------|-----------------|----------|
| Triple constraint? | Iron Triangle — fix two, flex one | Time+cost fixed → scope flexed via MoSCoW | "Scope is your only control lever" |
| CPM vs PERT? | Deterministic vs probabilistic | 22 days vs 23.8 days, range [20.2, 27.4] | "PERT forces pessimistic thinking" |
| Which estimation method best? | Context-dependent (Week 4) | Analogous matched actual; expert was worst | "Analogous → parametric → PERT → expert as fallback" |
| Why didn't you implement PERT in code? | MoSCoW — it was a 'Could have' | Architecture supports it; would've cut testing time | "That's an Iron Triangle call — correctness over features" |
| Why EVA? | Extends estimation into monitoring | SPI 0.75 = behind schedule by 25% | "Turns estimation from one-time to continuous" |

### Extended Estimation Detail

- "Four estimation methods compared on the parser: expert judgement (+200% error), PERT (+114%), analogous (~0% using Python coursework scaled by 2x), parametric (close after pair-programming adjustment). Analogous was most accurate because we had directly comparable historical data."
- "Parametric estimation: experienced C developers averaged 15 lines/hour, less experienced averaged 8. For the 45-line parser, parametric gives 5.6 hours — closer to actual once you factor pair-programming cutting time roughly in half."
- "EVA limitation: requires reliable percentage-complete data, which is subjective for knowledge work. Our Day 1 checkpoint worked because we could objectively count completed WBS packages."
- "We applied PERT during our Day 1 replan — re-estimating remaining work with O/M/P scenarios. That's how we decided visualisation was still achievable rather than cutting it. PERT informed a real-time scope decision, not just retrospective analysis."
- "Our hybrid lifecycle: sequential critical path dependency combined with iterative refinement within modules. Week 1 identifies hybrid as suited to 'complex projects with mixed needs' — our critical path needed predictability, but each module benefited from iterative feedback."
- "Crashing Activity E from 7 to 5 days costs £5,000 in overtime (£2,500/day). Crashing G from 4 to 3 costs £3,000 (£3,000/day). Crash E first — better ratio."

---

## Area 3: Teamwork and Team Theory

### Likely Questions

| Question | Theory Anchor | Project Example | Key Line |
|----------|---------------|-----------------|----------|
| What Tuckman stage reached? | Forming→Storming→Norming→Performing | Norming by Day 1 end; Performing glimpses Day 2 | "True Performing takes longer than two days" |
| Non-contributing member? | Storming — address directly | Understand why, reference allocation, offer support | "Suppressing it prolongs Storming" |
| Strengths-based allocation risks? | McClelland — over-indexes achievement | In 2-day sprint, speed trumps growth | "Longer projects need rotation" |
| Why Kanban over Scrum? | Uncertain durations; 2-day timeline | Ceremonies would eat into working time | "Continuous flow beat fixed-length sprints" |
| Theory Y assumption — when does it fail? | Mixed motivation or unclear priorities | Need push-based assignment | "Validate Theory Y before assuming it" |

### Extended Teamwork Detail

- "Our Kanban board's pull-based model worked because all four self-motivated — Theory Y assumption (McGregor, 1960). In a team with mixed motivation, you'd need push-based assignment. WIP limit of 1 matched single-person WBS packages."
- "Leadership shifted from transactional role allocation (Day 1 AM) to transformational influence during the C debate (Burns, 1978). That shift wasn't planned — it responded to what the team needed."
- "McClelland's three drivers: achievement (each person succeeding at their area), affiliation (shared stand-ups and pair-programming), power (owning your module). The risk is over-indexing achievement — nobody grows."
- "Our Tuckman progression: Formed Day 1 morning with role allocation, Stormed during C debate at 15:47, Normed by evening with shared processes, Performing glimpses Day 2 when people self-directed without checking in. But Norming wasn't a single transition — we Normed on process by Day 1 afternoon and didn't Norm on knowledge until Day 2."
- "Wilemon & Thamhain barrier mapping: managed 5 of 11. Prevented: Role Conflicts (RACI + struct), Communication Problems (stand-ups + Kanban). Encountered: Differing Outlooks (C debate), Dynamic Environments (replan), Lack of Team Definition (role expansion). Remaining 6 not applicable in self-selecting academic peers but would need Day-1 attention in industry."
- "Stand-ups worked because our modular task split meant blockers cascaded within hours. A block on parsing could stall everything downstream by next morning. In independent work, stand-ups would be wasted time."
- "Self-determination theory (Deci and Ryan, 1985): strengths-based allocation satisfied autonomy, familiar territory satisfied competence, shared stand-ups satisfied relatedness. Theory Y is the assumption; SDT is the mechanism."

---

## Area 4: Team Contract and Communication

### Likely Questions

| Question | Theory Anchor | Project Example | Key Line |
|----------|---------------|-----------------|----------|
| Team agreements? | Social contract (Belbin, 2010) | 6 agreements evolving through use | "Verbal for 4; write for 8+" |
| Why verbal contract? | Speed vs rigour | 4 people, same room, prior trust | "Documented retrospectively as transfer template" |
| Role evolution? | Tuckman Norming | Hamza's role grew into integration oversight | "Organic role expansion — roles refined as team discovers needs" |
| Communication over time? | Tuckman stages (Highsmith, 2002) | Forming=directive → Norming=open → Performing=autonomous | "Shifted as trust built" |

### Extended Detail

- "Team contract as social contract (Belbin, 2010): verbal for four people who already knew each other in the same room. For eight people or remote, you'd need written documentation to prevent 'I thought we agreed...' disputes."
- "Samuel proposed the sixth agreement ('test each other's modules before integration') at Day 2 stand-up, based on the Day 1 type-mismatch. Team agreed in under 2 minutes because evidence was fresh. That's a living contract, not static bureaucracy."
- "Our Belbin roles were more useful as a retrospective lens than a planning tool. We allocated by strength, then discovered the mapping. The value was diagnostic — understanding WHY our allocation worked, not deciding what it should be."
- "The 15-minute stand-ups adapted through use: first one ran 25 minutes, we restructured to the 3-question format (what did, what will do, blockers), cut to 12 minutes. Treating processes as living tools, not fixed."

---

## Area 5: Reflection and Learning Theory

### Likely Questions

| Question | Theory Anchor | Project Example | Key Line |
|----------|---------------|-----------------|----------|
| How did you structure reflections? | Kolb's cycle (1984) adapted | Assumption → event → theory → future action | "Kolb works retrospectively; our learning was messier" |
| Kolb vs Schön? | Retrospective vs in-action | Samuel's mid-flow knowledge-gap fix | "Schön doesn't require stopping to reflect formally" |
| Biggest team-level lesson? | Knowledge decomposition | WBS decomposes work, not understanding | "Knowledge map alongside WBS" |
| Adjourning — what transfers? | Tuckman (1965) | Processes transfer; trust doesn't | "Build relational foundations deliberately in new teams" |

### Extended Detail

- "Our reflection structure maps to Kolb's Experiential Learning Cycle — but Kolb assumes learning moves neatly from experience to reflection to theory. Ours was messier. The theory connection often came after the future action was already decided. Kolb is better as retrospective sense-making than a real-time learning model."
- "What actually happened in real time was closer to Schön's (1983) reflection-in-action: notice discomfort, name the assumption, test it immediately — a micro-cycle that doesn't wait for formal reflection."
- "The ADKAR connection goes further for Jamie's reflection: the structured C debate discussion ended up acting as Reinforcement. Committing publicly to 'stick with C but support each other' prevented reopening the debate every time someone hit a snag."
- "Counter-arguments on future actions: Jamie — spiking only makes sense when stakes are high and knowledge is uncertain. Samuel — the transfer still depends on the tester knowing enough to ask good questions. Cole — visual verification only works when the tool has a natural visual form. Hamza — interface ownership adds overhead; unnecessary for 2-person teams with simple interfaces."
- "The professional development transfer evidence: Jamie applied spike discipline at work (pushed for half-day spike rather than consensus vote on database choice). Samuel asks 'what's the pessimistic estimate?' in workplace stand-ups. Cole added automated screenshot comparison tests to his team's CI pipeline. Hamza reviews interface contracts before development begins."

---

## Area 6: Risk and Quality

### Likely Questions

| Question | Theory Anchor | Project Example | Key Line |
|----------|---------------|-----------------|----------|
| What risks identified? | Avoid/mitigate/transfer/accept | Integration→struct; Time→MoSCoW; Accuracy→tests | "Mitigation before the risk materialises" |
| Testing approach? | "Build quality in" | Golden path + edge cases + error cases | "Proactive, not bolted on at the end" |
| Demo failure plan? | Risk mitigation | Backup screenshot, rehearsed 3x | "5-second failover" |

---

## Area 7: Change Management

### Likely Questions

| Question | Theory Anchor | Project Example | Key Line |
|----------|---------------|-----------------|----------|
| Managing plan revision? | Lewin (Unfreeze→Change→Refreeze) | Acknowledged overrun → MoSCoW replan → committed | "Acknowledging the problem was the hardest step" |
| ADKAR in your project? | Hiatt (2006) | C debate: had Awareness+Desire, lacked Knowledge+Ability | "Change fails when you skip Knowledge and Ability" |

---

## Hard-Mode Questions to Practise

1. "If you had 3 more days, what would you add to the application?"
2. "How would your process change with a 6-person team?"
3. "What's the limitation of your JSON input format?"
4. "How would you handle resource constraints in CPM?"
5. "What would you do if two team members wanted the same role?"
6. "How does your experience relate to managing a real construction project?"
7. "Why didn't you implement Monte Carlo simulation?"
8. "What would happen if your critical path shifted during the project?"

---

## Handling Difficult Moments

**If you genuinely don't know:**
"That is outside what we explored in this sprint, but based on [principle], I would expect [reasoned guess]. I would want to verify by [action]."

**If asked about someone else's area:**
Give a brief answer showing cross-team knowledge, then: "[Name] can add detail on this."

**If asked a calculation you need to think through:**
"Let me work through that. [Pause. Think aloud briefly.] The new path would be... which means..."
