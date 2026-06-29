"""Render a CPM project network as a matplotlib figure."""

from __future__ import annotations

from typing import TYPE_CHECKING

import matplotlib.patches as patches
import matplotlib.pyplot as plt

if TYPE_CHECKING:
    from cpm import Project

DARK_BG = "#12161e"
CRITICAL_RED = "#c82828"
NORMAL_BORDER = "#3c4858"
NODE_TEXT = "#141820"


def render(project: Project) -> None:
    activities = project.activities
    by_id = {a.id: a for a in activities}
    positions = _layout(activities)
    max_rank = max(_rank(a, by_id) for a in activities)

    fig, ax = plt.subplots(
        figsize=(max(10, (max_rank + 1) * 3.5), 6),
    )
    ax.set_aspect("equal")
    ax.axis("off")
    fig.patch.set_facecolor(DARK_BG)
    ax.set_facecolor(DARK_BG)

    node_w, node_h = 2.4, 1.6

    for a in activities:
        x2, y2 = positions[a.id]
        for dep in a.dependencies:
            x1, y1 = positions[dep]
            pred = by_id[dep]
            critical = pred.is_critical and a.is_critical and pred.ef == a.es
            ax.annotate(
                "",
                xy=(x2 - node_w / 2, y2),
                xytext=(x1 + node_w / 2, y1),
                arrowprops=dict(
                    arrowstyle="->",
                    color=CRITICAL_RED if critical else "#5a5a5a",
                    lw=2.0 if critical else 1.2,
                ),
            )

    for a in activities:
        x, y = positions[a.id]
        fill = "#ffe0e0" if a.is_critical else "#f5f7fa"
        edge = CRITICAL_RED if a.is_critical else NORMAL_BORDER

        rect = patches.FancyBboxPatch(
            (x - node_w / 2, y - node_h / 2),
            node_w,
            node_h,
            boxstyle="round,pad=0.1",
            facecolor=fill,
            edgecolor=edge,
            linewidth=2.0 if a.is_critical else 1.0,
        )
        ax.add_patch(rect)

        mono = dict(fontsize=6, color=NODE_TEXT, family="monospace", ha="center", va="center")
        ax.text(x, y + node_h * 0.30, f"{a.id}  ({a.duration}d)",
                fontsize=8, fontweight="bold", color=NODE_TEXT, ha="center", va="center")
        ax.text(x, y + node_h * 0.10, a.name,
                fontsize=6, color=NODE_TEXT, ha="center", va="center")
        ax.text(x, y - node_h * 0.10, f"ES {a.es}   EF {a.ef}", **mono)
        ax.text(x, y - node_h * 0.25, f"LS {a.ls}   LF {a.lf}", **mono)
        slack_color = "#b41e1e" if a.is_critical else NODE_TEXT
        ax.text(x, y - node_h * 0.40,
                f"Slack {a.slack}" + ("  *" if a.is_critical else ""),
                fontsize=6, color=slack_color, family="monospace", ha="center", va="center")

    ax.autoscale()
    ax.margins(0.15)
    fig.suptitle(
        f"Critical Path Method  |  Project Duration: {project.duration}",
        color="white",
        fontsize=13,
        fontweight="bold",
    )
    plt.tight_layout()
    plt.show()


def _rank(activity, by_id: dict) -> int:
    return max((_rank(by_id[d], by_id) + 1 for d in activity.dependencies), default=0)


def _layout(activities) -> dict[str, tuple[float, float]]:
    by_id = {a.id: a for a in activities}
    ranks = {a.id: _rank(a, by_id) for a in activities}

    per_rank: dict[int, list[str]] = {}
    for aid, r in ranks.items():
        per_rank.setdefault(r, []).append(aid)

    col_spacing, row_spacing = 3.5, 2.2
    positions: dict[str, tuple[float, float]] = {}
    for r, ids in per_rank.items():
        total_height = (len(ids) - 1) * row_spacing
        for i, aid in enumerate(ids):
            positions[aid] = (r * col_spacing, i * row_spacing - total_height / 2)
    return positions
