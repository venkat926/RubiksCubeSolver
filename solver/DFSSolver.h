
#include<iostream>
#include<vector>
#include "../model/RubiksCube.h"
using namespace std;

#ifndef DFSSOLVER_H
#define DFSSOLVER_H

#endif //DFSSOLVER_H

/*
 *  Typename T: RubiksCube Representation used (3D, 1D)
 *  Typename H: Corresponding Hash function
 */
template<class T, class H>
class DFSSolver {
private:
    vector<RubiksCube::MOVE> moves;
    int maxSearchDepth;

    bool dfs(int depth) {
        if (rubiksCube.isSolved()) return true;
        if (depth > maxSearchDepth) return false;
        for (int i=0; i<18; i++) {
            rubiksCube.move(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));
            if (dfs(depth+1)) return true;
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }


public:
    T rubiksCube;

    DFSSolver(T rubiksCube, int maxSearchDepth=8) {
        this->rubiksCube = rubiksCube;
        this->maxSearchDepth = maxSearchDepth;
    }

    vector<RubiksCube::MOVE> solve() {
        dfs(1);
        return moves;
    }
};