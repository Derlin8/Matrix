//
// Created by mfbut on 11/14/2019.
//

#ifndef ECS_36B_HOMEWORK_BASEVECTOR_H
#define ECS_36B_HOMEWORK_BASEVECTOR_H
#include "ConstBaseVector.h"
namespace Matrix {
  class Vector;
  class VectorIterator;
  class ConstVectorIterator;
  class Matrix;
  class BaseVector  : public virtual ConstBaseVector{
   public:
    //the type tags
    using value_type = int;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using difference_type = int;
    using iterator = VectorIterator;
    using const_iterator = ConstVectorIterator;

    virtual ~BaseVector() override = default;

    //return a 1 X N matrix with the same values as yourself
    explicit operator Matrix() const;
    //element access
    virtual const ConstBaseVector::value_type& at(int index) const override = 0;
    virtual value_type& at(int index) = 0;
    virtual const ConstBaseVector::value_type& operator[](int index) const override = 0;
    virtual value_type& operator[](int index) = 0;

    //iterators
    virtual VectorIterator begin();
    virtual VectorIterator end();

    virtual ConstVectorIterator begin() const override;
    virtual ConstVectorIterator end() const override;

    virtual ConstVectorIterator cbegin() const;
    virtual ConstVectorIterator cend() const;

    //vector += vector
    virtual BaseVector& operator+=(const ConstBaseVector& rhs);

    //vector -= vector
    virtual BaseVector& operator-=(const ConstBaseVector& rhs);

    //vector += scalar
    virtual BaseVector& operator+=(const value_type& rhs);

    //vector -= scalar
    virtual BaseVector& operator-=(const value_type& rhs);

    //vector *= scalar
    virtual BaseVector& operator*=(const value_type& rhs);

  };
}
#include "ConstVectorIterator.h"
#include "VectorIterator.h"

#endif //ECS_36B_HOMEWORK_BASEVECTOR_H
