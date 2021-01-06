//
// Created by mfbut on 11/17/2019.
//

#include "ColumnIterator.h"
#include "ConstColumnIterator.h"
#include "Matrix.h"

//Create an column iterator over the specified matrix starting at the specified column
Matrix::ColumnIterator::ColumnIterator(Matrix* matrix, int col) {
    this->matrix = matrix;
    this->col = col;
}

//return a ConstColumnIterator that is over the same matrix and at the same position
Matrix::ColumnIterator::operator ConstColumnIterator() const {
    return *(new ConstColumnIterator(matrix, col));
}

//get a reference to the column you are at
Matrix::ConstVectorRef Matrix::ColumnIterator::operator*() const {
    return const_cast<const Matrix*>(matrix)->colAt(col);
}

//get a reference to the column you are at
Matrix::ColumnIterator::value_type Matrix::ColumnIterator::operator*() {
    return *(new VectorRef(*matrix, col));
}

//get a reference to a column offset past your current location
Matrix::ConstVectorRef  Matrix::ColumnIterator::operator[](int offset) const {
    return const_cast<const Matrix*>(matrix)->colAt(col + offset);
}

//get a reference to a column offset past your current location
Matrix::ColumnIterator::value_type Matrix::ColumnIterator::operator[](int offset) {
    return *(new VectorRef(matrix->rowAt(col + offset)));
}

//move to the next column
Matrix::ColumnIterator& Matrix::ColumnIterator::operator++() {
    col++;
    return *this;
}

//move to the next column
const Matrix::ColumnIterator Matrix::ColumnIterator::operator++(int) {
    const ColumnIterator iterator = *this;
    col++;
    return iterator;
}

//move to the previous column
Matrix::ColumnIterator& Matrix::ColumnIterator::operator--() {
    col--;
    return *this;
}

//move to the previous column
const Matrix::ColumnIterator Matrix::ColumnIterator::operator--(int) {
    const ColumnIterator iterator = *this;
    col--;
    return iterator;
}

//move forward amount columns
Matrix::ColumnIterator& Matrix::ColumnIterator::operator+=(int amount) {
    col += amount;
    return *this;
}

//move forward amount columns
Matrix::ColumnIterator Matrix::ColumnIterator::operator+(int amount) const {
    const int index = this->col + amount;
    return this[index];
}

//move backward amount columns
Matrix::ColumnIterator& Matrix::ColumnIterator::operator-=(int amount) {
    col -= amount;
    return *this;
}

//move backward amount columns
Matrix::ColumnIterator Matrix::ColumnIterator::operator-(int amount) const {
    const int index = this->col - amount;
    return this[index];
}
//return the number of columns between yourself and rhs
//for example if you were at column 10 and rhs was at column 7
//the difference would be 3
Matrix::ColumnIterator::difference_type Matrix::ColumnIterator::operator-(const ColumnIterator& rhs) {
    return rhs.col - this->col;
}

//you and rhs are equal if you are over the same matrix and
//at the same column
bool Matrix::ColumnIterator::operator==(const ColumnIterator& rhs) const {
    return rhs.matrix == this->matrix && rhs.col == this->col;
}
//you and rhs are equal if you are over the same matrix and
//at the same column
bool Matrix::ColumnIterator::operator!=(const ColumnIterator& rhs) const {
    return !(rhs.matrix == this->matrix && rhs.col == this->col);
}
//are you at a column before rhs?
bool Matrix::ColumnIterator::operator<(const ColumnIterator& rhs) const {
    return this->col < rhs.col;
}

//are you at a column before rhs?
bool Matrix::ColumnIterator::operator<=(const ColumnIterator& rhs) const {
    return this->col <= rhs.col;
}
//are you at a column after rhs?
bool Matrix::ColumnIterator::operator>(const ColumnIterator& rhs) const {
    return this->col > rhs.col;
}
//are you at a column after rhs?
bool Matrix::ColumnIterator::operator>=(const ColumnIterator& rhs) const {
    return this->col >= rhs.col;
}
