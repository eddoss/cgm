#pragma once


#include <tuple>
#include <algorithm>
#include <cgm/modules/core/operators/vector.hpp>
#include <cgm/modules/shapes/2d/types/rectangle.hpp>


CGM_2D_NAMESPACE_BEGIN

/**
 * Checks if rectangle A intersects rectangle B.
 * @return True, if rectangles are intersects, false otherwise.
 */
template<typename T>
constexpr bool
overlapped(const Rectangle<T>& A, const Rectangle<T>& B);

/**
 * Gets rectangles overlap region.
 * @param A Rectangle to check.
 * @param B Rectangle to check.
 * @return Overlap region (rectangle) and true, if exists, zero rectangle and false otherwise.
 */
template<typename T>
constexpr std::tuple<Rectangle<T>, bool>
overlapping(const Rectangle<T>& A, const Rectangle<T>& B);

CGM_2D_NAMESPACE_END


#include "overlap.inl"
