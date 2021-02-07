#pragma once


#include <CGM/Shapes/2D/Types/Rectangle.hpp>


CGM_2D_NAMESPACE_BEGIN

/**
 * Checks if rectangle A intersects rectangle B.
 * @return True, if rectangles are intersects, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE bool
overlapped(const Rectangle<T>& A, const Rectangle<T>& B);

/**
 * Gets rectangles overlap region.
 * @param[in] A Rectangle to check.
 * @param[in] B Rectangle to check.
 * @param[out] exists Sets true, if intersection is exists, false otherwise will be set.
 * @return Overlap region (rectangle) if exists, zero rectangle otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE Rectangle<T>
overlapping(const Rectangle<T>& A, const Rectangle<T>& B, bool& exists);

CGM_2D_NAMESPACE_END


#include "Overlap.inl"