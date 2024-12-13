#include <iostream>
#include "model/RubiksCube3DArrayRepresentation.cpp"
using namespace std;
int main() {

    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    /*
     * Testing RubiksCube3DModel
     */
    RubiksCube3DArray rubiksCube3DArray;

    rubiksCube3DArray.print();
    if (rubiksCube3DArray.isSolved()) cout << "Cube is Solved!" << endl;
    else cout << "Cube is Not Solved!" << endl;

    rubiksCube3DArray.d();
    rubiksCube3DArray.print();
    if (rubiksCube3DArray.isSolved()) cout << "Cube is Solved!" << endl;
    else cout << "Cube is Not Solved!" << endl;



    return 0;
}
