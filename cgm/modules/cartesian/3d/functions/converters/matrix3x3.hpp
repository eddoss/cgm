#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/cartesian/3d/types/quaternion.hpp>
#include <cgm/modules/core/operators/matrix_vector_multiplication.hpp>
#include <cgm/modules/core/functions/matrix.hpp>
#include <cgm/modules/cartesian/3d/functions/quaternion.hpp>
#include <cgm/modules/cartesian/common.hpp>
#include <cgm/modules/cartesian/3d/module_globals.hpp>
#include <cgm/modules/cartesian/3d/functions/orientation.hpp>
#include <cgm/modules/cartesian/3d/functions/utils.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

/**
 * Convert orientation from given space to another space. If 'Space' is 'Global' it mean
 * orientation will be converted to from local to global (and vice versa).
 * @tparam Space Space to convert to.
 * @param matrix 3x3 orientation matrix to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientation);

/**
 * Convert orientation from given space to another space. If 'Space' is 'Global' it mean
 * orientation will be converted to from local to global (and vice versa).
 * @tparam Space Space to convert to.
 * @param matrix 3x3 orientation matrix to convert.
 * @param space Local basis whose orientation will be used.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& space);

/**
 * Convert orientation from given space to another space. If 'Space' is 'Global' it mean
 * orientation will be converted to from local to global (and vice versa).
 * @tparam Space Space to convert to.
 * @param matrix 3x3 orientation matrix to convert.
 * @param orientation orientation Local space orientation represented by quaternion.
 */
template<ESpace Space, typename T>
constexpr void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientation);

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB);

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB);

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
/* ####################################################################################### */

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB);

/* ####################################################################################### */
/* Global to local / local to global (outplace) */
/* ####################################################################################### */

/**
 * Convert orientation from given space to another space. If 'Space' is 'Global' it mean
 * orientation will be converted to from local to global (and vice versa).
 * @tparam Space Space to convert to.
 * @param matrix 3x3 orientation matrix to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 * @return Converted orientation matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientation);

/**
 * Convert orientation from given space to another space. If 'Space' is 'Global' it mean
 * orientation will be converted to from local to global (and vice versa).
 * @tparam Space Space to convert to.
 * @param matrix 3x3 orientation matrix to convert.
 * @param space Local basis whose orientation will be used.
 * @return Converted orientation matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<4,4,T>& space);

/**
 * Convert orientation from given space to another space. If 'Space' is 'Global' it mean
 * orientation will be converted to from local to global (and vice versa).
 * @tparam Space Space to convert to.
 * @param matrix 3x3 orientation matrix to convert.
 * @param orientation orientation Local space orientation represented by quaternion.
 * @return Converted orientation matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Quaternion<T>& orientation);

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB);

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB);

/* ####################################################################################### */
/* Local to local: Quaternion (outplace) */
/* ####################################################################################### */

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 3x3 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB);

CGM_NAMESPACE_END


#include "matrix3x3.inl"
