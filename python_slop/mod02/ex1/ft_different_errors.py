def garden_operations() -> None:
    strn = "abc"
    plants = {}
    try:
        int(strn)
    except ValueError:
        print("Caught ValueError: invalid literal for int()")
    try:
        strn = 0/0
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero")
    try:
        open("blah")
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file 'missing.txt'")
    try:
        plants["plant"]
    except KeyError:
        print("Caught KeyError: 'plant'")
    try:
        plants["plant"]
        open("blah")
        int(strn)
    except (ValueError, FileNotFoundError, KeyError):
        print("caught Errors")
    finally:
        print("all errorss")


def test_error_types() -> None:
    garden_operations()


test_error_types()
