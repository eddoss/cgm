#pragma once


#include <cmath>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/coordinates/module_globals.hpp>
#include <cgm/modules/coordinates/types/polar.hpp>
#include <cgm/modules/coordinates/types/spherical.hpp>
#include <cgm/modules/coordinates/types/cylindrical.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

/**
 * Extracts the vector component responsible for "Right" axis coordinate.
 * @return Reference to component.
 */
template<typename T>
constexpr CGM_FORCEINLINE T&
right(Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Up" axis coordinate.
 * @return Reference to component.
 */
template<typename T>
constexpr CGM_FORCEINLINE T&
up(Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Forward" axis coordinate.
 * @return Reference to component.
 */
template<typename T>
constexpr CGM_FORCEINLINE T&
forward(Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Right" axis coordinate.
 * @return Const reference to component.
 */
template<typename T>
constexpr CGM_FORCEINLINE const T&
right(const Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Up" axis coordinate.
 * @return Const reference to component.
 */
template<typename T>
constexpr CGM_FORCEINLINE const T&
up(const Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Forward" axis coordinate.
 * @return Const reference to component.
 */
template<typename T>
constexpr CGM_FORCEINLINE const T&
forward(const Vector<3,T>& coord);

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END


#include "vector_components.inl"
