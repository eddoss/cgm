#pragma once


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Operators/MatrixVectorMultiplication.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Cartesian/Common.hpp>
#include <Math3D/Cartesian/2D/Types/Basis.hpp>
#include <private/Math3D/Cartesian/2D/InternalUtils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local */
/* ####################################################################################### */

/**
 * Translates 2D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param orientation Local space orientation represented as 2x2 matrix.
 * @return Vector converted to local space.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation);

/**
 * Translates 2D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param orientation Local space orientation represented as 2x2 matrix.
 * @param position Local space position.
 * @return Vector converted to local space.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation, const Vector<2,T>& position);

/**
 * Translates 2D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param localSpace Local space represented as 2x2 matrix.
 * @return Vector converted to local space.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Translates 2D vector from global space to local space. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global space.
 * @param localSpace Local space to convert to.
 * @return Vector converted to local space.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Basis<Base,T>& localSpace);

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

/**
 * Translates 2D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param orientation Local space orientation represented as 2x2 matrix.
 * @return Converted to global space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation);

/**
 * Translates 2D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param orientation Local space orientation represented as 2x2 matrix.
 * @param position Local space position.
 * @return Converted to global space vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation, const Vector<2,T>& position);

/**
 * Translates 2D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param localSpace Local space represented as 2x2 matrix.
 * @return Converted to global space vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Translates 2D vector from local space to global space. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local space.
 * @param localSpace Local space to convert from.
 * @return Converted to global space vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Basis<Base,T>& localSpace);

/* ####################################################################################### */
/* Local to local: Matrix2 */
/* ####################################################################################### */

/**
 * Translates 2D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted vector from space A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB);

/**
 * Translates 2D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB);

/**
 * Translates 2D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 2x2 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB Basis of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Basis<Base,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix2 with Position */
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
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB);

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
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param spaceB 2x2 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<3,3,T>& spaceB);

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
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Basis<Base,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix3 */
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
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB);

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
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 2x2 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB Basis of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Basis<Base,T>& spaceB);

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
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<Base,T>& spaceA, const Matrix<2,2,T>& orientationB);

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
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<Base,T>& spaceA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 2x2 matrix of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<Base,T>& spaceA, const Matrix<3,3,T>& spaceB);

/**
 * Translates 3D vector from space A to space B (A and B are in one space).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A space.
 * @param spaceA Basis of A space.
 * @param spaceB Basis of B space.
 * @return Converted vector from space A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase BaseA, EBasisBase BaseB, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<BaseA,T>& spaceA, const Basis<BaseB,T>& spaceB);

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/2D/Functions/Converters.hpp>
