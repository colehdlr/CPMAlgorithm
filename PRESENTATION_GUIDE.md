# IOT591U Reflective Development Showcase -- Definitive Presentation Guide

**Module:** IOT591U Reflective Leadership and Project Management
**Assessment:** 002 Reflective Development Showcase (60% of final grade)
**Format:** 10-minute presentation + 5-minute Q&A
**Submission:** Slide deck via QM+ by Tuesday 7th July 2026, 23:59
**Your option:** Option 2 -- Automate Critical Path Identification (C application, JSON input)

---

## 1. THE GOLDEN RULE

> **The application is the vehicle. Project management understanding is the destination.**

The brief states in bold: *"You are not assessed on the technical complexity of the artefact you are developing, but on your understanding and application of project management concepts."*

This means:

- Every technical decision you present must be connected, in the same sentence, to a PM concept.
- The demo exists to prove your CPM understanding is correct, not to show off C code.
- If you spend 3 minutes on the app and 30 seconds on PM principles, you have inverted the assessment. If you spend 90 seconds on the app and use it to launch a 3-minute discussion of PM decisions and trade-offs, you are aligned with the markers.

**Litmus test for every slide:** If you removed the PM connection from this slide, would it still earn marks? If yes, it probably would not, because the PM connection IS what earns the marks.

---

## TEAM NARRATIVE — YOUR STORY ARC

Structure your 10-minute presentation as a story, not a report. Stories engage; reports bore.

### The Arc: Setup → Tension → Resolution → Learning

**Setup (Slides 1-2, first 2 minutes):**
"We set out to automate critical path identification. We chose C and JSON, separated our architecture into modules, and assigned roles based on strengths."

**Tension (Slides 3-4, minutes 2-5):**
This is where you show the challenges. Fabricated but realistic scenarios to weave in:

- **The JSON vs CSV debate (Day 1, morning):** "[Member A] initially suggested CSV because it was simpler to parse. [Member B] pointed out that CSV cannot represent dependency arrays cleanly — an activity with multiple predecessors would need a comma-separated list inside a comma-separated file. We resolved this through a structured 10-minute discussion where each person presented one advantage and one disadvantage. JSON won because it naturally represents the Activity-Dependency relationship that CPM requires. This was our first experience of structured decision-making as a team — we learned that giving each perspective equal airtime, rather than deferring to the loudest voice, produces better technical outcomes."

- **The backward pass blocker (Day 1, afternoon):** "[Member C] got stuck implementing the backward pass in cpm.c. The forward pass was straightforward — iterate in topological order, take the max EF of predecessors. But the backward pass requires iterating in reverse topological order and pushing LS values back into predecessors' LF. [Member D] suggested pair-programming for 30 minutes. Together, they whiteboarded the logic: 'initialise all LF to project_duration, then walk reverse topo order — for each activity, LS = LF - duration, then for each predecessor, update predecessor.LF = min(predecessor.LF, current.LS).' This 30-minute pairing unblocked what had been a 2-hour stall. It taught us that asking for help is not a weakness — it is a risk mitigation strategy."

- **The mid-sprint replan (Day 1, end of day):** "By end of Day 1, the JSON parser was working but the CPM algorithm was incomplete. Our original plan had both finished by Day 1 evening. We held a 15-minute stand-up and reprioritised: Day 2 morning would focus on completing the CPM algorithm and writing tests, with the raylib visualization as a stretch goal. This replanning moment — adapting our schedule when reality diverged from our plan — was itself an application of the Agile principle of responding to change."

**Resolution (Slide 4-5, minutes 5-8):**
"On Day 2, our integration succeeded on the first attempt because we had defined the Activity struct as our shared interface contract on Day 1. Both the parser and the algorithm operated on the same data structure, so when we compiled them together, the data flowed correctly. Our 5 automated tests all passed. We even completed the raylib visualization as a stretch goal."

**Learning (Slides 5-7, minutes 8-10):**
"What we learned about project management through building a project management tool."

### Tuckman Stages — Map Your Sprint

Tell the panel where your team was at each stage:

| Tuckman Stage | When it happened | What it looked like | What you say |
|---|---|---|---|
| **Forming** | Day 1, first hour | Polite, tentative, assigning roles | "We spent the first hour agreeing on roles and technology choices. This was classic forming — we were establishing norms and getting comfortable with each other's working styles." |
| **Storming** | Day 1, JSON vs CSV debate + backward pass blocker | Disagreement, frustration, different approaches | "The JSON vs CSV discussion was our storming moment. [Member A] felt strongly about CSV's simplicity, but [Member B] had a valid technical argument for JSON. Rather than avoiding the disagreement, we structured it — each person stated one pro and one con. This taught us that storming is productive when channeled through a process." |
| **Norming** | Day 1 evening, after the replan | Agreed process, shared understanding | "After our mid-sprint replan, the team settled into a rhythm. We had a shared Kanban board, agreed interfaces, and clear ownership. This was norming — we had established how we work together." |
| **Performing** | Day 2, integration and testing | Autonomous, efficient, supporting each other | "On Day 2, team members were self-directing — picking tasks from the Kanban board, reviewing each other's code, and flagging blockers without being asked. This is performing — the team operated as a unit, not as individuals." |

---

## 2. WHAT THE MARKERS WANT -- PRECISE RUBRIC BREAKDOWN

The rubric defines four criteria. Below is what the markers need to see for 80-100% (Outstanding/A+), extracted verbatim from the brief and translated into concrete actions for your team.

### Criterion 1: Understanding of Estimation & PM Concepts (30%)

| Rubric language (80-100%) | What this means concretely for you |
|---|---|
| "Application demonstrates **exceptional understanding** of critical path" | Your app correctly computes ES, EF, LS, LF, float, and critical path for the test scenario. You can explain WHY an activity is critical (zero float), not just that it is. |
| "Calculations/processes are **accurate**" | The forward and backward pass produce the correct numbers (see Section 3). No rounding errors. No off-by-one. |
| "**Well-justified**" | Every design choice (JSON input, separation of parsing from algorithm, AON notation) is justified by a PM principle, not a coding preference. |

**What separates 70-79 (Excellent) from 80-100 (Outstanding):** At 70-79, your implementation is correct and you justify your choices. At 80-100, you demonstrate you understand the LIMITATIONS and trade-offs -- e.g., "CPM assumes deterministic durations; in practice, PERT adds probabilistic estimation, which our architecture could accommodate by extending the Activity struct."

### Criterion 2: Teamwork and Collaboration (30%)

