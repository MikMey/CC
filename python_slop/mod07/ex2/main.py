from .EliteCard import EliteCard


def main() -> None:
    print("=== DataDeck Ability System ===\n")

    print("EliteCard capabilities:")
    print("- Card: ['play', 'get_card_info', 'is_playable']")
    print("- Combatable: ['attack', 'defend', 'get_combat_stats']")
    print("- Magical: ['cast_spell', 'channel_mana', 'get_magic_stats']\n")

    arcane_warrior = EliteCard(
        name="Arcane Warrior",
        cost=5,
        rarity="Legendary",
        attack=5,
        health=10,
        mana=4
    )

    print("Playing Arcane Warrior (Elite Card):\n")

    print("Combat phase:")
    attack_result = arcane_warrior.attack("Enemy")
    print("Attack result:", attack_result)

    defense_result = arcane_warrior.defend(5)
    print("Defense result:", defense_result)

    print("\nMagic phase:")
    spell_result = arcane_warrior.cast_spell(
        "Fireball",
        ["Enemy1", "Enemy2"]
    )
    print("Spell cast:", spell_result)

    mana_result = arcane_warrior.channel_mana(3)
    print("Mana channel:", mana_result)

    print("\nMultiple interface implementation successful!")


if __name__ == "__main__":
    main()
