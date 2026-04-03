from typing import Callable


def spell(target: str, power: int) -> str:
    return (f"{target} at {power}")


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    """
    spell_combiner(spell1, spell2) - Combine two spells:
    • Return a new function that calls both spells with the same arguments
    • The combined spell should return a tuple of both results
    • Example: combined = spell_combiner(fireball, heal)
    """
    def call_both(target: str, power: int) -> tuple:
        return (spell1(target, power), spell2(target, power))
    return call_both


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    """
    power_amplifier(base_spell, multiplier) - Amplify spell power:
    • Returns a function with the same signature as the original spell
    • Returns a new spell where the power is multiplied before casting.
    • Example: mega_fireball = power_amplifier(fireball, 3)
    """
    def mult_power(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)
    return mult_power


def conditional_caster(condition: Callable, spell: Callable) -> Callable:

    """
    conditional_caster(condition, spell) - Cast spell conditionally:
    • Returns a new spell that only casts if a condition is True.
    • If condition fails, return "Spell fizzled"
    • Both condition and spell receive the same arguments
    """
    def cond_cast(target: str, power: int) -> str:
        if condition:
            return (spell(target, power))
        else:
            return "Spell fizzled"
    return cond_cast


def spell_sequence(spells: list[Callable]) -> Callable:
    """
    spell_sequence(spells) - Create spell sequence:
    • Return a function that casts all spells in order
    • Each spell receives the same arguments
    • Returns a list of all spell results
    """
    def cast_all(target: str, power: int) -> list[str]:
        return [single(target, power) for single in spells]
    return cast_all


def main():
    new_spell = spell_combiner(spell, spell)
    print(new_spell("target", "power"))

    print(power_amplifier(spell, 10)("your", 3))

    print(conditional_caster(lambda: True, spell)("tar", 1))

    print(spell_sequence([spell, spell, spell])("traaa", 2))


if __name__ == "__main__":
    main()
