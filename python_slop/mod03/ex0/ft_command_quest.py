import sys

if __name__ == "__main__":
    print(f"Program name: {sys.argv[0]}")
    if not sys.argv[1:]:
        print("No ARGS")
    for num, i in enumerate(sys.argv[1:]):
        print(f"Argument {num + 1}: {i}")
    print(f"Total args: {len(sys.argv)}")
