# Slide 7: Challenges and Conflict Resolution

**Speaker:** Hamza | **Time:** 1 minute

---

## On the Slide

- **Proactive:** Shared struct definition (30 mins) prevented integration conflicts; JSON vs CSV spike (20 mins) saved ~2-3 hrs rework
- **Reactive:** C language debate → 15-min escalation rule triggered → structured round-robin → stick with C + support each other
- **Why it worked for this team:** Round-robin gave structure, but it only worked because prior shared failure built trust that blame wouldn't follow disagreement (Edmondson, 1999). The process is portable; the trust is not.
- **Gap:** No spike on C — we confused enthusiasm with capability
- **Beyond task:** Jamie noticed Samuel was quieter — unprompted check surfaced unvoiced frustration

> **Evidence — Teams (Day 1, 15:47):**
> Hamza: *"C is taking way longer than we expected, should we switch?"*
> Samuel: *"the parser is brutal with all the malloc/free, python would be 10 lines."*
> Jamie: *"Let's stop and talk this through properly."*

---

## Speaker Notes

We agreed on C initially but it slowed Samuel down. Our escalation rule kicked in — unresolved after 15 minutes, structured round-robin. Decision: stick with C, support each other. After that, Jamie pair-programmed Samuel's malloc patterns for 45 minutes. Parser completed by Day 2 morning — the bottleneck was C syntax, not logic, and Jamie had that fluency.

The round-robin worked for us specifically because we're self-selecting peers with an existing relationship — a previous module failure taught us that blame destroys speed. That trust made it safe to say "I'm struggling" rather than defending a position. In a new team without that history, the same process might produce politeness rather than honesty. The process is portable; the trust enabling it is not.

Not all challenges were reactive. The JSON spike cost 20 minutes, saved 2-3 hours. No spike on C — an hour of frustration instead. That's our gap: we spiked the easy decision but not the risky one.

Beyond tasks, Jamie noticed Samuel was quieter and messaged privately — surfacing frustration he hadn't voiced.
