#pragma once


#include <initializer_list>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/functions/matrix.hpp>
#include <cgm/modules/cartesian/common.hpp>
#include <cgm/modules/cartesian/3d/types/axes.hpp>
#include <cgm/modules/cartesian/3d/functions/utils.hpp>
#include <cgm/modules/transformations/common.hpp>
#include <cgm/modules/transformations/3d/module_globals.hpp>
#include <cgm/modules/transformations/3d/types/enums.hpp>
#include <cgm/modules/transformations/3d/types/pivot.hpp>
#include <cgm/modules/transformations/3d/types/transforms.hpp>


/* ####################################################################################### */
/* Inplace */
/* ####################################################################################### */

CGM_NAMESPACE_BEGIN

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

CGM_NAMESPACE_END


#include "apply.inl"