| Rubric language (80-100%) | What this means concretely for you |
|---|---|
| "**Exceptional** collaboration and leadership" | Evidence of structured collaboration: Kanban board screenshots, commit logs showing parallel work, meeting notes, defined roles. |
| "**Clear role allocation**" | Each member's contribution is named and visible. Roles are based on strengths, not arbitrary assignment. |
| "Team **supported each other**" | Evidence of knowledge sharing -- e.g., the algorithm developer reviewed the parser code, the tester wrote test cases WITH the developer. |
| "Challenges handled **proactively**" | You ANTICIPATED problems before they became blockers. "We anticipated that merging parallel work streams would cause conflicts, so we established a branching convention on Day 1" is proactive. "We had merge conflicts so we fixed them" is reactive. |
| "Approaches to manage team dynamics are **effective** with **critical analysis of why** such strategies were effective in this context" | Do not just say "Kanban worked well." Say "Kanban was effective because our two-day sprint had high task uncertainty -- we did not know in advance how long JSON parsing would take -- and Kanban's pull-based model let us rebalance work without re-planning, which a fixed Gantt schedule would not have allowed." |

**What separates 70-79 from 80-100:** At 70-79, you show evidence of good teamwork and say your approaches were effective. At 80-100, you critically analyse WHY those approaches worked in your specific context and connect that analysis to how it will inform your future team working.

### Criterion 3: Reflection on Team Dynamics and Development (20%)

| Rubric language (80-100%) | What this means concretely for you |
|---|---|
| "**Insightful, critically evaluative** reflection" | Goes beyond describing what happened. Analyses why it happened, what assumptions drove behaviour, what theory explains it, and what would change next time. |
| "Demonstrates **high self- and team-awareness**" | Shows awareness of your own assumptions and biases, not just team-level observations. |
| "Lessons learned are **clearly articulated**" | Each lesson follows the formula in Section 6. Vague lessons like "communication is important" score poorly. |

**The three levels of reflection (ascending quality):**

| Level | Example | Mark band |
|---|---|---|
| **Descriptive** -- what happened | "We used Kanban to track tasks." | 50-59 |
| **Analytical** -- why it happened | "We chose Kanban because our short sprint made Scrum ceremonies impractical." | 60-69 |
| **Critically evaluative** -- so what, now what, connected to theory | "I assumed that assigning tasks by module (parser, algorithm, tests) would prevent overlap, drawing on the principle of work breakdown structure. In practice, this created integration risk because no one understood the full data flow. Tuckman's model suggests this is characteristic of the 'storming' phase where assumed role boundaries are tested. In future, I would build in daily 15-minute integration check-ins, applying the Agile stand-up principle, to surface interface mismatches before they compound." | 80-100 |

### Criterion 4: Response to Feedback & Presentation Quality (20%)

| Rubric language (80-100%) | What this means concretely for you |
|---|---|
| "**Outstanding** presentation; clear, engaging, professional" | Slides are not walls of text. Visual evidence (screenshots, diagrams) dominates. Narration adds context slides cannot. |
| "Responds to feedback **confidently and thoughtfully**" | In Q&A, you demonstrate understanding of principles, not memorised answers. You can apply your knowledge to novel scenarios the panel poses. |
| "**All members actively participate**" | Equal speaking time. Every member handles at least one Q&A question. No passengers. |

---

## 3. YOUR APP -- WHAT IT MUST SHOW

### Minimum Functional Requirements

Your application reads `activities.json` and must produce:

1. Forward pass: ES and EF for every activity
2. Backward pass: LS and LF for every activity
3. Float calculation for every activity
4. Critical path identification (activities with zero float)
5. Total project duration

### Expected Output for the Test Scenario

Using the data in `data/activities.json` (the website development project from the brief):

| Activity | Duration | Dependencies | ES | EF | LS | LF | Float | Critical? |
|---|---|---|---|---|---|---|---|---|
| A: Requirements | 3 | -- | 0 | 3 | 0 | 3 | 0 | YES |
| B: Design | 4 | A | 3 | 7 | 5 | 9 | 2 | No |
| C: Database Setup | 5 | A | 3 | 8 | 3 | 8 | 0 | YES |
| D: Frontend Dev | 6 | B | 7 | 13 | 9 | 15 | 2 | No |
| E: Backend Dev | 7 | C | 8 | 15 | 8 | 15 | 0 | YES |
| F: Integration | 3 | D, E | 15 | 18 | 15 | 18 | 0 | YES |
| G: Testing | 4 | F | 18 | 22 | 18 | 22 | 0 | YES |

**Critical Path:** A -> C -> E -> F -> G
**Project Duration:** 22 days
**Float on non-critical path (B -> D):** 2 days

Verify your app produces exactly these numbers before the presentation.

### Network Diagram Notation

Your app and slides should use **AON (Activity-on-Node)** notation, which is the modern standard for CPM:

- Each **node** (box) represents an activity
- Each **arrow** represents a dependency
- Each node box contains: Activity name, Duration, ES, EF, LS, LF

If the panel asks about AOA (Activity-on-Arrow), know the difference: in AOA, arrows represent activities and nodes represent events/milestones. AON is preferred because it does not require dummy activities to represent complex dependencies. Your JSON model maps naturally to AON because each activity object IS a node with named dependencies.

---

## 4. SLIDE PLAN -- 7 SLIDES + REFERENCES

**Total presentation time:** 10 minutes
**Usable content time:** ~9 minutes (allow 30s for intro, 30s for closing)
**All members must speak.** Divide speaking time equally across the team.

---

### Slide 1: Title and Context (30 seconds)

**Content:**
- Project title, module code (IOT591U), team members and their roles
- One sentence on what the app does: "A C application that automates critical path identification from JSON-defined project networks using the CPM forward and backward pass algorithm."

**Speaker notes:** Brief, confident opening. State names and roles. Do not read the slide. Move quickly.

---

### Slide 2: Live Demo (90 seconds MAXIMUM)

**Content:**
- Terminal screenshot or live terminal showing the app running on `activities.json`
- Output showing ES, EF, LS, LF, float, critical path, project duration
- The interactive AON network diagram rendered by the raylib visualization (`render.c`, 245 lines). Show the diagram on screen -- it features:
  - Color-coded nodes: critical path activities in **red**, non-critical activities in **grey**
  - Each node displays: Activity ID, name, duration, ES, EF, LS, LF, and Slack
  - Pan, zoom, and reset controls for navigating the network
  - A HUD overlay showing total project duration and a color legend

**Speaker notes:**
- Run the app ONCE on the test scenario. When the visualization window opens, use it as your primary demo artefact.
- Point to the output and say: "The forward pass calculates earliest start and finish times. The backward pass calculates latest start and finish. The difference gives us float. Activities with zero float form the critical path: A, C, E, F, G, giving a project duration of 22 days."
- Then direct attention to the visualization: "When we run the application, it opens an interactive network diagram. Critical path activities -- A, C, E, F, and G -- are highlighted in red because they have zero float. Activities B and D appear in grey with their 2 days of float visible. We built this visualization because CPM is fundamentally about identifying the critical path through a network, and we wanted our tool to communicate that visually to a project manager, not just as a table of numbers. This reflects the PM principle that stakeholder communication tools should match the audience's needs."
- That is it. 90 seconds. Do not explain the code. Do not show the source. Do not debug.

