

#include <CGM/detail/Cartesian/3D/Functions/Utils.hpp>


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
set(Matrix<4,4,T>& matrix, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& position)
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
invertOrientation(Matrix<4,4,T>& basis, T determinantTolerance)
{
    Matrix<3,3,T> orient
    {
        basis(0,0), basis(0,1), basis(0,2),
        basis(1,0), basis(1,1), basis(1,2),
        basis(2,0), basis(2,1), basis(2,2)
    };

    if (invert(orient, determinantTolerance))
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
inverseOrientation(const Matrix<4,4,T>& basis, bool& success, T determinantTolerance)
{
    Matrix<3,3,T> orient
    {
        basis(0,0), basis(0,1), basis(0,2),
        basis(1,0), basis(1,1), basis(1,2),
        basis(2,0), basis(2,1), basis(2,2)
    };

    success = invert(orient, determinantTolerance);

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
invertOrientationForce(Matrix<4,4,T>& basis)
{
    Matrix<3,3,T> orient
    {
        basis(0,0), basis(0,1), basis(0,2),
        basis(1,0), basis(1,1), basis(1,2),
        basis(2,0), basis(2,1), basis(2,2)
    };

    invertForce(orient);

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
inverseOrientationForce(const Matrix<4,4,T>& basis)
{
    Matrix<3,3,T> orient
    {
        basis(0,0), basis(0,1), basis(0,2),
        basis(1,0), basis(1,1), basis(1,2),
        basis(2,0), basis(2,1), basis(2,2)
    };

    invertForce(orient);

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

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END