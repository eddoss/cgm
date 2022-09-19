#pragma once


#include <cmath>
#include <cgm/modules/shapes/2d/module_globals.hpp>
#include <cgm/modules/shapes/2d/types/range.hpp>
#include <cgm/modules/shapes/2d/types/rectangle.hpp>
#include <cgm/modules/core/types/size.hpp>


CGM_2D_NAMESPACE_BEGIN

/**
 * Calculate size of 2D range.
 * @return Size of range.
 */
template<typename T>
constexpr CGM_FORCEINLINE Size<2,T>
size(const Range<T>& range);

/**
 * Calculate size of 2D rectangle.
 * @return Size of rectangle.
 */
template<typename T>
constexpr CGM_FORCEINLINE Size<2,T>
size(const Rectangle<T>& rectangle);

CGM_2D_NAMESPACE_END


#include "size.inl"
