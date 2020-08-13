#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Modules/Cartesian/2D/Types/Enums.hpp>
#include <CGM/Modules/Cartesian/2D/Types/Typedefs.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::AxesTuple<T>& axes);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::SpaceTuple<T>& space);

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XY::EAxes axis);


#include <CGM/detail/Modules/Cartesian/2D/Functions/IO.hpp>
