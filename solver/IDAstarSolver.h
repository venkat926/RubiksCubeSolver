
#ifndef IDASTARSOLVER_H
#define IDASTARSOLVER_H
#include "../patternDatabase/PatternDatabase.h"

template<typename T, typename H>
class IDAstarSolver {
private:
    T rubiksCube;
    PatternDatabase<T> patternDatabase;
    vector<RubiksCube::MOVE> moves;
    unordered_map<T, RubiksCube::MOVE, H> move_done;
    unordered_map<T, bool ,H> visited;
    struct Node {
        T cube;
        int depth;
        int estimate;

        Node(T _cube, int _depth, int _estimate) : cube(_cube), depth(_depth), estimate(_estimate) {};
    };
    struct compareCube {
        bool operator() (pair<Node, int> const &p1, pair<Node, int> const &p2) {
            Node node1 = p1.first;
            Node node2 = p2.first;
            if (node1.depth+node1.estimate == node2.depth+node2.estimate) {
                return node1.estimate > node2.estimate;
             } else {
                 node1.depth+node1.estimate > node2.depth+node2.estimate;
             }
        }
    };
    void resetStructure() {
        moves.clear();
        move_done.clear();
        visited.clear();
    }

    /*
     *  Returns {solved_cube, bound} : if the cube is solved
     *  Returns {rubiksCube, next_bound} : if the cube was not solved
     */
    pair<T, int> IDAstar(int bound) {
        // priority_queue contains pair(Node, move_done to reach that Node)
        priority_queue<pair<Node, int>, vector<pair<Node, int>>, compareCube> pq;
        Node start = Node(rubiksCube, 0, patternDatabase.getEstimate(rubiksCube));
        pq.push(make_pair(start, 0));
        int next_bound = 100;
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            Node node = p.first;

            if (visited[node.cube]) continue;
            visited[node.cube] = true;
            move_done[node.cube] = RubiksCube::MOVE(p.second);

            if (node.cube.isSolved()) return make_pair(node.cube, bound);
            node.depth++;
            for (int i=0; i<18; i++) {
                auto cur_move = RubiksCube::MOVE(i);
                node.cube.move(cur_move);
                if (!visited[node.cube]) {
                    node.estimate = patternDatabase.getEstimate(node.cube);
                    if (node.estimate+node.depth > bound) {
                        next_bound = min(next_bound, node.estimate+node.depth);
                    } else {
                        pq.push(make_pair(node, i));
                    }
                }
                node.cube.invert(cur_move);
            }
        }
        return make_pair(rubiksCube, next_bound);
    }

public:



    IDAstarSolver(T _rubiksCube) {
        rubiksCube = _rubiksCube;
    }

    vector<RubiksCube::MOVE> solve() {
        int bound = 1;
        auto p = IDAstar(bound);
        while (p.second != bound) {
            resetStructure();
            bound = p.second;
            p = IDAstar(bound);
        }
        T solvedCube = p.first;
        assert(solvedCube.isSolved());
        T currentCube = solvedCube;
        while (currentCube != rubiksCube) {
            RubiksCube::MOVE currentMove = move_done[currentCube];
            moves.push_back(currentMove);
            currentCube.invert(currentMove);
        }
        rubiksCube = solvedCube;
        reverse(moves.begin(), moves.end());
        return moves;
    }

    void printSolvedRubiksCube() {
        rubiksCube.print();
    }
};


#endif //IDASTARSOLVER_H
