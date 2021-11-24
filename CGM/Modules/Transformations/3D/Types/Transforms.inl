

#include "Transforms.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r)
    : pivot(x<T>(), y<T>(), z<T>(), Vector<3,T>(T(0)))
    , translation(t)
    , rotation(r)
    , scale(s)
    , uniformScale(T(1))
    , transformOrder(ETransformOrder::SRT)
    , rotationOrder(ERotationOrder::XYZ)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r, const Pivot<T>& p)
    : pivot(p)
    , translation(t)
    , rotation(r)
    , scale(s)
    , uniformScale(T(1))
    , transformOrder(ETransformOrder::SRT)
    , rotationOrder(ERotationOrder::XYZ)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r, T us)
    : pivot(x<T>(), y<T>(), z<T>(), Vector<3,T>(T(0)))
    , translation(t)
    , rotation(r)
    , scale(s)
    , uniformScale(us)
    , transformOrder(ETransformOrder::SRT)
    , rotationOrder(ERotationOrder::XYZ)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r, T us, const Pivot<T>& p)
    : pivot(p)
    , translation(t)
    , rotation(r)
    , scale(s)
    , uniformScale(us)
    , transformOrder(ETransformOrder::SRT)
    , rotationOrder(ERotationOrder::XYZ)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r, T us, const Pivot<T>& p, ERotationOrder ro, ETransformOrder to)
    : pivot(p)
    , translation(t)
    , rotation(r)
    , scale(s)
    , uniformScale(us)
    , transformOrder(to)
    , rotationOrder(ro)
{

}

CGM_NAMESPACE_END
