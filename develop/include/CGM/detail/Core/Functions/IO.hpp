#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/detail/Core/Types/Vector.hpp>
#include <CGM/detail/Core/Types/Matrix.hpp>


template <size_t D, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Vector<D,T>& vec);

template <size_t M, size_t N, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Matrix<M,N,T>& mat);


#include <CGM/detail/Core/Functions/IO_impl.hpp>
