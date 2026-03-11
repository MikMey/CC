# import sys
# import os
# sys.path.append(os.path.dirname(os.path.dirname(__file__)))
from ex0 import Card, Creature
from ex1.ArtifactCard import ArtifactCard as Artifact
from ex1.SpellCard import SpellCard as Spell
import random
from typing import Any


class DuplicateError(Exception):

    def __init__(self, *args):
        super().__init__(*args)


class Deck:
    __deck: list[Card] = []

    def add_card(self, card: Card) -> None:
        if card in self.__deck:
            raise DuplicateError("Card already exists")
        self.__deck.append(card)

    def remove_card(self, card_name: str) -> bool:
        for i in self.__deck:
            if card_name is i.name:
                self.__deck.pop(i)
                return True
        return False

    def shuffle(self) -> None:
        random.shuffle(self.__deck)

    def draw_card(self) -> Card:
        return self.__deck[0]

    def get_deck_stats(self) -> dict:
        stats: dict[str, Any] = {}
        stats['Cards'] = []
        stats['Creature'] = 0
        stats['Artifatc'] = 0
        stats['Spell'] = 0
        for count, i in enumerate(self.__deck):
            stats['Cards'].append(i)
            if isinstance(i, Creature):
                stats['Creature'] += 1
            elif isinstance(i, Artifact):
                stats['Artifatc'] += 1
            elif isinstance(i, Spell):
                stats['Spell'] += 1
        stats['Size'] = count
        return stats
