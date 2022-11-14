#include "Matrix.h"
#include <cmath>

#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"

class Dense
{
 private:
  Matrix weight;
  Matrix bias;
  act_func f;

 public:
  ::act_func get_activation() const;
  Matrix get_weights() const;
  Matrix get_bias() const;

  /**
 * constructor
 * @param weights
 * @param bias
 * @param f
 */
  Dense(const Matrix& weights, const Matrix& bias, ::act_func f);

  /**
 * activates the Dense function, all possible errors are handled by Matrix
 * @param input
 * @return the result by value
 */
  Matrix operator()(const Matrix& input) const;
};


#endif //DENSE_H
