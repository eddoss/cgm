#pragma once


#include <CGM/Cartesian/3D/Types/Quaternion.hpp>
#include <CGM/Core/Functions/Vector.hpp>


/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

/**
 * Get a negated copy of the quaternion.
 * @return A negated copy of the quaternion.
 */
template<typename T>
constexpr CGM_XYZ::Quaternion<T>
operator - (const CGM_XYZ::Quaternion<T>& quaternion);

/**
 * Gets the result of subtraction quaternion "A" and quaternion "B".
 * @return The result of quaternion subtraction.
 */
template<typename T>
constexpr CGM_XYZ::Quaternion<T>
operator - (const CGM_XYZ::Quaternion<T>& A, const CGM_XYZ::Quaternion<T>& B);

/**
 * Subtracts quaternion "B" from quaternion "B".
 * @return The result of quaternion subtraction.
 */
template<typename T>
constexpr CGM_XYZ::Quaternion<T>&
operator -= (CGM_XYZ::Quaternion<T>& A, const CGM_XYZ::Quaternion<T>& B);

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

/**
 * Gets the result of adding quaternion "A" and quaternion "B".
 * @return The result of quaternion adding.
 */
template<typename T>
constexpr CGM_XYZ::Quaternion<T>
operator + (const CGM_XYZ::Quaternion<T>& A, const CGM_XYZ::Quaternion<T>& B);

/**
 * Add quaternion "A" and quaternion "B".
 * @return The result of adding subtraction.
 */
template<typename T>
constexpr CGM_XYZ::Quaternion<T>&
operator += (CGM_XYZ::Quaternion<T>& A, const CGM_XYZ::Quaternion<T>& B);

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

/**
 * Multiply quaternion by a scaling factor.
 * @return The result of scaling.
 */
template<typename T, typename TScale>
constexpr CGM_XYZ::Quaternion<T>
operator * (const CGM_XYZ::Quaternion<T>& quaternion, TScale scale);

/**
 * Gets the result of multiplication quaternion "A" and quaternion "B".
 * @return The result of quaternion multiplication.
 */
template<typename T>
constexpr CGM_XYZ::Quaternion<T>
operator * (const CGM_XYZ::Quaternion<T>& A, const CGM_XYZ::Quaternion<T>& B);

/**
 * Multiply quaternion by a scaling factor.
 * @return The result of scaling.
 */
template<typename T, typename TScale>
constexpr CGM_XYZ::Quaternion<T>&
operator *= (CGM_XYZ::Quaternion<T>& quaternion, TScale scale);

/**
 * Gets the result of multiplication quaternion "A" and quaternion "B".
 * @return The result of quaternion multiplication.
 */
template<typename T>
constexpr CGM_XYZ::Quaternion<T>&
operator *= (CGM_XYZ::Quaternion<T>& A, const CGM_XYZ::Quaternion<T>& B);

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

/**
 * Divide this quaternion by scale.
 * @return Results of division.
 */
template<typename T, typename TDivider>
constexpr CGM_XYZ::Quaternion<T>
operator / (const CGM_XYZ::Quaternion<T>& quaternion, TDivider divider);

/**
 * Divide this quaternion by scale.
 * @return Results of division.
 */
template<typename T, typename TDivider>
constexpr CGM_XYZ::Quaternion<T>&
operator /= (CGM_XYZ::Quaternion<T>& quaternion, TDivider divider);

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

/**
 * Checks whether quaternion "A" is equal to quaternion "B".
 * @return true if the quaternion are equal, false otherwise.
 */
template<typename T>
constexpr bool
operator == (const CGM_XYZ::Quaternion<T>& A, const CGM_XYZ::Quaternion<T>& B);

/**
 * Checks whether quaternion "A" is not equal to quaternion "B".
 * @return true if the quaternion are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM_XYZ::Quaternion<T>& A, const CGM_XYZ::Quaternion<T>& B);

/* ####################################################################################### */
/* Dot product */
/* ####################################################################################### */

/**
 * Calculates dot product of two quaternions.
 * @return The dot product.
 */
template<typename T>
constexpr T
operator | (const CGM_XYZ::Quaternion<T>& A, const CGM_XYZ::Quaternion<T>& B);


#include "Quaternion.inl"