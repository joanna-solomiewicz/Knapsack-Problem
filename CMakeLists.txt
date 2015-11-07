cmake_minimum_required(VERSION 3.3)
project(Knapsack_Problem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lncurses")

set(SOURCE_FILES
        main.cpp
        ProblemGenerator.cpp
        ProblemGenerator.h
        Object.cpp
        Object.h
        ProblemInstance.cpp
        ProblemInstance.h
        Result.cpp
        Result.h
        Solvers/DynamicSolver.cpp
        Solvers/DynamicSolver.h
        Solvers/BruteforceRecursiveSolver.cpp
        Solvers/BruteforceRecursiveSolver.h
        Solvers/GreedySolver.cpp
        Solvers/GreedySolver.h
        Solvers/BacktrackingSolver.cpp
        Solvers/BacktrackingSolver.h Solvers/BranchAndBoundSolver.cpp Solvers/BranchAndBoundSolver.h Solvers/BruteforceIterativeSolver.cpp Solvers/BruteforceIterativeSolver.h)
add_executable(Knapsack_Problem ${SOURCE_FILES})