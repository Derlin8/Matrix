#ifndef ECS_36B_HOMEWORK_VECTOR_H
#define ECS_36B_HOMEWORK_VECTOR_H
#include <vector>
#include "BaseVector.h"
#include "ConstBaseVector.h"

namespace Matrix {
  class Vector : public BaseVector{
   public:
    //create a vector that contains the same elements as in orig
    explicit Vector(const ConstBaseVector& orig);

    //create a vector that holds numElements and each element is value
    Vector(int numElements, const BaseVector::value_type& value);

    //create a vector that holds numElements 0's
    explicit Vector(int numElements);

    //create a vector that contains the specified values
    explicit Vector(const std::vector<value_type>& values);

    //create a 1 X 1 vector with the value 0
    Vector();
    virtual ~Vector() override = default;

    //make all of the elements in this vector the same
    //as what is in rhs. adjust the size of this vector if necessary
    Vector& operator=(const ConstBaseVector& rhs);

    //return the number of elements in the Vector
    virtual int size() const override;

    //return the element at the position
    virtual value_type& at(int index) override;
    virtual const value_type& at(int index) const override;
    virtual value_type& operator[](int index) override;
    virtual const value_type& operator[](int index) const override;

   private:
      std::vector<value_type> rawVector;
  };

}

#endif //ECS_36B_HOMEWORK_VECTOR_H
