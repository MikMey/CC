from sys import argv
from math import sqrt

if __name__ == "__main__":
    coords_raw: list = []
    if not argv[1:]:
        print("No ARGS")
    else:
        for item in argv[1:]:
            try:
                item = int(item)
                coords_raw.append(int(item))
            except ValueError:
                print("not int")
        try:
            if len(coords_raw) < 3:
                raise ValueError(" not 3 args")
            coords: tuple = tuple(coords_raw)
            print(f"pos: {coords}")
            distance = sqrt(coords[0]**2 + coords[1]**2 + coords[2]**2)
            print(f"Distance (0,0,0) to {coords} is : {distance}")
        except ValueError as e:
            print(f"Skill issue {e}")
