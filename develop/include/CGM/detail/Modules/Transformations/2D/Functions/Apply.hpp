#pragma once


#include <CGM/detail/Modules/Core/Types/Vector.hpp>
#include <CGM/detail/Modules/Core/Types/Matrix.hpp>
#include <CGM/detail/Modules/Cartesian/Common.hpp>
#include <CGM/detail/Modules/Cartesian/2D/Types/Axes.hpp>
#include <CGM/detail/Modules/Transformations/Common.hpp>
#include <CGM/detail/Modules/Transformations/2D/ModuleGlobals.hpp>
#include <CGM/detail/Modules/Transformations/2D/Types/Pivot.hpp>
#include <CGM/detail/Modules/Transformations/2D/Types/Transforms.hpp>
#include <CGM/detail/Modules/Cartesian/2D/InternalUtils_impl.hpp>
#include <CGM/detail/Modules/Transformations/2D/InternalUtils_impl.hpp>

/* ####################################################################################### */
/* Inplace */
/* ####################################################################################### */

CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<2,T>& vector, const Matrix<2,2,T>& transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<2,T>& vector, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms List of 2x2 transformations matrices.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<2,T>& vector, std::initializer_list<Matrix<2,2,T>> transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms List of 3x3 transformations matrices.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<2,T>& vector, std::initializer_list<Matrix<3,3,T>> transforms);

/**
 * Applies transformations to 3x3 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<2,2,T>& matrix, const Matrix<2,2,T>& transforms);

/**
 * Applies transformations to 2x2 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 2x2 transformation matrices.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<2,2,T>& matrix, std::initializer_list<Matrix<2,2,T>> transforms);

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
 * @param transforms 3x3 transformation matrices.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<3,3,T>& matrix, std::initializer_list<Matrix<3,3,T>> transforms);

/* ####################################################################################### */
/* Outplace */
/* ####################################################################################### */

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms 2x2 transformation matrix.
 * @return Copy of transformed vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
applied(const Vector<2,T>& vector, const Matrix<2,2,T>& transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms 3x3 transformation matrix.
 * @return Copy of transformed vector.
 */
template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
applied(const Vector<2,T>& vector, const Matrix<3,3,T>& transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms List of 2x2 transformations matrices.
 * @return Copy of transformed vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
applied(const Vector<2,T>& vector, std::initializer_list<Matrix<2,2,T>> transforms);

/**
 * Applies transformations to vector.
 * @param vector Vector to apply transformations to.
 * @param transforms List of 3x3 transformations matrices.
 * @return Copy of transformed vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
applied(const Vector<2,T>& vector, std::initializer_list<Matrix<3,3,T>> transforms);

/**
 * Applies transformations to 2x2 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 2x2 transformation matrix.
 * @return Copy of transformed matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
applied(const Matrix<2,2,T>& matrix, const Matrix<2,2,T>& transforms);

/**
 * Applies transformations to 2x2 matrix.
 * @param matrix Matrix to apply transformations to.
 * @param transforms 2x2 transformation matrices.
 * @return Copy of transformed matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
applied(const Matrix<2,2,T>& matrix, std::initializer_list<Matrix<2,2,T>> transforms);

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

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/2D/Functions/Apply_impl.hpp>
