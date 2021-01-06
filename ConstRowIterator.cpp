//
// Created by mfbut on 11/17/2019.
//


#include "ConstRowIterator.h"
#include "Matrix.h"

//Create an row iterator over the specified Matrix starting at the specified row
Matrix::ConstRowIterator::ConstRowIterator(const Matrix* matrix, int row) {
    this->matrix = matrix;
    this->row = row;
}

//return a reference to the row you are on
Matrix::ConstRowIterator::value_type Matrix::ConstRowIterator::operator*() const {
    return *(new ConstVectorRef(matrix->rowAt(row)));
}

//return a reference to the row offset rows past your current position
Matrix::ConstRowIterator::value_type Matrix::ConstRowIterator::operator[](int offset) const {
    return *(new ConstVectorRef(matrix->rowAt(row + offset)));
}

//move forward one row
Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator++() {
    row++;
    return *this;
}

//move forward one row
const Matrix::ConstRowIterator Matrix::ConstRowIterator::operator++(int) {
    const ConstRowIterator iterator = *this;
    row++;
    return iterator;
}

//move backward one row
Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator--() {
    row--;
    return *this;
}

//move backward one row
const Matrix::ConstRowIterator Matrix::ConstRowIterator::operator--(int) {
    const ConstRowIterator iterator = *this;
    row--;
    return iterator;
}

//move forward amount rows
Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator+=(int amount) {
    row += amount;
    return *this;
}

//move forward amount rows
Matrix::ConstRowIterator Matrix::ConstRowIterator::operator+(int amount) const {
    const int index = this->row + amount;
    return this[index];
}

//move backward  rows
Matrix::ConstRowIterator& Matrix::ConstRowIterator::operator-=(int amount) {
    row -= amount;
    return *this;
}

//move backward  rows
Matrix::ConstRowIterator Matrix::ConstRowIterator::operator-(int amount) const {
    const int index = this->row - amount;
    return this[index];
}
//return the number of rows between yourself and rhs
//for example if you were at row 10 and rhs was at row 7
//the difference would be 3
Matrix::ConstRowIterator::difference_type Matrix::ConstRowIterator::operator-(const ConstRowIterator& rhs) {
    return rhs.row - this->row;
}
//you are equal to rhs if you are both over the same matrix
//and you are on the same row
bool Matrix::ConstRowIterator::operator==(const ConstRowIterator& rhs) const {
    return rhs.matrix == this->matrix && rhs.row == this->row;
}
//you are equal to rhs if you are both over the same matrix
//and you are on the same row
bool Matrix::ConstRowIterator::operator!=(const ConstRowIterator& rhs) const {
    return !(rhs.matrix == this->matrix && rhs.row == this->row);
}

//are you at a row before rhs?
bool Matrix::ConstRowIterator::operator<(const ConstRowIterator& rhs) const {
    return this->row < rhs.row;
}

//are you at a row before rhs?
bool Matrix::ConstRowIterator::operator<=(const ConstRowIterator& rhs) const {
    return this->row <= rhs.row;
}

//are you at a row after rhs?
bool Matrix::ConstRowIterator::operator>(const ConstRowIterator& rhs) const {
    return this->row > rhs.row;
}

//are you at a row after rhs?
bool Matrix::ConstRowIterator::operator>=(const ConstRowIterator& rhs) const {
    return this->row >= rhs.row;
}


