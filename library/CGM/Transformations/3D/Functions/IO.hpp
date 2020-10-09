#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Transformations/3D/Types/ArbitraryAxis.hpp>
#include <CGM/Transformations/3D/Types/Enums.hpp>
#include <CGM/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Transformations/3D/Types/AxisAngle.hpp>
#include <CGM/Transformations/3D/Types/Transforms.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::ArbitraryAxis<T>& axis);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::Pivot<T>& pivot);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::Transforms<T>& transforms);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::AxisAngle<T>& axisAngle);

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XFORM3D::ERotationOrder rotationOrder);


#include <CGM/Transformations/3D/Functions/IO.inl>
