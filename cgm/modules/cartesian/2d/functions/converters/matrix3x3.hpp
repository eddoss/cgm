#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/operators/matrix_vector_multiplication.hpp>
#include <cgm/modules/core/functions/matrix.hpp>
#include <cgm/modules/cartesian/common.hpp>
#include <cgm/modules/cartesian/2d/module_globals.hpp>
#include <cgm/modules/cartesian/2d/functions/orientation.hpp>


CGM_2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

/**
 * Convert vector from given space to another space. If 'Space' is 'Global' it mean vector
 * will be converted to from local to global (and vice versa). The physically position of
 * the vector does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param matrix 3x3 basis matrix to convert.
 * @param orientation Local space orientation represented by 2x2 matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientation);

/**
 * Convert vector from given space to another space. If 'Space' is 'Global' it mean vector
 * will be converted to from local to global (and vice versa). The physically position of
 * the vector does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param matrix 3x3 basis matrix to convert.
 * @param space Local space represented by 3x3 matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& space);

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param matrix 3x3 basis matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param matrix 3x3 basis matrix in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 3x3 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param matrix 3x3 basis matrix in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param matrix 3x3 basis matrix in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 3x3 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB);

/* ####################################################################################### */
/* Global to local / local to global (outplace) */
/* ####################################################################################### */

/**
 * Convert basis from given space to another space. If 'Space' is 'Global' it mean basis
 * will be converted to from local to global (and vice versa). The physically position
 * of the basis does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param matrix 3x3 basis matrix to convert.
 * @param orientation Local space orientation represented by 2x2 matrix.
 * @return Converted matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientation);

/**
 * Convert vector from given space to another space. If 'Space' is 'Global' it mean vector
 * will be converted to from local to global (and vice versa). The
 * physically position  of the vector does not change, only recalculation to the local
 * system occurs.
 * @tparam Space Space to convert to.
 * @param matrix 3x3 basis matrix to convert.
 * @param space Local space represented by 3x3 matrix.
 * @return Converted matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& space);

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param matrix 3x3 basis matrix in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param matrix 3x3 basis matrix in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 3x3 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param matrix 3x3 basis matrix in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param matrix 3x3 basis matrix in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 3x3 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB);

CGM_2D_NAMESPACE_END


#include "matrix3x3.inl"