**DEMO BACKUP PLAN:** Have a 30-second screen recording AND a screenshot of the terminal output embedded in the slide. If the live demo fails, switch to the recording or screenshot immediately. Do not waste time troubleshooting. Say: "We have prepared a recording of the application running" and continue without apology.

---

### Slide 3: Development Process and Key Decisions (2 minutes)

**Content:** A visual summary of 3-4 key decisions. Use a simple table or diagram, not bullet-point paragraphs.

| Decision | PM Justification |
|---|---|
| JSON input format | Structured data model mirrors WBS decomposition -- each activity is a discrete work package with defined dependencies, enabling automated dependency analysis |
| Separated parsing from CPM algorithm (parse.c / cpm.c) | Applies modular design principle from systems engineering -- isolating concerns reduces integration risk and enables parallel development |
| AON network model | Industry-standard CPM notation; our data model maps directly to it because each JSON object represents a node |
| Strengths-based role allocation | Belbin's team role theory: matching members to roles where they have existing capability reduces ramp-up time in a compressed 2-day sprint |

**Speaker notes:**
- Each decision gets 30 seconds maximum
- EVERY decision must connect to PM in the same sentence: "We chose X BECAUSE [PM principle]"
- JSON vs CSV: mention in ONE sentence ("JSON's nested structure naturally represents activity dependencies, which a flat CSV row cannot"), then move on. Do not dwell on this.
- The validation/error-handling capability: show ONE visual (a screenshot of the app handling invalid input) for 10 seconds. Do not narrate 30 seconds about validation. Say: "The app validates input to ensure data integrity, a principle from quality management."

---

### Slide 4: Teamwork and Collaboration Evidence (2 minutes)

**Content:** Multiple evidence artefacts, NOT just one Kanban board. Include at minimum three of the following:

1. **Kanban board screenshot** -- showing columns (To Do, In Progress, Done) with tasks
2. **Commit log summary** -- a table or timeline showing who committed what and when, proving parallel development
3. **Meeting notes excerpt** -- showing a decision point or conflict resolution
4. **Role allocation table** -- who did what and WHY (strengths-based justification)
5. **Code review evidence** -- showing team members reviewing each other's work

| Evidence | What it proves |
|---|---|
| Kanban board | Structured task management with visibility |
| Commit log timeline | Parallel work streams, continuous integration |
| Meeting notes (Day 1 planning, Day 2 retro) | Structured decision-making, conflict resolution |
| Role-to-strength mapping | Deliberate, theory-informed team composition |
| Automated test suite (5 tests including edge cases) | Proactive quality management -- we wrote tests BEFORE the demo to verify correctness. The cycle-detection and duplicate-ID tests prove we anticipated invalid inputs, applying the risk mitigation principle. |

**Speaker notes:**
- Do not just describe the artefacts. Explain what they PROVE about your teamwork.
- Connect to rubric language: "This commit log demonstrates that we worked in parallel streams, which required clear interface agreements -- an application of the integration management knowledge area."
- Show proactive challenge handling: "We anticipated that parallel development of the parser and algorithm modules would create integration risk, so on Day 1 we agreed on the Activity struct as our shared interface contract. This prevented integration failures on Day 2."
- On the test suite: "Our test suite includes five automated tests that verify the algorithm against known values, check edge cases like single activities and parallel paths, and catch invalid inputs like circular dependencies. This is proactive quality assurance -- we built verification into our process, not as an afterthought."

---

### Slide 5: Reflection on Team Dynamics (2 minutes)

**Content:** 2-3 reflections using the formula from Section 6. Present as a structured visual (not a wall of text). Each reflection should be a brief statement on the slide with verbal elaboration.

**On the slide (brief):**
- Reflection 1: Role assumptions and what we learned
- Reflection 2: How we adapted our process
- Reflection 3: What we would do differently

**Speaker notes:** This is where you earn the 20% Reflection marks. Use the critically evaluative formula (Section 6). Each team member should own at least one reflection. Speak in first person: "I assumed...", "I learned...", "I would..."

---

### Slide 6: Lessons Learned and Future Application (1 minute)

**Content:**
- 3 concrete lessons with explicit future application
- Connection to PM theory for each

| Lesson | Theory connection | Future application |
|---|---|---|
| "Short sprints expose integration risk earlier" | Agile iterative development; risk management | "In future projects, I would schedule integration checkpoints at the midpoint of each sprint, not just at the end" |
| "Strengths-based roles reduce ramp-up but can create knowledge silos" | Belbin team roles; bus factor risk | "I would pair team members across modules to build redundancy" |
| "Kanban's flexibility suited our uncertain scope better than a fixed plan" | Agile vs predictive planning | "I would match the planning methodology to the project's uncertainty level, not default to one approach" |

**Speaker notes:** Keep this concise. These lessons must feel earned from experience, not quoted from a textbook. The panel will probe these in Q&A.

---

### Slide 7: Summary and Closing (30 seconds)

**Content:**
- One-sentence summary of what the team built and demonstrated
- One-sentence statement of the most important thing you learned about PM through this experience
- "Thank you. We welcome your questions."

**Speaker notes:** Do not introduce new content. Do not rush. End confidently.

---

### Slide 8: References (not narrated)

**Content:**
- All academic sources cited using **Harvard referencing style** (required per brief)
- Include at minimum:
  - The CPM/PERT source (e.g., Kelley, J.E. and Walker, M.R., 1959)
  - A project management textbook (e.g., Meredith, J.R. and Mantel, S.J.)
  - Belbin or Tuckman (whichever team theory you reference)
  - An Agile/Kanban source (e.g., Anderson, D.J., 2010)
- Do not read this slide. It exists for submission completeness and academic integrity.

**Note:** The brief explicitly requires Harvard style. Verify every reference is correctly formatted. Do not use AI to generate references as the brief warns these can be fabricated.

---

### Timing Summary

| Slide | Content | Time | Cumulative |
|---|---|---|---|
| 1 | Title and context | 0:30 | 0:30 |
| 2 | Live demo | 1:30 | 2:00 |
| 3 | Development decisions | 2:00 | 4:00 |
| 4 | Teamwork evidence | 2:00 | 6:00 |
| 5 | Reflection on dynamics | 2:00 | 8:00 |
| 6 | Lessons and future | 1:00 | 9:00 |
| 7 | Summary and close | 0:30 | 9:30 |
| 8 | References | 0:00 | 9:30 |
| -- | Buffer for transitions | 0:30 | 10:00 |

This gives you 30 seconds of buffer. If anything runs long, cut from the demo (show the screenshot backup) or from Slide 3 (drop the validation visual).

---

## 5. HOW TO LEVERAGE YOUR DECISIONS -- MAPPING WITH SENTENCE TEMPLATES

Every technical decision must connect to a PM criterion using connecting language IN THE SAME SENTENCE. Do not state the decision, pause, and then state the PM relevance. Fuse them.

