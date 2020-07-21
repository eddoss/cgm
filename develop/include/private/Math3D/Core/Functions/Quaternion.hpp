

#include <Math3D/Core/Functions/Quaternion.hpp>


MATH3D_NAMESPACE_BEGIN

template<typename T>
constexpr FORCEINLINE T
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
constexpr FORCEINLINE Quaternion<T>
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

    if (MATH3D_NAMESPACE::equal(nrm, zero<T>))
    {
        return zero<T>;
    }
    else
    {
        return std::sqrt(nrm);
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
normalize(Quaternion<T>& quaternion, T lengthTolerance)
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
normalized(const Quaternion<T>& quaternion, bool& success, T lengthTolerance)
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
constexpr FORCEINLINE void
normalizeForce(Quaternion<T>& quaternion)
{
    quaternion /= length(quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Quaternion<T>
normalizedForce(const Quaternion<T>& quaternion)
{
    return quaternion / length(quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
invert(Quaternion<T>& quaternion, T normTolerance)
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
inverse(const Quaternion<T>& quaternion, bool& success, T normTolerance)
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
constexpr FORCEINLINE void
invertForce(Quaternion<T>& quaternion)
{
    conjugate(quaternion);
    quaternion /= norm(quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Quaternion<T>
inverseForce(const Quaternion<T>& quaternion)
{
    return conjugated(quaternion) / norm(quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
orient(Vector<3,T>& vector, const Quaternion<T>& quaternion)
{
    auto t = static_cast<T>(2) * cross(vector, quaternion.vector);
    vector += cross(t, quaternion.vector);
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
    return Quaternion<T> {zero<T>, number<T>(1)};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
equal(const Quaternion<T>& A, const Quaternion<T>& B, T tolerance)
{
    return
    MATH3D_NAMESPACE::equal(A.vector.x, B.vector.x, tolerance) &&
    MATH3D_NAMESPACE::equal(A.vector.y, B.vector.y, tolerance) &&
    MATH3D_NAMESPACE::equal(A.vector.z, B.vector.z, tolerance) &&
    MATH3D_NAMESPACE::equal(A.scalar, B.scalar, tolerance);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
notEqual(const Quaternion<T>& A, const Quaternion<T>& B, T tolerance)
{
    return
    MATH3D_NAMESPACE::notEqual(A.vector.x, B.vector.x, tolerance) ||
    MATH3D_NAMESPACE::notEqual(A.vector.y, B.vector.y, tolerance) ||
    MATH3D_NAMESPACE::notEqual(A.vector.z, B.vector.z, tolerance) ||
    MATH3D_NAMESPACE::notEqual(A.scalar, B.scalar, tolerance);
}

MATH3D_NAMESPACE_END