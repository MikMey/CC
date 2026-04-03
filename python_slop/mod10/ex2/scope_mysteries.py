from typing import Callable, Any


def mage_counter() -> Callable:
    """
    mage_counter() - Create a counting closure:
    • Return a function that counts how many times it’s been called
    • Each call should return the current count (starting from 1)
    • The counter should persist between calls
    • Creating two separate counters must yield independent state.
    • Use closure to maintain state without global variables
    """
    x: int = 0

    def inner() -> int:
        nonlocal x
        x += 1
        return x
    return inner


def spell_accumulator(initial_power: int) -> Callable:
    """
    spell_accumulator(initial_power) - Create power accumulator:
    • Return a function that accumulates power over time
    • Each call adds the given amount to the total power
    • Return the new total power after each addition
    • Start with initial_power as the base
    """
    x = initial_power

    def inner(add: int) -> int:
        nonlocal x
        x += add
        return x
    return inner


def enchantment_factory(enchantment_type: str) -> Callable:
    """
    enchantment_factory(enchantment_type) - Create enchantment functions:
    • Return a function that applies the specified enchantment
    • The returned function takes an item name and returns enchanted
    description
    • Format: "enchantment_type item_name" (e.g., "Flaming Sword")
    • Each factory creates functions with different enchantment types
    """
    def create(item_name: str) -> str:
        # nonlocal enchantment_type
        return f"{enchantment_type}{item_name}"
    return create


def memory_vault() -> dict[str, Callable]:
    """
    memory_vault() - Create a memory management system:
    • Return a dict with ’store’ and ’recall’ functions
    • ’store’ function: takes (key, value) and stores the memory
    • ’recall’ function: takes (key) and returns stored value or
    "Memory not found"
    • Use closure to maintain private memory storage
    """
    vault: dict = {}

    def store(key: Any, value: Any) -> None:
        # nonlocal vault
        vault[key] = value

    def recall(key: Any) -> Any:
        # nonlocal vault
        if key in vault:
            return vault[key]
        else:
            return "Memory not found"

    return {'store': store, 'recall': recall}


def main():
    counter1 = mage_counter()
    for _ in range(5):
        print(counter1())
    counter2 = mage_counter()
    print(counter2())
    print(counter1())

    mem = memory_vault()
    mem['store']("horse", "shoe")
    print(mem['recall']("horse"))


if __name__ == "__main__":
    main()