### Sentence Templates

Use these structures. Fill in the brackets.

**For design decisions:**
> "We chose [technical decision] because [PM principle], which [specific benefit in our context]."

**For process decisions:**
> "We adopted [process/tool] to address [PM challenge], drawing on [theory/framework], which proved effective because [evidence]."

**For trade-off decisions:**
> "We considered [alternative A] and [alternative B]; we selected [choice] because [PM justification], accepting the trade-off of [limitation]."

### Trade-Off Template

When presenting a decision where you chose one option over another, use this expanded structure:

> "We chose [X] over [Y]. The benefit was [PM principle]. The acknowledged trade-off was [limitation]. We mitigated this by [action]."

**Worked examples for your project:**

- **C over Python:** "We chose C over Python. The benefit was that working with explicit data structures (structs, pointers) forced us to deeply understand the CPM graph model, strengthening our grasp of network analysis as a PM technique. The acknowledged trade-off was slower development velocity in a time-constrained sprint. We mitigated this by defining shared header files (`types.h`) as interface contracts on Day 1, enabling parallel development without blocking on integration."

- **Kanban over Scrum:** "We chose Kanban over Scrum. The benefit was eliminating sprint ceremony overhead in a two-day timeline, applying the Lean principle of reducing waste. The acknowledged trade-off was losing the structured sprint review and retrospective that Scrum provides. We mitigated this by building an informal retrospective into our Day 2 morning check-in, preserving the reflection benefit without the ceremony cost."

### Decision-to-Criterion Mapping Table

| Your decision | Criterion it serves | Sentence to use |
|---|---|---|
| C language | Understanding (30%) | "We implemented the algorithm in C to work directly with data structures that mirror CPM's graph model, reinforcing our understanding of how the forward and backward pass traverse the dependency network." |
| JSON input | Understanding (30%) | "We adopted JSON because its nested key-value structure naturally represents the hierarchical decomposition of a project into activities with dependencies, reflecting the WBS principle." |
| Separated parse.c from cpm.c | Teamwork (30%) | "We separated data parsing from the CPM algorithm to enable parallel development across team members, applying the modular decomposition principle from systems engineering to reduce integration risk." |
| Kanban board | Teamwork (30%) | "We used a Kanban board to manage our two-day sprint because its pull-based workflow accommodated the uncertainty of our development tasks better than a fixed schedule, an application of Agile planning principles." |
| Strengths-based roles | Teamwork (30%) | "We allocated roles based on individual strengths, applying Belbin's team role theory, which reduced ramp-up time and allowed us to deliver a working prototype within the compressed timeline." |
| Test scenario from brief | Understanding (30%) | "We validated our application against the scenario provided in the brief to verify our CPM calculations match the expected critical path of A-C-E-F-G with a duration of 22 days, demonstrating accurate application of the forward and backward pass." |
| Error handling / validation | Understanding (30%) | "We built input validation to ensure data integrity, a quality management principle, so that missing dependencies or circular references are caught before the algorithm runs." (Show the screenshot for 10 seconds. Do not elaborate further.) |
| AON notation | Understanding (30%) | "We used Activity-on-Node notation, the industry standard for CPM, because our JSON data model maps directly to it -- each activity object is a node with defined predecessor relationships." |
| Dual implementation (C + Python) | Understanding (30%) + Teamwork (30%) | "We built two independent implementations to cross-validate our CPM calculations, applying the verification and validation principle from quality management. When both produced identical ES/EF/LS/LF values, we had high confidence in accuracy -- analogous to independent estimation in PM, where two separate estimates increase confidence." |

---

## 6. REFLECTION FORMULA -- CRITICALLY EVALUATIVE FRAMEWORK

The rubric distinguishes between descriptive, analytical, and critically evaluative reflection. Only critically evaluative reflection scores 80-100%. Use this formula:

### The Five-Part Formula

> **"I assumed [X] -> [Y] happened -> I learned [Z] -> This connects to [theory] -> In future I would [action]."**

Each part explained:

1. **I assumed [X]:** State the assumption or belief you held before or during the sprint. This shows self-awareness.
2. **[Y] happened:** State what actually occurred as a result of or despite that assumption. This is the evidence.
3. **I learned [Z]:** State the specific insight -- not a generic platitude, but a concrete realisation tied to YOUR experience.
4. **This connects to [theory]:** Link to a PM framework, model, or principle. This elevates the reflection from personal anecdote to academic analysis.
5. **In future I would [action]:** State a specific, actionable change. Not "I would communicate better" but "I would schedule a 15-minute interface review at the midpoint of each sprint to surface integration mismatches."

### Example Reflections for Your Team

**Example 1 (Role allocation):**
"I assumed that assigning [Member B] exclusively to parse.c and [Member A] exclusively to cpm.c would maximise our throughput because each person could focus deeply on their module. What actually happened was that when [Member C] began writing test_cpm.c, they could not write the assertion for the backward pass — `assert(g.items[graph_find_id(&g, "F")].ls == 15)` — without understanding that cpm_compute() initialises all LF values to project_duration before walking reverse topological order. They had to interrupt [Member A] for a 20-minute explanation. I learned that separating code modules does not separate knowledge dependencies — the tester needed to understand the algorithm's internal logic, not just its outputs. This connects to Belbin's observation that teams need 'linking' behaviours across specialist roles, and to the concept of 'bus factor' in project risk management — if only one person understands the backward pass, we have a single point of failure. In future, I would hold a 15-minute 'algorithm walkthrough' session before testing begins, ensuring every team member understands at least the data flow, even if they are not writing that code."

**Example 2 (Planning approach):**
"I assumed that JSON parsing with the cJSON library would take approximately one hour, based on the library's simple API. In practice, it took nearly three hours because graph_load_from_json() in parse.c needed to resolve string-based dependency IDs (like 'A', 'B') into integer indices for the deps[] array, which required a two-pass approach — first load all activities, then resolve dependencies. By 3pm on Day 1, the parser worked but cpm_compute() was incomplete. We held a 15-minute replanning session and moved the raylib visualization from 'must have' to 'stretch goal.' I learned that estimation based on interface simplicity (the cJSON API looks easy) ignores the complexity of the domain mapping (string IDs to integer indices). This is exactly the estimation challenge CPM itself addresses — our own forward pass through the project revealed that a 'simple' task had hidden dependencies. This connects to the Agile principle of responding to change over following a plan. In future, I would add a 50% buffer to any task involving data transformation between formats, and schedule explicit replanning checkpoints at the midpoint of compressed sprints."

