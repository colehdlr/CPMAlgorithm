"""CLI entry point: python main.py [activities.json]"""

import argparse
import sys

from cpm import Project


def main() -> int:
    parser = argparse.ArgumentParser(description="Critical Path Method analyser")
    parser.add_argument(
        "path",
        nargs="?",
        default="../data/activities.json",
        help="JSON file with activities (default: ../data/activities.json)",
    )
    parser.add_argument(
        "--no-render",
        action="store_true",
        help="print table only, skip the visualisation window",
    )
    args = parser.parse_args()

    try:
        project = Project.from_json(args.path)
    except (FileNotFoundError, ValueError, KeyError) as e:
        print(f"error: {e}", file=sys.stderr)
        return 1

    print(project.format_table())

    if not args.no_render:
        from render import render

        render(project)

    return 0


if __name__ == "__main__":
    sys.exit(main())
