

class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def display(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")


if __name__ == "__main__":
    print("=== Garden Plant Registry ===")
    Plant.display(Plant("Holz", 69, 69))
    Plant.display(Plant("Holz", 69, 69))
    Plant.display(Plant("Holz", 69, 69))
