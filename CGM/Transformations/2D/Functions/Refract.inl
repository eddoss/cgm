

#include "Refract.hpp"


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

template<typename T>
constexpr enable_if_floating<T, void>
refract(Vector<2,T>& vector, const Vector<2,T>& axisNormal, T ior)
{
    T cosi = -dot(vector, axisNormal);
    T sint = ior * ior * (1 - cosi * cosi);

    if (sint > 1)
    {
        return;
    }

    T cost = std::sqrt(1 - sint);

    vector = ior * vector + (ior * cosi - cost) * axisNormal;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr enable_if_floating<T, Vector<2,T>>
refracted(const Vector<2,T>& vector, const Vector<2,T>& axisNormal, T ior)
{
    auto copy = vector;
    refract(copy, axisNormal, ior);
    return copy;
}


CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END