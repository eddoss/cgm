#pragma once


#include <iomanip>
#include <iostream>
#include <cgm/modules/cartesian/2d/types/axes.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_2D::Axes<T>& axes);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::E2D axis);


#include "io.inl"
