You are improving a university group presentation slide set based on detailed marker feedback. Your goal is to push the mark into the 80-100 (A+) band across all four criteria.

## Your Task

1. Read ALL marker feedback files (one per criterion, plus a summary):
   - `{{PROJECT}}/feedback/criterion-1.md`
   - `{{PROJECT}}/feedback/criterion-2.md`
   - `{{PROJECT}}/feedback/criterion-3.md`
   - `{{PROJECT}}/feedback/criterion-4.md`
   - `{{PROJECT}}/feedback/summary.md`

2. Read the assignment brief for context: `{{PROJECT}}/brief.txt`

3. Read ALL lecture notes — use these as source material for PM theory to weave into the slides:
   - `{{PROJECT}}/lecture-notes/weeek-1-introduction-to-projects-new-student-copy.md`
   - `{{PROJECT}}/lecture-notes/week-2-team-dynamics-and-online-leadership-student-copy.md`
   - `{{PROJECT}}/lecture-notes/week-4-estimation-i-student-copy.md`
   - `{{PROJECT}}/lecture-notes/week-5-estimation-ii-intervention-student-copy.md`
   - `{{PROJECT}}/lecture-notes/iot591u-leadership-communication-and-professional.md`

4. Read ALL presentation slide files:
   - `{{PROJECT}}/01-title.md`
   - `{{PROJECT}}/02-team-roles.md`
   - `{{PROJECT}}/03-demonstration.md`
   - `{{PROJECT}}/04-programming-allocation.md`
   - `{{PROJECT}}/05-cpm-walkthrough.md`
   - `{{PROJECT}}/06-key-decisions.md`
   - `{{PROJECT}}/07-challenges.md`
   - `{{PROJECT}}/08-team-reflection.md`
   - `{{PROJECT}}/09-summary-closing.md`
   - `{{PROJECT}}/10-references.md`
   - `{{PROJECT}}/11-qa-preparation.md`

5. Edit the slide files directly, addressing **EVERY** piece of feedback in the rubric assessment.

---

## What 80-100 (A+) Looks Like — Your Target

These are the EXACT rubric descriptors for the A+ band. Every slide edit should be driving toward these:

### Criterion 1: Understanding of Estimation & PM Concepts (30%)
> "Application demonstrates exceptional understanding of estimation or critical path; calculations/processes are accurate and well-justified."

What "exceptional" and "well-justified" mean in practice:
- The CPM walkthrough doesn't just show the algorithm — it explains WHY forward/backward passes work, what the critical path MEANS for project planning, and how float enables schedule flexibility
- Estimation decisions aren't just described — they are justified using PM principles (Iron Triangle, PERT, WBS)
- The team shows they understand the IMPLICATIONS of their choices, not just the mechanics
- PM concepts are woven through multiple slides (not isolated to one "theory slide")

### Criterion 2: Teamwork and Collaboration (30%)
> "Exceptional collaboration and leadership; clear role allocation; team supported each other; challenges handled proactively. The approaches put in place to manage team dynamics are effective, and there is clear evidence of not only learning that informs future team working environments, but also critical analysis of why such strategies were effective in this context."

What distinguishes A+ from A here:
- A (70-79) says: "approaches put in place to manage team dynamics are effective, and there is clear evidence of learning that informs future team working environments"
- A+ adds: "critical analysis of WHY such strategies were effective in this context"
- So the slides must not just say "we used daily stand-ups and they worked" — they must analyse WHY stand-ups were effective for THIS team in THIS context (e.g., "stand-ups worked because our modular task split meant blockers in one module cascaded to others within hours, making daily synchronisation critical")

### Criterion 3: Reflection on Team Dynamics and Development (20%)
> "Insightful, critically evaluative reflection; demonstrates high self- and team-awareness; lessons learned are clearly articulated."

The key word is "critically evaluative" — this means:
- Each reflection must challenge an assumption the person held
- Each reflection must identify a gap between expectation and reality
- Each reflection must extract a transferable lesson grounded in PM theory
- Each reflection must propose a specific future action (not "communicate better")

### Criterion 4: Response to Feedback and Presentation Quality (20%)
> "Outstanding presentation; clear, engaging, professional; responds to feedback confidently and thoughtfully; all members actively participate."

What "outstanding" means:
- The slide structure is logical and builds a narrative arc (not just a list of topics)
- Speaker notes are confident and natural-sounding (not essay-like or robotic)
- ALL four members (Samuel, Jamie, Cole, Hamza) have meaningful speaking roles
- The Q&A preparation slide shows genuine anticipation of challenging questions and thoughtful answers
- Timing adds up to approximately 10 minutes

