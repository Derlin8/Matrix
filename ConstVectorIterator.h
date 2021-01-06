//
// Created by mfbut on 11/14/2019.
//

#ifndef ECS_36B_HOMEWORK_CONSTVECTORITERATOR_H
#define ECS_36B_HOMEWORK_CONSTVECTORITERATOR_H
#include <iterator>
#include "ConstBaseVector.h"

namespace Matrix {
  class ConstBaseVector;
  class ConstVectorIterator {
   public:
    //the iterator type tags
    using iterator_category = std::random_access_iterator_tag;
    using value_type = ConstBaseVector::value_type;
    using difference_type = int;
    using pointer = const value_type*;
    using reference = const value_type&;


    //create a ConstVectorIterator over the specified vector starting at the specified position
    ConstVectorIterator(const ConstBaseVector *vector, int pos);
    ConstVectorIterator(const ConstVectorIterator& orig) = default;
    virtual ~ConstVectorIterator() = default;

    //return a reference to the element you are at
    const value_type& operator*() const;

    //return a reference to the element offset past your current position
    const value_type& operator[](int offset) const;

    //move to the next element
    ConstVectorIterator& operator++(); //pre
    const ConstVectorIterator operator++(int); //post

    //move to the previous element
    ConstVectorIterator& operator--(); //pre
    const ConstVectorIterator operator--(int); //post

    //move forward amount elements
    ConstVectorIterator& operator+=(int amount);
    ConstVectorIterator operator+(int amount) const;

    //move backward amount elements
    ConstVectorIterator& operator-=(int amount);
    ConstVectorIterator operator-(int amount) const;

    //return the number of elements between yourself and rhs
    //for example if you were at element 10 and rhs was at element 7
    //the difference would be 3
    difference_type operator-(const ConstVectorIterator& rhs);

    //you are equal to rhs if you are over the same vector
    //and at the same position
    bool operator==(const ConstVectorIterator& rhs) const;
    bool operator!=(const ConstVectorIterator& rhs) const;

    //are you at an element before rhs?
    bool operator<(const ConstVectorIterator& rhs) const;
    bool operator<=(const ConstVectorIterator& rhs) const;

    //are you at an element after rhs?
    bool operator>(const ConstVectorIterator& rhs) const;
    bool operator>=(const ConstVectorIterator& rhs) const;

  protected:
    const ConstBaseVector* vector;
    int pos;
  };
}

#endif //ECS_36B_HOMEWORK_CONSTVECTORITERATOR_H
