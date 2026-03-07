import sys
from sys import argv
from math import sqrt

if __name__ == "__main__":
    scores: list = []
    if not sys.argv[1:]:
        print("No ARGS")
    else:
        for i in sys.argv[1:]:
            try:
                i = int(i)
                scores.append(i)
            except ValueError:
                print("Bro...")
        try:
            print(f"High score: {max(scores)}")
            print(f"Low score: {min(scores)}")
            if len(scores) >= 2:
                print(f"Total: {sum(scores)}")
            print(f"Amount: {len(scores)}")
        except ValueError:
            print("Bro...")

    coords_raw: list = []
    if not argv[1:]:
        print("No ARGS")
    else:
        for item in argv[1:]:
            try:
                item = int(item)
                coords_raw.append(int(item))
            except ValueError:
                print("not int")
        try:
            if len(coords_raw) < 3:
                raise ValueError(" not 3 args")
            coords: tuple = tuple(coords_raw)
            print(f"pos: {coords}")
            distance = sqrt(coords[0]**2 + coords[1]**2 + coords[2]**2)
            print(f"Distance (0,0,0) to {coords} is : {distance}")
        except ValueError as e:
            print(f"Skill issue {e}")

    alice: set = {'first_kill', 'level_10', 'treasure_hunter', 'speed_demon'}
    bob: set = {'first_kill', 'level_10', 'boss_slayer', 'collector'}
    charlie: set = {'level_10', 'treasure_hunter', 'boss_slayer',
                    'speed_demon', 'perfectionist'}
    all_ach: set = alice.union(bob, charlie)
    print(f"All unique achievements: {all_ach}")
    print(f"Total unique achievements: {len(all_ach)}\n")

    players: dict[str, set] = {'alice': alice, 'bob': bob, 'charlie': charlie}

    for key, value in players.items():
        print(f"player {key} achievements: {value}")

    print(f"\ncommon for all: {alice.intersection(bob, charlie)}")
    # print(f"none have: {all_ach - alice - bob - charlie}\n")

    print(f"only bob achievements: {bob - alice - charlie}")

    inv: dict = {
        'potion': 5,
        'armor': 3,
        'shield': 2,
        'sword': 1,
        'helmet': 1
        }
    total_items = sum(inv.values())
    unique_types = len(inv)

    print("\n === Inventory System Analysis === \n\n"
          f"Total items in inventory: {total_items}\n"
          f"Unique item types: {unique_types}\n\n")

    most_abundant = max(inv, key=inv.get)
    least_abundant = min(inv, key=inv.get)

    print(f"Most abundant: {most_abundant} ({inv[most_abundant]} units)\n"
          f"Least abundant: {least_abundant} ({inv[least_abundant]} unit(s))"
          "\n\n")

    abundance_categories: dict = {
        'abundant': {},
        'moderate': {},
        'rare': {}
    }

    for item, quantity in inv.items():
        percentage = (quantity / total_items) * 100
        if percentage >= 25:
            abundance_categories['abundant'][item] = quantity
        elif percentage >= 10:
            abundance_categories['moderate'][item] = quantity
        else:
            abundance_categories['rare'][item] = quantity

    print(" === Items by Abundance === \n")
    for category, items in abundance_categories.items():
        print(f"{category.upper()}:")
        for item, qty in items.items():
            print(f"  {item}: {qty} units")
        print()

    print(" === Current inventory === \n")
    for key, item in inv.items():
        print(f"{key}: {item} units ({round(item / total_items * 100, 2)}%)")

    print("\n === Inventory Report === \n")
    print(f"Storage efficiency: {round(total_items / unique_types, 2)} items "
          "per type (avg)")
    print(f"Inventory value: {total_items} total units across {unique_types} "
          "categories")
