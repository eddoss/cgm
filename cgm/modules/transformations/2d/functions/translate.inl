

#include "translate.hpp"


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Vector<2,T>& vector, T value)
{
    if constexpr (Axis == E2D::X)
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
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Vector<2,T>& vector, const Vector<2,T>& value)
{
    vector += value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Vector<2,T>& vector, T value, const Vector<2,T>& along)
{
    vector += along * value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Vector<2,T>& vector, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    vector += pivot.axes.x * values.x;
    vector += pivot.axes.y * values.y;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Vector<2,T>& vector, const Transforms<T>& transforms)
{
    translate(vector, transforms.translation, transforms.pivot);
}

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

template<E2D Axis, ESpace Space, typename T>
constexpr enable_if_floating<T, void>
translate(Matrix<3,3,T>& basis, T value)
{
    Vector<2,T> axs;

    if constexpr (Space == ESpace::Global)
    {
        if constexpr (Axis == E2D::X)
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
        if constexpr (Axis == E2D::X)
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
constexpr enable_if_floating<T, void>
translate(Matrix<3,3,T>& basis, const Vector<2,T>& value)
{
    if constexpr (Space == ESpace::Global)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
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
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Matrix<3,3,T>& basis, T value, const Vector<2,T>& along)
{
    if constexpr (Space == ESpace::Global)
    {
        setPosition(basis, position(basis) + along * value);
    }
    else
    {
        setPosition(basis, position(basis) + converted<ESpace::Global,AlongRepr>(along, basis) * value);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Matrix<3,3,T>& basis, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    if constexpr (Space == ESpace::Global)
    {
        auto pos = position(basis);
        pos += values.x * pivot.axes.x;
        pos += values.y * pivot.axes.y;
        setPosition(basis, pos);
    }
    else
    {
        auto piv = pivot;
        converted<ESpace::Global,EVectorRepresentation::Direction>(pivot.axes.x, basis);
        converted<ESpace::Global,EVectorRepresentation::Direction>(pivot.axes.y, basis);
        converted<ESpace::Global,EVectorRepresentation::Point>(pivot.position, basis);

        translate<ESpace::Global>(basis, values, piv);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Matrix<3,3,T>& basis, const Transforms<T>& transforms)
{
    translate<Space>(basis, transforms.translation, transforms.pivot);
}

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Pivot<T>& pivot, T value)
{
    translate<Axis>(pivot.position, value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Pivot<T>& pivot, const Vector<2,T>& value)
{
    pivot.position += value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Pivot<T>& pivot, T value, const Vector<2,T>& along)
{
    pivot.position += along * value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Pivot<T>& pivot, const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    pivot.position += pivotPoint.axes.x * values.x;
    pivot.position += pivotPoint.axes.y * values.y;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Pivot<T>& pivot, const Transforms<T>& transforms)
{
    translate(pivot, transforms.translation, transforms.pivot);
}

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(ArbitraryAxis<T>& axis, T value)
{
    translate<Axis>(axis.position, value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(ArbitraryAxis<T>& axis, const Vector<2,T>& value)
{
    axis.position += value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(ArbitraryAxis<T>& axis, T value, const Vector<2,T>& along)
{
    axis.position += along * value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(ArbitraryAxis<T>& axis, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    axis.position += pivot.axes.x * values.x;
    axis.position += pivot.axes.y * values.y;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(ArbitraryAxis<T>& axis, const Transforms<T>& transforms)
{
    translate(axis, transforms.translation, transforms.pivot);
}

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
translated(const Vector<2,T>& vector, T value)
{
    auto copy = vector;
    translate<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
translated(const Vector<2,T>& vector, const Vector<2,T>& value)
{
    auto copy = vector;
    translate(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
translated(const Vector<2,T>& vector, T value, const Vector<2,T>& along)
{
    auto copy = vector;
    translate(copy, value, along);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
translated(const Vector<2,T>& vector, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    auto copy = vector;
    translate(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
translated(const Vector<2,T>& vector, const Transforms<T>& transforms)
{
    auto copy = vector;
    translate(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

template<E2D Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translated(const Matrix<3,3,T>& matrix, T value)
{
    auto copy = matrix;
    translate<Axis,Space>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translated(const Matrix<3,3,T>& matrix, const Vector<2,T>& value)
{
    auto copy = matrix;
    translate<Space>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EVectorRepresentation AlongRepr, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translated(const Matrix<3,3,T>& basis, T value, const Vector<2,T>& along)
{
    auto copy = basis;
    translate<Space,AlongRepr>(copy, value, along);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translated(const Matrix<3,3,T>& basis, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    auto copy = basis;
    translate<Space>(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translated(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    auto copy = matrix;
    translate<Space>(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
translated(const Pivot<T>& pivot, T value)
{
    auto copy = pivot;
    translate<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
translated(const Pivot<T>& pivot, const Vector<2,T>& value)
{
    auto copy = pivot;
    translate(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
translated(const Pivot<T>& pivot, T value, const Vector<2,T>& along)
{
    auto copy = pivot;
    translate(copy, value, along);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
translated(const Pivot<T>& pivot, const Vector<2,T>& values, const Pivot<T>& pivotPoint)
{
    auto copy = pivot;
    translate(copy, values, pivotPoint);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
translated(const Pivot<T>& pivot, const Transforms<T>& transforms)
{
    auto copy = pivot;
    translate(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Axis (outplace) */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
translated(const ArbitraryAxis<T>& axis, T value)
{
    auto copy = axis;
    translate<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
translated(const ArbitraryAxis<T>& axis, const Vector<2,T>& value)
{
    auto copy = axis;
    translate(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
translated(const ArbitraryAxis<T>& axis, T value, const Vector<2,T>& along)
{
    auto copy = axis;
    translate(copy, value, along);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
translated(const ArbitraryAxis<T>& axis, const Vector<2,T>& values, const Pivot<T>& pivot)
{
    auto copy = axis;
    translate(copy, values, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
translated(const ArbitraryAxis<T>& axis, const Transforms<T>& transforms)
{
    auto copy = axis;
    translate(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translationMatrix(T value)
{
#ifdef CGM_CFG_MATRIX_POSTMULT
    if constexpr (Axis == E2D::X)
    {
        return
        {
            T(1), T(0), value,
            T(0), T(1), T(0),
            T(0), T(0), T(1)
        };
    }
    else
    {
        return
        {
            T(1), T(0), T(0),
            T(0), T(1), value,
            T(0), T(0), T(1)
        };
    }
#else
    if constexpr (Axis == E2D::X)
    {
        return
        {
            T(1), T(0), T(0),
            T(0), T(1), T(0),
            value, T(0), T(1)
        };
    }
    else
    {
        return
        {
            T(1), T(0), T(0),
            T(0), T(1), T(0),
            T(0), value, T(1)
        };
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translationMatrix(const Vector<2,T>& values)
{
#ifdef CGM_CFG_MATRIX_POSTMULT
    return
    {
        T(1), T(0), values.x,
        T(0), T(1), values.y,
        T(0), T(0), T(1)
    };
#else
    return
    {
        T(1), T(0), T(0),
        T(0), T(1), T(0),
        values.x, values.y, T(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translationMatrix(T value, const Vector<2,T>& along)
{
#ifdef CGM_CFG_MATRIX_POSTMULT
    return
    {
        T(1), T(0), along.x * value,
        T(0), T(1), along.y * value,
        T(0), T(0), T(1)
    };
#else
    return
    {
        T(1), T(0), T(0),
        T(0), T(1), T(0),
        along.x * value, along.y * value, T(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr enable_if_floating<T, Matrix<3,3,T>>
translationMatrix(const Vector<2,T>& values, const Pivot<T>& pivot)
{
    auto mat = identity<3,T>();
    translate(mat, values, pivot);
    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translationMatrix(const Transforms<T>& transforms)
{
    return translationMatrix(transforms.translation, transforms.pivot);
}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END