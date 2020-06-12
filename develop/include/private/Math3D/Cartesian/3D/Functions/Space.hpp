

#include <Math3D/Cartesian/3D/Functions/Space.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN


template<typename T>
constexpr FORCEINLINE Matrix<4,4,T>
space(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
{
    Matrix<4,4,T> mat;

    setX(mat,x);
    setY(mat,y);
    setZ(mat,z);

    mat(3,3) = number<T>(1);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    mat(3,0) = zero<T>;
    mat(3,1) = zero<T>;
    mat(3,2) = zero<T>;
#else
    mat(0,3) = zero<T>;
    mat(1,3) = zero<T>;
    mat(2,3) = zero<T>;
#endif
    setPosition(mat, position);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
space(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    Matrix<4,4,T> mat;

    mat(3,3) = number<T>(1);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    mat(3,0) = zero<T>;
    mat(3,1) = zero<T>;
    mat(3,2) = zero<T>;
#else
    mat(0,3) = zero<T>;
    mat(1,3) = zero<T>;
    mat(2,3) = zero<T>;
#endif

    setOrientation(mat, orientation);
    setPosition(mat, position);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
space(const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    Matrix<4,4,T> mat;

    mat(3,3) = number<T>(1);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    mat(3,0) = zero<T>;
    mat(3,1) = zero<T>;
    mat(3,2) = zero<T>;
#else
    mat(0,3) = zero<T>;
    mat(1,3) = zero<T>;
    mat(2,3) = zero<T>;
#endif

    setOrientation(mat, orientation);
    setPosition(mat, position);

    return mat;
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END