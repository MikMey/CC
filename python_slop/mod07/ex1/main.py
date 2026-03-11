# import sys
# import os
# sys.path.append(os.path.dirname(os.path.dirname(__file__)))
from ex0.CreatureCard import CreatureCard as Creature
from ex1.Deck import Deck
from ex1.SpellCard import SpellCard as Spell
from ex1.ArtifactCard import ArtifactCard as Artifact


def main():
    deck: Deck = Deck()
    deck.add_card(Creature('Dragon', 5, 'Legendary', 100, 200))
    deck.add_card(Spell('Magic', 1, 'Common', 'Shit your pants'))
    deck.add_card(Artifact('RAndom', 1, 'yes', 1, 'Garbage'))
    print(f"{deck.get_deck_stats()}\n")
    deck.shuffle()
    curr = deck.draw_card()
    curr.play(None)


if __name__ == "__main__":
    main()
