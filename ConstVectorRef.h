//
// Created by mfbut on 11/17/2019.
//

#ifndef ECS_36B_HOMEWORK_CONSTVECTORREF_H
#define ECS_36B_HOMEWORK_CONSTVECTORREF_H
#include <vector>
#include "ConstBaseVector.h"
namespace Matrix {
  class BaseVector;
  class Matrix;
  class ConstVectorRef : public virtual ConstBaseVector{
   public:
    virtual ~ConstVectorRef() override = default;
    explicit ConstVectorRef(const ConstBaseVector& orig);

    //create a reference over the specified column in the given matrix
    ConstVectorRef(const Matrix& matrix, int col);

    //because this is a const reference we cannot change the value
    //that it refers to so we delete the operator=
    ConstVectorRef& operator=(ConstBaseVector& rhs) = delete;

    //return the number of elements in the vector you refer to
    virtual int size() const override;

    //return a reference to the element at the position you refer to
    virtual const value_type& at(int index) const override;
    virtual const value_type& operator[](int index) const override;
   protected:
    std::vector<value_type*> elements;
  };
}

#endif //ECS_36B_HOMEWORK_CONSTVECTORREF_H
