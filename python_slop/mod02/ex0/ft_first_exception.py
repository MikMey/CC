
def check_temperature(temp_str: str = "") -> str:
    print(f"Testing temperature: {temp_str}")
    try:
        temp: int = int(temp_str)
    except ValueError:
        print(f"Error '{temp_str}' is not int")
        return
    except (TypeError, KeyError, IndexError):
        print("Error something went wrong")
        return
    if temp > 40:
        print(f"Error: {temp} is too hot")
        return
    elif temp < 0:
        print(f"Error: {temp} is too cold")
    else:
        print(f"Temoperature {temp} is perfect")
        return (temp_str)


def test_temperature_input():
    check_temperature("25")
    check_temperature("abc")
    check_temperature("100")
    check_temperature("-50")
    check_temperature(0)


test_temperature_input()
