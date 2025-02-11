cmake_minimum_required(VERSION 3.10)

# Set the project name
project(shape-printer)

# Add source files
file(GLOB SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Add include directories
include_directories(inc)

# Add the executable
add_executable(shape-printer src/main.cpp ${SOURCES})

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
file(GLOB TEST_SOURCES "test/*.cpp")
add_executable(shape-printer-tests ${TEST_SOURCES} ${SOURCES})
target_link_libraries(shape-printer-tests gtest gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME PrintShapeTest COMMAND shape-printer-tests)