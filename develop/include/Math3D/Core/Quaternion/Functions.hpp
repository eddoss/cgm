#ifndef MATH3D_QUATERNION_FUNCTIONS_HPP
#define MATH3D_QUATERNION_FUNCTIONS_HPP


#include <cmath>
#include <type_traits>
#include <Math3D/Core/Quaternion/Quaternion.hpp>
#include <Math3D/Core/Quaternion/Operators.hpp>


/**
 * Calculates dot product of two quaternions.
 * @return The dot product.
 */
template<typename T>
T
dot(const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Make quaternion conjugated.
 * @return The conjugated quaternion.
 */
template<typename T>
Quaternion<T>&
conjugate(Quaternion<T>& quaternion);

/**
 * Get the conjugate of the quaternion.
 * @return The conjugated quaternion.
 */
template<typename T>
Quaternion<T>
conjugated(const Quaternion<T>& quaternion);

/**
 * Get the length of the quaternion.
 * @return The length of this quaternion.
 */
template<typename TResult=FLOAT, typename T>
TResult
length(const Quaternion<T>& quaternion);

/**
 * Get the squared length of the quaternion.
 * @return The squared length of the quaternion.
 */
template<typename T>
T
lengthSquared(const Quaternion<T>& quaternion);

/**
 * Normalize the quaternion if it is large enough.
 * If it is too small, returns an no changed quaternion.
 */
template<typename T>
Quaternion<T>&
normalize(Quaternion<T>& quaternion);

/**
 * Return normalized copy of the quaternion if it is large enough.
 * If it is too small, returns an no changed copy.
 * @return normalized quternion.
 */
template<typename T>
Quaternion<T>
normalized(const Quaternion<T>& quaternion);

/**
 * Invert the quaternion if it is large enough.
 * If it is too small, returns an no changed quaternion.
 * @return Inverted quaternion.
 */
template<typename T>
Quaternion<T>&
invert(Quaternion<T>& quaternion);

/**
 * Get inverted copy of the quaternion if it is large enough.
 * If it is too small, returns an no changed copy.
 * @return Inverted quaternion.
 */
template<typename T>
Quaternion<T>
inverted(const Quaternion<T>& quaternion);

/**
 * Create identity quaternion.
 * @return Identity quaternion.
 */
template<typename T=FLOAT>
constexpr Quaternion<T>
identity();

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<typename T>
T
dot(const Quaternion<T> &A, const Quaternion<T> &B)
{
    return A | B;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>&
conjugate(Quaternion<T>& quaternion)
{
    quaternion.a *= -1;
    quaternion.b *= -1;
    quaternion.c *= -1;

    return quaternion;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
conjugated(const Quaternion<T>& quaternion)
{
    return Quaternion<T>
    {
        quaternion.s,
        quaternion.a * -1,
        quaternion.b * -1,
        quaternion.c * -1
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename TResult, typename T>
TResult
length(const Quaternion<T>& quaternion)
{
    TResult sum {dot(quaternion, quaternion)};
    TResult zer {zero<TResult>()};

    if (equal(sum,zer))
    {
        return zer;
    }
    else
    {
        return static_cast<TResult>(sqrt(sum));
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
T
lengthSquared(const Quaternion<T>& quaternion)
{
    return dot(quaternion, quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>&
normalize(Quaternion<T>& quaternion)
{
    T len {length<T>(quaternion)};

    if (notEqual(len, zero<T>()))
    {
        quaternion /= len;
    }

    return quaternion;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
normalized(const Quaternion<T>& quaternion)
{
    auto copy {quaternion};
    normalize(copy);
    return copy;
}

template<typename T>
Quaternion<T>&
invert(Quaternion<T>& quaternion)
{
    return conjugate(quaternion) /= lengthSquared(quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
inverted(const Quaternion<T>& quaternion)
{
    auto copy {quaternion};
    invert(copy);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>
identity()
{
    return Quaternion<T>
    {
        number<T>(1),
        zero<T>(),
        zero<T>(),
        zero<T>()
    };
}

#endif // MATH3D_QUATERNION_FUNCTIONS_HPP
