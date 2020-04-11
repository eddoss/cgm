

#include <Math3D/Core/Quaternion/Functions.hpp>


MATH3D_NAMESPACE_BEGIN

template<typename T>
constexpr T
dot(const Quaternion<T> &A, const Quaternion<T> &B)
{
    return A | B;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr T
norm(const Quaternion<T>& quaternion)
{
    return  quaternion.a * quaternion.a +
            quaternion.b * quaternion.b +
            quaternion.c * quaternion.c +
            quaternion.s * quaternion.s;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>&
conjugate(Quaternion<T>& quaternion)
{
    quaternion.a *= -1;
    quaternion.b *= -1;
    quaternion.c *= -1;

    return quaternion;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>
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

template<typename T>
constexpr T
length(const Quaternion<T>& quaternion)
{
    T nrm {norm(quaternion)};

    if (equal(nrm, zero<T>))
    {
        return zero<T>;
    }
    else
    {
        return sqrt(nrm);
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>&
normalize(Quaternion<T>& quaternion)
{
    T len {length<T>(quaternion)};

    if (notEqual(len, zero<T>))
    {
        quaternion /= len;
    }

    return quaternion;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>
normalized(const Quaternion<T>& quaternion)
{
    auto copy {quaternion};
    normalize(copy);
    return copy;
}

template<typename T>
constexpr Quaternion<T>&
invert(Quaternion<T>& quaternion)
{
    return conjugate(quaternion) /= norm(quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>
inverted(const Quaternion<T>& quaternion)
{
    auto copy {quaternion};
    invert(copy);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr T
angle(const Quaternion<T>& A, const Quaternion<T>& B)
{
    return 2 * std::acos(dot(A,B));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>
identity()
{
    return Quaternion<T>
    {
        number<T>(1),
        zero<T>,
        zero<T>,
        zero<T>
    };
}

MATH3D_NAMESPACE_END