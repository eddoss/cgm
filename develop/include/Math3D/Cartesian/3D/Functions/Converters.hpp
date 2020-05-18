#ifndef MATH3D_XYZ_FUNCTIONS_SPACE_CONVERTERS_HPP
#define MATH3D_XYZ_FUNCTIONS_SPACE_CONVERTERS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Quaternion.hpp>
#include <Math3D/Core/Operators/MatrixVectorMultiplication.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <private/Math3D/Cartesian/3D/InternalUtils.hpp>


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
 * @return Vector converted to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& localSpace);

/**
 * Translates 2D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param localSpace Local space represented as 3x3 matrix.
 * @return Vector converted to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace);

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

/**
 * Translates 2D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param localSpace Local space represented as 2x2 matrix.
 * @return Converted to global space vector.
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

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/3D/Functions/Converters.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_SPACE_CONVERTERS_HPP
