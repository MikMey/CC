import sys

if __name__ == "__main__":
    scores: list = []
    if not sys.argv[1:]:
        print("No ARGS")
    else:
        for i in sys.argv[1:]:
            try:
                i = int(i)
                scores.append(i)
            except ValueError:
                print("Bro...")
        try:
            print(f"High score: {max(scores)}")
            print(f"Low score: {min(scores)}")
            if len(scores) >= 2:
                print(f"Total: {sum(scores)}")
            print(f"Amount: {len(scores)}")
        except ValueError:
            print("Bro...")
