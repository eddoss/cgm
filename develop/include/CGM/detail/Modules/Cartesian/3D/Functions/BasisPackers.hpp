

#include <CGM/Modules/Cartesian/3D/Functions/BasisPackers.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
packBasis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        x.x, x.y, x.z, position.x,
        y.x, y.y, y.z, position.y,
        z.x, z.y, z.z, position.z,
        zero<T>, zero<T>, zero<T>, number<T>(1)
    };
#else
    return
    {
        x.x, y.x, z.x, zero<T>,
        x.y, y.y, z.y, zero<T>,
        x.z, y.z, z.z, zero<T>,
        position.x, position.y, position.z, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
packBasis(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        orientation(0,0), orientation(0,1), orientation(0,2), position.x,
        orientation(1,0), orientation(1,1), orientation(1,2), position.y,
        orientation(2,0), orientation(2,1), orientation(2,2), position.z,
        zero<T>, zero<T>, zero<T>, number<T>(1)
    };
#else
    return
    {
        orientation(0,0), orientation(0,1), orientation(0,2), zero<T>,
        orientation(1,0), orientation(1,1), orientation(1,2), zero<T>,
        orientation(2,0), orientation(2,1), orientation(2,2), zero<T>,
        position.x, position.y, position.z, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
packBasis(const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    return packBasis
    (
        oriented({T(1),T(0),T(0)}, orientation),
        oriented({T(0),T(1),T(0)}, orientation),
        oriented({T(0),T(0),T(1)}, orientation),
        position
    );
}

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END