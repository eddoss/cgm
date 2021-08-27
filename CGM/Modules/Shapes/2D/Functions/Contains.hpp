#pragma once


#include <CGM/Modules/Shapes/2D/Types/Rectangle.hpp>


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

CGM_2D_NAMESPACE_END


#include "Contains.inl"