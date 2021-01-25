#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Transformations/3D/Types/Ray.hpp>
#include <CGM/Transformations/3D/Types/Enums.hpp>
#include <CGM/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Transformations/3D/Types/AxisAngle.hpp>
#include <CGM/Transformations/3D/Types/Transforms.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Ray<T>& axis);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Pivot<T>& pivot);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Transforms<T>& transforms);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::AxisAngle<T>& axisAngle);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::ERotationOrder rotationOrder);


#include "IO.inl"