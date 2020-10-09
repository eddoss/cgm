

#include <CGM/detail/Transformations/2D/Functions/Converters/Axis.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientation)
{
    convert<Space>(axis.direction, orientation);
    convert<Space>(axis.position, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
    convert<Space>(axis.direction, orientation);
    convert<Space>(axis.position, orientation, position);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<3,3,T>& space)
{
    convert<Space,EVectorRepresentation::Direction>(axis.direction, space);
    convert<Space,EVectorRepresentation::Point>(axis.position, space);
}

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, orientationA, spaceB);
    convert<EVectorRepresentation::Point>(axis.position, orientationA, spaceB);
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, positionA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, positionA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<3,3,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, orientationA, spaceB);
    convert<EVectorRepresentation::Point>(axis.position, orientationA, positionA, spaceB);
}

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, spaceA, orientationB);
    convert<EVectorRepresentation::Point>(axis.position, spaceA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, spaceA, orientationB);
    convert<EVectorRepresentation::Point>(axis.position, spaceA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(ArbitraryAxis<T>& axis, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, spaceA, spaceB);
    convert<EVectorRepresentation::Point>(axis.position, spaceA, spaceB);
}

/* ####################################################################################### */
/* Global to local / local to global (outplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientation)
{
    auto copy = axis;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
    auto copy = axis;
    convert<Space>(copy, orientation, position);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<3,3,T>& space)
{
    auto copy = axis;
    convert<Space>(copy, space);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB)
{
    auto copy = axis;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    auto copy = axis;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB)
{
    auto copy = axis;
    convert(copy, orientationA, spaceB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<3,3,T>& spaceB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, spaceB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB)
{
    auto copy = axis;
    convert(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    auto copy = axis;
    convert(copy, spaceA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
converted(const ArbitraryAxis<T>& axis, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB)
{
    auto copy = axis;
    convert(copy, spaceA, spaceB);
    return copy;
}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END