#ifndef MATH3D_MATRIX_FUNCTIONS_HPP
#define MATH3D_MATRIX_FUNCTIONS_HPP


#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>


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
 * Safely calculate inverse matrix. Change flag to false, if cant calculate.
 * @param[in] matrix Matrix to calculate.
 * @param[out] success Set this false if cant calculate inverted matrix.
 * @return inverted matrix if could calculate, trash otherwise.
 */
template<typename TResult=FLOAT, size_t S, typename T>
constexpr Matrix<S,S,TResult>
inverted(const Matrix<S,S,T>& matrix, bool& success);

/**
 * Unsafely calculate inverse matrix. Does not check the determinants for equality to 0.
 * @param matrix Matrix to calculate.
 * @return inverted matrix if could calculate, trash otherwise.
 */
template<typename TResult=FLOAT, size_t S, typename T>
constexpr FORCEINLINE Matrix<S,S,TResult>
invertedForce(const Matrix<S,S,T>& matrix);

/**
 * Calculate matrix trace - sum of diagonal elements.
 * @return Matrix trace.
 */
template<size_t S, typename T>
constexpr FORCEINLINE T
trace(const Matrix<S,S,T>& matrix);

/**
 * Check if matrix is symmetric (a symmetric matrix is a square matrix
 * that equals its transpose: i.e., M = transposed(M)).
 * @return True if matrix is symmetric, false otherwise.
 */
template<size_t S, typename T>
constexpr FORCEINLINE T
symmetric(const Matrix<S,S,T>& matrix);

/**
 * Check if matrix is antisymmetric (an antisymmetric matrix is a matrix
 * whose transpose is its own negative: i.e., -M = transposed(M)).
 * @return True if matrix is antisymmetric, false otherwise.
 */
template<size_t S, typename T>
constexpr FORCEINLINE T
antisymmetric(const Matrix<S,S,T>& matrix);

/**
 * Check if matrix is diagonal (a diagonal matrix is a square matrix
 * whose elements are zero, apart from its diagonal).
 * @return True if matrix is diagonal, false otherwise.
 */
template<size_t S, typename T>
constexpr T
diagonal(const Matrix<S,S,T>& matrix);

/**
 * Check if matrix is orthogonal (a matrix is orthogonal if its transpose
 * is also its inverse, i.e., transposed(M) = inverted(M)).
 * @return True if matrix is orthogonal, false otherwise.
 */
template<size_t S, typename T>
constexpr T
orthogonal(const Matrix<S,S,T>& matrix);

/**
 * Create identity matrix.
 * @return Identity matrix.
 */
template<size_t S, typename T=FLOAT>
constexpr FORCEINLINE Matrix<S,S,T>
identity();

MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Functions/Matrix.hpp>


#endif //MATH3D_MATRIX_FUNCTIONS_HPP
