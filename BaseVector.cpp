//
// Created by mfbut on 11/14/2019.
//

#include "BaseVector.h"
#include "Vector.h"
#include "ConstVectorIterator.h"
#include "VectorIterator.h"
#include "Matrix.h"
Matrix::BaseVector::operator Matrix() const {
    std::vector<std::vector<value_type>> matrixInput;
    std::vector<value_type> firstRow;
    // allocates memory aka reserves space
    firstRow.reserve(size());
    for (int i = 0; i < size(); i++) {
        firstRow.push_back(at(i));
    }
    matrixInput.push_back(firstRow);
    return *(new Matrix(matrixInput));
}

Matrix::VectorIterator Matrix::BaseVector::begin() {
    // allocates memory for a pointer vectorIterator at pos 0, beg pos
    return *new VectorIterator(this, 0);
}

Matrix::VectorIterator Matrix::BaseVector::end() {
    // allocates memory for a pointer vectorIterator for BaseVector at last pos
    return *new VectorIterator(this, this->size());
}

Matrix::ConstVectorIterator Matrix::BaseVector::begin() const {
    // allocates memory for a pointer vectorIterator at pos 0, beg pos
    return *new ConstVectorIterator(this, 0);
}

Matrix::ConstVectorIterator Matrix::BaseVector::end() const {
    // allocates memory for a pointer vectorIterator for BaseVector at last pos
    return *new ConstVectorIterator(this, this->size());
}

Matrix::ConstVectorIterator Matrix::BaseVector::cbegin() const {
    // allocates memory for a pointer vectorIterator at pos 0, beg pos
    return *new ConstVectorIterator(this, 0);
}

Matrix::ConstVectorIterator Matrix::BaseVector::cend() const {
    // allocates memory for a pointer vectorIterator for BaseVector at last pos
    return *new ConstVectorIterator(this, this->size());
}

Matrix::BaseVector& Matrix::BaseVector::operator+=(const ConstBaseVector& rhs) {
    // vector += vector
    // iterates over rhs and adds each element at the index i
    // return the base vector
    for (int i = 0; i < this->size(); i++) {
        this->at(i) += rhs.at(i);
    }
    return *this;

}

Matrix::BaseVector& Matrix::BaseVector::operator-=(const ConstBaseVector& rhs) {
    // vector -= vector
    // iterates over rhs and adds each element at the index i
    // return the base vector
    for (int i = 0; i < rhs.size(); i++) {
        this->at(i) -= rhs.at(i);
    }
    return *this;
}

Matrix::BaseVector& Matrix::BaseVector::operator+=(const BaseVector::value_type& rhs) {
    // vector += scalar
    // iterates over the size of the current instance of vector
    // adds each element by the scalar
    // returns the base vector
    for (int i = 0; i < size(); i++) {
        this->at(i) += rhs;
    }
    return *this;
}

Matrix::BaseVector& Matrix::BaseVector::operator-=(const BaseVector::value_type& rhs) {
    // vector -= scalar
    // iterates over the size of the current instance of vector
    // adds each element by the scalar
    // returns the base vector
    for (int i = 0; i < size(); i++) {
        this->at(i) -= rhs;
    }
    return *this;
}

Matrix::BaseVector& Matrix::BaseVector::operator*=(const BaseVector::value_type& rhs) {
    // vector *= scalar
    // iterates over the size of the current instance of vector
    // multiplies each element by the respective scalar
    // returns the base vector
    for (int i = 0; i < size(); i++) {
        this->at(i) *= rhs;
    }
    return *this;
}












