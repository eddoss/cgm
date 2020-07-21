

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
x(const Quaternion<T>& orientation)
{
    return oriented({T(1),T(0),T(0)}, Quaternion<T>{orientation.vector, -orientation.scalar});
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
y(const Quaternion<T>& orientation)
{
    return oriented({T(0),T(1),T(0)}, Quaternion<T>{orientation.vector, -orientation.scalar});
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
z(const Quaternion<T>& orientation)
{
    return oriented({T(0),T(0),T(1)}, Quaternion<T>{orientation.vector, -orientation.scalar});
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
    auto quat = orientation;
    quat.scalar = -quat.scalar;

    setX(basis, oriented({T(1), T(0), T(0)}, quat));
    setY(basis, oriented({T(0), T(1), T(0)}, quat));
    setZ(basis, oriented({T(0), T(0), T(1)}, quat));
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

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END