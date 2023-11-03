cmake_minimum_required(VERSION 3.10)

project(MyProject)  # Change 'MyProject' to your project name

set(CMAKE_CXX_STANDARD 20)  # Set C++ standard to C++20

# Add the source files in the 'test' directory
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/test/*.cpp")

# Define the executable and its source files
add_executable(run_tests ${SOURCES})

# Specify the output directory for the executable
set_target_properties(run_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)
