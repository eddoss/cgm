#pragma once


#include <CGM/Shapes/2D/Types/Rectangle.hpp>


CGM_2D_NAMESPACE_BEGIN

/**
 * Checks whether is point inside rectangle or not.
 * @return True, if point is inside rectangle, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE bool
contains(const Rectangle<T>& rect, const Vector<2,T>& point);

CGM_2D_NAMESPACE_END


#include "Contains.inl"