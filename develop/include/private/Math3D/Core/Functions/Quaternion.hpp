

#include <Math3D/Core/Functions/Quaternion.hpp>


MATH3D_NAMESPACE_BEGIN

template<typename T>
constexpr FORCEINLINE T
dot(const Quaternion<T> &A, const Quaternion<T> &B)
{
    return A | B;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr T
norm(const Quaternion<T>& quaternion)
{
    return quaternion.x * quaternion.x +
           quaternion.y * quaternion.y +
           quaternion.z * quaternion.z +
           quaternion.s * quaternion.s;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>&
conjugate(Quaternion<T>& quaternion)
{
    quaternion.x *= -1;
    quaternion.y *= -1;
    quaternion.z *= -1;

    return quaternion;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Quaternion<T>
conjugated(const Quaternion<T>& quaternion)
{
    return Quaternion<T>
    {
        quaternion.s,
        -quaternion.x,
        -quaternion.y,
        -quaternion.z
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
equal(const Quaternion<T>& A, const Quaternion<T>& B, T tolerance)
{
    return
    MATH3D_NAMESPACE::equal(A.s, B.s, tolerance) &&
    MATH3D_NAMESPACE::equal(A.x, B.x, tolerance) &&
    MATH3D_NAMESPACE::equal(A.y, B.y, tolerance) &&
    MATH3D_NAMESPACE::equal(A.z, B.z, tolerance);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
notEqual(const Quaternion<T>& A, const Quaternion<T>& B, T tolerance)
{
    return
    MATH3D_NAMESPACE::notEqual(A.s, B.s, tolerance) ||
    MATH3D_NAMESPACE::notEqual(A.x, B.x, tolerance) ||
    MATH3D_NAMESPACE::notEqual(A.y, B.y, tolerance) ||
    MATH3D_NAMESPACE::notEqual(A.z, B.z, tolerance);
}

MATH3D_NAMESPACE_END