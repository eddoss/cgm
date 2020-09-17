

#include <CGM/Modules/Transformations/2D/Functions/Translate.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<2,T>& vector, T value)
{
    if constexpr (Axis == EAxes::X)
    {
        vector.x += value;
    }
    else
    {
        vector.y += value;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<2,T>& vector, const Vector<2,T>& value)
{
    vector += value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<2,T>& vector, T value, const Vector<2,T>& along)
{
    vector += along * value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<2,T>& vector, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    vector += pivot.axes.x * values.x;
    vector += pivot.axes.y * values.y;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<2,T>& vector, const Transforms<T>& transforms)
{
    translate(vector, transforms.translation, transforms.pivot);
}

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr void
translate(Matrix<3,3,T>& basis, T value)
{
    Vector<2,T> axs;

    if constexpr (Space == ESpace::World)
    {
        if constexpr (Axis == EAxes::X)
        {
            axs = x<T>();
        }
        else
        {
            axs = y<T>();
        }
    }
    else
    {
        if constexpr (Axis == EAxes::X)
        {
            axs = x(basis);
        }
        else
        {
            axs = y(basis);
        }
    }

    const auto pos = position(basis) + value * axs;
    setPosition(basis, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
translate(Matrix<3,3,T>& basis, const Vector<2,T>& value)
{
    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        basis(0,2) += value.x;
        basis(1,2) += value.y;
    #else
        basis(2,0) += value.x;
        basis(2,1) += value.y;
    #endif
    }
    else
    {
        auto pos = position(basis);

        pos += x(basis) * value.x;
        pos += y(basis) * value.y;

        setPosition(basis, pos);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EVectorRepresentation AlongRepr, typename T>
constexpr CGM_FORCEINLINE void
translate(Matrix<3,3,T>& basis, T value, const Vector<2,T>& along)
{
    if constexpr (Space == ESpace::World)
    {
        setPosition(basis, position(basis) + along * value);
    }
    else
    {
        setPosition(basis, position(basis) + converted<ESpace::World,AlongRepr>(along, basis) * value);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
translate(Matrix<3,3,T>& basis, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    if constexpr (Space == ESpace::World)
    {
        auto pos = position(basis);
        pos += values.x * pivot.axes.x;
        pos += values.y * pivot.axes.y;
        setPosition(basis, pos);
    }
    else
    {
        auto piv = pivot;
        converted<ESpace::World,EVectorRepresentation::Direction>(pivot.axes.x, basis);
        converted<ESpace::World,EVectorRepresentation::Direction>(pivot.axes.y, basis);
        converted<ESpace::World,EVectorRepresentation::Point>(pivot.position, basis);

        translate<ESpace::World>(basis, values, piv);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
translate(Matrix<3,3,T>& basis, const Transforms<T>& transforms)
{
    translate<Space>(basis, transforms.translation, transforms.pivot);
}

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, T value)
{
    translate<Axis>(pivot.position, value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, const Vector<2,T>& value)
{
    pivot.position += value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, T value, const Vector<2,T>& along)
{
    pivot.position += along * value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    pivot.position += pivotPoint.axes.x * values.x;
    pivot.position += pivotPoint.axes.y * values.y;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, const Transforms<T>& transforms)
{
    translate(pivot, transforms.translation, transforms.pivot);
}

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
translate(ArbitraryAxis<T>& axis, T value)
{
    translate<Axis>(axis.position, value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(ArbitraryAxis<T>& axis, const Vector<2,T>& value)
{
    axis.position += value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(ArbitraryAxis<T>& axis, T value, const Vector<2,T>& along)
{
    axis.position += along * value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(ArbitraryAxis<T>& axis, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    axis.position += pivot.axes.x * values.x;
    axis.position += pivot.axes.y * values.y;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(ArbitraryAxis<T>& axis, const Transforms<T>& transforms)
{
    translate(axis, transforms.translation, transforms.pivot);
}

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
translated(const Vector<2,T>& vector, T value)
{
    auto copy = vector;
    translate<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
translated(const Vector<2,T>& vector, const Vector<2,T>& value)
{
    auto copy = vector;
    translate(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
translated(const Vector<2,T>& vector, T value, const Vector<2,T>& along)
{
    auto copy = vector;
    translate(copy, value, along);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
translated(const Vector<2,T>& vector, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    auto copy = vector;
    translate(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
translated(const Vector<2,T>& vector, const Transforms<T>& transforms)
{
    auto copy = vector;
    translate(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
translated(const Matrix<3,3,T>& matrix, T value)
{
    auto copy = matrix;
    translate<Axis,Space>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
translated(const Matrix<3,3,T>& matrix, const Vector<2,T>& value)
{
    auto copy = matrix;
    translate<Space>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EVectorRepresentation AlongRepr, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
translated(const Matrix<3,3,T>& basis, T value, const Vector<2,T>& along)
{
    auto copy = basis;
    translate<Space,AlongRepr>(copy, value, along);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
translated(const Matrix<3,3,T>& basis, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    auto copy = basis;
    translate<Space>(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
translated(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    auto copy = matrix;
    translate<Space>(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
translated(const Pivot<T>& pivot, T value)
{
    auto copy = pivot;
    translate<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
translated(const Pivot<T>& pivot, const Vector<2,T>& value)
{
    auto copy = pivot;
    translate(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
translated(const Pivot<T>& pivot, T value, const Vector<2,T>& along)
{
    auto copy = pivot;
    translate(copy, value, along);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
translated(const Pivot<T>& pivot, const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    auto copy = pivot;
    translate(copy, values, pivotPoint);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
translated(const Pivot<T>& pivot, const Transforms<T>& transforms)
{
    auto copy = pivot;
    translate(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Axis (outplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
translated(const ArbitraryAxis<T>& axis, T value)
{
    auto copy = axis;
    translate<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
translated(const ArbitraryAxis<T>& axis, const Vector<2,T>& value)
{
    auto copy = axis;
    translate(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
translated(const ArbitraryAxis<T>& axis, T value, const Vector<2,T>& along)
{
    auto copy = axis;
    translate(copy, value, along);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
translated(const ArbitraryAxis<T>& axis, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    auto copy = axis;
    translate(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
translated(const ArbitraryAxis<T>& axis, const Transforms<T>& transforms)
{
    auto copy = axis;
    translate(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
translationMatrix(T value)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Axis == EAxes::X)
    {
        return
        {
            number<T>(1), number<T>(0), value,
            number<T>(0), number<T>(1), number<T>(0),
            number<T>(0), number<T>(0), number<T>(1)
        };
    }
    else
    {
        return
        {
            number<T>(1), number<T>(0), number<T>(0),
            number<T>(0), number<T>(1), value,
            number<T>(0), number<T>(0), number<T>(1)
        };
    }
#else
    if constexpr (Axis == EAxes::X)
    {
        return
        {
            number<T>(1), number<T>(0), number<T>(0),
            number<T>(0), number<T>(1), number<T>(0),
            value, number<T>(0), number<T>(1)
        };
    }
    else
    {
        return
        {
            number<T>(1), number<T>(0), number<T>(0),
            number<T>(0), number<T>(1), number<T>(0),
            number<T>(0), value, number<T>(1)
        };
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
translationMatrix(const Vector<2,T>& values)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        number<T>(1), number<T>(0), values.x,
        number<T>(0), number<T>(1), values.y,
        number<T>(0), number<T>(0), number<T>(1)
    };
#else
    return
    {
        number<T>(1), number<T>(0), number<T>(0),
        number<T>(0), number<T>(1), number<T>(0),
        values.x, values.y, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
translationMatrix(T value, const Vector<2,T>& along)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        number<T>(1), number<T>(0), along.x * value,
        number<T>(0), number<T>(1), along.y * value,
        number<T>(0), number<T>(0), number<T>(1)
    };
#else
    return
    {
        number<T>(1), number<T>(0), number<T>(0),
        number<T>(0), number<T>(1), number<T>(0),
        along.x * value, along.y * value, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<3,3,T>
translationMatrix(const Vector<2,T>& values, const Pivot<T>& pivot)
{
    auto mat = identity<3,T>();
    translate(mat, values, pivot);
    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
translationMatrix(const Transforms<T>& transforms)
{
    return translationMatrix(transforms.translation, transforms.pivot);
}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END