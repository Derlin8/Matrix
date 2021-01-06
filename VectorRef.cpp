#include "VectorRef.h"
#include "Matrix.h"

Matrix::VectorRef::VectorRef(BaseVector& orig) : ConstVectorRef(orig) {
    //create a reference to the given vector
}
Matrix::VectorRef::VectorRef(Matrix& matrix, int col) : ConstVectorRef(matrix, col) {
    //create a reference to the given vector
}
int Matrix::VectorRef::size() const {
    //return the number of elements in the vector it refers to
    return elements.size();
}

Matrix::BaseVector::value_type& Matrix::VectorRef::at(int index) {
    //element access
    return *elements.at(index);
}

const Matrix::BaseVector::value_type& Matrix::VectorRef::at(int index) const {
    //element access
    return *elements.at(index);
}

Matrix::BaseVector::value_type& Matrix::VectorRef::operator[](int index) {
    //element access
    return *elements[index];
}

const Matrix::BaseVector::value_type& Matrix::VectorRef::operator[](int index) const {
    //element access
    return *elements[index];
}

Matrix::VectorRef& Matrix::VectorRef::operator=(const BaseVector& rhs) {
    //set the value of each element that we refer to
    //equal to the value at the corresponding position in rhs
    for (int i = 0; i < rhs.size(); i++) {
        *elements.at(i) = rhs.at(i);
    }
    return *this;
}
