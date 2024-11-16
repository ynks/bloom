/**
 *  \file matrix.h
 *  \author Xein <xgonip@gmail.com>
 *  \date 2024-11-14
 *
 *  \brief Contains all matrix operations
 */

#pragma once
#include <cmath>

#include "vector.h"

namespace catv
{

// xTODO: Write matrix3 documentation
class Matrix3
{
  /// \brief The matrix data.
  float data[3][3]{};

public:
  /// \brief Default constructor. Sets all values to 0.
  Matrix3() : data{0.0f} {}
  /// \brief Constructor with data initialization.
  /// \param value The 3x3 matrix data.
  explicit Matrix3(const float value[3][3])
  {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        data[i][j] = value[i][j];
  }
  /// \brief Constructor with row vectors.
  /// \param a The first row vector.
  /// \param b The second row vector.
  /// \param c The third row vector.
  explicit Matrix3(const Vector3 a, const Vector3 b, const Vector3 c)
  {
    const float matData[3][3] = {
      {a.x, a.y, a.z},  // First row from Vector3 a
      {b.x, b.y, b.z},  // Second row from Vector3 b
      {c.x, c.y, c.z}   // Third row from Vector3 c
    };

    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        data[i][j] = matData[i][j];
  }

#pragma region Operators

    /// \brief Access the matrix data at the specified row and column.
    /// \param row The row index.
    /// \param col The column index.
    /// \return The value at the specified row and column.
    float operator()(const int row, const int col) const
    {
      return data[row][col];
    }

    /// \brief Matrix addition.
    /// \param other The matrix to add.
    /// \return The result of the addition.
    Matrix3 operator+(const Matrix3& other) const
    {
      Matrix3 result;
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
          result.data[i][j] = data[i][j] + other.data[i][j];
      return result;
    }

    /// \brief Matrix subtraction.
    /// \param other The matrix to subtract.
    /// \return The result of the subtraction.
    Matrix3 operator-(const Matrix3& other) const
    {
      Matrix3 result;
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
          result.data[i][j] = data[i][j] - other.data[i][j];
      return result;
    }

    /// \brief Matrix multiplication by a scalar.
    /// \param scalar The scalar to multiply by.
    /// \return The result of the multiplication.
    Matrix3 operator*(const float scalar) const
    {
      Matrix3 result;
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
          result.data[i][j] = data[i][j] * scalar;
      return result;
    }

    /// \brief Matrix division by a scalar.
    /// \param scalar The scalar to divide by.
    /// \return The result of the division.
    Matrix3 operator/(const float scalar) const
    {
      Matrix3 result;
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
          result.data[i][j] = data[i][j] / scalar;
      return result;
    }

    /// \brief Matrix multiplication by another matrix.
    /// \param other The matrix to multiply by.
    /// \return The result of the multiplication.
    Matrix3 operator*(const Matrix3& other) const
    {
      Matrix3 result;
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
          for (int k = 0; k < 3; k++)
            result.data[i][j] += data[i][k] * other.data[k][j];
      return result;
    }

    /// \brief Matrix multiplication by a vector.
    /// \param vector The vector to multiply by.
    /// \return The result of the multiplication.
    Vector3 operator*(const Vector3& vector) const
    {
      return {
        data[0][0] * vector.x + data[0][1] * vector.y + data[0][2] * vector.z,
        data[1][0] * vector.x + data[1][1] * vector.y + data[1][2] * vector.z,
        data[2][0] * vector.x + data[2][1] * vector.y + data[2][2] * vector.z
      };
    }

#pragma endregion

#pragma region Utilities

  /// \brief Transpose the matrix.
  /// \return The transposed matrix.
  [[nodiscard]] Matrix3 Transpose() const
  {
    Matrix3 result;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        result.data[i][j] = data[j][i];
    return result;
  }

  /// \brief Swaps two rows of the matrix
  /// \param row1 First row to swap
  /// \param row2 Second row to swap
  void SwapRows(const int row1, const int row2) {
    for (int i = 0; i < 3; i++) {
      std::swap(data[row1][i], data[row2][i]);
    }
  }

