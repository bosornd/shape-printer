cmake_minimum_required(VERSION 3.10)

# Set the project name
project(shape-printer)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Add include directories
include_directories(inc)

# Add the executable
add_executable(shape-printer
    src/main.cpp
    ${SOURCES}
)