

#include <Math3D/Cartesian/3D/Functions/Converters.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return transposed(orientation) * vector;
#else
    return vector * transposed(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return transposed(orientation) * (vector - position);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return transposed(orientation) * vector;
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return (vector - position) * transposed(orientation);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return vector * transposed(orientation);
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return _internal_multiply_matrix4x4_on_vector3<Representation>(_internal_fast_inverse_matrix4x4(localSpace), vector);
#else
    return _internal_multiply_vector3_on_matrix4x4<Representation>(vector, _internal_fast_inverse_matrix4x4(localSpace));
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientation)
{
    return oriented(vector, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return oriented(vector - position, orientation);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return oriented(vector, orientation);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Basis<Base,T>& localSpace)
{
    if constexpr (Base == EBasisBase::Matrix3)
    {
        if constexpr (Representation == EVectorRepresentation::Point)
        {
            return globalToLocal<Representation>(vector, localSpace.orientationMatrix(), localSpace.position());
        }
        else if constexpr (Representation == EVectorRepresentation::Direction)
        {
            return globalToLocal(vector, localSpace.orientationMatrix());
        }
    }
    else if constexpr (Base == EBasisBase::Matrix4)
    {
        return globalToLocal<Representation>(vector, localSpace.spaceMatrix());
    }
    else if constexpr (Base == EBasisBase::Quaternion)
    {
        if constexpr (Representation == EVectorRepresentation::Point)
        {
            return globalToLocal<Representation>(vector, localSpace.orientationQuaternion(), localSpace.position());
        }
        else if constexpr (Representation == EVectorRepresentation::Direction)
        {
            return globalToLocal(vector, localSpace.orientationQuaternion());
        }
    }
}

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return orientation * vector;
#else
    return vector * orientation;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return orientation * vector + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return orientation * vector;
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return vector * orientation + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return vector * orientation;
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return _internal_multiply_matrix4x4_on_vector3<Representation>(localSpace, vector);
#else
    return _internal_multiply_vector3_on_matrix4x4<Representation>(vector, localSpace);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& orientation)
{
    return oriented(vector, Quaternion<T>{orientation.vector, -orientation.scalar});
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return oriented(vector, Quaternion<T>{orientation.vector, -orientation.scalar}) + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return oriented(vector, Quaternion<T>{orientation.vector, -orientation.scalar});
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Basis<Base,T>& localSpace)
{
    if constexpr (Base == EBasisBase::Matrix3)
    {
        if constexpr (Representation == EVectorRepresentation::Point)
        {
            return localToGlobal(vector, localSpace.orientationMatrix(), localSpace.position());
        }
        else if constexpr (Representation == EVectorRepresentation::Direction)
        {
            return localToGlobal(vector, localSpace.orientationMatrix());
        }
    }
    else if constexpr (Base == EBasisBase::Matrix4)
    {
        return localToGlobal<Representation>(vector, localSpace.spaceMatrix());
    }
    else if constexpr (Base == EBasisBase::Quaternion)
    {
        if constexpr (Representation == EVectorRepresentation::Point)
        {
            return localToGlobal<Representation>(vector, localSpace.orientationQuaternion(), localSpace.position());
        }
        else if constexpr (Representation == EVectorRepresentation::Direction)
        {
            return localToGlobal(vector, localSpace.orientationQuaternion());
        }
    }
}

/* ####################################################################################### */
/* Local to local: Matrix3 */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
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
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
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

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Basis<Base,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
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
constexpr FORCEINLINE Vector<3,T>
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
constexpr FORCEINLINE Vector<3,T>
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
constexpr FORCEINLINE Vector<3,T>
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
constexpr FORCEINLINE Vector<3,T>
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

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Basis<Base,T>& spaceB)
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

/* ####################################################################################### */
/* Local to local: Matrix4 */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
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
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
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

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Basis<Base,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), spaceB);
}

/* ####################################################################################### */
/* Local to local: Quaternion */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
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
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
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

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Basis<Base,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
}

/* ####################################################################################### */
/* Local to local: Quaternion with Position */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
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
constexpr FORCEINLINE Vector<3,T>
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
constexpr FORCEINLINE Vector<3,T>
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
constexpr FORCEINLINE Vector<3,T>
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
constexpr FORCEINLINE Vector<3,T>
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

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Basis<Base,T>& spaceB)
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

/* ####################################################################################### */
/* Local to local: Basis */
/* ####################################################################################### */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
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

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
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

template<EVectorRepresentation Representation, EBasisBase BaseA, EBasisBase BaseB, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<BaseA,T>& spaceA, const Basis<BaseB,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), spaceB);
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END