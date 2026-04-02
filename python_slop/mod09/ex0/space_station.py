from pydantic import BaseModel, Field, ValidationError
from typing import Optional
from datetime import datetime


class SpaceStation(BaseModel):
    station_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=1, max_length=50)
    crew_size: int = Field(..., ge=1, le=20)
    power_level: float = Field(..., ge=0, le=100)
    oxygen_level: float = Field(..., ge=0, le=100)
    last_maintenance: datetime = Field(...)
    is_operational: bool = Field(default=True)
    notes: Optional[str] = Field(default=None, max_length=200)


def main() -> None:
    ss = SpaceStation(
        station_id="JoeMama2",
        name="BigIdiot",
        crew_size=5,
        power_level=100,
        oxygen_level=1,
        last_maintenance='2032-04-23T10:20:30.400+02:30'
    )

    for i in ss:
        print(f"{i[0]}: {i[1]}")

    try:
        ss = SpaceStation(
            station_id="JoeMama02",
            name="BigIdiot",
            crew_size=10000,
            power_level=100,
            oxygen_level=1,
            last_maintenance='2032-04-23T10:20:30.400+02:30'
        )
    except ValidationError:
        print("\ninvalid")


if __name__ == "__main__":
    main()
