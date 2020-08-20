#pragma once


#include <CGM/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Axes.hpp>
#include <CGM/Modules/Cartesian/3D/ModuleGlobals.hpp>


/**
 * Compares two axes structs for equality.
 * @param A Axes struct to compare.
 * @param B Axes struct to compare with.
 * @return true if the axes structs are equal, false otherwise.
 */
template<typename T>
constexpr bool
operator == (const CGM_XYZ::Axes<T>& A, const CGM_XYZ::Axes<T>& B);

/**
 * Compares two axes structs for inequality.
 * @param A Axes struct to compare.
 * @param B Axes struct to compare with.
 * @return true if the axes structs are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM_XYZ::Axes<T>& A, const CGM_XYZ::Axes<T>& B);


#include <CGM/detail/Modules/Cartesian/3D/Operators.hpp>