from enum import Enum
from typing import Optional
from datetime import datetime

from pydantic import BaseModel, Field, ValidationError, model_validator


class ContactTypes(Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(..., min_length=5, max_length=15)
    timestamp: datetime = Field(...)
    location: str = Field(..., min_length=3, max_length=100)
    contact_type: Enum = Field(...)
    signal_strength: float = Field(..., ge=0, le=10)
    duration_minutes: int = Field(..., ge=1, le=1440)
    witness_count: int = Field(..., ge=1, le=100)
    message_received: Optional[str] = Field(default=None, max_length=500)
    is_verified: bool = Field(default=False)

    @model_validator(mode='after')
    def validate(self):
        try:
            if not self.contact_id.startswith("AC"):
                raise ValidationError("bad id")
            elif not self.is_verified:
                raise ValidationError("contact not verified")
            elif (self.contact_type == ContactTypes.TELEPATHIC and
                  self.witness_count < 3):
                raise ValidationError("made up shit")
            elif (self.signal_strength <= 7 and self.message_received
                  is not None):
                raise ValidationError("bad signal")
        except ValidationError as e:
            print(f"Error {e}")
        else:
            print("all g")
        return self


def main():
    print("VALID:\n")
    ac = AlienContact(
        contact_id="ACBLAH",
        timestamp='2032-04-23T10:20:30.400+02:30',
        location="moon",
        contact_type=ContactTypes.RADIO,
        signal_strength=10,
        duration_minutes=1440,
        witness_count=69,
        message_received="UR mum ge",
        is_verified=True
    )
    for i in ac:
        print(f"{i[0]}: {i[1]}")
    print("\ninvalid:")
    try:
        ac = AlienContact(
            contact_id="",
            timestamp='2032-04-23T10:20:30.400+02:30',
            location="moon",
            contact_type=ContactTypes.RADIO,
            signal_strength=10,
            duration_minutes=1440,
            witness_count=69,
            message_received="UR mum ge",
            is_verified=True
        )
    except ValidationError as e:
        print(f"Error:\n{e}")


if __name__ == "__main__":
    main()
