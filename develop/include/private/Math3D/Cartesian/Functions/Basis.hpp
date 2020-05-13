

#include <Math3D/Cartesian/Functions/Basis.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* 2D */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
basis2D(const Vector<2,T>& x, const Vector<2,T>& y)
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
basis2D(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position)
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
basis2D(const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
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

/* ####################################################################################### */
/* 3D */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
basis3D(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };
#else
    {
        x.x, x.y, x.z,
        y.x, y.y, y.z,
        z.x, z.y, z.z
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Matrix<4,4,T>
basis3D(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
               x.x,        y.x,        z.x, T(0),
               x.y,        y.y,        z.y, T(0),
               x.z,        y.z,        z.z, T(1),
        position.x, position.y, position.y, T(1)
    };
#else
    {
         x.x,  x.y,  x.z,  position.x,
         y.x,  y.y,  y.z,  position.y,
         z.x,  z.y,  z.z,  position.z,
        T(0), T(0), T(0),        T(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Matrix<4,4,T>
basis3D(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        orientation(0,0), orientation(0,1), orientation(0,2), T(0),
        orientation(1,0), orientation(1,1), orientation(1,2), T(0),
        orientation(2,0), orientation(2,1), orientation(2,2), T(0),
              position.x,       position.y,       position.z, T(1)
    };
#else
    {
        orientation(0,0), orientation(0,1), orientation(0,2), position.x,
        orientation(1,0), orientation(1,1), orientation(1,2), position.y,
        orientation(2,0), orientation(2,1), orientation(2,2), position.z,
                    T(0),             T(0),             T(0),        T(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<3,3,T>
basis3D(const Quaternion<T>& orientation)
{
    Quaternion<T> conj {conjugated(orientation)};

    return basis3D
    (
        (orientation * Quaternion<T>{0,T(1),0,0} * conj).xyz(),
        (orientation * Quaternion<T>{0,0,T(1),0} * conj).xyz(),
        (orientation * Quaternion<T>{0,0,0,T(1)} * conj).xyz()
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
basis3D(const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    Quaternion<T> conj {conjugated(orientation)};

    return basis3D
    (
        (orientation * Quaternion<T>{0,T(1),0,0} * conj).xyz(),
        (orientation * Quaternion<T>{0,0,T(1),0} * conj).xyz(),
        (orientation * Quaternion<T>{0,0,0,T(1)} * conj).xyz(),
        position
    );
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END