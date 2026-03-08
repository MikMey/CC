def record_spell(spell_name: str, ingredients: str) -> str:
    from .validator import validate_ingredients

    ingredients = ingredients.split(' ')
    for i in ingredients:
        validation_result = validate_ingredients(i)
        if "INVALID" in validation_result:
            return f"Spell rejected: {spell_name} ({validation_result})"

    return f"Spell recorded: {spell_name} ({validation_result})"
