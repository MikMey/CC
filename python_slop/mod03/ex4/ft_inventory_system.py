if __name__ == "__main__":
    inv: dict = {
        'potion': 5,
        'armor': 3,
        'shield': 2,
        'sword': 1,
        'helmet': 1
        }
    total_items = sum(inv.values())
    unique_types = len(inv)

    print("\n === Inventory System Analysis === \n\n"
          f"Total items in inventory: {total_items}\n"
          f"Unique item types: {unique_types}\n\n")

    most_abundant = max(inv, key=inv.get)
    least_abundant = min(inv, key=inv.get)

    print(f"Most abundant: {most_abundant} ({inv[most_abundant]} units)\n"
          f"Least abundant: {least_abundant} ({inv[least_abundant]} unit(s))"
          "\n\n")

    abundance_categories: dict = {
        'abundant': {},
        'moderate': {},
        'rare': {}
    }

    for item, quantity in inv.items():
        percentage = (quantity / total_items) * 100
        if percentage >= 25:
            abundance_categories['abundant'][item] = quantity
        elif percentage >= 10:
            abundance_categories['moderate'][item] = quantity
        else:
            abundance_categories['rare'][item] = quantity

    print(" === Items by Abundance === \n")
    for category, items in abundance_categories.items():
        print(f"{category.upper()}:")
        for item, qty in items.items():
            print(f"  {item}: {qty} units")
        print()

    print(" === Current inventory === \n")
    for key, item in inv.items():
        print(f"{key}: {item} units ({round(item / total_items * 100, 2)}%)")

    print("\n === Inventory Report === \n")
    print(f"Storage efficiency: {round(total_items / unique_types, 2)} items "
          "per type (avg)")
    print(f"Inventory value: {total_items} total units across {unique_types} "
          "categories")
