

#include <CGM/Modules/Transformations/3D/Functions/Scale.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

 template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& values)
{
    vector.x *= values.x;
    vector.y *= values.y;
    vector.z *= values.z;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
scale(Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    auto p = vector - pivotPoint.position;

    auto sdx = dot(p, pivotPoint.x); // short dist to pivot XZ plane
    auto sdy = dot(p, pivotPoint.y); // short dist to pivot YZ plane
    auto sdz = dot(p, pivotPoint.z); // short dist to pivot XY plane

    vector += pivotPoint.x * (values.x - 1) * sdx;
    vector += pivotPoint.y * (values.y - 1) * sdy;
    vector += pivotPoint.z * (values.z - 1) * sdz;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, const Transforms<T>& transforms)
{
    scale(vector, transforms.scales * transforms.uniformScale, transforms.pivot);
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, const Vector<3,T>& values)
{
    if constexpr (Space == ESpace::World)
    {
        auto scaler = Matrix<3,3,T>
        {
            values.x, number<T>(0), number<T>(0),
            number<T>(0), values.y, number<T>(0),
            number<T>(0), number<T>(0), values.z
        };

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix = matrix * scaler;
    #else
        matrix = scaler * matrix;
    #endif
    }
    else
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix(0,0) *= values.x;
        matrix(0,1) *= values.x;
        matrix(0,2) *= values.x;

        matrix(1,0) *= values.y;
        matrix(1,1) *= values.y;
        matrix(1,2) *= values.y;

        matrix(2,0) *= values.z;
        matrix(2,1) *= values.z;
        matrix(2,2) *= values.z;
    #else
        matrix(0,0) *= values.x;
        matrix(1,0) *= values.x;
        matrix(2,0) *= values.x;

        matrix(0,1) *= values.y;
        matrix(1,1) *= values.y;
        matrix(2,1) *= values.y;

        matrix(0,2) *= values.z;
        matrix(1,2) *= values.z;
        matrix(2,2) *= values.z;
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    if constexpr (Space == ESpace::World)
    {
        auto worldSpacePivot = Pivot<T>
        {
            localToGlobal(pivotPoint.x, matrix),
            localToGlobal(pivotPoint.y, matrix),
            localToGlobal(pivotPoint.z, matrix),
            localToGlobal(pivotPoint.position, matrix)
        };

        scale<ESpace::Local>(matrix, values, worldSpacePivot);
    }
    else
    {
        auto axes = orientationAxes(matrix);

        scale(axes.x, values, pivotPoint);
        scale(axes.y, values, pivotPoint);
        scale(axes.z, values, pivotPoint);

        setX(matrix, axes.x);
        setY(matrix, axes.y);
        setZ(matrix, axes.z);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    scale<Space>(matrix, transforms.scales * transforms.uniformScale, transforms.pivot);
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& values)
{
    if constexpr (Space == ESpace::World)
    {
        auto scaler = Matrix<4,4,T>
        {
            values.x, number<T>(0), number<T>(0), number<T>(0),
            number<T>(0), values.y, number<T>(0), number<T>(0),
            number<T>(0), number<T>(0), values.z, number<T>(0),
            number<T>(0), number<T>(0), number<T>(0), number<T>(1)
        };

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix = matrix * scaler;
    #else
        matrix = scaler * matrix;
    #endif
    }
    else
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix(0,0) *= values.x;
        matrix(0,1) *= values.x;
        matrix(0,2) *= values.x;

        matrix(1,0) *= values.y;
        matrix(1,1) *= values.y;
        matrix(1,2) *= values.y;

        matrix(2,0) *= values.z;
        matrix(2,1) *= values.z;
        matrix(2,2) *= values.z;
    #else
        matrix(0,0) *= values.x;
        matrix(1,0) *= values.x;
        matrix(2,0) *= values.x;

        matrix(0,1) *= values.y;
        matrix(1,1) *= values.y;
        matrix(2,1) *= values.y;

        matrix(0,2) *= values.z;
        matrix(1,2) *= values.z;
        matrix(2,2) *= values.z;
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    if constexpr (Space == ESpace::World)
    {
        auto worldSpacePivot = Pivot<T>
        {
            localToGlobal<EVectorRepresentation::Direction>(pivotPoint.x, matrix),
            localToGlobal<EVectorRepresentation::Direction>(pivotPoint.y, matrix),
            localToGlobal<EVectorRepresentation::Direction>(pivotPoint.z, matrix),
            localToGlobal<EVectorRepresentation::Point>(pivotPoint.position, matrix)
        };

        scale<ESpace::Local>(matrix, values, worldSpacePivot);
    }
    else
    {
        auto axes = orientationAxes(matrix);

        scale(axes.x, values, pivotPoint);
        scale(axes.y, values, pivotPoint);
        scale(axes.z, values, pivotPoint);

        setX(matrix, axes.x);
        setY(matrix, axes.y);
        setZ(matrix, axes.z);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Transforms<T>& transforms)
{
    scale<Space>(matrix, transforms.scales * transforms.uniformScale, transforms.pivot);
}

/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

 template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, const Vector<3,T>& values)
{
    scale(pivot.position, values);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    scale(pivot.position, values, pivotPoint);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, const Transforms<T>& transforms)
{
    scale(pivot.position, transforms);
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END
