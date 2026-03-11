from ex4.TournamentCard import TournamentCard


class TournamentPlatform():
    def __init__(self):
        self.cards = {}
        self.matches = []

    def register_card(self, card: TournamentCard) -> str:
        card_id = f"{card.name.lower().replace(' ', '_')}_001"
        self.cards[card_id] = card
        return card_id

    def create_match(self, card1_id: str, card2_id: str) -> dict:
        card1 = self.cards[card1_id]
        card2 = self.cards[card2_id]

        if card1.attack_power > card2.attack_power:
            winner = card1
            winner_id = card1_id
            loser = card2
            loser_id = card2_id
        else:
            winner = card2
            winner_id = card2_id
            loser = card1
            loser_id = card1_id
        winner.rating += 16
        loser.rating -= 16
        winner.update_wins(1)
        loser.update_losses(1)
        match_result = {
            "winner": winner_id,
            "loser": loser_id,
            "winner_rating": winner.rating,
            "loser_rating": loser.rating
        }
        self.matches.append(match_result)
        return match_result

    def get_leaderboard(self) -> list:
        sorted_cards = sorted(self.cards.items(),
                              key=lambda x: x[1].rating,
                              reverse=True)
        return [
            {
                "rank": i + 1,
                "name": card.name,
                "rating": card.rating,
                "record": f"{card.wins}-{card.losses}"
            }
            for i, (card_id, card) in enumerate(sorted_cards)
        ]

    def generate_tournament_report(self) -> dict:
        return {
            "total_cards": len(self.cards),
            "matches_played": len(self.matches),
            "avg_rating": sum(card.rating for card in self.cards.values()) //
            len(self.cards),
            "platform_status": "active"
        }
