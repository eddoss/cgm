#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Modules/Cartesian/3D/Types/Enums.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Basis.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Typedefs.hpp>


template <CGM_XYZ::EBasisBase Base, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::Basis<Base,T>& basis);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::AxesTuple<T>& axes);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::SpaceTuple<T>& space);

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XYZ::EAxes axis);

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XYZ::EBasisBase basisBase);


#include <CGM/detail/Modules/Cartesian/3D/Functions/IO.hpp>
