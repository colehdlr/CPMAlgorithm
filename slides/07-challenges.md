# Slide 7: Challenges and Conflict Resolution

**Speaker:** Hamza | **Time:** 1 minute

---

## On the Slide

- **Proactive:** Shared struct definition (30 mins) prevented integration conflicts; JSON vs CSV spike (20 mins) saved ~2-3 hrs rework
- **Reactive:** C language debate → 15-min escalation rule triggered → structured round-robin → stick with C + support each other
- **Why it worked for this team:** Round-robin gave structure, but it only worked because we already trusted each other from a previous module failure — we knew blame wouldn't follow disagreement (Edmondson, 1999). A new team using the same process without that trust would get politeness, not honesty.
- **Gap:** No spike on C — we were all excited about it so nobody questioned whether we could actually do it
- **Beyond task:** Jamie noticed Samuel was quieter — unprompted check surfaced unvoiced frustration


---

## Speaker Notes

We agreed on C initially but it slowed Samuel down. Our escalation rule kicked in — unresolved after 15 minutes, structured round-robin. Decision: stick with C, support each other. After that, Jamie pair-programmed Samuel's malloc patterns for 45 minutes. Parser completed by Day 2 morning — the bottleneck was C syntax, not logic, and Jamie had that fluency.

The round-robin worked for us specifically because we already knew each other — a previous module failure taught us that blame destroys speed. That trust made it safe to say "I'm struggling" rather than defending a position. In a new team without that history, the same process would probably produce politeness rather than honesty.

Not all challenges were reactive. The shared struct definition took 30 minutes upfront but prevented integration conflicts entirely. The JSON spike cost 20 minutes, saved 2-3 hours. No spike on C — an hour of frustration instead. That's our gap: we spiked the easy decisions but not the risky one.

Beyond tasks, Jamie noticed Samuel was quieter and messaged privately — surfacing frustration he hadn't voiced.
