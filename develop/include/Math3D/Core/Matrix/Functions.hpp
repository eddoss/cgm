#ifndef MATH3D_MATRIX_FUNCTIONS_HPP
#define MATH3D_MATRIX_FUNCTIONS_HPP


#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Matrix/Operators.hpp>


MATH3D_NAMESPACE_BEGIN

/**
 * Get the transpose square matrix.
 * @param matrix Matrix to transpose.
 * @return The transposed matrix.
 */
template<size_t S, typename T>
constexpr Matrix<S,S,T>&
transpose(Matrix<S,S,T>& matrix);

/**
 * Get transposed copy of the non-square matrix.
 * @param matrix Matrix to transpose.
 * @return The transposed matrix.
 */
template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::Transposed
transposed(const Matrix<M,N,T>& matrix);

/**
 * Calculate determinant of square matrix.
 * @param matrix Matrix to calculate.
 * @return calculated determinant.
 */
template<size_t S, typename T>
constexpr T
determinant(const Matrix<S,S,T>& matrix);

/**
 * Calculate cofactors of square matrix.
 * @param matrix Matrix to calculate.
 * @return calculated cofactors.
 */
template<size_t S, typename T>
constexpr Matrix<S,S,T>
cofactors(const Matrix<S,S,T>& matrix);

/**
 * Calculate inverse matrix. Change flag to false, if cant calculate.
 * @param[in] matrix Matrix to calculate.
 * @param[out] success Set this false if cant calculate inverted matrix.
 * @return inverted matrix if could calculate, trash otherwise.
 */
template<typename TResult=FLOAT, size_t S, typename T>
constexpr Matrix<S,S,TResult>
inverted(const Matrix<S,S,T>& matrix, bool& success);

/**
 * Create identity matrix.
 * @return Identity matrix.
 */
