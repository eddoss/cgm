#pragma once


#include <type_traits>
#include <CGM/Modules/Utils/ModuleGlobals.hpp>
#include <CGM/Modules/Utils/Types/Number.hpp>


CGM_NAMESPACE_BEGIN

template <typename T>
struct is_floating_number
    : public std::false_type {};

template <>
struct is_floating_number<float>
    : public std::true_type {};

template <>
struct is_floating_number<double>
    : public std::true_type {};

template <>
struct is_floating_number<long double>
    : public std::true_type {};

template <typename T, typename Constraint>
struct is_floating_number<Number<T,Constraint>>
    : public std::true_type {};

template<typename T>
CGM_INLINE constexpr bool
is_floating_number_v = is_floating_number<T>::value;

/* --------------------------------------------------------------------------------------- */

template<typename ToCheck, typename Output>
using enable_if_floating = std::enable_if_t<is_floating_number_v<ToCheck>, Output>;

/* --------------------------------------------------------------------------------------- */

template<typename ToCheck, typename Output>
using enable_if_integral = std::enable_if_t<std::is_integral_v<ToCheck>, Output>;

/* --------------------------------------------------------------------------------------- */

template<typename ToCheck, typename Output>
using enable_if_number = std::enable_if_t<(std::is_integral_v<ToCheck> || is_floating_number_v<ToCheck>), Output>;

/* --------------------------------------------------------------------------------------- */

template<typename From, typename To, typename Output>
using enable_if_convertible = std::enable_if_t<(std::is_convertible_v<From, To>), Output>;

CGM_NAMESPACE_END