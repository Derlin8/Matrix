//
// Created by mfbut on 11/17/2019.
//

#ifndef ECS_36B_HOMEWORK_ROWITERATOR_H
#define ECS_36B_HOMEWORK_ROWITERATOR_H
#include <iterator>
#include "VectorRef.h"
#include "ConstVectorRef.h"
namespace Matrix {
  class Matrix;
  class ConstRowIterator;
  class RowIterator {
   public:
    //the iterator type tags
    using iterator_category = std::random_access_iterator_tag;
    using value_type = VectorRef;
    using difference_type = int;
    using pointer = const value_type*;
    using reference = const value_type&;

    //create a RowIterator over the specified matrix starting at the specified row
    RowIterator(Matrix* matrix, int row);
    RowIterator(const RowIterator& orig) = default;
    virtual ~RowIterator() = default;

    //return a ConstRowIterator over the same matrix and at the same row
    explicit operator ConstRowIterator() const;

    //return a reference to the row that you are on
    ConstVectorRef operator* () const;
    value_type operator*();

    //return a reference to the row offset past your current row
    ConstVectorRef operator[](int offset) const;
    value_type operator[](int offset);

    //move to the next row
    RowIterator& operator++(); //pre
    const RowIterator operator++(int); //post

    //move to the previous row
    RowIterator& operator--(); //pre
    const RowIterator operator--(int); //post

    //move forward amount rows
    RowIterator& operator+=(int amount);
    RowIterator operator+(int amount) const;

    //move backward amount rows
    RowIterator& operator-=(int amount);
    RowIterator operator-(int amount) const;

    //return the number of rows between yourself and rhs
    //for example if you were at row 10 and rhs was at row 7
    //the difference would be 3
    difference_type operator-(const RowIterator& rhs);

    //you are equal to rhs if you are both over the same matrix
    //and you are on the same row
    bool operator==(const RowIterator& rhs) const;
    bool operator!=(const RowIterator& rhs) const;

    //are you at a row before rhs?
    bool operator<(const RowIterator& rhs) const;
    bool operator<=(const RowIterator& rhs) const;

    //are you at a row after rhs
    bool operator>(const RowIterator& rhs) const;
    bool operator>=(const RowIterator& rhs) const;

   protected:
    Matrix* matrix;
    int row;
  };
}

#endif //ECS_36B_HOMEWORK_ROWITERATOR_H
