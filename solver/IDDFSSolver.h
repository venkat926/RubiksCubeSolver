
#include<iostream>
#include<vector>

#include "DFSSolver.h"
#include "../model/RubiksCube.h"
using namespace std;
#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H



/*
 *  Typename T: RubiksCube Representation used (3D, 1D)
 *  Typename H: Corresponding Hash function
 */
template<class T, class H>
class IDDFSSolver {
private:
    T rubiksCube;
    int maxSearchDepth;
    vector<RubiksCube::MOVE> moves;

public:
    IDDFSSolver(T rubiksCube, int maxSearchDepth) {
        this->rubiksCube = rubiksCube;
        this->maxSearchDepth = maxSearchDepth;
    }

    vector<RubiksCube::MOVE> solve() {
        for (int i=1; i<=maxSearchDepth; i++) {
            DFSSolver<T, H> dfsSolver(rubiksCube,i);
            moves = dfsSolver.solve();
            if (dfsSolver.getRubiksCube().isSolved()) {
                rubiksCube = dfsSolver.getRubiksCube();
                break;
            }
        }
        return moves;
    }
    void printSolvedRubiksCube() {
        this->rubiksCube.print();
    }
};

#endif //IDDFSSOLVER_H