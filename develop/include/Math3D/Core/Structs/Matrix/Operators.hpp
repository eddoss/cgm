#ifndef MATH3D_MATRIX_OPERATORS_HPP
#define MATH3D_MATRIX_OPERATORS_HPP


#include <Math3D/Core/Structs/Matrix/Matrix.hpp>
#include <Math3D/Global.hpp>


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
template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>
operator+(const Matrix<M,N,T>& matrix, TScalar scalar);

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
template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>&
operator+=(Matrix<M,N,T>& matrix, TScalar scalar);

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
template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>
operator-(const Matrix<M,N,T>& matrix, TScalar scalar);

/**
 * Subtract scalar from each matrix component.
 * @param matrix Matrix to subtract from.
 * @param scalar Value to subtract.
 * @return The result of subtraction.
 */
template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>&
operator-=(Matrix<M,N,T>& matrix, TScalar scalar);

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
template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>
operator*(const Matrix<M,N,T>& matrix, TScalar scalar);

/**
 * Multiply scalar to each matrix component and return copy.
 * @param matrix Matrix to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>
operator*(TScalar scalar, const Matrix<M,N,T>& matrix);

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
template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>&
operator*=(Matrix<M,N,T>& matrix, TScalar scalar);

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
template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>
operator/(const Matrix<M,N,T>& matrix, TScalar scalar);

/**
 * Divide each matrix component by a scalar and return copy.
 * @param matrix Matrix to division to.
 * @param scalar Value to division.
 * @return The result of division.
 */
template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>&
operator/=(Matrix<M,N,T>& matrix, TScalar scalar);

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
    if constexpr (M == 2 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);
        ++matrix(1,0);  ++matrix(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);  
        ++matrix(1,0);  ++matrix(1,1);
        ++matrix(2,0);  ++matrix(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);  ++matrix(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);  
        ++matrix(1,0);  ++matrix(1,1);
        ++matrix(2,0);  ++matrix(2,1);
        ++matrix(3,0);  ++matrix(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);
        ++matrix(3,0);  ++matrix(3,1);  ++matrix(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);  ++matrix(2,3);
        ++matrix(3,0);  ++matrix(3,1);  ++matrix(3,2);  ++matrix(3,3);
    } 
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) ++(matrix[i]);        
    }

    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator--(Matrix<M,N,T>& matrix)
{
    if constexpr (M == 2 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);
        --matrix(1,0);  --matrix(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);  
        --matrix(1,0);  --matrix(1,1);
        --matrix(2,0);  --matrix(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);  --matrix(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);  
        --matrix(1,0);  --matrix(1,1);
        --matrix(2,0);  --matrix(2,1);
        --matrix(3,0);  --matrix(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);
        --matrix(3,0);  --matrix(3,1);  --matrix(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);  --matrix(2,3);
        --matrix(3,0);  --matrix(3,1);  --matrix(3,2);  --matrix(3,3);
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) --(matrix[i]);
    }

    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator++(Matrix<M,N,T>& matrix, int)
{
    Matrix<M,N,T> copy {matrix};

    if constexpr (M == 2 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);
        ++matrix(1,0);  ++matrix(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);
        ++matrix(1,0);  ++matrix(1,1);
        ++matrix(2,0);  ++matrix(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);  ++matrix(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);
        ++matrix(1,0);  ++matrix(1,1);
        ++matrix(2,0);  ++matrix(2,1);
        ++matrix(3,0);  ++matrix(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);
        ++matrix(3,0);  ++matrix(3,1);  ++matrix(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);  ++matrix(2,3);
        ++matrix(3,0);  ++matrix(3,1);  ++matrix(3,2);  ++matrix(3,3);
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) ++(matrix[i]);
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator--(Matrix<M,N,T>& matrix, int)
{
    Matrix<M,N,T> copy {matrix};

    if constexpr (M == 2 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);
        --matrix(1,0);  --matrix(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);
        --matrix(1,0);  --matrix(1,1);
        --matrix(2,0);  --matrix(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);  --matrix(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);
        --matrix(1,0);  --matrix(1,1);
        --matrix(2,0);  --matrix(2,1);
        --matrix(3,0);  --matrix(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);
        --matrix(3,0);  --matrix(3,1);  --matrix(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);  --matrix(2,3);
        --matrix(3,0);  --matrix(3,1);  --matrix(3,2);  --matrix(3,3);
    } 
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) --(matrix[i]);
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Plus */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator+(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return Matrix<M,N,T>
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),
            A(1,0)+B(1,0),  A(1,1)+B(1,1)
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return Matrix<M,N,T>
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2)
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return Matrix<M,N,T>
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),  A(0,3)+B(0,3),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2),  A(1,3)+B(1,3)
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return Matrix<M,N,T>
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),
            A(2,0)+B(2,0),  A(2,1)+B(2,1)
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return Matrix<M,N,T>
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2),
            A(2,0)+B(2,0),  A(2,1)+B(2,1),  A(2,2)+B(2,2)
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return Matrix<M,N,T>
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),  A(0,3)+B(0,3),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2),  A(1,3)+B(1,3),
            A(2,0)+B(2,0),  A(2,1)+B(2,1),  A(2,2)+B(2,2),  A(2,3)+B(2,3)
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return Matrix<M,N,T>
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),
            A(2,0)+B(2,0),  A(2,1)+B(2,1),
            A(3,0)+B(3,0),  A(3,1)+B(3,1)
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return Matrix<M,N,T>
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2),
            A(2,0)+B(2,0),  A(2,1)+B(2,1),  A(2,2)+B(2,2),
            A(3,0)+B(3,0),  A(3,1)+B(3,1),  A(3,2)+B(3,2)
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return Matrix<M,N,T>
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),  A(0,3)+B(0,3),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2),  A(1,3)+B(1,3),
            A(2,0)+B(2,0),  A(2,1)+B(2,1),  A(2,2)+B(2,2),  A(2,3)+B(2,3),
            A(3,0)+B(3,0),  A(3,1)+B(3,1),  A(3,2)+B(3,2),  A(3,3)+B(3,3)
        };
    }
    else
    {
        Matrix<M,N,T> result;
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i)
        {
            result[i] = A[i] + B[i];
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>
operator+(const Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value,
            matrix(2,0)+value,  matrix(2,1)+value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,  matrix(2,3)+value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value,
            matrix(2,0)+value,  matrix(2,1)+value,
            matrix(3,0)+value,  matrix(3,1)+value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,
            matrix(3,0)+value,  matrix(3,1)+value,  matrix(3,2)+value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,  matrix(2,3)+value,
            matrix(3,0)+value,  matrix(3,1)+value,  matrix(3,2)+value,  matrix(3,3)+value
        };
    }
    else
    {
        Matrix<M,N,T> result {matrix};
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i)
        {
            result[i] += value;
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator+(T scalar, const Matrix<M,N,T>& matrix)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value,
            matrix(2,0)+value,  matrix(2,1)+value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,  matrix(2,3)+value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value,
            matrix(2,0)+value,  matrix(2,1)+value,
            matrix(3,0)+value,  matrix(3,1)+value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,
            matrix(3,0)+value,  matrix(3,1)+value,  matrix(3,2)+value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,  matrix(2,3)+value,
            matrix(3,0)+value,  matrix(3,1)+value,  matrix(3,2)+value,  matrix(3,3)+value
        };
    }
    else
    {
        Matrix<M,N,T> result {matrix};
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i)
        {
            result[i] += value;
        }
        return result;
    } 
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>&
operator+=(Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;  matrix(0,3)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;  matrix(1,3)+=value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;  matrix(2,2)+=value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;  matrix(0,3)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;  matrix(1,3)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;  matrix(2,2)+=value;  matrix(2,3)+=value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;
        matrix(3,0)+=value;  matrix(3,1)+=value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;  matrix(2,2)+=value;
        matrix(3,0)+=value;  matrix(3,1)+=value;  matrix(3,2)+=value;
    }
    else if constexpr (M == 4 && N == 4)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;  matrix(0,3)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;  matrix(1,3)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;  matrix(2,2)+=value;  matrix(2,3)+=value;
        matrix(3,0)+=value;  matrix(3,1)+=value;  matrix(3,2)+=value;  matrix(3,3)+=value;
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) matrix[i] += value;
    }
    
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator+=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);  A(0,3)+=B(0,3);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);  A(1,3)+=B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);  A(2,2)+=B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);  A(0,3)+=B(0,3);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);  A(1,3)+=B(1,3);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);  A(2,2)+=B(2,2);  A(2,3)+=B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);
        A(3,0)+=B(3,0);  A(3,1)+=B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);  A(2,2)+=B(2,2);
        A(3,0)+=B(3,0);  A(3,1)+=B(3,1);  A(3,2)+=B(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);  A(0,3)+=B(0,3);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);  A(1,3)+=B(1,3);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);  A(2,2)+=B(2,2);  A(2,3)+=B(2,3);
        A(3,0)+=B(3,0);  A(3,1)+=B(3,1);  A(3,2)+=B(3,2);  A(3,3)+=B(3,3);
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) A[i] += B[i];
    }
    
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Minus */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator-(const Matrix<M,N,T>& matrix)
{
    if constexpr (M == 2 && N == 2)
    {
        return Matrix<M,N,T>
        {
            -matrix(0,0),  -matrix(0,1),
            -matrix(1,0),  -matrix(1,1)
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return Matrix<M,N,T>
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2)
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return Matrix<M,N,T>
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),  -matrix(0,3),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2),  -matrix(1,3)
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return Matrix<M,N,T>
        {
            -matrix(0,0),  -matrix(0,1),
            -matrix(1,0),  -matrix(1,1),
            -matrix(2,0),  -matrix(2,1)
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return Matrix<M,N,T>
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2),
            -matrix(2,0),  -matrix(2,1),  -matrix(2,2)
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return Matrix<M,N,T>
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),  -matrix(0,3),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2),  -matrix(1,3),
            -matrix(2,0),  -matrix(2,1),  -matrix(2,2),  -matrix(2,3)
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return Matrix<M,N,T>
        {
            -matrix(0,0),  -matrix(0,1),
            -matrix(1,0),  -matrix(1,1),
            -matrix(2,0),  -matrix(2,1),
            -matrix(3,0),  -matrix(3,1)
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return Matrix<M,N,T>
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2),
            -matrix(2,0),  -matrix(2,1),  -matrix(2,2),
            -matrix(3,0),  -matrix(3,1),  -matrix(3,2)
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return Matrix<M,N,T>
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),  -matrix(0,3),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2),  -matrix(1,3),
            -matrix(2,0),  -matrix(2,1),  -matrix(2,2),  -matrix(2,3),
            -matrix(3,0),  -matrix(3,1),  -matrix(3,2),  -matrix(3,3)
        };
    }
    else
    {
        Matrix<M,N,T> result;
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i)
        {
            result[i] = -matrix[i];
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator-(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return Matrix<M,N,T>
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),
            A(1,0)-B(1,0),  A(1,1)-B(1,1)
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return Matrix<M,N,T>
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2)
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return Matrix<M,N,T>
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),  A(0,3)-B(0,3),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2),  A(1,3)-B(1,3)
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return Matrix<M,N,T>
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),
            A(2,0)-B(2,0),  A(2,1)-B(2,1)
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return Matrix<M,N,T>
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2),
            A(2,0)-B(2,0),  A(2,1)-B(2,1),  A(2,2)-B(2,2)
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return Matrix<M,N,T>
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),  A(0,3)-B(0,3),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2),  A(1,3)-B(1,3),
            A(2,0)-B(2,0),  A(2,1)-B(2,1),  A(2,2)-B(2,2),  A(2,3)-B(2,3)
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return Matrix<M,N,T>
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),
            A(2,0)-B(2,0),  A(2,1)-B(2,1),
            A(3,0)-B(3,0),  A(3,1)-B(3,1)
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return Matrix<M,N,T>
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2),
            A(2,0)-B(2,0),  A(2,1)-B(2,1),  A(2,2)-B(2,2),
            A(3,0)-B(3,0),  A(3,1)-B(3,1),  A(3,2)-B(3,2)
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return Matrix<M,N,T>
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),  A(0,3)-B(0,3),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2),  A(1,3)-B(1,3),
            A(2,0)-B(2,0),  A(2,1)-B(2,1),  A(2,2)-B(2,2),  A(2,3)-B(2,3),
            A(3,0)-B(3,0),  A(3,1)-B(3,1),  A(3,2)-B(3,2),  A(3,3)-B(3,3)
        };
    }
    else
    {
        Matrix<M,N,T> result;
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i)
        {
            result[i] = A[i] - B[i];
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>
operator-(const Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)-value,  matrix(0,1)-value,
            matrix(1,0)-value,  matrix(1,1)-value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,  matrix(0,3)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value,  matrix(1,3)-value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)-value,  matrix(0,1)-value,
            matrix(1,0)-value,  matrix(1,1)-value,
            matrix(2,0)-value,  matrix(2,1)-value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value,
            matrix(2,0)-value,  matrix(2,1)-value,  matrix(2,2)-value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,  matrix(0,3)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value,  matrix(1,3)-value,
            matrix(2,0)-value,  matrix(2,1)-value,  matrix(2,2)-value,  matrix(2,3)-value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)-value,  matrix(0,1)-value,
            matrix(1,0)-value,  matrix(1,1)-value,
            matrix(2,0)-value,  matrix(2,1)-value,
            matrix(3,0)-value,  matrix(3,1)-value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value,
            matrix(2,0)-value,  matrix(2,1)-value,  matrix(2,2)-value,
            matrix(3,0)-value,  matrix(3,1)-value,  matrix(3,2)-value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,  matrix(0,3)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value,  matrix(1,3)-value,
            matrix(2,0)-value,  matrix(2,1)-value,  matrix(2,2)-value,  matrix(2,3)-value,
            matrix(3,0)-value,  matrix(3,1)-value,  matrix(3,2)-value,  matrix(3,3)-value
        };
    }
    else
    {
        Matrix<M,N,T> result;
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i)
        {
            result[i] = matrix[i] - value;
        }
        return result;
    } 
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>&
operator-=(Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;  matrix(0,3)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;  matrix(1,3)-=value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;  matrix(2,2)-=value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;  matrix(0,3)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;  matrix(1,3)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;  matrix(2,2)-=value;  matrix(2,3)-=value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;
        matrix(3,0)-=value;  matrix(3,1)-=value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;  matrix(2,2)-=value;
        matrix(3,0)-=value;  matrix(3,1)-=value;  matrix(3,2)-=value;
    }
    else if constexpr (M == 4 && N == 4)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;  matrix(0,3)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;  matrix(1,3)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;  matrix(2,2)-=value;  matrix(2,3)-=value;
        matrix(3,0)-=value;  matrix(3,1)-=value;  matrix(3,2)-=value;  matrix(3,3)-=value;
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) matrix[i] -= value;
    }
    
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator-=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);  A(0,3)-=B(0,3);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);  A(1,3)-=B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);  A(2,2)-=B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);  A(0,3)-=B(0,3);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);  A(1,3)-=B(1,3);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);  A(2,2)-=B(2,2);  A(2,3)-=B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);
        A(3,0)-=B(3,0);  A(3,1)-=B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);  A(2,2)-=B(2,2);
        A(3,0)-=B(3,0);  A(3,1)-=B(3,1);  A(3,2)-=B(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);  A(0,3)-=B(0,3);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);  A(1,3)-=B(1,3);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);  A(2,2)-=B(2,2);  A(2,3)-=B(2,3);
        A(3,0)-=B(3,0);  A(3,1)-=B(3,1);  A(3,2)-=B(3,2);  A(3,3)-=B(3,3);
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) A[i] -= B[i];
    }

    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Multiplication */
