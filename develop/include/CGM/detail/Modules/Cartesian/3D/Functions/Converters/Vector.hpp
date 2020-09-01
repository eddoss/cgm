

#include <CGM/Modules/Cartesian/3D/Functions/Converters/Vector.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientation)
{
    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        vector = vector * orientation;
    #else
        vector = orientation * vector;
    #endif
    }
    else
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        vector = orientation * vector;
    #else
        vector = vector * orientation;
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        vector = vector * orientation + position;
    #else
        vector = orientation * vector + position;
    #endif
    }
    else
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        vector = orientation * (vector - position);
    #else
        vector = (vector - position) * orientation;
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& space)
{
    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        if constexpr (Representation == EVectorRepresentation::Point)
        {
            vector = detail::multiply_vector3_on_matrix4x4<EVectorRepresentation::Direction>(vector, space) + position(space);
        }
        else if constexpr (Representation == EVectorRepresentation::Direction)
        {
            vector = detail::multiply_vector3_on_matrix4x4<EVectorRepresentation::Direction>(vector, space);
        }
    #else
        if constexpr (Representation == EVectorRepresentation::Point)
        {
            vector = detail::multiply_matrix4x4_on_vector3<EVectorRepresentation::Direction>(space, vector) + position(space);
        }
        else if constexpr (Representation == EVectorRepresentation::Direction)
        {
            vector = detail::multiply_matrix4x4_on_vector3<EVectorRepresentation::Direction>(space, vector);
        }
    #endif
    }
    else
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        if constexpr (Representation == EVectorRepresentation::Point)
        {
            vector = detail::multiply_matrix4x4_on_vector3<EVectorRepresentation::Direction>(space, vector - position(space));
        }
        else
        {
            vector = detail::multiply_matrix4x4_on_vector3<EVectorRepresentation::Direction>(space, vector);
        }
    #else
        if constexpr (Representation == EVectorRepresentation::Point)
        {
            vector = detail::multiply_vector3_on_matrix4x4<EVectorRepresentation::Direction>(vector - position(space), space);
        }
        else
        {
            vector = detail::multiply_vector3_on_matrix4x4<EVectorRepresentation::Direction>(vector, space);
        }
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientation)
{
    if constexpr (Space == ESpace::World)
    {
        vector = oriented(vector, orientation);
    }
    else
    {
        vector = oriented(vector, inverseForce(orientation));
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    if constexpr (Space == ESpace::World)
    {
        vector = oriented(vector, orientation) + position;
    }
    else
    {
        vector = oriented(vector - position, inverseForce(orientation));
    }
}

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert<CGM_WORLD>(vector, orientationA);
    convert<CGM_LOCAL>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<CGM_WORLD>(vector, orientationA);
    convert<CGM_LOCAL>(vector, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<CGM_WORLD>(vector, orientationA);
    convert<CGM_LOCAL,Representation>(vector, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    convert<CGM_WORLD>(vector, orientationA);
    convert<CGM_LOCAL>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<CGM_WORLD>(vector, orientationA);
    convert<CGM_LOCAL>(vector, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    convert<CGM_WORLD>(vector, orientationA, positionA);
    convert<CGM_LOCAL>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<CGM_WORLD>(vector, orientationA, positionA);
    convert<CGM_LOCAL>(vector, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    convert<CGM_WORLD>(vector, orientationA, positionA);
    convert<CGM_LOCAL,EVectorRepresentation::Point>(vector, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    convert<CGM_WORLD>(vector, orientationA, positionA);
    convert<CGM_LOCAL>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<CGM_WORLD>(vector, orientationA, positionA);
    convert<CGM_LOCAL>(vector, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    convert<CGM_WORLD,Representation>(vector, spaceA);
    convert<CGM_LOCAL>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<CGM_WORLD,EVectorRepresentation::Point>(vector, spaceA);
    convert<CGM_LOCAL>(vector, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    convert<CGM_WORLD,Representation>(vector, spaceA);
    convert<CGM_LOCAL,Representation>(vector, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    convert<CGM_WORLD,Representation>(vector, spaceA);
    convert<CGM_LOCAL>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<CGM_WORLD,EVectorRepresentation::Point>(vector, spaceA);
    convert<CGM_LOCAL>(vector, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert<CGM_WORLD>(vector, orientationA);
    convert<CGM_LOCAL>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<CGM_WORLD>(vector, orientationA);
    convert<CGM_LOCAL>(vector, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<CGM_WORLD>(vector, orientationA);
    convert<CGM_LOCAL,Representation>(vector, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    convert<CGM_WORLD>(vector, orientationA);
    convert<CGM_LOCAL>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<CGM_WORLD>(vector, orientationA);
    convert<CGM_LOCAL>(vector, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Quaternion with Position (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    convert<CGM_WORLD>(vector, orientationA, positionA);
    convert<CGM_LOCAL>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<CGM_WORLD>(vector, orientationA, positionA);
    convert<CGM_LOCAL>(vector, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    convert<CGM_WORLD>(vector, orientationA, positionA);
    convert<CGM_LOCAL,EVectorRepresentation::Point>(vector, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    convert<CGM_WORLD>(vector, orientationA, positionA);
    convert<CGM_LOCAL>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<CGM_WORLD>(vector, orientationA, positionA);
    convert<CGM_LOCAL>(vector, orientationB, positionB);
}

/* ####################################################################################### */
/* Global to local / local to global (outplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation)
{
    auto copy = vector;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    auto copy = vector;
    convert<Space>(copy, orientation, position);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<4,4,T>& space)
{
    auto copy = vector;
    convert<Space,Representation>(copy, space);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientation)
{
    auto copy = vector;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    auto copy = vector;
    convert<Space>(copy, orientation, position);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    auto copy = vector;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = vector;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    auto copy = vector;
    convert<Representation>(copy, orientationA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    auto copy = vector;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = vector;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    auto copy = vector;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = vector;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    auto copy = vector;
    convert(copy, orientationA, positionA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    auto copy = vector;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = vector;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    auto copy = vector;
    convert<Representation>(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = vector;
    convert(copy, spaceA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    auto copy = vector;
    convert<Representation>(copy, spaceA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    auto copy = vector;
    convert<Representation>(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = vector;
    convert(copy, spaceA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Quaternion (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    auto copy = vector;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = vector;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    auto copy = vector;
    convert<Representation>(copy, orientationA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    auto copy = vector;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = vector;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Quaternion with Position (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    auto copy = vector;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = vector;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    auto copy = vector;
    convert(copy, orientationA, positionA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    auto copy = vector;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
converted(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = vector;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END