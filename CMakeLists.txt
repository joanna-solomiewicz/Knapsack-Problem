cmake_minimum_required(VERSION 3.3)
project(Knapsack_Problem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        ProblemGenerator.cpp
        ProblemGenerator.h
        Object.cpp
        Object.h
        ProblemInstance.cpp
        ProblemInstance.h
)
add_executable(Knapsack_Problem ${SOURCE_FILES})