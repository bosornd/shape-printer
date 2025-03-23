cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ShapePrinter)

# Add the executable
add_executable(ShapePrinter
    src/main.cpp
    src/PrintShape.cpp
    src/Diamond.cpp
    src/StreamOut.cpp
)

# Include directories
target_include_directories(ShapePrinter PRIVATE inc)