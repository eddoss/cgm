#ifndef MATH3D_XYZ_FUNCTIONS_CONVERTERS_HPP
#define MATH3D_XYZ_FUNCTIONS_CONVERTERS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Quaternion.hpp>
#include <Math3D/Core/Operators/MatrixVectorMultiplication.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Cartesian/3D/Functions/RawBasis.hpp>
#include <private/Math3D/Cartesian/3D/InternalUtils.hpp>
#include <private/Math3D/Cartesian/3D/Basis.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local */
/* ####################################################################################### */

/**
 * Translates 3D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param orientation Local space orientation represented as 3x3 matrix.
 * @return Vector converted to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation);

/**
 * Translates 3D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param orientation Local space orientation represented as 3x3 matrix.
 * @param position Local space position.
 * @return Vector converted to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

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
 * @param orientation Quaternion that orients local space.
 * @return Vector converted to local space.
 */
template<typename T>
constexpr Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientation);

/**
 * Translates 3D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param orientation Quaternion that orients local space.
 * @param position Position of local space.
 * @return Vector converted to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientation, const Vector<3,T>& position);

/**
 * Translates 3D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param localSpace Local space to convert to.
 * @return Vector converted to local space.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Basis<Base,T>& localSpace);

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

/**
 * Translates 3D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param orientation Local space orientation represented as 3x3 matrix.
 * @return Converted to global space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation);

/**
 * Translates 3D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param orientation Local space orientation represented as 3x3 matrix.
 * @param position Local space position.
 * @return Converted to global space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

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
 * @param orientation Quaternion that orients local space.
 * @return Converted to global space vector.
 */
template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& orientation);

/**
 * Translates 3D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param orientation Quaternion that orients local space.
 * @tparam position Position of local space.
 * @return Converted to global space vector.
 */
template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& orientation, const Vector<3,T>& position);

/**
 * Translates 3D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param localSpace Local space to convert from.
 * @return Converted to global space vector.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Basis<Base,T>& localSpace);

/* ####################################################################################### */
/* Local to local: Matrix3 */
/* ####################################################################################### */

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB Basis of B space.
 * @return Converted vector from space A to B.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Basis<Base,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix3 with Position */
/* ####################################################################################### */

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param spaceB Basis of B space.
 * @return Converted vector from space A to B.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Basis<Base,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix4 */
/* ####################################################################################### */

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB Basis of B space.
 * @return Converted vector from space A to B.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Basis<Base,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Quaternion */
/* ####################################################################################### */

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
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
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB Basis of B space.
 * @return Converted vector from space A to B.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Basis<Base,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Quaternion with Position */
/* ####################################################################################### */

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param spaceB Basis of B space.
 * @return Converted vector from space A to B.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Basis<Base,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Basis */
/* ####################################################################################### */

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Matrix<3,3,T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Matrix<4,4,T>& spaceB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Quaternion<T>& orientationB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB Basis of B space.
 * @return Converted vector from space A to B.
 */
template<EBasisBase BaseA, EBasisBase BaseB, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<BaseA,T>& spaceA, const Basis<BaseB,T>& spaceB);

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/3D/Functions/Converters.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_CONVERTERS_HPP
