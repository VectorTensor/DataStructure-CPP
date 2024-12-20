# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define the project name and version
project(MyProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable to the project
add_executable(MyProject main.cpp)
