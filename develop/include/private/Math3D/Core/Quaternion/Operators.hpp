

#include <Math3D/Core/Quaternion/Operators.hpp>


template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator - (const MATH3D_NAMESPACE::Quaternion<T>& quaternion)
{
    return
    {
        -quaternion.s,
        -quaternion.a,
        -quaternion.b,
        -quaternion.c
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
        A.a - B.a,
        A.b - B.b,
        A.c - B.c
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator -= (MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    A.s -= B.s;
    A.a -= B.a;
    A.b -= B.b;
    A.c -= B.c;

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
        A.a + B.a,
        A.b + B.b,
        A.c + B.c
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator += (MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    A.s += B.s;
    A.a += B.a;
    A.b += B.b;
    A.c += B.c;

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
        quaternion.a * scl,
        quaternion.b * scl,
        quaternion.c * scl
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator * (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return
    {
        A.s * B.s - A.a * B.a - A.b * B.b - A.c * B.c,
        A.a * B.s + B.a * A.s + A.b * B.c - A.c * B.b,
        A.b * B.s + B.b * A.s + A.c * B.a - A.a * B.c,
        A.c * B.s + B.c * A.s + A.a * B.b - A.b * B.a
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename TScale>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator *= (MATH3D_NAMESPACE::Quaternion<T>& quaternion, TScale scale)
{
    quaternion.s *= scale;
    quaternion.a *= scale;
    quaternion.b *= scale;
    quaternion.c *= scale;

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
        quaternion.a / castedDivider,
        quaternion.b / castedDivider,
        quaternion.c / castedDivider
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename TDivider>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator /= (MATH3D_NAMESPACE::Quaternion<T>& quaternion, TDivider divider)
{
    T castedDivider = MATH3D_NAMESPACE::number<T>(divider);

    quaternion.s /= castedDivider;
    quaternion.a /= castedDivider;
    quaternion.b /= castedDivider;
    quaternion.c /= castedDivider;

    return quaternion;
}

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return  MATH3D_NAMESPACE::equal(A.s, B.s) &&
            MATH3D_NAMESPACE::equal(A.a, B.a) &&
            MATH3D_NAMESPACE::equal(A.b, B.b) &&
            MATH3D_NAMESPACE::equal(A.c, B.c);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return  MATH3D_NAMESPACE::notEqual(A.s, B.s) ||
            MATH3D_NAMESPACE::notEqual(A.a, B.a) ||
            MATH3D_NAMESPACE::notEqual(A.b, B.b) ||
            MATH3D_NAMESPACE::notEqual(A.c, B.c);
}

/* ####################################################################################### */
/* Dot product */
/* ####################################################################################### */

template<typename T>
constexpr T
operator | (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return  A.s * B.s +
            A.a * B.a +
            A.b * B.b +
            A.c * B.c;
}
