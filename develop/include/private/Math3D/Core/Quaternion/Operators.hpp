

#include <Math3D/Core/Quaternion/Operators.hpp>


template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator - (const MATH3D_NAMESPACE::Quaternion<T>& quaternion)
{
    return
    {
        -quaternion.s,
        -quaternion.x,
        -quaternion.y,
        -quaternion.z
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator - (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return
    {
        A.s - B.s,
        A.x - B.x,
        A.y - B.y,
        A.z - B.z
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator -= (MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    A.s -= B.s;
    A.x -= B.x;
    A.y -= B.y;
    A.z -= B.z;

    return A;
}

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator + (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return
    {
        A.s + B.s,
        A.x + B.x,
        A.y + B.y,
        A.z + B.z
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator += (MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    A.s += B.s;
    A.x += B.x;
    A.y += B.y;
    A.z += B.z;

    return A;
}

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

template<typename T, typename TScale>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator * (const MATH3D_NAMESPACE::Quaternion<T>& quaternion, TScale scale)
{
    T scl {MATH3D_NAMESPACE::number<T>(scale)};

    return
    {
        quaternion.s * scl,
        quaternion.x * scl,
        quaternion.y * scl,
        quaternion.z * scl
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator * (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return
    {
        A.s * B.s - A.x * B.x - A.y * B.y - A.z * B.z,
        A.x * B.s + B.x * A.s + A.y * B.z - A.z * B.y,
        A.y * B.s + B.y * A.s + A.z * B.x - A.x * B.z,
        A.z * B.s + B.z * A.s + A.x * B.y - A.y * B.x
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename TScale>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator *= (MATH3D_NAMESPACE::Quaternion<T>& quaternion, TScale scale)
{
    quaternion.s *= scale;
    quaternion.x *= scale;
    quaternion.y *= scale;
    quaternion.z *= scale;

    return quaternion;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator *= (MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    A = A * B;

    return A;
}

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

template<typename T, typename TDivider>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator / (const MATH3D_NAMESPACE::Quaternion<T>& quaternion, TDivider divider)
{
    T castedDivider = MATH3D_NAMESPACE::number<T>(divider);

    return
    {
        quaternion.s / castedDivider,
        quaternion.x / castedDivider,
        quaternion.y / castedDivider,
        quaternion.z / castedDivider
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename TDivider>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator /= (MATH3D_NAMESPACE::Quaternion<T>& quaternion, TDivider divider)
{
    T castedDivider = MATH3D_NAMESPACE::number<T>(divider);

    quaternion.s /= castedDivider;
    quaternion.x /= castedDivider;
    quaternion.y /= castedDivider;
    quaternion.z /= castedDivider;

    return quaternion;
}

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return MATH3D_NAMESPACE::equal(A.s, B.s) &&
           MATH3D_NAMESPACE::equal(A.x, B.x) &&
           MATH3D_NAMESPACE::equal(A.y, B.y) &&
           MATH3D_NAMESPACE::equal(A.z, B.z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return MATH3D_NAMESPACE::notEqual(A.s, B.s) ||
           MATH3D_NAMESPACE::notEqual(A.x, B.x) ||
           MATH3D_NAMESPACE::notEqual(A.y, B.y) ||
           MATH3D_NAMESPACE::notEqual(A.z, B.z);
}

/* ####################################################################################### */
/* Dot product */
/* ####################################################################################### */

template<typename T>
constexpr T
operator | (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return  A.s * B.s +
            A.x * B.x +
            A.y * B.y +
            A.z * B.z;
}
