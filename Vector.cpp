#include "Vector.h"


Matrix::Vector::Vector(const ConstBaseVector& orig)  {
    //create a vector that contains the same elements as in orig
    //allocates space for the raw vector with the original size of the ConstBaseVector
    rawVector.reserve(orig.size());
    // iterates through the orig.size() and pushes back the element in the container of orig
    for (int i = 0; i < orig.size(); i++) {
        rawVector.push_back(orig.at(i));
    }
}

Matrix::Vector::Vector(int numElements, const BaseVector::value_type& value) {
    // create a vector that holds numElements and each element is value
    rawVector.reserve(numElements);
    for (int i = 0; i < numElements; i++) {
        rawVector.push_back(value);
    }
}

Matrix::Vector::Vector(int numElements) {
    // creates a vector that holds numElements 0's
    rawVector.reserve(numElements);
    for (int i = 0; i < numElements; i++) {
        rawVector.push_back(0);
    }
}

Matrix::Vector::Vector(const std::vector<value_type>& values) {
    // creates a vector that contains the specified values
    rawVector = values;
}

Matrix::Vector::Vector() {
    // creates a 1x1 vector with the value 0
    rawVector.reserve(1);
    rawVector.push_back(0);
}

int Matrix::Vector::size() const {
    // returns the number of elements in the vector
    return rawVector.size();
}

Matrix::BaseVector::value_type& Matrix::Vector::at(int index) {
    // return the element at the position
    return rawVector.at(index);
}

const Matrix::BaseVector::value_type& Matrix::Vector::at(int index) const {
    // return the element at the position
    return rawVector.at(index);
}

Matrix::BaseVector::value_type& Matrix::Vector::operator[](int index) {
    // return the element at the position
    return rawVector[index];
}

const Matrix::BaseVector::value_type& Matrix::Vector::operator[](int index) const {
    // return the element at the position
    return rawVector[index];
}

Matrix::Vector& Matrix::Vector::operator=(const ConstBaseVector& rhs) {
    // assignment operator
    // make all of the elements in this vector the same
    // as what is in rhs. adjust the size of this vector if necessary
    rawVector.clear();
    rawVector.reserve(rhs.size());
    for (int i = 0; i < rhs.size(); i++) {
        rawVector.push_back(rhs[i]);
    }
    return *this;
}









