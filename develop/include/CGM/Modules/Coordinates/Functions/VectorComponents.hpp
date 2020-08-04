#pragma once


#include <cmath>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Coordinates/ModuleGlobals.hpp>
#include <CGM/Modules/Coordinates/Types/Polar.hpp>
#include <CGM/Modules/Coordinates/Types/Spherical.hpp>
#include <CGM/Modules/Coordinates/Types/Cylindrical.hpp>


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


#include <CGM/detail/Modules/Coordinates/Functions/VectorComponents.hpp>