#ifndef MATH3D_QUATERNION_FUNCTIONS_HPP
#define MATH3D_QUATERNION_FUNCTIONS_HPP


#include <cmath>
#include <type_traits>
#include <Math3D/Core/Quaternion/Quaternion.hpp>
#include <Math3D/Core/Quaternion/Operators.hpp>


/**
 * Calculates dot product of two quaternions.
 * @param quaternion The other quaternion.
 * @return The dot product.
 */
template<typename T>
T
dot(const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Make this quaternion conjugated.
 */
template<typename T>
Quaternion<T>&
conjugate(Quaternion<T>& quaternion);

/**
 * Get the conjugate of this quaternion.
 * @return The conjugated quaternion.
 */
template<typename T>
Quaternion<T>
conjugated(const Quaternion<T>& quaternion);

/**
 * Get the length of this quaternion.
 * @return The length of this quaternion.
 */
template<typename TResult=FLOAT, typename T>
TResult
length(const Quaternion<T>& quaternion);

/**
 * Get the length squared of this quaternion.
 * @return The length of this quaternion.
 */
template<typename T>
T
lengthSquared(const Quaternion<T>& quaternion);

/**
 * Normalize this quaternion if it is large enough.
 * If it is too small, returns an identity quaternion.
 */
template<typename T>
void
normalize(Quaternion<T> quaternion);

/**
 * Return normalized copy of this quaternion if it is large enough.
 * If it is too small, returns an identity quaternion.
 * @return normalized quternion.
 */
template<typename T>
Quaternion<T>
normalized(const Quaternion<T>& quaternion);

/**
 * Invert this quaternion.
 * @return Inverted quaternion.
 */
template<typename T>
Quaternion<T>&
invert(Quaternion<T>& quaternion);

/**
 * Get inverted copy of this quaternion.
 * @return Inverted quaternion.
 */
template<typename T>
Quaternion<T>
inverted(const Quaternion<T>& quaternion);

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<typename T>
T
dot(const Quaternion<T> &A, const Quaternion<T> &B)
{
    return nullptr;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>&
conjugate(Quaternion<T>& quaternion)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
conjugated(const Quaternion<T>& quaternion)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename TResult, typename T>
TResult
length(const Quaternion<T>& quaternion)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
T
lengthSquared(const Quaternion<T>& quaternion)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
void
normalize(Quaternion<T> quaternion)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
normalized(const Quaternion<T>& quaternion)
{

}

template<typename T>
Quaternion<T>&
invert(Quaternion<T>& quaternion)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
inverted(const Quaternion<T>& quaternion)
{

}

#endif // MATH3D_QUATERNION_FUNCTIONS_HPP
