/**
 *  \file matrix.h
 *  \author Xein <xgonip@gmail.com>
 *  \date 2024-11-14
 *
 *  \brief Contains all matrix operations
 */

#pragma once
#include "vector.h"

namespace catv
{

// xTODO: Write matrix documentation
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

}
