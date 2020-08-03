#pragma once


#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>


/**
 * Generic multiplication vector A by matrix B.
 * @tparam D Vector dimensions.
 * @tparam N Matrix rows count.
 * @return If N == 1 return scalar, otherwise return Vector<N>.
 */
template<size_t D, size_t N, typename T>
constexpr std::conditional_t<(N == 1), T, MATH3D_NAMESPACE::Vector<N,T>>
operator * (const MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Matrix<D,N,T>& B);

/**
 * Generic multiplication matrix A by vector B.
 * @tparam D Vector dimensions.
 * @tparam M Matrix rows count.
 * @return The result of multiplication (vector).
 */
template<size_t D, size_t M, typename T>
constexpr std::conditional_t<(M == 1), T, MATH3D_NAMESPACE::Vector<M,T>>
operator * (const MATH3D_NAMESPACE::Matrix<M,D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);


#include <private/Math3D/Core/Operators/MatrixVectorMultiplication.hpp>