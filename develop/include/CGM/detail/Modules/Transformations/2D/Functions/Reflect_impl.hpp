

#include <CGM/detail/Modules/Transformations/2D/Functions/Reflect.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr void
reflect(Vector<2,T>& vector, const Vector<2,T>& axisNormal)
{
    vector -= number<T>(2) * dot(vector, axisNormal) * axisNormal;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
reflect(Vector<2,T>& vector, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter)
{
    auto projected = dot(vector, axisNormal) * axisNormal;
    auto reflected = vector - projected - projected;

    T dist = dot(axisCenter, axisNormal);
    reflected += axisNormal * dist * number<T>(2);

    vector = reflected;
}

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr void
reflect(Matrix<2,2,T>& matrix, const Vector<2,T>& axisNormal)
{
    auto axes = orientationAxes(matrix);

    if constexpr (Space == ESpace::World)
    {
        reflect(axes.x, axisNormal);
        reflect(axes.y, axisNormal);
    }
    else
    {
        auto an = converted<ESpace::World>(axisNormal, matrix);

        reflect(axes.x, an);
        reflect(axes.y, an);
    }

    set(matrix, axes);
}

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, const Vector<2,T>& axisNormal)
{
    auto axes = orientationAxes(matrix);
    auto pos = position(matrix);

    if constexpr (Space == ESpace::World)
    {
        reflect(axes.x, axisNormal);
        reflect(axes.y, axisNormal);
        reflect(pos, axisNormal);
    }
    else
    {
        auto pn = converted<ESpace::World>(axisNormal, matrix);

        reflect(axes.x, pn);
        reflect(axes.y, pn);
        reflect(pos, pn);
    }

    set(matrix, axes, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter)
{
    auto axes = orientationAxes(matrix);
    auto pos = position(matrix);

    if constexpr (Space == ESpace::World)
    {
        reflect(axes.x, axisNormal);
        reflect(axes.y, axisNormal);
        reflect(pos, axisNormal, axisCenter);
    }
    else
    {
        auto an = converted<ESpace::World>(axisNormal, matrix);
        auto ac = converted<ESpace::World>(axisCenter, matrix);

        reflect(axes.x, an);
        reflect(axes.y, an);
        reflect(pos, an, ac);
    }

    set(matrix, axes, pos);
}

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr void
reflect(Pivot<T>& pivot, const Vector<2,T>& axisNormal)
{
    reflect(pivot.axes.x, axisNormal);
    reflect(pivot.axes.y, axisNormal);
    reflect(pivot.position, axisNormal);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
reflect(Pivot<T>& pivot, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter)
{
    reflect(pivot.axes.x, axisNormal);
    reflect(pivot.axes.y, axisNormal);
    reflect(pivot.position, axisNormal, axisCenter);
}

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
reflect(ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& axisNormal)
{
    reflect(arbitraryAxis.direction, axisNormal);
    reflect(arbitraryAxis.position, axisNormal);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
reflect(ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter)
{
    reflect(arbitraryAxis.direction, axisNormal);
    reflect(arbitraryAxis.position, axisNormal, axisCenter);
}

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr Vector<2,T>
reflected(const Vector<2,T>& vector, const Vector<2,T>& axisNormal)
{
    auto copy = vector;
    reflect(copy, axisNormal);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<2,T>
reflected(const Vector<2,T>& vector, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter)
{
    auto copy = vector;
    reflect(copy, axisNormal, axisCenter);
    return copy;
}

/* ####################################################################################### */
/* Matrix2 (outplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr Matrix<2,2,T>
reflected(const Matrix<2,2,T>& matrix, const Vector<2,T>& axisNormal)
{
    auto copy = matrix;
    reflect<Space>(copy, axisNormal);
    return copy;
}

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr Matrix<3,3,T>
reflected(const Matrix<3,3,T>& matrix, const Vector<2,T>& axisNormal)
{
    auto copy = matrix;
    reflect<Space>(copy, axisNormal);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<3,3,T>
reflected(const Matrix<3,3,T>& matrix, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter)
{
    auto copy = matrix;
    reflect<Space>(copy, axisNormal, axisCenter);
    return copy;
}

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr Pivot<T>
reflected(const Pivot<T>& pivot, const Vector<2,T>& axisNormal)
{
    auto copy = pivot;
    reflect(copy, axisNormal);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Pivot<T>
reflected(const Pivot<T>& pivot, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter)
{
    auto copy = pivot;
    reflect(copy, axisNormal, axisCenter);
    return copy;
}

/* ####################################################################################### */
/* Axis (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
reflected(const ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& axisNormal)
{
    auto copy = arbitraryAxis;
    reflect(copy, axisNormal);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
reflected(const ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter)
{
    auto copy = arbitraryAxis;
    reflect(copy, axisNormal, axisCenter);
    return copy;
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
reflectionMatrix(const Vector<2,T>& axisNormal)
{
    auto mat = identity<N,T>();
    reflect(mat, axisNormal);

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

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
reflectionMatrix(const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter)
{
    auto mat = identity<3,T>();
    reflect(mat, axisNormal, axisCenter);
    transposeOrientation(mat);

    return mat;
}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END