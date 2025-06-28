# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(VirtualAltitudeMonitor C)

set(CMAKE_C_STANDARD 99)

# Source files
add_executable(altitude_monitor
    src/main.c
    src/barometer.c
    src/cli.c
)

# Include directory
target_include_directories(altitude_monitor PRIVATE include)
