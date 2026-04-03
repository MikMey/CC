

def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    """
    artifact_sorter(artifacts) - Sort magical artifacts:
    • Use sorted() with a lambda to sort by ’power’ level (descending)
    • Each artifact is a dict: {’name’: str, ’power’: int, ’type’: str}
    • Return the sorted list
    """
    return sorted(artifacts, key=lambda x: x['power'], reverse=True)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    """
    • Use filter() with a lambda to find mages with power >= min_power
    • Each mage is a dict: {’name’: str, ’power’: int, ’element’: str}
    • Return a list of filtered mages
    """
    return list(filter(lambda x: x['power'] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    """
    • Use map() with a lambda to add "* " prefix and " *" suffix
    • Input: list of spell names (strings)
    • Return a list of transformed spell names
    """
    return list(map(lambda x: "* " + x + " *", spells))


def mage_stats(mages: list[dict]) -> dict:
    """
    • Most powerful mage’s power level
    • Least powerful mage’s power level
    • Average power level (rounded to 2 decimals)
    • Return dict: {’max_power’: int, ’min_power’: int, ’avg_power’: float}
    """
    res: dict = {}
    res['max_power'] = max(mages, key=lambda x: x['power'])['power']
    res['min_power'] = min(mages, key=lambda x: x['power'])['power']
    temp = [item['power'] for item in mages]
    res['avg_power'] = round(sum(temp) / len(temp), 2)
    return res


def main():
    print(artifact_sorter(
        [
            {
                'name': "name",
                'power': 2,
                'type': ""
            },
            {
                'name': "name",
                'power': 1,
                'type': ""
            },
            {
                'name': "name",
                'power': 3,
                'type': ""
            }
        ]
    ))

    print(power_filter(
        [
            {
                'name': "name",
                'power': 10,
                'element': "test"
            },
            {
                'name': "badname",
                'power': 1,
                'element': "test"
            },
            {
                'name': "othername",
                'power': 2,
                'element': "test"
            }
        ],
        2
    ))

    print(spell_transformer(["asswater", "spelel", "pizzza"]))

    print(mage_stats(
        [
            {
                'name': "name",
                'power': 2,
                'type': ""
            },
            {
                'name': "name",
                'power': 1,
                'type': ""
            },
            {
                'name': "name",
                'power': 3,
                'type': ""
            }
        ]
    ))


if __name__ == "__main__":
    main()
