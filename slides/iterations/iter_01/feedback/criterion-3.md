# Criterion 3: Reflection on Team Dynamics and Development (20%)

## Mark Awarded: 16 / 20

## Band: A+ (80-100)

## Rubric Band Placement

**Band above (n/a — this is the highest band):**
> N/A — A+ is the ceiling.

**Band awarded — A+ (80-100):**
> "Insightful, critically evaluative reflection; demonstrates high self- and team-awareness; lessons learned are clearly articulated."

**Band below — A (70-79):**
> "Strong reflection; critical evaluation present; good awareness of team and self-learning."

## What Earns the Mark

### Reflections Are Critically Evaluative, Not Merely Descriptive or Analytical

Each reflection in Slide 8 follows the five-part structure: assumption → event → learning → theory → future action. This is the hallmark of critically evaluative reflection because it interrogates prior assumptions rather than merely describing events.

**Demonstration using the descriptive → analytical → critically evaluative spectrum:**

- **Descriptive (caps at C):** "We used C for our project."
- **Analytical (B range):** "Using C slowed us down because not everyone knew it well."
- **Critically evaluative (A/A+ — what Jamie actually writes):** "I assumed that because we all agreed on C initially, the language decision was settled. In practice, Hamza and Samuel found C significantly slowed their implementation — what seemed like consensus was actually untested assumption. I learned that agreement at the start doesn't mean the decision was thorough. We estimated based on enthusiasm, not effort."

Jamie's reflection explicitly identifies and challenges a prior assumption ("consensus = thoroughness"), identifies the mechanism of failure ("untested assumption"), and derives a transferable principle about estimation. This IS critical evaluation.

**Samuel's reflection similarly:**
- Challenges assumption: "I assumed that writing tests independently of the algorithm would be straightforward"
- Identifies why it failed: "I couldn't write meaningful test assertions without understanding how the backward pass updates LF values"
- Derives insight: "Separating code modules doesn't separate knowledge dependencies — the tester needs to understand the algorithm's logic, not just its outputs"
- Connects to theory with specificity: "This connects to Wilemon & Thamhain's 'Communication Problems' barrier — not a lack of talking, but a lack of shared technical understanding."

The distinction Samuel draws — "not a lack of talking, but a lack of shared technical understanding" — demonstrates genuine critical analysis. It reinterprets the theory for the specific context rather than simply citing it.

### High Self-Awareness (Slide 8)

Each team member identifies their own incorrect assumption and owns it in first person:

- Jamie: "I assumed... what seemed like consensus was actually untested assumption" — owns the failure to verify the decision
- Samuel: "I assumed... I had to interrupt Jamie for an explanation" — acknowledges dependency he didn't foresee
- Cole: "I assumed my role was just to render the output" — challenges his own narrow framing of his contribution
- Hamza: "I assumed that if everyone followed the same spec, integration would be straightforward" — identifies naive faith in documentation

No member deflects blame or presents themselves as having been correct all along. Each identifies what THEY got wrong.

### High Team-Awareness (Slides 4, 7, 8)

The reflections show understanding of how individual actions affected team dynamics:

- Samuel recognises interrupting Jamie was a team-level problem (knowledge silos affecting workflow)
- Cole recognises his work served a team function he hadn't planned (visualisation as validation)
- Hamza recognises that cross-module oversight was a team need, not just his personal contribution
- Jamie recognises his assumption affected the whole team's velocity (the C language choice)

### Lessons Learned Clearly Articulated (Slide 8)

Each lesson is:
1. **Specific** (not "communicate better" but "schedule a 15-minute knowledge-sharing session before testing begins")
2. **Actionable** (contains a concrete action: "push for a short spike", "schedule a mid-sprint alignment check")
3. **Transferable** (applies to future projects, not just this one)
4. **Theoretically grounded** (connected to a course concept)

Examples:
- Jamie: "In future, I would push for a short spike or prototype before committing the whole team to a technology choice." — Specific, actionable, transferable.
- Samuel: "I would schedule a 15-minute knowledge-sharing session before testing begins, so everyone understands the data flow." — Specific duration, specific timing, specific purpose.
- Hamza: "I would schedule a mid-sprint alignment check specifically for cross-module type consistency." — Specific timing, specific focus, directly addresses the root cause.

### Theory Connected to Experience (Not Name-Dropped)

