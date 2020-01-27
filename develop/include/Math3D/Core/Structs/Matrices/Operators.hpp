#ifndef MATH3D_MATRIX_OPERATORS_HPP
#define MATH3D_MATRIX_OPERATORS_HPP


#include <Math3D/Core/Structs/Matrices/Matrix.hpp>


/* ####################################################################################### */
/* Increment and decrement */
/* ####################################################################################### */

/**
 * Increase all components of matrix by 1 and returns it.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator++(Matrix<M,N,T>& matrix);

/**
 * Decrease all components of matrix by 1 and returns it.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator--(Matrix<M,N,T>& matrix);

/**
 * Increase all components of matrix by 1 and returns unchanged copy of it.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator++(Matrix<M,N,T>& matrix, int);

/**
 * Decrease all components of matrix by 1 and returns unchanged copy of it.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator--(Matrix<M,N,T>& matrix, int);

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

/**
 * Calculates sum of two matrix.
 * @param A Left matrix.
 * @param B Right matrix.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator+(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Add scalar to matrix and return copy.
 * @param matrix Matrix to add to.
 * @param scalar Value to add.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator+(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Add scalar to matrix and return copy.
 * @param matrix Matrix to add to.
 * @param scalar Value to add.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator+(T scalar, const Matrix<M,N,T>& matrix);

/**
 * Add scalar to matrix components.
 * @param matrix Matrix to add to.
 * @param scalar Value to add.
 * @return The result of adding.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator+=(Matrix<M,N,T>& matrix, T scalar);

/**
 * Add matrix B to matrix A.
 * @param A Matrix to add to.
 * @param B Matrix to add.
 * @return The result of adding.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator+=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

/**
 * Get a negated copy of the matrix.
 * @param matrix Matrix to negate.
 * @return A negated copy of the matrix.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator-(const Matrix<M,N,T>& matrix);

/**
 * Calculates difference of two matrix.
 * @param A Left matrix.
 * @param B Right matrix.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator-(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Subtract scalar from each matrix component and return copy.
 * @param matrix Matrix to subtract from.
 * @param scalar Value to subtract.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator-(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Subtract scalar from each matrix component.
 * @param matrix Matrix to subtract from.
 * @param scalar Value to subtract.
 * @return The result of subtraction.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator-=(Matrix<M,N,T>& matrix, T scalar);

/**
 * Subtract matrix B from matrix A.
 * @param A Matrix to subtract from.
 * @param B Matrix to subtract.
 * @return The result of subtraction.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator-=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

/**
 * Multiply scalar to each matrix component and return copy.
 * @param matrix Matrix to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator*(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Multiply scalar to each matrix component and return copy.
 * @param matrix Matrix to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator*(T scalar, const Matrix<M,N,T>& matrix);

/**
 * Multiply A matrix by B matrix.
 * @param A left matrix.
 * @param B right matrix.
 * @param AM left matrix rows count.
 * @param AN left matrix columns count and right matrix rows count.
 * @param BN right matrix columns count.
 * @return The result of multiplication.
 */
template<size_t AM, size_t AN, size_t BN, typename T>
constexpr Matrix<AM,BN,T>
operator*(const Matrix<AM,AN,T>& A, const Matrix<AN,BN,T>& B);

/**
 * Multiply scalar to each matrix component.
 * @param matrix Matrix to multiply to.
 * @param scalar Value to multiply.
 * @return The result of multiplication.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator*=(Matrix<M,N,T>& matrix, T scalar);

/**
 * Multiply square matrix A by square matrix B and store result in A.
 * @param A left matrix.
 * @param B right matrix.
 * @param S matrices size
 * @return The result of multiplication.
 */
template<size_t S, typename T>
constexpr Matrix<S,S,T>&
operator*=(Matrix<S,S,T>& A, const Matrix<S,S,T>& B);

/* ####################################################################################### */
/* Component wise division */
/* ####################################################################################### */

/**
 * Divide each matrix component by a scalar and return copy.
 * @param matrix Matrix to division to.
 * @param scalar Value to division.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator/(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Divide each matrix component by a scalar and return copy.
 * @param matrix Matrix to division to.
 * @param scalar Value to division.
 * @return The result of division.
 */
template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator/=(Matrix<M,N,T>& matrix, T scalar);

/* ####################################################################################### */
/* Comparison with scalar */
/* ####################################################################################### */

/**
 * Checking the components of a matrix for equality with a scalar.
 * @param matrix Matrix to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are equal to scalar, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator==(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Checking the components of a matrix for inequality with a scalar.
 * @param matrix Matrix to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are not equal to scalar, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator!=(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Checks if all components of a matrix are less than a scalar.
 * @param matrix Matrix to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are less than scalar, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator<(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Checks if all components of a matrix are greater than a scalar.
 * @param matrix Matrix to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are greater than scalar, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator>(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Checks if all components of a matrix are less or equal to a scalar.
 * @param matrix Matrix to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are less or equal to a scalar, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator<=(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Checks if all components of a matrix are greater or equal to a scalar.
 * @param matrix Matrix to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are greater or equal to a scalar, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator>=(const Matrix<M,N,T>& matrix, T scalar);

/* ####################################################################################### */
/* Comparison with other */
/* ####################################################################################### */

