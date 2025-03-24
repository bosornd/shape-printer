cmake_minimum_required(VERSION 3.10)
project(shape-printer-tests)

# Add test source files
file(GLOB TEST_SOURCES "*.cpp")

# tests/CMakeLists.txt
add_executable(
    shape-printer-tests
    ${SOURCES}
    ${TEST_SOURCES}
)

target_link_libraries(
    shape-printer-tests
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(shape-printer-tests)