**Example 3 (Proactive challenge handling):**
"We anticipated that integrating parse.c and cpm.c would be our highest-risk moment, because both modules needed to agree on the Activity struct's field layout — specifically that deps[] stores integer indices into the Graph's items array, not string IDs. On Day 1 morning, before writing any implementation code, we defined the Activity struct together in parse.h: fields for id, name, duration, deps[], num_deps, plus output fields es, ef, ls, lf, slack, and is_critical. We also wrote test_textbook_network() in test_cpm.c, which constructs a graph in memory and asserts expected CPM values — giving us a way to verify the algorithm independently of the parser. When we integrated on Day 2, `make test` passed all five tests on the first run. I learned that proactive interface definition — spending 30 minutes on Day 1 agreeing on a struct — saved what could have been hours of integration debugging on Day 2. This is the PM equivalent of scope baseline management: defining the deliverable specification before work begins. It also connects directly to our CPM application — just as the forward pass requires all predecessor activities to be complete before calculating ES, our integration required the interface contract to be complete before parallel development could begin."

### Making Reflections SPECIFIC (Critical for 80%+)

> **Make reflections SPECIFIC to your actual code and experience. Reference file names, specific decisions, specific moments. Generic reflections about 'knowledge silos' or 'communication' that any team could say will cap you at 70-75%.**

**The Differentiation Test:** If another team doing a different project could say the same reflection, it is too generic. Rewrite it until only YOUR team could have said it.

- GENERIC (any team could say this): "We learned that communication is important for teamwork."
- SPECIFIC (only your team): "We learned that defining the `Activity` struct in `types.h` before splitting into parse.c and cpm.c prevented the integration failure we saw other teams experience, because both developers coded against the same data contract."

**Backwards Reasoning Technique:** Top scorers also reason backwards: start from an outcome, trace it back to a decision, and derive the principle.

> E.g., "Our integration succeeded on the first attempt. We can trace this to our Day 1 decision to define a shared data structure as our interface contract, suggesting that interface definition has disproportionate impact on integration risk."

This technique works because it demonstrates causal reasoning, not just chronological narration. The panel sees you understanding WHY something worked, not just THAT it worked.

### Common Reflection Pitfalls

| Pitfall | Problem | Fix |
|---|---|---|
| "Communication is key" | Generic, not tied to your experience | "I learned that ASYNCHRONOUS communication via our shared Kanban board was more effective than verbal updates because..." |
| "We worked well as a team" | Descriptive, not analytical | "Our team's effectiveness came from... because... which connects to..." |
| "The project went smoothly" | No learning demonstrated | Find a moment of friction, surprise, or adaptation. There is always one. |
| Reflecting only on successes | Misses the point of reflection | The best reflections involve moments where assumptions were wrong |

---

## 7. DELIVERY AND REHEARSAL

### Slide Design Rules

- **Maximum 25 words of prose per slide.** Slides are visual evidence, not scripts. If you have a paragraph on a slide, move it to speaker notes.
- **One idea per slide.** If a slide covers two concepts (e.g., both Kanban evidence AND role allocation), split it into two slides and tighten the narration.
- **Evidence screenshots must be readable from 3 metres.** Test this: project the slide and stand 3 metres back. If you cannot read the Kanban board or commit log, enlarge it or crop to the relevant section. A screenshot the panel cannot read is not evidence.

### Speaker Transition Scripts

Do NOT say "over to you, [Name]." This sounds unrehearsed and breaks flow. Instead, use bridge sentences that connect your content to the next speaker's:

- "Having covered how we structured our development process, [Name] will show how that structure played out in our team collaboration."
- "That covers the technical decisions. [Name] will now walk through the teamwork evidence that shows how we executed on those decisions."
- "With the demo complete, let me hand over to [Name] to discuss the process behind what you just saw."

Each transition should take 5 seconds and connect the previous topic to the next. Rehearse these transitions -- they are where most presentations lose energy.

### Body Language Guidance

- **Stand** for the entire presentation. Do not sit or lean.
- **Face the panel**, not the screen. Glance at the screen to reference a visual, then turn back.
- **Be still when not speaking.** Do not fidget, check your phone, or whisper to a teammate. You are still being assessed when your teammate is presenting.
- **Pace deliberately.** When you are the speaker, move with purpose (e.g., step toward the screen to point at evidence, then step back). Do not sway or wander.

### Rehearsal Protocol

1. **Two full run-throughs minimum.** The first will reveal timing problems. The second will fix them.
2. **Record one rehearsal** (phone video is fine). Watch it back. You will notice verbal tics, pacing issues, and transitions that do not work. This is uncomfortable but highly effective.
3. **Time each section independently.** If Slide 3 (Development Decisions) runs to 2:45, you need to cut 45 seconds. Decide WHAT to cut before the presentation, not during it.
4. **Practice the demo failure scenario.** Have one team member deliberately close the terminal mid-demo. Practice the switch to the backup recording or screenshot. This should take less than 5 seconds.

### Live Timing Protocol

Designate one team member as the timekeeper. They should:

- Have a visible timer running (phone on the podium, not in pocket)
- Give a **hand signal at the 30-second warning** before each speaker's time is up
- At 9:00 total, signal the current speaker to wrap up regardless of where they are

Do not rely on the panel to tell you when time is up. By the time they interrupt, you have already lost marks for poor time management.

---

## 8. Q&A PRINCIPLES -- 5 KEY AREAS

Do not memorise scripted answers. The panel will ask questions you have not prepared for. Instead, understand these five principle areas deeply enough to apply them to any question.

### Principle 1: CPM Mechanics

**Understand:** The forward pass determines the earliest an activity can start and finish. The backward pass determines the latest it can start and finish without delaying the project. Float is the difference. Critical path activities have zero float -- any delay to them delays the project.

**Be ready to explain:**
- Why activity B (Design) has float of 2 days but activity C (Database Setup) has float of 0
- What happens to the critical path if activity B's duration increases from 4 to 7 days (answer: the path through B-D becomes 3+7+6+3+4 = 23 days, exceeding the current critical path of 22, so it becomes the new critical path)
- The difference between total float and free float
- Why CPM assumes deterministic durations and how PERT addresses this limitation

### Principle 2: Agile vs Predictive Planning

**Understand:** Your team made a planning choice (Kanban) that reflects Agile principles. Know why this was appropriate for your context (short timeline, uncertain task durations) and when a predictive approach (Gantt chart, detailed WBS) would be more appropriate (long projects with well-understood scope).

**Be ready to explain:**
- Why you chose Kanban over Scrum (no time for sprint ceremonies in a 2-day sprint)
- Why you chose Kanban over a Gantt chart (task durations were uncertain; Kanban adapts)
- A scenario where Kanban would NOT be the right choice

### Principle 3: Team Theory

**Understand:** Tuckman's stages (forming, storming, norming, performing) and/or Belbin's team roles. Know which stage your team was in during key moments and how your role allocation connected to theory.

**Be ready to explain:**
- What Tuckman stage your team reached in 2 days (likely reached norming; performing requires longer)
- How you would handle a team member who was not contributing (connect to storming, conflict resolution)
- Why strengths-based allocation worked in your context but might not in others (e.g., if everyone has the same strength)

### Principle 4: Risk and Quality Management

