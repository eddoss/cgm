#pragma once


#include <cgm/modules/shapes/2d/types/range.hpp>
#include <cgm/modules/shapes/2d/types/rectangle.hpp>


CGM_2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Ranges */
/* ####################################################################################### */

/**
 * Gets range top let corner position.
 * @return Top let corner position
 */
constexpr CGM_FORCEINLINE Vector<2,T>
topLeft(const Range<T>& range) const;

/**
 * Gets range top right corner position.
 * @return Top right corner position
 */
constexpr CGM_FORCEINLINE Vector<2,T>
topRight(const Range<T>& range) const;

/**
 * Gets range bottom let corner position.
 * @return Bottom let corner position
 */
constexpr CGM_FORCEINLINE Vector<2,T>
bottomLeft(const Range<T>& range) const;

/**
 * Gets range bottom right corner position.
 * @return Bottom right corner position
 */
constexpr CGM_FORCEINLINE Vector<2,T>
bottomRight(const Range<T>& range) const;

/* ####################################################################################### */
/* Rectangle */
/* ####################################################################################### */

/**
 * Gets rectangle top let corner position.
 * @return Top let corner position
 */
constexpr CGM_FORCEINLINE Vector<2,T>
topLeft(const Rectangle<T>& rectangle) const;

/**
 * Gets rectangle top right corner position.
 * @return Top right corner position
 */
constexpr CGM_FORCEINLINE Vector<2,T>
topRight(const Rectangle<T>& rectangle) const;

/**
 * Gets rectangle bottom let corner position.
 * @return Bottom let corner position
 */
constexpr CGM_FORCEINLINE Vector<2,T>
bottomLeft(const Rectangle<T>& rectangle) const;

/**
 * Gets rectangle bottom right corner position.
 * @return Bottom right corner position
 */
constexpr CGM_FORCEINLINE Vector<2,T>
bottomRight(const Rectangle<T>& rectangle) const;

CGM_2D_NAMESPACE_END


#include "corners.inl"
