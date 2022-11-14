// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
/**
 * @struct matrix_dims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and main.cpp
 */
typedef struct matrix_dims
{
    int rows, cols;
} matrix_dims;

class Matrix{

 private:
  int rows;
  int columns;
  float *matt;

 public:
  // =============constructors/destructors==============
    /**
   * constructor, also used as default constructor
   * @param rows if nothing is given = 1
   * @param columns if nothing is given = 1
   */
  explicit Matrix (int rows=1, int columns=1);

    /**
   * copy constructor - deep copy
   * @param m
   */
  Matrix (const Matrix& m);

    /**
   * special destructor rule of 3
   */
  ~Matrix();

  // ==================functions========================

  int get_rows() const {return this->rows;}
  int get_cols() const {return this->columns;}

  /**
 * transpose the matrix
 * @return the matrix by reference for chaining
 */
  Matrix& transpose();

  /**
 * vectorize the matrix
 * @return the matrix by reference for chaining
 */
  Matrix& vectorize();

  /**
 * prints the matrix exactly by value
 */
  void plain_print() const;

/**
 * calculate the hadamard product of 2 matrices
 * @param mat
 * @return the result by value
 */
  Matrix dot(const Matrix& mat) const;

  /**
 * calculate the norm of the matrix
 * @return the result
 */
  double norm() const;

  // ==================operators========================
    /**
   *  operator =, rule of 3
   * @param mat
   * @return reference to itself
   */
  Matrix &operator=(const Matrix& mat);

    /**
   * operator +, adds to matrices
   * @param mat
   * @return the sum by value
   */
  Matrix operator+(const Matrix& mat) const;

  /**
 * operator * multiply two matrices
 * @param mat
 * @return the result by value
 */
  Matrix operator*(const Matrix& mat) const;

  /**
 * operator * multiply matrix by scalar
 * @param c
 * @return the result by value
 */
  Matrix operator*(float c) const;

  /**
 * operator * multiply matrix by scalar
 * @param c
 * @return the result by value
 */
  friend Matrix operator*(float c, const Matrix& mat);

  /**
 * operator +=
 * @param mat
 * @return it self by reference for chaining
 */
  Matrix &operator+=(const Matrix& mat);

  /**
 * operator () used to get a value by index from matrix for right hand side
 * @param row
 * @param col
 * @return the value from matrix
 */
  const float& operator()(int row, int col) const;

  /**
 * operator [] used to get a value by index from matrix for right hand side
 * @param row
 * @param col
 * @return the value from matrix
 */
  const float& operator[](int i) const;

  /**
 * operator () used to get a value by index from matrix for left hand side
 * @param row
 * @param col
 * @return the value from matrix
 */
  float& operator()(int row, int col);

  /**
 * operator [] used to get a value by index from matrix for left hand side
 * @param row
 * @param col
 * @return the value from matrix
 */
  float& operator[](int i);

  /**
 * operator << used to print the matrix with a small filter
 * @param os
 * @param mat
 * @return the stream for chaining
 */
  friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);

  /**
 * operator >> used to fill the matrix from stream, sizes need to match
 * @param os
 * @param mat
 * @return the stream for chaining
 */
  friend std::istream& operator>>(std::istream& os, const Matrix& mat);
};




#endif //MATRIX_H