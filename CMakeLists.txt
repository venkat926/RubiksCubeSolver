cmake_minimum_required(VERSION 3.30)
project(RubiksCubeSolverExplain)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubiksCubeSolverExplain main.cpp
        model/RubiksCube.cpp
        model/RubiksCube.h
        model/RubiksCube3DArrayRepresentation.cpp
        model/RubiksCube1DArrayRepresentation.cpp
        solver/DFSSolver.h
        solver/BFSSolver.h
        solver/IDDFSSolver.h
        patternDatabase/NibbleArray.cpp
        patternDatabase/NibbleArray.h
        patternDatabase/PatternDatabase.cpp
        patternDatabase/PatternDatabase.h
        solver/IDAstarSolver.h)
