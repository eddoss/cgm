

#include "scale.hpp"


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<2,T>& vector, T value)
{
    if constexpr (Axis == E2D::X)
    {
        vector.x += vector.x * (value - T(1));
    }
    else
    {
        vector.y += vector.y * (value - T(1));
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<2,T>& vector, const Vector<2,T>& values)
{
    vector.x *= values.x;
    vector.y *= values.y;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<2,T>& vector, T value, const Vector<2,T>& direction)
{
    vector += direction * (value - T(1)) * shortestDistance(vector, direction);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<2,T>& vector, T value, const ArbitraryAxis<T>& axis)
{
    vector += axis.direction * (value - T(1)) * shortestDistance(vector - axis.position, axis.direction);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
scale(Vector<2,T>& vector, const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    auto vec = vector - pivotPoint.position;
    vector += pivotPoint.axes.x * (values.x - T(1)) * shortestDistance(vec, pivotPoint.axes.x);
    vector += pivotPoint.axes.y * (values.y - T(1)) * shortestDistance(vec, pivotPoint.axes.y);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<2,T>& vector, const Transforms<T>& transforms)
{
    scale(vector, transforms.scale * transforms.uniformScale, transforms.pivot);
}

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

template<E2D Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<2,2,T>& matrix, T value)
{
    if constexpr (Space == ESpace::Global)
    {
        auto axes = orientationAxes(matrix);

        scale<Axis>(axes.x, value);
        scale<Axis>(axes.y, value);

        set(matrix, axes);
    }
    else
    {
        if constexpr (Axis == E2D::X)
        {
            scale<ESpace::Global>(matrix, value, x(matrix));
        }
        else
        {
            scale<ESpace::Global>(matrix, value, y(matrix));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<2,2,T>& matrix, const Vector<2,T>& values)
{
    auto scales = Matrix<2,2,T>
    {
        values.x, T(0),
        T(0), values.y
    };

    if constexpr (Space == ESpace::Global)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = scales * matrix;
    #else
        matrix = matrix * scales;
    #endif
    }
    else
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = inverse(scales) * matrix;
    #else
        matrix = matrix * inverse(scales);
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<2,2,T>& matrix, T value, const Vector<2,T>& direction)
{
    if constexpr (Space == ESpace::Global)
    {
        auto axes = orientationAxes(matrix);

        scale(axes.x, value, direction);
        scale(axes.y, value, direction);

        set(matrix, axes);
    }
    else
    {
        scale<ESpace::Global>(matrix, value, converted<ESpace::Global>(direction, matrix));
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<2,2,T>& matrix, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    auto pivotPoint = pivot;
    pivotPoint.position = Vector<2,T>(T(0));

    if constexpr (Space == ESpace::Global)
    {
        auto axes = orientationAxes(matrix);

        scale(axes.x, values, pivotPoint);
        scale(axes.y, values, pivotPoint);

        set(matrix, axes);
    }
    else
    {
        auto wsPivot = Pivot<T>
        {
            converted<ESpace::Global>(pivotPoint.axes.x, matrix),
            converted<ESpace::Global>(pivotPoint.axes.y, matrix),
            Vector<2,T>(T(0))
        };

        scale<ESpace::Global>(matrix, values, wsPivot);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<2,2,T>& matrix, const Transforms<T>& transforms)
{
    scale<Space>(matrix, transforms.scale * transforms.uniformScale, transforms.pivot);
}

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

template<E2D Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<3,3,T>& matrix, T value)
{
    if constexpr (Space == ESpace::Global)
    {
        auto axes = orientationAxes(matrix);
        auto pos = position(matrix);

        scale<Axis>(axes.x, value);
        scale<Axis>(axes.y, value);
        scale<Axis>(pos, value);

        set(matrix, axes, pos);
    }
    else
    {
        if constexpr (Axis == E2D::X)
        {
            scale<ESpace::Global>(matrix, value, x(matrix));
        }
        else
        {
            scale<ESpace::Global>(matrix, value, y(matrix));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<3,3,T>& matrix, const Vector<2,T>& values)
{
    auto scales = Matrix<3,3,T>
    {
        values.x, T(0), T(0),
        T(0), values.y, T(0),
        T(0), T(0), T(1)
    };

    if constexpr (Space == ESpace::Global)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = scales * matrix;
    #else
        matrix = matrix * scales;
    #endif

    }
    else
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = inverse(scales) * matrix;
    #else
        matrix = matrix * inverse(scales);
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, T value, const Vector<2,T>& direction)
{
    if constexpr (Space == ESpace::Global)
    {
        auto axes = orientationAxes(matrix);
        auto pos = position(matrix);

        scale(axes.x, value, direction);
        scale(axes.y, value, direction);
        scale(pos, value, direction);

        set(matrix, axes, pos);
    }
    else
    {
        scale<ESpace::Global>
        (
            matrix, value,
            converted<ESpace::Global,EVectorRepresentation::Direction>(direction, matrix)
        );
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, T value, const ArbitraryAxis<T>& axis)
{
    if constexpr (Space == ESpace::Global)
    {
        auto axes = orientationAxes(matrix);
        auto pos = position(matrix);

        scale(axes.x, value, axis.direction);
        scale(axes.y, value, axis.direction);
        scale(pos, value, axis);

        set(matrix, axes, pos);
    }
    else
    {
        scale<ESpace::Global>
        (
            matrix, value,
            ArbitraryAxis<T>
            (
                converted<ESpace::Global,EVectorRepresentation::Direction>(axis.direction, matrix),
                converted<ESpace::Global,EVectorRepresentation::Point>(axis.position, matrix)
            )
        );
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    if constexpr (Space == ESpace::Global)
    {
        auto pos = position(matrix);
        auto axes = orientationAxes(matrix);

        auto axesPivot = pivotPoint;
        axesPivot.position = Vector<2,T>(T(0));

        scale(axes.x, values, axesPivot);
        scale(axes.y, values, axesPivot);
        scale(pos, values, pivotPoint);

        set(matrix, axes, pos);
    }
    else
    {
        auto globalSpacePivot = Pivot<T>
        {
            converted<ESpace::Global,EVectorRepresentation::Direction>(pivotPoint.axes.x, matrix),
            converted<ESpace::Global,EVectorRepresentation::Direction>(pivotPoint.axes.y, matrix),
            converted<ESpace::Global,EVectorRepresentation::Point>(pivotPoint.position, matrix)
        };

        scale<ESpace::Global>(matrix, values, globalSpacePivot);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    scale<Space>(matrix, transforms.scale * transforms.uniformScale, transforms.pivot);
}

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, T value)
{
    scale<Axis>(pivot.position, value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, const Vector<2,T>& values)
{
    scale(pivot.position, values);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, T value, const Vector<2,T>& direction)
{
    scale(pivot.position, value, direction);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, T value, const ArbitraryAxis<T>& axis)
{
    scale(pivot.position, value, axis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    scale(pivot.position, values, pivotPoint);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, const Transforms<T>& transforms)
{
    scale(pivot.position, transforms);
}

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, T value)
{
    scale<Axis>(arbitraryAxis.position, value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& values)
{
    scale(arbitraryAxis.position, values);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, T value, const Vector<2,T>& direction)
{
    scale(arbitraryAxis.position, value, direction);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, T value, const ArbitraryAxis<T>& axis)
{
    scale(arbitraryAxis.position, value, axis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    scale(arbitraryAxis.position, values, pivotPoint);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, const Transforms<T>& transforms)
{
    scale(arbitraryAxis.position, transforms);
}

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, T value)
{
    auto copy = vector;
    scale<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, const Vector<2,T>& values)
{
    auto copy = vector;
    scale(copy, values);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, T value, const Vector<2,T>& direction)
{
    auto copy = vector;
    scale(copy, value, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, T value, const Vector<2,T>& direction, const Vector<2,T>& origin)
{
    auto copy = vector;
    scale(copy, value, direction, origin);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, T value, const ArbitraryAxis<T>& axis)
{
    auto copy = vector;
    scale(copy, value, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    auto copy = vector;
    scale(copy, values, pivotPoint);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, const Transforms<T>& transforms)
{
    auto copy = vector;
    scale(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

template<E2D Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
scaled(const Matrix<2,2,T>& matrix, T value)
{
    auto copy = matrix;
    scale<Axis,Space>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
scaled(const Matrix<2,2,T>& matrix, const Vector<2,T>& values)
{
    auto copy = matrix;
    scale<Space>(copy, values);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
scaled(const Matrix<2,2,T>& matrix, T value, const Vector<2,T>& direction)
{
    auto copy = matrix;
    scale<Space>(copy, value, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
scaled(const Matrix<2,2,T>& matrix, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    auto copy = matrix;
    scale<Space>(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
scaled(const Matrix<2,2,T>& matrix, const Transforms<T>& transforms)
{
    auto copy = matrix;
    scale<Space>(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

template<E2D Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, T value)
{
    auto copy = matrix;
    scale<Axis,Space>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, const Vector<2,T>& values)
{
    auto copy = matrix;
    scale<Space>(copy, values);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, T value, const Vector<2,T>& direction)
{
    auto copy = matrix;
    scale<Space>(copy, value, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, T value, const Vector<2,T>& direction, const Vector<2,T>& origin)
{
    auto copy = matrix;
    scale<Space>(copy, value, direction, origin);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, T value, const ArbitraryAxis<T>& axis)
{
    auto copy = matrix;
    scale<Space>(copy, value, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    auto copy = matrix;
    scale<Space>(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    auto copy = matrix;
    scale<Space>(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, T value)
{
    auto copy = pivot;
    scale<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, const Vector<2,T>& values)
{
    auto copy = pivot;
    scale(copy, values);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, T value, const Vector<2,T>& direction)
{
    auto copy = pivot;
    scale(copy, value, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, T value, const Vector<2,T>& direction, const Vector<2,T>& origin)
{
    auto copy = pivot;
    scale(copy, value, direction, origin);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, T value, const ArbitraryAxis<T>& axis)
{
    auto copy = pivot;
    scale(copy, value, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    auto copy = pivot;
    scale(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, const Transforms<T>& transforms)
{
    auto copy = pivot;
    scale(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, T value)
{
    auto copy = arbitraryAxis;
    scale<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& values)
{
    auto copy = arbitraryAxis;
    scale(copy, values);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, T value, const Vector<2,T>& direction)
{
    auto copy = arbitraryAxis;
    scale(copy, value, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, T value, const ArbitraryAxis<T>& axis)
{
    auto copy = arbitraryAxis;
    scale(copy, value, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    auto copy = arbitraryAxis;
    scale(copy, values, pivotPoint);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, const Transforms<T>& transforms)
{
    auto copy = arbitraryAxis;
    scale(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

template<E2D Axis, size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==2 || N==3), Matrix<N,N,T>>
scalingMatrix(T value)
{
    if constexpr (N == 2)
    {
        if constexpr (Axis == E2D::X)
        {
            return
            {
                value, T(0),
                T(0), T(1)
            };
        }
        else
        {
            return
            {
                T(1), T(0),
                T(0), value
            };
        }
    }
    else
    {
        if constexpr (Axis == E2D::X)
        {
            return
            {
                value, T(0), T(0),
                T(0), T(1), T(0),
                T(0), T(0), T(1)
            };
        }
        else
        {
            return
            {
                T(1), T(0), T(0),
                T(0), value, T(0),
                T(0), T(0), T(1)
            };
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==2 || N==3), Matrix<N,N,T>>
scalingMatrix(const Vector<2,T>& values)
{
    if constexpr (N == 2)
    {
        return
        {
            values.x, T(0),
            T(0), values.y,
        };
    }
    else
    {
        return
        {
            values.x, T(0), T(0),
            T(0), values.y, T(0),
            T(0), T(0), T(1)
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==2 || N==3), Matrix<N,N,T>>
scalingMatrix(T value, const Vector<2,T>& direction)
{
    auto mat = identity<N,T>();
    scale(mat, value, direction);
    transposeOrientation(mat);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scalingMatrix(T value, const ArbitraryAxis<T>& axis)
{
    auto mat = identity<3,T>();
    scale(mat, value, axis);
    transposeOrientation(mat);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scalingMatrix(const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    auto mat = identity<3,T>();
    scale(mat, values, pivotPoint);
    transposeOrientation(mat);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scalingMatrix(const Transforms<T>& transforms)
{
    auto mat = identity<3,T>();
    scale(mat, transforms);
    transposeOrientation(mat);

    return mat;
}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END
