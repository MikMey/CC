from ex0.Card import Card
from ex2.Combatable import Combatable
from ex4.Rankable import Rankable


class TournamentCard(Card, Combatable, Rankable):
    def __init__(self, name: str, cost: int, rarity: str, attack: int):
        super().__init__(name, cost, rarity)
        self.attack_power = attack
        self.wins = 0
        self.losses = 0
        self.rating = 1200

    def play(self, game_status: dict) -> dict:
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": "Tournament card ready for battle"
        }

    def attack(self, target) -> dict:
        return {
            "attacker": self.name,
            "target": target,
            "damage": self.attack_power,
            "combat_type": "melee"
        }

    def defend(self, incoming_damage: int) -> dict:
        return {
            "defender": self.name,
            "damage_taken": incoming_damage,
            "damage_blocked": self.attack_power - incoming_damage,
            "still_alive": True
        }

    def get_combat_stats(self) -> dict:
        return {
            "name": self.name,
            "attack_power": self.attack_power,
            "combat_type": "melee"
        }

    def calculate_rating(self) -> int:
        return self.rating

    def update_wins(self, wins: int) -> None:
        self.wins += wins

    def update_losses(self, losses: int) -> None:
        self.losses += losses

    def get_rank_info(self) -> dict:
        return {
            "rating": self.calculate_rating(),
            "wins": self.wins,
            "losses": self.losses,
            "record": f"{self.wins} - {self.losses}"
        }

    def get_tournament_stats(self) -> dict:
        return {
            "name": self.name,
            "rating": self.calculate_rating(),
            "record": f"{self.wins} - {self.losses}",
            "attack_power": self.attack_power
        }
