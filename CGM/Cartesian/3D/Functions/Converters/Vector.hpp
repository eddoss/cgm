#pragma once


#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Cartesian/3D/Types/Quaternion.hpp>
#include <CGM/Core/Operators/MatrixVectorMultiplication.hpp>
#include <CGM/Core/Functions/Matrix.hpp>
#include <CGM/Cartesian/3D/Functions/Quaternion.hpp>
#include <CGM/Cartesian/Common.hpp>
#include <CGM/Cartesian/3D/ModuleGlobals.hpp>
#include <CGM/Cartesian/3D/Functions/Orientation.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

/**
 * Convert vector from given space to another space. If 'Space' is 'World' it mean vector 
 * will be converted to from local to world (and vice versa). The physically position of
 * the vector does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param vector Vector to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientation);

/**
 * Convert vector from given space to another space. If 'Space' is 'World' it mean vector 
 * will be converted to from local to world (and vice versa). The physically position of
 * the vector does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param vector Vector to convert.
 * @param space Local space represented by 4x4 matrix.
 */
template<ESpace Space, EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& space);

/**
 * Convert vector from given space to another space. If 'Space' is 'World' it mean vector 
 * will be converted to from local to world (and vice versa). The physically position of
 * the vector does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param vector Vector to convert.
 * @param orientation orientation Local space orientation represented by quaternion.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientation);

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
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
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB);

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
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
convert(Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB);

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
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
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB);

/* ####################################################################################### */
/* Global to local / local to global (outplace) */
/* ####################################################################################### */

/**
 * Convert vector from given space to another space. If 'Space' is 'World' it mean vector
 * will be converted to from local to world (and vice versa). The physically position
 * of the vector does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param vector Vector to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 * @return Converted vector.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation);

/**
 * Convert vector from given space to another space. If 'Space' is 'World' it mean vector
 * will be converted to from local to world (and vice versa). The
 * physically position  of the vector does not change, only recalculation to the local
 * system occurs.
 * @tparam Space Space to convert to.
 * @param vector Vector to convert.
 * @param space Local space represented by 4x4 matrix.
 * @return Converted vector.
 */
template<ESpace Space, EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<4,4,T>& space);

/**
 * Convert vector from given space to another space. If 'Space' is 'World' it mean vector
 * will be converted to from local to world (and vice versa). The
 * physically position  of the vector does not change, only recalculation to the local
 * system occurs.
 * @tparam Space Space to convert to.
 * @param vector Vector to convert.
 * @param orientation orientation Local space orientation represented by quaternion.
 * @return Converted vector.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientation);

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB);

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB);

/* ####################################################################################### */
/* Local to local: Quaternion (outplace) */
/* ####################################################################################### */

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert vector from space A to space B (A and B are in one space). The physically 
 * position of the vector does not change, only recalculation to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB);

CGM_NAMESPACE_END


#include "Vector.inl"