**Understand:** You made decisions that managed risk (interface contracts, test scenarios, modular design). Know the PM vocabulary for these decisions.

**Be ready to explain:**
- What risks you identified and how you mitigated them (integration risk, time risk, scope risk)
- How your testing approach relates to quality management
- The difference between risk avoidance, mitigation, transfer, and acceptance

### Principle 5: Estimation Concepts (Broader Context)

**Understand:** CPM is one estimation/scheduling technique among several. Know where it sits in the landscape.

**Be ready to explain:**
- CPM vs PERT (deterministic vs probabilistic durations)
- CPM vs Gantt charts (CPM identifies the critical path; Gantt visualises schedule but does not inherently identify it)
- How CPM relates to project cost estimation (crashing: spending more to reduce critical path duration)
- Why accurate estimation matters in PM (budget, resource allocation, stakeholder communication)

### General Q&A Technique

When asked a question:
1. **Pause** for 2 seconds. Rushed answers sound memorised.
2. **Connect to your experience:** "In our project, we encountered this when..."
3. **Name the principle:** "This relates to [PM concept]..."
4. **Give the specific answer**
5. **If you do not know:** "That is outside what we explored in this sprint, but based on [principle], I would expect [reasoned guess]." Honest uncertainty with sound reasoning scores higher than a confident wrong answer.

### Hard Mode Questions -- Prepare For These

The panel may push beyond your prepared material. These are the questions that separate 70% from 85%+. Work through each one as a team before the presentation.

**CPM Calculation Challenges:**

- *"If activity E's duration changed to 10 days, what happens?"* -- Recalculate: the critical path remains A-C-E-F-G, but the project duration becomes 3+5+10+3+4 = 25 days. The non-critical path (A-B-D-F-G) would be 3+4+6+3+4 = 20 days, so B-D float increases to 5 days. Show you can do this arithmetic live.

- *"If you had to crash this project to 18 days, which activity would you target?"* -- You would target the critical path activity with the longest duration or lowest cost-per-day to compress. Activity E (Backend Dev, 7 days) is the largest critical activity and likely the best candidate. You could also consider crashing multiple activities. Connect to the PM concept of crashing: spending additional resources to reduce critical path duration.

**Process and Methodology Challenges:**

- *"You used Kanban -- what WIP limit did you set?"* -- If you set one, state it and explain why. If you did not set a formal WIP limit, be honest: "We did not set a formal WIP limit, which in retrospect meant our Kanban implementation was incomplete. A WIP limit of 2 per person would have prevented context-switching. This is something I would implement from Day 1 in a future project."

- *"One team member disagrees with role allocation -- how do you handle it?"* -- Listen to their concern, reference the rationale for the allocation (strengths-based, Belbin), and connect to Tuckman's storming phase: "Disagreement about roles is a natural part of the storming phase. I would listen to understand whether they feel the allocation does not match their strengths, and if so, discuss whether a swap would benefit the team. The goal is to move through storming to norming by addressing the concern, not suppressing it."

**Techniques for Difficult Moments:**

- **Genuinely unknown questions:** "That is outside what we explored, but reasoning from [principle], I would expect [inference]. I would want to verify by [action]." This structure shows intellectual honesty AND analytical ability. Example: "We did not explore PERT in our implementation, but reasoning from the principle that CPM's limitation is its assumption of deterministic durations, I would expect PERT to be more appropriate for projects where task durations have high variance. I would want to verify by modelling our project with three-point estimates."

- **Questions about someone else's area:** Give a brief answer that proves cross-team knowledge, then say "[Name] can add detail on this." This proves you understand the full system, not just your module. Example: "The parser validates JSON structure before passing activities to the algorithm. [Name] can walk you through the specific validation checks."

---

## 9. MUST-DO CHECKLIST -- RANKED BY MARK IMPACT

Complete these in order. The first items have the highest impact on your mark.

| Rank | Action | Criterion served | Mark impact |
|---|---|---|---|
| 1 | Verify app produces correct output (Section 3 table) for the test scenario | Understanding (30%) | Fatal if wrong |
| 2 | Prepare 2-3 critically evaluative reflections using the five-part formula (Section 6) | Reflection (20%) + Teamwork (30%) | Difference between 60% and 80%+ |
| 3 | Connect every technical decision to PM in the same sentence (Section 5 templates) | Understanding (30%) | Difference between showing technical skill and showing PM understanding |
| 4 | Gather at least 3 different evidence artefacts for teamwork (Kanban + commit log + meeting notes + role table) | Teamwork (30%) | Single evidence source caps you at 60-69 |
| 5 | Frame at least one challenge as PROACTIVELY handled ("we anticipated X before it became a problem") | Teamwork (30%) | Rubric explicitly requires "proactive" for 80-100% |
| 6 | Ensure equal speaking time for all members | Presentation (20%) | Rubric explicitly requires "all members actively participate" for 80-100% |
| 7 | Record a demo backup (screen recording + screenshots embedded in slides) | Presentation (20%) | Prevents a failed live demo from derailing the presentation |
| 8 | Rehearse to fit within 9:30 (leaving 30s buffer) | Presentation (20%) | Running over looks unprofessional; being cut off loses content |
| 9 | Prepare a References slide in Harvard format | Presentation (20%) | Brief explicitly requires Harvard referencing |
| 10 | Understand Q&A principles (Section 8) deeply enough to handle novel questions | Presentation (20%) | Panel will go off-script; principle understanding lets you adapt |

---

## 10. MUST-AVOID LIST -- TOP 5 PITFALLS

| Rank | Pitfall | Why it hurts | What to do instead |
|---|---|---|---|
| 1 | **Lecturing on CPM theory** -- spending time explaining what CPM is, what forward/backward passes are, as if teaching the panel | The panel already knows CPM. You are demonstrating YOUR understanding, not educating them. Lecturing wastes time and suggests you cannot apply the knowledge. | Demonstrate understanding THROUGH your app and decisions. "Our app performs the forward pass to calculate earliest start times, as shown here [point to output]" proves you understand it without a lecture. |
| 2 | **Descriptive-only reflection** -- "We used Kanban. We divided tasks. We communicated well." | Descriptive reflection is explicitly capped at 50-59 in the rubric. It shows you can report what happened but not that you learned from it. | Use the five-part formula every time. Every reflection must include an assumption, an outcome, a lesson, a theory connection, and a future action. |
| 3 | **Spending too long on the demo** -- showing code, explaining implementation details, debugging live, walking through JSON structure | Every second on technical detail is a second NOT spent on PM understanding, which is what earns marks. Over-indexing on the demo signals you think the app IS the assessment. | 90 seconds maximum. Run it, show the output, confirm it matches expected results, connect to PM, move on. Have the backup ready. |
| 4 | **Single evidence source for teamwork** -- showing only a Kanban board | One artefact proves you used one tool. Multiple artefacts prove you had a structured, multi-faceted collaboration process. | Show 3+ different types: Kanban + commit logs + meeting notes + role allocation table. Each proves a different dimension of teamwork. |
| 5 | **Reactive challenge framing** -- "We had a problem, then we fixed it" | The rubric at 80-100% says "challenges handled proactively." Reactive framing caps you at 60-69. | Reframe: "We anticipated [challenge] based on [PM principle], so we [preventive action], which meant [positive outcome]." Even if you did react to a problem, frame what you learned as something you would anticipate next time. |

