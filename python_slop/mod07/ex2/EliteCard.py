from typing import Dict, Any, List
from ex0.Card import Card
from .Combatable import Combatable
from .Magical import Magical


class EliteCard(Card, Combatable, Magical):
    def __init__(
        self,
        name: str,
        cost: int,
        rarity: str,
        attack: int,
        health: int,
        mana: int
    ) -> None:
        super().__init__(name, cost, rarity)
        self.attack_power = attack
        self.health = health
        self.mana = mana

    def play(self, game_state: Dict[str, Any]) -> Dict[str, Any]:
        return {
            "card_played": self.name,
            "type": "EliteCard",
            "cost": self.cost
        }

    # ------------------
    # Combatable methods
    # ------------------

    def attack(self, target: str) -> Dict[str, Any]:
        return {
            "attacker": self.name,
            "target": target,
            "damage": self.attack_power,
            "combat_type": "melee"
        }

    def defend(self, incoming_damage: int) -> Dict[str, Any]:
        blocked = min(self.attack_power, incoming_damage)
        damage_taken = incoming_damage - blocked
        self.health -= damage_taken

        return {
            "defender": self.name,
            "damage_taken": damage_taken,
            "damage_blocked": blocked,
            "still_alive": self.health > 0
        }

    def get_combat_stats(self) -> Dict[str, Any]:
        return {
            "attack": self.attack_power,
            "health": self.health
        }

    # ----------------
    # Magical methods
    # ----------------

    def cast_spell(self, spell_name: str, targets: List[str]) -> Dict[str,
                                                                      Any]:
        mana_cost = 4
        self.mana -= mana_cost

        return {
            "caster": self.name,
            "spell": spell_name,
            "targets": targets,
            "mana_used": mana_cost
        }

    def channel_mana(self, amount: int) -> Dict[str, Any]:
        self.mana += amount

        return {
            "channeled": amount,
            "total_mana": self.mana
        }

    def get_magic_stats(self) -> Dict[str, Any]:
        return {
            "mana": self.mana
        }
