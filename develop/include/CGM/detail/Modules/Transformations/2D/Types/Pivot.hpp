

#include <CGM/Modules/Transformations/2D/Types/Pivot.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

template<typename T>
constexpr
Pivot<T>::Pivot(const Vector<2,T>& X, const Vector<2,T>& Y)
    : axes(X, Y)
    , position(0,0)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Pivot<T>::Pivot(const Axes<T>& orientationAxes)
    : axes(orientationAxes)
    , position(0,0)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Pivot<T>::Pivot(const Vector<2,T>& X, const Vector<2,T>& Y, const Vector<2,T>& P)
    : axes(X, Y)
    , position(P)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Pivot<T>::Pivot(const Axes<T>& orientationAxes, const Vector<2,T>& P)
    : axes(orientationAxes)
    , position(P)
{

}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END