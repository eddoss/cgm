#ifndef MATH3D_COMMON_HPP
#define MATH3D_COMMON_HPP


#include <Math3D/Global.hpp>


MATH3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Numbers comparison */
/* ####################################################################################### */

/**
 * Compare number A and B (floating point numbers).
 * @param A First number.
 * @param B Second number.
 * @param tolerance Compare tolerance.
 * @return true if A equal to B, false otherwise.
 */
template<typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
equal(T A, T B, T tolerance=TOLERANCE);

/**
 * Compare number A and B (integral numbers).
 * @param A First number.
 * @param B Second number.
 * @return true if A equal to B, false otherwise.
 */
template<typename T>
constexpr FORCEINLINE enable_if_integral<T,bool>
equal(T A, T B);

/**
 * Compare number A and B (floating point numbers).
 * @param A First number.
 * @param B Second number.
 * @param tolerance Compare tolerance.
 * @return true if A not equal to B, false otherwise.
 */
template<typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
notEqual(T A, T B, T tolerance=TOLERANCE);

/**
 * Compare number A and B (integral numbers).
 * @param A First number.
 * @param B Second number.
 * @return true if A not equal to B, false otherwise.
 */
template<typename T>
constexpr FORCEINLINE enable_if_integral<T,bool>
notEqual(T A, T B);

/* ####################################################################################### */
/* Number converter */
/* ####################################################################################### */

/**
 * Convert number from type A to type B.
 */
template<typename AT, typename BT>
constexpr FORCEINLINE typename std::enable_if_t<(std::is_floating_point_v<AT> || std::is_integral_v<AT>), AT>
number(BT value);

/**
 * Create zero value number with given type.
 * @return Zero with given type.
 */
template<typename T>
constexpr typename std::enable_if_t<(std::is_floating_point_v<T> || std::is_integral_v<T>), T>
zero = T(0);

MATH3D_NAMESPACE_END


#include <private/Math3D/Common.hpp>


#endif // MATH3D_COMMON_HPP
