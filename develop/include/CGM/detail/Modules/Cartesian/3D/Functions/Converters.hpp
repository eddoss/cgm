

#include <CGM/Modules/Cartesian/3D/Functions/Converters.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return orientation * vector;
#else
    return vector * orientation;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return orientation * (vector - position);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return orientation * vector;
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return (vector - position) * orientation;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return vector * orientation;
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return detail::multiply_matrix4x4_on_vector3<EVectorRepresentation::Direction>(localSpace, vector - position(localSpace));
    }
    else
    {
        return detail::multiply_matrix4x4_on_vector3<EVectorRepresentation::Direction>(localSpace, vector);
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return detail::multiply_vector3_on_matrix4x4<EVectorRepresentation::Direction>(vector - position(localSpace), localSpace);
    }
    else
    {
        return detail::multiply_vector3_on_matrix4x4<EVectorRepresentation::Direction>(vector, localSpace);
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientation)
{
    return oriented(vector, inverseForce(orientation));
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return oriented(vector - position, inverseForce(orientation));
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return oriented(vector, inverseForce(orientation));
    }
}

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * orientation;
#else
    return orientation * vector;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return vector * orientation + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return vector * orientation;
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return orientation * vector + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return orientation * vector;
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return detail::multiply_vector3_on_matrix4x4<EVectorRepresentation::Direction>(vector, localSpace) + position(localSpace);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return detail::multiply_vector3_on_matrix4x4<EVectorRepresentation::Direction>(vector, localSpace);
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return detail::multiply_matrix4x4_on_vector3<EVectorRepresentation::Direction>(localSpace, vector) + position(localSpace);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return detail::multiply_matrix4x4_on_vector3<EVectorRepresentation::Direction>(localSpace, vector);
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& orientation)
{
    return oriented(vector, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return oriented(vector, orientation) + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return oriented(vector, orientation);
    }
}

/* ####################################################################################### */
/* Local to local: Matrix3 */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal(vector, orientationA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
       return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal(vector, orientationA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal(localToGlobal<Representation>(vector, orientationA, positionA), orientationB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, orientationA, positionA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, orientationA, positionA), spaceB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal(localToGlobal<Representation>(vector, orientationA, positionA), orientationB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, orientationA, positionA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* ####################################################################################### */
/* Local to local: Matrix4 */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
    }
}

/* ####################################################################################### */
/* Local to local: Quaternion */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal(vector, orientationA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal(vector, orientationA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* ####################################################################################### */
/* Local to local: Quaternion with Position */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal(localToGlobal<Representation>(vector, orientationA, positionA), orientationB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, orientationA, positionA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, orientationA, positionA), spaceB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal(localToGlobal<Representation>(vector, orientationA, positionA), orientationB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, orientationA, positionA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END