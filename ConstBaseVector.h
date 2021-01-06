//
// Created by mfbut on 11/17/2019.
//

#ifndef ECS_36B_HOMEWORK_CONSTBASEVECTOR_H
#define ECS_36B_HOMEWORK_CONSTBASEVECTOR_H
namespace Matrix {
  class Vector;
  class ConstVectorIterator;

  class ConstBaseVector {
   public:
    //type tags
    using value_type = int;
    using reference = const value_type&;
    using const_reference = const value_type&;
    using pointer = const value_type*;
    using const_pointer = const value_type*;
    using difference_type = int;
    using iterator = ConstVectorIterator;
    using const_iterator = ConstVectorIterator;

    virtual ~ConstBaseVector() = default;
    virtual int size() const = 0;

    //element access
    virtual const value_type& at(int index) const = 0 ;
    virtual const value_type& operator[](int index) const = 0;

    //iterators
    virtual ConstVectorIterator begin() const;
    virtual ConstVectorIterator end() const;

    //negation
    virtual Vector operator-() const;

    //vector addition
    virtual Vector operator+(const ConstBaseVector& rhs);

    //vector subtraction
    virtual Vector operator-(const ConstBaseVector& rhs);

    //vector multiplication i.e. dot product
    virtual Vector operator*(const ConstBaseVector& rhs) const;

    //vector + scalar
    virtual Vector operator+(const value_type& rhs) const;

    //vector - scalar
    virtual Vector operator-(const value_type& rhs) const;

    //vector * scalar
    virtual Vector operator*(const value_type& rhs) const;

    //you are the same as rhs if you contain the same elements as rhs
    bool operator==(const ConstBaseVector& rhs) const;
    bool operator!=(const ConstBaseVector& rhs) const;

  };

  //scalar + vector
  Vector operator+(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs);

  //scalar + vector
  Vector operator-(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs);

  //scalar * vector
  Vector operator*(const ConstBaseVector::value_type& lhs, const ConstBaseVector& rhs);

}
#include "ConstVectorIterator.h"

#endif //ECS_36B_HOMEWORK_CONSTBASEVECTOR_H
