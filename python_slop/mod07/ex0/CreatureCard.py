from .Card import Card
from typing import Any


class CreatureCard(Card):

    def __init__(self, name: str, cost: int, rarity: str, attack: int,
                 health: int) -> None:
        if attack <= 0 or health <= 0:
            raise ValueError("Attack and health must be positive integers")
        super().__init__(name, cost, rarity)
        self.attack = attack
        self.health = health

    def play(self, game_state: dict) -> dict:
        info = super().play(game_state)
        info['effect'] = 'Creature summoned to battlefield'
        return info

    def attack_target(self, target: Any) -> dict:
        return {
            'attacker': self.name,
            'target': target,
            'damage_dealt': self.attack,
            'combat_resolved': True
        }

    def get_card_info(self) -> dict:
        info = super().get_card_info()
        info['type'] = 'Creature'
        info['attack'] = self.attack
        info['health'] = self.health
        return info
