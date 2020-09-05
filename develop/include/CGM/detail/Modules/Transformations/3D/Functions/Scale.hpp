

#include <CGM/Modules/Transformations/3D/Functions/Scale.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, T value)
{
    if constexpr (Axis == EAxes::X)
    {
        vector.x += vector.x * (value - number<T>(1));
    }
    if constexpr (Axis == EAxes::X)
    {
        vector.y += vector.y * (value - number<T>(1));
    }
    else
    {
        vector.z += vector.z * (value - number<T>(1));
    }
}

/* --------------------------------------------------------------------------------------- */

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
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, T value, const Vector<3,T>& direction)
{
    vector += direction * (value - number<T>(1)) * shortestDistance(vector, direction);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, T value, const Vector<3,T>& direction, const Vector<3,T>& origin)
{
    vector += direction * (value - number<T>(1)) * shortestDistance(vector - origin, direction);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, T value, const Axis<T>& axis)
{
    scale(vector, value, axis.direction, axis.origin);
}

/* --------------------------------------------------------------------------------------- */
#include <CGM/Modules/Core/Functions/IO.hpp>
template<EVectorRepresentation Representation, typename T>
constexpr void
scale(Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        auto vec = vector - pivotPoint.position;

        vector += pivotPoint.axes.x * (values.x - number<T>(1)) * shortestDistance(vec, pivotPoint.axes.x);
        vector += pivotPoint.axes.y * (values.y - number<T>(1)) * shortestDistance(vec, pivotPoint.axes.y);
        vector += pivotPoint.axes.z * (values.z - number<T>(1)) * shortestDistance(vec, pivotPoint.axes.z);
    }
    else
    {
        vector += pivotPoint.axes.x * (values.x - number<T>(1)) * shortestDistance(vector, pivotPoint.axes.x);
        vector += pivotPoint.axes.y * (values.y - number<T>(1)) * shortestDistance(vector, pivotPoint.axes.y);
        vector += pivotPoint.axes.z * (values.z - number<T>(1)) * shortestDistance(vector, pivotPoint.axes.z);
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, const Transforms<T>& transforms)
{
    scale(vector, transforms.scales * transforms.uniformScale, transforms.pivot);
}

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<3,3,T>& matrix, T value)
{
    if constexpr (Space == ESpace::World)
    {
        auto axes = orientationAxes(matrix);

        scale<Axis>(axes.x, value);
        scale<Axis>(axes.y, value);
        scale<Axis>(axes.z, value);

        set(matrix, axes);
    }
    else
    {
        if constexpr (Axis == EAxes::X)
        {
            scale<ESpace::World>(matrix, value, x(matrix));
        }
        else if constexpr (Axis == EAxes::Y)
        {
            scale<ESpace::World>(matrix, value, y(matrix));
        }
        else
        {
            scale<ESpace::World>(matrix, value, z(matrix));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

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
scale(Matrix<3,3,T>& matrix, T value, const Vector<3,T>& direction)
{
    if constexpr (Space == ESpace::World)
    {
        auto axes = orientationAxes(matrix);

        scale(axes.x, value, direction);
        scale(axes.y, value, direction);
        scale(axes.z, value, direction);

        set(matrix, axes);
    }
    else
    {
        scale<ESpace::World>(matrix, value, converted<ESpace::World>(direction, matrix));
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, T value, const Vector<3,T>& direction, const Vector<3,T>& origin)
{


    if constexpr (Space == ESpace::World)
    {
        auto axes = orientationAxes(matrix);

        scale(axes.x, value, direction, origin);
        scale(axes.y, value, direction, origin);
        scale(axes.z, value, direction, origin);

        set(matrix, axes);
    }
    else
    {
        scale<ESpace::World>(matrix, value, converted<ESpace::World>(direction, matrix), converted<ESpace::World>(origin, matrix));
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, T value, const Axis<T>& axis)
{
    if constexpr (Space == ESpace::World)
    {
        auto axes = orientationAxes(matrix);

        scale(axes.x, value, axis);
        scale(axes.y, value, axis);
        scale(axes.z, value, axis);

        set(matrix, axes);
    }
    else
    {
        scale<ESpace::World>(matrix, value, converted<ESpace::World>(axis.direction, matrix), converted<ESpace::World>(axis.origin, matrix));
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    if constexpr (Space == ESpace::World)
    {
        auto axes = orientationAxes(matrix);

        scale<EVectorRepresentation::Direction>(axes.x, values, pivotPoint);
        scale<EVectorRepresentation::Direction>(axes.y, values, pivotPoint);
        scale<EVectorRepresentation::Direction>(axes.z, values, pivotPoint);

        set(matrix, axes);
    }
    else
    {
        auto wsPivot = Pivot<T>
        {
            converted<ESpace::World,EVectorRepresentation::Direction>(pivotPoint.axes.x, matrix),
            converted<ESpace::World,EVectorRepresentation::Direction>(pivotPoint.axes.y, matrix),
            converted<ESpace::World,EVectorRepresentation::Direction>(pivotPoint.axes.z, matrix),
            converted<ESpace::World,EVectorRepresentation::Point>(pivotPoint.position, matrix)
        };

        scale<ESpace::World>(matrix, values, wsPivot);
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
/* Matrix4 (inplace) */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<4,4,T>& matrix, T value)
{
    if constexpr (Space == ESpace::World)
    {
        auto axes = orientationAxes(matrix);
        auto pos = position(matrix);

        scale<Axis>(axes.x, value);
        scale<Axis>(axes.y, value);
        scale<Axis>(axes.z, value);
        scale<Axis>(pos, value);

        set(matrix, axes, pos);
    }
    else
    {
        if constexpr (Axis == EAxes::X)
        {
            scale<ESpace::World>(matrix, value, x(matrix));
        }
        else if constexpr (Axis == EAxes::Y)
        {
            scale<ESpace::World>(matrix, value, y(matrix));
        }
        else
        {
            scale<ESpace::World>(matrix, value, z(matrix));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& values)
{
    if constexpr (Space == ESpace::World)
    {
        auto scales = Matrix<4,4,T>
        {
            values.x, number<T>(0), number<T>(0), number<T>(0),
            number<T>(0), values.y, number<T>(0), number<T>(0),
            number<T>(0), number<T>(0), values.z, number<T>(0),
            number<T>(0), number<T>(0), number<T>(0), number<T>(1)
        };

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix = matrix * scales;
        matrix(0,3) *= values.x;
        matrix(1,3) *= values.y;
        matrix(2,3) *= values.z;
    #else
        matrix = scales * matrix;
        matrix(3,0) *= values.x;
        matrix(3,1) *= values.y;
        matrix(3,2) *= values.z;
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
scale(Matrix<4,4,T>& matrix, T value, const Vector<3,T>& direction)
{
    if constexpr (Space == ESpace::World)
    {
        auto axes = orientationAxes(matrix);
        auto pos = position(matrix);

        scale(axes.x, value, direction);
        scale(axes.y, value, direction);
        scale(axes.z, value, direction);
        scale(pos, value, direction);

        set(matrix, axes, pos);
    }
    else
    {
        scale(matrix, value, converted<ESpace::World,EVectorRepresentation::Direction>(direction, matrix));
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<4,4,T>& matrix, T value, const Vector<3,T>& direction, const Vector<3,T>& origin)
{
    if constexpr (Space == ESpace::World)
    {
        auto axes = orientationAxes(matrix);
        auto pos = position(matrix);

        scale(axes.x, value, direction, origin);
        scale(axes.y, value, direction, origin);
        scale(axes.z, value, direction, origin);
        scale(pos, value, direction, origin);

        set(matrix, axes, pos);
    }
    else
    {
        scale
        (
            matrix, value,
            converted<ESpace::World,EVectorRepresentation::Direction>(direction, matrix),
            converted<ESpace::World,EVectorRepresentation::Point>(origin, matrix)
        );
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<4,4,T>& matrix, T value, const Axis<T>& axis)
{
    if constexpr (Space == ESpace::World)
    {
        auto axes = orientationAxes(matrix);
        auto pos = position(matrix);

        scale(axes.x, value, axis);
        scale(axes.y, value, axis);
        scale(axes.z, value, axis);
        scale(pos, value, axis);

        set(matrix, axes, pos);
    }
    else
    {
        scale
        (
            matrix, value,
            converted<ESpace::World,EVectorRepresentation::Direction>(axis.direction, matrix),
            converted<ESpace::World,EVectorRepresentation::Point>(axis.origin, matrix)
        );
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    if constexpr (Space == ESpace::World)
    {
        auto pos = position(matrix);
        auto axes = orientationAxes(matrix);

        scale<EVectorRepresentation::Direction>(axes.x, values, pivotPoint);
        scale<EVectorRepresentation::Direction>(axes.y, values, pivotPoint);
        scale<EVectorRepresentation::Direction>(axes.z, values, pivotPoint);
        scale<EVectorRepresentation::Point>(pos, values, pivotPoint);

        set(matrix, axes, pos);
    }
    else
    {
        auto worldSpacePivot = Pivot<T>
        {
            converted<ESpace::World,EVectorRepresentation::Direction>(pivotPoint.axes.x, matrix),
            converted<ESpace::World,EVectorRepresentation::Direction>(pivotPoint.axes.y, matrix),
            converted<ESpace::World,EVectorRepresentation::Direction>(pivotPoint.axes.z, matrix),
            converted<ESpace::World,EVectorRepresentation::Point>(pivotPoint.position, matrix)
        };

        scale<ESpace::World>(matrix, values, worldSpacePivot);
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
/* Pivot (inplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, T value)
{
    scale<Axis>(pivot.position, value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, const Vector<3,T>& values)
{
    scale(pivot.position, values);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, T value, const Vector<3,T>& direction)
{
    scale(pivot.position, value, direction);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, T value, const Vector<3,T>& direction, const Vector<3,T>& origin)
{
    scale(pivot.position, value, direction);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, T value, const Axis<T>& axis)
{
    scale(pivot.position, value, axis);
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

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, T value)
{
    auto copy = vector;
    scale<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, const Vector<3,T>& values)
{
    auto copy = vector;
    scale(copy, values);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, T value, const Vector<3,T>& direction)
{
    auto copy = vector;
    scale(copy, value, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, T value, const Vector<3,T>& direction, const Vector<3,T>& origin)
{
    auto copy = vector;
    scale(copy, value, direction, origin);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, T value, const Axis<T>& axis)
{
    auto copy = vector;
    scale<Representation>(copy, value, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    auto copy = vector;
    scale<Representation>(copy, values, pivotPoint);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, const Transforms<T>& transforms)
{
    auto copy = vector;
    scale(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, T value)
{
    auto copy = matrix;
    scale<Axis,Space>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, const Vector<3,T>& values)
{
    auto copy = matrix;
    scale<Space>(copy, values);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, T value, const Vector<3,T>& direction)
{
    auto copy = matrix;
    scale<Space>(copy, value, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, T value, const Vector<3,T>& direction, const Vector<3,T>& origin)
{
    auto copy = matrix;
    scale<Space>(copy, value, direction, origin);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, T value, const Axis<T>& axis)
{
    auto copy = matrix;
    scale<Space>(copy, value, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivot)
{
    auto copy = matrix;
    scale<Space>(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    auto copy = matrix;
    scale<Space>(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(Matrix<4,4,T>& matrix, T value)
{
    auto copy = matrix;
    scale<Axis,Space>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, const Vector<3,T>& values)
{
    auto copy = matrix;
    scale<Space>(copy, values);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, T value, const Vector<3,T>& direction)
{
    auto copy = matrix;
    scale<Space>(copy, value, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, T value, const Vector<3,T>& direction, const Vector<3,T>& origin)
{
    auto copy = matrix;
    scale<Space>(copy, value, direction, origin);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, T value, const Axis<T>& axis)
{
    auto copy = matrix;
    scale<Space>(copy, value, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivot)
{
    auto copy = matrix;
    scale<Space>(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, const Transforms<T>& transforms)
{
    auto copy = matrix;
    scale<Space>(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, T value)
{
    auto copy = pivot;
    scale<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, const Vector<3,T>& values)
{
    auto copy = pivot;
    scale(copy, values);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, T value, const Vector<3,T>& direction)
{
    auto copy = pivot;
    scale(copy, value, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, T value, const Vector<3,T>& direction, const Vector<3,T>& origin)
{
    auto copy = pivot;
    scale(copy, value, direction, origin);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, T value, const Axis<T>& axis)
{
    auto copy = pivot;
    scale(copy, value, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    auto copy = pivot;
    scale(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, const Transforms<T>& transforms)
{
    auto copy = pivot;
    scale(copy, transforms);
    return copy;
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END
