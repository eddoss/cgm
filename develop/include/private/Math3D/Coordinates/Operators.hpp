

#include <Math3D/Coordinates/Operators.hpp>


/* ####################################################################################### */
/* Polar */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Polar<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Polar<T>& B)
{
    return  MATH3D_NAMESPACE::equal(A.angle(), B.angle()) &&
            MATH3D_NAMESPACE::equal(A.radius(), B.radius());
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Polar<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Polar<T>& B)
{
    return  MATH3D_NAMESPACE::notEqual(A.angle(), B.angle()) ||
            MATH3D_NAMESPACE::notEqual(A.radius(), B.radius());
}

/* ####################################################################################### */
/* Spherical */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Spherical<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Spherical<T>& B)
{
    return  MATH3D_NAMESPACE::equal(A.radius(), B.radius())       &&
            MATH3D_NAMESPACE::equal(A.latitude(), B.latitude())   &&
            MATH3D_NAMESPACE::equal(A.longitude(), B.longitude());
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Spherical<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Spherical<T>& B)
{
    return  MATH3D_NAMESPACE::notEqual(A.radius(), B.radius())       ||
            MATH3D_NAMESPACE::notEqual(A.latitude(), B.latitude())   ||
            MATH3D_NAMESPACE::notEqual(A.longitude(), B.longitude());
}

/* ####################################################################################### */
/* Cylindrical */
/* ####################################################################################### */

template<typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Cylindrical<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Cylindrical<T>& B)
{
    return  MATH3D_NAMESPACE::equal(A.angle(), B.angle())     &&
            MATH3D_NAMESPACE::equal(A.radius(), B.radius())   &&
            MATH3D_NAMESPACE::equal(A.height(), B.height());
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Cylindrical<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Cylindrical<T>& B)
{
    return  MATH3D_NAMESPACE::notEqual(A.angle(), B.angle())      ||
            MATH3D_NAMESPACE::notEqual(A.radius(), B.radius())    ||
            MATH3D_NAMESPACE::notEqual(A.height(), B.height());
}
