/**
 *  \file vector.h
 *  \author Xein <xgonip@gmail.com>
 *  \date 2024-11-14
 *
 *  \brief Contains all vector operations
 */

#pragma once
#include <cmath>
#include "matrix.h"

/**
 *  \namespace catv
 *  \brief Custom math engine for 2D and 3D game engines
 *
 *  Catv (or cat-vector) is a custom math library that provides all the mathematical operations needed by a
 *  game engine. It is named after the famous spanish-portuguese song of trigonometrical functions that stars
 *  a really cute cat dancing to the song. The song lyrics goes like this: "un dos tres, tres dos uno,
 *  todo el mondo sobre dos, raíz en cada uno".
 */
namespace catv {

// xTODO: Write vector documentation
struct Vector3
{
    float x, y, z; ///< x, y and z components of the vector

    /// \brief Default constructor set to 0
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    /// \brief 2D constructor, z is defined as 0
    /// \param x x component
    /// \param y y component
    Vector3(const float x, const float y) : x(x), y(y), z(0) {}
    /// \brief 3D constructor
    /// \param x x component
    /// \param y y component
    /// \param z z component
    Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}

#pragma region Operators

    /// \brief Addition of two vectors
    /// \param other Vector to add
    Vector3 operator+(const Vector3& other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    /// \brief Subtraction of two vectors
    /// \param other Vector to subtract
    Vector3 operator-(const Vector3& other) const
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    /// \brief Scalar multiplication of the vector
    /// \param scalar Number to multiply the vector
    Vector3 operator*(const float scalar) const
    {
        return {x * scalar, y * scalar, z * scalar};
    }

    /// \brief Scalar division of the vector
    /// \param scalar Number to divide the vector
    Vector3 operator/(const float scalar) const
    {
        return {x / scalar, y / scalar, z / scalar};
    }

    /// \brief Dot product between two vectors
    /// \param a Vector a
    /// \param b Vector b
    /// \return Result of the computation
    static float Dot(const Vector3& a, const Vector3& b)
    {
        return (a.x * b.x + a.y * b.y + a.z * b.z);
    }

    /// \brief Cross product between two vectors
    /// \param a Vector a
    /// \param b Vector b
    /// \return Result of the computation
    static Vector3 Cross(const Vector3& a, const Vector3& b)
    {
        return {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

#pragma endregion

#pragma region Utilities

    /// \brief Calculate the length of the vector
    /// \return Length
    [[nodiscard]] float Length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    /// \brief Normalizes the value of the vector so the length is 1
    /// \return Normalized vector
    [[nodiscard]] Vector3 Normalize() const
    {
        const float len = Length();
        return (len !=0)? Vector3(x/len, y/len, z/len) : Vector3();
    }

    /// \brief Makes a 3x3 matrix from 3 vectors
    ///
    static Matrix3 MakeMatrix(const Vector3 a, const Vector3 b, const Vector3 c)
    {
        float matData[3][3] = {
            {a.x, a.y, a.z},  // First row from Vector3 a
            {b.x, b.y, b.z},  // Second row from Vector3 b
            {c.x, c.y, c.z}   // Third row from Vector3 c
        };

        return Matrix3(matData);
    }

#pragma endregion

};

}
