#include "Matrix.h"
#include <cmath>
#ifndef ACTIVATION_H
#define ACTIVATION_H

namespace activation
{
/**
 * the fist activation function, makes any negative value in matrix into 0
 * @param mat
 * @return the resulted matrix
 */
  Matrix relu(const Matrix& mat);

    /**
   * the second activation function, turn every value into the exp of it and
   * normalize so all the values are sumed up to 1.
   * @param mat
   * @return he resulted matrix
   */
  Matrix softmax(const Matrix& mat);
};
typedef Matrix (*act_func)(const Matrix&);

#endif //ACTIVATION_H