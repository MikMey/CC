class GardenError(Exception):
    def __init__(self, *args):
        super().__init__(*args)


class PlantError(GardenError):
    def __init__(self, *args):
        super().__init__(*args)


class WaterError(PlantError):
    def __init__(self, *args):
        super().__init__(*args)


class GardenManager:
    __garden: list[dict] = []

    @classmethod
    def water_plants(cls):
        mng = cls()
        for i in mng.__garden:
            try:
                i['water_level'] += 2
                mng.check_plant_health(i)
                print(f"watered {i['plant']}")
            except WaterError as e:
                print(f"Error: {e}")
            finally:
                print(f"finished {i['plant']}\n")

    @classmethod
    def add_plants(cls, plants: list[dict]):
        mng = cls()
        for i in plants:
            try:
                if 'plant' in i and 'water_level' in i:
                    mng.check_plant_health(i)
                    mng.__garden.append(i)
                else:
                    raise GardenError(f"Invalid plant {i}")
            except (GardenError, PlantError, WaterError) as e:
                print(f"Error: {e}")
            finally:
                print("finished adding plant\n")

    @staticmethod
    def check_plant_health(plants: dict) -> None:
        if not plants['plant']:
            raise PlantError("Plant name cannot be None")
        elif plants['water_level'] < 1:
            raise WaterError("Plant water level is too low")
        elif plants['water_level'] > 10:
            raise WaterError("Plant water level is too high")
        else:
            print(f"Plant {plants['plant']} isok")


def test_garden_management() -> None:
    garden: GardenManager = GardenManager
    garden.add_plants([
        {'plant': "tomator", 'water_level': 9},
        {'plant': "lettt us", 'water_level': 50},
        {'plant': None, 'water_level': 4},
        {'plant': "ok", 'test': 5},
    ])
    garden.water_plants()


if __name__ == "__main__":
    test_garden_management()
