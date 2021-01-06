//
// Created by mfbut on 11/14/2019.
//

#ifndef ECS_36B_HOMEWORK_MATRIX_H
#define ECS_36B_HOMEWORK_MATRIX_H
#include <vector>
#include "Vector.h"
#include "VectorRef.h"
#include "ConstVectorRef.h"
namespace Matrix {
  class RowIterator;
  class ConstRowIterator;
  class ColumnIterator;
  class ConstColumnIterator;
  class Matrix {
   public:

    using element_type = Vector::value_type;
    using value_type = Vector;
    using reference = VectorRef;
    using const_reference = ConstVectorRef;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using difference_type = int;

    using row_iterator = RowIterator;
    using const_row_iterator = ConstRowIterator;
    using column_iterator = ColumnIterator;
    using const_column_iterator = ConstColumnIterator;

    //by default we go through the rows
    using iterator = row_iterator;
    using const_iterator = const_row_iterator;

    Matrix(const Matrix& orig) = default;

    //create a numRows X numCols Matrix where all of the elements are val
    Matrix(int numRows, int numCols, const element_type& val);
    //create a numRows X numCols Matrix where all of the elements are 0
    Matrix(int numRows, int numCols);

    //create a matrix with the specified values
    explicit Matrix(const std::vector<std::vector<element_type>>& values);
    explicit Matrix(const std::vector<Vector>& values);
    explicit Matrix(const std::vector<ConstVectorRef>& values);
    explicit Matrix(const std::vector<VectorRef>& values);
    virtual ~Matrix() = default;

    //return an identity matrix that is dim X dim big
    //in the identity matrix all of the elements are 0 except for the ones
    //on the main diagonal
    //an example 3 X 3 identity matrix
    //1 0 0
    //0 1 0
    //0 0 1
    static Matrix ident(int dim);

    //return the number of rows
    int getNumRows() const;

    //return the number of columns
    int getNumCols() const;

    //element access
    element_type& at(int row, int col);
    const element_type& at(int row, int col) const;

    //get a reference to the specified row
    VectorRef rowAt(int row);
    ConstVectorRef rowAt(int row) const;

    //get a reference to the specified column
    VectorRef colAt(int col);
    ConstVectorRef colAt(int col) const;

    //get a reference to the specified row
    VectorRef operator[](int row);
    ConstVectorRef operator[](int row) const;

    //const iterators. go through the matrix by row
    const_iterator begin() const;
    const_iterator end() const;

    //iterators. go through the matrix by row
    iterator begin();
    iterator end();

    //explicit const row iterators
    const_row_iterator rowBegin() const;
    const_row_iterator rowEnd() const;

    //explicit row iterators
    row_iterator rowBegin();
    row_iterator rowEnd();

    //explicit const column iterators
    const_column_iterator colBegin() const;
    const_column_iterator colEnd() const;

    //explicit column iterators
    column_iterator colBegin();
    column_iterator colEnd();

    //negate
    Matrix operator-() const;

    //Matrix + Matrix
    Matrix& operator+=(const Matrix& rhs);
    Matrix operator+(const Matrix& rhs);

    //Matrix - Matrix
    Matrix& operator-=(const Matrix& rhs);
    Matrix operator-(const Matrix& rhs);

    //Matrix * Matrix
    Matrix& operator*=(const Matrix& rhs);
    Matrix operator*(const Matrix& rhs);

    //Matrix + scalar
    Matrix& operator+=(const element_type& rhs);
    Matrix operator+(const element_type& rhs) const;

    //Matrix - scalar
    Matrix& operator-=(const element_type& rhs);
    Matrix operator-(const element_type& rhs) const;

    //Matrix * scalar
    Matrix& operator*=(const element_type& rhs);
    Matrix operator*(const element_type& rhs) const;

   protected:
      std::vector<Vector> matrix;
      int numColumns;
      int numRows;
  };

  //scalar + Matrix
  Matrix operator+(const Matrix::element_type& lhs, const Matrix& rhs);

  //scalar - Matrix
  Matrix operator-(const Matrix::element_type& lhs, const Matrix& rhs);

  //scalar * Matrix
  Matrix operator*(const Matrix::element_type& lhs, const Matrix& rhs);

}

#include "ConstRowIterator.h"
#include "RowIterator.h"
#include "ConstColumnIterator.h"
#include "ColumnIterator.h"


#endif //ECS_36B_HOMEWORK_MATRIX_H
