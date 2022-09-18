

#include "utils.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
x(const Matrix<S,S,T>& basis)
{
    return
#ifdef CGM_CFG_MATRIX_POSTMULT
    {
        basis(0,0),
        basis(1,0),
        basis(2,0)
    };
#else
    {
        basis(0,0),
        basis(0,1),
        basis(0,2)
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
    return oriented({T(1),T(0),T(0)}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
y(const Matrix<S,S,T>& basis)
{
    return
#ifdef CGM_CFG_MATRIX_POSTMULT
    {
        basis(0,1),
        basis(1,1),
        basis(2,1)
    };
#else
    {
        basis(1,0),
        basis(1,1),
        basis(1,2)
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
    return oriented({T(0),T(1),T(0)}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
z(const Matrix<S,S,T>& basis)
{
    return
#ifdef CGM_CFG_MATRIX_POSTMULT
    {
        basis(0,2),
        basis(1,2),
        basis(2,2)
    };
#else
    {
        basis(2,0),
        basis(2,1),
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
    return oriented({T(0),T(0),T(1)}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setX(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef CGM_CFG_MATRIX_POSTMULT
    basis(0,0) = value.x;
    basis(1,0) = value.y;
    basis(2,0) = value.z;
#else
    basis(0,0) = value.x;
    basis(0,1) = value.y;
    basis(0,2) = value.z;
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
#ifdef CGM_CFG_MATRIX_POSTMULT
    basis(0,1) = value.x;
    basis(1,1) = value.y;
    basis(2,1) = value.z;
#else
    basis(1,0) = value.x;
    basis(1,1) = value.y;
    basis(1,2) = value.z;
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
#ifdef CGM_CFG_MATRIX_POSTMULT
    basis(0,2) = value.x;
    basis(1,2) = value.y;
    basis(2,2) = value.z;
#else
    basis(2,0) = value.x;
    basis(2,1) = value.y;
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
#ifdef CGM_CFG_UP_IS_X
    return x(basis);
#endif
#ifdef CGM_CFG_UP_IS_Y
    return y(basis);
#endif
#ifdef CGM_CFG_UP_IS_Z
    return z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
up(const Quaternion<T>& orientation)
{
#ifdef CGM_CFG_UP_IS_X
    return x(orientation);
#endif
#ifdef CGM_CFG_UP_IS_Y
    return y(orientation);
#endif
#ifdef CGM_CFG_UP_IS_Z
    return z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
up(const Axes<T>& axes)
{
#ifdef CGM_CFG_UP_IS_X
    return x(axes);
#endif
#ifdef CGM_CFG_UP_IS_Y
    return y(axes);
#endif
#ifdef CGM_CFG_UP_IS_Z
    return z(axes);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
right(const Matrix<S,S,T>& basis)
{
#ifdef CGM_CFG_RIGHT_IS_X
    return x(basis);
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    return y(basis);
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    return z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
right(const Quaternion<T>& orientation)
{
#ifdef CGM_CFG_RIGHT_IS_X
    return x(orientation);
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    return y(orientation);
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    return z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
right(const Axes<T>& axes)
{
#ifdef CGM_CFG_RIGHT_IS_X
    return x(axes);
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    return y(axes);
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    return z(axes);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
forward(const Matrix<S,S,T>& basis)
{
#ifdef CGM_CFG_FORWARD_IS_X
    return x(basis);
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    return y(basis);
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    return z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
forward(const Quaternion<T>& orientation)
{
#ifdef CGM_CFG_FORWARD_IS_X
    return x(orientation);
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    return y(orientation);
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    return z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
forward(const Axes<T>& axes)
{
#ifdef CGM_CFG_FORWARD_IS_X
    return x(axes);
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    return y(axes);
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
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
#ifdef CGM_CFG_UP_IS_X
    setX(basis, value);
#endif
#ifdef CGM_CFG_UP_IS_Y
    setY(basis, value);
#endif
#ifdef CGM_CFG_UP_IS_Z
    setZ(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setUp(Axes<T>& axes, const Vector<3,T>& value)
{
#ifdef CGM_CFG_UP_IS_X
    setX(axes, value);
#endif
#ifdef CGM_CFG_UP_IS_Y
    setY(axes, value);
#endif
#ifdef CGM_CFG_UP_IS_Z
    setZ(axes, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setRight(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef CGM_CFG_RIGHT_IS_X
    setX(basis, value);
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    setY(basis, value);
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    setZ(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setRight(Axes<T>& axes, const Vector<3,T>& value)
{
#ifdef CGM_CFG_RIGHT_IS_X
    setX(axes, value);
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    setY(axes, value);
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    setZ(axes, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setForward(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef CGM_CFG_FORWARD_IS_X
    setX(basis, value);
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    setY(basis, value);
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    setZ(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setForward(Axes<T>& axes, const Vector<3,T>& value)
{
#ifdef CGM_CFG_FORWARD_IS_X
    setX(axes, value);
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    setY(axes, value);
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    setZ(axes, value);
#endif
}

/* ####################################################################################### */
/* Basis homogeneous components */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
homogeneous(Matrix<4,4,T>& matrix)
{
    return
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix(3,0),
        matrix(3,1),
        matrix(3,2),
    #else
        matrix(0,3),
        matrix(1,3),
        matrix(2,3),
    #endif
        matrix(3,3)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<4,T>
axesHomogeneous(Matrix<4,4,T>& matrix)
{
    return
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix(3,0),
        matrix(3,1),
        matrix(3,2)
    #else
        matrix(0,3),
        matrix(1,3),
        matrix(2,3)
    #endif
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setHomogeneous(Matrix<4,4,T>& matrix, const Vector<3,T>& values)
{
#ifdef CGM_CFG_MATRIX_POSTMULT
    matrix(3,0) = values.x;
    matrix(3,1) = values.y;
    matrix(3,2) = values.z;
#else
    matrix(0,3) = values.x;
    matrix(1,3) = values.y;
    matrix(2,3) = values.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setHomogeneous(Matrix<4,4,T>& matrix, const Vector<4,T>& values)
{
#ifdef CGM_CFG_MATRIX_POSTMULT
    matrix(3,0) = values.x;
    matrix(3,1) = values.y;
    matrix(3,2) = values.z;
#else
    matrix(0,3) = values.x;
    matrix(1,3) = values.y;
    matrix(2,3) = values.z;
#endif
    matrix(3,3) = values.w;
}

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
position(const Matrix<4,4,T>& basis)
{
    return
#ifdef CGM_CFG_MATRIX_POSTMULT
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
#ifdef CGM_CFG_MATRIX_POSTMULT
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
constexpr CGM_FORCEINLINE void
setOrientation(Matrix<4,4,T>& basis, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    setX(basis, x);
    setY(basis, y);
    setZ(basis, z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
setOrientation(Matrix<4,4,T>& basis, const Axes<T>& axes)
{
    setX(basis, axes.x);
    setY(basis, axes.y);
    setZ(basis, axes.z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
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
constexpr CGM_FORCEINLINE void
setOrientation(Matrix<4,4,T>& basis, const Quaternion<T>& orientation)
{
    setX(basis, x(orientation));
    setY(basis, y(orientation));
    setZ(basis, z(orientation));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
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
/* Setup all */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<3,3,T>& matrix, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    setX(matrix, x);
    setY(matrix, y);
    setZ(matrix, z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<3,3,T>& matrix, const Axes<T>& axes)
{
    setX(matrix, axes.x);
    setY(matrix, axes.y);
    setZ(matrix, axes.z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<4,4,T>& matrix, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
{
    setX(matrix, x);
    setY(matrix, y);
    setZ(matrix, z);
    setPosition(matrix, position);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<4,4,T>& matrix, const Vector<4,T>& x, const Vector<4,T>& y, const Vector<4,T>& z, const Vector<4,T>& position)
{
    setX(matrix, x);
    setY(matrix, y);
    setZ(matrix, z);
    setPosition(matrix, position);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<4,4,T>& matrix, const Axes<T>& axes, const Vector<3,T>& position)
{
    setX(matrix, axes.x);
    setY(matrix, axes.y);
    setZ(matrix, axes.z);
    setPosition(matrix, position);
}

/* ####################################################################################### */
/* Space matrix */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
spaceMatrix(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
{
#ifdef CGM_CFG_MATRIX_POSTMULT
    return
    {
        x.x, y.x, z.x, position.x,
        x.y, y.y, z.y, position.y,
        x.z, y.z, z.z, position.z,
        T(0), T(0), T(0), T(1)
    };
#else
    return
    {
        x.x, x.y, x.z, T(0),
        y.x, y.y, y.z, T(0),
        z.x, z.y, z.z, T(0),
        position.x, position.y, position.z, T(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
spaceMatrix(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
#ifdef CGM_CFG_MATRIX_POSTMULT
    return
    {
        orientation(0,0), orientation(0,1), orientation(0,2), position.x,
        orientation(1,0), orientation(1,1), orientation(1,2), position.y,
        orientation(2,0), orientation(2,1), orientation(2,2), position.z,
        T(0), T(0), T(0), T(1)
    };
#else
    return
    {
        orientation(0,0), orientation(0,1), orientation(0,2), T(0),
        orientation(1,0), orientation(1,1), orientation(1,2), T(0),
        orientation(2,0), orientation(2,1), orientation(2,2), T(0),
        position.x, position.y, position.z, T(1)
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
        oriented({T(1),T(0),T(0)}, orientation),
        oriented({T(0),T(1),T(0)}, orientation),
        oriented({T(0),T(0),T(1)}, orientation),
        position
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>, Vector<3,T>>
unpackSpace(const Matrix<4,4,T>& space)
{
    return std::make_tuple
    (
        x(space),
        y(space),
        z(space),
        position(space)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
lookAt(const Vector<3,T>& position, const Vector<3,T>& target, const Vector<3,T>& up)
{
#ifdef CGM_CFG_RHS
    const auto f = CGM::normalized(position - target);
    const auto r = CGM::normalized(CGM::cross(up, f));
    const auto u = CGM::normalized(CGM::cross(f, r));
#else
    const auto f = CGM::normalized(target - position);
    const auto r = CGM::normalized(CGM::cross(f, up));
    const auto u = CGM::normalized(CGM::cross(r, f));
#endif

    Matrix<4,4,T> mat {};
    mat(3,3) = T(1);

    setUp(mat, u);
    setRight(mat, r);
    setForward(mat, f);
    setPosition(mat, position);

    return mat;
}

/* ####################################################################################### */
/* Vector remapper */
/* ####################################################################################### */

template<E3D X, E3D Y, E3D Z, typename T>
constexpr Matrix<3,3,T>
remapper()
{
    auto x = Vector<3,T>(T(0));
    auto y = Vector<3,T>(T(0));
    auto z = Vector<3,T>(T(0));

    x.template get<X>() = T(1);
    y.template get<Y>() = T(1);
    z.template get<Z>() = T(1);

    Matrix<3,3,T> mat;
    set(mat, x, y, z);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<E4D X, E4D Y, E4D Z, E4D W, typename T>
constexpr Matrix<4,4,T>
remapper()
{
    Matrix<4,4,T> mat;

    auto x = Vector<4,T>(T(0));
    auto y = Vector<4,T>(T(0));
    auto z = Vector<4,T>(T(0));
    auto w = Vector<4,T>(T(0));

    x.template get<X>() = T(1);
    y.template get<Y>() = T(1);
    z.template get<Z>() = T(1);
    w.template get<W>() = T(1);

#ifdef CGM_CFG_MATRIX_POSTMULT
    mat.setColumn(0,x);
    mat.setColumn(1,y);
    mat.setColumn(2,z);
    mat.setColumn(3,w);
#else
    mat.setRow(0,x);
    mat.setRow(1,y);
    mat.setRow(2,z);
    mat.setRow(3,w);
#endif

    return mat;
}

/* ####################################################################################### */
/* 4x4 orientation manipulations */
/* ####################################################################################### */

template<typename T>
constexpr void
transposeOrientation(Matrix<4,4,T>& basis)
{
    std::swap(basis(0,1), basis(1,0));
    std::swap(basis(0,2), basis(2,0));
    std::swap(basis(1,2), basis(2,1));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
transposedOrientation(const Matrix<4,4,T>& basis)
{
    auto copy = basis;
    transposeOrientation(copy);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
invertOrientationSafe(Matrix<4,4,T>& basis, T determinantTolerance)
{
    Matrix<3,3,T> orient
    {
        basis(0,0), basis(0,1), basis(0,2),
        basis(1,0), basis(1,1), basis(1,2),
        basis(2,0), basis(2,1), basis(2,2)
    };

    if (invertSafe(orient, determinantTolerance))
    {
        basis(0,0) = orient(0,0);
        basis(0,1) = orient(0,1);
        basis(0,2) = orient(0,2);
        basis(1,0) = orient(1,0);
        basis(1,1) = orient(1,1);
        basis(1,2) = orient(1,2);
        basis(2,0) = orient(2,0);
        basis(2,1) = orient(2,1);
        basis(2,2) = orient(2,2);

        return true;
    }
    else
    {
        return false;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
inverseOrientationSafe(const Matrix<4,4,T>& basis, bool& success, T determinantTolerance)
{
    Matrix<3,3,T> orient
    {
        basis(0,0), basis(0,1), basis(0,2),
        basis(1,0), basis(1,1), basis(1,2),
        basis(2,0), basis(2,1), basis(2,2)
    };

    success = invertSafe(orient, determinantTolerance);

    if (success)
    {
        Matrix<4,4,T> mat;

        mat(0,0) = orient(0,0);
        mat(0,1) = orient(0,1);
        mat(0,2) = orient(0,2);
        mat(1,0) = orient(1,0);
        mat(1,1) = orient(1,1);
        mat(1,2) = orient(1,2);
        mat(2,0) = orient(2,0);
        mat(2,1) = orient(2,1);
        mat(2,2) = orient(2,2);

        mat(3,0) = basis(3,0);
        mat(3,1) = basis(3,1);
        mat(3,2) = basis(3,2);
        mat(0,3) = basis(0,3);
        mat(1,3) = basis(1,3);
        mat(2,3) = basis(2,3);
        mat(3,3) = basis(3,3);

        return mat;
    }
    else
    {
        return basis;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
invertOrientation(Matrix<4,4,T>& basis)
{
    Matrix<3,3,T> orient
    {
        basis(0,0), basis(0,1), basis(0,2),
        basis(1,0), basis(1,1), basis(1,2),
        basis(2,0), basis(2,1), basis(2,2)
    };

    invert(orient);

    basis(0,0) = orient(0,0);
    basis(0,1) = orient(0,1);
    basis(0,2) = orient(0,2);
    basis(1,0) = orient(1,0);
    basis(1,1) = orient(1,1);
    basis(1,2) = orient(1,2);
    basis(2,0) = orient(2,0);
    basis(2,1) = orient(2,1);
    basis(2,2) = orient(2,2);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
inverseOrientation(const Matrix<4,4,T>& basis)
{
    Matrix<3,3,T> orient
    {
        basis(0,0), basis(0,1), basis(0,2),
        basis(1,0), basis(1,1), basis(1,2),
        basis(2,0), basis(2,1), basis(2,2)
    };

    invert(orient);

    Matrix<4,4,T> mat;

    mat(0,0) = orient(0,0);
    mat(0,1) = orient(0,1);
    mat(0,2) = orient(0,2);
    mat(1,0) = orient(1,0);
    mat(1,1) = orient(1,1);
    mat(1,2) = orient(1,2);
    mat(2,0) = orient(2,0);
    mat(2,1) = orient(2,1);
    mat(2,2) = orient(2,2);

    mat(3,0) = basis(3,0);
    mat(3,1) = basis(3,1);
    mat(3,2) = basis(3,2);
    mat(0,3) = basis(0,3);
    mat(1,3) = basis(1,3);
    mat(2,3) = basis(2,3);
    mat(3,3) = basis(3,3);

    return mat;
}

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
multiply(const Vector<3,T>& vector, const Matrix<4,4,T>& matrix)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return
        {
            matrix(0,0) * vector.x + matrix(1,0) * vector.y + matrix(2,0) * vector.z + matrix(3,0),
            matrix(0,1) * vector.x + matrix(1,1) * vector.y + matrix(2,1) * vector.z + matrix(3,1),
            matrix(0,2) * vector.x + matrix(1,2) * vector.y + matrix(2,2) * vector.z + matrix(3,2)
        };
    }
    else
    {
        return
        {
            matrix(0,0) * vector.x + matrix(1,0) * vector.y + matrix(2,0) * vector.z,
            matrix(0,1) * vector.x + matrix(1,1) * vector.y + matrix(2,1) * vector.z,
            matrix(0,2) * vector.x + matrix(1,2) * vector.y + matrix(2,2) * vector.z
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
multiply(const Matrix<4,4,T>& matrix, const Vector<3,T>& vector)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return
        {
            matrix(0,0) * vector.x + matrix(0,1) * vector.y + matrix(0,2) * vector.z + matrix(0,3),
            matrix(1,0) * vector.x + matrix(1,1) * vector.y + matrix(1,2) * vector.z + matrix(1,3),
            matrix(2,0) * vector.x + matrix(2,1) * vector.y + matrix(2,2) * vector.z + matrix(2,3)
        };
    }
    else
    {
        return
        {
            matrix(0,0) * vector.x + matrix(0,1) * vector.y + matrix(0,2) * vector.z,
            matrix(1,0) * vector.x + matrix(1,1) * vector.y + matrix(1,2) * vector.z,
            matrix(2,0) * vector.x + matrix(2,1) * vector.y + matrix(2,2) * vector.z
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr std::enable_if_t<(N == 3 || N == 4), Matrix<N,N,T>>
multiply(const Matrix<3,3,T>& A, const Matrix<4,4,T>& B)
{
    if constexpr (N == 3)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2)
        };
    }
    else
    {
        return Matrix<N,N,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3),

            // row 3
            B(3,0),
            B(3,1),
            B(3,2),
            B(3,3)
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr std::enable_if_t<(N == 3 || N == 4), Matrix<N,N,T>>
multiply(const Matrix<4,4,T>& A, const Matrix<3,3,T>& B)
{
    if constexpr (N == 3)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2)
        };
    }
    else
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),
            A(0,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),
            A(1,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2),
            A(2,3),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2),
            A(3,3)
        };
    }
}

CGM_NAMESPACE_END