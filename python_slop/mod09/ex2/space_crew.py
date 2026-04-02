from enum import Enum
from typing import List
from datetime import datetime

from pydantic import BaseModel, Field, model_validator


class Rank(Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=2, max_length=50)
    rank: Rank = Field(...)
    age: int = Field(..., ge=18, le=80)
    specialization: str = Field(..., min_length=3, max_length=30)
    years_experience: int = Field(..., ge=0, le=50)
    is_active: bool = Field(default=True)


class SpaceMission(BaseModel):
    mission_id: str = Field(..., min_length=5, max_length=15)
    mission_name: str = Field(..., min_length=3, max_length=100)
    destination: str = Field(..., min_length=3, max_length=50)
    launch_date: datetime = Field(...)
    duration_days: int = Field(..., ge=1, le=3650)
    crew: List[CrewMember] = Field(..., min_length=1, max_length=12)
    mission_status: str = Field(default="planned")
    budget_millions: float = Field(..., ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def validate(self):
        try:
            if not self.mission_id.startswith("M"):
                raise ValueError("Mission id bad")
            self.__check_rank()
            if self.duration_days > 365:
                self.__check_experience()
            self.__check_activity()
        except ValueError as e:
            print(f"Error:\n{e}")
        else:
            print("Valid\n")
        return self

    def __check_rank(self) -> None:
        for member in self.crew:
            if member.rank == Rank.COMMANDER or member.rank == Rank.CAPTAIN:
                return
        raise ValueError("no sufficient rank")

    def __check_experience(self) -> None:
        total = range(self.crew)
        count = 0
        for member in self.crew:
            if member.years_experience >= 5:
                count += 1
            if (total / 2 + total % 2) <= count:
                return
        raise ValueError("crew inexperienced")

    def __check_activity(self) -> None:
        for member in self.crew:
            if member.is_active is False:
                raise ValueError("some member not active")


def main():
    print("VALID:\n")
    crew1 = CrewMember(
        member_id="CM001",
        name="John Smith",
        rank=Rank.CAPTAIN,
        age=45,
        specialization="Navigation",
        years_experience=20,
        is_active=True
    )

    crew2 = CrewMember(
        member_id="CM002",
        name="Alice Johnson",
        rank=Rank.LIEUTENANT,
        age=35,
        specialization="Engineering",
        years_experience=10,
        is_active=True
    )

    crew3 = CrewMember(
        member_id="CM003",
        name="Bob Wilson",
        rank=Rank.OFFICER,
        age=32,
        specialization="Science",
        years_experience=8,
        is_active=True
    )

    mission = SpaceMission(
        mission_id="M12345",
        mission_name="Lunar Base Alpha",
        destination="Moon",
        launch_date='2026-06-15T08:00:00',
        duration_days=180,
        crew=[crew1, crew2, crew3],
        mission_status="planned",
        budget_millions=500.5
    )

    for i in mission:
        if i[0] == "crew":
            print("members:")
            for member in mission.crew:
                print(f"\t{member.member_id}")
        else:
            print(f"{i[0]}: {i[1]}")

    print("\nINVALID:\n")
    try:
        bad_crew1 = CrewMember(
            member_id="CM004",
            name="Charlie Brown",
            rank=Rank.CADET,
            age=22,
            specialization="Training",
            years_experience=0,
            is_active=True
        )

        mission = SpaceMission(
            mission_id="BAD123",
            mission_name="Invalid Mission",
            destination="Mars",
            launch_date='2027-01-01T00:00:00',
            duration_days=500,
            crew=[bad_crew1],
            mission_status="planned",
            budget_millions=1000.0
        )
    except ValueError as e:
        print(f"Error:\n{e}")


if __name__ == "__main__":
    main()
