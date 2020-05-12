

#include <Math3D/Cartesian/Functions/CoordinateConverters.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Local to parent */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToParent(const Vector<2,T>& vector, const Matrix<2,2,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * localSpace;
#else
    return localSpace * vector;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<2,T>
localToParent(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace)
{
    Vector<2,T> oriented
    {
        vector * get2DBasisX(localSpace),
        vector * get2DBasisY(localSpace)
    };
    return oriented + get2DBasisPosition(localSpace);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToParent(const Vector<3,T>& vector, const Matrix<3,3,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * localSpace;
#else
    return localSpace * vector;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
localToParent(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{
    Vector<3,T> oriented
    {
        vector * get3DBasisX(localSpace),
        vector * get3DBasisY(localSpace),
        vector * get3DBasisZ(localSpace)
    };
    return oriented + get3DBasisPosition(localSpace);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
localToParent(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * basis3D(localSpaceOrientation);
#else
    return basis3D(localSpaceOrientation) * vector;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
localToParent(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation, const Vector<3,T>& localSpacePosition)
{
    auto orientation = basis3D(localSpaceOrientation);
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * orientation + localSpacePosition;
#else
    return orientation * vector + localSpacePosition;
#endif
}

/* ####################################################################################### */
/* Prent to local */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
parentToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * invertedForce(localSpace);
#else
    return invertedForce(localSpace) * vector;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
parentToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * invertedForce(localSpace);
#else
    return invertedForce(localSpace) * vector;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
parentToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * invertedForce(localSpace);
#else
    return invertedForce(localSpace) * vector;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
parentToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * invertedForce(localSpace);
#else
    return invertedForce(localSpace) * vector;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
parentToLocal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * invertedForce(basis3D(localSpaceOrientation));
#else
    return invertedForce(basis3D(localSpaceOrientation)) * vector;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
parentToLocal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation, const Vector<3,T>& localSpacePosition)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * invertedForce(basis3D(localSpaceOrientation, localSpacePosition));
#else
    return invertedForce(basis3D(localSpaceOrientation, localSpacePosition)) * vector;
#endif
}

/* ####################################################################################### */
/* Local to local */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& A, const Matrix<2,2,T>& B)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& localSpace)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
localToLocal(const Vector<3,T>& vector, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{

}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END