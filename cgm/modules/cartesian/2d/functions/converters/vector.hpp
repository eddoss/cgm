#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/operators/matrix_vector_multiplication.hpp>
#include <cgm/modules/core/functions/matrix.hpp>
#include <cgm/modules/cartesian/2d/module_globals.hpp>
#include <cgm/modules/cartesian/common.hpp>
#include <cgm/modules/cartesian/2d/functions/utils.hpp>
#include <cgm/modules/cartesian/2d/functions/orientation.hpp>


CGM_2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local (inplace) */
/* ####################################################################################### */

/**
 * Convert vector from given space to another space. If 'Space' is 'Global' it mean vector
 * will be converted to from local to global (and vice versa). The physically position of
 * the vector does not change, only recalculation to the local system occurs.
 * @param vector Vector in global space.
 * @param orientation Local space orientation represented as 2x2 matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<2,2,T>& orientation);

/**
 * Convert vector from given space to another space. If 'Space' is 'Global' it mean vector
 * will be converted to from local to global (and vice versa). The physically position of
 * the vector does not change, only recalculation to the local system occurs.
 * @param vector Vector in global space.
 * @param space Local space represented as 2x2 matrix.
 */
template<ESpace Space, EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<3,3,T>& space);

/* ####################################################################################### */
/* Local to local: Matrix2 (inplace) */
/* ####################################################################################### */

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 2x2 matrix of B space.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 2x2 matrix of B space.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB);

/* ####################################################################################### */
/* Global to local (outplace) */
/* ####################################################################################### */

/**
 * Convert vector from given space to another space. If 'Space' is 'Global' it mean vector
 * will be converted to from local to global (and vice versa). The physically position of
 * the vector does not change, only recalculation to the local system occurs.
 * @param vector Vector in global space.
 * @param orientation Local space orientation represented as 2x2 matrix.
 * @return Converted vector.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation);

/**
 * Convert vector from given space to another space. If 'Space' is 'Global' it mean vector
 * will be converted to from local to global (and vice versa). The physically position of
 * the vector does not change, only recalculation to the local system occurs.
 * @param vector Vector in global space.
 * @param space Local space represented as 2x2 matrix.
 * @return Converted vector.
 */
template<ESpace Space, EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<3,3,T>& space);

/* ####################################################################################### */
/* Local to local: Matrix2 (outplace) */
/* ####################################################################################### */

/**
 * Convert vector from space A to space B (A and B are in one space). The physically
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 2x2 matrix of B space.
 * @return Converted vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Convert vector from space A to space B (A and B are in one space). The physically
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 2x2 matrix of B space.
 * @return Converted vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB);

CGM_2D_NAMESPACE_END


#include "vector.inl"
