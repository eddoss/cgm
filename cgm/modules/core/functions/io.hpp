#pragma once


#include <iomanip>
#include <iostream>
#include <cgm/modules/core/module_globals.hpp>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>


template <size_t D, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Vector<D,T>& vec);

template <size_t M, size_t N, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Matrix<M,N,T>& mat);


#include "io.inl"
