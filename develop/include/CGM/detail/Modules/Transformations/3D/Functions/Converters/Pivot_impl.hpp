

#include <CGM/detail/Modules/Transformations/3D/Functions/Converters/Pivot.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientation)
{
    convert<Space>(pivot.axes.x, orientation);
    convert<Space>(pivot.axes.y, orientation);
    convert<Space>(pivot.axes.z, orientation);
    convert<Space>(pivot.position, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    convert<Space>(pivot.axes.x, orientation);
    convert<Space>(pivot.axes.y, orientation);
    convert<Space>(pivot.axes.z, orientation);
    convert<Space>(pivot.position, orientation, position);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& space)
{
    convert<Space,EVectorRepresentation::Direction>(pivot.axes.x, space);
    convert<Space,EVectorRepresentation::Direction>(pivot.axes.y, space);
    convert<Space,EVectorRepresentation::Direction>(pivot.axes.z, space);
    convert<Space,EVectorRepresentation::Point>(pivot.position, space);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientation)
{
    convert<Space>(pivot.axes.x, orientation);
    convert<Space>(pivot.axes.y, orientation);
    convert<Space>(pivot.axes.z, orientation);
    convert<Space>(pivot.position, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    convert<Space>(pivot.axes.x, orientation);
    convert<Space>(pivot.axes.y, orientation);
    convert<Space>(pivot.axes.z, orientation);
    convert<Space>(pivot.position, orientation, position);
}

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(pivot.axes.x, orientationA, spaceB);
    convert<EVectorRepresentation::Direction>(pivot.axes.y, orientationA, spaceB);
    convert<EVectorRepresentation::Direction>(pivot.axes.z, orientationA, spaceB);
    convert<EVectorRepresentation::Point>(pivot.position, orientationA, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, positionA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, positionA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(pivot.axes.x, orientationA, spaceB);
    convert<EVectorRepresentation::Direction>(pivot.axes.y, orientationA, spaceB);
    convert<EVectorRepresentation::Direction>(pivot.axes.z, orientationA, spaceB);
    convert<EVectorRepresentation::Point>(pivot.position, orientationA, positionA, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, positionA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, positionA, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    convert<EVectorRepresentation::Direction>(pivot.axes.x, spaceA, orientationB);
    convert<EVectorRepresentation::Direction>(pivot.axes.y, spaceA, orientationB);
    convert<EVectorRepresentation::Direction>(pivot.axes.z, spaceA, orientationB);
    convert<EVectorRepresentation::Point>(pivot.position, spaceA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<EVectorRepresentation::Direction>(pivot.axes.x, spaceA, orientationB);
    convert<EVectorRepresentation::Direction>(pivot.axes.y, spaceA, orientationB);
    convert<EVectorRepresentation::Direction>(pivot.axes.z, spaceA, orientationB);
    convert<EVectorRepresentation::Point>(pivot.position, spaceA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(pivot.axes.x, spaceA, spaceB);
    convert<EVectorRepresentation::Direction>(pivot.axes.y, spaceA, spaceB);
    convert<EVectorRepresentation::Direction>(pivot.axes.z, spaceA, spaceB);
    convert<EVectorRepresentation::Point>(pivot.position, spaceA, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    convert<EVectorRepresentation::Direction>(pivot.axes.x, spaceA, orientationB);
    convert<EVectorRepresentation::Direction>(pivot.axes.y, spaceA, orientationB);
    convert<EVectorRepresentation::Direction>(pivot.axes.z, spaceA, orientationB);
    convert<EVectorRepresentation::Point>(pivot.position, spaceA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<EVectorRepresentation::Direction>(pivot.axes.x, spaceA, orientationB);
    convert<EVectorRepresentation::Direction>(pivot.axes.y, spaceA, orientationB);
    convert<EVectorRepresentation::Direction>(pivot.axes.z, spaceA, orientationB);
    convert<EVectorRepresentation::Point>(pivot.position, spaceA, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(pivot.axes.x, orientationA, spaceB);
    convert<EVectorRepresentation::Direction>(pivot.axes.y, orientationA, spaceB);
    convert<EVectorRepresentation::Direction>(pivot.axes.z, orientationA, spaceB);
    convert<EVectorRepresentation::Point>(pivot.position, orientationA, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Quaternion with Position (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, positionA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, positionA, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    convert<EVectorRepresentation::Direction>(pivot.axes.x, orientationA, spaceB);
    convert<EVectorRepresentation::Direction>(pivot.axes.y, orientationA, spaceB);
    convert<EVectorRepresentation::Direction>(pivot.axes.z, orientationA, spaceB);
    convert<EVectorRepresentation::Point>(pivot.position, orientationA, positionA, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, positionA, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert(pivot.axes.x, orientationA, orientationB);
    convert(pivot.axes.y, orientationA, orientationB);
    convert(pivot.axes.z, orientationA, orientationB);
    convert(pivot.position, orientationA, positionA, orientationB, positionB);
}

/* ####################################################################################### */
/* Global to local / local to global (outplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientation)
{
    auto copy = pivot;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    auto copy = pivot;
    convert<Space>(copy, orientation, position);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& space)
{
    auto copy = pivot;
    convert<Space>(copy, space);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientation)
{
    auto copy = pivot;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    auto copy = pivot;
    convert<Space>(copy, orientation, position);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    auto copy = pivot;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = pivot;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    auto copy = pivot;
    convert(copy, orientationA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    auto copy = pivot;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = pivot;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    auto copy = pivot;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = pivot;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    auto copy = pivot;
    convert(copy, orientationA, positionA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    auto copy = pivot;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = pivot;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    auto copy = pivot;
    convert(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = pivot;
    convert(copy, spaceA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    auto copy = pivot;
    convert(copy, spaceA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    auto copy = pivot;
    convert(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = pivot;
    convert(copy, spaceA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Quaternion (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    auto copy = pivot;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = pivot;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    auto copy = pivot;
    convert(copy, orientationA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    auto copy = pivot;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = pivot;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Quaternion with Position (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    auto copy = pivot;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = pivot;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    auto copy = pivot;
    convert(copy, orientationA, positionA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    auto copy = pivot;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = pivot;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END