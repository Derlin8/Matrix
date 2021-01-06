//
// Created by mfbut on 11/17/2019.
//

#ifndef ECS_36B_HOMEWORK_CONSTCOLUMNITERATOR_H
#define ECS_36B_HOMEWORK_CONSTCOLUMNITERATOR_H

#include <iterator>
#include "ConstVectorRef.h"
namespace Matrix {
  class Matrix;
  class ConstColumnIterator {
   public:
    //the iterator type tags
    using iterator_category = std::random_access_iterator_tag;
    using value_type = ConstVectorRef;
    using difference_type = int;
    using pointer = const value_type*;
    using reference = const value_type&;


    //Create an column iterator over the specified Matrix starting at the specified column
    ConstColumnIterator(const Matrix* matrix, int col);
    ConstColumnIterator(const ConstColumnIterator& orig) = default;
    virtual ~ConstColumnIterator() = default;

    //return a reference to the column you are at
    value_type operator* () const;

    //return a reference to the column offset columns from your current position
    value_type operator[](int offset) const;

    //move to the next column
    ConstColumnIterator& operator++(); //pre
    const ConstColumnIterator operator++(int); //post

      //move backward amount columns
    ConstColumnIterator& operator--(); //pre
    const ConstColumnIterator operator--(int); //post

    //move forward amount columns
    ConstColumnIterator& operator+=(int amount);
    ConstColumnIterator operator+(int amount) const;

    //move backward amount columns
    ConstColumnIterator& operator-=(int amount);
    ConstColumnIterator operator-(int amount) const;

    //return the number of columns between yourself and rhs
    //for example if you were at column 10 and rhs was at column 7
    //the difference would be 3
    difference_type operator-(const ConstColumnIterator& rhs);

    //you and rhs are equal if you are over the same matrix and
    //at the same column
    bool operator==(const ConstColumnIterator& rhs) const;
    bool operator!=(const ConstColumnIterator& rhs) const;

    //are you at a column before rhs?
    bool operator<(const ConstColumnIterator& rhs) const;
    bool operator<=(const ConstColumnIterator& rhs) const;

    //are you at a column after rhs?
    bool operator>(const ConstColumnIterator& rhs) const;
    bool operator>=(const ConstColumnIterator& rhs) const;

   protected:
      const Matrix* matrix;
      int col;

  };
}

#endif //ECS_36B_HOMEWORK_CONSTCOLUMNITERATOR_H
