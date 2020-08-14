

#include <CGM/Modules/Cartesian/2D/Functions/Utils.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
x(const Matrix<S,S,T>& basis)
{
    return
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,0),
        basis(0,1)
    };
#else
    {
        basis(0,0),
        basis(1,0)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
x(const Axes<T>& axes)
{
    return axes.x;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
y(const Matrix<S,S,T>& basis)
{
    return
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(1,0),
        basis(1,1)
    };
#else
    {
        basis(0,1),
        basis(1,1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
y(const Axes<T>& axes)
{
    return axes.y;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setX(Matrix<S,S,T>& basis, const Vector<2,T>& value)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,0) = value.x;
    basis(0,1) = value.y;
#else
    basis(0,0) = value.x;
    basis(1,0) = value.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setX(Axes<T>& axes, const Vector<2,T>& value)
{
    axes.x = value;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setY(Matrix<S,S,T>& basis, const Vector<2,T>& value)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(1,0) = value.x;
    basis(1,1) = value.y;
#else
    basis(0,1) = value.x;
    basis(1,1) = value.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setY(Axes<T>& axes, const Vector<2,T>& value)
{
    axes.y = value;
}

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
position(const Matrix<3,3,T>& basis)
{
    return
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,2),
        basis(1,2)
    };
#else
    {
        basis(2,0),
        basis(2,1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setPosition(Matrix<3,3,T>& basis, const Vector<2,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,2) = position.x;
    basis(1,2) = position.y;
#else
    basis(2,0) = position.x;
    basis(2,1) = position.y;
#endif
}

/* ####################################################################################### */
/* Orientation */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
orientation(const Matrix<3,3,T>& basis)
{
    return
    {
        basis(0,0), basis(0,1),
        basis(1,0), basis(1,1)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& basis, const Vector<2,T>& x, const Vector<2,T>& y)
{
    setX(basis, x);
    setY(basis, y);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& basis, const Matrix<2,2,T>& orientation)
{
    basis(0,0) = orientation(0,0);
    basis(0,1) = orientation(0,1);
    basis(1,0) = orientation(1,0);
    basis(1,1) = orientation(1,1);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& basis, const Matrix<3,3,T>& other)
{
    basis(0,0) = other(0,0);
    basis(0,1) = other(0,1);
    basis(1,0) = other(1,0);
    basis(1,1) = other(1,1);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& basis, const Axes<T>& axes)
{
    setX(basis, x(axes));
    setY(basis, y(axes));
}

/* ####################################################################################### */
/* Space matrix */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
spaceMatrix(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        x.x, x.y, position.x,
        y.x, y.y, position.y,
        zero<T>, zero<T>, number<T>(1)
    };
#else
    return
    {
        x.x, y.x, zero<T>,
        x.y, y.y, zero<T>,
        position.x, position.y, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
spaceMatrix(const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        orientation(0,0), orientation(0,1), position.x,
        orientation(1,0), orientation(1,1), position.y,
        zero<T>, zero<T>, number<T>(1)
    };
#else
    return
    {
        orientation(0,0), orientation(0,1), zero<T>,
        orientation(1,0), orientation(1,1), zero<T>,
        position.x, position.y, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr std::tuple<Vector<2,T>, Vector<2,T>, Vector<2,T>>
unpackSpace(const Matrix<3,3,T>& space)
{
    return std::make_tuple
    (
        x(space),
        y(space),
        position(space)
    );
}

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END