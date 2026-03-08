if __name__ == "__main__":
    with open("./ex3/classified_data.txt", "r") as cont:
        print(cont.read())
    with open("./ex3/security_protocols.txt", "r") as cont:
        with open("./ex3/classified_data.txt", "a") as file:
            file.write(f"\n{cont.read()}")
    with open("./ex3/classified_data.txt", "r") as cont:
        print(cont.read())