template<size_t S, typename T=FLOAT>
constexpr Matrix<S,S,T>
identity();

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr Matrix<S,S,T>&
transpose(Matrix<S,S,T>& matrix)
{
    if constexpr (S == 2)
    {
        std::swap(matrix(0,1), matrix(1,0));
    }

    else if constexpr (S == 3)
    {
        std::swap(matrix(0,1), matrix(1,0));
        std::swap(matrix(0,2), matrix(2,0));
        std::swap(matrix(1,2), matrix(2,1));
    }
    else if constexpr (S == 4)
    {
        std::swap(matrix(0,1), matrix(1,0));
        std::swap(matrix(0,2), matrix(2,0));
        std::swap(matrix(0,3), matrix(3,0));
        std::swap(matrix(1,2), matrix(2,1));
        std::swap(matrix(1,3), matrix(3,1));
        std::swap(matrix(2,3), matrix(3,2));
    }
    else
    {
        for (size_t i = 0; i < S-1; ++i)
        {
            for (size_t j = i+1; j < S; ++j)
            {
                std::swap(matrix(i,j),matrix(j,i));
            }
        }
    }

    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::Transposed
transposed(const Matrix<M,N,T>& matrix)
{
    if constexpr (M==N)
    {
        auto copy {matrix};
        transpose(copy);
        return copy;
    }
    if constexpr (M == 1 && N == 2)
    {
        return
        {
            matrix(0,0),
            matrix(0,1)
        };
    }
    if constexpr (M == 1 && N == 3)
    {
        return
        {
            matrix(0,0),
            matrix(0,1),
            matrix(0,2)
        };
    }
    if constexpr (M == 1 && N == 4)
    {
        return
        {
            matrix(0,0),
            matrix(0,1),
            matrix(0,2),
            matrix(0,3)
        };
    }
    if constexpr (M == 2 && N == 1)
    {
        return
        {
            matrix(0,0), matrix(1,0)
        };
    }
    if constexpr (M == 3 && N == 1)
    {
        return
        {
            matrix(0,0), matrix(1,0), matrix(2,0)
        };
    }
    if constexpr (M == 4 && N == 1)
    {
        return
        {
            matrix(0,0), matrix(1,0), matrix(2,0), matrix(3,0)
        };
    }
    if constexpr (M == 2 && N == 3)
    {
        return
        {
            matrix(0,0), matrix(1,0),
            matrix(0,1), matrix(1,1),
            matrix(0,2), matrix(1,2)
        };
    }
    if constexpr (M == 2 && N == 4)
    {
        return
        {
            matrix(0,0), matrix(1,0),
            matrix(0,1), matrix(1,1),
            matrix(0,2), matrix(1,2),
            matrix(0,3), matrix(1,3)
        };
    }
    if constexpr (M == 3 && N == 2)
    {
        return
        {
            matrix(0,0), matrix(1,0), matrix(2,0),
            matrix(0,1), matrix(1,1), matrix(2,1),
        };
    }
    if constexpr (M == 3 && N == 4)
    {
        return
        {
            matrix(0,0), matrix(1,0), matrix(2,0),
            matrix(0,1), matrix(1,1), matrix(2,1),
            matrix(0,2), matrix(1,2), matrix(2,2),
            matrix(0,3), matrix(1,3), matrix(2,3)
        };
    }
    if constexpr (M == 4 && N == 2)
    {
        return
        {
            matrix(0,0), matrix(1,0), matrix(2,0), matrix(3,0),
            matrix(0,1), matrix(1,1), matrix(2,1), matrix(3,1)
        };
    }
    if constexpr (M == 4 && N == 3)
    {
        return
        {
            matrix(0,0), matrix(1,0), matrix(2,0), matrix(3,0),
            matrix(0,1), matrix(1,1), matrix(2,1), matrix(3,1),
            matrix(0,2), matrix(1,2), matrix(2,2), matrix(3,2)
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr T
determinant(const Matrix<S,S,T>& matrix)
{
    static_assert(S <= 4, "Matrix functions. Cant calculate determinant for matrices more than 4x4 size.");

    if constexpr (S == 2)
    {
        return matrix(0,0)*matrix(1,1) - matrix(0,1)*matrix(1,0);
    }

    if constexpr (S == 3)
    {
        return
        matrix(0,0) * (matrix(1,1)*matrix(2,2) - matrix(1,2)*matrix(2,1)) -
        matrix(0,1) * (matrix(1,0)*matrix(2,2) - matrix(1,2)*matrix(2,0)) +
        matrix(0,2) * (matrix(1,0)*matrix(2,1) - matrix(1,1)*matrix(2,0));
    }

    if constexpr (S == 4)
    {
        return
        matrix(0,0) *
        (
            matrix(1,1) * (matrix(2,2)*matrix(3,3) - matrix(2,3)*matrix(3,2)) -
            matrix(1,2) * (matrix(2,1)*matrix(3,3) - matrix(2,3)*matrix(3,1)) +
            matrix(1,3) * (matrix(2,1)*matrix(3,2) - matrix(2,2)*matrix(3,1))
        )
        -matrix(0,1) *
        (
            matrix(1,0) * (matrix(2,2)*matrix(3,3) - matrix(2,3)*matrix(3,2)) -
            matrix(1,2) * (matrix(2,0)*matrix(3,3) - matrix(2,3)*matrix(3,0)) +
            matrix(1,3) * (matrix(2,0)*matrix(3,2) - matrix(2,2)*matrix(3,0))
        )
        +matrix(0,2) *
        (
            matrix(1,0) * (matrix(2,1)*matrix(3,3) - matrix(2,3)*matrix(3,1)) -
            matrix(1,1) * (matrix(2,0)*matrix(3,3) - matrix(2,3)*matrix(3,0)) +
            matrix(1,3) * (matrix(2,0)*matrix(3,1) - matrix(2,1)*matrix(3,0))
        )
        -matrix(0,3) *
        (
            matrix(1,0) * (matrix(2,1)*matrix(3,2) - matrix(2,2)*matrix(3,1)) -
            matrix(1,1) * (matrix(2,0)*matrix(3,2) - matrix(2,2)*matrix(3,0)) +
            matrix(1,2) * (matrix(2,0)*matrix(3,1) - matrix(2,1)*matrix(3,0))
        );
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr Matrix<S,S,T>
cofactors(const Matrix<S,S,T>& matrix)
{
    static_assert(S <= 4, "Matrix functions. Cant calculate cofactors for matrices more than 4x4 size.");

    if constexpr (S == 2)
    {
        return
        {
            matrix(1,1),    -matrix(1,0),
            -matrix(0,1),    matrix(0,0),
        };
    }

    if constexpr (S == 3)
    {
        return
        {
            matrix(1,1)*matrix(2,2) - matrix(1,2)*matrix(2,1), matrix(1,2)*matrix(2,0) - matrix(1,0)*matrix(2,2), matrix(1,0)*matrix(2,1) - matrix(1,1)*matrix(2,0),
            matrix(0,2)*matrix(2,1) - matrix(0,1)*matrix(2,2), matrix(0,0)*matrix(2,2) - matrix(0,2)*matrix(2,0), matrix(0,1)*matrix(2,0) - matrix(0,0)*matrix(2,1),
            matrix(0,1)*matrix(1,2) - matrix(0,2)*matrix(1,1), matrix(0,2)*matrix(1,0) - matrix(0,0)*matrix(1,2), matrix(0,0)*matrix(1,1) - matrix(0,1)*matrix(1,0)
        };
    }

    if constexpr (S == 4)
    {
        return
        {
            matrix(1,1) * (matrix(2,2)*matrix(3,3) - matrix(2,3)*matrix(3,2)) - matrix(1,2) * (matrix(2,1)*matrix(3,3) - matrix(2,3)*matrix(3,1)) + matrix(1,3) * (matrix(2,1)*matrix(3,2) - matrix(2,2)*matrix(3,1)),
            matrix(1,2) * (matrix(2,0)*matrix(3,3) - matrix(2,3)*matrix(3,0)) - matrix(1,0) * (matrix(2,2)*matrix(3,3) - matrix(2,3)*matrix(3,2)) - matrix(1,3) * (matrix(2,0)*matrix(3,2) - matrix(2,2)*matrix(3,0)),
            matrix(1,0) * (matrix(2,1)*matrix(3,3) - matrix(2,3)*matrix(3,1)) - matrix(1,1) * (matrix(2,0)*matrix(3,3) - matrix(2,3)*matrix(3,0)) + matrix(1,3) * (matrix(2,0)*matrix(3,1) - matrix(2,1)*matrix(3,0)),
            matrix(1,1) * (matrix(2,0)*matrix(3,2) - matrix(2,2)*matrix(3,0)) - matrix(1,0) * (matrix(2,1)*matrix(3,2) - matrix(2,2)*matrix(3,1)) - matrix(1,2) * (matrix(2,0)*matrix(3,1) - matrix(2,1)*matrix(3,0)),
            matrix(0,2) * (matrix(2,1)*matrix(3,3) - matrix(2,3)*matrix(3,1)) - matrix(0,1) * (matrix(2,2)*matrix(3,3) - matrix(2,3)*matrix(3,2)) - matrix(0,3) * (matrix(2,1)*matrix(3,2) - matrix(2,2)*matrix(3,1)),
            matrix(0,0) * (matrix(2,2)*matrix(3,3) - matrix(2,3)*matrix(3,2)) - matrix(0,2) * (matrix(2,0)*matrix(3,3) - matrix(2,3)*matrix(3,0)) + matrix(0,3) * (matrix(2,0)*matrix(3,2) - matrix(2,2)*matrix(3,0)),
            matrix(0,1) * (matrix(2,0)*matrix(3,3) - matrix(2,3)*matrix(3,0)) - matrix(0,0) * (matrix(2,1)*matrix(3,3) - matrix(2,3)*matrix(3,1)) - matrix(0,3) * (matrix(2,0)*matrix(3,1) - matrix(2,1)*matrix(3,0)),
            matrix(0,0) * (matrix(2,1)*matrix(3,2) - matrix(2,2)*matrix(3,1)) - matrix(0,1) * (matrix(2,0)*matrix(3,2) - matrix(2,2)*matrix(3,0)) + matrix(0,2) * (matrix(2,0)*matrix(3,1) - matrix(2,1)*matrix(3,0)),
            matrix(0,1) * (matrix(1,2)*matrix(3,3) - matrix(1,3)*matrix(3,2)) - matrix(0,2) * (matrix(1,1)*matrix(3,3) - matrix(1,3)*matrix(3,1)) + matrix(0,3) * (matrix(1,1)*matrix(3,2) - matrix(1,2)*matrix(3,1)),
            matrix(0,2) * (matrix(1,0)*matrix(3,3) - matrix(1,3)*matrix(3,0)) - matrix(0,0) * (matrix(1,2)*matrix(3,3) - matrix(1,3)*matrix(3,2)) - matrix(0,3) * (matrix(1,0)*matrix(3,2) - matrix(1,2)*matrix(3,0)),
            matrix(0,0) * (matrix(1,1)*matrix(3,3) - matrix(1,3)*matrix(3,1)) - matrix(0,1) * (matrix(1,0)*matrix(3,3) - matrix(1,3)*matrix(3,0)) + matrix(0,3) * (matrix(1,0)*matrix(3,1) - matrix(1,1)*matrix(3,0)),
            matrix(0,1) * (matrix(1,0)*matrix(3,2) - matrix(1,2)*matrix(3,0)) - matrix(0,0) * (matrix(1,1)*matrix(3,2) - matrix(1,2)*matrix(3,1)) - matrix(0,2) * (matrix(1,0)*matrix(3,1) - matrix(1,1)*matrix(3,0)),
            matrix(0,2) * (matrix(1,1)*matrix(2,3) - matrix(1,3)*matrix(2,1)) - matrix(0,1) * (matrix(1,2)*matrix(2,3) - matrix(1,3)*matrix(2,2)) - matrix(0,3) * (matrix(1,1)*matrix(2,2) - matrix(1,2)*matrix(2,1)),
            matrix(0,0) * (matrix(1,2)*matrix(2,3) - matrix(1,3)*matrix(2,2)) - matrix(0,2) * (matrix(1,0)*matrix(2,3) - matrix(1,3)*matrix(2,0)) + matrix(0,3) * (matrix(1,0)*matrix(2,2) - matrix(1,2)*matrix(2,0)),
            matrix(0,1) * (matrix(1,0)*matrix(2,3) - matrix(1,3)*matrix(2,0)) - matrix(0,0) * (matrix(1,1)*matrix(2,3) - matrix(1,3)*matrix(2,1)) - matrix(0,3) * (matrix(1,0)*matrix(2,1) - matrix(1,1)*matrix(2,0)),
            matrix(0,0) * (matrix(1,1)*matrix(2,2) - matrix(1,2)*matrix(2,1)) - matrix(0,1) * (matrix(1,0)*matrix(2,2) - matrix(1,2)*matrix(2,0)) + matrix(0,2) * (matrix(1,0)*matrix(2,1) - matrix(1,1)*matrix(2,0))
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename TResult, size_t S, typename T>
constexpr Matrix<S,S,TResult>
inverted(const Matrix<S,S,T>& matrix, bool& success)
{
    static_assert(S <= 4, "Matrix functions. Cant calculate inverted matrices more than 4x4 size.");

    T det {determinant(matrix)};

    if (equal(det, zero<T>()))
    {
        success = false;
        return Matrix<S,S,TResult>();
    }
    else
    {
        success = true;
        return transposed(cofactors(matrix))/det;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr Matrix<S,S,T>
identity()
{
    if constexpr (S==2)
    {
        return
        {
            1, 0,
            0, 1
        };
    }
    else if constexpr (S==3)
    {
        return
        {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };
    }
    else if constexpr (S==4)
    {
        return
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
    }
    else
    {
        Matrix<S,S,T> matrix(zero<T>());
        for (auto i = 0; i < S; ++i) matrix(i,i) = number<T>(1);
        return matrix;
    }
}

MATH3D_NAMESPACE_END

#endif //MATH3D_MATRIX_FUNCTIONS_HPP
