def validate_ingredients(ingredients: str) -> str:
    valid_elements = {"fire", "water", "earth", "air"}

    if ingredients in valid_elements:
        return f"{ingredients} - VALID"
    else:
        return f"{ingredients} - INVALID"
