//
// Created by mfbut on 11/17/2019.
//

#include "ConstVectorRef.h"
#include "Matrix.h"

Matrix::ConstVectorRef::ConstVectorRef(const ConstBaseVector& orig)  {
  elements.reserve(orig.size());
  for(auto& element : orig){
    //the const cast here allows us to remove the const from the const int*
    //so that we can place the int* into our vector
    //const_cast can be dangerous if used incorrectly but
    //can be very helpful when applied correctly
    //please don't use it in your own code until we cover it in class
    //or you read up on it.
    elements.push_back(const_cast<value_type*>(&element));
  }
}

Matrix::ConstVectorRef::ConstVectorRef(const Matrix& matrix, int col) {
  elements.reserve(matrix.getNumCols());
  for(const auto& row : matrix){
    //again with the const cast to discard the constness
    elements.push_back(const_cast<value_type*>(&row.at(col)));
  }
}

int Matrix::ConstVectorRef::size() const {
    // return the number of elements in the vector you refer to
    return elements.size();
}

const Matrix::ConstBaseVector::value_type& Matrix::ConstVectorRef::at(int index) const {
    // return a reference to the element at the position you refer to
    return *elements.at(index);
}

const Matrix::ConstBaseVector::value_type& Matrix::ConstVectorRef::operator[](int index) const {
    // return a reference to the element at the position you refer to
    return *elements[index];
}

