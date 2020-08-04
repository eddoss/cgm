

#include <CGM/Cartesian/2D/Functions/BasisPackers.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
packBasis(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        x.x, x.y, position.x,
        y.x, y.y, position.y,
        zero<T>, zero<T>, number<T>(1)
    };
#else
    return
    {
        x.x, y.x, zero<T>,
        x.y, y.y, zero<T>,
        position.x, position.y, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
packBasis(const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        orientation(0,0), orientation(0,1), position.x,
        orientation(1,0), orientation(1,1), position.y,
        zero<T>, zero<T>, number<T>(1)
    };
#else
    return
    {
        orientation(0,0), orientation(0,1), zero<T>,
        orientation(1,0), orientation(1,1), zero<T>,
        position.x, position.y, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE SpaceTuple<T>
unpackBasis(const Matrix<3,3,T>& matrix)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return std::make_tuple
    (
        Vector<2,T>{matrix(0,0), matrix(0,1)},
        Vector<2,T>{matrix(1,0), matrix(1,1)},
        Vector<2,T>{matrix(0,2), matrix(1,2)}
    );
#else
    return std::make_tuple
    (
        Vector<2,T>{matrix(0,0), matrix(1,0)},
        Vector<2,T>{matrix(0,1), matrix(1,1)},
        Vector<2,T>{matrix(2,0), matrix(2,1)}
    );
#endif
}

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END