- Samuel connects to Wilemon & Thamhain (1983) with a reinterpretation: "'Communication Problems' barrier — not a lack of talking, but a lack of shared technical understanding." This APPLIES the theory, not merely cites it.
- Jamie connects to estimation principles (K15) by identifying that three-point estimation should have been applied to the language decision itself — a creative application of the concept.
- Slide 7 connects the conflict to Tuckman's Storming and the resolution process to Wilemon & Thamhain's recommendation for equal airtime.

## What Holds the Mark Back

### Cole's Reflection Is Less Critically Evaluative Than Others (Slide 8)

Cole's reflection: "I learned that visual output has disproportionate value in catching errors — it's a form of verification that complements automated testing. This connects to quality management — building multiple verification methods into the process rather than relying on a single approach."

The theory connection ("quality management") is vaguer than the specific citations in Jamie's (estimation principles, K15) and Samuel's (Wilemon & Thamhain, 'Communication Problems'). "Quality management" is a broad area, not a specific framework. To reach the same depth as the other reflections, Cole would need to connect to a specific quality principle — e.g., "This connects to the 'build quality in' principle from lean manufacturing — visual management boards (Ohno, 1988) serve the same function as my graph visualisation: making problems visible immediately rather than waiting for formal inspection."

### Hamza's Theory Connection Could Be Deeper (Slide 8)

Hamza: "This connects to integration risk management — proactive checking reduces the probability of integration failure, which is a mitigation strategy rather than avoidance."

This is competent but the theory reference ("integration risk management") is generic — it's a description of what he did, not a named framework. A stronger connection would be: "This connects to Wilemon & Thamhain's barrier of 'Role Conflicts' — the ambiguity wasn't in who owned which module, but in who owned the INTERFACE between modules. My mid-sprint check functioned as what Highsmith (2002) calls an 'integration ceremony' — a deliberate synchronisation point."

### No Explicit Reference to Tuckman Stage in Reflections (Slide 8)

The reflections describe team dynamics events but don't explicitly place them within the Tuckman model. For example, Samuel's knowledge-silo problem could be framed as a Norming-stage breakdown: "I assumed we had fully Normed — shared processes established — but our Norming was incomplete because it covered workflow (who does what) without covering knowledge (who knows what). True Norming requires both."

### Reflections Could Interrogate Whether "In Future I Would..." Is Always Correct

The reflections end with confident future actions, but don't question whether those actions might have trade-offs. For example, Jamie's "push for a short spike before committing" — what's the cost? A spike in a 2-day timeline might consume 25% of available time. The most sophisticated reflection would acknowledge this tension: "A spike would cost half a day in our timeline — but the cost of NOT spiking was higher (half a day of rework). The break-even point depends on project duration and reversibility."

## Actionable Improvements

1. **Slide 8 (Cole) — Strengthen theory connection:** Replace "This connects to quality management" with a specific citation: "This connects to the principle of 'visual management' from lean thinking — making work and problems visible in real-time rather than waiting for formal inspection stages. Our graph served the same function as a build radiator in continuous integration."

2. **Slide 8 (Hamza) — Name a specific framework:** Replace "integration risk management" with: "This connects to Wilemon & Thamhain's 'Role Conflicts' barrier — the ambiguity wasn't in who owned which module, but in who owned the interface between modules. In future teams, I would explicitly assign interface ownership as a separate responsibility from module ownership."

3. **Slide 8 (Any member) — Add Tuckman staging to one reflection:** E.g., Samuel could add: "This revealed that our Norming was incomplete — we'd agreed on workflow ('who does what') but not on knowledge flow ('who needs to understand what'). Tuckman's model treats Norming as uniform, but in practice our team Normed at different layers at different speeds."

4. **Slide 8 (Jamie) — Acknowledge trade-off in future action:** Add: "A spike costs time — in a 2-day sprint, half a day is 25% of our budget. But the cost of NOT spiking (half a day of rework plus team friction) was higher. The lesson isn't 'always spike' but 'spike when reversibility is low and the team will be locked in.'"

## Conclusion

The reflections are genuinely insightful and critically evaluative — they interrogate assumptions, identify mechanisms of failure, connect to course theory with application (not just citation), and articulate specific, actionable lessons. The mark sits at 80% (16/20) — the lower boundary of A+ — because the strongest reflections (Jamie's, Samuel's) clearly meet the "insightful, critically evaluative" descriptor, while Cole's and Hamza's, though good, have vaguer theory connections. The self-awareness and team-awareness are consistently high across all four members. The primary gap to higher A+ is the absence of meta-reflection on trade-offs in the proposed future actions, and the opportunity to situate the reflections within Tuckman's developmental stages explicitly.
