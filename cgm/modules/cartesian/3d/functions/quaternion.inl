

#include "quaternion.hpp"


CGM_NAMESPACE_BEGIN


template<typename T>
constexpr CGM_FORCEINLINE T
dot(const Quaternion<T> &A, const Quaternion<T> &B)
{
    return
    A.vector.x * B.vector.x +
    A.vector.y * B.vector.y +
    A.vector.z * B.vector.z +
    A.scalar * B.scalar;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr T
norm(const Quaternion<T>& quaternion)
{
    return
    quaternion.vector.x * quaternion.vector.x +
    quaternion.vector.y * quaternion.vector.y +
    quaternion.vector.z * quaternion.vector.z +
    quaternion.scalar * quaternion.scalar;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>&
conjugate(Quaternion<T>& quaternion)
{
    quaternion.vector.x *= -1;
    quaternion.vector.y *= -1;
    quaternion.vector.z *= -1;

    return quaternion;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
conjugated(const Quaternion<T>& quaternion)
{
    return Quaternion<T> {-quaternion.vector, quaternion.scalar};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr T
length(const Quaternion<T>& quaternion)
{
    T nrm {norm(quaternion)};

    if (CGM::eq(nrm, T(0)))
    {
        return T(0);
    }
    else
    {
        return std::sqrt(nrm);
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
normalizeSafe(Quaternion<T>& quaternion, T lengthTolerance)
{
    T len {length<T>(quaternion)};

    if (len >= lengthTolerance)
    {
        quaternion /= len;
        return true;
    }

    return false;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>
normalizedSafe(const Quaternion<T>& quaternion, bool& success, T lengthTolerance)
{
    T len {length<T>(quaternion)};

    if (len >= lengthTolerance)
    {
        success = true;
        return quaternion / len;
    }
    else
    {
        success = false;
        return quaternion;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
normalize(Quaternion<T>& quaternion)
{
    quaternion /= length(quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
normalized(const Quaternion<T>& quaternion)
{
    return quaternion / length(quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
invertSafe(Quaternion<T>& quaternion, T normTolerance)
{
    auto nrm {norm(quaternion)};

    if (std::abs(nrm) >= normTolerance)
    {
        quaternion = conjugate(quaternion) /= nrm;
        return true;
    }
    else
    {
        return false;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>
inverseSafe(const Quaternion<T>& quaternion, bool& success, T normTolerance)
{
    auto nrm {norm(quaternion)};

    if (std::abs(nrm) >= normTolerance)
    {
        success = true;
        return conjugated(quaternion) / nrm;
    }
    else
    {
        success = false;
        return quaternion;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
invert(Quaternion<T>& quaternion)
{
    conjugate(quaternion);
    quaternion /= norm(quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
inverse(const Quaternion<T>& quaternion)
{
    return conjugated(quaternion) / norm(quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
orient(Vector<3,T>& vector, const Quaternion<T>& quaternion)
{
#ifdef CGM_CFG_LHS
    auto t = static_cast<T>(2) * cross(vector, quaternion.vector);
    vector += cross(t, quaternion.vector);
#else
    auto t = static_cast<T>(2) * cross(quaternion.vector, vector);
    vector += cross(quaternion.vector, t);
#endif

    vector += quaternion.scalar * t;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
oriented(const Vector<3,T>& vector, const Quaternion<T>& quaternion)
{
    Vector<3,T> result {vector};
    orient(result, quaternion);
    return result;
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
    return Quaternion<T> {T(0), T(1)};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
eq(const Quaternion<T>& A, const Quaternion<T>& B, T tolerance)
{
    return
    CGM::eq(A.vector.x, B.vector.x, tolerance) &&
    CGM::eq(A.vector.y, B.vector.y, tolerance) &&
    CGM::eq(A.vector.z, B.vector.z, tolerance) &&
    CGM::eq(A.scalar, B.scalar, tolerance);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
neq(const Quaternion<T>& A, const Quaternion<T>& B, T tolerance)
{
    return
    CGM::neq(A.vector.x, B.vector.x, tolerance) ||
    CGM::neq(A.vector.y, B.vector.y, tolerance) ||
    CGM::neq(A.vector.z, B.vector.z, tolerance) ||
    CGM::neq(A.scalar, B.scalar, tolerance);
}

CGM_NAMESPACE_END