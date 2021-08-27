#pragma once


#include <CGM/Modules/Core/ModuleGlobals.hpp>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Utils/Functions/Numbers.hpp>


/**
 * Generic multiplication vector A by matrix B.
 * @tparam D Vector dimensions.
 * @tparam N Matrix rows count.
 * @return If N == 1 return scalar, otherwise return Vector<N>.
 */
template<size_t D, size_t N, typename T>
constexpr std::conditional_t<(N == 1), T, CGM::Vector<N,T>>
operator * (const CGM::Vector<D,T>& A, const CGM::Matrix<D,N,T>& B);

/**
 * Generic multiplication matrix A by vector B.
 * @tparam D Vector dimensions.
 * @tparam M Matrix rows count.
 * @return The result of multiplication (vector).
 */
template<size_t D, size_t M, typename T>
constexpr std::conditional_t<(M == 1), T, CGM::Vector<M,T>>
operator * (const CGM::Matrix<M,D,T>& A, const CGM::Vector<D,T>& B);

/**
 * Generic multiplication (inplace) vector A by matrix B.
 * @tparam D Vector dimensions.
 * @tparam N Matrix rows count.
 * @return If N == 1 return scalar, otherwise return Vector<N>.
 */
template<size_t D, size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N > 1), CGM::Vector<N,T>&>
operator *= (CGM::Vector<D,T>& A, const CGM::Matrix<D,N,T>& B);


#include "MatrixVectorMultiplication.inl"