  /// \brief Invert the matrix.
  /// \return The inverted matrix.
  /// Uses Cramer's rule to calculate the inverse. A-1 = adj(A)t / det(A)
  [[nodiscard]] Matrix3 Inverse() const
  {
    Matrix3 result;
    const float det = Determinant();
    if (det == 0.0f)
      return result;

    result.data[0][0] = (data[1][1] * data[2][2] - data[1][2] * data[2][1]) / det;
    result.data[0][1] = (data[0][2] * data[2][1] - data[0][1] * data[2][2]) / det;
    result.data[0][2] = (data[0][1] * data[1][2] - data[0][2] * data[1][1]) / det;
    result.data[1][0] = (data[1][2] * data[2][0] - data[1][0] * data[2][2]) / det;
    result.data[1][1] = (data[0][0] * data[2][2] - data[0][2] * data[2][0]) / det;
    result.data[1][2] = (data[0][2] * data[1][0] - data[0][0] * data[1][2]) / det;
    result.data[2][0] = (data[1][0] * data[2][1] - data[1][1] * data[2][0]) / det;
    result.data[2][1] = (data[0][1] * data[2][0] - data[0][0] * data[2][1]) / det;
    result.data[2][2] = (data[0][0] * data[1][1] - data[0][1] * data[1][0]) / det;

    return result;
  }

  /// \brief Calculate the determinant of the matrix.
  /// \return The determinant of the matrix.
  [[nodiscard]] float Determinant() const
  {
    return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
           data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
           data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
  }

#pragma endregion

};

// xTODO: Write matrix4 documentation
class Matrix4
{
  /// \brief The matrix data.
  float data[4][4]{};

public:
  /// \brief Default constructor. Sets all values to 0.
  Matrix4() : data{0.0f} {}
  /// \brief Constructor with data initialization.
  /// \param value The 4x4 matrix data.
  explicit Matrix4(const float value[4][4])
  {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        data[i][j] = value[i][j];
  }
  /// \brief Constructor with Matrix3.
  /// The w is set to 1
  /// \param m A 3d matrix
  explicit Matrix4(const Matrix3& m)
  {
      const float matData[4][4] = {
        { m(1,1), m(1,2), m(1,3), 0 },
        { m(2,1), m(2,2), m(2,3), 0 },
        { m(3,1), m(3,2), m(3,3), 0 },
        { 0, 0, 0, 1}
      };

      for (int i = 0; i < 4; i++)
          for (int j = 0; j < 4; j++)
              data[i][j] = matData[i][j];
  }
  /// \brief Constructor with Matrix4.
  /// \param m A 4D matrix
  Matrix4(const Matrix4& m)
  {
    const float matData[4][4] = {
      { m(0,1), m(0,2), m(0,3), m(0,4) },
      { m(1,1), m(1,2), m(1,3), m(1,4) },
      { m(2,1), m(2,2), m(2,3), m(2,4) },
      { m(3,1), m(3,2), m(3,3), m(3,4) }
    };

    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        data[i][j] = matData[i][j];
  }

#pragma region Operators

  /// \brief Access the matrix data at the specified row and column.
  /// \param row The row index.
  /// \param col The column index.
  /// \return The value at the specified row and column.
  float operator()(const int row, const int col) const
  {
    return data[row][col];
  }

  /// \brief Matrix addition.
  /// \param other The matrix to add.
  /// \return The result of the addition.
  Matrix4 operator+(const Matrix4& other) const
  {
    Matrix4 result;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
  }

  /// \brief Matrix subtraction.
  /// \param other The matrix to subtract.
  /// \return The result of the subtraction.
  Matrix4 operator-(const Matrix4& other) const
  {
    Matrix4 result;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
  }

  /// \brief Matrix multiplication by a scalar.
  /// \param scalar The scalar to multiply by.
  /// \return The result of the multiplication.
  Matrix4 operator*(const float scalar) const
  {
    Matrix4 result;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        result.data[i][j] = data[i][j] * scalar;
    return result;
  }

  /// \brief Matrix division by a scalar.
  /// \param scalar The scalar to divide by.
  /// \return The result of the division.
  Matrix4 operator/(const float scalar) const
  {
    Matrix4 result;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        result.data[i][j] = data[i][j] / scalar;
    return result;
  }

