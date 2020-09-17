

#include <CGM/Modules/Transformations/2D/Functions/Rotate.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<2,T>& vector, T angle)
{
    const T sin = number<T>(std::sin(angle));
    const T cos = number<T>(std::cos(angle));

#ifdef CGM_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    vector.x = vector.x * cos - vector.y * sin;
    vector.y = vector.x * sin + vector.y * cos;
#else
    vector.x = vector.x * cos + vector.y * sin;
    vector.y = vector.y * cos - vector.x * sin;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<2,T>& vector, T angle, const Vector<2,T>& point)
{
    vector -= point;
    rotate(vector, angle);
    vector += point;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<2,T>& vector, T angle, const Pivot<T>& pivot)
{
    vector -= pivot.position;
    rotate(vector, angle);
    vector += pivot.position;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<2,T>& vector, const Transforms<T>& transforms)
{
    vector -= transforms.pivot.position;
    rotate(vector, transforms.rotation);
    vector += transforms.pivot.position;
}

/* ####################################################################################### */
/* Matrix2 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<2,2,T>& matrix, T angle)
{
    const T sin = number<T>(std::sin(angle));
    const T cos = number<T>(std::cos(angle));

#ifdef CGM_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix *= {
            cos, -sin,
            sin,  cos
        };
    #else
        matrix *= {
             cos, sin,
            -sin, cos
        };
    #endif
#else
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix *= {
             cos, sin,
            -sin, cos
        };
    #else
        matrix *= {
            cos, -sin,
            sin,  cos
        };
    #endif
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<2,2,T>& matrix, const Transforms<T>& transforms)
{
    rotate(matrix, transforms.rotation);
}

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, T angle)
{
    const T sin = number<T>(std::sin(angle));
    const T cos = number<T>(std::cos(angle));

    auto axs = orientationAxes(matrix);

#ifdef CGM_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    axs.x.x = axs.x.x * cos - axs.x.y * sin;
    axs.x.y = axs.x.x * sin + axs.x.y * cos;
    axs.y.x = axs.y.x * cos - axs.y.y * sin;
    axs.y.y = axs.y.x * sin + axs.y.y * cos;
#else
    axs.x.x = axs.x.x * cos + axs.x.y * sin;
    axs.x.y = axs.x.y * cos - axs.x.x * sin;
    axs.y.x = axs.y.x * cos + axs.y.y * sin;
    axs.y.y = axs.y.y * cos - axs.y.x * sin;
#endif

    if constexpr (Space == ESpace::World)
    {
        auto pos = position(matrix);

    #ifdef CGM_USE_LEFT_HANDED_CARTESIAN_SYSTEM
        pos.x = pos.x * cos - pos.y * sin;
        pos.y = pos.x * sin + pos.y * cos;
    #else
        pos.x = pos.x * cos + pos.y * sin;
        pos.y = pos.y * cos - pos.x * sin;
    #endif

        set(matrix, axs, pos);
    }
    else
    {
        setOrientation(matrix, axs);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, T angle, const Vector<2,T>& point)
{
    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix(0,2) -= point.x;
        matrix(1,2) -= point.y;
    #else
        matrix(2,0) -= point.x;
        matrix(2,1) -= point.y;
    #endif

        rotate<ESpace::World>(matrix, angle);

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix(0,2) += point.x;
        matrix(1,2) += point.y;
    #else
        matrix(2,0) += point.x;
        matrix(2,1) += point.y;
    #endif
    }
    else
    {
        const auto pt = converted<ESpace::World,EVectorRepresentation::Point>(point, matrix);

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix(0,2) -= pt.x;
        matrix(1,2) -= pt.y;
    #else
        matrix(2,0) -= pt.x;
        matrix(2,1) -= pt.y;
    #endif

        rotate<ESpace::World>(matrix, angle);

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix(0,2) += pt.x;
        matrix(1,2) += pt.y;
    #else
        matrix(2,0) += pt.x;
        matrix(2,1) += pt.y;
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, T angle, const Pivot<T>& pivot)
{
    rotate<Space>(matrix, angle, pivot);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    rotate<Space>(matrix, transforms.angle, transforms.pivot);
}

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, T angle)
{
    rotate(pivot.axes.x, angle);
    rotate(pivot.axes.y, angle);
    rotate(pivot.position, angle);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, T angle, const Vector<2,T>& point)
{
    rotate(pivot.axes.x, angle);
    rotate(pivot.axes.y, angle);
    rotate(pivot.position, angle, point);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, T angle, const Pivot<T>& pivotPoint)
{
    rotate(pivot.axes.x, angle);
    rotate(pivot.axes.y, angle);
    rotate(pivot.position, angle, pivotPoint.position);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, const Transforms<T>& transforms)
{
    rotate(pivot.axes.x, transforms.angle);
    rotate(pivot.axes.y, transforms.angle);
    rotate(pivot.position, transforms.rotation, transforms.pivot.position);
}

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& axis, T angle)
{
    rotate(axis.direction, angle);
    rotate(axis.position, angle);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& axis, T angle, const Vector<2,T>& point)
{
    rotate(axis.direction, angle);
    rotate(axis.position, angle, point);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& axis, T angle, const Pivot<T>& pivotPoint)
{
    rotate(axis.direction, angle);
    rotate(axis.position, angle, pivotPoint.position);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& axis, const Transforms<T>& transforms)
{
    rotate(axis.direction, transforms.rotation);
    rotate(axis.position, transforms.rotation, transforms.pivot.position);
}

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
rotated(const Vector<2,T>& vector, T angle)
{
    auto copy = vector;
    rotate(copy, angle);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
rotated(const Vector<2,T>& vector, T angle, const Vector<2,T>& point)
{
    auto copy = vector;
    rotate(copy, angle, point);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
rotated(const Vector<2,T>& vector, T angle, const Pivot<T>& pivot)
{
    auto copy = vector;
    rotate(copy, angle, pivot.position);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
rotated(const Vector<2,T>& vector, const Transforms<T>& transforms)
{
    auto copy = vector;
    rotate(copy, transforms.rotation, transforms.pivot.position);
    return copy;
}

/* ####################################################################################### */
/* Matrix2 (outplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
rotated(const Matrix<2,2,T>& matrix, T angle)
{
    auto copy = matrix;
    rotate(copy, angle);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
rotated(const Matrix<2,2,T>& matrix, const Transforms<T>& transforms)
{
    auto copy = matrix;
    rotate(copy, transforms.rotation);
    return copy;
}

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, T angle)
{
    auto copy = matrix;
    rotate(copy, angle);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, T angle, const Vector<2,T>& point)
{
    auto copy = matrix;
    rotate(copy, angle, point);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, T angle, const Pivot<T>& pivot)
{
    auto copy = matrix;
    rotate(copy, angle, pivot.position);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    auto copy = matrix;
    rotate(copy, transforms.rotation, transforms.pivot.position);
    return copy;
}

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, T angle)
{
    auto copy = pivot;
    rotate(copy, angle);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, T angle, const Vector<2,T>& point)
{
    auto copy = pivot;
    rotate(copy, angle, point);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, T angle, const Pivot<T>& pivotPoint)
{
    auto copy = pivot;
    rotate(copy, angle, pivotPoint.position);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, const Transforms<T>& transforms)
{
    auto copy = pivot;
    rotate(copy, transforms.rotation, transforms.pivot.position);
    return copy;
}

/* ####################################################################################### */
/* Axis (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& axis, T angle)
{
    auto copy = axis;
    rotate(copy, angle);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& axis, T angle, const Vector<2,T>& point)
{
    auto copy = axis;
    rotate(copy, angle, point);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& axis, T angle, const Pivot<T>& pivotPoint)
{
    auto copy = axis;
    rotate(copy, angle, pivotPoint.position);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& axis, const Transforms<T>& transforms)
{
    auto copy = axis;
    rotate(copy, transforms.rotation, transforms.pivot.position);
    return copy;
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotationMatrix(T angle)
{
    auto mat = identity<N,T>();
    rotate<ESpace::World>(mat, angle);

    if constexpr (N == 3)
    {
        transpose(mat);
    }
    else
    {
        transposeOrientation(mat);
    }

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotationMatrix(T angle, const Vector<2,T>& point)
{
    auto mat = identity<3,T>();
    rotate<ESpace::World>(mat, angle, point);

    if constexpr (N == 3)
    {
        transpose(mat);
    }
    else
    {
        transposeOrientation(mat);
    }

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotationMatrix(T angle, const Pivot<T>& pivot)
{
    auto mat = identity<3,T>();
    rotate<ESpace::World>(mat, angle, pivot.position);

    if constexpr (N == 3)
    {
        transpose(mat);
    }
    else
    {
        transposeOrientation(mat);
    }

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotationMatrix(const Transforms<T>& transforms)
{
    auto mat = identity<3,T>();
    rotate<ESpace::World>(mat, transforms.rotation, transforms.pivot.position);

    if constexpr (N == 3)
    {
        transpose(mat);
    }
    else
    {
        transposeOrientation(mat);
    }

    return mat;
}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END