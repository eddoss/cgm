

#include <CGM/Modules/Cartesian/3D/Functions/Utils.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
x(const Matrix<S,S,T>& basis)
{
    return
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,0),
        basis(0,1),
        basis(0,2),
    };
#else
    {
        basis(0,0),
        basis(1,0),
        basis(2,0),
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
x(const Axes<T>& axes)
{
    return axes.x;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
x(const Quaternion<T>& orientation)
{
    return oriented({number<T>(1),zero<T>,zero<T>}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
y(const Matrix<S,S,T>& basis)
{
    return
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(1,0),
        basis(1,1),
        basis(1,2)
    };
#else
    {
        basis(0,1),
        basis(1,1),
        basis(2,1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
y(const Axes<T>& axes)
{
    return axes.y;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
y(const Quaternion<T>& orientation)
{
    return oriented({zero<T>,number<T>(1),zero<T>}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
z(const Matrix<S,S,T>& basis)
{
    return
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(2,0),
        basis(2,1),
        basis(2,2)
    };
#else
    {
        basis(0,2),
        basis(1,2),
        basis(2,2)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
z(const Axes<T>& axes)
{
    return axes.z;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
z(const Quaternion<T>& orientation)
{
    return oriented({zero<T>,zero<T>,number<T>(1)}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setX(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,0) = value.x;
    basis(0,1) = value.y;
    basis(0,2) = value.z;
#else
    basis(0,0) = value.x;
    basis(1,0) = value.y;
    basis(2,0) = value.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setX(Axes<T>& axes, const Vector<3,T>& value)
{
    axes.x = value;
}
/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setY(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(1,0) = value.x;
    basis(1,1) = value.y;
    basis(1,2) = value.z;
#else
    basis(0,1) = value.x;
    basis(1,1) = value.y;
    basis(2,1) = value.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setY(Axes<T>& axes, const Vector<3,T>& value)
{
    axes.y = value;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setZ(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(2,0) = value.x;
    basis(2,1) = value.y;
    basis(2,2) = value.z;
#else
    basis(0,2) = value.x;
    basis(1,2) = value.y;
    basis(2,2) = value.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setZ(Axes<T>& axes, const Vector<3,T>& value)
{
    axes.z = value;
}

/* ####################################################################################### */
/* Uo, Right, Forward axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
up(const Matrix<S,S,T>& basis)
{
#ifdef CGM_CARTESIAN_UP_X
    return x(basis);
#endif
#ifdef CGM_CARTESIAN_UP_Y
    return y(basis);
#endif
#ifdef CGM_CARTESIAN_UP_Z
    return z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
up(const Quaternion<T>& orientation)
{
#ifdef CGM_CARTESIAN_UP_X
    return x(orientation);
#endif
#ifdef CGM_CARTESIAN_UP_Y
    return y(orientation);
#endif
#ifdef CGM_CARTESIAN_UP_Z
    return z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
up(const Axes<T>& axes)
{
#ifdef CGM_CARTESIAN_UP_X
    return x(axes);
#endif
#ifdef CGM_CARTESIAN_UP_Y
    return y(axes);
#endif
#ifdef CGM_CARTESIAN_UP_Z
    return z(axes);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
right(const Matrix<S,S,T>& basis)
{
#ifdef CGM_CARTESIAN_RIGHT_X
    return x(basis);
#endif
#ifdef CGM_CARTESIAN_RIGHT_Y
    return y(basis);
#endif
#ifdef CGM_CARTESIAN_RIGHT_Z
    return z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
right(const Quaternion<T>& orientation)
{
#ifdef CGM_CARTESIAN_RIGHT_X
    return x(orientation);
#endif
#ifdef CGM_CARTESIAN_RIGHT_Y
    return y(orientation);
#endif
#ifdef CGM_CARTESIAN_RIGHT_Z
    return z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
right(const Axes<T>& axes)
{
#ifdef CGM_CARTESIAN_RIGHT_X
    return x(axes);
#endif
#ifdef CGM_CARTESIAN_RIGHT_Y
    return y(axes);
#endif
#ifdef CGM_CARTESIAN_RIGHT_Z
    return z(axes);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
forward(const Matrix<S,S,T>& basis)
{
#ifdef CGM_CARTESIAN_FORWARD_X
    return x(basis);
#endif
#ifdef CGM_CARTESIAN_FORWARD_Y
    return y(basis);
#endif
#ifdef CGM_CARTESIAN_FORWARD_Z
    return z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
forward(const Quaternion<T>& orientation)
{
#ifdef CGM_CARTESIAN_FORWARD_X
    return x(orientation);
#endif
#ifdef CGM_CARTESIAN_FORWARD_Y
    return y(orientation);
#endif
#ifdef CGM_CARTESIAN_FORWARD_Z
    return z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
forward(const Axes<T>& axes)
{
#ifdef CGM_CARTESIAN_FORWARD_X
    return x(axes);
#endif
#ifdef CGM_CARTESIAN_FORWARD_Y
    return y(axes);
#endif
#ifdef CGM_CARTESIAN_FORWARD_Z
    return z(axes);
#endif
}

/* ####################################################################################### */
/* Down, Left, backward axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
down(const Matrix<S,S,T>& basis)
{
    return -up(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
down(const Quaternion<T>& orientation)
{
    return -up(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
down(const Axes<T>& axes)
{
    return -up(axes);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
left(const Matrix<S,S,T>& basis)
{
    return -right(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
left(const Quaternion<T>& orientation)
{
    return -right(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
left(const Axes<T>& axes)
{
    return -right(axes);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
backward(const Matrix<S,S,T>& basis)
{
    return -forward(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
backward(const Quaternion<T>& orientation)
{
    return -forward(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
backward(const Axes<T>& axes)
{
    return -forward(axes);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setUp(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef CGM_CARTESIAN_UP_X
    return setX(basis, value);
#endif
#ifdef CGM_CARTESIAN_UP_Y
    return setY(basis, value);
#endif
#ifdef CGM_CARTESIAN_UP_Z
    return setZ(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
setUp(Axes<T>& axes, const Vector<3,T>& value)
{
#ifdef CGM_CARTESIAN_UP_X
    return setX(axes, value);
#endif
#ifdef CGM_CARTESIAN_UP_Y
    return setY(axes, value);
#endif
#ifdef CGM_CARTESIAN_UP_Z
    return setZ(axes, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setRight(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef CGM_CARTESIAN_RIGHT_X
    return setX(basis, value);
#endif
#ifdef CGM_CARTESIAN_RIGHT_Y
    return setY(basis, value);
#endif
#ifdef CGM_CARTESIAN_RIGHT_Z
    return setZ(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
setRight(Axes<T>& axes, const Vector<3,T>& value)
{
#ifdef CGM_CARTESIAN_RIGHT_X
    return setX(axes, value);
#endif
#ifdef CGM_CARTESIAN_RIGHT_Y
    return setY(axes, value);
#endif
#ifdef CGM_CARTESIAN_RIGHT_Z
    return setZ(axes, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setForward(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef CGM_CARTESIAN_FORWARD_X
    return setX(basis, value);
#endif
#ifdef CGM_CARTESIAN_FORWARD_Y
    return setY(basis, value);
#endif
#ifdef CGM_CARTESIAN_FORWARD_Z
    return setZ(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
setForward(Axes<T>& axes, const Vector<3,T>& value)
{
#ifdef CGM_CARTESIAN_FORWARD_X
    return setX(axes, value);
#endif
#ifdef CGM_CARTESIAN_FORWARD_Y
    return setY(axes, value);
#endif
#ifdef CGM_CARTESIAN_FORWARD_Z
    return setZ(axes, value);
#endif
}

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
position(const Matrix<4,4,T>& basis)
{
    return
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,3),
        basis(1,3),
        basis(2,3)
    };
#else
    {
        basis(3,0),
        basis(3,1),
        basis(3,2)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setPosition(Matrix<4,4,T>& basis, const Vector<3,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,3) = position.x;
    basis(1,3) = position.y;
    basis(2,3) = position.z;
#else
    basis(3,0) = position.x;
    basis(3,1) = position.y;
    basis(3,2) = position.z;
#endif
}

/* ####################################################################################### */
/* Orientation */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
orientation(const Matrix<4,4,T>& basis)
{
    return
    {
        basis(0,0), basis(0,1), basis(0,2),
        basis(1,0), basis(1,1), basis(1,2),
        basis(2,0), basis(2,1), basis(2,2)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    setX(basis, x);
    setY(basis, y);
    setZ(basis, z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Matrix<3,3,T>& orientation)
{
    basis(0,0) = orientation(0,0);
    basis(0,1) = orientation(0,1);
    basis(0,2) = orientation(0,2);
    basis(1,0) = orientation(1,0);
    basis(1,1) = orientation(1,1);
    basis(1,2) = orientation(1,2);
    basis(2,0) = orientation(2,0);
    basis(2,1) = orientation(2,1);
    basis(2,2) = orientation(2,2);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Quaternion<T>& orientation)
{
    setX(basis, x(orientation));
    setY(basis, y(orientation));
    setZ(basis, z(orientation));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Matrix<4,4,T>& other)
{
    basis(0,0) = other(0,0);
    basis(0,1) = other(0,1);
    basis(0,2) = other(0,2);
    basis(1,0) = other(1,0);
    basis(1,1) = other(1,1);
    basis(1,2) = other(1,2);
    basis(2,0) = other(2,0);
    basis(2,1) = other(2,1);
    basis(2,2) = other(2,2);
}

/* ####################################################################################### */
/* Space matrix */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
spaceMatrix(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        x.x, x.y, x.z, position.x,
        y.x, y.y, y.z, position.y,
        z.x, z.y, z.z, position.z,
        zero<T>, zero<T>, zero<T>, number<T>(1)
    };
#else
    return
    {
        x.x, y.x, z.x, zero<T>,
        x.y, y.y, z.y, zero<T>,
        x.z, y.z, z.z, zero<T>,
        position.x, position.y, position.z, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
spaceMatrix(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        orientation(0,0), orientation(0,1), orientation(0,2), position.x,
        orientation(1,0), orientation(1,1), orientation(1,2), position.y,
        orientation(2,0), orientation(2,1), orientation(2,2), position.z,
        zero<T>, zero<T>, zero<T>, number<T>(1)
    };
#else
    return
    {
        orientation(0,0), orientation(0,1), orientation(0,2), zero<T>,
        orientation(1,0), orientation(1,1), orientation(1,2), zero<T>,
        orientation(2,0), orientation(2,1), orientation(2,2), zero<T>,
        position.x, position.y, position.z, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
spaceMatrix(const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    return spaceMatrix
    (
        oriented({number<T>(1),zero<T>,zero<T>}, orientation),
        oriented({zero<T>,number<T>(1),zero<T>}, orientation),
        oriented({zero<T>,zero<T>,number<T>(1)}, orientation),
        position
    );
}

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END