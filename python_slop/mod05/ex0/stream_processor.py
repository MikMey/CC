from typing import Any
from abc import ABC, abstractmethod
import sys


class DataProcessor(ABC):

    @abstractmethod
    def process(self, data: Any) -> str:
        return (f"processing {data}")

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    def format_output(self, result: str) -> str:
        pass


class NumericProcessor(DataProcessor):

    def process(self, data):
        print("init num proc")
        print(super().process(data))

    def validate(self, data) -> bool:
        sum = 0
        try:
            for i in data:
                try:
                    sum += i
                except ValueError:
                    print("Error", file=sys.stderr)
            print("num Data validated")
        except ValueError:
            print("Error", file=sys.stderr)


class TextProcessor(DataProcessor):

    def process(self, data):
        print("init txt proc")
        print(super().process(data))

    def validate(self, data) -> bool:
        print("Bro wtf")


class LogProcessor(DataProcessor):

    def process(self, data):
        print("init log proc")
        print(super().process(data))

    def validate(self, data) -> bool:
        print("Bro wtf")


log = LogProcessor()
txt = TextProcessor()
num = NumericProcessor()

log.process(None)
log.validate(None)
txt.process(None)
txt.validate(None)
num.process(None)
num.validate(None)
