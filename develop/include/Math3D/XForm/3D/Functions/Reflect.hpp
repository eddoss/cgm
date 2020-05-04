#ifndef MATH3D_XFORM_3D_FUNCTIONS_REFLECT_HPP
#define MATH3D_XFORM_3D_FUNCTIONS_REFLECT_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Cartesian.hpp>
#include <Math3D/XForm/3D/Pivot.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

using MATH3D_XYZ_NAMESPACE::EPlane;

/**
 * Reflects 3D vector through Cartesian plane.
 * @tparam Plane Reflection plane.
 * @param vector Vector to reflect.
 */
template<EPlane Plane, typename T>
constexpr void
reflect(Vector<3,T>& vector);

/**
 * Reflects 3D vector through Cartesian plane.
 * @tparam Plane Reflection plane.
 * @param vector Vector to reflect.
 * @param offset Offset of reflection plane along plane normal.
 */
template<EPlane Plane, typename T>
constexpr void
reflect(Vector<3,T>& vector, T offset);

/**
 * Reflects 3D vector through plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(Vector<3,T>& vector, Vector<3,T>& planeNormal);

/**
 * Reflects 3D vector through plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param offset Offset of reflection plane along plane normal.
 */
template<typename T>
constexpr void
reflect(Vector<3,T>& vector, Vector<3,T>& planeNormal, T offset);

/**
 * Reflects 3D vector through plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<typename T>
constexpr void
reflect(Vector<3,T>& vector, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter);

/**
 * Reflects 3D vector through plane.
 * @param vector Vector to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 * @param offset Offset of reflection plane origin along plane normal.
 */
template<typename T>
constexpr void
reflect(Vector<3,T>& vector, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter, T offset);

/**
 * Reflects 3D orientation matrix through Cartesian plane.
 * @tparam Space In which space to transform.
 * @tparam Plane Reflection plane.
 * @param matrix Matrix to reflect.
 */
template<EPlane Plane, ESpace Space = ESpace::Local, typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix);

/**
 * Reflects 3D orientation matrix through Cartesian plane.
 * @tparam Plane Reflection plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param offset Offset of reflection plane along plane normal.
 */
template<EPlane Plane, ESpace Space = ESpace::Local, typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, T offset);

/**
 * Reflects 3D orientation matrix through plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, Vector<3,T>& planeNormal);

/**
 * Reflects 3D orientation matrix through plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param offset Offset of reflection plane along plane normal.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, Vector<3,T>& planeNormal, T offset);

/**
 * Reflects 3D orientation matrix through plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter);

/**
 * Reflects 3D orientation matrix through plane.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 * @param offset Offset of reflection plane origin along plane normal.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter, T offset);

/**
 * Reflects 3D pivot through Cartesian plane.
 * @tparam Plane Reflection plane.
 * @param pivot Pivot to reflect.
 */
template<EPlane Plane, typename T>
constexpr void
reflect(Pivot<3,T>& pivot);

/**
 * Reflects 3D pivot through Cartesian plane.
 * @tparam Plane Reflection plane.
 * @param pivot Pivot to reflect.
 * @param offset Offset of reflection plane along plane normal.
 */
template<EPlane Plane, typename T>
constexpr void
reflect(Pivot<3,T>& pivot, T offset);

/**
 * Reflects 3D pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 */
template<typename T>
constexpr void
reflect(Pivot<3,T>& pivot, Vector<3,T>& planeNormal);

/**
 * Reflects 3D pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 * @param offset Offset of reflection plane along plane normal.
 */
template<typename T>
constexpr void
reflect(Pivot<3,T>& pivot, Vector<3,T>& planeNormal, T offset);

/**
 * Reflects 3D pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 */
template<typename T>
constexpr void
reflect(Pivot<3,T>& pivot, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter);

/**
 * Reflects 3D pivot through plane.
 * @param pivot Pivot to reflect.
 * @param planeNormal Plane normal.
 * @param planeCenter Plane origin.
 * @param offset Offset of reflection plane origin along plane normal.
 */
template<typename T>
constexpr void
reflect(Pivot<3,T>& pivot, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter, T offset);

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_3D_FUNCTIONS_REFLECT_HPP