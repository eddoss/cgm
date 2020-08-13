#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Modules/Cartesian/3D/Types/Enums.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Typedefs.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::AxesTuple<T>& axes);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::SpaceTuple<T>& space);

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XYZ::EAxes axis);


#include <CGM/detail/Modules/Cartesian/3D/Functions/IO.hpp>
