//
// Created by mfbut on 11/17/2019.
//

#ifndef ECS_36B_HOMEWORK_CONSTROWITERATOR_H
#define ECS_36B_HOMEWORK_CONSTROWITERATOR_H
#include <iterator>
#include "ConstVectorRef.h"
#include "Matrix.h"

namespace Matrix {
  class Matrix;
  class ConstRowIterator {
   public:
    //the iterator type tags
    using iterator_category = std::random_access_iterator_tag;
    using value_type = ConstVectorRef;
    using difference_type = int;
    using pointer = const value_type*;
    using reference = const value_type&;

    //Create an row iterator over the specified Matrix starting at the specified row
    ConstRowIterator(const Matrix* matrix, int row);
    ConstRowIterator(const ConstRowIterator& orig) = default;
    virtual ~ConstRowIterator() = default;

    //return a reference to the row you are on
    value_type operator* () const;

    //return a reference to the row offset rows past your current position
    value_type operator[](int offset) const;

    //move forward one row
    ConstRowIterator& operator++(); //pre
    const ConstRowIterator operator++(int); //post

    //move backward one row
    ConstRowIterator& operator--(); //pre
    const ConstRowIterator operator--(int); //post

    //move forward amount rows
    ConstRowIterator& operator+=(int amount);
    ConstRowIterator operator+(int amount) const;

    //move backward  rows
    ConstRowIterator& operator-=(int amount);
    ConstRowIterator operator-(int amount) const;

    //return the number of rows between yourself and rhs
    //for example if you were at row 10 and rhs was at row 7
    //the difference would be 3
    difference_type operator-(const ConstRowIterator& rhs);

    //you are equal to rhs if you are both over the same matrix
    //and you are on the same row
    bool operator==(const ConstRowIterator& rhs) const;
    bool operator!=(const ConstRowIterator& rhs) const;

    //are you at a row before rhs?
    bool operator<(const ConstRowIterator& rhs) const;
    bool operator<=(const ConstRowIterator& rhs) const;

    //are you at a row after rhs?
    bool operator>(const ConstRowIterator& rhs) const;
    bool operator>=(const ConstRowIterator& rhs) const;

   protected:
      const Matrix* matrix;
      int row;
  };
}

#endif //ECS_36B_HOMEWORK_CONSTROWITERATOR_H
