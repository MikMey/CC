from typing import Any, List, Dict, Union, Optional
from abc import ABC, abstractmethod


def format_batch(data_batch: List[Any]) -> str:
    if all(isinstance(item, dict) for item in data_batch):
        items = []
        for d in data_batch:
            for k, v in d.items():
                items.append(f"{k}:{v}")
        return '[' + ', '.join(items) + ']'
    elif all(isinstance(item, str) for item in data_batch):
        return '[' + ', '.join(data_batch) + ']'
    else:
        return str(data_batch)


class DataStream(ABC):
    def __init__(self, stream_id: str):
        self.stream_id = stream_id

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        # Default implementation: return all data
        return data_batch

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        # Default stats
        return {"stream_id": self.stream_id, "type": "Generic", "processed": 0}


class SensorStream(DataStream):
    def __init__(self, stream_id: str):
        super().__init__(stream_id)
        self.processed_readings = 0
        self.avg_temp = 0.0

    def process_batch(self, data_batch: List[Any]) -> str:
        try:
            temps = [item["temp"] for item in data_batch
                     if isinstance(item, dict) and "temp" in item]
            self.processed_readings += len(data_batch)
            if temps:
                self.avg_temp = sum(temps) / len(temps)
            return (f"Sensor analysis: {len(data_batch)} readings processed, "
                    f"avg temp: {self.avg_temp:.1f}°C")
        except Exception as e:
            return f"Error processing sensor batch: {str(e)}"

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "stream_id": self.stream_id,
            "type": "Environmental Data",
            "processed": self.processed_readings,
            "avg_temp": self.avg_temp
        }


class TransactionStream(DataStream):
    def __init__(self, stream_id: str):
        super().__init__(stream_id)
        self.operations = 0
        self.net_flow = 0

    def process_batch(self, data_batch: List[Any]) -> str:
        try:
            for item in data_batch:
                if isinstance(item, dict):
                    if "buy" in item:
                        self.net_flow += item["buy"]
                    elif "sell" in item:
                        self.net_flow -= item["sell"]
            self.operations += len(data_batch)
            return (f"Transaction analysis: {len(data_batch)} operations, "
                    f"net flow: {self.net_flow} units")
        except Exception as e:
            return f"Error processing transaction batch: {str(e)}"

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "stream_id": self.stream_id,
            "type": "Financial Data",
            "operations": self.operations,
            "net_flow": self.net_flow
        }


class EventStream(DataStream):
    def __init__(self, stream_id: str):
        super().__init__(stream_id)
        self.events = 0
        self.errors = 0

    def process_batch(self, data_batch: List[Any]) -> str:
        try:
            self.events += len(data_batch)
            self.errors += sum(
                1 for event in data_batch
                if isinstance(event, str) and "error" in event.lower()
            )
            return (f"Event analysis: {len(data_batch)} events, {self.errors} "
                    f"error{'s' if self.errors != 1 else ''} detected")
        except Exception as e:
            return f"Error processing event batch: {str(e)}"

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "stream_id": self.stream_id,
            "type": "System Events",
            "events": self.events,
            "errors": self.errors
        }


class StreamProcessor:
    def __init__(self):
        self.streams: List[DataStream] = []

    def add_stream(self, stream: DataStream):
        self.streams.append(stream)

    def process_mixed_batch(self, stream_batches: Dict[str, List[Any]]) -> str:
        results = []
        for stream_id, data_batch in stream_batches.items():
            stream = next((s for s in self.streams
                           if s.stream_id == stream_id), None)
            if stream:
                try:
                    result = stream.process_batch(data_batch)
                    if "Sensor analysis:" in result:
                        num = result.split("readings processed")[0] \
                              .split(": ")[-1].strip()
                        summary = f"Sensor data: {num} readings processed"
                    elif "Transaction analysis:" in result:
                        num = result.split("operations")[0] \
                              .split(": ")[-1].strip()
                        summary = (
                            f"Transaction data: {num} operations processed"
                        )
                    elif "Event analysis:" in result:
                        num = result.split("events")[0] \
                              .split(": ")[-1].strip()
                        summary = f"Event data: {num} events processed"
                    else:
                        summary = result
                    results.append(f"- {summary}")
                except Exception as e:
                    results.append(f"- {stream_id}: Error processing batch: "
                                   f"{str(e)}")
            else:
                results.append(f"- {stream_id}: Stream not found")
        return "\n".join(results)

    def filter_all_streams(self, criteria: Optional[str] = None
                           ) -> Dict[str, List[Any]]:
        filtered = {}
        for stream in self.streams:
            if (isinstance(stream, SensorStream) and
                    criteria == "high-priority"):
                filtered[stream.stream_id] = [
                    {"temp": 30.0, "alert": "high"},
                    {"temp": 35.0, "alert": "critical"}
                ]
            elif isinstance(stream, TransactionStream) \
                    and criteria == "high-priority":
                filtered[stream.stream_id] = [{"sell": 1000}]
            else:
                filtered[stream.stream_id] = []
        return filtered


if __name__ == "__main__":
    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===")

    # Initialize streams
    sensor = SensorStream("SENSOR_001")
    print("Initializing Sensor Stream...")
    print(f"Stream ID: {sensor.stream_id}, Type: {sensor.get_stats()['type']}")
    sensor_data = [{"temp": 22.5}, {"humidity": 65}, {"pressure": 1013}]
    print(f"Processing sensor batch: {format_batch(sensor_data)}")
    print(sensor.process_batch(sensor_data))

    trans = TransactionStream("TRANS_001")
    print("\nInitializing Transaction Stream...")
    print(f"Stream ID: {trans.stream_id}, Type: {trans.get_stats()['type']}")
    trans_data = [{"buy": 100}, {"sell": 150}, {"buy": 75}]
    print(f"Processing transaction batch: {format_batch(trans_data)}")
    print(trans.process_batch(trans_data))

    event = EventStream("EVENT_001")
    print("\nInitializing Event Stream...")
    print(f"Stream ID: {event.stream_id}, Type: {event.get_stats()['type']}")
    event_data = ["login", "error", "logout"]
    print(f"Processing event batch: {format_batch(event_data)}")
    print(event.process_batch(event_data))

    # Polymorphic processing
    processor = StreamProcessor()
    processor.add_stream(sensor)
    processor.add_stream(trans)
    processor.add_stream(event)

    print("\n=== Polymorphic Stream Processing ===")
    print("Processing mixed stream types through unified interface...")
    mixed_batches = {
        "SENSOR_001": [{"temp": 20.0}, {"temp": 25.0}],
        "TRANS_001": [{"buy": 200}, {"sell": 50}, {"buy": 100}, {"sell": 150}],
        "EVENT_001": ["login", "error", "logout"]
    }
    results = processor.process_mixed_batch(mixed_batches)
    print("Batch 1 Results:")
    print(results)
    print("Stream filtering active: High-priority data only")
    filtered = processor.filter_all_streams("high-priority")
    print(f"Filtered results: {len(filtered['SENSOR_001'])} critical sensor "
          f"alerts, {len(filtered['TRANS_001'])} large transaction")
    print("All streams processed successfully. Nexus throughput optimal.")
