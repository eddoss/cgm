#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Basis.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Typedefs.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/Modules/Transformations/3D/Types/Axis.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/3D/Types/Transforms.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

/**
 * Reflects vector from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(Vector<3,T>& vector, const Vector<3,T>& planeNormal);

/**
 * Reflects vector from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<typename T>
constexpr void
reflect(Vector<3,T>& vector, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter);

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

/**
 * Reflects 3x3 matrix from a plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal);

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

/**
 * Reflects 4x4 matrix from a plane.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal);

/**
 * Reflects 4x4 matrix from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<typename T>
constexpr void
reflect(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter);

/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

/**
 * Reflects pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(Pivot<T>& pivot, Vector<3,T>& planeNormal);

/**
 * Reflects pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<typename T>
constexpr void
reflect(Pivot<T>& pivot, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter);

/* ####################################################################################### */
/* Axes tuple */
/* ####################################################################################### */

/**
 * Reflects axes tuple from a plane.
 * @tparam Space In which space to transform.
 * @param axes Axes tuple to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(AxesTuple<T>& axes, const Vector<3,T>& planeNormal);

/* ####################################################################################### */
/* Space tuple */
/* ####################################################################################### */

/**
 * Reflects space tuple from a plane.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(SpaceTuple<T>& space, const Vector<3,T>& planeNormal);

/**
 * Reflects space tuple from a plane.
 * @param space Space tuple to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<typename T>
constexpr void
reflect(SpaceTuple<T>& space, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter);

/* ####################################################################################### */
/* Basis struct */
/* ####################################################################################### */

/**
 * Reflects basis struct from a plane.
 * @param basis Basis struct tuple to reflect.
 * @param planeNormal Plane normal.
 */
template<EBasisBase Base, typename T>
constexpr void
reflect(Basis<Base,T>& basis, const Vector<3,T>& planeNormal);

/**
 * Reflects basis struct from a plane.
 * @param basis Basis struct to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<EBasisBase Base, typename T>
constexpr void
reflect(Basis<Base,T>& basis, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END