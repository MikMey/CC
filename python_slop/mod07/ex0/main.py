from .CreatureCard import CreatureCard


def main():
    print("=== DataDeck Card Foundation ===")
    print("Testing Abstract Base Class Design:")
    print()

    # Create a creature card
    dragon = CreatureCard("Fire Dragon", 5, "Legendary", 7, 5)

    # Display card info
    print("CreatureCard Info:")
    print(dragon.get_card_info())
    print()

    # Test with sufficient mana
    print(f"Playing {dragon.name} with 6 mana available:")
    print(f"Playable: {dragon.is_playable(6)}")
    print(f"Play result: {dragon.play({})}")
    print()

    # Show attack
    print(f"{dragon.name} attacks Goblin Warrior:")
    print(f"Attack result: {dragon.attack_target('Goblin Warrior')}")
    print()

    # Test with insufficient mana
    print("Testing insufficient mana (3 available):")
    print(f"Playable: {dragon.is_playable(3)}")
    print()

    print("Abstract pattern successfully demonstrated!")


if __name__ == "__main__":
    main()
