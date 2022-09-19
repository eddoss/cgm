#pragma once


#include <cgm/modules/shapes/2d/types/rectangle.hpp>
#include <cgm/modules/shapes/2d/types/range.hpp>


CGM_2D_NAMESPACE_BEGIN

/**
 * Checks whether is point inside rectangle or not.
 * @return True, if point is inside rectangle, false otherwise.
 */
template<typename T>
constexpr bool
contains(const Rectangle<T>& rect, const Vector<2,T>& point);

/**
 * Checks whether all B rectangle points are inside A rectangle or not.
 * @return True, if all points are inside, false otherwise.
 */
template<typename T>
constexpr bool
contains(const Rectangle<T>& A, const Rectangle<T>& B);

/**
 * Checks whether is point inside range or not.
 * @return True, if point is inside range, false otherwise.
 */
template<typename T>
constexpr bool
contains(const Range<T>& range, const Vector<2,T>& point);

/**
 * Checks whether all B range is inside A range or not.
 * @return True, if all points are inside, false otherwise.
 */
template<typename T>
constexpr bool
contains(const Range<T>& A, const Range<T>& B);

CGM_2D_NAMESPACE_END


#include "contains.inl"
