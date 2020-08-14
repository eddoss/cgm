

#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
Pivot<T>::Pivot(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z)
    : axes(X, Y, Z)
    , position(0,0,0)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Pivot<T>::Pivot(const Axes<T>& orientationAxes)
    : axes(orientationAxes)
    , position(0,0,0)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Pivot<T>::Pivot(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z, const Vector<3,T>& P)
    : axes(X, Y, Z)
    , position(P)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Pivot<T>::Pivot(const Axes<T>& orientationAxes, const Vector<3,T>& P)
    : axes(orientationAxes)
    , position(P)
{

}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END