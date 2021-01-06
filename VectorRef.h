//
// Created by mfbut on 11/16/2019.
//

#ifndef ECS_36B_HOMEWORK_VECTORREF_H
#define ECS_36B_HOMEWORK_VECTORREF_H
#include <vector>
#include "BaseVector.h"
#include "ConstVectorRef.h"
namespace Matrix {
  class Matrix;
  class VectorRef : public ConstVectorRef, public BaseVector {
   public:
    //type tags
    using value_type = BaseVector::value_type;
    using reference = BaseVector::reference;
    using const_reference = BaseVector::const_reference;
    using pointer = BaseVector::pointer;
    using const_pointer = BaseVector::const_pointer;
    using difference_type = BaseVector::difference_type;
    using iterator = BaseVector::iterator;
    using const_iterator = BaseVector::const_iterator;

    VectorRef() = delete;
    virtual ~VectorRef() override = default;

    //create a reference to the given vector
    explicit VectorRef(BaseVector& orig);
    explicit VectorRef(const ConstBaseVector& orig) = delete; // make extra sure this doesn't get created

    //create a reference over the specified column in the given matrix
    VectorRef(Matrix& matrix, int col);
    VectorRef(const Matrix& matrix, int col) = delete; // make extra sure this doesn't get created

    //set the value of each element that we refer to
    //equal to the value at the corresponding position in rhs
    VectorRef& operator=(const BaseVector& rhs);

    //return the number of elements in the vector it refers to
    virtual int size() const override;

    //element access
    virtual value_type& at(int index) override;
    virtual const value_type& at(int index) const override;
    virtual value_type& operator[](int index) override;
    virtual const value_type& operator[](int index) const override;
//  protected:
//      std::vector<value_type> rawVector;
  };
}

#endif //ECS_36B_HOMEWORK_VECTORREF_H
