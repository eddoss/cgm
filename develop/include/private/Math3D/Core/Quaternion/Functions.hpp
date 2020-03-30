#ifndef MATH3D_PRIVATE_QUATERNION_FUNCTIONS_HPP
#define MATH3D_PRIVATE_QUATERNION_FUNCTIONS_HPP


#include <Math3D/Core/Quaternion/Functions.hpp>


MATH3D_NAMESPACE_BEGIN

template<typename T>
T
dot(const Quaternion<T> &A, const Quaternion<T> &B)
{
    return A | B;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>&
conjugate(Quaternion<T>& quaternion)
{
    quaternion.a *= -1;
    quaternion.b *= -1;
    quaternion.c *= -1;

    return quaternion;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
conjugated(const Quaternion<T>& quaternion)
{
    return Quaternion<T>
    {
        quaternion.s,
        quaternion.a * -1,
        quaternion.b * -1,
        quaternion.c * -1
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename TResult, typename T>
TResult
length(const Quaternion<T>& quaternion)
{
    TResult sum {dot(quaternion, quaternion)};
    TResult zer {zero<TResult>()};

    if (equal(sum,zer))
    {
        return zer;
    }
    else
    {
        return static_cast<TResult>(sqrt(sum));
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
T
lengthSquared(const Quaternion<T>& quaternion)
{
    return dot(quaternion, quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>&
normalize(Quaternion<T>& quaternion)
{
    T len {length<T>(quaternion)};

    if (notEqual(len, zero<T>()))
    {
        quaternion /= len;
    }

    return quaternion;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
normalized(const Quaternion<T>& quaternion)
{
    auto copy {quaternion};
    normalize(copy);
    return copy;
}

template<typename T>
Quaternion<T>&
invert(Quaternion<T>& quaternion)
{
    return conjugate(quaternion) /= lengthSquared(quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Quaternion<T>
inverted(const Quaternion<T>& quaternion)
{
    auto copy {quaternion};
    invert(copy);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>
identity()
{
    return Quaternion<T>
    {
        number<T>(1),
        zero<T>(),
        zero<T>(),
        zero<T>()
    };
}

MATH3D_NAMESPACE_END

#endif // MATH3D_PRIVATE_QUATERNION_FUNCTIONS_HPP
