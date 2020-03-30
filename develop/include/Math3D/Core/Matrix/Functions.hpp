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

MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Matrix/Functions.hpp>


#endif //MATH3D_MATRIX_FUNCTIONS_HPP
