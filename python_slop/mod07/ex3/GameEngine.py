from ex3.CardFactory import CardFactory
from ex3.GameStrategy import GameStrategy


class GameEngine:

    def __init__(self):
        self.factory = None
        self.strategy = None
        self.turns = 0
        self.total_damage = 0

    def configure_engine(self, factory:
                         CardFactory, strategy: GameStrategy) -> None:
        self.factory = factory
        self.strategy = strategy

    def simulate_turn(self) -> dict:
        hand = [
            self.factory.create_creature("dragon"),
            self.factory.create_creature("goblin"),
            self.factory.create_spell("lightning bolt"),
        ]

        result = self.strategy.execute_turn(hand, ["Enemy Player"])

        self.total_damage += result["damage_dealt"]
        self.turns += 1

        return {
            "hand": [f"{card.name} ({card.cost})" for card in hand],
            "actions": result
        }

    def get_engine_status(self) -> dict:
        return {
            "turns_simulated": self.turns,
            "strategy_used": self.strategy.get_strategy_name(),
            "cards_created": self.turns * 3,
            "total_damage": self.total_damage
        }
