import alchemy.grimoire as grimoire
import alchemy.transmutation as transmutation
import alchemy


if __name__ == "__main__":
    print(grimoire.validate_ingredients("fire"))
    print(grimoire.validate_ingredients("shit"))
    print(grimoire.record_spell("Shitbomb", "fire earth") + "\n")

    print(transmutation.lead_to_gold())
    print(transmutation.philosophers_stone())
    print(transmutation.stone_to_gem())
    print(transmutation.elixir_of_life() + "\n")

    print(alchemy.create_water())
    print(alchemy.create_fire())
