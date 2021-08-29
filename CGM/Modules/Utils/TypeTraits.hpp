#pragma once


#include <type_traits>
#include <CGM/Modules/Utils/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

template<typename T, typename = void>
struct floating_or_unsigned;

template<typename T>
struct floating_or_unsigned<T, std::enable_if_t<(std::is_floating_point_v<T>)>> {using type = T;};

template<typename T>
struct floating_or_unsigned<T, std::enable_if_t<(std::is_unsigned_v<T>)>> {using type = T;};

template<typename T>
using floating_or_unsigned_t = typename floating_or_unsigned<T>::type;

/* --------------------------------------------------------------------------------------- */

template<typename ToCheck, typename Output>
using enable_if_floating = std::enable_if_t<std::is_floating_point_v<ToCheck>, Output>;

/* --------------------------------------------------------------------------------------- */

template<typename ToCheck, typename Output>
using enable_if_integral = std::enable_if_t<std::is_integral_v<ToCheck>, Output>;

/* --------------------------------------------------------------------------------------- */

template<typename ToCheck, typename Output>
using enable_if_number = std::enable_if_t<(std::is_integral_v<ToCheck> || std::is_floating_point_v<ToCheck>), Output>;

/* --------------------------------------------------------------------------------------- */

template<typename From, typename To, typename Output>
using enable_if_convertible = std::enable_if_t<(std::is_convertible_v<From, To>), Output>;

CGM_NAMESPACE_END