/* ####################################################################################### */


/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>
operator*(const Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value,
            matrix(2,0)*value,  matrix(2,1)*value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,  matrix(2,3)*value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value,
            matrix(2,0)*value,  matrix(2,1)*value,
            matrix(3,0)*value,  matrix(3,1)*value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,
            matrix(3,0)*value,  matrix(3,1)*value,  matrix(3,2)*value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,  matrix(2,3)*value,
            matrix(3,0)*value,  matrix(3,1)*value,  matrix(3,2)*value,  matrix(3,3)*value
        };
    }
    else
    {
        Matrix<M,N,T> result {matrix};
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i)
        {
            result[i] *= value;
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>
operator*(TScalar scalar, const Matrix<M,N,T>& matrix)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value,
            matrix(2,0)*value,  matrix(2,1)*value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,  matrix(2,3)*value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value,
            matrix(2,0)*value,  matrix(2,1)*value,
            matrix(3,0)*value,  matrix(3,1)*value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,
            matrix(3,0)*value,  matrix(3,1)*value,  matrix(3,2)*value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,  matrix(2,3)*value,
            matrix(3,0)*value,  matrix(3,1)*value,  matrix(3,2)*value,  matrix(3,3)*value
        };
    }
    else
    {
        Matrix<M,N,T> result {matrix};
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i)
        {
            result[i] *= value;
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t AM, size_t AN, size_t BN, typename T>
constexpr Matrix<AM,BN,T>
operator*(const Matrix<AM,AN,T>& A, const Matrix<AN,BN,T>& B)
{
    // 2x2 * 2x2 -> 2x2
    if constexpr (AM == 2 && AN == 2 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1)
        };
    }

    // 2x2 * 2x3 -> 2x3
    if constexpr (AM == 2 && AN == 2 && BN == 3)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2)
        };
    }

    // 2x2 * 2x4 -> 2x4
    if constexpr (AM == 2 && AN == 2 && BN == 4)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3)
        };
    }

    // 2x3 * 3x2 -> 2x2
    if constexpr (AM == 2 && AN == 3 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1)
        };
    }

    // 2x3 * 3x3 -> 2x3
    if constexpr (AM == 2 && AN == 3 && BN == 3)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2)
        };
    }

    // 2x3 * 3x4 -> 2x4
    if constexpr (AM == 2 && AN == 3 && BN == 4)
    {
        return Matrix<AM,BN,T>
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
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3)
        };
    }

    // 2x3 * 3x2 -> 2x2
    if constexpr (AM == 2 && AN == 3 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1)
        };
    }

    // 2x3 * 3x3 -> 2x3
    if constexpr (AM == 2 && AN == 3 && BN == 3)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2)
        };
    }

    // 2x3 * 3x4 -> 2x4
    if constexpr (AM == 2 && AN == 3 && BN == 4)
    {
        return Matrix<AM,BN,T>
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
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3)
        };
    }

    // 2x4 * 4x2 -> 2x2
    if constexpr (AM == 2 && AN == 4 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1)
        };
    }

    // 2x4 * 4x3 -> 2x3
    if constexpr (AM == 2 && AN == 4 && BN == 3)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2)
        };
    }

    // 2x4 * 4x4 -> 2x4
    if constexpr (AM == 2 && AN == 4 && BN == 4)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3) + A(0,3)*B(3,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3) + A(1,3)*B(3,3)
        };
    }

    // 3x2 * 2x2 -> 3x2
    if constexpr (AM == 3 && AN == 2 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1)
        };
    }

    // 3x2 * 2x3 -> 3x3
    if constexpr (AM == 3 && AN == 2 && BN == 3)
    {
        return Matrix<AM,BN,T>
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
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2)
        };
    }

    // 3x2 * 2x4 -> 3x4
    if constexpr (AM == 3 && AN == 2 && BN == 4)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3)
        };
    }

    // 3x3 * 3x2 -> 3x2
    if constexpr (AM == 3 && AN == 3 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1)
        };
    }

    // 3x3 * 3x3 -> 3x3
    if constexpr (AM == 3 && AN == 3 && BN == 3)
    {
        return Matrix<AM,BN,T>
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

    // 3x3 * 3x4 -> 3x4
    if constexpr (AM == 3 && AN == 3 && BN == 4)
    {
        return Matrix<AM,BN,T>
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
            A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3)
        };
    }

    // 3x3 * 3x2 -> 3x2
    if constexpr (AM == 3 && AN == 3 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1)
        };
    }

    // 3x3 * 3x3 -> 3x3
    if constexpr (AM == 3 && AN == 3 && BN == 3)
    {
        return Matrix<AM,BN,T>
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

    // 3x3 * 3x4 -> 3x4
    if constexpr (AM == 3 && AN == 3 && BN == 4)
    {
        return Matrix<AM,BN,T>
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
            A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3)
        };
    }

    // 3x4 * 4x2 -> 3x2
    if constexpr (AM == 3 && AN == 4 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1)
        };
    }

    // 3x4 * 4x3 -> 3x3
    if constexpr (AM == 3 && AN == 4 && BN == 3)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2) + A(2,3)*B(3,2)
        };
    }

    // 3x4 * 4x4 -> 3x4
    if constexpr (AM == 3 && AN == 4 && BN == 4)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3) + A(0,3)*B(3,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3) + A(1,3)*B(3,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2) + A(2,3)*B(3,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3) + A(2,3)*B(3,3)
        };
    }

    // 4x2 * 2x2 -> 4x2
    if constexpr (AM == 4 && AN == 2 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1)
        };
    }

    // 4x2 * 2x3 -> 4x3
    if constexpr (AM == 4 && AN == 2 && BN == 3)
    {
        return Matrix<AM,BN,T>
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
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2)
        };
    }

    // 4x2 * 2x4 -> 4x4
    if constexpr (AM == 4 && AN == 2 && BN == 4)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2),
            A(3,0)*B(0,3) + A(3,1)*B(1,3)
        };
    }

    // 4x3 * 3x2 -> 4x2
    if constexpr (AM == 4 && AN == 3 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1)
        };
    }

    // 4x3 * 3x3 -> 4x3
    if constexpr (AM == 4 && AN == 3 && BN == 3)
    {
        return Matrix<AM,BN,T>
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
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2)
        };
    }

    // 4x3 * 3x4 -> 4x4
    if constexpr (AM == 4 && AN == 3 && BN == 4)
    {
        return Matrix<AM,BN,T>
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
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2),
            A(3,0)*B(0,3) + A(3,1)*B(1,3) + A(3,2)*B(2,3)
        };
    }

    // 4x3 * 3x2 -> 4x2
    if constexpr (AM == 4 && AN == 3 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1)
        };
    }

    // 4x3 * 3x3 -> 4x3
    if constexpr (AM == 4 && AN == 3 && BN == 3)
    {
        return Matrix<AM,BN,T>
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
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2)
        };
    }

    // 4x3 * 3x4 -> 4x4
    if constexpr (AM == 4 && AN == 3 && BN == 4)
    {
        return Matrix<AM,BN,T>
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
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2),
            A(3,0)*B(0,3) + A(3,1)*B(1,3) + A(3,2)*B(2,3)
        };
    }

    // 4x4 * 4x2 -> 4x2
    if constexpr (AM == 4 && AN == 4 && BN == 2)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0) + A(3,3)*B(3,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1) + A(3,3)*B(3,1)
        };
    }

    // 4x4 * 4x3 -> 4x3
    if constexpr (AM == 4 && AN == 4 && BN == 3)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2) + A(2,3)*B(3,2),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0) + A(3,3)*B(3,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1) + A(3,3)*B(3,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2) + A(3,3)*B(3,2)
        };
    }

    // 4x4 * 4x4 -> 4x4
    if constexpr (AM == 4 && AN == 4 && BN == 4)
    {
        return Matrix<AM,BN,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3) + A(0,3)*B(3,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3) + A(1,3)*B(3,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2) + A(2,3)*B(3,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3) + A(2,3)*B(3,3),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0) + A(3,3)*B(3,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1) + A(3,3)*B(3,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2) + A(3,3)*B(3,2),
            A(3,0)*B(0,3) + A(3,1)*B(1,3) + A(3,2)*B(2,3) + A(3,3)*B(3,3)
        };
    }

    if constexpr (AM > 4 && AN > 4 && BN > 4)
    {
        Matrix<AM,BN,T> result;
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
                result(r,c) = sum;
            }
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>&
operator*=(Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;  matrix(0,3)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;  matrix(1,3)*=value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;  matrix(2,2)*=value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;  matrix(0,3)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;  matrix(1,3)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;  matrix(2,2)*=value;  matrix(2,3)*=value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;
        matrix(3,0)*=value;  matrix(3,1)*=value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;  matrix(2,2)*=value;
        matrix(3,0)*=value;  matrix(3,1)*=value;  matrix(3,2)*=value;
    }
    else if constexpr (M == 4 && N == 4)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;  matrix(0,3)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;  matrix(1,3)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;  matrix(2,2)*=value;  matrix(2,3)*=value;
        matrix(3,0)*=value;  matrix(3,1)*=value;  matrix(3,2)*=value;  matrix(3,3)*=value;
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) matrix[i] *= value;
    }
    
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr Matrix<S,S,T>&
operator*=(Matrix<S,S,T>& A, const Matrix<S,S,T>& B)
{
    Matrix<S,S,T> result;

    if constexpr (S== 2)
    {
        A = Matrix<S,S,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1)
        };
    }
    else if constexpr (S == 3)
    {
        A = Matrix<S,S,T>
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
    else if constexpr (S == 4)
    {
        A = Matrix<S,S,T>
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3) + A(0,3)*B(3,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3) + A(1,3)*B(3,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2) + A(2,3)*B(3,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3) + A(2,3)*B(3,3),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0) + A(3,3)*B(3,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1) + A(3,3)*B(3,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2) + A(3,3)*B(3,2),
            A(3,0)*B(0,3) + A(3,1)*B(1,3) + A(3,2)*B(2,3) + A(3,3)*B(3,3)
        };
    }
    else
    {
        typename Matrix<S,S,T>::value_type sum;
    
        for (auto c = 0; c < S; ++c)
        {
            for (auto r = 0; r < S; ++r)
            {
                sum = typename Matrix<S,S,T>::value_type(0);
                for (auto i = 0; i < S; ++i)
                {
                    sum += A(r,i) * B(i,c);
                }
                result(r,c) = sum;
            }
        }
        A = result;
        return A;
    }
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise division */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>
operator/(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return Matrix<M,N,T>
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),
            A(1,0)/B(1,0),  A(1,1)/B(1,1)
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return Matrix<M,N,T>
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2)
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return Matrix<M,N,T>
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),  A(0,3)/B(0,3),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2),  A(1,3)/B(1,3)
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return Matrix<M,N,T>
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),
            A(2,0)/B(2,0),  A(2,1)/B(2,1)
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return Matrix<M,N,T>
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2),
            A(2,0)/B(2,0),  A(2,1)/B(2,1),  A(2,2)/B(2,2)
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return Matrix<M,N,T>
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),  A(0,3)/B(0,3),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2),  A(1,3)/B(1,3),
            A(2,0)/B(2,0),  A(2,1)/B(2,1),  A(2,2)/B(2,2),  A(2,3)/B(2,3)
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return Matrix<M,N,T>
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),
            A(2,0)/B(2,0),  A(2,1)/B(2,1),
            A(3,0)/B(3,0),  A(3,1)/B(3,1)
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return Matrix<M,N,T>
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2),
            A(2,0)/B(2,0),  A(2,1)/B(2,1),  A(2,2)/B(2,2),
            A(3,0)/B(3,0),  A(3,1)/B(3,1),  A(3,2)/B(3,2)
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return Matrix<M,N,T>
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),  A(0,3)/B(0,3),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2),  A(1,3)/B(1,3),
            A(2,0)/B(2,0),  A(2,1)/B(2,1),  A(2,2)/B(2,2),  A(2,3)/B(2,3),
            A(3,0)/B(3,0),  A(3,1)/B(3,1),  A(3,2)/B(3,2),  A(3,3)/B(3,3)
        };
    }
    else
    {
        Matrix<M,N,T> result;
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i)
        {
            result[i] = A[i] / B[i];
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>
operator/(const Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)/value,  matrix(0,1)/value,
            matrix(1,0)/value,  matrix(1,1)/value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,  matrix(0,3)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value,  matrix(1,3)/value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)/value,  matrix(0,1)/value,
            matrix(1,0)/value,  matrix(1,1)/value,
            matrix(2,0)/value,  matrix(2,1)/value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value,
            matrix(2,0)/value,  matrix(2,1)/value,  matrix(2,2)/value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,  matrix(0,3)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value,  matrix(1,3)/value,
            matrix(2,0)/value,  matrix(2,1)/value,  matrix(2,2)/value,  matrix(2,3)/value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)/value,  matrix(0,1)/value,
            matrix(1,0)/value,  matrix(1,1)/value,
            matrix(2,0)/value,  matrix(2,1)/value,
            matrix(3,0)/value,  matrix(3,1)/value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value,
            matrix(2,0)/value,  matrix(2,1)/value,  matrix(2,2)/value,
            matrix(3,0)/value,  matrix(3,1)/value,  matrix(3,2)/value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return Matrix<M,N,T>
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,  matrix(0,3)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value,  matrix(1,3)/value,
            matrix(2,0)/value,  matrix(2,1)/value,  matrix(2,2)/value,  matrix(2,3)/value,
            matrix(3,0)/value,  matrix(3,1)/value,  matrix(3,2)/value,  matrix(3,3)/value
        };
    }
    else
    {
        Matrix<M,N,T> result;
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i)
        {
            result[i] = matrix[i] / value;
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr Matrix<M,N,T>&
operator/=(Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;  matrix(0,3)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;  matrix(1,3)/=value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;  matrix(2,2)/=value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;  matrix(0,3)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;  matrix(1,3)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;  matrix(2,2)/=value;  matrix(2,3)/=value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;
        matrix(3,0)/=value;  matrix(3,1)/=value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;  matrix(2,2)/=value;
        matrix(3,0)/=value;  matrix(3,1)/=value;  matrix(3,2)/=value;
    }
    else if constexpr (M == 4 && N == 4)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;  matrix(0,3)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;  matrix(1,3)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;  matrix(2,2)/=value;  matrix(2,3)/=value;
        matrix(3,0)/=value;  matrix(3,1)/=value;  matrix(3,2)/=value;  matrix(3,3)/=value;
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) matrix[i] /= value;
    }
    
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
operator/=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);  A(0,3)/=B(0,3);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);  A(1,3)/=B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);  A(2,2)/=B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);  A(0,3)/=B(0,3);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);  A(1,3)/=B(1,3);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);  A(2,2)/=B(2,2);  A(2,3)/=B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);
        A(3,0)/=B(3,0);  A(3,1)/=B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);  A(2,2)/=B(2,2);
        A(3,0)/=B(3,0);  A(3,1)/=B(3,1);  A(3,2)/=B(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);  A(0,3)/=B(0,3);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);  A(1,3)/=B(1,3);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);  A(2,2)/=B(2,2);  A(2,3)/=B(2,3);
        A(3,0)/=B(3,0);  A(3,1)/=B(3,1);  A(3,2)/=B(3,2);  A(3,3)/=B(3,3);
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) A[i] /= B[i];
    }
    
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with scalar */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr bool
operator==(const Matrix<M,N,T>& matrix, T scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        return
        equal(matrix(0,0),value) &&
        equal(matrix(0,1),value) &&
        equal(matrix(1,0),value) &&
        equal(matrix(1,1),value);
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        equal(matrix(0,0),value) &&
        equal(matrix(0,1),value) &&
        equal(matrix(0,2),value) &&
        equal(matrix(1,0),value) &&
        equal(matrix(1,1),value) &&
        equal(matrix(1,2),value);
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        equal(matrix(0,0),value) &&
        equal(matrix(0,1),value) &&
        equal(matrix(0,2),value) &&
        equal(matrix(0,3),value) &&
        equal(matrix(1,0),value) &&
        equal(matrix(1,1),value) &&
        equal(matrix(1,2),value) &&
        equal(matrix(1,3),value);
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        equal(matrix(0,0),value) &&
        equal(matrix(1,0),value) &&
        equal(matrix(2,0),value) &&
        equal(matrix(0,1),value) &&
        equal(matrix(1,1),value) &&
        equal(matrix(2,1),value);
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        equal(matrix(0,0),value) &&
        equal(matrix(0,1),value) &&
        equal(matrix(0,2),value) &&
        equal(matrix(1,0),value) &&
        equal(matrix(1,1),value) &&
        equal(matrix(1,2),value) &&
        equal(matrix(2,0),value) &&
        equal(matrix(2,1),value) &&
        equal(matrix(2,2),value);
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        equal(matrix(0,0),value) &&
        equal(matrix(0,1),value) &&
        equal(matrix(0,2),value) &&
        equal(matrix(0,3),value) &&
        equal(matrix(1,0),value) &&
        equal(matrix(1,1),value) &&
        equal(matrix(1,2),value) &&
        equal(matrix(1,3),value) &&
        equal(matrix(2,0),value) &&
        equal(matrix(2,1),value) &&
        equal(matrix(2,2),value) &&
        equal(matrix(2,3),value);
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        equal(matrix(0,0),value) &&
        equal(matrix(0,1),value) &&
        equal(matrix(1,0),value) &&
        equal(matrix(1,1),value) &&
        equal(matrix(2,0),value) &&
        equal(matrix(2,1),value) &&
        equal(matrix(3,0),value) &&
        equal(matrix(3,1),value);
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        equal(matrix(0,0),value) &&
        equal(matrix(0,1),value) &&
        equal(matrix(0,2),value) &&
        equal(matrix(1,0),value) &&
        equal(matrix(1,1),value) &&
        equal(matrix(1,2),value) &&
        equal(matrix(2,0),value) &&
        equal(matrix(2,1),value) &&
        equal(matrix(2,2),value) &&
        equal(matrix(3,0),value) &&
        equal(matrix(3,1),value) &&
        equal(matrix(3,2),value);
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        equal(matrix(0,0),value) &&
        equal(matrix(0,1),value) &&
        equal(matrix(0,2),value) &&
        equal(matrix(0,3),value) &&
        equal(matrix(1,0),value) &&
        equal(matrix(1,1),value) &&
        equal(matrix(1,2),value) &&
        equal(matrix(1,3),value) &&
        equal(matrix(2,0),value) &&
        equal(matrix(2,1),value) &&
        equal(matrix(2,2),value) &&
        equal(matrix(2,3),value) &&
        equal(matrix(3,0),value) &&
        equal(matrix(3,1),value) &&
        equal(matrix(3,2),value) &&
        equal(matrix(3,3),value);
    } 
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (notEqual(matrix[i], scalar)) return false;
        return true;   
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator!=(const Matrix<M,N,T>& matrix, T scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        return
        notEqual(matrix(0,0),value) ||
        notEqual(matrix(0,1),value) ||
        notEqual(matrix(1,0),value) ||
        notEqual(matrix(1,1),value);
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        notEqual(matrix(0,0),value) ||
        notEqual(matrix(0,1),value) ||
        notEqual(matrix(0,2),value) ||
        notEqual(matrix(1,0),value) ||
        notEqual(matrix(1,1),value) ||
        notEqual(matrix(1,2),value);
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        notEqual(matrix(0,0),value) ||
        notEqual(matrix(0,1),value) ||
        notEqual(matrix(0,2),value) ||
        notEqual(matrix(0,3),value) ||
        notEqual(matrix(1,0),value) ||
        notEqual(matrix(1,1),value) ||
        notEqual(matrix(1,2),value) ||
        notEqual(matrix(1,3),value);
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        notEqual(matrix(0,0),value) ||
        notEqual(matrix(1,0),value) ||
        notEqual(matrix(2,0),value) ||
        notEqual(matrix(0,1),value) ||
        notEqual(matrix(1,1),value) ||
        notEqual(matrix(2,1),value);
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        notEqual(matrix(0,0),value) ||
        notEqual(matrix(0,1),value) ||
        notEqual(matrix(0,2),value) ||
        notEqual(matrix(1,0),value) ||
        notEqual(matrix(1,1),value) ||
        notEqual(matrix(1,2),value) ||
        notEqual(matrix(2,0),value) ||
        notEqual(matrix(2,1),value) ||
        notEqual(matrix(2,2),value);
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        notEqual(matrix(0,0),value) ||
        notEqual(matrix(0,1),value) ||
        notEqual(matrix(0,2),value) ||
        notEqual(matrix(0,3),value) ||
        notEqual(matrix(1,0),value) ||
        notEqual(matrix(1,1),value) ||
        notEqual(matrix(1,2),value) ||
        notEqual(matrix(1,3),value) ||
        notEqual(matrix(2,0),value) ||
        notEqual(matrix(2,1),value) ||
        notEqual(matrix(2,2),value) ||
        notEqual(matrix(2,3),value);
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        notEqual(matrix(0,0),value) ||
        notEqual(matrix(0,1),value) ||
        notEqual(matrix(1,0),value) ||
        notEqual(matrix(1,1),value) ||
        notEqual(matrix(2,0),value) ||
        notEqual(matrix(2,1),value) ||
        notEqual(matrix(3,0),value) ||
        notEqual(matrix(3,1),value);
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        notEqual(matrix(0,0),value) ||
        notEqual(matrix(0,1),value) ||
        notEqual(matrix(0,2),value) ||
        notEqual(matrix(1,0),value) ||
        notEqual(matrix(1,1),value) ||
        notEqual(matrix(1,2),value) ||
        notEqual(matrix(2,0),value) ||
        notEqual(matrix(2,1),value) ||
        notEqual(matrix(2,2),value) ||
        notEqual(matrix(3,0),value) ||
        notEqual(matrix(3,1),value) ||
        notEqual(matrix(3,2),value);
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        notEqual(matrix(0,0),value) ||
        notEqual(matrix(0,1),value) ||
        notEqual(matrix(0,2),value) ||
        notEqual(matrix(0,3),value) ||
        notEqual(matrix(1,0),value) ||
        notEqual(matrix(1,1),value) ||
        notEqual(matrix(1,2),value) ||
        notEqual(matrix(1,3),value) ||
        notEqual(matrix(2,0),value) ||
        notEqual(matrix(2,1),value) ||
        notEqual(matrix(2,2),value) ||
        notEqual(matrix(2,3),value) ||
        notEqual(matrix(3,0),value) ||
        notEqual(matrix(3,1),value) ||
        notEqual(matrix(3,2),value) ||
        notEqual(matrix(3,3),value);
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (notEqual(matrix[i], scalar)) return true;
        return false;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator<(const Matrix<M,N,T>& matrix, T scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        return
        matrix(0,0) < value && 
        matrix(0,1) < value &&
        matrix(1,0) < value && 
        matrix(1,1) < value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        matrix(0,0) < value && 
        matrix(0,1) < value && 
        matrix(0,2) < value &&
        matrix(1,0) < value && 
        matrix(1,1) < value && 
        matrix(1,2) < value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        matrix(0,0) < value && 
        matrix(0,1) < value && 
        matrix(0,2) < value && 
        matrix(0,3) < value &&
        matrix(1,0) < value && 
        matrix(1,1) < value && 
        matrix(1,2) < value && 
        matrix(1,3) < value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        matrix(0,0) < value && 
        matrix(0,1) < value &&
        matrix(1,0) < value && 
        matrix(1,1) < value &&
        matrix(2,0) < value && 
        matrix(2,1) < value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        matrix(0,0) < value && 
        matrix(0,1) < value && 
        matrix(0,2) < value &&
        matrix(1,0) < value && 
        matrix(1,1) < value && 
        matrix(1,2) < value &&
        matrix(2,0) < value && 
        matrix(2,1) < value && 
        matrix(2,2) < value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        matrix(0,0) < value && 
        matrix(0,1) < value && 
        matrix(0,2) < value && 
        matrix(0,3) < value &&
        matrix(1,0) < value && 
        matrix(1,1) < value && 
        matrix(1,2) < value && 
        matrix(1,3) < value &&
        matrix(2,0) < value && 
        matrix(2,1) < value && 
        matrix(2,2) < value && 
        matrix(2,3) < value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        matrix(0,0) < value && 
        matrix(0,1) < value &&
        matrix(1,0) < value && 
        matrix(1,1) < value &&
        matrix(2,0) < value && 
        matrix(2,1) < value &&
        matrix(3,0) < value && 
        matrix(3,1) < value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        matrix(0,0) < value &&
        matrix(0,1) < value && 
        matrix(0,2) < value &&
        matrix(1,0) < value && 
        matrix(1,1) < value && 
        matrix(1,2) < value &&
        matrix(2,0) < value && 
        matrix(2,1) < value && 
        matrix(2,2) < value &&
        matrix(3,0) < value && 
        matrix(3,1) < value && 
        matrix(3,2) < value; 
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        matrix(0,0) < value && 
        matrix(0,1) < value && 
        matrix(0,2) < value &&
        matrix(0,3) < value &&
        matrix(1,0) < value && 
        matrix(1,1) < value && 
        matrix(1,2) < value && 
        matrix(1,3) < value &&
        matrix(2,0) < value && 
        matrix(2,1) < value &&
        matrix(2,2) < value &&
        matrix(2,3) < value &&
        matrix(3,0) < value && 
        matrix(3,1) < value && 
        matrix(3,2) < value && 
        matrix(3,3) < value;
    } 
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (matrix[i] >= scalar) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator>(const Matrix<M,N,T>& matrix, T scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        return
        matrix(0,0) > value && 
        matrix(0,1) > value &&
        matrix(1,0) > value && 
        matrix(1,1) > value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        matrix(0,0) > value &&
        matrix(0,1) > value && 
        matrix(0,2) > value &&
        matrix(1,0) > value &&
        matrix(1,1) > value && 
        matrix(1,2) > value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        matrix(0,0) > value && 
        matrix(0,1) > value && 
        matrix(0,2) > value && 
        matrix(0,3) > value &&
        matrix(1,0) > value && 
        matrix(1,1) > value && 
        matrix(1,2) > value && 
        matrix(1,3) > value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        matrix(0,0) > value && 
        matrix(0,1) > value &&
        matrix(1,0) > value &&
        matrix(1,1) > value &&
        matrix(2,0) > value &&
        matrix(2,1) > value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        matrix(0,0) > value && 
        matrix(0,1) > value && 
        matrix(0,2) > value &&
        matrix(1,0) > value && 
        matrix(1,1) > value && 
        matrix(1,2) > value &&
        matrix(2,0) > value &&
        matrix(2,1) > value && 
        matrix(2,2) > value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        matrix(0,0) > value &&
        matrix(0,1) > value && 
        matrix(0,2) > value && 
        matrix(0,3) > value &&
        matrix(1,0) > value &&
        matrix(1,1) > value && 
        matrix(1,2) > value && 
        matrix(1,3) > value &&
        matrix(2,0) > value && 
        matrix(2,1) > value && 
        matrix(2,2) > value && 
        matrix(2,3) > value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        matrix(0,0) > value && 
        matrix(0,1) > value &&
        matrix(1,0) > value &&
        matrix(1,1) > value &&
        matrix(2,0) > value &&
        matrix(2,1) > value &&
        matrix(3,0) > value &&
        matrix(3,1) > value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        matrix(0,0) > value && 
        matrix(0,1) > value && 
        matrix(0,2) > value &&
        matrix(1,0) > value && 
        matrix(1,1) > value && 
        matrix(1,2) > value &&
        matrix(2,0) > value &&
        matrix(2,1) > value && 
        matrix(2,2) > value &&
        matrix(3,0) > value && 
        matrix(3,1) > value && 
        matrix(3,2) > value; 
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        matrix(0,0) > value && 
        matrix(0,1) > value && 
        matrix(0,2) > value && 
        matrix(0,3) > value &&
        matrix(1,0) > value && 
        matrix(1,1) > value && 
        matrix(1,2) > value && 
        matrix(1,3) > value &&
        matrix(2,0) > value && 
        matrix(2,1) > value && 
        matrix(2,2) > value && 
        matrix(2,3) > value &&
        matrix(3,0) > value && 
        matrix(3,1) > value && 
        matrix(3,2) > value && 
        matrix(3,3) > value;
    }
    else
    {
        for (auto i = 0; i < Matrix<M, N, T>::size; ++i) if (matrix[i] <= scalar) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator<=(const Matrix<M,N,T>& matrix, T scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        return
        matrix(0,0) <= value &&
        matrix(0,1) <= value &&
        matrix(1,0) <= value && 
        matrix(1,1) <= value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        matrix(0,0) <= value &&
        matrix(0,1) <= value && 
        matrix(0,2) <= value &&
        matrix(1,0) <= value && 
        matrix(1,1) <= value && 
        matrix(1,2) <= value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        matrix(0,0) <= value && 
        matrix(0,1) <= value && 
        matrix(0,2) <= value && 
        matrix(0,3) <= value &&
        matrix(1,0) <= value && 
        matrix(1,1) <= value &&
        matrix(1,2) <= value &&
        matrix(1,3) <= value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        matrix(0,0) <= value &&
        matrix(0,1) <= value &&
        matrix(1,0) <= value &&
        matrix(1,1) <= value &&
        matrix(2,0) <= value &&
        matrix(2,1) <= value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        matrix(0,0) <= value && 
        matrix(0,1) <= value &&
        matrix(0,2) <= value &&
        matrix(1,0) <= value && 
        matrix(1,1) <= value && 
        matrix(1,2) <= value &&
        matrix(2,0) <= value && 
        matrix(2,1) <= value && 
        matrix(2,2) <= value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        matrix(0,0) <= value &&
        matrix(0,1) <= value && 
        matrix(0,2) <= value && 
        matrix(0,3) <= value &&
        matrix(1,0) <= value && 
        matrix(1,1) <= value && 
        matrix(1,2) <= value && 
        matrix(1,3) <= value &&
        matrix(2,0) <= value && 
        matrix(2,1) <= value &&
        matrix(2,2) <= value && 
        matrix(2,3) <= value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        matrix(0,0) <= value &&
        matrix(0,1) <= value &&
        matrix(1,0) <= value && 
        matrix(1,1) <= value &&
        matrix(2,0) <= value && 
        matrix(2,1) <= value &&
        matrix(3,0) <= value && 
        matrix(3,1) <= value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        matrix(0,0) <= value &&
        matrix(0,1) <= value && 
        matrix(0,2) <= value &&
        matrix(1,0) <= value && 
        matrix(1,1) <= value && 
        matrix(1,2) <= value &&
        matrix(2,0) <= value && 
        matrix(2,1) <= value && 
        matrix(2,2) <= value &&
        matrix(3,0) <= value && 
        matrix(3,1) <= value && 
        matrix(3,2) <= value; 
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        matrix(0,0) <= value && 
        matrix(0,1) <= value && 
        matrix(0,2) <= value && 
        matrix(0,3) <= value &&
        matrix(1,0) <= value && 
        matrix(1,1) <= value && 
        matrix(1,2) <= value && 
        matrix(1,3) <= value &&
        matrix(2,0) <= value && 
        matrix(2,1) <= value && 
        matrix(2,2) <= value && 
        matrix(2,3) <= value &&
        matrix(3,0) <= value &&
        matrix(3,1) <= value &&
        matrix(3,2) <= value &&
        matrix(3,3) <= value;
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (matrix[i] > scalar) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator>=(const Matrix<M,N,T>& matrix, T scalar)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return
        matrix(0,0) >= value &&
        matrix(0,1) >= value &&
        matrix(1,0) >= value && 
        matrix(1,1) >= value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        matrix(0,0) >= value && 
        matrix(0,1) >= value && 
        matrix(0,2) >= value &&
        matrix(1,0) >= value && 
        matrix(1,1) >= value && 
        matrix(1,2) >= value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        matrix(0,0) >= value && 
        matrix(0,1) >= value && 
        matrix(0,2) >= value && 
        matrix(0,3) >= value &&
        matrix(1,0) >= value && 
        matrix(1,1) >= value && 
        matrix(1,2) >= value && 
        matrix(1,3) >= value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        matrix(0,0) >= value && 
        matrix(0,1) >= value &&
        matrix(1,0) >= value && 
        matrix(1,1) >= value &&
        matrix(2,0) >= value && 
        matrix(2,1) >= value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        matrix(0,0) >= value && 
        matrix(0,1) >= value && 
        matrix(0,2) >= value &&
        matrix(1,0) >= value && 
        matrix(1,1) >= value && 
        matrix(1,2) >= value &&
        matrix(2,0) >= value && 
        matrix(2,1) >= value &&
        matrix(2,2) >= value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        matrix(0,0) >= value && 
        matrix(0,1) >= value && 
        matrix(0,2) >= value && 
        matrix(0,3) >= value &&
        matrix(1,0) >= value && 
        matrix(1,1) >= value && 
        matrix(1,2) >= value && 
        matrix(1,3) >= value &&
        matrix(2,0) >= value && 
        matrix(2,1) >= value && 
        matrix(2,2) >= value && 
        matrix(2,3) >= value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        matrix(0,0) >= value && 
        matrix(0,1) >= value &&
        matrix(1,0) >= value && 
        matrix(1,1) >= value &&
        matrix(2,0) >= value && 
        matrix(2,1) >= value &&
        matrix(3,0) >= value && 
        matrix(3,1) >= value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        matrix(0,0) >= value &&
        matrix(0,1) >= value && 
        matrix(0,2) >= value &&
        matrix(1,0) >= value && 
        matrix(1,1) >= value && 
        matrix(1,2) >= value &&
        matrix(2,0) >= value && 
        matrix(2,1) >= value && 
        matrix(2,2) >= value &&
        matrix(3,0) >= value && 
        matrix(3,1) >= value && 
        matrix(3,2) >= value; 
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        matrix(0,0) >= value &&
        matrix(0,1) >= value && 
        matrix(0,2) >= value && 
        matrix(0,3) >= value &&
        matrix(1,0) >= value && 
        matrix(1,1) >= value && 
        matrix(1,2) >= value && 
        matrix(1,3) >= value &&
        matrix(2,0) >= value && 
        matrix(2,1) >= value && 
        matrix(2,2) >= value && 
        matrix(2,3) >= value &&
        matrix(3,0) >= value && 
        matrix(3,1) >= value && 
        matrix(3,2) >= value && 
        matrix(3,3) >= value;
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (matrix[i] < scalar) return false;
        return true; 
    }
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with other */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr bool
operator==(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return
        equal(A(0,0), B(0,0)) &&
        equal(A(0,1), B(0,1)) &&
        equal(A(1,0), B(1,0)) &&
        equal(A(1,1), B(1,1));
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        equal(A(0,0), B(0,0)) &&
        equal(A(0,1), B(0,1)) &&
        equal(A(0,2), B(0,2)) &&
        equal(A(1,0), B(1,0)) &&
        equal(A(1,1), B(1,1)) &&
        equal(A(1,2), B(1,2));
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        equal(A(0,0), B(0,0)) &&
        equal(A(0,1), B(0,1)) &&
        equal(A(0,2), B(0,2)) &&
        equal(A(0,3), B(0,3)) &&
        equal(A(1,0), B(1,0)) &&
        equal(A(1,1), B(1,1)) &&
        equal(A(1,2), B(1,2)) &&
        equal(A(1,3), B(1,3));
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        equal(A(0,0), B(0,0)) &&
        equal(A(1,0), B(1,0)) &&
        equal(A(2,0), B(2,0)) &&
        equal(A(0,1), B(0,1)) &&
        equal(A(1,1), B(1,1)) &&
        equal(A(2,1), B(2,1));
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        equal(A(0,0), B(0,0)) &&
        equal(A(0,1), B(0,1)) &&
        equal(A(0,2), B(0,2)) &&
        equal(A(1,0), B(1,0)) &&
        equal(A(1,1), B(1,1)) &&
        equal(A(1,2), B(1,2)) &&
        equal(A(2,0), B(2,0)) &&
        equal(A(2,1), B(2,1)) &&
        equal(A(2,2), B(2,2));
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        equal(A(0,0), B(0,0)) &&
        equal(A(0,1), B(0,1)) &&
        equal(A(0,2), B(0,2)) &&
        equal(A(0,3), B(0,3)) &&
        equal(A(1,0), B(1,0)) &&
        equal(A(1,1), B(1,1)) &&
        equal(A(1,2), B(1,2)) &&
        equal(A(1,3), B(1,3)) &&
        equal(A(2,0), B(2,0)) &&
        equal(A(2,1), B(2,1)) &&
        equal(A(2,2), B(2,2)) &&
        equal(A(2,3), B(2,3));
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        equal(A(0,0), B(0,0)) &&
        equal(A(0,1), B(0,1)) &&
        equal(A(1,0), B(1,0)) &&
        equal(A(1,1), B(1,1)) &&
        equal(A(2,0), B(2,0)) &&
        equal(A(2,1), B(2,1)) &&
        equal(A(3,0), B(3,0)) &&
        equal(A(3,1), B(3,1));
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        equal(A(0,0), B(0,0)) &&
        equal(A(0,1), B(0,1)) &&
        equal(A(0,2), B(0,2)) &&
        equal(A(1,0), B(1,0)) &&
        equal(A(1,1), B(1,1)) &&
        equal(A(1,2), B(1,2)) &&
        equal(A(2,0), B(2,0)) &&
        equal(A(2,1), B(2,1)) &&
        equal(A(2,2), B(2,2)) &&
        equal(A(3,0), B(3,0)) &&
        equal(A(3,1), B(3,1)) &&
        equal(A(3,2), B(3,2));
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        equal(A(0,0), B(0,0)) &&
        equal(A(0,1), B(0,1)) &&
        equal(A(0,2), B(0,2)) &&
        equal(A(0,3), B(0,3)) &&
        equal(A(1,0), B(1,0)) &&
        equal(A(1,1), B(1,1)) &&
        equal(A(1,2), B(1,2)) &&
        equal(A(1,3), B(1,3)) &&
        equal(A(2,0), B(2,0)) &&
        equal(A(2,1), B(2,1)) &&
        equal(A(2,2), B(2,2)) &&
        equal(A(2,3), B(2,3)) &&
        equal(A(3,0), B(3,0)) &&
        equal(A(3,1), B(3,1)) &&
        equal(A(3,2), B(3,2)) &&
        equal(A(3,3), B(3,3));
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (notEqual(A[i], B[i])) return false;
        return true; 
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator!=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return
        notEqual(A(0,0), B(0,0)) ||
        notEqual(A(0,1), B(0,1)) ||
        notEqual(A(1,0), B(1,0)) ||
        notEqual(A(1,1), B(1,1));
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        notEqual(A(0,0), B(0,0)) ||
        notEqual(A(0,1), B(0,1)) ||
        notEqual(A(0,2), B(0,2)) ||
        notEqual(A(1,0), B(1,0)) ||
        notEqual(A(1,1), B(1,1)) ||
        notEqual(A(1,2), B(1,2));
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        notEqual(A(0,0), B(0,0)) ||
        notEqual(A(0,1), B(0,1)) ||
        notEqual(A(0,2), B(0,2)) ||
        notEqual(A(0,3), B(0,3)) ||
        notEqual(A(1,0), B(1,0)) ||
        notEqual(A(1,1), B(1,1)) ||
        notEqual(A(1,2), B(1,2)) ||
        notEqual(A(1,3), B(1,3));
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        notEqual(A(0,0), B(0,0)) ||
        notEqual(A(1,0), B(1,0)) ||
        notEqual(A(2,0), B(2,0)) ||
        notEqual(A(0,1), B(0,1)) ||
        notEqual(A(1,1), B(1,1)) ||
        notEqual(A(2,1), B(2,1));
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        notEqual(A(0,0), B(0,0)) ||
        notEqual(A(0,1), B(0,1)) ||
        notEqual(A(0,2), B(0,2)) ||
        notEqual(A(1,0), B(1,0)) ||
        notEqual(A(1,1), B(1,1)) ||
        notEqual(A(1,2), B(1,2)) ||
        notEqual(A(2,0), B(2,0)) ||
        notEqual(A(2,1), B(2,1)) ||
        notEqual(A(2,2), B(2,2));
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        notEqual(A(0,0), B(0,0)) ||
        notEqual(A(0,1), B(0,1)) ||
        notEqual(A(0,2), B(0,2)) ||
        notEqual(A(0,3), B(0,3)) ||
        notEqual(A(1,0), B(1,0)) ||
        notEqual(A(1,1), B(1,1)) ||
        notEqual(A(1,2), B(1,2)) ||
        notEqual(A(1,3), B(1,3)) ||
        notEqual(A(2,0), B(2,0)) ||
        notEqual(A(2,1), B(2,1)) ||
        notEqual(A(2,2), B(2,2)) ||
        notEqual(A(2,3), B(2,3));
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        notEqual(A(0,0), B(0,0)) ||
        notEqual(A(0,1), B(0,1)) ||
        notEqual(A(1,0), B(1,0)) ||
        notEqual(A(1,1), B(1,1)) ||
        notEqual(A(2,0), B(2,0)) ||
        notEqual(A(2,1), B(2,1)) ||
        notEqual(A(3,0), B(3,0)) ||
        notEqual(A(3,1), B(3,1));
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        notEqual(A(0,0), B(0,0)) ||
        notEqual(A(0,1), B(0,1)) ||
        notEqual(A(0,2), B(0,2)) ||
        notEqual(A(1,0), B(1,0)) ||
        notEqual(A(1,1), B(1,1)) ||
        notEqual(A(1,2), B(1,2)) ||
        notEqual(A(2,0), B(2,0)) ||
        notEqual(A(2,1), B(2,1)) ||
        notEqual(A(2,2), B(2,2)) ||
        notEqual(A(3,0), B(3,0)) ||
        notEqual(A(3,1), B(3,1)) ||
        notEqual(A(3,2), B(3,2));
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        notEqual(A(0,0), B(0,0)) ||
        notEqual(A(0,1), B(0,1)) ||
        notEqual(A(0,2), B(0,2)) ||
        notEqual(A(0,3), B(0,3)) ||
        notEqual(A(1,0), B(1,0)) ||
        notEqual(A(1,1), B(1,1)) ||
        notEqual(A(1,2), B(1,2)) ||
        notEqual(A(1,3), B(1,3)) ||
        notEqual(A(2,0), B(2,0)) ||
        notEqual(A(2,1), B(2,1)) ||
        notEqual(A(2,2), B(2,2)) ||
        notEqual(A(2,3), B(2,3)) ||
        notEqual(A(3,0), B(3,0)) ||
        notEqual(A(3,1), B(3,1)) ||
        notEqual(A(3,2), B(3,2)) ||
        notEqual(A(3,3), B(3,3));
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (notEqual(A[i], B[i])) return true;
        return false;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator<(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return
        A(0,0) < B(0,0) && 
        A(0,1) < B(0,1) &&
        A(1,0) < B(1,0) && 
        A(1,1) < B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        A(0,0) < B(0,0) &&
        A(0,1) < B(0,1) && 
        A(0,2) < B(0,2) &&
        A(1,0) < B(1,0) && 
        A(1,1) < B(1,1) && 
        A(1,2) < B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        A(0,0) < B(0,0) && 
        A(0,1) < B(0,1) && 
        A(0,2) < B(0,2) && 
        A(0,3) < B(0,3) &&
        A(1,0) < B(1,0) && 
        A(1,1) < B(1,1) && 
        A(1,2) < B(1,2) && 
        A(1,3) < B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        A(0,0) < B(0,0) && 
        A(0,1) < B(0,1) &&
        A(1,0) < B(1,0) && 
        A(1,1) < B(1,1) &&
        A(2,0) < B(2,0) && 
        A(2,1) < B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        A(0,0) < B(0,0) && 
        A(0,1) < B(0,1) && 
        A(0,2) < B(0,2) &&
        A(1,0) < B(1,0) && 
        A(1,1) < B(1,1) && 
        A(1,2) < B(1,2) &&
        A(2,0) < B(2,0) &&
        A(2,1) < B(2,1) && 
        A(2,2) < B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        A(0,0) < B(0,0) && 
        A(0,1) < B(0,1) && 
        A(0,2) < B(0,2) && 
        A(0,3) < B(0,3) &&
        A(1,0) < B(1,0) && 
        A(1,1) < B(1,1) && 
        A(1,2) < B(1,2) &&
        A(1,3) < B(1,3) &&
        A(2,0) < B(2,0) && 
        A(2,1) < B(2,1) && 
        A(2,2) < B(2,2) && 
        A(2,3) < B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        A(0,0) < B(0,0) && 
        A(0,1) < B(0,1) &&
        A(1,0) < B(1,0) && 
        A(1,1) < B(1,1) &&
        A(2,0) < B(2,0) && 
        A(2,1) < B(2,1) &&
        A(3,0) < B(3,0) && 
        A(3,1) < B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        A(0,0) < B(0,0) && 
        A(0,1) < B(0,1) && 
        A(0,2) < B(0,2) &&
        A(1,0) < B(1,0) && 
        A(1,1) < B(1,1) && 
        A(1,2) < B(1,2) &&
        A(2,0) < B(2,0) && 
        A(2,1) < B(2,1) && 
        A(2,2) < B(2,2) &&
        A(3,0) < B(3,0) && 
        A(3,1) < B(3,1) && 
        A(3,2) < B(3,2); 
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        A(0,0) < B(0,0) && 
        A(0,1) < B(0,1) && 
        A(0,2) < B(0,2) && 
        A(0,3) < B(0,3) &&
        A(1,0) < B(1,0) && 
        A(1,1) < B(1,1) && 
        A(1,2) < B(1,2) && 
        A(1,3) < B(1,3) &&
        A(2,0) < B(2,0) && 
        A(2,1) < B(2,1) && 
        A(2,2) < B(2,2) && 
        A(2,3) < B(2,3) &&
        A(3,0) < B(3,0) && 
        A(3,1) < B(3,1) && 
        A(3,2) < B(3,2) && 
        A(3,3) < B(3,3);
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (A[i] >= B[i]) return false;
        return true;  
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator>(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return
        A(0,0) > B(0,0) &&
        A(0,1) > B(0,1) &&
        A(1,0) > B(1,0) &&
        A(1,1) > B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        A(0,0) > B(0,0) && 
        A(0,1) > B(0,1) && 
        A(0,2) > B(0,2) &&
        A(1,0) > B(1,0) && 
        A(1,1) > B(1,1) && 
        A(1,2) > B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        A(0,0) > B(0,0) && 
        A(0,1) > B(0,1) && 
        A(0,2) > B(0,2) && 
        A(0,3) > B(0,3) &&
        A(1,0) > B(1,0) && 
        A(1,1) > B(1,1) && 
        A(1,2) > B(1,2) && 
        A(1,3) > B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        A(0,0) > B(0,0) && 
        A(0,1) > B(0,1) &&
        A(1,0) > B(1,0) &&
        A(1,1) > B(1,1) &&
        A(2,0) > B(2,0) &&
        A(2,1) > B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        A(0,0) > B(0,0) &&
        A(0,1) > B(0,1) && 
        A(0,2) > B(0,2) &&
        A(1,0) > B(1,0) && 
        A(1,1) > B(1,1) && 
        A(1,2) > B(1,2) &&
        A(2,0) > B(2,0) && 
        A(2,1) > B(2,1) && 
        A(2,2) > B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        A(0,0) > B(0,0) && 
        A(0,1) > B(0,1) && 
        A(0,2) > B(0,2) && 
        A(0,3) > B(0,3) &&
        A(1,0) > B(1,0) && 
        A(1,1) > B(1,1) && 
        A(1,2) > B(1,2) && 
        A(1,3) > B(1,3) &&
        A(2,0) > B(2,0) && 
        A(2,1) > B(2,1) && 
        A(2,2) > B(2,2) && 
        A(2,3) > B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        A(0,0) > B(0,0) && 
        A(0,1) > B(0,1) &&
        A(1,0) > B(1,0) && 
        A(1,1) > B(1,1) &&
        A(2,0) > B(2,0) && 
        A(2,1) > B(2,1) &&
        A(3,0) > B(3,0) && 
        A(3,1) > B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        A(0,0) > B(0,0) && 
        A(0,1) > B(0,1) && 
        A(0,2) > B(0,2) &&
        A(1,0) > B(1,0) && 
        A(1,1) > B(1,1) && 
        A(1,2) > B(1,2) &&
        A(2,0) > B(2,0) && 
        A(2,1) > B(2,1) && 
        A(2,2) > B(2,2) &&
        A(3,0) > B(3,0) && 
        A(3,1) > B(3,1) && 
        A(3,2) > B(3,2); 
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        A(0,0) > B(0,0) && 
        A(0,1) > B(0,1) && 
        A(0,2) > B(0,2) && 
        A(0,3) > B(0,3) &&
        A(1,0) > B(1,0) && 
        A(1,1) > B(1,1) && 
        A(1,2) > B(1,2) && 
        A(1,3) > B(1,3) &&
        A(2,0) > B(2,0) && 
        A(2,1) > B(2,1) && 
        A(2,2) > B(2,2) && 
        A(2,3) > B(2,3) &&
        A(3,0) > B(3,0) && 
        A(3,1) > B(3,1) && 
        A(3,2) > B(3,2) && 
        A(3,3) > B(3,3);
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (A[i] <= B[i]) return false;
        return true;   
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator<=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return
        A(0,0) <= B(0,0) &&
        A(0,1) <= B(0,1) &&
        A(1,0) <= B(1,0) &&
        A(1,1) <= B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        A(0,0) <= B(0,0) && 
        A(0,1) <= B(0,1) && 
        A(0,2) <= B(0,2) &&
        A(1,0) <= B(1,0) && 
        A(1,1) <= B(1,1) && 
        A(1,2) <= B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        A(0,0) <= B(0,0) && 
        A(0,1) <= B(0,1) && 
        A(0,2) <= B(0,2) && 
        A(0,3) <= B(0,3) &&
        A(1,0) <= B(1,0) && 
        A(1,1) <= B(1,1) && 
        A(1,2) <= B(1,2) && 
        A(1,3) <= B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        A(0,0) <= B(0,0) && 
        A(0,1) <= B(0,1) &&
        A(1,0) <= B(1,0) && 
        A(1,1) <= B(1,1) &&
        A(2,0) <= B(2,0) && 
        A(2,1) <= B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        A(0,0) <= B(0,0) && 
        A(0,1) <= B(0,1) && 
        A(0,2) <= B(0,2) &&
        A(1,0) <= B(1,0) && 
        A(1,1) <= B(1,1) && 
        A(1,2) <= B(1,2) &&
        A(2,0) <= B(2,0) && 
        A(2,1) <= B(2,1) && 
        A(2,2) <= B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        A(0,0) <= B(0,0) && 
        A(0,1) <= B(0,1) && 
        A(0,2) <= B(0,2) && 
        A(0,3) <= B(0,3) &&
        A(1,0) <= B(1,0) && 
        A(1,1) <= B(1,1) && 
        A(1,2) <= B(1,2) && 
        A(1,3) <= B(1,3) &&
        A(2,0) <= B(2,0) && 
        A(2,1) <= B(2,1) && 
        A(2,2) <= B(2,2) && 
        A(2,3) <= B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        A(0,0) <= B(0,0) && 
        A(0,1) <= B(0,1) &&
        A(1,0) <= B(1,0) && 
        A(1,1) <= B(1,1) &&
        A(2,0) <= B(2,0) && 
        A(2,1) <= B(2,1) &&
        A(3,0) <= B(3,0) &&
        A(3,1) <= B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        A(0,0) <= B(0,0) &&
        A(0,1) <= B(0,1) && 
        A(0,2) <= B(0,2) &&
        A(1,0) <= B(1,0) && 
        A(1,1) <= B(1,1) && 
        A(1,2) <= B(1,2) &&
        A(2,0) <= B(2,0) && 
        A(2,1) <= B(2,1) && 
        A(2,2) <= B(2,2) &&
        A(3,0) <= B(3,0) && 
        A(3,1) <= B(3,1) && 
        A(3,2) <= B(3,2); 
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        A(0,0) <= B(0,0) && 
        A(0,1) <= B(0,1) && 
        A(0,2) <= B(0,2) && 
        A(0,3) <= B(0,3) &&
        A(1,0) <= B(1,0) && 
        A(1,1) <= B(1,1) && 
        A(1,2) <= B(1,2) && 
        A(1,3) <= B(1,3) &&
        A(2,0) <= B(2,0) && 
        A(2,1) <= B(2,1) && 
        A(2,2) <= B(2,2) && 
        A(2,3) <= B(2,3) &&
        A(3,0) <= B(3,0) && 
        A(3,1) <= B(3,1) && 
        A(3,2) <= B(3,2) && 
        A(3,3) <= B(3,3);
    }
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (A[i] > B[i]) return false;
        return true;  
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator>=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return
        A(0,0) >= B(0,0) &&
        A(0,1) >= B(0,1) &&
        A(1,0) >= B(1,0) && 
        A(1,1) >= B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        A(0,0) >= B(0,0) && 
        A(0,1) >= B(0,1) && 
        A(0,2) >= B(0,2) &&
        A(1,0) >= B(1,0) && 
        A(1,1) >= B(1,1) && 
        A(1,2) >= B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        A(0,0) >= B(0,0) && 
        A(0,1) >= B(0,1) && 
        A(0,2) >= B(0,2) &&
        A(0,3) >= B(0,3) &&
        A(1,0) >= B(1,0) && 
        A(1,1) >= B(1,1) && 
        A(1,2) >= B(1,2) && 
        A(1,3) >= B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        A(0,0) >= B(0,0) && 
        A(0,1) >= B(0,1) &&
        A(1,0) >= B(1,0) && 
        A(1,1) >= B(1,1) &&
        A(2,0) >= B(2,0) && 
        A(2,1) >= B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        A(0,0) >= B(0,0) &&
        A(0,1) >= B(0,1) &&
        A(0,2) >= B(0,2) &&
        A(1,0) >= B(1,0) && 
        A(1,1) >= B(1,1) && 
        A(1,2) >= B(1,2) &&
        A(2,0) >= B(2,0) && 
        A(2,1) >= B(2,1) && 
        A(2,2) >= B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        A(0,0) >= B(0,0) && 
        A(0,1) >= B(0,1) && 
        A(0,2) >= B(0,2) && 
        A(0,3) >= B(0,3) &&
        A(1,0) >= B(1,0) && 
        A(1,1) >= B(1,1) && 
        A(1,2) >= B(1,2) && 
        A(1,3) >= B(1,3) &&
        A(2,0) >= B(2,0) && 
        A(2,1) >= B(2,1) && 
        A(2,2) >= B(2,2) && 
        A(2,3) >= B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        A(0,0) >= B(0,0) && 
        A(0,1) >= B(0,1) &&
        A(1,0) >= B(1,0) && 
        A(1,1) >= B(1,1) &&
        A(2,0) >= B(2,0) && 
        A(2,1) >= B(2,1) &&
        A(3,0) >= B(3,0) && 
        A(3,1) >= B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        A(0,0) >= B(0,0) &&
        A(0,1) >= B(0,1) && 
        A(0,2) >= B(0,2) &&
        A(1,0) >= B(1,0) &&
        A(1,1) >= B(1,1) && 
        A(1,2) >= B(1,2) &&
        A(2,0) >= B(2,0) && 
        A(2,1) >= B(2,1) && 
        A(2,2) >= B(2,2) &&
        A(3,0) >= B(3,0) && 
        A(3,1) >= B(3,1) && 
        A(3,2) >= B(3,2); 
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        A(0,0) >= B(0,0) && 
        A(0,1) >= B(0,1) && 
        A(0,2) >= B(0,2) && 
        A(0,3) >= B(0,3) &&
        A(1,0) >= B(1,0) && 
        A(1,1) >= B(1,1) && 
        A(1,2) >= B(1,2) && 
        A(1,3) >= B(1,3) &&
        A(2,0) >= B(2,0) && 
        A(2,1) >= B(2,1) && 
        A(2,2) >= B(2,2) && 
        A(2,3) >= B(2,3) &&
        A(3,0) >= B(3,0) && 
        A(3,1) >= B(3,1) && 
        A(3,2) >= B(3,2) && 
        A(3,3) >= B(3,3);
    } 
    else
    {
        for (auto i = 0; i < Matrix<M,N,T>::size; ++i) if (A[i] < B[i]) return false;
        return true;
    }
}

#endif // MATH3D_MATRIX_OPERATORS_HPP
