//
// Created by mfbut on 11/17/2019.
//

#ifndef ECS_36B_HOMEWORK_COLUMNITERATOR_H
#define ECS_36B_HOMEWORK_COLUMNITERATOR_H

#include <iterator>
#include "ConstVectorRef.h"
#include "VectorRef.h"
namespace Matrix {
  class Matrix;
  class ConstColumnIterator;
  class ColumnIterator {
   public:
    //the iterator type tags
    using iterator_category = std::random_access_iterator_tag;
    using value_type = VectorRef;
    using difference_type = int;
    using pointer = const value_type*;
    using reference = const value_type&;

    //Create an column iterator over the specified matrix starting at the specified column
    ColumnIterator(Matrix* matrix, int col);
    ColumnIterator(const ColumnIterator& orig) = default;
    virtual ~ColumnIterator() = default;

    //return a ConstColumnIterator that is over the same matrix and at the same position
    explicit operator ConstColumnIterator() const;

    //get a reference to the column you are at
    ConstVectorRef operator* () const;
    value_type operator*();

    //get a reference to a column offset past your current location
    ConstVectorRef operator[](int offset) const;
    value_type operator[](int offset);

    //move to the next column
    ColumnIterator& operator++(); //pre
    const ColumnIterator operator++(int); //post

    //move to the previous column
    ColumnIterator& operator--(); //pre
    const ColumnIterator operator--(int); //post

    //move forward amount columns
    ColumnIterator& operator+=(int amount);
    ColumnIterator operator+(int amount) const;

    //move backward amount columns
    ColumnIterator& operator-=(int amount);
    ColumnIterator operator-(int amount) const;

    //return the number of columns between yourself and rhs
    //for example if you were at column 10 and rhs was at column 7
    //the difference would be 3
    difference_type operator-(const ColumnIterator& rhs);

    //you and rhs are equal if you are over the same matrix and
    //at the same column
    bool operator==(const ColumnIterator& rhs) const;
    bool operator!=(const ColumnIterator& rhs) const;

    //are you at a column before rhs?
    bool operator<(const ColumnIterator& rhs) const;
    bool operator<=(const ColumnIterator& rhs) const;

    //are you at a column after rhs?
    bool operator>(const ColumnIterator& rhs) const;
    bool operator>=(const ColumnIterator& rhs) const;

   protected:
    Matrix* matrix;
    int col;
  };
}

#endif //ECS_36B_HOMEWORK_COLUMNITERATOR_H
