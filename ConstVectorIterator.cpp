#include "ConstVectorIterator.h"
#include "BaseVector.h"

Matrix::ConstVectorIterator::ConstVectorIterator(const ConstBaseVector *vector, int pos){
    //create a ConstVectorIterator over the specified vector starting at the specified position
    this->vector = vector;
    this->pos = pos;
}

const Matrix::ConstVectorIterator::value_type& Matrix::ConstVectorIterator::operator*() const {
    // returns a reference to the element you are at
    // at() returns a reference to the element at pos n in the vector
    return this->vector->at(this->pos);
}

const Matrix::ConstVectorIterator::value_type& Matrix::ConstVectorIterator::operator[](int offset) const {
    //return a reference to the element offset past your current position
    return this->vector->at(this->pos + offset);
}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator++() {
    // move to the next element
    // pre fix increment
    this->pos++;
    return *this;
}

const Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator++(int) {
    // move to the next element
    // post fix increment
    const ConstVectorIterator currentIterator = *this;
    this->pos++;
    return currentIterator;
}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator--() {
    // move to the previous element
    // pre fix decrement
    this->pos--;
    return *this;
}

const Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator--(int) {
    // move to the previous element
    // post fix decrement
    const ConstVectorIterator currentIterator = *this;
    this->pos--;
    return currentIterator;
}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator+=(int amount) {
    // move forward amount of elements
    // gets position and adds amount
    // returns new pos
    this->pos += amount;
    return *this;
}

Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator+(int amount) const {
    // moves forward amount elements
    // doesn't increment, plain adds
    const int index = this->pos + amount;
    return this[index];
}

Matrix::ConstVectorIterator& Matrix::ConstVectorIterator::operator-=(int amount) {
    // moves backward amount elements
    // gets position and subtracts amount
    // returns new pos
    this->pos -= amount;
    return *this;
}

Matrix::ConstVectorIterator Matrix::ConstVectorIterator::operator-(int amount) const {
    // moves backward amount elements
    // doesn't decrement, plain subtracts
    const int index = this->pos - amount;
    return this[index];
}

Matrix::ConstVectorIterator::difference_type Matrix::ConstVectorIterator::operator-(const ConstVectorIterator& rhs) {
    //return the number of elements between yourself and rhs
    //for example if you were at element 10 and rhs was at element 7
    //the difference would be 3
    return rhs.pos - this->pos;
}

bool Matrix::ConstVectorIterator::operator==(const ConstVectorIterator& rhs) const {
    //you are equal to rhs if you are over the same vector
    //and at the same position
    return rhs.vector == this->vector && rhs.pos == this->pos;
}

bool Matrix::ConstVectorIterator::operator!=(const ConstVectorIterator& rhs) const {
    //you are equal to rhs if you are over the same vector
    //and at the same position
    return !(rhs.vector == this->vector && rhs.pos == this->pos);
}

bool Matrix::ConstVectorIterator::operator<(const ConstVectorIterator& rhs) const {
    //are you at an element before rhs?
    return this->pos < rhs.pos;
}

bool Matrix::ConstVectorIterator::operator<=(const ConstVectorIterator& rhs) const {
    //are you at an element before rhs?
    return this->pos <= rhs.pos;
}

bool Matrix::ConstVectorIterator::operator>(const ConstVectorIterator& rhs) const {
    //are you at an element after rhs?
    return this->pos > rhs.pos;
}

bool Matrix::ConstVectorIterator::operator>=(const ConstVectorIterator& rhs) const {
    //are you at an element after rhs?
    return this->pos >= rhs.pos;
}
