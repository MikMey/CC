class Plant:
    def __init__(self, name: str, height: int, age: int,
                 days: int = 0) -> None:
        self.name = name
        self.height = height
        self.age = age
        self.days = days

    def get_info(self) -> None:
        self.grow()
        self.aged()
        print(f"=== Day {self.days} ===")
        print(f"{self.name}: {self.height}cm, {self.age} days old")
        if self.days % 7 == 0 and self.days > 1:
            print(f"Growth this week: +{self.days - 1}cm")

    def grow(self) -> None:
        self.height += self.days - 1

    def aged(self) -> None:
        self.age += self.days


if __name__ == "__main__":
    holz: Plant = Plant("Holz", 30, 25, 1)
    Plant.get_info(holz)
    holz.days += 6
    Plant.get_info(holz)
