

#include <Math3D/Core/Quaternion/Operators.hpp>


template<typename T>
MATH3D_NAMESPACE::Quaternion<T>
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
MATH3D_NAMESPACE::Quaternion<T>
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
MATH3D_NAMESPACE::Quaternion<T>&
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
MATH3D_NAMESPACE::Quaternion<T>
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
MATH3D_NAMESPACE::Quaternion<T>&
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
MATH3D_NAMESPACE::Quaternion<T>
operator * (const MATH3D_NAMESPACE::Quaternion<T>& quaternion, TScale scale)
{
    T scl {static_cast<T>(scale)};

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
MATH3D_NAMESPACE::Quaternion<T>
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
MATH3D_NAMESPACE::Quaternion<T>&
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
MATH3D_NAMESPACE::Quaternion<T>&
operator *= (MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    A = A * B;

    return A;
}

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

template<typename T, typename TScale>
MATH3D_NAMESPACE::Quaternion<T>
operator / (const MATH3D_NAMESPACE::Quaternion<T>& quaternion, TScale scale)
{
    return
    {
        quaternion.s / scale,
        quaternion.a / scale,
        quaternion.b / scale,
        quaternion.c / scale
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename TScale>
MATH3D_NAMESPACE::Quaternion<T>&
operator /= (MATH3D_NAMESPACE::Quaternion<T>& quaternion, TScale scale)
{
    quaternion.s /= scale;
    quaternion.a /= scale;
    quaternion.b /= scale;
    quaternion.c /= scale;

    return quaternion;
}

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

template<typename T>
bool
operator == (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return  equal(A.s, B.s) &&
            equal(A.a, B.a) &&
            equal(A.b, B.b) &&
            equal(A.c, B.c);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
bool
operator != (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return  notEqual(A.s, B.s) ||
            notEqual(A.a, B.a) ||
            notEqual(A.b, B.b) ||
            notEqual(A.c, B.c);
}

/* ####################################################################################### */
/* Dot product */
/* ####################################################################################### */

template<typename T>
T
operator | (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return A.s * B.s + A.a * B.a + A.b * B.b + A.c * B.c;
}
