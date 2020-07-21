

#include <Math3D/Core/Operators/Quaternion.hpp>


template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator - (const MATH3D_NAMESPACE::Quaternion<T>& quaternion)
{
    return {-quaternion.vector, -quaternion.scalar};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator - (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return
    {
        A.vector.x - B.vector.x,
        A.vector.y - B.vector.y,
        A.vector.z - B.vector.z,
        A.scalar - B.scalar,
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator -= (MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    A.vector.x -= B.vector.x;
    A.vector.y -= B.vector.y;
    A.vector.z -= B.vector.z;
    A.scalar -= B.scalar;

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
        A.vector.x + B.vector.x,
        A.vector.y + B.vector.y,
        A.vector.z + B.vector.z,
        A.scalar + B.scalar
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator += (MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    A.vector.x += B.vector.x;
    A.vector.y += B.vector.y;
    A.vector.z += B.vector.z;
    A.scalar += B.scalar;

    return A;
}

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

template<typename T, typename TScale>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator * (const MATH3D_NAMESPACE::Quaternion<T>& quaternion, TScale scale)
{
    if constexpr (std::is_same_v<T, TScale>)
    {
        return
        {
            quaternion.vector.x * scale,
            quaternion.vector.y * scale,
            quaternion.vector.z * scale,
            quaternion.scalar * scale
        };
    }
    else
    {
        T castedScale = MATH3D_NAMESPACE::number<T>(scale);

        return
        {
            quaternion.vector.x * castedScale,
            quaternion.vector.y * castedScale,
            quaternion.vector.z * castedScale,
            quaternion.scalar * castedScale
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr MATH3D_NAMESPACE::Quaternion<T>
operator * (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
//    return
//    {
//        A.vector.x * B.scalar + B.vector.x * A.scalar + A.vector.y * B.vector.z - A.vector.z * B.vector.y,
//        A.vector.y * B.scalar + B.vector.y * A.scalar + A.vector.z * B.vector.x - A.vector.x * B.vector.z,
//        A.vector.z * B.scalar + B.vector.z * A.scalar + A.vector.x * B.vector.y - A.vector.y * B.vector.x,
//        A.scalar * B.scalar - A.vector.x * B.vector.x - A.vector.y * B.vector.y - A.vector.z * B.vector.z
//    };
    return MATH3D_NAMESPACE::Quaternion<T>
    {
        A.vector * B.scalar + B.vector * A.scalar + MATH3D_NAMESPACE::cross(A.vector, B.vector),
        A.scalar * B.scalar - (A.vector.x * B.vector.x + A.vector.y * B.vector.y + A.vector.z * B.vector.z)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename TScale>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator *= (MATH3D_NAMESPACE::Quaternion<T>& quaternion, TScale scale)
{
    if constexpr (std::is_same_v<T, TScale>)
    {
        quaternion.vector.x *= scale;
        quaternion.vector.y *= scale;
        quaternion.vector.z *= scale;
        quaternion.scalar *= scale;
    }
    else
    {
        T castedScale = MATH3D_NAMESPACE::number<T>(scale);

        quaternion.vector.x *= castedScale;
        quaternion.vector.y *= castedScale;
        quaternion.vector.z *= castedScale;
        quaternion.scalar *= castedScale;
    }

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
    if constexpr (std::is_same_v<T, TDivider>)
    {
        return
        {
            quaternion.vector.x / divider,
            quaternion.vector.y / divider,
            quaternion.vector.z / divider,
            quaternion.scalar / divider
        };
    }
    else
    {
        T castedDivider = MATH3D_NAMESPACE::number<T>(divider);

        return
        {
            quaternion.vector.x / castedDivider,
            quaternion.vector.y / castedDivider,
            quaternion.vector.z / castedDivider,
            quaternion.scalar / castedDivider
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename TDivider>
constexpr MATH3D_NAMESPACE::Quaternion<T>&
operator /= (MATH3D_NAMESPACE::Quaternion<T>& quaternion, TDivider divider)
{
    if constexpr (std::is_same_v<T, TDivider>)
    {
        quaternion.vector.x /= divider;
        quaternion.vector.y /= divider;
        quaternion.vector.z /= divider;
        quaternion.scalar /= divider;
    }
    else
    {
        T castedDivider = MATH3D_NAMESPACE::number<T>(divider);

        quaternion.vector.x /= castedDivider;
        quaternion.vector.y /= castedDivider;
        quaternion.vector.z /= castedDivider;
        quaternion.scalar /= castedDivider;
    }

    return quaternion;
}

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return
    MATH3D_NAMESPACE::equal(A.vector.x, B.vector.x) &&
    MATH3D_NAMESPACE::equal(A.vector.y, B.vector.y) &&
    MATH3D_NAMESPACE::equal(A.vector.z, B.vector.z) &&
    MATH3D_NAMESPACE::equal(A.scalar, B.scalar);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    return
    MATH3D_NAMESPACE::notEqual(A.vector.x, B.vector.x) ||
    MATH3D_NAMESPACE::notEqual(A.vector.y, B.vector.y) ||
    MATH3D_NAMESPACE::notEqual(A.vector.z, B.vector.z) ||
    MATH3D_NAMESPACE::notEqual(A.scalar, B.scalar);
}

/* ####################################################################################### */
/* Dot product */
/* ####################################################################################### */

template<typename T>
constexpr T
operator | (const MATH3D_NAMESPACE::Quaternion<T>& A, const MATH3D_NAMESPACE::Quaternion<T>& B)
{
    A.vector.x * B.vector.x +
    A.vector.y * B.vector.y +
    A.vector.z * B.vector.z +
    A.scalar * B.scalar;
}
