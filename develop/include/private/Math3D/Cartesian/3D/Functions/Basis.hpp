

#include <Math3D/Cartesian/3D/Functions/RawBasis.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
rawBasis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        x.x, x.y, x.z,
        y.x, y.y, y.z,
        z.x, z.y, z.z
    };
#else
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Matrix<4,4,T>
rawBasis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        x.x,  x.y,  x.z,  position.x,
        y.x,  y.y,  y.z,  position.y,
        z.x,  z.y,  z.z,  position.z,
        T(0), T(0), T(0),        T(1)
    };
#else
    {
               x.x,        y.x,        z.x, T(0),
               x.y,        y.y,        z.y, T(0),
               x.z,        y.z,        z.z, T(0),
        position.x, position.y, position.z, T(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Matrix<4,4,T>
rawBasis(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        orientation(0,0), orientation(0,1), orientation(0,2), position.x,
        orientation(1,0), orientation(1,1), orientation(1,2), position.y,
        orientation(2,0), orientation(2,1), orientation(2,2), position.z,
                    T(0),             T(0),             T(0),        T(1)
    };
#else
    {
        orientation(0,0), orientation(0,1), orientation(0,2), T(0),
        orientation(1,0), orientation(1,1), orientation(1,2), T(0),
        orientation(2,0), orientation(2,1), orientation(2,2), T(0),
              position.x,       position.y,       position.z, T(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<3,3,T>
rawBasis(const Quaternion<T>& orientation)
{
    Quaternion<T> conj {conjugated(orientation)};

    return rawBasis
    (
        (orientation * Quaternion<T>{0,T(1),0,0} * conj).imaginary(),
        (orientation * Quaternion<T>{0,0,T(1),0} * conj).imaginary(),
        (orientation * Quaternion<T>{0,0,0,T(1)} * conj).imaginary()
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
rawBasis(const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    Quaternion<T> conj {conjugated(orientation)};

    return rawBasis
    (
        (orientation * Quaternion<T>{0,T(1),0,0} * conj).imaginary(),
        (orientation * Quaternion<T>{0,0,T(1),0} * conj).imaginary(),
        (orientation * Quaternion<T>{0,0,0,T(1)} * conj).imaginary(),
        position
    );
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END