---

## How to Improve — Specific Guidance

### For PM Theory Integration (Criterion 1)

DO NOT just name-drop theories. Instead, use this pattern:

BAD: "We used the Iron Triangle to make decisions."
GOOD: "We faced a trade-off between time and quality when choosing C over Python. C required more development time but gave us explicit control over memory and data structures, which deepened our understanding of the CPM graph model. This is an Iron Triangle trade-off (Atkinson, 1999) — we deliberately accepted higher time cost to protect scope and quality."

Specific theories to integrate where relevant (from the module lectures):

| Theory | Where it fits | How to apply it |
|--------|--------------|-----------------|
| Iron Triangle (scope/time/cost) | Slide 06 (Key Decisions) | Frame language choice, scope decisions as explicit trade-offs between the three constraints |
| PERT: E = (O + 4M + P) / 6 | Slide 05 or 06 | Show how three-point estimation could have improved duration estimates; connect to their own estimation failures |
| WBS (Work Breakdown Structure) | Slide 04 (Programming Allocation) | Frame the module split as a responsibility-based WBS; each module = work package |
| Tuckman's stages | Slide 07 (Challenges) or 08 (Reflection) | Map the team's ACTUAL journey through Forming/Storming/Norming/Performing with specific moments as evidence |
| Belbin's team roles | Slide 02 (Team Roles) | Map each team member to Belbin roles and explain how the role distribution affected team dynamics |
| Wilemon & Thamhain barriers | Slide 07 (Challenges) or 08 (Reflection) | Identify WHICH specific barriers the team hit (Communication Problems, Role Conflicts, etc.) and how they were overcome |
| Servant Leadership (Greenleaf) | Slide 07 or 08 | If any team member unblocked others, frame it as servant leadership |
| Agile practices | Slide 04 or 07 | Connect any sprint-like practices (daily check-ins, iterative development) to Agile methodology |
| McClelland's Theory of Needs | Slide 08 (Reflection) | If relevant, connect team motivation to achievement/power/affiliation needs |
| Estimation methods | Slide 06 | Reference expert judgement, analogous, parametric, bottom-up, top-down estimation — identify which the team actually used |
| CHAOS report statistics | Slide 05 or 06 | "The Standish Group reports 66% of software projects fail; our use of CPM to track dependencies was a deliberate mitigation" |

### For Reflections (Criterion 3)

Every reflection MUST follow this five-part formula:

> "I assumed [X] -> [Y] happened -> I learned [Z] -> This connects to [specific theory with citation] -> In future I would [concrete action]"

Check each of the four reflections (Jamie, Samuel, Cole, Hamza) against this formula. If any part is missing, add it.

Common failures to fix:
- Theory connection is vague: "This connects to project management theory" -> Fix: name the specific theory and cite it
- Future action is generic: "I would communicate better" -> Fix: "I would schedule a 15-minute knowledge-sharing session before testing begins"
- The reflection describes what happened but doesn't evaluate WHY it happened or what assumption was wrong
- The reflection doesn't show team-awareness (only self-awareness, or vice versa)

### For Teamwork Evidence (Criterion 2)

The slides must demonstrate ALL of these for A+:
1. **Clear role allocation** — who did what, and WHY those assignments were made (not just listed)
2. **Mutual support** — specific examples of team members helping each other (not just working independently)
3. **Proactive challenge handling** — evidence of anticipating problems, not just reacting to them
4. **Team dynamics strategies** — what approaches the team PUT IN PLACE (contracts, norms, communication patterns) to manage collaboration
5. **Critical analysis of WHY** — not just "daily stand-ups worked" but "daily stand-ups worked because [specific reason in this context]"

### For Presentation Quality (Criterion 4)

- Speaker notes must sound like a real person talking, not an essay being read aloud
- Each slide's "On the Slide" content should be concise bullet points or visuals — the depth goes in speaker notes
- The narrative should flow: Title -> Team -> Demo -> How we split work -> How CPM works -> Key decisions -> Challenges -> What we learned -> Summary -> References -> Q&A
- The Q&A slide must show PREPARED answers, not just questions. The answers should demonstrate depth of understanding.

---

## Constraints — DO NOT Violate These

### Format preservation
- **Preserve the slide format:** Every slide must keep its existing structure: `# Slide N: Title`, `**Speaker:** Name | **Time:** X`, `## On the Slide`, `## Speaker Notes`, `## KSBs Signalled`
- **Do not change speakers:** Keep the same person assigned to each slide
- **Do not change the slide numbering or add/remove slides**

