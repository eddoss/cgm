#ifndef MATH3D_XYZ_FUNCTIONS_SPACE_CONVERTERS_HPP
#define MATH3D_XYZ_FUNCTIONS_SPACE_CONVERTERS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Matrix/Functions.hpp>
#include <Math3D/Core/Quaternion/Quaternion.hpp>
#include <Math3D/Cartesian/Functions/BasisCreators.hpp>
#include <Math3D/Cartesian/Functions/Utils.hpp>

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
#include <Math3D/Core/Matrix/Operators.hpp>
#else
#include <Math3D/Core/Vector/Operators.hpp>
#endif


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local */
/* ####################################################################################### */

/**
 * Translates 2D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param localSpace Local space represented as 2x2 matrix.
 * @return Position recalculated to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& localSpace);

/**
 * Translates 2D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @@param localSpace Local space represented as 3x3 matrix.
 * @return Vector converted to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Translates 3D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param localSpace Local space represented as 3x3 matrix.
 * @return Vector converted to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Translates 3D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param localSpace Local space represented as 4x4 matrix.
 * @return Vector converted to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace);

/**
 * Translates 3D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param localSpaceOrientation Quaternion that orients local space.
 * @return Vector converted to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation);

/**
 * Translates 3D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param localSpaceOrientation Quaternion that orients local space.
 * @param localSpacePosition Position of local space.
 * @return Vector converted to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation, const Vector<3,T>& localSpacePosition);

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

 /**
 * Translates 2D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param localSpace Local space represented as 2x2 matrix.
 * @return converted to world space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<2,2,T>& localSpace);

/**
 * Translates 2D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param localSpace Local space represented as 3x3 matrix.
 * @return Converted to global space vector.
 */
template<typename T>
constexpr Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Translates 3D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param localSpace Local space represented as 3x3 matrix.
 * @return Converted to global space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Translates 3D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param localSpace Local space represented as 4x4 matrix.
 * @return Converted to global space vector.
 */
template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace);

/**
 * Translates 3D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param localSpaceOrientation Quaternion that orients local space.
 * @return Converted to global space vector.
 */
template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation);

/**
 * Translates 3D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param localSpaceOrientation Quaternion that orients local space.
 * @tparam localSpacePosition Position of local space.
 * @return Converted to global space vector.
 */
template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation, const Vector<3,T>& localSpacePosition);

/* ####################################################################################### */
/* Local to local */
/* ####################################################################################### */

/**
 * Translates 2D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param A Space to convert from.
 * @param B Space to convert to.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& A, const Matrix<2,2,T>& B);

/**
 * Translates 2D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param A Space to convert from.
 * @param B Space to convert to.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& A, const Matrix<2,2,T>& B);

/**
 * Translates 2D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param A Space to convert from.
 * @param B Space to convert to.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& A, const Matrix<3,3,T>& B);

/**
 * Translates 2D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param A Space to convert from.
 * @param B Space to convert to.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& A, const Matrix<3,3,T>& B);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param A Space to convert from.
 * @param B Space to convert to.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& A, const Matrix<3,3,T>& B);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param A Space to convert from.
 * @param B Space to convert to.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& A, const Matrix<3,3,T>& B);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param A Space to convert from.
 * @param B Space to convert to.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& A, const Matrix<4,4,T>& B);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param A Space to convert from.
 * @param B Space to convert to.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& A, const Matrix<4,4,T>& B);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Quaternion that orients "A" space.
 * @param orientationB Quaternion that orients "B" space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Quaternion that orients "A" space.
 * @param positionA "A" space position.
 * @param orientationB Quaternion that orients "B" space.
 * @param positionB "B" space position.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/Functions/CoordinateConverters.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_SPACE_CONVERTERS_HPP
