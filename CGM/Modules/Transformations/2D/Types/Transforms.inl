

#include "Transforms.hpp"


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<2,T>& t, const Vector<2,T>& s, T r)
    : pivot(x<T>(), y<T>(), Vector<2,T>(T(0)))
    , translation(t)
    , rotation(r)
    , scale(s)
    , uniformScale(T(1))
    , transformOrder(ETransformOrder::SRT)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<2,T>& t, const Vector<2,T>& s, T r, T us)
    : pivot(x<T>(), y<T>(), Vector<2,T>(T(0)))
    , translation(t)
    , rotation(r)
    , scale(s)
    , uniformScale(us)
    , transformOrder(ETransformOrder::SRT)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<2,T>& t, const Vector<2,T>& s, T r, const Pivot<T>& p)
    : pivot(p)
    , translation(t)
    , rotation(r)
    , scale(s)
    , uniformScale(T(1))
    , transformOrder(ETransformOrder::SRT)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<2,T>& t, const Vector<2,T>& s, T r, T us, const Pivot<T>& p)
    : pivot(p)
    , translation(t)
    , rotation(r)
    , scale(s)
    , uniformScale(us)
    , transformOrder(ETransformOrder::SRT)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<2,T>& t, const Vector<2,T>& s, T r, T us, const Pivot<T>& p, ETransformOrder to)
    : pivot(x<T>(), y<T>(), Vector<2,T>(T(0)))
    , translation(t)
    , rotation(r)
    , scale(s)
    , uniformScale(us)
    , transformOrder(to)
{

}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END