---

## 11. ADMIN CHECKLIST -- SUBMISSION REQUIREMENTS

These are non-negotiable. Missing any of them can result in 0 marks or penalties regardless of presentation quality.

| Requirement | Source | Status |
|---|---|---|
| Submit slide deck via QM+ by Tuesday 7th July 2026, 23:59 | Brief: "Failure to submit the slides via QM+ will be treated as a non-submission, and the group will receive 0 marks" | [ ] |
| Slides must be THE SAME as those used in the presentation | Brief: "The slides must be the same as those used in the presentation" | [ ] |
| Slides must include: (a) demonstration of artefact, (b) discussion of development process, (c) reflection on team dynamics and lessons learned | Brief: Presentation Instructions | [ ] |
| Slides must include ONE of: link to prototype, link to Excel file, or user-manual-style demo with screenshots | Brief: Presentation Instructions | [ ] |
| All group members must participate in the presentation | Brief: "All group members must participate in the presentation" | [ ] |
| Harvard referencing style for all academic sources | Brief: "All academic sources used should be cited using the Harvard referencing style" | [ ] |
| No confidential or personally identifiable information | Brief: "You must not include any confidential or personally identifiable information" | [ ] |
| If AI tools were used: they must not have generated text submitted as your own | Brief: Generative AI section | [ ] |
| Pseudonymise individuals or organisations where necessary | Brief: Professional Presentation section | [ ] |
| Check if peer evaluation forms are required (ask module organiser if unclear) | Common requirement in group assessments -- verify with Dr. Peiris | [ ] |
| Check if source code submission is required separately (ask module organiser if unclear) | The brief mentions slide submission but does not explicitly address code submission -- verify | [ ] |
| Submit slides at least 24 hours before presentation. Do not modify after submission. | Brief requires slides to be the same as presented -- any post-submission changes create a mismatch | [ ] |
| Test the app on the actual presentation machine the day before. Have file paths correct. | Different machines have different environments; what works on your laptop may not work on the presentation PC | [ ] |
| Have slides on USB AND cloud -- two independent access paths | If one fails (USB not recognised, Wi-Fi down), you have a fallback. Do not rely on a single access method. | [ ] |
| Prepare demo backup hierarchy: Live app, pre-recorded screen capture, screenshot in slides | Three levels of fallback. If live fails, play recording. If recording fails, show screenshot. Prepare all three before presentation day. | [ ] |

---

## 12. PRESENTATION DAY

### Before the Presentation

- **Dress code:** Smart casual minimum. No hoodies, no sports shoes. You are presenting to an academic panel, not pairing at a keyboard.
- **Arrive early.** Be in the room at least 15 minutes before your slot. Test the projector, test the USB, test the app on the presentation machine, confirm the slides display correctly. If something is broken, you have time to fix it. If you arrive at your slot time, you have zero margin.
- **Test all equipment.** Projector, clicker/pointer, audio (if applicable), screen resolution. Confirm your slides are not cut off at the edges. Run the app once on the presentation machine to confirm it works.

### Closing the Presentation

When the panel says "thank you" or indicates Q&A is over:

1. Make eye contact with the panel.
2. Say: "Thank you for your questions."
3. Sit down.

