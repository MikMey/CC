from ex3.GameEngine import GameEngine
from ex3.AggressiveStrategy import AggressiveStrategy
from ex3.FantasyCardFactory import FantasyCardFactory


def main():
    print("=== DataDeck Game Engine ===")

    factory = FantasyCardFactory()
    strategy = AggressiveStrategy()
    engine = GameEngine()

    print("Configuring Fantasy Card Game...")
    print("Factory:", factory.__class__.__name__)
    print("Strategy:", strategy.__class__.__name__)
    print("Available types:", factory.get_supported_types())

    engine.configure_engine(factory, strategy)

    print("\nSimulating aggressive turn...")
    result = engine.simulate_turn()
    print("Hand:", result["hand"])
    print("\nTurn execution:")
    print("Strategy:", strategy.get_strategy_name())
    print("Actions:", result["actions"])

    print("\nGame Report:")
    print(engine.get_engine_status())
    print(
        "\nAbstract Factory + Strategy Pattern: Maximum flexibility achieved!"
        )


if __name__ == "__main__":
    main()
