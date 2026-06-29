"""Tests for the CPM module - exercised through the Project interface."""

import pytest

from cpm import Activity, Project


class TestTextbookNetwork:
    """Same network as data/activities.json."""

    @pytest.fixture()
    def project(self):
        return Project([
            Activity("A", "Requirements",         3),
            Activity("B", "Design",               4, ["A"]),
            Activity("C", "Database Setup",       5, ["A"]),
            Activity("D", "Frontend Development", 6, ["B"]),
            Activity("E", "Backend Development",  7, ["C"]),
            Activity("F", "Integration",          3, ["D", "E"]),
            Activity("G", "Testing",              4, ["F"]),
        ])

    def test_project_duration(self, project):
        assert project.duration == 22

    def test_critical_path(self, project):
        assert [a.id for a in project.critical_path] == ["A", "C", "E", "F", "G"]

    def test_schedule_values(self, project):
        expected = {
            "A": (0,  3,  0,  3, 0, True),
            "B": (3,  7,  5,  9, 2, False),
            "C": (3,  8,  3,  8, 0, True),
            "D": (7, 13,  9, 15, 2, False),
            "E": (8, 15,  8, 15, 0, True),
            "F": (15, 18, 15, 18, 0, True),
            "G": (18, 22, 18, 22, 0, True),
        }
        by_id = {a.id: a for a in project.activities}
        for aid, (es, ef, ls, lf, slack, crit) in expected.items():
            a = by_id[aid]
            assert (a.es, a.ef, a.ls, a.lf, a.slack, a.is_critical) == \
                   (es, ef, ls, lf, slack, crit), f"mismatch on {aid}"


class TestSingleActivity:

    def test_single(self):
        project = Project([Activity("X", "Only", 5)])
        assert project.duration == 5
        a = project.activities[0]
        assert (a.es, a.ef, a.ls, a.lf, a.slack, a.is_critical) == (0, 5, 0, 5, 0, True)


class TestParallelPaths:

    def test_longer_path_is_critical(self):
        project = Project([
            Activity("S", "Start", 2),
            Activity("A", "A",     5, ["S"]),
            Activity("B", "B",     3, ["S"]),
            Activity("T", "End",   1, ["A", "B"]),
        ])
        assert project.duration == 8
        by_id = {a.id: a for a in project.activities}
        assert by_id["A"].is_critical
        assert not by_id["B"].is_critical
        assert by_id["B"].slack == 2


class TestValidation:

    def test_cycle_rejected(self):
        with pytest.raises(ValueError, match="cycle"):
            Project([
                Activity("A", "A", 1, ["B"]),
                Activity("B", "B", 1, ["A"]),
            ])

    def test_duplicate_ids_rejected(self):
        with pytest.raises(ValueError, match="duplicate"):
            Project([
                Activity("X", "first", 1),
                Activity("X", "again", 1),
            ])

    def test_unknown_dependency_rejected(self):
        with pytest.raises(ValueError, match="unknown"):
            Project([Activity("A", "A", 1, ["Z"])])

    def test_self_dependency_rejected(self):
        with pytest.raises(ValueError, match="depends on itself"):
            Project([Activity("A", "A", 1, ["A"])])

    def test_negative_duration_rejected(self):
        with pytest.raises(ValueError, match="negative"):
            Project([Activity("A", "A", -1)])


class TestFromJson:

    def test_loads_activities_json(self, tmp_path):
        data = {
            "activities": [
                {"id": "A", "name": "Start", "duration": 3, "dependencies": []},
                {"id": "B", "name": "End",   "duration": 2, "dependencies": ["A"]},
            ]
        }
        path = tmp_path / "test.json"
        path.write_text(__import__("json").dumps(data))
        project = Project.from_json(path)
        assert project.duration == 5
        assert len(project.activities) == 2
