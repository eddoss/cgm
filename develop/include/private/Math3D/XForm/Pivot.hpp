
#include <Math3D/XForm/Pivot.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

template<size_t D, typename T>
constexpr
Pivot<D, T, std::enable_if_t<(D == 2)>>::Pivot(const Vector<D,T>& InX, const Vector<D,T>& InY, const Vector<D,T>& InPosition)
    : x(InX)
    , y(InY)
    , position(InPosition)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr
Pivot<D, T, std::enable_if_t<(D == 3)>>::Pivot(const Vector<D,T>& InX, const Vector<D,T>& InY, const Vector<D,T>& InZ, const Vector<D,T>& InPosition)
    : x(InX)
    , y(InY)
    , z(InZ)
    , position(InPosition)
{

}

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END