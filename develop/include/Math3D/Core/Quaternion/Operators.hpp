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
 * Gets the result of subtraction of this by another quaternion.
 * @param quaternion The quaternion to subtract from this.
 * @return The result of quaternion subtraction.
 */
template<typename T>
Quaternion<T>
operator - (const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Subtracts another quaternion from this.
 * @param quaternion The quaternion to subtract from this.
 * @return The result of quaternion subtraction.
 */
template<typename T>
Quaternion<T>&
operator -= (Quaternion<T>& A, const Quaternion<T>& B);

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

/**
 * Gets the result of adding this to another quaternion.
 * @param quaternion The quaternion to add to this.
 * @return The result of quaternion adding.
 */
template<typename T>
Quaternion<T>
operator + (const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Add another quaternion to this.
 * @param quaternion The quaternion to add to this.
 * @return The result of quaternion adding.
 */
template<typename T>
Quaternion<T>&
operator += (Quaternion<T>& A, const Quaternion<T>& B);

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

/**
 * Multiply this quaternion by a scaling factor.
 * @param scale The scaling factor.
 * @return The result of scaling.
 */
template<typename T, typename TScale>
Quaternion<T>
operator * (TScale scale);

/**
 * Gets the result of multiplying this to another quaternion.
 * @param quaternion The quaternion to multiply this by.
 * @return The result of multiplication.
 */
template<typename T>
Quaternion<T>
operator * (const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Multiply this quaternion by a scaling factor.
 * @param scale The scaling factor.
 * @return The result of scaling.
 */
template<typename T, typename TScale>
Quaternion<T>&
operator *= (Quaternion<T>& quaternion, TScale scale);

/**
 * Multiply this by a quaternion.
 * @param quaternion The quaternion to multiply this by.
 * @return The result of multiplication.
 */
template<typename T>
Quaternion<T>&
operator *= (Quaternion<T>& A, const Quaternion<T>& B);

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

/**
 * Divide this quaternion by scale.
 * @param scale What to divide by.
 * @return Results of division.
 */
template<typename T, typename TScale>
Quaternion<T>
operator / (const Quaternion<T>& quaternion, TScale scale);

/**
 * Divide this quaternion by scale.
 * @param scale What to divide by.
 * @return Results of division.
 */
template<typename T, typename TScale>
Quaternion<T>&
operator /= (Quaternion<T>& quaternion, TScale scale);

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

/**
 * Checks whether another quaternion is equal to this.
 * @param quaternion The quaternion to check against.
 * @return true if the quaternion are equal, false otherwise.
 */
template<typename T>
bool
operator == (const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Checks whether another quaternion is not equal to this.
 * @param quaternion The quaternion to check against.
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
 * @param quaternion The other quaternion.
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

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
operator - (const Quaternion<T>& A, const Quaternion<T>& B)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>&
operator -= (Quaternion<T>& A, const Quaternion<T>& B)
{

}

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

template<typename T>
Quaternion<T>
operator + (const Quaternion<T>& A, const Quaternion<T>& B)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>&
operator += (Quaternion<T>& A, const Quaternion<T>& B)
{

}

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

template<typename T, typename TScale>
Quaternion<T>
operator * (TScale scale)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
operator * (const Quaternion<T>& A, const Quaternion<T>& B)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename TScale>
Quaternion<T>&
operator *= (Quaternion<T>& quaternion, TScale scale)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>&
operator *= (Quaternion<T>& A, const Quaternion<T>& B)
{

}

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

template<typename T, typename TScale>
Quaternion<T>
operator / (const Quaternion<T>& quaternion, TScale scale)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename TScale>
Quaternion<T>&
operator /= (Quaternion<T>& quaternion, TScale scale)
{

}

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

template<typename T>
bool
operator == (const Quaternion<T>& A, const Quaternion<T>& B)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
bool
operator != (const Quaternion<T>& A, const Quaternion<T>& B)
{

}

/* ####################################################################################### */
/* Dot product */
/* ####################################################################################### */

template<typename T>
T
operator | (const Quaternion<T>& A, const Quaternion<T>& B)
{

}

#endif // MATH3D_QUATERNION_OPERATORS_HPP
