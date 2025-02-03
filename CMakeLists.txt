cmake_minimum_required(VERSION 3.10)

# Set the project name
project(shape-printer)

# Add the executable
add_executable(shape-printer src/main.cpp src/Diamond.cpp src/PrintShape.cpp src/Cross.cpp src/StreamOut.cpp src/BMPCreator.cpp src/BMP.cpp)

# Include directories
target_include_directories(shape-printer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add the test executable
add_executable(tests test/PrintShapeTest.cpp src/PrintShape.cpp src/StreamOut.cpp src/Diamond.cpp src/Cross.cpp src/BMPCreator.cpp src/BMP.cpp)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(tests gtest gtest_main)
