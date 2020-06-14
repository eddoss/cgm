

#include <Math3D/Cartesian/2D/Functions/Orientation.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const Matrix<2,2,T>& orientation)
{
    return std::make_tuple(getX(orientation), getY(orientation));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE AxesTuple<T>
orientationAxes(const Matrix<3,3,T>& space)
{
    return std::make_tuple(getX(space), getY(space));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<2,2,T>
orientationMatrix(const Vector<2,T>& x, const Vector<2,T>& y)
{
    Matrix<2,2,T> mat;

    setX(mat,x);
    setY(mat,y);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<2,2,T>
orientationMatrix(const AxesTuple<T>& axes)
{
    Matrix<2,2,T> mat;

    setX(mat, std::get<0>(axes));
    setY(mat, std::get<1>(axes));

    return mat;
}

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END