class GardenError(Exception):
    def __init__(self, *args):
        super().__init__(*args)


class PlantError(GardenError):
    def __init__(self, *args):
        super().__init__(*args)


class WaterError(PlantError):
    def __init__(self, *args):
        super().__init__(*args)


def raise_errors() -> None:
    garden = ""
    try:
        if garden == "":
            raise GardenError("garden is empty")
        garden.name
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        if garden == "":
            raise PlantError("no plants in garden")
        garden.name["plant"]
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    try:
        if garden == "":
            raise WaterError("no water available")
        garden.name["plant"].water
    except WaterError as e:
        print(f"Caught WaterError: {e}")


if __name__ == "__main__":
    raise_errors()
