//
// Created by mfbut on 11/17/2019.
//

#include "ConstColumnIterator.h"
#include "Matrix.h"

//Create an column iterator over the specified Matrix starting at the specified column
Matrix::ConstColumnIterator::ConstColumnIterator(const Matrix* matrix, int col) {
    this->matrix = matrix;
    this->col = col;
}


//return a reference to the column you are at
Matrix::ConstColumnIterator::value_type Matrix::ConstColumnIterator::operator*() const {
    return *(new ConstVectorRef(matrix->rowAt(col)));
}

//return a reference to the column offset columns from your current position
Matrix::ConstColumnIterator::value_type Matrix::ConstColumnIterator::operator[](int offset) const {
    return *(new ConstVectorRef(matrix->rowAt(col + offset)));
}

//move to the next column
Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator++() {
    col++;
    return *this;
}

//move to the next column
const Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator++(int) {
    const ConstColumnIterator iterator = *this;
    col++;
    return iterator;
}
//move backward amount columns
Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator--() {
    col --;
    return *this;
}

//move backward amount columns
const Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator--(int) {
    const ConstColumnIterator iterator = *this;
    col--;
    return iterator;
}

//move forward amount columns
Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator+=(int amount) {
    col += amount;
    return *this;
}

//move forward amount columns
Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator+(int amount) const {
    const int index = this->col + amount;
    return this[index];
}
//move backward amount columns
Matrix::ConstColumnIterator& Matrix::ConstColumnIterator::operator-=(int amount) {
    col -= amount;
    return *this;
}

//move backward amount columns
Matrix::ConstColumnIterator Matrix::ConstColumnIterator::operator-(int amount) const {
    const int index = this->col - amount;
    return this[index];
}

//return the number of columns between yourself and rhs
//for example if you were at column 10 and rhs was at column 7
//the difference would be 3
Matrix::ConstColumnIterator::difference_type Matrix::ConstColumnIterator::operator-(const ConstColumnIterator& rhs) {
    return rhs.col - this->col;
}
//you and rhs are equal if you are over the same matrix and
//at the same column
bool Matrix::ConstColumnIterator::operator==(const ConstColumnIterator& rhs) const {
    return rhs.matrix == this->matrix && rhs.col == this->col;
}

//you and rhs are equal if you are over the same matrix and
//at the same column
bool Matrix::ConstColumnIterator::operator!=(const ConstColumnIterator& rhs) const {
    return !(rhs.matrix == this->matrix && rhs.col == this->col);
}

//are you at a column before rhs?
bool Matrix::ConstColumnIterator::operator<(const ConstColumnIterator& rhs) const {
    return this-> col < rhs.col;
}

//are you at a column before rhs?
bool Matrix::ConstColumnIterator::operator<=(const ConstColumnIterator& rhs) const {
    return this->col <= rhs.col;
}

//are you at a column after rhs?
bool Matrix::ConstColumnIterator::operator>(const ConstColumnIterator& rhs) const {
    return this->col > rhs.col;
}

//are you at a column after rhs?
bool Matrix::ConstColumnIterator::operator>=(const ConstColumnIterator& rhs) const {
    return this->col >= rhs.col;
}

