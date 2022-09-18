#pragma once


#include <cgm/modules/core/operators/vector.hpp>
#include <cgm/modules/cartesian/2d/types/axes.hpp>
#include <cgm/modules/cartesian/2d/module_globals.hpp>


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


#include "operators.inl"
