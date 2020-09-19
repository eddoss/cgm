#pragma once


#include <CGM/Modules/Common.hpp>
#include <CGM/detail/Modules/Core/Types/Matrix.hpp>
#include <CGM/detail/Modules/Core/Types/Vector.hpp>
#include <CGM/detail/Modules/Core/Operators/MatrixVectorMultiplication.hpp>


/* ####################################################################################### */
/* Increment and decrement */
/* ####################################################################################### */

/**
 * Increase all components of matrix by 1 and returns it.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>&
operator ++ (CGM::Matrix<M,N,T>& matrix);

/**
 * Decrease all components of matrix by 1 and returns it.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>&
operator -- (CGM::Matrix<M,N,T>& matrix);

/**
 * Increase all components of matrix by 1 and returns unchanged copy of it.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator ++ (CGM::Matrix<M,N,T>& matrix, int);

/**
 * Decrease all components of matrix by 1 and returns unchanged copy of it.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator -- (CGM::Matrix<M,N,T>& matrix, int);

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
constexpr CGM::Matrix<M,N,T>
operator + (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B);

/**
 * Add scalar to matrix and return copy.
 * @param matrix Matrix to add to.
 * @param scalar Value to add.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>
operator + (const CGM::Matrix<M,N,T>& matrix, TScalar scalar);

/**
 * Add scalar to matrix and return copy.
 * @param matrix Matrix to add to.
 * @param scalar Value to add.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator + (T scalar, const CGM::Matrix<M,N,T>& matrix);

/**
 * Add scalar to matrix components.
 * @param matrix Matrix to add to.
 * @param scalar Value to add.
 * @return The result of adding.
 */
template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>&
operator += (CGM::Matrix<M,N,T>& matrix, TScalar scalar);

/**
 * Add matrix B to matrix A.
 * @param A Matrix to add to.
 * @param B Matrix to add.
 * @return The result of adding.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>&
operator += (CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B);

/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

/**
 * Get a negated copy of the matrix.
 * @param matrix Matrix to negate.
 * @return A negated copy of the matrix.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator - (const CGM::Matrix<M,N,T>& matrix);

/**
 * Calculates difference of two matrix.
 * @param A Left matrix.
 * @param B Right matrix.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator - (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B);

/**
 * Subtract scalar from each matrix component and return copy.
 * @param matrix Matrix to subtract from.
 * @param scalar Value to subtract.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>
operator - (const CGM::Matrix<M,N,T>& matrix, TScalar scalar);

/**
 * Subtract scalar from each matrix component.
 * @param matrix Matrix to subtract from.
 * @param scalar Value to subtract.
 * @return The result of subtraction.
 */
template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>&
operator -= (CGM::Matrix<M,N,T>& matrix, TScalar scalar);

/**
 * Subtract matrix B from matrix A.
 * @param A Matrix to subtract from.
 * @param B Matrix to subtract.
 * @return The result of subtraction.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>&
operator -= (CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B);

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
constexpr CGM::Matrix<M,N,T>
operator * (const CGM::Matrix<M,N,T>& matrix, TScalar scalar);

/**
 * Multiply scalar to each matrix component and return copy.
 * @param matrix Matrix to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>
operator * (TScalar scalar, const CGM::Matrix<M,N,T>& matrix);

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
constexpr CGM::Matrix<AM,BN,T>
operator * (const CGM::Matrix<AM,AN,T>& A, const CGM::Matrix<AN,BN,T>& B);

/**
 * Multiply matrix A<1,N> by matrix B<N,1>.
 * @param A left matrix.
 * @param B right matrix.
 * @tparam S matrices size.
 * @return The result of multiplication (scalar value).
 */
template<size_t S, typename T>
constexpr T
operator * (const CGM::Matrix<1,S,T>& A, const CGM::Matrix<S,1,T>& B);

/**
 * Multiply scalar to each matrix component.
 * @param matrix Matrix to multiply to.
 * @param scalar Value to multiply.
 * @return The result of multiplication.
 */
template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>&
operator *= (CGM::Matrix<M,N,T>& matrix, TScalar scalar);

/**
 * Multiply square matrix A by square matrix B and store result in A.
 * @param A left matrix.
 * @param B right matrix.
 * @tparam S matrices size.
 * @return The result of multiplication.
 */
template<size_t S, typename T>
constexpr CGM::Matrix<S,S,T>&
operator *= (CGM::Matrix<S,S,T>& A, const CGM::Matrix<S,S,T>& B);

/**
 * Component-wise multiplication of matrix A by matrix B.
 * @param A Matrix to multiply.
 * @param B Matrix to multiply on.
 * @return Result of component-wise multiplication.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator ^ (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B);

/**
 * Component-wise multiplication of matrix A by matrix B and store result in A.
 * @param A Matrix to multiply.
 * @param B Matrix to multiply by.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>&
operator ^= (CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B);

/* ####################################################################################### */
/* Component wise division */
/* ####################################################################################### */

/**
 * Component-wise division of matrix A by matrix B.
 * @param A Matrix to division.
 * @param B Matrix to division by.
 * @return Result of component-wise division.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator | (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B);

/**
 * Component-wise division of matrix A by matrix B and store result in A.
 * @param A Matrix to division.
 * @param B Matrix to division by.
 * @return Result of component-wise division.
 */
template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator |= (CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B);

/**
 * Component-wise division of matrix A by scalar.
 * @param matrix Matrix to division to.
 * @param scalar Value to division.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>
operator / (const CGM::Matrix<M,N,T>& matrix, TScalar scalar);

/**
 * Divide each matrix component by a scalar and return copy.
 * @param matrix Matrix to division to.
 * @param scalar Value to division.
 * @return The result of division.
 */
template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>&
operator /= (CGM::Matrix<M,N,T>& matrix, TScalar scalar);

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
operator == (const CGM::Matrix<M,N,T>& matrix, T scalar);

/**
 * Checking the components of a matrix for inequality with a scalar.
 * @param matrix Matrix to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are not equal to scalar, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator != (const CGM::Matrix<M,N,T>& matrix, T scalar);

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
operator == (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B);

/**
 * Check against another matrix for inequality.
 * @param A Matrix to compare.
 * @param B Matrix to compare with.
 * @return true if the matrices are not equal, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr bool
operator != (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B);


#include <CGM/detail/Modules/Core/Operators/Matrix_impl.hpp>
