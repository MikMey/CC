if __name__ == "__main__":
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
