#pragma once


#include <CGM/Core/Operators/Vector.hpp>
#include <CGM/Cartesian/2D/Types/Axes.hpp>
#include <CGM/Cartesian/2D/ModuleGlobals.hpp>


/**
 * Compares two axes structs for equality.
 * @param A Axes struct to compare.
 * @param B Axes struct to compare with.
 * @return true if the axes structs are equal, false otherwise.
 */
template<typename T>
constexpr bool
operator == (const CGM_2D::Axes<T>& A, const CGM_2D::Axes<T>& B);

/**
 * Compares two axes structs for inequality.
 * @param A Axes struct to compare.
 * @param B Axes struct to compare with.
 * @return true if the axes structs are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM_2D::Axes<T>& A, const CGM_2D::Axes<T>& B);


#include "Operators.inl"
