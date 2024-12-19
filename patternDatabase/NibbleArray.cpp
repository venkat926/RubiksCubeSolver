

#include "NibbleArray.h"
using namespace std;

NibbleArray::NibbleArray(const size_t _size, const uint8_t _val) : size(_size), arr(size/2+1, _val) {
}

uint8_t NibbleArray::get(const size_t index) const {
    size_t i = index / 2;
    assert(index <= this->size);
    uint8_t val = this->arr[i];

    // odd position: last 4 bits
    if (index&1) {
        return val & 0x0F;
    } else { // even position: 4 bits from left
        return val >> 4;
    }
}

void NibbleArray::set(const size_t index, const uint8_t val) {
    size_t i = index / 2;
    uint8_t currVal = this->arr[i];
    assert(index <= this->size);

    // odd position: last 4 bits
    if (index&1) {
        this->arr[i] = (currVal & 0xF0) | (val & 0x0F);
    } else { // even position: 4 bits from left
        this->arr[i] = (currVal & 0x0F) | (val & 0xF0);
    }
}

//Get pointer to underlying array
uint8_t* NibbleArray::data() {
    return this->arr.data();
}

const uint8_t* NibbleArray::data() const {
    return this->arr.data();
}

// Move all the moves to a vector. This doubles the size, but is faster to access,
// since there is no bitwise operation needed.

void NibbleArray::inflate(vector<uint8_t> &dest) const {
    dest.reserve(this->size);

    for (unsigned i = 0; i < this->size; ++i)
        dest.push_back(this->get(i));
}

// Reset the array
void NibbleArray::reset(const uint8_t val) {
    fill(this->arr.begin(), this->arr.end(), val);
}

