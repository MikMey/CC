def check_plant_health(plant_name: str, water_level: int,
                       sunlight_hours: int) -> None:
    if not plant_name:
        raise ValueError("Plant name cannot be None")
    elif water_level < 1:
        raise ValueError("Plant water level is too low")
    elif water_level > 10:
        raise ValueError("Plant water level is too high")
    elif sunlight_hours < 2:
        raise ValueError("Plant sunlight level is too low")
    elif sunlight_hours > 12:
        raise ValueError("Plant sunlight level is too high")
    else:
        print(f"Plant {plant_name} isok")


def test_plant_checks() -> None:
    try:
        check_plant_health("tomato", 5, 5)
    except ValueError as e:
        print(f"Error: {e}")
    try:
        check_plant_health(None, 5, 5)
    except ValueError as e:
        print(f"Error: {e}")
    try:
        check_plant_health("tomato", 0, 5)
    except ValueError as e:
        print(f"Error: {e}")
    try:
        check_plant_health("tomato", 5, 50)
    except ValueError as e:
        print(f"Error: {e}")
    finally:
        print("all doen")


if __name__ == "__main__":
    test_plant_checks()
