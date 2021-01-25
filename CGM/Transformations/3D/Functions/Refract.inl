

#include "Refract.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

template<EPlane Plane, typename T>
constexpr void
refract(Vector<3,T>& vector, T ior)
{
    T cosi;

    if constexpr (Plane == EPlane::XY)
    {
        cosi = -vector.z;
    }
    else if constexpr (Plane == EPlane::YZ)
    {
        cosi = -vector.x;
    }
    else
    {
        cosi = -vector.y;
    }

    T sint = ior * ior * (1 - cosi * cosi);

    if (sint > 1)
    {
        return;
    }

    T cost = std::sqrt(1 - sint);

    vector *= ior;

    if constexpr (Plane == EPlane::XY)
    {
        vector.z += ior * cosi - cost;
    }
    else if constexpr (Plane == EPlane::YZ)
    {
        vector.x += ior * cosi - cost;
    }
    else
    {
        vector.y += ior * cosi - cost;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
refract(Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior)
{
    T cosi = -dot(vector, planeNormal);
    T sint = ior * ior * (1 - cosi * cosi);

    if (sint > 1)
    {
        return;
    }

    T cost = std::sqrt(1 - sint);

    vector = ior * vector + (ior * cosi - cost) * planeNormal;
}

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

template<EPlane Plane, typename T>
constexpr Vector<3,T>
refracted(const Vector<3,T>& vector, T ior)
{
    auto copy = vector;
    refract<Plane>(copy, ior);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
refracted(const Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior)
{
    auto copy = vector;
    refract(copy, planeNormal, ior);
    return copy;
}

CGM_NAMESPACE_END