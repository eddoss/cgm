#ifndef MATH3D_XFORM_3D_FUNCTIONS_TRANSLATE_HPP
#define MATH3D_XFORM_3D_FUNCTIONS_TRANSLATE_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/XForm/3D/Pivot.hpp>
#include <Math3D/XForm/3D/Transforms.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

/**
 * Translate 3D vector.
 * @param vector Vector to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Vector<3,T>& vector, const Vector<3,T>& value);

/**
 * Translates 3D vector using "transforms.translations".
 * @param vector Vector to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Vector<3,T>& vector, const Transforms<3,T>& transforms);

/**
 * Translates 3D transform matrix by vector.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
translate(Matrix<4,4,T>& matrix, const Vector<3,T>& value);

/**
 * Translates 3D transform matrix using "transforms.translations".
 * @param vector Vector to translate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
translate(Matrix<4,4,T>& matrix, const Transforms<3,T>& transforms);

/**
 * Translate 3D pivot.
 * @param pivot Pivot to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Pivot<3,T>& pivot, const Vector<3,T>& value);

/**
 * Translates 3D pivot using "transforms.translations".
 * @param pivot Pivot to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Pivot<3,T>& pivot, const Transforms<3,T>& transforms);

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_3D_FUNCTIONS_TRANSLATE_HPP