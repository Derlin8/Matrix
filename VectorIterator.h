//
// Created by mfbut on 11/14/2019.
//

#ifndef ECS_36B_HOMEWORK_VECTORITERATOR_H
#define ECS_36B_HOMEWORK_VECTORITERATOR_H
#include <iterator>
#include "BaseVector.h"
namespace Matrix {
  class BaseVector;
  class ConstVectorIterator;
  class VectorIterator {
   public:
    //the iterator type tags
    using value_type = BaseVector::value_type;
    using difference_type = int;
    using pointer = value_type*;
    using reference = value_type&;
    using iterator_category = std::random_access_iterator_tag;

    //create an iterator over the given vector starting at the specified position
    VectorIterator(BaseVector* vector, int pos);
    virtual ~VectorIterator() = default;

    //conversion to a ConstVectorIterator
    explicit operator ConstVectorIterator() const;

    //return the element that you are at
    value_type& operator*();
    const value_type& operator*() const;

    //return the element offset elements away from your current position
    value_type& operator[](int offset);
    const value_type& operator[](int offset) const;

    //go to the next element
    VectorIterator& operator++(); //pre
    const VectorIterator operator++(int); //post

    //go to the previous element
    VectorIterator& operator--(); //pre
    const VectorIterator operator--(int); //post

    //move amount elements forward
    VectorIterator& operator+=(int amount);
    VectorIterator operator+(int amount) const;

    //move amount elements backwards
    VectorIterator& operator-=(int amount);
    VectorIterator operator-(int amount) const;

    //return the number of elements between yourself and rhs
    //for example if you were at element 10 and rhs was at element 7
    //the difference would be 3
    difference_type operator-(const VectorIterator& rhs);

    //true if both this and rhs are over the same vector and at the same element
    bool operator==(const VectorIterator& rhs) const;
    bool operator!=(const VectorIterator& rhs) const;

    //are you at an element before rhs?
    bool operator<(const VectorIterator& rhs) const;
    bool operator<=(const VectorIterator& rhs) const;

    //are you at an element after rhs?
    bool operator>(const VectorIterator& rhs) const;
    bool operator>=(const VectorIterator& rhs) const;

   protected:
    BaseVector* vector;
    int pos;
  };
}

#endif //ECS_36B_HOMEWORK_VECTORITERATOR_H
