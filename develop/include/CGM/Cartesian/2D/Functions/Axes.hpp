#pragma once


#include <CGM/Global.hpp>
#include <CGM/Common.hpp>
#include <CGM/Core/Vector.hpp>
#include <CGM/Core/Operators/Vector.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

/**
 * Gets Cartesian X axis.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
x();

/**
 * Gets Cartesian Y axis.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
y();

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END


#include <private/CGM/Cartesian/2D/Functions/Axes.hpp>