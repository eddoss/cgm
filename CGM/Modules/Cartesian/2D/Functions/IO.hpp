#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Modules/Cartesian/2D/Types/Axes.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_2D::Axes<T>& axes);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::E2D axis);


#include "IO.inl"
