from typing import Callable, Any
import functools


def spell_reducer(spells: list[int], operation: str) -> int:
    """
    spell_reducer(spells, operation) - Reduce spell powers:
    • Use functools.reduce to combine all spell powers
    • Support operations: "add", "multiply", "max", "min"
    • Use operator module functions (add, mul, etc.)
    • Return the final reduced value
    • If spells is empty, return 0
    • If operation is unknow, properly handle the error
    """
    ops: dict = {
        'add': lambda x, y: x + y,
        'mul': lambda x, y: x * y,
        'max': lambda x, y: max(x, y),
        'min': lambda x, y: min(x, y)
    }
    if operation not in ops.keys():
        return 0
    elif spells is None or len(spells) == 0:
        return 0
    else:
        return functools.reduce(ops[operation], spells)


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    """
    partial_enchanter(base_enchantment) - Create partial applications:
    • Take a base enchantment function with signature (power: int, element:
    str, target:
    str) -> str
    • Use functools.partial to create 3 specialized versions
    • Each version pre-filling power=50 and the element
    """
    def partialiser(elem: str) -> Callable:
        return functools.partial(base_enchantment, 50, elem)

    return {
        'fire': partialiser('fire'),
        'water': partialiser('water'),
        'earth': partialiser('earth')
    }


@functools.lru_cache(128)
def memoized_fibonacci(n: int) -> int:
    """
    memoized_fibonacci(n) - Cached fibonacci:
    • Use functools.lru_cache decorator for memoization
    • Implement fibonacci sequence calculation
    • Function should return the nth Fibonacci number
    • The cache should improve performance for repeated calls
    • Return the nth fibonacci number
    You can verify caching works via memoized_fibonacci.cache_info().
    """
    if n < 2:
        return n
    return memoized_fibonacci(n-1) + memoized_fibonacci(n-2)


def spell_dispatcher() -> Callable[[Any], str]:
    """
    spell_dispatcher() - Create single dispatch system:
    • Use decorator functools.singledispatch to create a spell system
    • The base function receives Any and handles unknown spell type
    • Handle different types: int (damage spell), str (enchantment),
    list (multi-cast)
    • Return the dispatcher function
    • Each type should have appropriate spell behavior
    """

    @functools.singledispatch
    def gen_spell(var: Any) -> None:
        print(var)

    @gen_spell.register(int)
    def _1(var: int) -> None:
        print(var * 2)

    @gen_spell.register(str)
    def _2(var: str) -> None:
        print(f"This {var}")

    @gen_spell.register(list)
    def _3(var: list) -> None:
        for num, i in enumerate(var):
            print(f"{num}: {i}")
    return gen_spell


def main():
    test_spell = [10, 20, 5]
    test_ops = ["add", "mul", "min", "max"]
    for x in test_ops:
        print(spell_reducer(test_spell, x))

    def base(power: int, element: str, target: str) -> str:
        return (f"{power} of {element} at {target}")
    res = partial_enchanter(base)
    for i in res.values():
        print(i("orc"))

    print(memoized_fibonacci(100))

    option = spell_dispatcher()
    option(str("Hello"))
    option([1, 2, 3])
    option(10)


if __name__ == "__main__":
    main()
