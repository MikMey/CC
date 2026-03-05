class Plant:
    def __init__(self, name: str, height: int = 0, age: int = 0):
        self.name = name
        self.height = height
        self.age = age


class Flower(Plant):
    def __init__(self, plant: Plant, color: str):
        super().__init__(plant)
        self.color = color
        self.plant = plant
        print(f"{self.plant.name} (Flower): {self.plant.height}cm, "
              f"{self.plant.age} days, {self.color} color")

    def bloom(self):
        print(f"{self.plant.name} is blooming beautifully!")


class Tree(Plant):
    def __init__(self, plant: Plant, trunk_diameter: int):
        super().__init__(plant)
        self.trunk_diameter = trunk_diameter
        self.plant = plant
        print(f"{self.plant.name} (Flower): {self.plant.height}cm, "
              f"{self.plant.age} days, {self.trunk_diameter} cm diameter")

    def produce_shade(self):
        print(f"Oak provides {self.trunk_diameter * self.plant.height * 0.2} "
              "square meters of shade")


class Vegetable(Plant):
    def __init__(self, plant: Plant, harvest_season: str,
                 nutritional_value: str):
        super().__init__(plant)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value
        self.plant = plant
        print(f"{self.plant.name} (Flower): {self.plant.height}cm, "
              f"{self.plant.age} days, {self.harvest_season} harvest")
        print(f"{self.plant.name} is rich in vitamin C")


if __name__ == "__main__":
    holz = Tree(Plant("holz", 10000, 10000), 1000)
    holz.produce_shade()

# do the rest urself im too lazy
