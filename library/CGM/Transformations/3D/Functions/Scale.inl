

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
    else if constexpr (Axis == EAxes::Y)
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
scale(Vector<3,T>& vector, T value, const ArbitraryAxis<T>& axis)
{
    vector += axis.direction * (value - number<T>(1)) * shortestDistance(vector - axis.position, axis.direction);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
scale(Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    auto vec = vector - pivotPoint.position;
    vector += pivotPoint.axes.x * (values.x - number<T>(1)) * shortestDistance(vec, pivotPoint.axes.x);
    vector += pivotPoint.axes.y * (values.y - number<T>(1)) * shortestDistance(vec, pivotPoint.axes.y);
    vector += pivotPoint.axes.z * (values.z - number<T>(1)) * shortestDistance(vec, pivotPoint.axes.z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, const Transforms<T>& transforms)
{
    scale(vector, transforms.scale * transforms.uniformScale, transforms.pivot);
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
    auto scaler = Matrix<3,3,T>
    {
        values.x, number<T>(0), number<T>(0),
        number<T>(0), values.y, number<T>(0),
        number<T>(0), number<T>(0), values.z
    };

    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_MATRIX_POST_MULTIPLICATION
        matrix = scaler * matrix;
    #else
        matrix = matrix * scaler;
    #endif
    }
    else
    {
    #ifdef CGM_MATRIX_POST_MULTIPLICATION
        matrix = matrix * scaler;
    #else
        matrix = scaler * matrix;
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
scale(Matrix<3,3,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivot)
{
    auto pivotPoint = pivot;
    pivotPoint.position = Vector<3,T>(zero<T>);

    if constexpr (Space == ESpace::World)
    {
        auto axes = orientationAxes(matrix);

        scale(axes.x, values, pivotPoint);
        scale(axes.y, values, pivotPoint);
        scale(axes.z, values, pivotPoint);

        set(matrix, axes);
    }
    else
    {
        scale<ESpace::World>(matrix, values, converted<ESpace::World>(pivot, matrix));
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    scale<Space>(matrix, transforms.scale * transforms.uniformScale, transforms.pivot);
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
    auto scaler = Matrix<4,4,T>
    {
        values.x, number<T>(0), number<T>(0), number<T>(0),
        number<T>(0), values.y, number<T>(0), number<T>(0),
        number<T>(0), number<T>(0), values.z, number<T>(0),
        number<T>(0), number<T>(0), number<T>(0), number<T>(1)
    };

    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_MATRIX_POST_MULTIPLICATION
        matrix = scaler * matrix;
    #else
        matrix = matrix * scaler;
    #endif

    }
    else
    {
    #ifdef CGM_MATRIX_POST_MULTIPLICATION
        matrix = matrix * scaler;
    #else
        matrix = scaler * matrix;
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
        scale<ESpace::World>
        (
            matrix, value,
            converted<ESpace::World,EVectorRepresentation::Direction>(direction, matrix)
        );
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<4,4,T>& matrix, T value, const ArbitraryAxis<T>& axis)
{
    if constexpr (Space == ESpace::World)
    {
        auto axes = orientationAxes(matrix);
        auto pos = position(matrix);

        scale(axes.x, value, axis.direction);
        scale(axes.y, value, axis.direction);
        scale(axes.z, value, axis.direction);
        scale(pos, value, axis);

        set(matrix, axes, pos);
    }
    else
    {
        scale<ESpace::World>
        (
            matrix, value,
            ArbitraryAxis<T>
            (
                converted<ESpace::World,EVectorRepresentation::Direction>(axis.direction, matrix),
                converted<ESpace::World,EVectorRepresentation::Point>(axis.position, matrix)
            )
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

        auto axesPivot = pivotPoint;
        axesPivot.position = Vector<3,T>(zero<T>);

        scale(axes.x, values, axesPivot);
        scale(axes.y, values, axesPivot);
        scale(axes.z, values, axesPivot);
        scale(pos, values, pivotPoint);

        set(matrix, axes, pos);
    }
    else
    {
        scale<ESpace::World>(matrix, values, converted<ESpace::World>(pivotPoint, matrix));
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Transforms<T>& transforms)
{
    scale<Space>(matrix, transforms.scale * transforms.uniformScale, transforms.pivot);
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
scale(Pivot<T>& pivot, T value, const ArbitraryAxis<T>& axis)
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
/* Axis (inplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
scale(ArbitraryAxis<T>& arbitraryAxis, T value)
{
    scale<Axis>(arbitraryAxis.position, value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& values)
{
    scale(arbitraryAxis.position, values);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(ArbitraryAxis<T>& arbitraryAxis, T value, const Vector<3,T>& direction)
{
    scale(arbitraryAxis.position, value, direction);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(ArbitraryAxis<T>& arbitraryAxis, T value, const ArbitraryAxis<T>& axis)
{
    scale(arbitraryAxis.position, value, axis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    scale(arbitraryAxis.position, values, pivotPoint);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(ArbitraryAxis<T>& arbitraryAxis, const Transforms<T>& transforms)
{
    scale(arbitraryAxis.position, transforms);
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

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, T value, const ArbitraryAxis<T>& axis)
{
    auto copy = vector;
    scale(copy, value, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    auto copy = vector;
    scale(copy, values, pivotPoint);
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
scaled(const Matrix<4,4,T>& matrix, T value)
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
scaled(const Matrix<4,4,T>& matrix, T value, const ArbitraryAxis<T>& axis)
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
scaled(const Pivot<T>& pivot, T value, const ArbitraryAxis<T>& axis)
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

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
scaled(const ArbitraryAxis<T>& arbitraryAxis, T value)
{
    auto copy = arbitraryAxis;
    scale<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
scaled(const ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& values)
{
    auto copy = arbitraryAxis;
    scale(copy, values);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
scaled(const ArbitraryAxis<T>& arbitraryAxis, T value, const Vector<3,T>& direction)
{
    auto copy = arbitraryAxis;
    scale(copy, value, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
scaled(const ArbitraryAxis<T>& arbitraryAxis, T value, const ArbitraryAxis<T>& axis)
{
    auto copy = arbitraryAxis;
    scale(copy, value, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
scaled(const ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    auto copy = arbitraryAxis;
    scale(copy, values, pivotPoint);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
scaled(const ArbitraryAxis<T>& arbitraryAxis, const Transforms<T>& transforms)
{
    auto copy = arbitraryAxis;
    scale(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

template<EAxes Axis, size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
scalingMatrix(T value)
{
    if constexpr (N == 3)
    {
        if constexpr (Axis == EAxes::X)
        {
            return
            {
                value, number<T>(0), number<T>(0),
                number<T>(0), number<T>(1), number<T>(0),
                number<T>(0), number<T>(0), number<T>(1)
            };
        }
        else if constexpr (Axis == EAxes::Y)
        {
            return
            {
                number<T>(1), number<T>(0), number<T>(0),
                number<T>(0), value, number<T>(0),
                number<T>(0), number<T>(0), number<T>(1)
            };
        }
        else
        {
            return
            {
                number<T>(1), number<T>(0), number<T>(0),
                number<T>(0), number<T>(1), number<T>(0),
                number<T>(0), number<T>(0), value
            };
        }
    }
    else
    {
        if constexpr (Axis == EAxes::X)
        {
            return
            {
                value, number<T>(0), number<T>(0), number<T>(0),
                number<T>(0), number<T>(1), number<T>(0), number<T>(0),
                number<T>(0), number<T>(0), number<T>(1), number<T>(0),
                number<T>(0), number<T>(0), number<T>(0), number<T>(1)
            };
        }
        else if constexpr (Axis == EAxes::Y)
        {
            return
            {
                number<T>(1), number<T>(0), number<T>(0), number<T>(0),
                number<T>(0), value, number<T>(0), number<T>(0),
                number<T>(0), number<T>(0), number<T>(1), number<T>(0),
                number<T>(0), number<T>(0), number<T>(0), number<T>(1)
            };
        }
        else
        {
            return
            {
                number<T>(1), number<T>(0), number<T>(0), number<T>(0),
                number<T>(0), number<T>(1), number<T>(0), number<T>(0),
                number<T>(0), number<T>(0), value, number<T>(0),
                number<T>(0), number<T>(0), number<T>(0), number<T>(1)
            };
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
scalingMatrix(const Vector<3,T>& values)
{
    if constexpr (N == 3)
    {
        return {
            values.x, number<T>(0), number<T>(0),
            number<T>(0), values.y, number<T>(0),
            number<T>(0), number<T>(0), values.z
        };
    }
    else
    {
        return
        {
            values.x, number<T>(0), number<T>(0), number<T>(0),
            number<T>(0), values.y, number<T>(0), number<T>(0),
            number<T>(0), number<T>(0), values.z, number<T>(0),
            number<T>(0), number<T>(0), number<T>(0), number<T>(1)
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
scalingMatrix(T value, const Vector<3,T>& direction)
{
    auto mat = CGM::identity<N,T>();
    scale(mat, value, direction);
    transposeOrientation(mat);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scalingMatrix(T value, const ArbitraryAxis<T>& axis)
{
    auto mat = CGM::identity<4,T>();
    scale(mat, value, axis);
    transposeOrientation(mat);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scalingMatrix(const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    auto mat = CGM::identity<4,T>();
    scale(mat, values, pivotPoint);
    transposeOrientation(mat);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scalingMatrix(const Transforms<T>& transforms)
{
    auto mat = CGM::identity<4,T>();
    scale(mat, transforms);
    transposeOrientation(mat);

    return mat;
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END
