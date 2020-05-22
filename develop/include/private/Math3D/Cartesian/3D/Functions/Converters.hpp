

#include <Math3D/Cartesian/3D/Functions/Converters.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return invertedForce(localSpace) * vector;
#else
    return vector * invertedForce(localSpace);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return invertedForce(localSpace) * vector;
#else
    return vector * invertedForce(localSpace);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return invertedForce(basis3D(localSpaceOrientation)) * vector;
#else
    return vector * invertedForce(basis3D(localSpaceOrientation));
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
globalToLocal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation, const Vector<3,T>& localSpacePosition)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return invertedForce(basis3D(localSpaceOrientation, localSpacePosition)) * vector;
#else
    return vector * invertedForce(basis3D(localSpaceOrientation, localSpacePosition));
#endif
}

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<3,3,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return localSpace * vector;
#else
    return vector * localSpace;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{
    Vector<3,T> oriented
    {
        vector * _internal_get_basis_x(localSpace),
        vector * _internal_get_basis_y(localSpace),
        vector * _internal_get_basis_z(localSpace)
    };
    return oriented + _internal_get_basis_position(localSpace);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return basis3D(localSpaceOrientation) * vector;
#else
    return vector * basis3D(localSpaceOrientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
localToGlobal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation, const Vector<3,T>& localSpacePosition)
{
    auto orientation = basis3D(localSpaceOrientation);
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return orientation * vector + localSpacePosition;
#else
    return vector * orientation + localSpacePosition;
#endif
}

/* ####################################################################################### */
/* Local to local */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& A, const Matrix<3,3,T>& B)
{
    return globalToLocal(localToGlobal(vector, A), B);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& A, const Matrix<4,4,T>& B)
{
    return globalToLocal(localToGlobal(vector, A), B);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& A, const Matrix<4,4,T>& B)
{
    return globalToLocal(localToGlobal(vector, A), B);
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
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    return globalToLocal(localToGlobal(vector, orientationA, positionA), orientationB, positionB);
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END