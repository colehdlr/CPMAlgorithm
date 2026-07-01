# Slide 7: Challenges and Conflict Resolution

**Speaker:** Hamza | **Time:** 1 minute 5 seconds

---

## On the Slide

- **Proactive:** Shared struct definition (30 mins) prevented integration conflicts; JSON vs CSV spike (20 mins) saved ~2-3 hrs rework
- **Reactive:** C language debate → 15-min escalation rule triggered → structured round-robin → unanimous decision to stick with C + support each other
- **Why it worked:** Round-robin created urgency, prevented dominance, lowered emotional temperature; trust from shared failure in prior module provided psychological safety (Edmondson, 1999)
- **Gap:** No spike on C — confirmation bias made us confuse enthusiasm with capability
- **Beyond task:** Jamie noticed Samuel was quieter — unprompted check surfaced unvoiced frustration

> **Evidence — Teams (Day 1, 15:47):**
> Hamza: *"C is taking way longer than we expected, should we switch?"*
> Cole: *"we're 80% done on the algorithm, switching now would waste more time than finishing."*
> Samuel: *"yeah but the parser is brutal with all the malloc/free, python would be 10 lines."*
> Jamie: *"Let's stop and talk this through properly."*

---

## Speaker Notes

We agreed on C initially but it slowed Samuel down. Our escalation rule kicked in — unresolved after 15 minutes, structured round-robin. Decision: stick with C, support each other. After that, Jamie pair-programmed Samuel's malloc patterns for 45 minutes. Parser completed by Day 2 morning — the bottleneck was C syntax, not logic, and Jamie had that fluency.

The round-robin worked: time limit created urgency, turn-taking prevented dominance, structure lowered emotional temperature. But only because a shared failure in a previous module taught us that blame destroys speed — that trust provided psychological safety (Edmondson, 1999). The process is portable, the trust is not.

We proactively prevented Role Conflicts via RACI and Communication Problems via stand-ups (Wilemon and Thamhain, 1983) — encountered Differing Outlooks during the C debate.

Not all challenges were reactive. The JSON spike cost 20 minutes, saved 2-3 hours. No spike on C — an hour of frustration instead.

Beyond tasks, Jamie noticed Samuel was quieter and messaged privately — surfacing frustration he hadn't voiced.
