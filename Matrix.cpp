//
// Created by mfbut on 11/14/2019.
//

#include <algorithm>
#include <functional>
#include "Matrix.h"

Matrix::Matrix::Matrix(int numRows, int numCols, const Matrix::Matrix::element_type& val) {
    //create a numRows X numCols Matrix where all of the elements are val
    this->numColumns = numCols;
    this->numRows = numRows;
    // iterates over the numRow, which will be the first element in each col
    for (int i = 0; i < numRows; i++) {
        auto vector = new Vector(numCols, val);
        this->matrix.push_back(*vector);
    }
}

Matrix::Matrix::Matrix(int numRows, int numCols) {
    //create a numRows X numCols Matrix where all of the elements are 0
    this->numColumns = numCols;
    this->numRows = numRows;
    for (int i = 0; i < numRows; i++) {
        auto vector = new Vector(numCols, 0);
        this->matrix.push_back(*vector);
    }
}

Matrix::Matrix::Matrix(const std::vector<std::vector<element_type>>& values) {
    // sets the numRows, which is the height to equal the numSize of the matrix
    this->numRows = values.size();
    for (unsigned long i = 0; i < values.size(); i++) {
        // overrides the numColumns, which will equal the the width, numColumns
        this->numColumns = values[i].size();
        this->matrix.push_back(*(new Vector(values[i])));
    }
//    for (auto it = values.begin(); it != values.end(); it++) {
//        this->numColumns = (*it).size();
//        this->matrix.push_back(* new Vector(*it));
//    }
}

Matrix::Matrix::Matrix(const std::vector<Vector>& values) {
    this->numRows = values.size();
    this->numColumns = values[0].size();
    this->matrix = values;
}

Matrix::Matrix::Matrix(const std::vector<ConstVectorRef>& values) {
    this->numRows = values.size();
    for (unsigned long i = 0; i < values.size(); i++) {
        this->numColumns = values[i].size();
        Vector* vector = new Vector(values[i]);
        this->matrix.push_back(*vector);
    }
}

Matrix::Matrix::Matrix(const std::vector<VectorRef>& values) {
    this-> numRows = values.size();
    for (unsigned long i = 0; i < values.size(); i++) {
        this->numColumns = values[i].size();
        Vector* vector = new Vector(values[i]);
        this->matrix.push_back(*vector);
    }
}

Matrix::Matrix Matrix::Matrix::ident(int dim) { // done
    Matrix* identity = new Matrix(dim, dim);
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (i == j) {
                identity->rowAt(i)[j] = 1;
            }
        }
    }
    return *identity;
}

int Matrix::Matrix::getNumRows() const {
    return numRows;
}

int Matrix::Matrix::getNumCols() const {
    return numColumns;
}

Matrix::Matrix::element_type& Matrix::Matrix::at(int row, int col) {
    //element access
    return matrix.at(row).at(col);
}

const Matrix::Matrix::element_type& Matrix::Matrix::at(int row, int col) const {
    //element access
    return matrix.at(row).at(col);
}

Matrix::VectorRef Matrix::Matrix::rowAt(int row) {
    //get a reference to the specified row
    return *(new VectorRef(matrix.at(row)));
}

 Matrix::ConstVectorRef Matrix::Matrix::rowAt(int row) const {
     //get a reference to the specified row
     return *new ConstVectorRef(matrix.at(row));
}

Matrix::VectorRef Matrix::Matrix::colAt(int col) {
    //get a reference to the specified column
    return *new VectorRef(*this,col);
}

Matrix::ConstVectorRef Matrix::Matrix::colAt(int col) const {
    //get a reference to the specified column
    return *new ConstVectorRef(*this, col);
}

Matrix::VectorRef Matrix::Matrix::operator[](int row) {
    //get a reference to the specified row
    return *new VectorRef(matrix[row]);
}

Matrix::ConstVectorRef Matrix::Matrix::operator[](int row) const {
    //get a reference to the specified row
    return *new ConstVectorRef(matrix.at(row));
}

Matrix::Matrix::const_iterator Matrix::Matrix::begin() const {
    //const iterators. go through the matrix by row
    return *(new ConstRowIterator(this, 0));
}

Matrix::Matrix::const_iterator Matrix::Matrix::end() const {
    //const iterators. go through the matrix by row
    return *(new ConstRowIterator(this, matrix.size()));
}

