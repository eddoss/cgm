

#include <CGM/Modules/Transformations/3D/Types/Transforms.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r)
    : pivot(x<T>(), y<T>(), z<T>(), Vector<3,T>(zero<T>))
    , translations(t)
    , rotations(r)
    , scales(s)
    , uniformScale(number<T>(1))
    , transformOrder(ETransformOrder::SRT)
    , rotationOrder(ERotationOrder::XYZ)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r, const Pivot<T>& p)
    : pivot(p)
    , translations(t)
    , rotations(r)
    , scales(s)
    , uniformScale(number<T>(1))
    , transformOrder(ETransformOrder::SRT)
    , rotationOrder(ERotationOrder::XYZ)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr
Transforms<T>::Transforms(const Vector<3,T>& t, const Vector<3,T>& s, const Vector<3,T>& r, T us)
    : pivot(x<T>(), y<T>(), z<T>(), Vector<3,T>(zero<T>))
    , translations(t)
    , rotations(r)
    , scales(s)
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
    , translations(t)
    , rotations(r)
    , scales(s)
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
    , translations(t)
    , rotations(r)
    , scales(s)
    , uniformScale(us)
    , transformOrder(to)
    , rotationOrder(ro)
{

}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END