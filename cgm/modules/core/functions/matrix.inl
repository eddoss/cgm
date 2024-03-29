

#include "matrix.hpp"


CGM_NAMESPACE_BEGIN

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
    else
    {
        typename Matrix<M,N,T>::Transposed mat;

        for (size_t m = 0; m < M; ++m)
        {
            for (size_t n = 0; n < N; ++n)
            {
                mat(n,m) = matrix(m,n);
            }
        }

        return mat;
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

template<size_t S, typename T>
constexpr enable_if_floating<T, bool>
invertSafe(Matrix<S,S,T>& matrix, T determinantTolerance)
{
    static_assert(S <= 4, "Matrix functions. Cant calculate inverse matrix more than 4x4 size.");

    T det {determinant(matrix)};

    if (std::abs(det) >= determinantTolerance)
    {
        matrix = transposed(cofactors(matrix)) / det;
        return true;
    }
    else
    {
        return false;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr enable_if_floating<T,Matrix<S,S,T>>
inverseSafe(const Matrix<S,S,T>& matrix, bool& success, T determinantTolerance)
{
    static_assert(S <= 4, "Matrix functions. Cant calculate inverse matrix more than 4x4 size.");

    T det {determinant(matrix)};

    if (std::abs(det) >= determinantTolerance)
    {
        success = true;
        return transposed(cofactors(matrix)) / det;
    }
    else
    {
        success = false;
        return Matrix<S,S,T>();
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
invert(Matrix<S,S,T>& matrix)
{
    static_assert(S <= 4, "Matrix functions. Cant calculate inverse matrix more than 4x4 size.");
    matrix = transposed(cofactors(matrix)) / determinant(matrix);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Matrix<S,S,T>>
inverse(const Matrix<S,S,T>& matrix)
{
    static_assert(S <= 4, "Matrix functions. Cant calculate inverse matrix more than 4x4 size.");
    return transposed(cofactors(matrix)) / determinant(matrix);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE T
trace(const Matrix<S,S,T>& matrix)
{
    if constexpr (S == 2)
    {
        return matrix(0,0) + matrix(1,1);
    }
    else if constexpr (S == 3)
    {
        return matrix(0,0) + matrix(1,1) + matrix(2,2);
    }
    else if constexpr (S == 4)
    {
        return matrix(0,0) + matrix(1,1) + matrix(2,2) + matrix(3,3);
    }
    else
    {
        T sum {T(0)};

        for (size_t i = 0; i < S; ++i)
        {
            sum += matrix(i,i);
        }

        return sum;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE bool
symmetric(const Matrix<S,S,T>& matrix)
{
    if constexpr (S == 2)
    {
        return eq(matrix(0,1), matrix(1,0));
    }
    else if constexpr (S == 3)
    {
        return
        eq(matrix(0,1), matrix(1,0)) &&
        eq(matrix(0,2), matrix(2,0)) &&
        eq(matrix(1,2), matrix(2,1));
    }
    else if constexpr (S == 4)
    {
        return
        eq(matrix(0,1), matrix(1,0)) &&
        eq(matrix(0,2), matrix(2,0)) &&
        eq(matrix(0,3), matrix(3,0)) &&
        eq(matrix(1,2), matrix(2,1)) &&
        eq(matrix(1,3), matrix(3,1)) &&
        eq(matrix(2,3), matrix(3,2));
    }
    else
    {
        for (size_t i = 0; i < S-1; ++i)
        {
            for (size_t j = i+1; j < S; ++j)
            {
                if (neq(matrix(i,j),matrix(j,i)))
                {
                    return false;
                }
            }
        }
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE bool
symmetric(const Matrix<S,S,T>& matrix, T tolerance)
{
    if constexpr (S == 2)
    {
        return eq(matrix(0,1), matrix(1,0), tolerance);
    }
    else if constexpr (S == 3)
    {
        return
        eq(matrix(0,1), matrix(1,0), tolerance) &&
        eq(matrix(0,2), matrix(2,0), tolerance) &&
        eq(matrix(1,2), matrix(2,1), tolerance);
    }
    else if constexpr (S == 4)
    {
        return
        eq(matrix(0,1), matrix(1,0), tolerance) &&
        eq(matrix(0,2), matrix(2,0), tolerance) &&
        eq(matrix(0,3), matrix(3,0), tolerance) &&
        eq(matrix(1,2), matrix(2,1), tolerance) &&
        eq(matrix(1,3), matrix(3,1), tolerance) &&
        eq(matrix(2,3), matrix(3,2), tolerance);
    }
    else
    {
        for (size_t i = 0; i < S-1; ++i)
        {
            for (size_t j = i+1; j < S; ++j)
            {
                if (neq(matrix(i,j),matrix(j,i), tolerance))
                {
                    return false;
                }
            }
        }
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE bool
antisymmetric(const Matrix<S,S,T>& matrix)
{
    if constexpr (S == 2)
    {
        return eq(-matrix(0,1), matrix(1,0));
    }
    else if constexpr (S == 3)
    {
        return
        eq(-matrix(0,1), matrix(1,0)) &&
        eq(-matrix(0,2), matrix(2,0)) &&
        eq(-matrix(1,2), matrix(2,1));
    }
    else if constexpr (S == 4)
    {
        eq(-matrix(0,1), matrix(1,0)) &&
        eq(-matrix(0,2), matrix(2,0)) &&
        eq(-matrix(0,3), matrix(3,0)) &&
        eq(-matrix(1,2), matrix(2,1)) &&
        eq(-matrix(1,3), matrix(3,1)) &&
        eq(-matrix(2,3), matrix(3,2));
    }
    else
    {
        for (size_t i = 0; i < S-1; ++i)
        {
            for (size_t j = i+1; j < S; ++j)
            {
                if (neq(-matrix(i,j),matrix(j,i)))
                {
                    return false;
                }
            }
        }
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE bool
antisymmetric(const Matrix<S,S,T>& matrix, T tolerance)
{
    if constexpr (S == 2)
    {
        return eq(-matrix(0,1), matrix(1,0), tolerance);
    }
    else if constexpr (S == 3)
    {
        return
        eq(-matrix(0,1), matrix(1,0), tolerance) &&
        eq(-matrix(0,2), matrix(2,0), tolerance) &&
        eq(-matrix(1,2), matrix(2,1), tolerance);
    }
    else if constexpr (S == 4)
    {
        return
        eq(-matrix(0,1), matrix(1,0), tolerance) &&
        eq(-matrix(0,2), matrix(2,0), tolerance) &&
        eq(-matrix(0,3), matrix(3,0), tolerance) &&
        eq(-matrix(1,2), matrix(2,1), tolerance) &&
        eq(-matrix(1,3), matrix(3,1), tolerance) &&
        eq(-matrix(2,3), matrix(3,2), tolerance);
    }
    else
    {
        for (size_t i = 0; i < S-1; ++i)
        {
            for (size_t j = i+1; j < S; ++j)
            {
                if (neq(-matrix(i,j),matrix(j,i), tolerance))
                {
                    return false;
                }
            }
        }
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr bool
diagonal(const Matrix<S,S,T>& matrix)
{
    for (size_t i = 0; i < S; ++i)
    {
        if (eq(matrix(i,i), T(0)))
        {
            return false;
        }
    }

    for (size_t m = 0; m < S; ++m)
    {
        for (size_t n = 0; n < S; ++n)
        {
            if (m == n) {continue;}

            if (neq(matrix(m,n), T(0)))
            {
                return false;
            }
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr bool
diagonal(const Matrix<S,S,T>& matrix, T tolerance)
{
    for (size_t i = 0; i < S; ++i)
    {
        if (eq(matrix(i,i), T(0)), tolerance)
        {
            return false;
        }
    }

    for (size_t m = 0; m < S; ++m)
    {
        for (size_t n = 0; n < S; ++n)
        {
            if (m == n) {continue;}

            if (neq(matrix(m,n), T(0), tolerance))
            {
                return false;
            }
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr bool
orthogonal(const Matrix<S,S,T>& matrix, T tolerance, T determinantTolerance)
{
    bool existInverse {false};
    auto invmat {inverseSafe(matrix, existInverse)};

    if (!existInverse)
    {
        return false;
    }
    else
    {
        if constexpr (S == 2)
        {
            return
            eq(invmat(0,0), matrix(0,0), tolerance) &&
            eq(invmat(0,1), matrix(1,0), tolerance) &&
            eq(invmat(1,1), matrix(1,1), tolerance);
        }
        else if constexpr (S == 3)
        {
            return
            eq(invmat(0,0), matrix(0,0), tolerance) &&
            eq(invmat(0,1), matrix(1,0), tolerance) &&
            eq(invmat(0,2), matrix(2,0), tolerance) &&
            eq(invmat(1,2), matrix(2,1), tolerance) &&
            eq(invmat(2,2), matrix(2,2), tolerance);
        }
        else if constexpr (S == 4)
        {
            return
            eq(invmat(0,0), matrix(0,0), tolerance) &&
            eq(invmat(0,1), matrix(1,0), tolerance) &&
            eq(invmat(0,2), matrix(2,0), tolerance) &&
            eq(invmat(0,3), matrix(3,0), tolerance) &&
            eq(invmat(1,2), matrix(2,1), tolerance) &&
            eq(invmat(1,3), matrix(3,1), tolerance) &&
            eq(invmat(2,3), matrix(3,2), tolerance) &&
            eq(invmat(3,3), matrix(3,3), tolerance);
        }
        else
        {
            bool result {false};
            for (size_t i = 0; i < S-1; ++i)
            {
                for (size_t j = i+1; j < S; ++j)
                {
                    if (neq(invmat(i,j),matrix(j,i), tolerance))
                    {
                        result = false;
                    };
                }
            }

            return
            eq(invmat(0,0),matrix(0,0), tolerance) &&
            eq(invmat(S-1,S-1),matrix(S-1,S-1), tolerance) &&
            result;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE Matrix<S,S,T>
identity()
{
    if constexpr (S==2)
    {
        return
        {
            T(1), T(0),
            T(0), T(1)
        };
    }
    else if constexpr (S==3)
    {
        return
        {
            T(1), T(0), T(0),
            T(0), T(1), T(0),
            T(0), T(0), T(1)
        };
    }
    else if constexpr (S==4)
    {
        return
        {
            T(1), T(0), T(0), T(0),
            T(0), T(1), T(0), T(0),
            T(0), T(0), T(1), T(0),
            T(0), T(0), T(0), T(1)
        };
    }
    else
    {
        Matrix<S,S,T> matrix(T(0));
        for (size_t i = 0; i < S; ++i) matrix(i,i) = T(1);
        return matrix;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM_FORCEINLINE void
setIdentity(Matrix<S,S,T>& matrix)
{
    if constexpr (S==2)
    {
        matrix(0,0) = T(1);
        matrix(1,1) = T(1);
        matrix(0,1) = T(0);
        matrix(1,0) = T(0);
    }
    else if constexpr (S==3)
    {
        matrix(0,0) = T(1);
        matrix(1,1) = T(1);
        matrix(2,2) = T(1);
        matrix(0,1) = T(0);
        matrix(0,2) = T(0);
        matrix(1,0) = T(0);
        matrix(1,2) = T(0);
        matrix(2,0) = T(0);
        matrix(2,1) = T(0);
    }
    else if constexpr (S==4)
    {
        matrix(0,0) = T(1);
        matrix(1,1) = T(1);
        matrix(2,2) = T(1);
        matrix(3,3) = T(1);
        matrix(0,1) = T(0);
        matrix(0,2) = T(0);
        matrix(0,3) = T(0);
        matrix(1,0) = T(0);
        matrix(1,2) = T(0);
        matrix(1,3) = T(0);
        matrix(2,0) = T(0);
        matrix(2,1) = T(0);
        matrix(2,3) = T(0);
        matrix(3,0) = T(0);
        matrix(3,1) = T(0);
        matrix(3,2) = T(0);
    }
    else
    {
        matrix = T(0);
        for (size_t i = 0; i < S; ++i)
        {
            matrix(i,i) = T(1);
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
eq(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B, T tolerance)
{
    if constexpr (M == 1 && N == 2)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance);
    }
    else if constexpr (M == 1 && N == 3)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance) &&
        CGM::eq(A(0,2), B(0,2), tolerance);
    }
    else if constexpr (M == 1 && N == 4)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance) &&
        CGM::eq(A(0,2), B(0,2), tolerance) &&
        CGM::eq(A(0,3), B(0,3), tolerance);
    }
    else if constexpr (M == 2 && N == 1)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance);
    }
    else if constexpr (M == 3 && N == 1)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance) &&
        CGM::eq(A(2,0), B(2,0), tolerance);
    }
    else if constexpr (M == 4 && N == 1)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance) &&
        CGM::eq(A(2,0), B(2,0), tolerance) &&
        CGM::eq(A(3,0), B(3,0), tolerance);
    }
    else if constexpr (M == 2 && N == 2)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance) &&
        CGM::eq(A(1,1), B(1,1), tolerance);
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance) &&
        CGM::eq(A(0,2), B(0,2), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance) &&
        CGM::eq(A(1,1), B(1,1), tolerance) &&
        CGM::eq(A(1,2), B(1,2), tolerance);
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance) &&
        CGM::eq(A(0,2), B(0,2), tolerance) &&
        CGM::eq(A(0,3), B(0,3), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance) &&
        CGM::eq(A(1,1), B(1,1), tolerance) &&
        CGM::eq(A(1,2), B(1,2), tolerance) &&
        CGM::eq(A(1,3), B(1,3), tolerance);
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance) &&
        CGM::eq(A(2,0), B(2,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance) &&
        CGM::eq(A(1,1), B(1,1), tolerance) &&
        CGM::eq(A(2,1), B(2,1), tolerance);
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance) &&
        CGM::eq(A(0,2), B(0,2), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance) &&
        CGM::eq(A(1,1), B(1,1), tolerance) &&
        CGM::eq(A(1,2), B(1,2), tolerance) &&
        CGM::eq(A(2,0), B(2,0), tolerance) &&
        CGM::eq(A(2,1), B(2,1), tolerance) &&
        CGM::eq(A(2,2), B(2,2), tolerance);
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance) &&
        CGM::eq(A(0,2), B(0,2), tolerance) &&
        CGM::eq(A(0,3), B(0,3), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance) &&
        CGM::eq(A(1,1), B(1,1), tolerance) &&
        CGM::eq(A(1,2), B(1,2), tolerance) &&
        CGM::eq(A(1,3), B(1,3), tolerance) &&
        CGM::eq(A(2,0), B(2,0), tolerance) &&
        CGM::eq(A(2,1), B(2,1), tolerance) &&
        CGM::eq(A(2,2), B(2,2), tolerance) &&
        CGM::eq(A(2,3), B(2,3), tolerance);
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance) &&
        CGM::eq(A(1,1), B(1,1), tolerance) &&
        CGM::eq(A(2,0), B(2,0), tolerance) &&
        CGM::eq(A(2,1), B(2,1), tolerance) &&
        CGM::eq(A(3,0), B(3,0), tolerance) &&
        CGM::eq(A(3,1), B(3,1), tolerance);
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance) &&
        CGM::eq(A(0,2), B(0,2), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance) &&
        CGM::eq(A(1,1), B(1,1), tolerance) &&
        CGM::eq(A(1,2), B(1,2), tolerance) &&
        CGM::eq(A(2,0), B(2,0), tolerance) &&
        CGM::eq(A(2,1), B(2,1), tolerance) &&
        CGM::eq(A(2,2), B(2,2), tolerance) &&
        CGM::eq(A(3,0), B(3,0), tolerance) &&
        CGM::eq(A(3,1), B(3,1), tolerance) &&
        CGM::eq(A(3,2), B(3,2), tolerance);
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        CGM::eq(A(0,0), B(0,0), tolerance) &&
        CGM::eq(A(0,1), B(0,1), tolerance) &&
        CGM::eq(A(0,2), B(0,2), tolerance) &&
        CGM::eq(A(0,3), B(0,3), tolerance) &&
        CGM::eq(A(1,0), B(1,0), tolerance) &&
        CGM::eq(A(1,1), B(1,1), tolerance) &&
        CGM::eq(A(1,2), B(1,2), tolerance) &&
        CGM::eq(A(1,3), B(1,3), tolerance) &&
        CGM::eq(A(2,0), B(2,0), tolerance) &&
        CGM::eq(A(2,1), B(2,1), tolerance) &&
        CGM::eq(A(2,2), B(2,2), tolerance) &&
        CGM::eq(A(2,3), B(2,3), tolerance) &&
        CGM::eq(A(3,0), B(3,0), tolerance) &&
        CGM::eq(A(3,1), B(3,1), tolerance) &&
        CGM::eq(A(3,2), B(3,2), tolerance) &&
        CGM::eq(A(3,3), B(3,3), tolerance);
    }
    else
    {
        for (size_t i = 0; i < CGM::Matrix<M,N,T>::count; ++i)
        {
            if (CGM::neq(A[i], B[i]), tolerance) return false;
        }
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
neq(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B, T tolerance)
{
    if constexpr (M == 1 && N == 2)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance);
    }
    else if constexpr (M == 1 && N == 3)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance) ||
        CGM::neq(A(0,2), B(0,2), tolerance);
    }
    else if constexpr (M == 1 && N == 4)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance) ||
        CGM::neq(A(0,2), B(0,2), tolerance) ||
        CGM::neq(A(0,3), B(0,3), tolerance);
    }
    else if constexpr (M == 2 && N == 1)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance);
    }
    else if constexpr (M == 3 && N == 1)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance) ||
        CGM::neq(A(2,0), B(2,0), tolerance);
    }
    else if constexpr (M == 4 && N == 1)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance) ||
        CGM::neq(A(2,0), B(2,0), tolerance) ||
        CGM::neq(A(3,0), B(3,0), tolerance);
    }
    else if constexpr (M == 2 && N == 2)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance) ||
        CGM::neq(A(1,1), B(1,1), tolerance);
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance) ||
        CGM::neq(A(0,2), B(0,2), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance) ||
        CGM::neq(A(1,1), B(1,1), tolerance) ||
        CGM::neq(A(1,2), B(1,2), tolerance);
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance) ||
        CGM::neq(A(0,2), B(0,2), tolerance) ||
        CGM::neq(A(0,3), B(0,3), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance) ||
        CGM::neq(A(1,1), B(1,1), tolerance) ||
        CGM::neq(A(1,2), B(1,2), tolerance) ||
        CGM::neq(A(1,3), B(1,3), tolerance);
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance) ||
        CGM::neq(A(2,0), B(2,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance) ||
        CGM::neq(A(1,1), B(1,1), tolerance) ||
        CGM::neq(A(2,1), B(2,1), tolerance);
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance) ||
        CGM::neq(A(0,2), B(0,2), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance) ||
        CGM::neq(A(1,1), B(1,1), tolerance) ||
        CGM::neq(A(1,2), B(1,2), tolerance) ||
        CGM::neq(A(2,0), B(2,0), tolerance) ||
        CGM::neq(A(2,1), B(2,1), tolerance) ||
        CGM::neq(A(2,2), B(2,2), tolerance);
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance) ||
        CGM::neq(A(0,2), B(0,2), tolerance) ||
        CGM::neq(A(0,3), B(0,3), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance) ||
        CGM::neq(A(1,1), B(1,1), tolerance) ||
        CGM::neq(A(1,2), B(1,2), tolerance) ||
        CGM::neq(A(1,3), B(1,3), tolerance) ||
        CGM::neq(A(2,0), B(2,0), tolerance) ||
        CGM::neq(A(2,1), B(2,1), tolerance) ||
        CGM::neq(A(2,2), B(2,2), tolerance) ||
        CGM::neq(A(2,3), B(2,3), tolerance);
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance) ||
        CGM::neq(A(1,1), B(1,1), tolerance) ||
        CGM::neq(A(2,0), B(2,0), tolerance) ||
        CGM::neq(A(2,1), B(2,1), tolerance) ||
        CGM::neq(A(3,0), B(3,0), tolerance) ||
        CGM::neq(A(3,1), B(3,1), tolerance);
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance) ||
        CGM::neq(A(0,2), B(0,2), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance) ||
        CGM::neq(A(1,1), B(1,1), tolerance) ||
        CGM::neq(A(1,2), B(1,2), tolerance) ||
        CGM::neq(A(2,0), B(2,0), tolerance) ||
        CGM::neq(A(2,1), B(2,1), tolerance) ||
        CGM::neq(A(2,2), B(2,2), tolerance) ||
        CGM::neq(A(3,0), B(3,0), tolerance) ||
        CGM::neq(A(3,1), B(3,1), tolerance) ||
        CGM::neq(A(3,2), B(3,2), tolerance);
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        CGM::neq(A(0,0), B(0,0), tolerance) ||
        CGM::neq(A(0,1), B(0,1), tolerance) ||
        CGM::neq(A(0,2), B(0,2), tolerance) ||
        CGM::neq(A(0,3), B(0,3), tolerance) ||
        CGM::neq(A(1,0), B(1,0), tolerance) ||
        CGM::neq(A(1,1), B(1,1), tolerance) ||
        CGM::neq(A(1,2), B(1,2), tolerance) ||
        CGM::neq(A(1,3), B(1,3), tolerance) ||
        CGM::neq(A(2,0), B(2,0), tolerance) ||
        CGM::neq(A(2,1), B(2,1), tolerance) ||
        CGM::neq(A(2,2), B(2,2), tolerance) ||
        CGM::neq(A(2,3), B(2,3), tolerance) ||
        CGM::neq(A(3,0), B(3,0), tolerance) ||
        CGM::neq(A(3,1), B(3,1), tolerance) ||
        CGM::neq(A(3,2), B(3,2), tolerance) ||
        CGM::neq(A(3,3), B(3,3), tolerance);
    }
    else
    {
        for (size_t i = 0; i < CGM::Matrix<M,N,T>::count; ++i)
        {
            if (CGM::neq(A[i], B[i]), tolerance) return true;
        }
        return false;
    }
}

CGM_NAMESPACE_END