Matrix::Matrix::iterator Matrix::Matrix::begin() {
    //iterators. go through the matrix by row
    return *(new RowIterator(this, 0));
}

Matrix::Matrix::iterator Matrix::Matrix::end() {
    //iterators. go through the matrix by row
    return *(new RowIterator(this, matrix.size()));
}

Matrix::Matrix::const_row_iterator Matrix::Matrix::rowBegin() const {
    //explicit const row iterators
    return *(new ConstRowIterator(this, 0));
}

Matrix::Matrix::const_row_iterator Matrix::Matrix::rowEnd() const {
    //explicit const row iterators
    return *(new ConstRowIterator(this, matrix.size()));
}

Matrix::Matrix::row_iterator Matrix::Matrix::rowBegin() {
    //explicit row iterators
    return *(new RowIterator(this, 0));
}

Matrix::Matrix::row_iterator Matrix::Matrix::rowEnd() {
    //explicit row iterators
    return *(new RowIterator(this, matrix.size()));
}

Matrix::Matrix::const_column_iterator Matrix::Matrix::colBegin() const {
    //explicit const column iterators
    return *(new ConstColumnIterator(this, 0));
}

Matrix::Matrix::const_column_iterator Matrix::Matrix::colEnd() const {
    //explicit const column iterators
    return *(new ConstColumnIterator(this, numColumns));
}

Matrix::Matrix::column_iterator Matrix::Matrix::colBegin() {
    //explicit column iterators
    return *(new ColumnIterator(this, 0));
}

Matrix::Matrix::column_iterator Matrix::Matrix::colEnd() {
    //explicit column iterators
    return *(new ColumnIterator(this, numColumns));
}

Matrix::Matrix Matrix::Matrix::operator-() const{
    //negate
    Matrix neg = *this;
    for (int i = 0; i != neg.getNumRows(); ++i) {
        for (int j = 0; j != neg.getNumCols(); ++j) {
            neg.at(i, j) = -neg.at(i, j);
        }
    }
    return neg;
}

