

#include <CGM/Modules/Transformations/3D/Functions/Converters/Axis.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientation)
{
    convert<Space>(axis.direction, orientation);
    convert<Space>(axis.position, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    convert<Space>(axis.direction, orientation);
    convert<Space>(axis.position, orientation, position);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<4,4,T>& space)
{
    convert<Space,EVectorRepresentation::Direction>(axis.direction, space);
    convert<Space,EVectorRepresentation::Point>(axis.position, space);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientation)
{
    convert<Space>(axis.direction, orientation);
    convert<Space>(axis.position, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    convert<Space>(axis.direction, orientation);
    convert<Space>(axis.position, orientation, position);
}

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, orientationA, spaceB);
    convert<EVectorRepresentation::Point>(axis.position, orientationA, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, positionA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, positionA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, orientationA, spaceB);
    convert<EVectorRepresentation::Point>(axis.position, orientationA, positionA, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, positionA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, positionA, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, spaceA, orientationB);
    convert<EVectorRepresentation::Point>(axis.position, spaceA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, spaceA, orientationB);
    convert<EVectorRepresentation::Point>(axis.position, spaceA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, spaceA, spaceB);
    convert<EVectorRepresentation::Point>(axis.position, spaceA, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, spaceA, orientationB);
    convert<EVectorRepresentation::Point>(axis.position, spaceA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, spaceA, orientationB);
    convert<EVectorRepresentation::Point>(axis.position, spaceA, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, orientationA, spaceB);
    convert<EVectorRepresentation::Point>(axis.position, orientationA, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Quaternion with Position (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, positionA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, positionA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(axis.direction, orientationA, spaceB);
    convert<EVectorRepresentation::Point>(axis.position, orientationA, positionA, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, positionA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Axis<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert(axis.direction, orientationA, orientationB);
    convert(axis.position, orientationA, positionA, orientationB, positionB);
}

/* ####################################################################################### */
/* Global to local / local to global (outplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientation)
{
    auto copy = axis;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    auto copy = axis;
    convert<Space>(copy, orientation, position);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<4,4,T>& space)
{
    auto copy = axis;
    convert<Space>(copy, space);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientation)
{
    auto copy = axis;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    auto copy = axis;
    convert<Space>(copy, orientation, position);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    auto copy = axis;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = axis;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    auto copy = axis;
    convert(copy, orientationA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    auto copy = axis;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = axis;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    auto copy = axis;
    convert(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = axis;
    convert(copy, spaceA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    auto copy = axis;
    convert(copy, spaceA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    auto copy = axis;
    convert(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = axis;
    convert(copy, spaceA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Quaternion (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    auto copy = axis;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = axis;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    auto copy = axis;
    convert(copy, orientationA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    auto copy = axis;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = axis;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Quaternion with Position (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axis<T>
converted(const Axis<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = axis;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END