
#include "VectorIterator.h"
#include "ConstColumnIterator.h"

Matrix::VectorIterator::VectorIterator(BaseVector* vector, int pos) {
    //create an iterator over the given vector starting at the specified position
    this->vector = vector;
    this->pos = pos;
}

Matrix::VectorIterator::operator ConstVectorIterator() const {
    //conversion to a ConstVectorIterator
    return *new ConstVectorIterator(this->vector, this->pos);
}

Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator*() {
    //return the element that you are at
    return this->vector->at(this->pos);
}

const Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator*() const {
    //return the element that you are at
    return this->vector->at(this->pos);
}

const Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator[](int offset) const {
    //return the element offset elements away from your current position
    return this->vector->at(this->pos + offset);
}

Matrix::VectorIterator::value_type& Matrix::VectorIterator::operator[](int offset) {
    //return the element offset elements away from your current position
    return this->vector->at(this->pos + offset);
}

Matrix::VectorIterator& Matrix::VectorIterator::operator++() {
    // go to the next element
    // pre fix increment
    this->pos++;
    return *this;
}

const Matrix::VectorIterator Matrix::VectorIterator::operator++(int) {
    const VectorIterator iterator = *this;
    // go to the next element
    // post fix increment
    this->pos++;
    return iterator;
}

Matrix::VectorIterator& Matrix::VectorIterator::operator--() {
    // go to the previous element
    // pre fix decrement
    this->pos--;
    return *this;
}

const Matrix::VectorIterator Matrix::VectorIterator::operator--(int) {
    // go to the previous element
    // post fix decrement
    const VectorIterator iterator = *this;
    this->pos--;
    return iterator;
}

Matrix::VectorIterator& Matrix::VectorIterator::operator+=(int amount) {
    //move amount elements forward
    this->pos += amount;
    return *this;
}

Matrix::VectorIterator Matrix::VectorIterator::operator+(int amount) const {
    //move amount elements forward
    const int index = this->pos + amount;
    return this[index];
}

Matrix::VectorIterator& Matrix::VectorIterator::operator-=(int amount) {
    //move amount elements backwards
    this->pos -= amount;
    return *this;
}

Matrix::VectorIterator Matrix::VectorIterator::operator-(int amount) const {
    //move amount elements backwards
    const int index = this->pos - amount;
    return this[index];
}

Matrix::VectorIterator::difference_type Matrix::VectorIterator::operator-(const VectorIterator& rhs) {
    //return the number of elements between yourself and rhs
    //for example if you were at element 10 and rhs was at element 7
    //the difference would be 3
    return rhs.pos - this->pos;
}

bool Matrix::VectorIterator::operator==(const VectorIterator& rhs) const {
    //true if both this and rhs are over the same vector and at the same element
    return rhs.vector == this->vector && rhs.pos == this->pos;
}

bool Matrix::VectorIterator::operator!=(const VectorIterator& rhs) const {
    //true if both this and rhs are over the same vector and at the same element
    return !(rhs.vector == this->vector && rhs.pos == this->pos);
}

bool Matrix::VectorIterator::operator<(const VectorIterator& rhs) const {
    //are you at an element before rhs?
    return this->pos < rhs.pos;
}

bool Matrix::VectorIterator::operator<=(const VectorIterator& rhs) const {
    //are you at an element before rhs?
    return this->pos <= rhs.pos;
}

bool Matrix::VectorIterator::operator>(const VectorIterator& rhs) const {
    //are you at an element after rhs?
    return this->pos > rhs.pos;
}

bool Matrix::VectorIterator::operator>=(const VectorIterator& rhs) const {
    //are you at an element after rhs?
    return this->pos >= rhs.pos;
}






