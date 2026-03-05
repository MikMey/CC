

def ft_count_harvest_recursive():
    # recursive version asks and then prints from 1 to n
    def helper(current, limit):
        if current > limit:
            return
        print(f"Day {current}")
        helper(current + 1, limit)

    n = int(input("Days until harvest: "))
    helper(1, n)
    print("Harvest time!")
