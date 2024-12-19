#include <iostream>
#include "model/RubiksCube3DArrayRepresentation.cpp"
#include "model/RubiksCube1DArrayRepresentation.cpp"
#include "solver/BFSSolver.h"
#include "solver/DFSSolver.h"
#include "solver/IDAstarSolver.h"
#include "solver/IDDFSSolver.h"
using namespace std;
int main() {

    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";


    /*
   * IDAstarSolver testing
   */
    RubiksCube1DArray rubiksCube;
    rubiksCube.randomShuffleCube(5);
    rubiksCube.print();

    IDAstarSolver<RubiksCube1DArray, Hash1d> ida_solver(rubiksCube);

    auto ida_start = std::chrono::high_resolution_clock::now();
    ida_solver.solve();
    auto ida_end = std::chrono::high_resolution_clock::now();
    ida_solver.printSolvedRubiksCube();

    auto ida_duration = std::chrono::duration_cast<std::chrono::duration<double>>(ida_end - ida_start).count();
    std::cout << "Time taken by IDAstarSolver: " << ida_duration << " seconds" << std::endl;

    /*
    * IDDFSSolver testing
    */

    // RubiksCube1DArray rubiksCube;
    // rubiksCube.randomShuffleCube(3);
    // rubiksCube.print();

    IDDFSSolver<RubiksCube1DArray, Hash1d> iddfs_solver(rubiksCube, 7);

    auto iddfs_start = std::chrono::high_resolution_clock::now();
    iddfs_solver.solve();
    auto iddfs_end = std::chrono::high_resolution_clock::now();
    iddfs_solver.printSolvedRubiksCube();

    auto iddfs_duration = std::chrono::duration_cast<std::chrono::duration<double>>(iddfs_end - iddfs_start).count();
    std::cout << "Time taken by IDDFSSolver: " << iddfs_duration << " seconds" << std::endl;


    /*
     * DFSSolver, BFSSolver and IDDFSSolver testing
     */
    // RubiksCube1DArray rubiksCube;
    // rubiksCube.randomShuffleCube(5);
    // rubiksCube.print();
    //
    // DFSSolver<RubiksCube1DArray, Hash1d> dfs_solver(rubiksCube, 7);
    // BFSSolver<RubiksCube1DArray, Hash1d> bfs_solver(rubiksCube, 7);
    // IDDFSSolver<RubiksCube1DArray, Hash1d> iddfs_solver(rubiksCube, 7);
    //
    // auto dfs_start = std::chrono::high_resolution_clock::now();
    // dfs_solver.solve();
    // auto dfs_end = std::chrono::high_resolution_clock::now();
    // dfs_solver.printSolvedRubiksCube();
    //
    //
    // auto bfs_start = std::chrono::high_resolution_clock::now();
    // bfs_solver.solve();
    // auto bfs_end = std::chrono::high_resolution_clock::now();
    // bfs_solver.printSolvedRubiksCube();
    //
    // auto iddfs_start = std::chrono::high_resolution_clock::now();
    // iddfs_solver.solve();
    // auto iddfs_end = std::chrono::high_resolution_clock::now();
    // iddfs_solver.printSolvedRubiksCube();
    //
    //
    // auto dfs_duration = std::chrono::duration_cast<std::chrono::duration<double>>(dfs_end - dfs_start).count();
    // std::cout << "Time taken by DFSSolver: " << dfs_duration << " seconds" << std::endl;
    // auto bfs_duration = std::chrono::duration_cast<std::chrono::duration<double>>(bfs_end - bfs_start).count();
    // std::cout << "Time taken by BFSSolver: " << bfs_duration << " seconds" << std::endl;
    // auto iddfs_duration = std::chrono::duration_cast<std::chrono::duration<double>>(iddfs_end - iddfs_start).count();
    // std::cout << "Time taken by IDDFSSolver: " << iddfs_duration << " seconds" << std::endl;



    {
        /*
         * Testing RubiksCube3DModel
         */
        // RubiksCube3DArray rubiksCube3DArray;
        //
        // rubiksCube3DArray.print();
        // if (rubiksCube3DArray.isSolved()) cout << "Cube is Solved!" << endl;
        // else cout << "Cube is Not Solved!" << endl;
        //
        // rubiksCube3DArray.l();
        // rubiksCube3DArray.print();
        // if (rubiksCube3DArray.isSolved()) cout << "Cube is Solved!" << endl;
        // else cout << "Cube is Not Solved!" << endl;
    }



    {
        /*
         * Testing RubiksCube1DModel
         */
        // RubiksCube1DArray cube;
        //
        // cube.print();
        // if (cube.isSolved()) cout << "Cube is Solved!" << endl;
        // else cout << "Cube is Not Solved!" << endl;
        //
        // cube.b();
        // cube.print();
        //
        // if (cube.isSolved()) cout << "Cube is Solved!" << endl;
        // else cout << "Cube is Not Solved!" << endl;
    }



    return 0;
}