### TIMING — HARD CONSTRAINT
- **The presentation MUST NOT exceed 10 minutes.** The Q&A is a separate 5 minutes and does not count.
- Add up every slide's time allocation. If the total exceeds 10 minutes, you MUST reduce time on slides to fit within 10 minutes. Cut speaker note content to match the reduced time — do not leave 2 minutes of content in a 1-minute slot.
- When reducing time, prioritise keeping the highest-scoring content (PM theory, critical reflections) and trimming descriptive/transitional content.

### SPEAKER ASSIGNMENT — HARD CONSTRAINT
- Every slide must have ONE unambiguous speaker. No "X or Y" — pick one person.
- All four members (Samuel, Jamie, Cole, Hamza) must have at least one slide assigned to them.

### Authenticity guardrails
- **Keep content authentic:** The team built a CPM (Critical Path Method) application in C. The team members are Samuel, Jamie, Cole, and Hamza. All project details, reflections, and examples must be plausible and consistent with this real project.
- **Do not fabricate experiences:** Improve the depth and PM-theoretical grounding of existing reflections — do not invent new events that didn't happen. You may add more analytical depth, theoretical connections, and critical evaluation to existing experiences.
- **Keep reflections in first person:** Each team member's reflection must stay in their own voice ("I assumed...", "I learned...")
- **Keep speaker notes speakable:** Notes should read like things someone would actually say in a presentation, not like an essay. Test: could a student actually say this out loud naturally?

### Anti-AI-voice guardrails
These are critical. A marker who suspects AI-generated content will penalise heavily.

- **Do NOT make every section equally polished.** Real student work has some sections stronger than others. Let the reflections and theory sections be the strongest; let transitional slides (title, demo) stay brief.
- **Do NOT use corporate/AI-sounding phrases.** Avoid: "leveraged", "holistic approach", "multifaceted", "synergy", "in this context", "it is worth noting", "this underscores". Use plain student language instead.
- **Do NOT over-cite.** 4-6 well-placed theory references across the whole deck is ideal. 15+ references looks AI-generated. Each reference should appear where it naturally fits, not shotgunned everywhere.
- **Preserve imperfection.** If a student's reflection has a slightly informal tone ("we really struggled with this"), keep it — that's authentic voice. Don't polish it into "this presented a significant challenge to the team."
- **Vary sentence structure.** Real speaker notes mix short punchy sentences with longer explanations. Don't make everything the same length or structure.
- **Let different speakers sound different.** Jamie's speaking style should feel different from Hamza's. Don't homogenise the voice across all speaker notes.

---

## Quality Standards

- Make genuine analytical improvements — don't just add filler sentences
- Every PM theory reference should include the specific concept name AND how it applies to this project
- Reflections must follow the pattern: assumption -> what happened -> what I learned -> theory connection -> future action
- Ensure new content integrates coherently with existing content — don't create jarring transitions where new material was inserted
- Keep slide bullet points concise (the audience sees these) — put depth in the speaker notes
- Harvard referencing style for any academic sources added
- When adding a theory connection, make sure it is CORRECT. Don't misattribute frameworks or misstate what a theory says. Check against the lecture notes.

---

## Prioritisation

If you must choose where to invest most effort, prioritise in this order:

1. **Criterion 2 (Teamwork, 30%)** — this is often the hardest to get right because it requires both evidence of collaboration AND critical analysis of WHY strategies worked. Focus especially on adding the "critical analysis of why" component.
2. **Criterion 1 (PM Concepts, 30%)** — ensure every PM decision is justified with theory, not just described.
3. **Criterion 3 (Reflection, 20%)** — ensure every reflection has all five parts of the formula and is critically evaluative.
4. **Criterion 4 (Presentation Quality, 20%)** — this is largely about professional structure and Q&A preparation.

---

## Important

Do not stop partway through. Address every single item of feedback before finishing. Edit every slide file that needs improvement. After editing, do a final pass to check:

1. Does every reflection have all five parts? (assumption, event, learning, theory, future action)
2. Is there critical analysis of WHY team strategies worked (not just that they worked)?
3. Are PM theories applied (not just named)?
4. Do the speaker notes sound like a real student talking?
5. Do all four team members have active speaking roles?
6. Does the Q&A slide have prepared, thoughtful answers?
7. Are there 4-6 well-placed theory references with Harvard citations on the references slide?