  /// \brief Matrix multiplication by another matrix.
  /// \param other The matrix to multiply by.
  /// \return The result of the multiplication.
  Matrix4 operator*(const Matrix4& other) const
  {
    Matrix4 result;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        for (int k = 0; k < 4; k++)
          result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
  }

  /// \brief Matrix multiplication by a vector.
  /// \param vector The vector to multiply by.
  /// \return The result of the multiplication.
  Vector4 operator*(const Vector4& vector) const
  {
    return {
      data[0][0] * vector.x + data[0][1] * vector.y + data[0][2] * vector.z + data[0][3] * vector.w,
      data[1][0] * vector.x + data[1][1] * vector.y + data[1][2] * vector.z + data[1][3] * vector.w,
      data[2][0] * vector.x + data[2][1] * vector.y + data[2][2] * vector.z + data[2][3] * vector.w,
      data[3][0] * vector.x + data[3][1] * vector.y + data[3][2] * vector.z  + data[3][3] * vector.w
    };
  }

#pragma endregion

#pragma region Utilities

  /// \brief Transpose the matrix.
  /// \return The transposed matrix.
  [[nodiscard]] Matrix4 Transpose() const
  {
    Matrix4 result;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        result.data[i][j] = data[j][i];
    return result;
  }

  /// \brief Swaps two rows of the matrix
  /// \param row1 First row to swap
  /// \param row2 Second row to swap
  void SwapRows(const int row1, const int row2) {
    for (int i = 0; i < 4; i++) {
      std::swap(data[row1][i], data[row2][i]);
    }
  }

  /// \brief Calculate the determinant of the matrix.
  /// \return The determinant of the matrix.
  [[nodiscard]] float Determinant() const
  {
    float m0d[3][3] = {
      { data[1][1], data[1][2], data[1][3] },
      { data[2][1], data[2][2], data[2][3] },
      { data[3][1], data[3][2], data[3][3] }
    };
    float m1d[3][3] = {
      { data[1][0], data[1][2], data[1][3] },
      { data[2][0], data[2][2], data[2][3] },
      { data[3][0], data[3][2], data[3][3] }
    };
    float m2d[3][3] = {
      { data[1][0], data[1][1], data[1][3] },
      { data[2][0], data[2][1], data[2][3] },
      { data[3][0], data[3][1], data[3][3] }
    };
    float m3d[3][3] = {
      { data[1][0], data[1][1], data[1][2] },
      { data[2][0], data[2][1], data[2][2] },
      { data[3][0], data[3][1], data[3][2] }
    };
    const auto m0 = Matrix3(m0d);
    const auto m1 = Matrix3(m1d);
    const auto m2 = Matrix3(m2d);
    const auto m3 = Matrix3(m3d);

    const float det = data[0][0] * m0.Determinant() - data[0][1] * m1.Determinant() +
                      data[0][2] * m2.Determinant() - data[0][3] * m3.Determinant();
    return det;
  }

  /// \brief Calculates the cofactor matrix
  /// \return Cofactor matrix
  [[nodiscard]] Matrix4 Cofactor() const
  {
    const float epsilon = 1e-6; // Tolerance for near-zero determinant
    float cofactor[4][4];

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        float subMatrix[3][3];
        int subRow = 0;
        for (int k = 0; k < 4; k++) {
          if (k == i) continue; //Skip row i
          int subCol = 0;
          for (int l = 0; l < 4; l++) {
            if (l == j) continue; // Skip column j
            subMatrix[subRow][subCol] = data[k][l];
            subCol++;
          }
          subRow++;
        }

        auto mat = Matrix3(subMatrix);
        if (const float det = mat.Determinant(); std::fabs(det) < epsilon)
          cofactor[i][j] = 0;
        else
          cofactor[i][j] = ( (i + j) % 2 == 0 ? 1.0f : -1.0f) * det;
      }
    }

    return Matrix4(cofactor);
  }

  /// \brief Invert the matrix.
  /// \return The inverted matrix.
  /// Uses Cramer's rule to calculate the inverse. A-1 = adj(A)t / det(A)
  [[nodiscard]] Matrix4 Inverse() const
  {
    return Cofactor().Transpose() * (1/Determinant());
  }

#pragma endregion

};

}
