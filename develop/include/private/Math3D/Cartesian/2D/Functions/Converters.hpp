

#include <Math3D/Cartesian/2D/Functions/Converters.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return inverseForce(localSpace) * vector;
#else
    return vector * inverseForce(localSpace);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return inverseForce(localSpace) * vector;
#else
    return vector * inverseForce(localSpace);
#endif
}

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<2,2,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return localSpace * vector;
#else
    return vector * localSpace;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace)
{
    Vector<2,T> oriented
    {
        vector * get2DBasisX(localSpace),
        vector * get2DBasisY(localSpace)
    };
    return oriented + get2DBasisPosition(localSpace);
}

/* ####################################################################################### */
/* Local to local */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& A, const Matrix<2,2,T>& B)
{
    return globalToLocal(localToGlobal(vector, A), B);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& A, const Matrix<2,2,T>& B)
{
    return globalToLocal(localToGlobal(vector, A), B);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& A, const Matrix<3,3,T>& B)
{
    return globalToLocal(localToGlobal(vector, A), B);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& A, const Matrix<3,3,T>& B)
{
    return globalToLocal(localToGlobal(vector, A), B);
}

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END