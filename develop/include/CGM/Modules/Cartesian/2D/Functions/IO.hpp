#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Modules/Cartesian/2D/Types/Enums.hpp>
#include <CGM/Modules/Cartesian/2D/Types/Basis.hpp>
#include <CGM/Modules/Cartesian/2D/Types/Typedefs.hpp>


template <CGM_XY::EBasisBase Base, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::Basis<Base,T>& basis);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::AxesTuple<T>& axes);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::SpaceTuple<T>& space);

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XY::EAxes axis);

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XY::EBasisBase basisBase);


#include <CGM/detail/Modules/Cartesian/2D/Functions/IO.hpp>
