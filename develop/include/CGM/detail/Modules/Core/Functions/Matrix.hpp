#pragma once


#include <CGM/detail/Modules/Core/Types/Matrix.hpp>
#include <CGM/detail/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Global.hpp>


CGM_NAMESPACE_BEGIN

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
 * Safely invert matrix.
 * @param matrix Matrix for which it is necessary to calculate the inverse.
 * @param determinantTolerance If determinant less than this parameter, inverting will failed.
 * @return False if cant calculate inverse matrix. true otherwise.
 */
template<size_t S, typename T>
constexpr enable_if_floating<T,bool>
invert(Matrix<S,S,T>& matrix, T determinantTolerance=T(0.000001));

/**
 * Safely calculate inverse matrix. Change flag to false, if cant calculate.
 * @param[in] matrix Matrix for which it is necessary to calculate the inverse.
 * @param[out] success Set this false if cant calculate inverse matrix.
 * @param determinantTolerance If determinant less than this parameter, inverting will failed.
 * @return Inverse matrix if could calculate, trash otherwise.
 */
template<size_t S, typename T>
constexpr enable_if_floating<T,Matrix<S,S,T>>
inverse(const Matrix<S,S,T>& matrix, bool& success, T determinantTolerance=T(0.000001));

/**
 * Unsafely calculate inverse matrix. Does not check the determinants for equality to 0.
 * @param matrix Matrix to calculate.
 * @return Inverse matrix if could calculate, trash otherwise.
 */
template<size_t S, typename T>
constexpr enable_if_floating<T,void>
invertForce(Matrix<S,S,T>& matrix);

/**
 * Unsafely calculate inverse matrix. Does not check the determinants for equality to 0.
 * @param matrix Matrix to calculate.
 * @return Inverse matrix if could calculate, trash otherwise.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Matrix<S,S,T>>
inverseForce(const Matrix<S,S,T>& matrix);

/**
 * Calculate matrix trace - sum of diagonal elements.
 * @return Matrix trace.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE T
trace(const Matrix<S,S,T>& matrix);

/**
 * Check if matrix is symmetric (a symmetric matrix is a square matrix
 * that equals its transpose: i.e., M = transposed(M)).
 * @param matrix Matrix to check.
 * @return True if matrix is symmetric, false otherwise.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE enable_if_integral<T,T>
symmetric(const Matrix<S,S,T>& matrix);

/**
 * Check if matrix is symmetric (a symmetric matrix is a square matrix
 * that equals its transpose: i.e., M = transposed(M)).
 * @param matrix Matrix to check.
 * @param tolerance Comparison tolerance.
 * @return True if matrix is symmetric, false otherwise.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
symmetric(const Matrix<S,S,T>& matrix, T tolerance);

/**
 * Check if matrix is antisymmetric (an antisymmetric matrix is a matrix
 * whose transpose is its own negative: i.e., -M = transposed(M)).
 * @param matrix Matrix to check.
 * @return True if matrix is antisymmetric, false otherwise.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE enable_if_integral<T,T>
antisymmetric(const Matrix<S,S,T>& matrix);

/**
 * Check if matrix is antisymmetric (an antisymmetric matrix is a matrix
 * whose transpose is its own negative: i.e., -M = transposed(M)).
 * @param matrix Matrix to check.
 * @param tolerance Comparison tolerance.
 * @return True if matrix is antisymmetric, false otherwise.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
antisymmetric(const Matrix<S,S,T>& matrix, T tolerance);

/**
 * Check if matrix is diagonal (a diagonal matrix is a square matrix
 * whose elements are zero, apart from its diagonal).
 * @param matrix Matrix to check.
 * @return True if matrix is diagonal, false otherwise.
 */
template<size_t S, typename T>
constexpr enable_if_integral<T,T>
diagonal(const Matrix<S,S,T>& matrix);

/**
 * Check if matrix is diagonal (a diagonal matrix is a square matrix
 * whose elements are zero, apart from its diagonal).
 * @param matrix Matrix to check.
 * @param tolerance Comparison tolerance.
 * @return True if matrix is diagonal, false otherwise.
 */
template<size_t S, typename T>
constexpr enable_if_floating<T,T>
diagonal(const Matrix<S,S,T>& matrix, T tolerance);

/**
 * Check if matrix is orthogonal (a matrix is orthogonal if its transpose
 * is also its inverse, i.e., transposed(M) = inverse(M)).
 * @param matrix Matrix to check.
 * @param tolerance Comparison tolerance.
 * @return True if matrix is orthogonal, false otherwise.
 */
template<size_t S, typename T>
constexpr enable_if_floating<T,T>
orthogonal(const Matrix<S,S,T>& matrix, T tolerance);

/**
 * Create identity matrix.
 * @return Identity matrix.
 */
template<size_t S, typename T=FLOAT>
constexpr CGM_FORCEINLINE Matrix<S,S,T>
identity();

/**
 * Compare matrix A and B (floating point based).
 * @param A First matrix.
 * @param B Second matrix.
 * @param tolerance Compare tolerance.
 * @return true if A equal to B, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
eq(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B, T tolerance);

/**
 * Compare matrix A and B (floating point based).
 * @param A First matrix.
 * @param B Second matrix.
 * @param tolerance Compare tolerance.
 * @return true if A not equal to B, false otherwise.
 */
template<size_t M, size_t N, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
neq(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B, T tolerance);

CGM_NAMESPACE_END


#include <CGM/detail/Modules/Core/Functions/Matrix_impl.hpp>
