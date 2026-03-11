from ex0.Card import Card
from ex0.CreatureCard import CreatureCard
from ex1.SpellCard import SpellCard
from ex1.ArtifactCard import ArtifactCard
from ex3.CardFactory import CardFactory


class FantasyCardFactory(CardFactory):

    def get_supported_types(self) -> dict:
        return {
            "creatures": ["dragon", "goblin"],
            "spells": ["fireball"],
            "artifacts": ["mana_ring"]
        }

    def create_creature(self, name_or_power: str | int | None = None) -> Card:
        if name_or_power == "dragon" or name_or_power == 5:
            return CreatureCard("Fire Dragon", 5, "Legendary", 7, 5)
        elif name_or_power == "goblin" or name_or_power == 4:
            return CreatureCard("Goblin Warrior", 2, "Common", 3, 2)
        else:
            return CreatureCard("Default Creature", 1, "Common", 1, 1)

    def create_spell(self, name_or_power: str | int | None = None) -> Card:
        if name_or_power == "lightning bolt" or name_or_power == 3:
            return SpellCard("Lightning Bolt", 3, "Rare", "damage")
        else:
            return SpellCard("Default", 1, "Rare", "damage")

    def create_artifact(self, name_or_power: str | int | None = None) -> Card:
        if name_or_power == "mana_ring":
            return ArtifactCard("Normal Mana Ring", 2,
                                "Common", 5, "+1 mana per turn")
        else:
            return ArtifactCard("Mana Crystal", 1,
                                "Common", 1, "+1 mana per turn")

    def create_themed_deck(self, size: int) -> dict:
        cards = []
        # loop bis size erreicht ist
        # abwechselnd creatures, spells, artifacts hinzufügen
        return {"cards": cards, "size": len(cards)}
