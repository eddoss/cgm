

#include <Math3D/Cartesian/2D/Functions/Space.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

template<typename T>
constexpr Matrix<3,3,T>
space(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position)
{
    Matrix<3,3,T> mat;

    setX(mat,x);
    setY(mat,y);

    mat(2,2) = number<T>(1);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    mat(2,0) = zero<T>;
    mat(2,1) = zero<T>;
#else
    mat(0,2) = zero<T>;
    mat(1,2) = zero<T>;
#endif
    setPosition(mat, position);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<3,3,T>
space(const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
    Matrix<3,3,T> mat;

    mat(2,2) = number<T>(1);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    mat(2,0) = zero<T>;
    mat(2,1) = zero<T>;
#else
    mat(0,2) = zero<T>;
    mat(1,2) = zero<T>;
#endif

    setPosition(mat, position);
    setOrientation(mat, orientation);

    return mat;
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END