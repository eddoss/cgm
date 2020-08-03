

#include <Math3D/Cartesian/2D/Functions/Utils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
x(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
constexpr FORCEINLINE Vector<2,T>
x(const AxesTuple<T>& axes)
{
    return std::get<0>(axes);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
x(const SpaceTuple<T>& axes)
{
    return std::get<0>(axes);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
y(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
constexpr FORCEINLINE Vector<2,T>
y(const AxesTuple<T>& axes)
{
    return std::get<1>(axes);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
y(const SpaceTuple<T>& axes)
{
    return std::get<1>(axes);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setX(Matrix<S,S,T>& basis, const Vector<2,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,0) = value.x;
    basis(0,1) = value.y;
#else
    basis(0,0) = value.x;
    basis(1,0) = value.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setX(AxesTuple<T>& axes, const Vector<2,T>& value)
{
    std::get<0>(axes) = value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setX(SpaceTuple<T>& space, const Vector<2,T>& value)
{
    std::get<0>(space) = value;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setY(Matrix<S,S,T>& basis, const Vector<2,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(1,0) = value.x;
    basis(1,1) = value.y;
#else
    basis(0,1) = value.x;
    basis(1,1) = value.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setY(AxesTuple<T>& axes, const Vector<2,T>& value)
{
    std::get<1>(axes) = value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setY(SpaceTuple<T>& space, const Vector<2,T>& value)
{
    std::get<1>(space) = value;
}

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
position(const Matrix<3,3,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
constexpr FORCEINLINE Vector<2,T>
position(const SpaceTuple<T>& space)
{
    return std::get<3>(space);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setPosition(Matrix<3,3,T>& basis, const Vector<2,T>& position)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,2) = position.x;
    basis(1,2) = position.y;
#else
    basis(2,0) = position.x;
    basis(2,1) = position.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setPosition(SpaceTuple<T>& space, const Vector<2,T>& position)
{
    std::get<3>(space) = position;
}

/* ####################################################################################### */
/* Orientation */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
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
setOrientation(Matrix<3,3,T>& basis, const AxesTuple<T>& axes)
{
    setX(basis, x(axes));
    setY(basis, y(axes));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& basis, const SpaceTuple<T>& space)
{
    setX(basis, x(space));
    setY(basis, y(space));
}

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END