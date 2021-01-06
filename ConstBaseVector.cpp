#include "Vector.h"
#include "ConstBaseVector.h"

// An abstract class that contains all of the operations you can perform on a Vector without modifying it.

Matrix::ConstVectorIterator Matrix::ConstBaseVector::begin() const {
    // create a ConstVectorIterator over the specified vector starting at the specified position
    // returns pointer to new memory initialized by ConstVectorIterator at the beginning position
    return *new ConstVectorIterator(this, 0);
}

Matrix::ConstVectorIterator Matrix::ConstBaseVector::end() const {
    // create a ConstVectorIterator over the specified vector starting at the specified position
    // returns pointer to new memory initialized by ConstVectorIterator at the ending position
    return *new ConstVectorIterator(this, this->size());
}

Matrix::Vector Matrix::ConstBaseVector::operator-() const {
    // negation
    // creates a new vector that will store the negated vector
    // newVector allocates memory with the number of elements with the size of the orig
    // iterates through newVector and grabs element, multiplying by -1
    Vector newVector = *new Vector(this->size());
    for (int i = 0; i < this->size(); i++) {
        newVector[i] = (*this)[i] * -1;
    }
    return newVector;
}

Matrix::Vector Matrix::ConstBaseVector::operator+(const ConstBaseVector& rhs) {
    // vector addition
    // passes in a reference (not the copy, the original) of rhs, which will be another ConstBaseVector vector
    // allocates new memory for newVector and creates memory of that newVector with the necessary size
    // iterates through the size of the vector and adds the *this vector[i] and adds rhs[i]
    // returns the newVector that is a sum of the two vectors
    Vector newVector = *new Vector(this->size());
    for (int i = 0; i < this->size(); i++) {
        newVector[i] = (*this)[i] + rhs[i];
    }
    return newVector;
}

Matrix::Vector Matrix::ConstBaseVector::operator-(const ConstBaseVector& rhs) {
    // vector subtraction
    // passes in a reference (not the copy, the original) of rhs, which will be another ConstBaseVector vector
    // allocates new memory for newVector and creates memory of that newVector with the necessary size
    // iterates through the size of the vector and adds the *this vector[i] and subtracts rhs[i]
    // returns the newVector that is the difference of the two vectors
    Vector newVector = *new Vector(this->size());
    for (int i = 0; i < this->size(); i++) {
        newVector[i] = (*this)[i] - rhs[i];
    }
    return newVector;
}

Matrix::Vector Matrix::ConstBaseVector::operator*(const ConstBaseVector& rhs) const {
    // multiplies vector by vector i.e dot product
    // passes in a reference (not a copy, the original) of rhs, which will be another ConstBaseVector vector
    // allocates new memory for newVector and creates memory of that newVector with the necessary size
    // iterates through the size of the vector and multiplies the elements of this vector and &rhs vector
    int sumOfElements = 0;
    for (int i = 0; i < this->size(); i++) {
        //newVector[i] = (*this)[i] * rhs[i]; // returns a vector with n elements
        sumOfElements += (*this)[i] * rhs[i]; // adds elements into sum
        // expected has 1 element that is equal to 140
        // Actual: { 10, 40, 90 } (of type Matrix::Vector), which has 3 elements
    }
    return Vector(1,sumOfElements);
}

Matrix::Vector Matrix::ConstBaseVector::operator+(const ConstBaseVector::value_type& rhs) const {
    // vector plus scalar
    // value_type& rhs = scalar
    // passes in the reference of the rhs, which is the value_type, not the entire vector
    // allocates memory for Vector newVector with the same size as the Vector
    // iterates through the size of the vector and adds the individual elements of the vector (*this) with rhs, which is
    // value_type&, which is essentially the scalar
    // returns the newVector that is the sum of the value_type& rhs and the original vector
    Vector newVector = *new Vector(this->size());
    for (int i = 0; i < this->size(); i++) {
        newVector[i] = (*this)[i] + rhs;
    }
    return newVector;
}

Matrix::Vector Matrix::ConstBaseVector::operator-(const ConstBaseVector::value_type& rhs) const {
    // vector minus scalar
    // value_type& rhs = scalar
    // passes in the reference of the rhs, which is the value_type of the individual elements,
    // not the entire vector
    // allocates memory for Vector newVector with the same size as the Vector
    // iterates through the size of the vector and subtracts the individual elements of the vector (*this) by the
    // designated scalar
    // returns the newVector that is the sum of the value_type & rhs and the original vector
    Vector newVector = *new Vector(this->size());
    for (int i = 0; i < this->size(); i++) {
        newVector[i] = (*this)[i] - rhs;
    }
    return newVector;
}

Matrix::Vector Matrix::ConstBaseVector::operator*(const ConstBaseVector::value_type& rhs) const {
    // vector times scalar
    // value_type& rhs = scalar
    // passes in the reference of the rhs, which is the value type of the individual elements,
    // not the entire vector
    // allocates memory for Vector newVector with the same size as the Vector
    // iterates through the size of the vector and multiplies the individual element with the
    // designated scalar
    // returns the newVector that is the product of the value_type& and the original vector
    Vector newVector = *new Vector(this->size());
    for (int i = 0; i < this->size(); i++) {
        newVector[i] = (*this)[i] * rhs;
    }
    return newVector;
}

bool Matrix::ConstBaseVector::operator==(const ConstBaseVector& rhs) const {
    // operator ==
    // iterates through the size of the ConstBaseVector and checks to see if
    // the elements of the rhs and ConstBaseVector are the same
    // returns true if the elements inside the vector are the same
    // returns false if the elements int the vector are different at respected index
    for (int i = 0; i < this->size(); i++) {
        if ((*this)[i] != rhs[i])
            return false;
    }
    return true;
}

bool Matrix::ConstBaseVector::operator!=(const ConstBaseVector& rhs) const {
    // operator !=
    // iterates through the size of the ConstBaseVector and checks to see if
    // the elements of the rhs and ConstBaseVector are the same
    // returns true if the elements inside the vector are the same
    // returns false if the elements in the vector are different at respected index
    for (int i = 0; i < this->size(); i++) {
        if ((*this)[i] != rhs[i])
            return true;
    }
    return false;
}

Matrix::Vector Matrix::operator+(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs) {
    // scalar plus vector
    // passes in the vector rhs and subtracts by the left hand side, a value type
    return rhs + lhs;
}

Matrix::Vector Matrix::operator-(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs) {
    // scalar - vector
    return -(rhs -lhs);
}

Matrix::Vector Matrix::operator*(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs) {
    // scalar times vector
    return rhs * lhs;
}
