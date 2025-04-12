cmake_minimum_required(VERSION 3.10)

# Project name
project(cli_todo_cpp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the executable
add_executable(cli_todo_cpp src/main.cpp)

# Link the data directory
add_custom_command(
    TARGET cli_todo_cpp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:cli_todo_cpp>/data
)