

#include <CGM/Cartesian/2D/Functions/Orientation.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Vector<2,T>& x, const Vector<2,T>& y)
{
    return Axes<T>(x,y);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Matrix<2,2,T>& orientation)
{
#ifdef CGM_MATRIX_POST_MULTIPLICATION
    return Axes<T>
    (
        Vector<2,T>{orientation(0,0), orientation(0,1)},
        Vector<2,T>{orientation(1,0), orientation(1,1)}
    );
#else
    return Axes<T>
    (
        Vector<2,T>{orientation(0,0), orientation(1,0)},
        Vector<2,T>{orientation(0,1), orientation(1,1)}
    );
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Matrix<3,3,T>& space)
{
#ifdef CGM_MATRIX_POST_MULTIPLICATION
    return Axes<T>
    (
        Vector<2,T>{space(0,0), space(0,1)},
        Vector<2,T>{space(1,0), space(1,1)}
    );
#else
    return Axes<T>
    (
        Vector<2,T>{space(0,0), space(1,0)},
        Vector<2,T>{space(0,1), space(1,1)}
    );
#endif
}

/* ####################################################################################### */
/* Matrix */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
orientationMatrix(const Vector<2,T>& x, const Vector<2,T>& y)
{
#ifdef CGM_MATRIX_POST_MULTIPLICATION
    return
    {
        x.x, x.y,
        y.x, y.y
    };
#else
    return
    {
        x.x, y.x,
        x.y, y.y
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
orientationMatrix(const Axes<T>& axes)
{
    return orientationMatrix
    (
        x(axes),
        y(axes)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
orientationMatrix(const Matrix<3,3,T>& space)
{
    return
    {
        space(0,0), space(0,1),
        space(1,0), space(1,1)
    };
}

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END