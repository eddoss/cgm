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

/**
 * Refracts vector from a plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior);

/**
 * Refracts 3x3 matrix from a plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal, T ior);

/**
 * Refracts 4x4 matrix from a plane.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, T ior);

/**
 * Refracts pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(Pivot<T>& pivot, Vector<3,T>& planeNormal, T ior);

/**
 * Refracts axes tuple from a plane.
 * @tparam Space In which space to transform.
 * @param axes Axes tuple to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(AxesTuple<T>& axes, const Vector<3,T>& planeNormal, T ior);

/**
 * Refracts space tuple from a plane.
 * @param space Space tuple to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<typename T>
constexpr void
refract(SpaceTuple<T>& space, const Vector<3,T>& planeNormal, T ior);

/**
 * Refracts basis struct from a plane.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param ior Index of refraction.
 */
template<EBasisBase Base, typename T>
constexpr void
refract(Basis<Base,T>& basis, const Vector<3,T>& planeNormal, T ior);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Functions/Refract.hpp>