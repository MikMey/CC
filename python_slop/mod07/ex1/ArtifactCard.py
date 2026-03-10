import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(__file__)))
from ex0.Card import Card


class ArtifactCard(Card):

    def __init__(self, name: str, cost: int, rarity: str, durability: int,
                 effect: str) -> None:
        if durability <= 0 or effect is None:
            raise ValueError("Attack and health must be positive integers")
        super().__init__(name, cost, rarity)
        self.durability = durability
        self.effect = effect

    def play(self, game_state: dict) -> dict:
        info = super().play(game_state)
        info['effect'] = self.effect

    def activate_ability(self) -> dict:
        pass
