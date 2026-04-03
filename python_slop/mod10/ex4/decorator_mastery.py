import functools
from typing import Callable, Any
import time


def spell_timer(func: Callable) -> Callable:
    """
    spell_timer(func) - Time execution decorator:
    • Create a decorator that measures function execution time
    • Print "Casting function_name..." before execution
    • Print "Spell completed in X.XXX seconds" after execution
    (3 decimal places)
    • Use functools.wraps to preserve original function metadata
    • Return the original function’s result
    """

    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        print(f"Casting {func.__name__}")
        start = time.time()
        func()
        end = time.time()
        print(f"Completed in {round(end-start, 3)}s")

    wrapper.__name__ = func.__name__
    wrapper.__doc__ = func.__doc__
    return wrapper


def power_validator(min_power: int) -> Callable:
    """
    power_validator(min_power) - Parameterized validation decorator:
    • Create a decorator factory that validates power levels
    • Applied on a standalone function whose first argument is power.
    • If power is valid (>= min_power), execute the function normally
    • If invalid, return "Insufficient power for this spell"
    • Use functools.wraps properly
    """

    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args, **kwargs) -> Any:
            # print(args)
            power = kwargs['power']
            if min_power > power:
                return "Insufficient power"
            else:
                return func(*args, **kwargs)

        wrapper.__name__ = func.__name__
        wrapper.__doc__ = func.__doc__
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> Callable:
    """
    retry_spell(max_attempts) - Retry decorator:
    • Create a decorator that retries failed spells
    • If function raises an exception, retry up to max_attempts times
    • Print "Spell failed, retrying... (attempt n/max_attempts)"
    • If all attempts fail, return "Spell casting failed after
    max_attempts attempts"
    • If one attempt succeeds, return its result normally
    MageGuild class - Demonstrate staticmethod:
    """
    def decorator(func: Callable) -> Callable:

        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            for i in range(max_attempts):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if (i + 1) == max_attempts:
                        return (f"Spell casting failed after {max_attempts}"
                                "attempts")
                    print(f"Spell failed, retrying {i + 1}/{max_attempts}")
        wrapper.__name__ = func.__name__
        wrapper.__doc__ = func.__doc__
        return wrapper
    return decorator


class MageGuild:
    """
    • validate_mage_name(name) - Static method that checks if name is valid
    • Name is valid if it’s at least 3 characters and contains only
    letters/spaces
    • cast_spell(self, spell_name, power) - Instance method
    • Should use the power_validator decorator with min_power=10
    • When power is valid, return "Successfully cast spell_name with
    <power> power"
    • Otherwise return "Insufficient power for this spell"
    """
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if len(name) >= 3 and (name.isalnum or name.isspace):
            return True
        return False

    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


@retry_spell(3)
def fail():
    raise ValueError


@power_validator(5)
def something(power: int) -> str:
    return f"Its working at {power}"


@spell_timer
def main():
    print("Hello from inside")
    print(something(power=4))
    print(something(power=6))
    print(fail())
    test = MageGuild()
    print(test.cast_spell("any", power=11))


if __name__ == "__main__":
    main()