/**
 * Check against another matrix for equality.
 * @param A Matrix to compare.
 * @param B Matrix to compare with.
 * @return true if the matrix are equal, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator==(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Check against another matrix for inequality.
 * @param A Matrix to compare.
 * @param B Matrix to compare with.
 * @return true if the matrices are not equal, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator!=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Compares whether all the components of this matrix are smaller than other.
 * @param A Matrix to compare.
 * @param B Matrix to compare with.
 * @return true if A matrix components less than B matrix components, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator<(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Compares whether all the components of this matrix are larger than other.
 * @param A Matrix to compare.
 * @param B Matrix to compare with.
 * @return true if A matrix components less or equal B matrix components, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator<=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Compares whether all the components of this matrix are smaller (or equal) than other.
 * @param A Matrix to compare.
 * @param B Matrix to compare with.
 * @return true if A matrix components greater than B matrix components, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator>(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Compares whether all the components of this matrix are larger (or equal) than other.
 * @param A Matrix to compare.
 * @param B Matrix to compare with.
 * @return true if A matrix components greater or equal B matrix components, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator>=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);






/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */






/* ####################################################################################### */
/* IMPLEMENTATION | Increment and decrement */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator++(Matrix<M,N,T>& matrix)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) ++(matrix[i]);
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator--(Matrix<M,N,T>& matrix)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) --(matrix[i]);
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator++(Matrix<M,N,T>& matrix, int)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) ++(matrix[i]);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator--(Matrix<M,N,T>& matrix, int)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) --(matrix[i]);
    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Plus */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator+(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    Matrix<M,N,T> copy {A};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) copy[i] += B[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator+(const Matrix<M,N,T>& matrix, T scalar)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) copy[i] += scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator+(T scalar, const Matrix<M,N,T>& matrix)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) copy[i] += scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator+=(Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) matrix[i] += scalar;
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator+=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) A[i] += B[i];
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Minus */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator-(const Matrix<M,N,T>& matrix)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) copy[i] = -copy[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator-(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    Matrix<M,N,T> copy {A};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) copy[i] -= B[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator-(const Matrix<M,N,T>& matrix, T scalar)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) copy[i] -= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator-=(Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) matrix[i] -= scalar;
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator-=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) A[i] -= B[i];
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Multiplication */
/* ####################################################################################### */


/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator*(const Matrix<M,N,T>& matrix, T scalar)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) copy[i] *= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator*(T scalar, const Matrix<M,N,T>& matrix)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) copy[i] *= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t AM, size_t AN, size_t BN, typename T>
constexpr Matrix<AM,BN,T>
operator*(const Matrix<AM,AN,T>& A, const Matrix<AN,BN,T>& B)
{
    Matrix<AM,BN,T> out;
    typename Matrix<AM,BN,T>::value_type sum;

    for (size_t c = 0; c < BN; ++c )
    {
        for (auto r = 0; r < AM; ++r)
        {
            sum = static_cast<typename Matrix<AM,BN,T>::value_type>(0);
            for (auto i = 0; i < AN; ++i)
            {
                sum += A(r,i) * B(i,c);
            }
            out(r,c) = sum;
        }
    }
    return out;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator*=(Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) matrix[i] *= scalar;
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr Matrix<S,S,T>&
operator*=(Matrix<S,S,T>& A, const Matrix<S,S,T>& B)
{
    Matrix<S,S,T> out;
    FLOAT sum {0};

    for (auto c = 0; c < S; ++c)
    {
        for (auto r = 0; r < S; ++r)
        {
            sum = Matrix<S,S,T>::value_type(0);
            for (auto i = 0; i < S; ++i)
            {
                sum += A(r,i) * B(i,c);
            }
            out(r,c) = sum;
        }
    }
    A = out;
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise division */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator/(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    Matrix<M,N,T> copy {A};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) copy[i] /= B[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator/(const Matrix<M,N,T>& matrix, T scalar)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) copy[i] /= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator/=(Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) matrix[i] /= scalar;
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator/=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) A[i] /= B[i];
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with scalar */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr bool
operator==(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (notEqual(matrix[i], scalar)) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator!=(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (notEqual(matrix[i], scalar)) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator<(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (matrix[i] >= scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator>(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (matrix[i] <= scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator<=(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (matrix[i] > scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator>=(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (matrix[i] < scalar) return false;
    return true;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with other */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr bool
operator==(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (notEqual(A[i], B[i])) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator!=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (notEqual(A[i], B[i])) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator<(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (A[i] >= B[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator>(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (A[i] <= B[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator<=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (A[i] > B[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator>=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (A[i] < B[i]) return false;
    return true;
}

#endif // MATH3D_MATRIX_OPERATORS_HPP
