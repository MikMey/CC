import sys

if __name__ == "__main__":
    # input("gimme input: ")
    cont = ""
    cont = sys.stdin.readline()
    cont = input("get name: ")

    sys.stdout.write("give name: " + str(cont) + "\n")
    sys.stderr.write(f"Error: skill issue {str(cont)} \n")
