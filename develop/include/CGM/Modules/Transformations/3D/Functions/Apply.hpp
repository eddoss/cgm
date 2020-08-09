#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Basis.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Typedefs.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/3D/Types/Transforms.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

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

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

/**
 * Applies transformations to 3x3 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to 3x3 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 4x4 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& transforms);

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

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

/* ####################################################################################### */
/* Axes tuple */
/* ####################################################################################### */

/**
 * Applies transformations to axes tuple.
 * @param axes Axes tuple to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(AxesTuple<T>& axes, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to axes tuple.
 * @param axes Axes tuple to apply transformations to.
 * @param transforms 4x4 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(AxesTuple<T>& axes, const Matrix<4,4,T>& transforms);

/* ####################################################################################### */
/* Space tuple */
/* ####################################################################################### */

/**
 * Applies transformations to space tuple.
 * @param space Space tuple to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(SpaceTuple<T>& space, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to space tuple.
 * @param space Space tuple to apply transformations to.
 * @param transforms 4x4 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(SpaceTuple<T>& space, const Matrix<4,4,T>& transforms);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END