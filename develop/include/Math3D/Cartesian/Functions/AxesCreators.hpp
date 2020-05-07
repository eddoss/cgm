#ifndef MATH3D_XYZ_FUNCTIONS_AXES_CREATORS_HPP
#define MATH3D_XYZ_FUNCTIONS_AXES_CREATORS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

/**
 * Gets Cartesian x axis.
 * @tparam D space dimensions. Valid values are 2 and 3.
 */
template<size_t D=3, typename T=FLOAT>
constexpr FORCEINLINE std::enable_if_t<(D == 2 || D == 3), Vector<D,T>>
x();

/**
 * Gets Cartesian system y axis.
 * @tparam D space dimensions. Valid values are 2 and 3.
 */
template<size_t D=3, typename T=FLOAT>
constexpr FORCEINLINE std::enable_if_t<(D == 2 || D == 3), Vector<D,T>>
y();

/**
 * Gets Cartesian system z axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
z();

/* ####################################################################################### */
/* Cartesian system axes */
/* ####################################################################################### */

/**
 * Gets Cartesian system up axis.
 * @tparam D space dimensions. Valid values are 2 and 3.
 */
template<size_t D=3, typename T=FLOAT>
constexpr FORCEINLINE Vector<D,T>
up();

/**
 * Gets Cartesian system right axis.
 * @tparam D space dimensions. Valid values are 2 and 3.
 */
template<size_t D=3, typename T=FLOAT>
constexpr FORCEINLINE Vector<D,T>
right();

/**
 * Gets Cartesian system forward axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
forward();

/**
 * Gets Cartesian system down axis.
 */
template<size_t D=3, typename T=FLOAT>
constexpr FORCEINLINE Vector<D,T>
down();

/**
 * Gets Cartesian system left axis.
 */
template<size_t D=3, typename T=FLOAT>
constexpr FORCEINLINE Vector<D,T>
left();

/**
 * Gets Cartesian system backward axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
backward();

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/Functions/AxesCreators.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_AXES_CREATORS_HPP
