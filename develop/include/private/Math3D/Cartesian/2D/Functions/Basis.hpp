

#include <Math3D/Cartesian/2D/Functions/RawBasis.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
rawBasis(const Vector<2,T>& x, const Vector<2,T>& y)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        x.x, y.x,
        x.y, y.y
    };
#else
    {
        x.x, x.y,
        y.x, y.y
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
rawBasis(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
               x.x,        y.x, T(0),
               x.y,        y.y, T(0),
        position.x, position.y, T(1)
    };
#else
    {
        x.x,  x.y,  position.x,
        y.x,  y.y,  position.y,
        T(0), T(0), T(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
rawBasis(const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        orientation(0,0), orientation(0,1), T(0),
        orientation(1,0), orientation(1,1), T(0),
              position.x,       position.y, T(1)
    };
#else
    {
        orientation(0,0), orientation(0,1), position.x,
        orientation(1,0), orientation(1,1), position.y,
                    T(0),             T(0),        T(1)
    };
#endif
}

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END