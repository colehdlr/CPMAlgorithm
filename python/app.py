"""Streamlit CPM app - interactive critical path analysis."""

import json
import streamlit as st
import matplotlib.pyplot as plt
import matplotlib.patches as patches
from cpm import Activity, Project

st.set_page_config(page_title="CPM Analyzer", layout="wide")


def draw_network(project):
    activities = project.activities
    by_id = {a.id: a for a in activities}

    ranks = {}
    for a in activities:
        ranks[a.id] = max((ranks[d] + 1 for d in a.dependencies), default=0)
    per_rank = {}
    for id, r in ranks.items():
        per_rank.setdefault(r, []).append(id)

    col_sp, row_sp = 3.5, 2.2
    positions = {}
    for r, ids in per_rank.items():
        h = (len(ids) - 1) * row_sp
        for i, id in enumerate(ids):
            positions[id] = (r * col_sp, i * row_sp - h / 2)

    max_x = max(x for x, _ in positions.values())
    fig, ax = plt.subplots(figsize=(max(8, max_x + 4), 5))
    ax.set_aspect("equal")
    ax.axis("off")
    fig.patch.set_facecolor("#12161e")
    ax.set_facecolor("#12161e")

    node_w, node_h = 2.4, 1.6

    for a in activities:
        x2, y2 = positions[a.id]
        for dep in a.dependencies:
            x1, y1 = positions[dep]
            pred = by_id[dep]
            critical = pred.is_critical and a.is_critical and pred.ef == a.es
            ax.annotate(
                "", xy=(x2 - node_w / 2, y2), xytext=(x1 + node_w / 2, y1),
                arrowprops=dict(
                    arrowstyle="->",
                    color="#c82828" if critical else "#5a5a5a",
                    lw=2.0 if critical else 1.2,
                ),
            )

    for a in activities:
        x, y = positions[a.id]
        fill = "#ffe0e0" if a.is_critical else "#f5f7fa"
        edge = "#c82828" if a.is_critical else "#3c4858"

        rect = patches.FancyBboxPatch(
            (x - node_w / 2, y - node_h / 2), node_w, node_h,
            boxstyle="round,pad=0.1",
            facecolor=fill, edgecolor=edge,
            linewidth=2.0 if a.is_critical else 1.0,
        )
        ax.add_patch(rect)

        mono = dict(fontsize=6, color="#141820", family="monospace", ha="center", va="center")
        ax.text(x, y + node_h * 0.30, f"{a.id}  ({a.duration}d)",
                fontsize=8, fontweight="bold", color="#141820", ha="center", va="center")
        ax.text(x, y + node_h * 0.10, a.name, fontsize=6, color="#141820", ha="center", va="center")
        ax.text(x, y - node_h * 0.10, f"ES {a.es}   EF {a.ef}", **mono)
        ax.text(x, y - node_h * 0.25, f"LS {a.ls}   LF {a.lf}", **mono)
        ax.text(x, y - node_h * 0.40, f"Slack {a.slack}" + ("  *" if a.is_critical else ""),
                fontsize=6, color="#b41e1e" if a.is_critical else "#141820",
                family="monospace", ha="center", va="center")

    ax.autoscale()
    ax.margins(0.12)
    fig.suptitle(f"Critical Path  |  Duration: {project.duration} days",
                 color="white", fontsize=12, fontweight="bold")
    plt.tight_layout()
    return fig


# --- App layout ---

st.title("Critical Path Method Analyzer")

st.sidebar.header("Project Activities")

default_data = [
    {"id": "A", "name": "Requirements",         "duration": 3, "dependencies": []},
    {"id": "B", "name": "Design",               "duration": 4, "dependencies": ["A"]},
    {"id": "C", "name": "Database Setup",       "duration": 5, "dependencies": ["A"]},
    {"id": "D", "name": "Frontend Development", "duration": 6, "dependencies": ["B"]},
    {"id": "E", "name": "Backend Development",  "duration": 7, "dependencies": ["C"]},
    {"id": "F", "name": "Integration",          "duration": 3, "dependencies": ["D", "E"]},
    {"id": "G", "name": "Testing",              "duration": 4, "dependencies": ["F"]},
]

uploaded = st.sidebar.file_uploader("Upload activities JSON", type=["json"])
if uploaded:
    data = json.load(uploaded)["activities"]
else:
    data = default_data

st.sidebar.markdown("---")
st.sidebar.subheader("Edit Activities")

edited = []
for i, item in enumerate(data):
    with st.sidebar.expander(f"{item['id']} - {item['name']}"):
        name = st.text_input("Name", item["name"], key=f"name_{i}")
        duration = st.number_input("Duration (days)", value=item["duration"], min_value=0, key=f"dur_{i}")
        deps = st.text_input("Dependencies (comma-separated)", ",".join(item["dependencies"]), key=f"deps_{i}")
        dep_list = [d.strip() for d in deps.split(",") if d.strip()]
        edited.append({"id": item["id"], "name": name, "duration": duration, "dependencies": dep_list})

# Compute and display
try:
    project = Project([
        Activity(a["id"], a["name"], a["duration"], a["dependencies"])
        for a in edited
    ])

    col1, col2 = st.columns([1, 2])

    with col1:
        st.subheader("Schedule")
        table_data = []
        for a in project.activities:
            table_data.append({
                "ID": a.id,
                "Name": a.name,
                "Duration": a.duration,
                "ES": a.es,
                "EF": a.ef,
                "LS": a.ls,
                "LF": a.lf,
                "Slack": a.slack,
                "Critical": "Yes" if a.is_critical else "",
            })
        st.dataframe(table_data, use_container_width=True, hide_index=True)
        st.metric("Project Duration", f"{project.duration} days")
        st.write("**Critical Path:**", " → ".join(a.id for a in project.critical_path))

    with col2:
        st.subheader("Network Diagram")
        fig = draw_network(project)
        st.pyplot(fig)
        plt.close(fig)

except ValueError as e:
    st.error(f"Invalid project: {e}")
