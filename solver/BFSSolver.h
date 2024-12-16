
#include<iostream>
#include<vector>
#include "../model/RubiksCube.h"
using namespace std;

#ifndef BFSSOLVER_H
#define BFSSOLVER_H

#endif //BFSSOLVER_H


/*
 *  Typename T: RubiksCube Representation used (3D, 1D)
 *  Typename H: Corresponding Hash function
 */
template<class T, class H>
class BFSSolver {
private:
    int maxDepth;
    vector<RubiksCube::MOVE> moves;
    unordered_map<T, bool, H> visited;
    unordered_map<T, RubiksCube::MOVE, H> move_done;

    /*
    * bfs() -> performs breadth-first-search and returns a solved Rubik's Cube
    * move_done[] -> Back-Pointer map as to how we reached that state
    * */
    T bfs() {
        int depth = 0;
        queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube] = true;

        while (!q.empty()) {
            if (depth >= maxDepth) break;
            int siz = q.size();
            for (int i = 0; i < siz; i++) {
                 T node = q.front(); q.pop();
                if (node.isSolved()) {
                    return node;
                }

                for (int i=0; i<18; i++) {
                    auto cur_move = RubiksCube::MOVE(i);
                    node.move(cur_move);
                    if (!visited[node]) {
                        visited[node] = true;
                        move_done[node] = cur_move;
                        q.push(node);
                    }
                    node.invert(cur_move);
                }
            }
            depth++;

        }

        return rubiksCube;
    }

public:
    T rubiksCube;

    BFSSolver(T rubiksCube, int maxDepth) {
        this->rubiksCube = rubiksCube;
        this->maxDepth = maxDepth;
    }

    vector<RubiksCube::MOVE> solve() {
        T solved_cube = bfs();
        if (!solved_cube.isSolved()) return moves;
        T cur_cube = solved_cube;
        while (cur_cube != rubiksCube) {
            RubiksCube::MOVE cur_move = move_done[cur_cube];
            moves.push_back(cur_move);
            cur_cube.invert(cur_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }

};