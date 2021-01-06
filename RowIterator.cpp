//
// Created by mfbut on 11/17/2019.
//

#include "RowIterator.h"
#include "Matrix.h"

//create a RowIterator over the specified matrix starting at the specified row
Matrix::RowIterator::RowIterator(Matrix* matrix, int row)  {
    this->matrix = matrix;
    this->row = row;
}

//return a ConstRowIterator over the same matrix and at the same row
Matrix::RowIterator::operator ConstRowIterator() const {
    return *(new ConstRowIterator(matrix, row));
}

//return a reference to the row that you are on
Matrix::ConstVectorRef Matrix::RowIterator::operator*() const {
  //make sure that we call the const at method on matrix
  return const_cast<const Matrix*>(matrix)->rowAt(row);
}

//return a reference to the row offset past your current row
Matrix::ConstVectorRef Matrix::RowIterator::operator[](int offset) const {
  //make sure that we call the const at method on matrix
  return const_cast<const Matrix*>(matrix)->rowAt(row + offset);
}

//return a reference to the row that you are on
Matrix::RowIterator::value_type Matrix::RowIterator::operator*() {
    return *(new VectorRef(matrix->rowAt(row)));
}

//return a reference to the row offset past your current row
Matrix::RowIterator::value_type Matrix::RowIterator::operator[](int offset) {
    return *(new VectorRef(matrix->rowAt(row + offset)));
}

//move to the next row
Matrix::RowIterator& Matrix::RowIterator::operator++() {
    row++;
    return *this;
}

//move to the next row
const Matrix::RowIterator Matrix::RowIterator::operator++(int) {
    const RowIterator iterator = *this;
    row++;
    return iterator;
}

//move to the previous row
Matrix::RowIterator& Matrix::RowIterator::operator--() {
    row--;
    return *this;
}

//move to the previous row
const Matrix::RowIterator Matrix::RowIterator::operator--(int) {
    const RowIterator iterator = *this;
    row--;
    return iterator;
}

//move forward amount rows
Matrix::RowIterator& Matrix::RowIterator::operator+=(int amount) {
    row += amount;
    return *this;
}

//move forward amount rows
Matrix::RowIterator Matrix::RowIterator::operator+(int amount) const {
    const int index = this->row + amount;
    return this[index];
}

//move backward amount rows
Matrix::RowIterator& Matrix::RowIterator::operator-=(int amount) {
    row -= amount;
    return *this;
}

//move backward amount rows
Matrix::RowIterator Matrix::RowIterator::operator-(int amount) const {
    const int index = this->row - amount;
    return this[index];
}

//return the number of rows between yourself and rhs
//for example if you were at row 10 and rhs was at row 7
//the difference would be 3
Matrix::RowIterator::difference_type Matrix::RowIterator::operator-(const RowIterator& rhs) {
    return rhs.row - this->row;
}

//you are equal to rhs if you are both over the same matrix
//and you are on the same row
bool Matrix::RowIterator::operator==(const RowIterator& rhs) const {
    return (rhs.matrix == this->matrix) && (rhs.row == this->row);
}
//you are equal to rhs if you are both over the same matrix
//and you are on the same row
bool Matrix::RowIterator::operator!=(const RowIterator& rhs) const {
    return !(rhs.matrix == this->matrix && rhs.row == this->row);
}

//are you at a row before rhs?
bool Matrix::RowIterator::operator<(const RowIterator& rhs) const {
    return this->row < rhs.row;
}

//are you at a row before rhs?
bool Matrix::RowIterator::operator<=(const RowIterator& rhs) const {
    return this->row <= rhs.row;
}

//are you at a row after rhs?
bool Matrix::RowIterator::operator>(const RowIterator& rhs) const {
    return this->row > rhs.row;
}

//are you at a row after rhs?
bool Matrix::RowIterator::operator>=(const RowIterator& rhs) const {
    return this->row >= rhs.row;
}
