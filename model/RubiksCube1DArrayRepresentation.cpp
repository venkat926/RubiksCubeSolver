
#include "RubiksCube.h"

class RubiksCube1DArray : public RubiksCube {
private:
     static inline int getIndex(int idx, int row, int col) {
        return idx*9 + row*3 + col;
    }
    void rotateFace(int idx) {
        char temp_arr[9] = {};
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                temp_arr[i*3 + j] = cube[getIndex(idx, i, j)];
            }
        }

        for (int i=0; i<3; i++) cube[getIndex(idx, 0, i)] = temp_arr[getIndex(0, 2-i, 0)];
        for (int i=0; i<3; i++) cube[getIndex(idx, i, 2)] = temp_arr[getIndex(0, 0, i)];
        for (int i=0; i<3; i++) cube[getIndex(idx, 2, 2-i)] = temp_arr[getIndex(0, i, 2)];
        for (int i=0; i<3; i++) cube[getIndex(idx, 2-i, 0)] = temp_arr[getIndex(0, 2, 2-i)];

    }
public:
    char cube[54] = {};

    RubiksCube1DArray() {
        for (int i=0; i<6; i++) {
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    cube[getIndex(i, j, k)] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[getIndex((int)face, (int)row, (int)col)];
        COLOR resColor = {};
        switch (color) {
            case 'W' : resColor = COLOR::WHITE; break;
            case 'G' : resColor = COLOR::GREEN; break;
            case 'R' : resColor = COLOR::RED; break;
            case 'B' : resColor = COLOR::BLUE; break;
            case 'O' : resColor = COLOR::ORANGE; break;
            case 'Y' : resColor = COLOR::YELLOW; break;
        }
        return resColor;
    }

    bool isSolved() const override {
        for (int i=0; i<6; i++) {
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    if (this->cube[getIndex(i, j, k)] != getColorLetter(COLOR(i))) return false;
                }
            }
        }
        return true;
    }

    RubiksCube &u() override {
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i=0; i<3; i++) temp_arr[i] = cube[getIndex(4, 0, 2-i)];
        for (int i=0; i<3; i++) cube[getIndex(4, 0, 2-i)] = cube[getIndex(1, 0, 2-i)];
        for (int i=0; i<3; i++) cube[getIndex(1, 0, 2-i)] = cube[getIndex(2, 0, 2-i)];
        for (int i=0; i<3; i++) cube[getIndex(2, 0, 2-i)] = cube[getIndex(3, 0, 2-i)];
        for (int i=0; i<3; i++) cube[getIndex(3, 0, 2-i)] = temp_arr[i];

        return *this;
    }
    RubiksCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }
    RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    }


    RubiksCube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i=0; i<3; i++) temp_arr[i] = cube[getIndex(0, i, 0)];
        for (int i=0; i<3; i++) cube[getIndex(0, i, 0)] = cube[getIndex(4, 2-i, 2)];
        for (int i=0; i<3; i++) cube[getIndex(4, 2-i, 2)] = cube[getIndex(5,  i, 0)];
        for (int i=0; i<3; i++) cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
        for (int i=0; i<3; i++) cube[getIndex(2, i, 0)] = temp_arr[i];

        return *this;
    }
    RubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }
    RubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i=0; i<3; i++) temp_arr[i] = cube[getIndex(0, 2, i)];
        for (int i=0; i<3; i++) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2-i, 2)];
        for (int i=0; i<3; i++) cube[getIndex(1, 2-i, 2)] = cube[getIndex(5, 0, 2-i)];
        for (int i=0; i<3; i++) cube[getIndex(5, 0, 2-i)] = cube[getIndex(3, i, 0)];
        for (int i=0; i<3; i++) cube[getIndex(3, i, 0)] = temp_arr[i];

        return *this;
    }
    RubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }
    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2, i)] = temp_arr[i];

        return *this;
    }

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const RubiksCube1DArray &r1) const {
        for (int i = 0; i < 54; i++) if (cube[i] != r1.cube[i]) return false;
        return true;
    }
    RubiksCube1DArray &operator=(const RubiksCube1DArray &r1) {
        for (int i = 0; i < 54; i++) cube[i] = r1.cube[i];
        return *this;
    }
};