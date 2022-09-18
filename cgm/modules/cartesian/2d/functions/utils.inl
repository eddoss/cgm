

#include "utils.hpp"


CGM_2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
x(const Matrix<S,S,T>& basis)
{
    return
#ifdef CGM_CFG_MATRIX_POSTMULT
    {
        basis(0,0),
        basis(1,0)
    };
#else
    {
        basis(0,0),
        basis(0,1)
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
#ifdef CGM_CFG_MATRIX_POSTMULT
    {
        basis(0,1),
        basis(1,1)
    };
#else
    {
        basis(1,0),
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
#ifdef CGM_CFG_MATRIX_POSTMULT
    basis(0,0) = value.x;
    basis(1,0) = value.y;
#else
    basis(0,0) = value.x;
    basis(0,1) = value.y;
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
#ifdef CGM_CFG_MATRIX_POSTMULT
    basis(0,1) = value.x;
    basis(1,1) = value.y;
#else
    basis(1,0) = value.x;
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
#ifdef CGM_CFG_MATRIX_POSTMULT
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
#ifdef CGM_CFG_MATRIX_POSTMULT
    basis(0,2) = position.x;
    basis(1,2) = position.y;
#else
    basis(2,0) = position.x;
    basis(2,1) = position.y;
#endif
}

/* ####################################################################################### */
/* Setup all */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<2,2,T>& matrix, const Vector<2,T>& x, const Vector<2,T>& y)
{
    setX(matrix, x);
    setY(matrix, y);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<2,2,T>& matrix, const Axes<T>& axes)
{
    setX(matrix, axes.x);
    setY(matrix, axes.y);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<3,3,T>& matrix, const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position)
{
    setX(matrix, x);
    setY(matrix, y);
    setPosition(matrix, position);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<3,3,T>& matrix, const Axes<T>& axes, const Vector<2,T>& position)
{
    setX(matrix, axes.x);
    setY(matrix, axes.y);
    setPosition(matrix, position);
}

/* ####################################################################################### */
/* Orientation */
/* ####################################################################################### */

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
#ifdef CGM_CFG_MATRIX_POSTMULT
    return
    {
        x.x, y.x, position.x,
        x.y, y.y, position.y,
        T(0),  T(0), T(1)
    };
#else
    return
    {
        x.x, x.y, T(0),
        y.x, y.y, T(0),
        position.x, position.y, T(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
spaceMatrix(const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
#ifdef CGM_CFG_MATRIX_POSTMULT
    return
    {
        orientation(0,0), orientation(0,1), position.x,
        orientation(1,0), orientation(1,1), position.y,
        T(0), T(0), T(1)
    };
#else
    return
    {
        orientation(0,0), orientation(0,1), T(0),
        orientation(1,0), orientation(1,1), T(0),
        position.x, position.y, T(1)
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

/* ####################################################################################### */
/* 4x4 orientation manipulations */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
transposeOrientation(Matrix<3,3,T>& basis)
{
    std::swap(basis(0,1), basis(1,0));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
transposedOrientation(const Matrix<3,3,T>& basis)
{
    auto copy = basis;
    transposeOrientation(copy);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr enable_if_floating<T, bool>
invertOrientationSafe(Matrix<3,3,T>& basis, T determinantTolerance)
{
    Matrix<2,2,T> orient
    {
        basis(0,0), basis(0,1),
        basis(1,0), basis(1,1)
    };

    if (invertSafe(orient, determinantTolerance))
    {
        basis(0,0) = orient(0,0);
        basis(0,1) = orient(0,1);
        basis(1,0) = orient(1,0);
        basis(1,1) = orient(1,1);

        return true;
    }
    else
    {
        return false;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr enable_if_floating<T, Matrix<3,3,T>>
inverseOrientationSafe(const Matrix<3,3,T>& basis, bool& success, T determinantTolerance)
{
    Matrix<2,2,T> orient
    {
        basis(0,0), basis(0,1),
        basis(1,0), basis(1,1)
    };

    success = invertSafe(orient, determinantTolerance);

    if (success)
    {
        Matrix<3,3,T> mat;

        mat(0,0) = orient(0,0);
        mat(0,1) = orient(0,1);
        mat(1,0) = orient(1,0);
        mat(1,1) = orient(1,1);

        mat(2,0) = basis(2,0);
        mat(2,1) = basis(2,1);
        mat(0,2) = basis(0,2);
        mat(1,2) = basis(1,2);
        mat(2,2) = basis(2,2);

        return mat;
    }
    else
    {
        return basis;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr enable_if_floating<T, void>
invertOrientation(Matrix<3,3,T>& basis)
{
    Matrix<2,2,T> orient
    {
        basis(0,0), basis(0,1),
        basis(1,0), basis(1,1)
    };

    invert(orient);

    basis(2,0) = orient(2,0);
    basis(2,1) = orient(2,1);
    basis(0,2) = orient(0,2);
    basis(1,2) = orient(1,2);
    basis(2,2) = orient(2,2);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr enable_if_floating<T, Matrix<3,3,T>>
inverseOrientation(const Matrix<3,3,T>& basis)
{
    Matrix<2,2,T> orient
    {
        basis(0,0), basis(0,1),
        basis(1,0), basis(1,1)
    };

    invert(orient);

    Matrix<3,3,T> mat;

    mat(0,0) = orient(0,0);
    mat(0,1) = orient(0,1);
    mat(1,0) = orient(1,0);
    mat(1,1) = orient(1,1);

    mat(2,0) = basis(2,0);
    mat(2,1) = basis(2,1);
    mat(0,2) = basis(0,2);
    mat(1,2) = basis(1,2);
    mat(2,2) = basis(2,2);

    return mat;
}

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
multiply(const Vector<2,T>& vector, const Matrix<3,3,T>& matrix)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return
        {
            matrix(0,0) * vector.x + matrix(1,0) * vector.y + matrix(2,0),
            matrix(0,1) * vector.x + matrix(1,1) * vector.y + matrix(2,1)
        };
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return
        {
            matrix(0,0) * vector.x + matrix(1,0) * vector.y,
            matrix(0,1) * vector.x + matrix(1,1) * vector.y
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
multiply(const Matrix<3,3,T>& matrix, const Vector<2,T>& vector)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return
        {
            matrix(0,0) * vector.x + matrix(0,1) * vector.y + matrix(0,2),
            matrix(1,0) * vector.x + matrix(1,1) * vector.y + matrix(1,2)
        };
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return
        {
            matrix(0,0) * vector.x + matrix(0,1) * vector.y,
            matrix(1,0) * vector.x + matrix(1,1) * vector.y
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr std::enable_if_t<(N == 2 || N == 3), Matrix<N,N,T>>
multiply(const Matrix<2,2,T>& A, const Matrix<3,3,T>& B)
{
    if constexpr (N == 2)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
        };
    }
    else
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2),

            // row 2
            B(2,0),
            B(2,1),
            B(2,2)
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr std::enable_if_t<(N == 2 || N == 3), Matrix<N,N,T>>
multiply(const Matrix<3,3,T>& A, const Matrix<2,2,T>& B)
{
    if constexpr (N == 2)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
        };
    }
    else
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1),
            A(2,2)
        };
    }
}

CGM_2D_NAMESPACE_END