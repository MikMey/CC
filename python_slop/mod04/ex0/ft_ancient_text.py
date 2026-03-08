

if __name__ == "__main__":
    try:
        print("\naccesing\n")
        cont = open("./ex0/ancient_fragment.txt", "r")
        print("\nreading\n")
        print(cont.read())
        print("\n\nclosing\n")
        cont.close()
    except (FileNotFoundError):
        print("Doesnt exist")
        exit()