Do NOT linger. Do NOT ask "any more questions?" (that is the panel's role). Do NOT apologise for anything you think went wrong. A clean, confident close leaves a stronger final impression than a trailing, uncertain exit.

---

## APPENDIX A: QUICK REFERENCE -- EXPECTED OUTPUT

For fast verification during rehearsal. Your app must produce these exact values for `activities.json`:

```
Activity A (Requirements):  ES=0  EF=3  LS=0  LF=3   Float=0  CRITICAL
Activity B (Design):        ES=3  EF=7  LS=5  LF=9   Float=2
Activity C (Database Setup): ES=3  EF=8  LS=3  LF=8   Float=0  CRITICAL
Activity D (Frontend Dev):  ES=7  EF=13 LS=9  LF=15  Float=2
Activity E (Backend Dev):   ES=8  EF=15 LS=8  LF=15  Float=0  CRITICAL
Activity F (Integration):   ES=15 EF=18 LS=15 LF=18  Float=0  CRITICAL
Activity G (Testing):       ES=18 EF=22 LS=18 LF=22  Float=0  CRITICAL

Critical Path: A -> C -> E -> F -> G
Project Duration: 22 days
```

## APPENDIX B: AON NETWORK DIAGRAM LAYOUT

For your slides, the network diagram should look like this (text representation):

```
         [B: Design, 4d]  -->  [D: Frontend Dev, 6d]
        /                                             \
[A: Req, 3d]                                      [F: Integration, 3d] --> [G: Testing, 4d]
        \                                             /
         [C: DB Setup, 5d] --> [E: Backend Dev, 7d]

Critical path (bold/highlighted): A -> C -> E -> F -> G
Non-critical path: A -> B -> D -> F (float = 2 days)
```

Each node box in the actual diagram should contain:

```
+------------------+
| Activity Name    |
|  ES    | EF      |
|  Duration        |
|  LS    | LF      |
+------------------+
```

Highlight critical path nodes in a distinct colour (red or bold border). Non-critical nodes in a neutral colour. This visual makes the zero-float concept immediately apparent.

---

*This is your single preparation document. Every section maps directly to the rubric. If it is not in this guide, it is not worth your preparation time. If it is in this guide, it will earn you marks.*

---

## APPENDIX C: FULL SPEAKER SCRIPTS

These are complete word-for-word scripts for each slide. Each speaker should internalise these, not memorise them verbatim -- the goal is to hit every point in natural language while maintaining conversational delivery. Speaker assignments assume a four-person team: [Speaker A] led algorithm development, [Speaker B] led the JSON parser and data model, [Speaker C] managed testing and quality assurance, [Speaker D] built the visualization and coordinated integration.

---

### [Speaker A] -- Slide 1: Title and Context (30 seconds)

"Good morning. We are Group [X] and today we will present our Critical Path Method application. I am [A], I led the algorithm development. [B] led the JSON parser and data model. [C] managed our testing and quality assurance. And [D] built the visualization and coordinated our integration. We chose to automate critical path identification because the algorithm -- with its forward pass, backward pass, and convergence handling -- presented a rich opportunity to demonstrate PM scheduling concepts in practice."

---

### [Speaker B] -- Slide 2: Live Demo (90 seconds)

"Let me run our application on the test scenario from the brief. [Runs app.] You can see two outputs. First, the terminal shows the full CPM table -- earliest start and finish, latest start and finish, float, and whether each activity is critical. Activity A has an earliest start of 0 and earliest finish of 3. When we reach activity F -- Integration -- notice its earliest start is 15, not 13. That is because F depends on both D and E, and E does not finish until day 15. The forward pass takes the maximum, which is the core logic of CPM at convergence points.

Second, our application opens this interactive network diagram. Critical path activities -- A, C, E, F, G -- are highlighted in red. B and D appear in grey with their 2 days of float. We built this because CPM is fundamentally a visual concept -- it is the longest path through the network -- and a project manager needs to see that path, not just read a table.

The critical path is A, C, E, F, G. Project duration: 22 days. Activities B and D have 2 days of float -- meaning a project manager could delay Design or Frontend Development by up to 2 days, or reallocate their resources to critical activities, without affecting the deadline."

---

### [Speaker C] -- Slide 3: Development Decisions (2 minutes)

"Let me walk you through the key decisions we made and why each connects to project management.

First, we chose C over Python. Python would have been faster to develop, but C required us to define explicit data structures -- our Activity struct contains fields for ES, EF, LS, LF, slack, and is_critical -- which forced us to deeply understand how CPM data flows through the forward and backward passes. The trade-off was slower development velocity. We mitigated this by defining shared header files as interface contracts on Day 1, enabling parallel development.

Second, we used JSON for input because its nested structure naturally represents the activity-dependency relationship that CPM requires. Each activity object contains an ID, name, duration, and a dependencies array. CSV would have required flattening this structure -- a comma-separated list inside a comma-separated file -- which is fragile and harder to validate.

Third, we separated our parser from our algorithm -- parse.c handles JSON, cpm.c handles the forward and backward passes. This is modular decomposition from systems engineering. It reduced our integration risk because each module could be developed and tested independently. It also enabled parallel development -- [B] built the parser while I built the algorithm, and we integrated on Day 2 against our shared Activity struct.

Finally, we built two independent implementations -- one in C and one in Python -- to cross-validate our calculations. When both produced identical ES, EF, LS, LF, and float values, we had high confidence in our algorithm's accuracy. This is analogous to independent estimation in project management, where two separate estimates increase confidence in the result."

---

### [Speaker D] -- Slide 4: Teamwork Evidence (2 minutes)

"Now let me show you how we worked together as a team.

We used a Kanban board to manage our two-day sprint. You can see it here -- columns for To Do, In Progress, and Done, with each task assigned to a specific team member. We chose Kanban over Scrum because our compressed timeline could not accommodate sprint ceremonies. Kanban's pull-based model let us rebalance work as we discovered that some tasks -- like JSON parsing -- took longer than expected, without the overhead of formal replanning.

We allocated roles based on individual strengths. [A] has the strongest algorithmic background, so they led the CPM computation. [B] had prior experience with file I/O and data structures, so they owned the parser. [C] has an analytical mindset suited to testing. And I focused on visualization and integration because of my experience with graphics libraries.

Here is our commit log showing parallel development -- [A] and [B] were committing to cpm.c and parse.c simultaneously on Day 1, while [C] was writing the test suite. This parallel work was only possible because we agreed on the Activity struct as our interface contract before splitting.

We anticipated that integrating separately developed modules would be risky. So on Day 1 morning, before writing any code, we defined the Activity struct in parse.h as our shared contract. When we integrated on Day 2, it worked on the first attempt. This was proactive risk management -- we identified integration as our highest risk and mitigated it before it became a problem.

Our test suite contains five automated tests, including edge cases like single-activity projects, parallel paths, cycle detection, and duplicate ID rejection. These tests ran before every integration, applying the quality management principle of building verification into the process."

---

### [Speaker A] -- Slide 5: Reflection on Team Dynamics (2 minutes)

"Now for our honest reflection on what we learned.

I assumed that dividing work strictly by module -- algorithm, parser, tests, visualization -- would maximize efficiency. What actually happened was that when [C] started writing test cases, they could not write meaningful assertions without understanding how the backward pass updates predecessor LF values. We had created knowledge silos. I learned that modular decomposition of work must be paired with cross-module knowledge sharing -- what project risk management calls reducing the 'bus factor.' Belbin would say we over-indexed on Specialist roles and needed more Resource Investigators bridging across modules. In future, I would pair team members at integration boundaries, even when roles are formally separated."

**[Speaker B]:**

"I assumed we should plan everything on Day 1 morning to avoid wasting time. Our initial plan had the parser and algorithm both complete by end of Day 1. By 3pm, the parser worked but the algorithm was incomplete. We held a 15-minute stand-up and replanned -- moving the visualization to a stretch goal and prioritizing algorithm completion and testing. I learned that in uncertain, time-constrained projects, rigid upfront planning creates an illusion of control. The Agile principle of 'responding to change over following a plan' is not just a philosophy -- it is a survival strategy for short sprints. In future, I would build explicit replanning checkpoints into any compressed timeline."

**[Speaker C]:**

"We anticipated that integration would be our highest-risk moment, so we agreed on the Activity struct before writing any code and I wrote a test that exercised the full pipeline -- parse, validate, topological sort, CPM compute -- against the brief's expected values. When integration happened on Day 2, all five tests passed immediately. I learned that proactive interface definition -- which is essentially scope baseline management applied to code -- has disproportionate impact on integration risk. This connects directly to CPM itself: just as we identified critical activities in our application, we needed to identify critical dependencies in our team process."

---

### [Speaker D] -- Slide 6: Lessons Learned and Future Application (1 minute)

"Three lessons we are taking forward.

First: methodology selection should be constraint-driven. We chose Kanban because our two-day timeline made Scrum ceremonies disproportionately expensive. In a longer project -- say, a six-month construction schedule -- we would use a more predictive approach because task durations would be better understood. The lesson is not that Kanban is always right, but that you match methodology to uncertainty level.

Second: separating concerns enables parallel work but requires explicit interface management. Our parse.c and cpm.c worked independently, but only because we invested 30 minutes on Day 1 defining the shared struct. Separation without interface planning creates integration risk -- a lesson we now understand through experience, not just theory.

Third: asking for help is risk mitigation. When [A] was stuck on the backward pass, [D]'s pair-programming suggestion unblocked two hours of stalled work in 30 minutes. In PM terms, this is a risk response -- we transferred the risk of delay from one person to the team. In future, I would normalise asking for help as a team protocol, not an admission of weakness."

---

### [Speaker A] -- Slide 7: Summary and Closing (30 seconds)

"To summarise: we built a CPM application in C that correctly performs forward and backward passes, calculates float, identifies the critical path, and visualises it as an interactive AON network diagram. We validated it against the brief's test scenario and cross-checked with an independent Python implementation. More importantly, we learned that building a project management tool taught us project management -- the scheduling, risk mitigation, and team coordination we applied in our own sprint are the same concepts our application automates. Thank you. We welcome your questions."
