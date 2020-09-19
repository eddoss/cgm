#pragma once


#include <initializer_list>
#include <CGM/detail/Modules/Core/Types/Vector.hpp>
#include <CGM/detail/Modules/Core/Types/Matrix.hpp>
#include <CGM/detail/Modules/Cartesian/Common.hpp>
#include <CGM/detail/Modules/Cartesian/2D/Types/Axes.hpp>
#include <CGM/detail/Modules/Transformations/Common.hpp>
#include <CGM/detail/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/detail/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/detail/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/detail/Modules/Transformations/3D/Types/Transforms.hpp>
#include <CGM/detail/Modules/Cartesian/3D/InternalUtils_impl.hpp>
#include <CGM/detail/Modules/Transformations/3D/InternalUtils_impl.hpp>

/* ####################################################################################### */
/* Inplace */
/* ####################################################################################### */

CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/**
 * Applies transformation to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<3,T>& vector, const Matrix<3,3,T>& transforms);

/**
 * Applies transformation to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms 4x4 transformation matrix.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<3,T>& vector, const Matrix<4,4,T>& transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms List of 3x3 transformations matrices.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<3,T>& vector, std::initializer_list<Matrix<3,3,T>> transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms List of 4x4 transformations matrices.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<3,T>& vector, std::initializer_list<Matrix<4,4,T>> transforms);

/**
 * Applies transformation to 3x3 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to 3x3 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 3x3 transformation matrices.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<3,3,T>& matrix, std::initializer_list<Matrix<3,3,T>> transforms);

/**
 * Applies transformation to 4x4 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 4x4 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& transforms);

/**
 * Applies transformations to 4x4 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 4x4 transformation matrices.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<4,4,T>& matrix, std::initializer_list<Matrix<4,4,T>> transforms);

/* ####################################################################################### */
/* Outplace */
/* ####################################################################################### */

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 * @return Copy of transformed vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
applied(const Vector<3,T>& vector, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms 4x4 transformation matrix.
 * @return Copy of transformed vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
applied(const Vector<3,T>& vector, const Matrix<4,4,T>& transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms List of 3x3 transformations matrices.
 * @return Copy of transformed vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
applied(const Vector<3,T>& vector, std::initializer_list<Matrix<3,3,T>> transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms List of 4x4 transformations matrices.
 * @return Copy of transformed vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
applied(const Vector<3,T>& vector, std::initializer_list<Matrix<4,4,T>> transforms);

/**
 * Applies transformations to 3x3 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 * @return Copy of transformed matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
applied(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to 3x3 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 3x3 transformation matrices.
 * @return Copy of transformed matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
applied(const Matrix<3,3,T>& matrix, std::initializer_list<Matrix<3,3,T>> transforms);

/**
 * Applies transformations to 4x4 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 4x4 transformation matrix.
 * @return Copy of transformed matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
applied(const Matrix<4,4,T>& matrix, const Matrix<4,4,T>& transforms);

/**
 * Applies transformations to 4x4 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 4x4 transformation matrices.
 * @return Copy of transformed matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
applied(const Matrix<4,4,T>& matrix, std::initializer_list<Matrix<4,4,T>> transforms);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Functions/Apply_impl.hpp>
