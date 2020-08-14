

#include <CGM/Modules/Transformations/3D/Functions/Translate.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<3,T>& vector, const Vector<3,T>& value)
{
    vector += value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<3,T>& vector, const Transforms<T>& transforms)
{
    vector += transforms.translations;
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr void
translate(Matrix<4,4,T>& matrix, const Vector<3,T>& value)
{
    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix(0,3) += value.x;
        matrix(1,3) += value.y;
        matrix(2,3) += value.z;
    #else
        matrix(3,0) += value.x;
        matrix(3,1) += value.y;
        matrix(3,2) += value.z;
    #endif
    }
    else
    {
        const auto xOffset = x(matrix) * value.x;
        const auto yOffset = y(matrix) * value.y;
        const auto zOffset = z(matrix) * value.z;

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix(0,3) += xOffset;
        matrix(1,3) += yOffset;
        matrix(2,3) += zOffset;
    #else
        matrix(3,0) += xOffset.x + yOffset.x + zOffset.x;
        matrix(3,1) += xOffset.y + yOffset.y + zOffset.y;
        matrix(3,2) += xOffset.z + yOffset.z + zOffset.z;
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
translate(Matrix<4,4,T>& matrix, const Transforms<T>& transforms)
{
    translate<Space>(matrix, transforms.translations);
}

/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, const Vector<3,T>& value)
{
    pivot.position += value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, const Transforms<T>& transforms)
{
    pivot += transforms.translations;
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END
