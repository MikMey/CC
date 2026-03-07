def water_plants(plant_list: list[str]) -> None:
    print("Opening watering system\n")
    try:
        for i in plant_list:
            if not i:
                raise ValueError
            print(f"watering {i}")
    except ValueError:
        print(f"cant water {i}")
    finally:
        print("closing\n")


def test_watering_system():
    water_plants(["holz", "tree", "else"])
    water_plants(["tomato", None, 0])


if __name__ == "__main__":
    test_watering_system()
