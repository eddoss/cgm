

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
    return inverseForce(orientation) * vector;
#else
    return vector * inverseForce(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return inverseForce(orientation) * vector + position;
#else
    return vector * inverseForce(orientation) + position;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return _internal_multiply_matrix4x4_on_vector3(inverseForce(localSpace), vector);
#else
    return _internal_multiply_vector3_on_matrix4x4(vector, inverseForce(localSpace));
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientation)
{
    Vector<3,T> vec {vector};
    _internal_rotate_vector3_by_quaternion(vec, inverseForce(orientation));
    return vec;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    Vector<3,T> vec {vector};
    _internal_rotate_vector3_by_quaternion(vec, inverseForce(orientation));
    return vec + position;
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Basis<Base,T>& localSpace)
{
    if constexpr (Base == EBasisBase::Matrix3)
    {
        return globalToLocal(vector, localSpace.orientationMatrix(), localSpace.position());
    }
    else if constexpr (Base == EBasisBase::Matrix4)
    {
        return globalToLocal(vector, localSpace.spaceMatrix());
    }
    else if constexpr (Base == EBasisBase::Quaternion)
    {
        return globalToLocal(vector, localSpace.orientationQuaternion(), localSpace.position());
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

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return orientation * vector + position;
#else
    return vector * orientation + position;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return _internal_multiply_matrix4x4_on_vector3(localSpace, vector);
#else
    return _internal_multiply_vector3_on_matrix4x4(vector, localSpace);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& orientation)
{
    Vector<3,T> vec {vector};
    _internal_rotate_vector3_by_quaternion(vec, orientation);
    return vec;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    Vector<3,T> vec {vector};
    _internal_rotate_vector3_by_quaternion(vec, orientation);
    return vec + position;
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Basis<Base,T>& localSpace)
{
    if constexpr (Base == EBasisBase::Matrix3)
    {
        return localToGlobal(vector, localSpace.orientationMatrix(), localSpace.position());
    }
    else if constexpr (Base == EBasisBase::Matrix4)
    {
        return localToGlobal(vector, localSpace.spaceMatrix());
    }
    else if constexpr (Base == EBasisBase::Quaternion)
    {
        return localToGlobal(vector, localSpace.orientationQuaternion(), localSpace.position());
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

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, orientationA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Basis<Base,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, orientationA), spaceB);
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Basis<Base,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), spaceB);
}

/* ####################################################################################### */
/* Local to local: Matrix4 */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, spaceA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, spaceA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, spaceA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& spaceA, const Basis<Base,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, spaceA), spaceB);
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

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, orientationA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Basis<Base,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, orientationA), spaceB);
}

/* ####################################################################################### */
/* Local to local: Quaternion with Position */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Basis<Base,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), spaceB);
}

/* ####################################################################################### */
/* Local to local: Basis */
/* ####################################################################################### */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Matrix<3,3,T>& orientationB, const Matrix<3,3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, spaceA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, spaceA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Quaternion<T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<Base,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, spaceA), orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase BaseA, EBasisBase BaseB, typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Basis<BaseA,T>& spaceA, const Basis<BaseB,T>& spaceB)
{
    return globalToLocal(localToGlobal(vector, spaceA), spaceB);
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END