#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Cartesian/Common.hpp>
#include <CGM/Modules/Cartesian/2D/Types/Axes.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/3D/Types/Transforms.hpp>
#include <CGM/detail/Modules/Cartesian/3D/InternalUtils.hpp>
#include <CGM/detail/Modules/Transformations/3D/InternalUtils.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<3,T>& vector, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms 4x4 transformation matrix.
 */
template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<3,T>& vector, const Matrix<4,4,T>& transforms);

/**
 * Applies transformations to 3x3 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to 4x4 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to 4x4 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 4x4 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& transforms);

/**
 * Applies transformations to axes struct.
 * @param axes Axes struct to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Axes<T>& axes, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to axes struct.
 * @param axes Axes struct to apply transformations to.
 * @param transforms 4x4 transformation matrix.
 */
template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
apply(Axes<T>& axes, const Matrix<4,4,T>& transforms);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Functions/Apply.hpp>