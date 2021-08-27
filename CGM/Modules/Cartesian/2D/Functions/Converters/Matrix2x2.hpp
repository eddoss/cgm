#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Core/Operators/MatrixVectorMultiplication.hpp>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Cartesian/Common.hpp>
#include <CGM/Modules/Cartesian/2D/ModuleGlobals.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Orientation.hpp>


CGM_2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

/**
 * Convert orientation from given space to another space. If 'Space' is 'Global' it mean
 * orientation will be converted to from local to global (and vice versa).
 * @tparam Space Space to convert to.
 * @param matrix 2x2 orientation matrix to convert.
 * @param orientation Local space orientation represented by 2x2 matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientation);

/**
 * Convert orientation from given space to another space. If 'Space' is 'Global' it mean
 * orientation will be converted to from local to global (and vice versa).
 * @tparam Space Space to convert to.
 * @param matrix 2x2 orientation matrix to convert.
 * @param space Local basis whose orientation will be used.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<3,3,T>& space);

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 2x2 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 2x2 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 3x3 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 2x2 orientation matrix in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 2x2 orientation matrix in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 3x3 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB);

/* ####################################################################################### */
/* Global to local / local to global (outplace) */
/* ####################################################################################### */

/**
 * Convert orientation from given space to another space. If 'Space' is 'Global' it mean
 * orientation will be converted to from local to global (and vice versa).
 * @tparam Space Space to convert to.
 * @param matrix 2x2 orientation matrix to convert.
 * @param orientation Local space orientation represented by 2x2 matrix.
 * @return Converted orientation matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientation);

/**
 * Convert orientation from given space to another space. If 'Space' is 'Global' it mean
 * orientation will be converted to from local to global (and vice versa).
 * @tparam Space Space to convert to.
 * @param matrix 2x2 orientation matrix to convert.
 * @param space Local basis whose orientation will be used.
 * @return Converted orientation matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<3,3,T>& space);

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 2x2 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 2x2 orientation matrix in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 3x3 matrix of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 2x2 orientation matrix in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB);

/**
 * Convert orientation from space A to space B (A and B are in one space).
 * @param matrix 2x2 orientation matrix in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 3x3 matrix of B space.
 * @return Converted orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB);

CGM_2D_NAMESPACE_END


#include "Matrix2x2.inl"
