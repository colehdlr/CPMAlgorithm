"""Critical Path Method - load a project network and compute the schedule."""

from __future__ import annotations

import json
from collections import deque
from dataclasses import dataclass, field
from pathlib import Path


@dataclass
class Activity:
    id: str
    name: str
    duration: int
    dependencies: list[str] = field(default_factory=list)
    es: int = 0
    ef: int = 0
    ls: int = 0
    lf: int = 0
    slack: int = 0
    is_critical: bool = False


class Project:
    """A project network with CPM schedule computed on construction.

    >>> p = Project.from_json("data/activities.json")
    >>> p.duration
    22
    >>> [a.id for a in p.critical_path]
    ['A', 'C', 'E', 'F', 'G']
    """

    def __init__(self, activities: list[Activity]) -> None:
        self._by_id = _validate_and_index(activities)
        self._topo_order = _topological_sort(self._by_id)
        self._duration = _compute_cpm(self._by_id, self._topo_order)

    @classmethod
    def from_json(cls, path: str | Path) -> Project:
        with open(path) as f:
            data = json.load(f)
        return cls([
            Activity(
                id=item["id"],
                name=item.get("name", item["id"]),
                duration=item["duration"],
                dependencies=item.get("dependencies", []),
            )
            for item in data["activities"]
        ])

    @property
    def activities(self) -> list[Activity]:
        return [self._by_id[aid] for aid in self._topo_order]

    @property
    def duration(self) -> int:
        return self._duration

    @property
    def critical_path(self) -> list[Activity]:
        return [a for a in self.activities if a.is_critical]

    def format_table(self) -> str:
        acts = self.activities
        iw = max(max(len(a.id) for a in acts), 2)
        nw = max(max(len(a.name) for a in acts), 4)
        header = (
            f"{'ID':<{iw}}  {'Name':<{nw}}  {'Dur':>5}  "
            f"{'ES':>4}  {'EF':>4}  {'LS':>4}  {'LF':>4}  {'Slack':>5}  Crit"
        )
        rows = [header, "-" * len(header)]
        for a in acts:
            rows.append(
                f"{a.id:<{iw}}  {a.name:<{nw}}  {a.duration:>5}  "
                f"{a.es:>4}  {a.ef:>4}  {a.ls:>4}  {a.lf:>4}  {a.slack:>5}  "
                f"{'*' if a.is_critical else ''}"
            )
        rows.append(f"\nProject duration: {self.duration}")
        return "\n".join(rows)


# -- Private implementation ------------------------------------------------


def _validate_and_index(activities: list[Activity]) -> dict[str, Activity]:
    by_id: dict[str, Activity] = {}
    for a in activities:
        if a.id in by_id:
            raise ValueError(f"duplicate activity id '{a.id}'")
        if a.duration < 0:
            raise ValueError(f"activity '{a.id}' has negative duration")
        by_id[a.id] = a
    for a in activities:
        for dep in a.dependencies:
            if dep not in by_id:
                raise ValueError(f"activity '{a.id}' depends on unknown id '{dep}'")
            if dep == a.id:
                raise ValueError(f"activity '{a.id}' depends on itself")
    return by_id


def _topological_sort(by_id: dict[str, Activity]) -> list[str]:
    successors: dict[str, list[str]] = {aid: [] for aid in by_id}
    in_degree: dict[str, int] = {}
    for a in by_id.values():
        in_degree[a.id] = len(a.dependencies)
        for dep in a.dependencies:
            successors[dep].append(a.id)

    queue = deque(aid for aid, deg in in_degree.items() if deg == 0)
    order: list[str] = []
    while queue:
        node = queue.popleft()
        order.append(node)
        for succ in successors[node]:
            in_degree[succ] -= 1
            if in_degree[succ] == 0:
                queue.append(succ)

    if len(order) != len(by_id):
        raise ValueError(
            f"cycle detected (sorted {len(order)} of {len(by_id)} activities)"
        )
    return order


def _compute_cpm(by_id: dict[str, Activity], topo_order: list[str]) -> int:
    for aid in topo_order:
        a = by_id[aid]
        a.es = max((by_id[d].ef for d in a.dependencies), default=0)
        a.ef = a.es + a.duration

    project_duration = max(a.ef for a in by_id.values())

    for a in by_id.values():
        a.lf = project_duration
    for aid in reversed(topo_order):
        a = by_id[aid]
        a.ls = a.lf - a.duration
        a.slack = a.ls - a.es
        a.is_critical = a.slack == 0
        for dep in a.dependencies:
            by_id[dep].lf = min(by_id[dep].lf, a.ls)

    return project_duration
