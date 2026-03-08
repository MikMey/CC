def handle_file(filename: str) -> None:
    print(f"\nattemptint access: {filename}")
    try:
        with open(filename, "r") as file:
            print(f" Archive recovered - {file.read()}")
    except (FileNotFoundError, PermissionError):
        print("Crisis handled, security maintained")
    finally:
        print("continuing\n")


if __name__ == "__main__":
    handle_file("python_slop/mod04/ex4/corrupted_archive.txt")
    handle_file("python_slop/mod04/ex4/standard_archive.txt")
