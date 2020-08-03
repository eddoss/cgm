

#include <Math3D/Cartesian/3D/Functions/Utils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
x(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
constexpr FORCEINLINE Vector<3,T>
x(const AxesTuple<T>& axes)
{
    return std::get<0>(axes);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
x(const SpaceTuple<T>& axes)
{
    return std::get<0>(axes);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
x(const Quaternion<T>& orientation)
{
    return oriented({T(1),T(0),T(0)}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
y(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
constexpr FORCEINLINE Vector<3,T>
y(const AxesTuple<T>& axes)
{
    return std::get<1>(axes);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
y(const SpaceTuple<T>& axes)
{
    return std::get<1>(axes);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
y(const Quaternion<T>& orientation)
{
    return oriented({T(0),T(1),T(0)}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
z(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
constexpr FORCEINLINE Vector<3,T>
z(const AxesTuple<T>& axes)
{
    return std::get<2>(axes);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
z(const SpaceTuple<T>& axes)
{
    return std::get<2>(axes);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
z(const Quaternion<T>& orientation)
{
    return oriented({T(0),T(0),T(1)}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setX(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
constexpr FORCEINLINE void
setX(AxesTuple<T>& axes, const Vector<3,T>& value)
{
    std::get<0>(axes) = value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setX(SpaceTuple<T>& space, const Vector<3,T>& value)
{
    std::get<0>(space) = value;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setY(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
constexpr FORCEINLINE void
setY(AxesTuple<T>& axes, const Vector<3,T>& value)
{
    std::get<1>(axes) = value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setY(SpaceTuple<T>& space, const Vector<3,T>& value)
{
    std::get<1>(space) = value;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setZ(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
constexpr FORCEINLINE void
setZ(AxesTuple<T>& axes, const Vector<3,T>& value)
{
    std::get<2>(axes) = value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setZ(SpaceTuple<T>& space, const Vector<3,T>& value)
{
    std::get<2>(space) = value;
}

/* ####################################################################################### */
/* Uo, Right, Forward axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
up(const Matrix<S,S,T>& basis)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return x(basis);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return y(basis);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
up(const Quaternion<T>& orientation)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return x(orientation);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return y(orientation);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
up(const AxesTuple<T>& axes)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return x(axes);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return y(axes);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return z(axes);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
up(const SpaceTuple<T>& space)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return x(space);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return y(space);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return z(space);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
right(const Matrix<S,S,T>& basis)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return x(basis);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return y(basis);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
right(const Quaternion<T>& orientation)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return x(orientation);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return y(orientation);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
right(const AxesTuple<T>& axes)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return x(axes);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return y(axes);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return z(axes);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
right(const SpaceTuple<T>& space)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return x(space);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return y(space);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return z(space);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
forward(const Matrix<S,S,T>& basis)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return x(basis);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return y(basis);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
forward(const Quaternion<T>& orientation)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return x(orientation);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return y(orientation);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
forward(const AxesTuple<T>& axes)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return x(axes);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return y(axes);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return z(axes);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
forward(const SpaceTuple<T>& space)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return x(space);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return y(space);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return z(space);
#endif
}

/* ####################################################################################### */
/* Down, Left, backward axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
down(const Matrix<S,S,T>& basis)
{
    return -up(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
down(const Quaternion<T>& orientation)
{
    return -up(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
down(const AxesTuple<T>& axes)
{
    return -up(axes);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
down(const SpaceTuple<T>& space)
{
    return -up(space);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
left(const Matrix<S,S,T>& basis)
{
    return -right(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
left(const Quaternion<T>& orientation)
{
    return -right(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
left(const AxesTuple<T>& axes)
{
    return -right(axes);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
left(const SpaceTuple<T>& space)
{
    return -right(space);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
backward(const Matrix<S,S,T>& basis)
{
    return -forward(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
backward(const Quaternion<T>& orientation)
{
    return -forward(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
backward(const AxesTuple<T>& axes)
{
    return -forward(axes);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
backward(const SpaceTuple<T>& space)
{
    return -forward(space);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setUp(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return setX(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return setY(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return setZ(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
setUp(AxesTuple<T>& axes, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return setX(axes, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return setY(axes, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return setZ(axes, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
setUp(SpaceTuple<T>& space, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return setX(space, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return setY(space, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return setZ(space, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setRight(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return setX(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return setY(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return setZ(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
setRight(AxesTuple<T>& axes, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return setX(axes, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return setY(axes, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return setZ(axes, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
setRight(SpaceTuple<T>& space, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return setX(space, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return setY(space, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return setZ(space, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setForward(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return setX(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return setY(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return setZ(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
setForward(AxesTuple<T>& axes, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return setX(axes, value);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return setY(axes, value);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return setZ(axes, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
setForward(SpaceTuple<T>& space, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return setX(space, value);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return setY(space, value);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return setZ(space, value);
#endif
}

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
position(const Matrix<4,4,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
constexpr FORCEINLINE Vector<3,T>
position(const SpaceTuple<T>& space)
{
    return std::get<3>(space);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setPosition(Matrix<4,4,T>& basis, const Vector<3,T>& position)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,3) = position.x;
    basis(1,3) = position.y;
    basis(2,3) = position.z;
#else
    basis(3,0) = position.x;
    basis(3,1) = position.y;
    basis(3,2) = position.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setPosition(SpaceTuple<T>& space, const Vector<3,T>& position)
{
    std::get<3>(space) = position;
}

/* ####################################################################################### */
/* Orientation */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const AxesTuple<T>& axes)
{
    setX(basis, x(axes));
    setY(basis, y(axes));
    setZ(basis, z(axes));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const SpaceTuple<T>& space)
{
    setX(basis, x(space));
    setY(basis, y(space));
    setZ(basis, z(space));
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END