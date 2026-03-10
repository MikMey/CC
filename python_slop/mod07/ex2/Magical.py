"""
Magical interface.

Defines magical abilities for cards.
"""

from abc import ABC, abstractmethod
from typing import Dict, Any, List


class Magical(ABC):
    """Abstract interface for magic-capable cards."""

    @abstractmethod
    def cast_spell(self, spell_name: str, targets: List[str]) -> Dict[str, Any]:
        """Cast a spell on targets."""
        pass

    @abstractmethod
    def channel_mana(self, amount: int) -> Dict[str, Any]:
        """Channel additional mana."""
        pass

    @abstractmethod
    def get_magic_stats(self) -> Dict[str, Any]:
        """Return magic-related statistics."""
        pass