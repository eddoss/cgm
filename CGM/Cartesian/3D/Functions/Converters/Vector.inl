

#include "Vector.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientation)
{
    if constexpr (Space == ESpace::Global)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        vector = orientation * vector;
    #else
        vector = vector * orientation;
    #endif
    }
    else
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        vector = inverse(orientation) * vector;
    #else
        vector = vector * inverse(orientation);
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& space)
{
    if constexpr (Space == ESpace::Global)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        vector = multiply<Representation>(space, vector);
    #else
        vector = multiply<Representation>(vector, space);
    #endif
    }
    else
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        vector = multiply<Representation>(inverse(space), vector);
    #else
        vector = multiply<Representation>(vector, inverse(space));
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientation)
{
    if constexpr (Space == ESpace::Global)
    {
        vector = oriented(vector, orientation);
    }
    else
    {
        vector = oriented(vector, inverse(orientation));
    }
}

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::Global>(vector, orientationA);
    convert<ESpace::Local>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::Global>(vector, orientationA);
    convert<ESpace::Local,Representation>(vector, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    convert<ESpace::Global>(vector, orientationA);
    convert<ESpace::Local>(vector, orientationB);
}

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::Global,Representation>(vector, spaceA);
    convert<ESpace::Local>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::Global,Representation>(vector, spaceA);
    convert<ESpace::Local,Representation>(vector, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    convert<ESpace::Global,Representation>(vector, spaceA);
    convert<ESpace::Local>(vector, orientationB);
}

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::Global>(vector, orientationA);
    convert<ESpace::Local>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::Global>(vector, orientationA);
    convert<ESpace::Local,Representation>(vector, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    convert<ESpace::Global>(vector, orientationA);
    convert<ESpace::Local>(vector, orientationB);
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

CGM_NAMESPACE_END