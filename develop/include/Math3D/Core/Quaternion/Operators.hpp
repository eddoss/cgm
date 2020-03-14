#ifndef MATH3D_QUATERNION_OPERATORS_HPP
#define MATH3D_QUATERNION_OPERATORS_HPP


#include <Math3D/Core/Quaternion/Quaternion.hpp>


/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

/**
 * Get a negated copy of the quaternion.
 * @return A negated copy of the quaternion.
 */
template<typename T>
Quaternion<T>
operator - (const Quaternion<T>& quaternion);

/**
 * Gets the result of subtraction quaternion "A" and quaternion "B".
 * @return The result of quaternion subtraction.
 */
template<typename T>
Quaternion<T>
operator - (const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Subtracts quaternion "B" from quaternion "B".
 * @return The result of quaternion subtraction.
 */
template<typename T>
Quaternion<T>&
operator -= (Quaternion<T>& A, const Quaternion<T>& B);

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

/**
 * Gets the result of adding quaternion "A" and quaternion "B".
 * @return The result of quaternion adding.
 */
template<typename T>
Quaternion<T>
operator + (const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Add quaternion "A" and quaternion "B".
 * @return The result of adding subtraction.
 */
template<typename T>
Quaternion<T>&
operator += (Quaternion<T>& A, const Quaternion<T>& B);

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

/**
 * Multiply quaternion by a scaling factor.
 * @return The result of scaling.
 */
template<typename T, typename TScale>
Quaternion<T>
operator * (const Quaternion<T>& quaternion, TScale scale);

/**
 * Gets the result of multiplication quaternion "A" and quaternion "B".
 * @return The result of quaternion multiplication.
 */
template<typename T>
Quaternion<T>
operator * (const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Multiply quaternion by a scaling factor.
 * @return The result of scaling.
 */
template<typename T, typename TScale>
Quaternion<T>&
operator *= (Quaternion<T>& quaternion, TScale scale);

/**
 * Gets the result of multiplication quaternion "A" and quaternion "B".
 * @return The result of quaternion multiplication.
 */
template<typename T>
Quaternion<T>&
operator *= (Quaternion<T>& A, const Quaternion<T>& B);

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

/**
 * Divide this quaternion by scale.
 * @return Results of division.
 */
template<typename T, typename TScale>
Quaternion<T>
operator / (const Quaternion<T>& quaternion, TScale scale);

/**
 * Divide this quaternion by scale.
 * @return Results of division.
 */
template<typename T, typename TScale>
Quaternion<T>&
operator /= (Quaternion<T>& quaternion, TScale scale);

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

/**
 * Checks whether quaternion "A" is equal to quaternion "B".
 * @return true if the quaternion are equal, false otherwise.
 */
template<typename T>
bool
operator == (const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Checks whether quaternion "A" is not equal to quaternion "B".
 * @return true if the quaternion are not equal, false otherwise.
 */
template<typename T>
bool
operator != (const Quaternion<T>& A, const Quaternion<T>& B);

/* ####################################################################################### */
/* Dot product */
/* ####################################################################################### */

/**
 * Calculates dot product of two quaternions.
 * @return The dot product.
 */
template<typename T>
T
operator | (const Quaternion<T>& A, const Quaternion<T>& B);

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<typename T>
Quaternion<T>
operator - (const Quaternion<T>& quaternion)
{
    return Quaternion
    {
        -quaternion.s,
        -quaternion.a,
        -quaternion.b,
        -quaternion.c
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
operator - (const Quaternion<T>& A, const Quaternion<T>& B)
{
    return Quaternion
    {
        A.s - B.s,
        A.a - B.a,
        A.b - B.b,
        A.c - B.c
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>&
operator -= (Quaternion<T>& A, const Quaternion<T>& B)
{
    A.s -= B.s;
    A.a -= B.a;
    A.b -= B.b;
    A.c -= B.c;

    return A;
}

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

template<typename T>
Quaternion<T>
operator + (const Quaternion<T>& A, const Quaternion<T>& B)
{
    return Quaternion
    {
        A.s + B.s,
        A.a + B.a,
        A.b + B.b,
        A.c + B.c
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>&
operator += (Quaternion<T>& A, const Quaternion<T>& B)
{
    A.s += B.s;
    A.a += B.a;
    A.b += B.b;
    A.c += B.c;

    return A;
}

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

template<typename T, typename TScale>
Quaternion<T>
operator * (const Quaternion<T>& quaternion, TScale scale)
{
    T scl {static_cast<T>(scale)};

    return Quaternion
    {
        quaternion.s * scl,
        quaternion.a * scl,
        quaternion.b * scl,
        quaternion.c * scl
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
operator * (const Quaternion<T>& A, const Quaternion<T>& B)
{
    return Quaternion
    {
        A.s * B.s - A.a * B.a - A.b * B.b - A.c * B.c,
        A.a * B.s + B.a * A.s + A.b * B.c - A.c * B.b,
        A.b * B.s + B.b * A.s + A.c * B.a - A.a * B.c,
        A.c * B.s + B.c * A.s + A.a * B.b - A.b * B.a
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename TScale>
Quaternion<T>&
operator *= (Quaternion<T>& quaternion, TScale scale)
{
    quaternion.s *= scale;
    quaternion.a *= scale;
    quaternion.b *= scale;
    quaternion.c *= scale;

    return quaternion;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>&
operator *= (Quaternion<T>& A, const Quaternion<T>& B)
{
    A = A * B;

    return A;
}

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

template<typename T, typename TScale>
Quaternion<T>
operator / (const Quaternion<T>& quaternion, TScale scale) {

    return Quaternion<T>
    {
        quaternion.s / scale,
        quaternion.a / scale,
        quaternion.b / scale,
        quaternion.c / scale
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename TScale>
Quaternion<T>&
operator /= (Quaternion<T>& quaternion, TScale scale)
{
    quaternion.s /= scale;
    quaternion.a /= scale;
    quaternion.b /= scale;
    quaternion.c /= scale;

    return quaternion;
}

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

template<typename T>
bool
operator == (const Quaternion<T>& A, const Quaternion<T>& B)
{
    return  equal(A.s, B.s) &&
            equal(A.a, B.a) &&
            equal(A.b, B.b) &&
            equal(A.c, B.c);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
bool
operator != (const Quaternion<T>& A, const Quaternion<T>& B)
{
    return  notEqual(A.s, B.s) ||
            notEqual(A.a, B.a) ||
            notEqual(A.b, B.b) ||
            notEqual(A.c, B.c);
}

/* ####################################################################################### */
/* Dot product */
/* ####################################################################################### */

template<typename T>
T
operator | (const Quaternion<T>& A, const Quaternion<T>& B)
{
    return A.s * B.s + A.a * B.a + A.b * B.b + A.c * B.c;
}

#endif // MATH3D_QUATERNION_OPERATORS_HPP
