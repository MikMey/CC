class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def get_info(self) -> str:
        return (f"{self.height}cm, {self.age} days old")


class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, age: int, color: str):
        super().__init__(name, height, age)
        self.__color = color

    def get_info(self):
        return (super().get_info() + f", color: {self.__color}")


class PrizeFlower(FloweringPlant):
    def __init__(self, name: str, height: int, age: int, color: str,
                 prize: str):
        super().__init__(name, height, age, color)
        self.__prize = prize

    def get_info(self):
        return (super().get_info() + f", prize: {self.__prize}")


class Garden:
    def __init__(self, owner: str, plants: list):
        self.__garden = {}
        self.__garden[owner] = []
        for i in plants:
            self.__garden[owner] += [i]

    def get_info(self) -> dict:
        return self.__garden


class GardenManager:
    _gardens: dict = {}
    _count: int = 0
    _growth: int = 0
    _amount: int = 0

    def __init__(self) -> None:
        pass

    class GardenStats:
        @classmethod
        def get_info(cls, name: str):
            print(f"\n === {name}'s Garden Report === \n")
            if name in GardenManager._gardens:
                for i, j in GardenManager._gardens[name].items():
                    print(f"- ({j.__class__.__name__}) {i}: {j.get_info()}")
            else:
                print(f"Garden {name} doesnt exist")

        @classmethod
        def get_stats(cls):
            print(f"\nPlants total: {GardenManager._count}, "
                  f"total growth: {GardenManager._growth}\n")

        @classmethod
        def get_total_gardens(cls):
            print(f"Total gardens: {GardenManager._amount}")

    @staticmethod
    def __print_plant_added(name: str, plant: str):
        print(f"Added {plant} to {name}'s garden")

    def __garden_add(self, name: str):
        if name not in self._gardens:
            GardenManager._amount += 1
            self._gardens[name] = {}

    def __plant_add(self, name: str, plant: Plant):
        self._gardens[name][plant.name] = plant
        GardenManager._count += 1
        self.__print_plant_added(name, plant.name)

    @classmethod
    def create_garden_network(cls, info: list):
        manager = cls()
        for garden in info:
            for key, cont in garden.get_info().items():
                manager.__garden_add(key)
                for i in cont:
                    manager.__plant_add(key, i)
        return manager

    def grow_garden(self, name: str):
        print(f"\n === {name} is helping all plants grow === \n")
        for plant in GardenManager._gardens[name].values():
            plant.height += 1
            print(f"{plant.name} grew 1cm")
            GardenManager._growth += 1


if __name__ == "__main__":
    print("\n\n=== Garden Management System Demo ===\n\n")
    netw = GardenManager.create_garden_network([
        Garden("mika", [
            FloweringPlant("rose", 1, 1, "red"),
            PrizeFlower("holz", 1, 1, "shit", "$yes")
            ]),
        Garden("other", [
            Plant("tulip", 1, 1),
            Plant("water", 1, 1)
            ])
        ])
    netw.GardenStats.get_info("mika")
    netw.GardenStats.get_info("other")
    netw.grow_garden("mika")
    netw.GardenStats.get_stats()
    netw.GardenStats.get_total_gardens()
