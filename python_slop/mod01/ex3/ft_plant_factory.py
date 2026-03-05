class Plant:
    def __init__(self, name: str, str_height: int,
                 str_age: int):
        self.name = name
        self.start_height = str_height
        self.start_age = str_age

    def create(self):
        print(f"Created: {self.name} ({self.start_height}cm, "
              f"{self.start_age} days)")


if __name__ == "__main__":
    count: int = 0
    print("=== Plant Factory Output ===")
    lst: list = [
        Plant("Rose", 25, 30),
        Plant("Oak", 200, 365),
        Plant("Cactus", 5, 90),
        Plant("Sunflower", 80, 45),
        Plant("Fern", 15, 120)
                ]
    for i in lst:
        Plant.create(i)
        count += 1
    print(f"\nTotal plants created: {count}")