Matrix::Matrix& Matrix::Matrix::operator+=(const Matrix& rhs) {
    //Matrix + Matrix
    for (int i = 0; i != this->getNumRows(); ++i) {
        for (int j = 0; j != this->getNumCols(); ++j) {
            this->at(i, j) += rhs.at(i, j);
        }
    }
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator+(const Matrix& rhs) {
    //Matrix + Matrix
    Matrix currentMatrix = *new Matrix(*this);
    auto currentMatrixIt = currentMatrix.begin();
    auto rhsIt = rhs.begin();
    for (auto it = this->begin(); it!= this->end(); it++) {
        for (int i = 0; i < currentMatrix.getNumCols(); i++) {
            (*currentMatrixIt).at(i) = (*it).at(i) + (*rhsIt).at(i);
//            for (int j = 0; j < currentMatrix.getNumCols(); j++) {
//                currentMatrix[i][j] += rhs[i][j];
//            }
        }
        currentMatrixIt++;
        rhsIt++;
    }
    return currentMatrix;
}

Matrix::Matrix& Matrix::Matrix::operator-=(const Matrix& rhs) {
    //Matrix - Matrix
    for (int i = 0; i != this->getNumRows(); ++i) {
        for (int j = 0; j != this->getNumCols(); ++j) {
            this->at(i, j) -= rhs.at(i, j);
        }
    }
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator-(const Matrix& rhs) {
    //Matrix - Matrix
    Matrix currentMatrix = *new Matrix(*this);
    auto currentMatrixIt = currentMatrix.begin();
    auto rhsIt = rhs.begin();
    for (auto it = this->begin(); it!= this->end(); it++) {
        for (int i = 0; i < currentMatrix.getNumCols(); i++) {
            (*currentMatrixIt).at(i) = (*it).at(i) - (*rhsIt).at(i);
        }
        currentMatrixIt++;
        rhsIt++;
    }
    return currentMatrix;
}

Matrix::Matrix& Matrix::Matrix::operator*=(const Matrix& rhs) {
    // matrix * matrix
//    for (int i = 0; i != this->getNumRows(); ++i) {
//        for (int j = 0; j != rhs.getNumCols(); ++j) {
//            this->at(i,j) = (this->rowAt(i) * rhs.colAt(j)).at(0);
//        }
//    }
//    numColumns = rhs.getNumCols();
//    return *this;
    std::vector<Vector> values;
    for (int i = 0; i != this->getNumRows(); ++i) {
        std::vector<element_type> inner_vector;
        for (int j = 0; j != rhs.getNumCols(); ++j) {
            inner_vector.push_back((this->rowAt(i) * rhs.colAt(j)).at(0));
        }
        values.push_back(*new Vector(inner_vector));
    }
    this->matrix = values;
    numColumns = rhs.getNumCols();
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator*(const Matrix& rhs) {
    // matrix * matrix
    Matrix currentMatrix = *new Matrix(this->getNumRows(), rhs.getNumCols());
//    auto currentMatrixIt = currentMatrix.begin();
//    for (auto it = this->begin(); it != this->end(); it++) {
//        for (int i = 0; i < rhs.getNumCols(); i++) {
//            (*currentMatrixIt).at(i) = ((*it) * (rhs)).at(0);
//        }
//        currentMatrixIt++;
//        rhsIt++;
//    }
    for (int i = 0; i < this->getNumRows(); i++) {
        for (int j = 0; j < rhs.getNumCols(); j++) {
            element_type dotProduct = (this->rowAt(i) * rhs.colAt(j)).at(0);
            currentMatrix.at(i, j) = dotProduct;
        }
    }
    return currentMatrix;
}

Matrix::Matrix& Matrix::Matrix::operator+=(const element_type& rhs) {
    //Matrix + scalar

    for (auto it = this->begin(); it != this->end(); it++) {
        *it += rhs;
    }
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator+(const element_type& rhs) const {
    //Matrix + scalar
    Matrix currentMatrix = *new Matrix(this->getNumRows(), this->getNumCols());
    auto currentMatrixIt = currentMatrix.begin();
    for (auto it = this->begin(); it != this->end(); it++) {
        for (int i = 0; i < (*it).size(); i++) {
            (*currentMatrixIt).at(i) = (*it).at(i) + rhs;
        }
        currentMatrixIt++;
    }
    return currentMatrix;
}

Matrix::Matrix& Matrix::Matrix::operator-=(const element_type& rhs) {
    //Matrix - scalar
    for (auto it = this->begin(); it != this->end(); it++) {
        *it -= rhs;
    }
    return *this;

}

Matrix::Matrix Matrix::Matrix::operator-(const element_type& rhs) const{
    //Matrix - scalar
    Matrix currentMatrix = *new Matrix(this->getNumRows(), this->getNumCols());
    auto currentMatrixIt = currentMatrix.begin();
    for (auto it = this->begin(); it != this->end(); it++) {
        for (int i = 0; i < (*it).size(); i++) {
            (*currentMatrixIt).at(i) = (*it).at(i) - rhs;
        }
        currentMatrixIt++;
    }
    return currentMatrix;

    // vector - scalar
    /*Vector newVector = *new Vector(this->size());
    for (int i = 0; i < this->size(); i++) {
        newVector[i] = (*this)[i] - rhs;
    }
    return newVector;*/
}

Matrix::Matrix& Matrix::Matrix::operator*=(const element_type& rhs) {
    //Matrix * scalar
    for (auto it = this->begin(); it != this->end(); it++) {
        *it *= rhs;
    }
    return *this;
}

Matrix::Matrix Matrix::Matrix::operator*(const element_type& rhs) const{
    //Matrix * scalar
    Matrix currentMatrix = *new Matrix(this->getNumRows(), this->getNumCols());
    auto currentMatrixIt = currentMatrix.begin();
    for (auto it = this->begin(); it != this->end(); it++) {
        for (int i = 0; i < (*it).size(); i++) {
            (*currentMatrixIt).at(i) = (*it).at(i) * rhs;
        }
        currentMatrixIt++;
    }
    return currentMatrix;
}


Matrix::Matrix Matrix::operator+(const Matrix::element_type& lhs, const Matrix& rhs) {
    //scalar + Matrix
    return rhs + lhs;
}

Matrix::Matrix Matrix::operator-(const Matrix::element_type& lhs, const Matrix& rhs) {
    //scalar - Matrix
    return -(rhs - lhs);
}

Matrix::Matrix Matrix::operator*(const Matrix::element_type& lhs, const Matrix& rhs) {
    //scalar * Matrix
    return rhs * lhs;
}




