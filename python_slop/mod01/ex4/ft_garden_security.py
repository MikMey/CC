class SecurePlant:
    def __init__(self, name: str):
        self.__name = name
        self.__create_plant()

    def __create_plant(self):
        print(f"Plant created: {self.__name}")

    def set_height(self, height: int = 0):
        if height >= 0:
            self.__height = height
            print(f"Height updated: {self.__height}cm [OK]")
        else:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")

    def set_age(self, age: int = 0):
        if age >= 0:
            self.__age = age
            print(f"Height updated: {self.__age}cm [OK]")
        else:
            print(f"Invalid operation attempted: age {age} days [REJECTED]")

    def get_info(self):
        print(f"Current plant: {self.__name} ({self.__height}cm, "
              f"{self.__age} days)")

    def get_height(self):
        print(f"Current height: {self.__height}cm")

    def get_age(self):
        print(f"Current age: {self.__age} days")


if __name__ == "__main__":
    print("=== Garden Security System ===")
    holz: SecurePlant = SecurePlant("Holz")
    holz.set_height(1)
    holz.set_age(100000)
    holz.set_height(-5)
    holz.get_info()
