# Virtual Altitude Monitor Embedded System

🚀 **Virtual Altitude Monitor** is a simulated embedded system project written in C that mimics an aerospace barometric altitude monitor. It features:

- Virtual barometric sensor simulating altitude fluctuations
- Command-line interface (CLI) for status, logging control, and fault queries
- Fault detection for rapid altitude drops (>100 ft per second)
- CSV data logging with timestamps
- Modular, clean C code with build system (CMake)

---

## Project Structure

```
virtual-altitude-monitor/
├── src/ # Source code
├── include/ # Header files
├── logs/ # CSV log files generated at runtime
├── build/ # Build directory (ignored)
├── CMakeLists.txt # Build system config
└── README.md # This document
```


---

## Prerequisites

- GCC or Clang compiler
- CMake build system

On macOS, install with Homebrew:
brew install cmake

---

## Build Instructions
```
mkdir -p build
cd build
cmake ..
make
```

---

## Running the Program
```
Run the compiled binary:
./altitude_monitor
```


---

## CLI Commands

| Command | Description                              |
| ------- | ---------------------------------------- |
| STATUS  | Print the current altitude value         |
| LOG ON  | Enable data logging to `logs/log.csv`    |
| LOG OFF | Disable data logging                     |
| FAULT   | Query if a rapid descent fault is active |
| EXIT    | Exit the program                         |


---

## Example Usage

```
>> STATUS
📡 Altitude: 1003.27 ft
>> LOG ON
✅ Logging enabled.
>> FAULT
✅ No faults detected.
>> EXIT
🛑 System shutting down.
```


---

## Features

Virtual Sensor: Simulates altitude changes using a sine wave function.

Fault Detection: Alerts if altitude drops by more than 100 feet within one second.

Data Logging: Logs timestamped altitude and fault status to CSV format.

Modular Code: Clean separation of sensor, CLI, logger, and main logic.

Build System: Uses CMake for easy, cross-platform building.


---

## Sample Log File (logs/log.csv)
```
timestamp,altitude,fault
2025-06-23 20:18:05,1002.34,OK
2025-06-23 20:18:06,900.12,FAULT
```

---

## Acknowledgments

Inspired by common aerospace embedded software patterns and designed for portfolio demonstration.
