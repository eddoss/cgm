#ifndef MATH3D_AXES_HPP
#define MATH3D_AXES_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Platform.hpp>
#include <Math3D/Core/Vector/Vector.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_AXES_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

/**
 * Cartesian x axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
x();

/**
 * Cartesian system y axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
y();

/**
 * Cartesian system z axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
z();

/* ####################################################################################### */
/* Cartesian system axes */
/* ####################################################################################### */

/**
 * Return Cartesian system up axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
up();

/**
 * Return Cartesian system right axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
right();

/**
 * Return Cartesian system forward axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
forward();

/**
 * Return Cartesian system down axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
down();

/**
 * Return Cartesian system left axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
left();

/**
 * Return Cartesian system backward axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
backward();

/* ####################################################################################### */
/* Utils */
/* ####################################################################################### */

/**
 * Create Cartesian coordinate independently from axes labels.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
makeCoord(T right, T up, T forward);

/**
 * Extracts the vector component responsible for "Right" axis coordinate.
 * @return Reference to component.
 */
template<typename T>
constexpr FORCEINLINE T&
rightComponent(Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Up" axis coordinate.
 * @return Reference to component.
 */
template<typename T>
constexpr FORCEINLINE T&
upComponent(Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Forward" axis coordinate.
 * @return Reference to component.
 */
template<typename T>
constexpr FORCEINLINE T&
forwardComponent(Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Right" axis coordinate.
 * @return Const reference to component.
 */
template<typename T>
constexpr FORCEINLINE const T&
rightComponent(const Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Up" axis coordinate.
 * @return Const reference to component.
 */
template<typename T>
constexpr FORCEINLINE const T&
upComponent(const Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Forward" axis coordinate.
 * @return Const reference to component.
 */
template<typename T>
constexpr FORCEINLINE const T&
forwardComponent(const Vector<3,T>& coord);

MATH3D_AXES_NAMESPACE_END
MATH3D_NAMESPACE_END

#include <private/Math3D/Core/Axes.hpp>

#endif // MATH3D_AXES_HPP