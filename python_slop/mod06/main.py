import alchemy.grimoire as grimoire
import alchemy.transmutation as transmutation
import alchemy


if __name__ == "__main__":
    print(grimoire.validate_ingredients("fire"))
    print(grimoire.validate_ingredients("shit"))
    print(grimoire.record_spell("Shitbomb", "fire earth"))
