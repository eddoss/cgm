#ifndef MATH3D_XY_FUNCTIONS_SPACE_CONVERTERS_HPP
#define MATH3D_XY_FUNCTIONS_SPACE_CONVERTERS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Operators/MatrixVectorMultiplication.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Cartesian/2D/Basis.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local */
/* ####################################################################################### */

/**
 * Translates 2D vector from global basis to local basis. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global basis.
 * @param orientation Local basis orientation represented as 2x2 matrix.
 * @return Vector converted to local basis.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation);

/**
 * Translates 2D vector from global basis to local basis. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global basis.
 * @param orientation Local basis orientation represented as 2x2 matrix.
 * @param position Local basis position.
 * @return Vector converted to local basis.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation, const Vector<2,T>& position);

/**
 * Translates 2D vector from global basis to local basis. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global basis.
 * @param localSpace Local basis represented as 3x3 matrix.
 * @return Vector converted to local basis.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Translates 2D vector from global basis to local basis. The "physically"
 * position of the vector does not change, only recalculation to the local
 * system occurs.
 * @param vector Vector in global basis.
 * @param localSpace Local basis to convert to.
 * @return Vector converted to local basis.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Basis<Base,T>& localSpace);

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

/**
 * Translates 2D vector from local basis to global basis. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local basis.
 * @param orientation Local basis orientation represented as 2x2 matrix.
 * @return Converted to global basis vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation);

/**
 * Translates 2D vector from local basis to global basis. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local basis.
 * @param orientation Local basis orientation represented as 2x2 matrix.
 * @param position Local basis position.
 * @return Converted to global basis vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation, const Vector<2,T>& position);

/**
 * Translates 2D vector from local basis to global basis. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local basis.
 * @param localSpace Local basis represented as 3x3 matrix.
 * @return Converted to global basis vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Translates 2D vector from local basis to global basis. The "physically"
 * position of the vector does not change, only recalculation to the global
 * system occurs.
 * @param vector Vector in local basis.
 * @param localSpace Local basis to convert from.
 * @return Converted to global basis vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Basis<Base,T>& localSpace);

/* ####################################################################################### */
/* Local to local: Matrix3 */
/* ####################################################################################### */

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param orientationA Orientation of A basis.
 * @param orientationB Orientation of B basis.
 * @return Converted vector from basis A to B.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param orientationA Orientation of A basis.
 * @param orientationB Orientation of B basis.
 * @param positionB Position of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param orientationA Orientation of A basis.
 * @param spaceB 3x3 matrix of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param orientationA Orientation of A basis.
 * @param spaceB Basis of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Basis<Base,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix3 with Position */
/* ####################################################################################### */

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param orientationA Orientation of A basis.
 * @param positionB Position of A basis.
 * @param orientationB Orientation of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param orientationA Orientation of A basis.
 * @param positionB Position of A basis.
 * @param orientationB Orientation of B basis.
 * @param positionB Position of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param orientationA Orientation of A basis.
 * @param positionB Position of A basis.
 * @param spaceB 3x3 matrix of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<3,3,T>& spaceB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param orientationA Orientation of A basis.
 * @param positionB Position of A basis.
 * @param spaceB Basis of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Basis<Base,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Matrix4 */
/* ####################################################################################### */

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param spaceA Basis of A basis.
 * @param orientationB Orientation of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param spaceA Basis of A basis.
 * @param orientationB Orientation of B basis.
 * @param positionB Position of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param spaceA Basis of A basis.
 * @param spaceB 3x3 matrix of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param spaceA Basis of A basis.
 * @param spaceB Basis of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Basis<Base,T>& spaceB);

/* ####################################################################################### */
/* Local to local: Basis */
/* ####################################################################################### */

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param spaceA Basis of A basis.
 * @param orientationB Orientation of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<Base,T>& spaceA, const Matrix<2,2,T>& orientationB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param spaceA Basis of A basis.
 * @param orientationB Orientation of B basis.
 * @param positionB Position of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<Base,T>& spaceA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param spaceA Basis of A basis.
 * @param spaceB 3x3 matrix of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<Base,T>& spaceA, const Matrix<3,3,T>& spaceB);

/**
 * Translates 2D vector from basis A to basis B (A and B are in one basis).
 * The "physically" position of the vector does not change, only recalculation
 * to the B system occurs.
 * @param vector Vector in A basis.
 * @param spaceA Basis of A basis.
 * @param spaceB Basis of B basis.
 * @return Converted vector from basis A to B.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, EBasisBase BaseA, EBasisBase BaseB, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<BaseA,T>& spaceA, const Basis<BaseB,T>& spaceB);

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/2D/Functions/Converters.hpp>


#endif // MATH3D_XY_FUNCTIONS_SPACE_CONVERTERS_HPP
