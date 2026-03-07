import random


def my_gen(count: int = 0, player: list[str] = ["player", "other"]):
    num = 1
    event: list[str] = ["killed monster", "found treasure", "eveled up",
                        "died"]
    while count >= 0:
        yield (f"Event {num}: Player "
               f"{player[random.randrange(0, len(player) - 1)]}"
               f" (level {random.randrange(1, 50)})"
               f" {event[random.randrange(0, len(event))]}")
        count -= 1
        num += 1


for i in my_gen(10):
    print(i)
