

#include <Math3D/XForm/Operators.hpp>


/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Pivot<D,T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Pivot<D,T>& B)
{
    if constexpr (D == 2)
    {
        return
        MATH3D_NAMESPACE::equal(A.x, B.x) &&
        MATH3D_NAMESPACE::equal(A.y, B.y) &&
        MATH3D_NAMESPACE::equal(A.position, B.position);
    }
    else if constexpr (D == 3)
    {
        return
        MATH3D_NAMESPACE::equal(A.x, B.x) &&
        MATH3D_NAMESPACE::equal(A.y, B.y) &&
        MATH3D_NAMESPACE::equal(A.z, B.z) &&
        MATH3D_NAMESPACE::equal(A.position, B.position);
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Pivot<D,T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Pivot<D,T>& B)
{
    if constexpr (D == 2)
    {
        return
        MATH3D_NAMESPACE::notEqual(A.x, B.x) ||
        MATH3D_NAMESPACE::notEqual(A.y, B.y) ||
        MATH3D_NAMESPACE::notEqual(A.position, B.position);
    }
    else if constexpr (D == 3)
    {
        return
        MATH3D_NAMESPACE::notEqual(A.x, B.x) ||
        MATH3D_NAMESPACE::notEqual(A.y, B.y) ||
        MATH3D_NAMESPACE::notEqual(A.z, B.z) ||
        MATH3D_NAMESPACE::notEqual(A.position, B.position);
    }
}

/* ####################################################################################### */
/* Transforms */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Transforms<D,T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Transforms<D,T>& B)
{
    return
    A.pivot == B.pivot                                          &&
    A.scales == B.scales                                        &&
    A.rotations == B.rotations                                  &&
    A.translations == B.translations                            &&
    A.rotationOrder == B.rotationOrder                          &&
    A.transformOrder == B.transformOrder                        &&
    MATH3D_NAMESPACE::equal(A.uniformScale, B.uniformScale);
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Transforms<D,T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Transforms<D,T>& B)
{
    return
    A.pivot != B.pivot                                          ||
    A.scales != B.scales                                        ||
    A.rotations != B.rotations                                  ||
    A.translations != B.translations                            ||
    A.rotationOrder != B.rotationOrder                          ||
    A.transformOrder != B.transformOrder                        ||
    MATH3D_NAMESPACE::notEqual(A.uniformScale, B.uniformScale);
}

/* ####################################################################################### */
/* Euler angles */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::EulerAngles<T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::EulerAngles<T>& B)
{
    return
    MATH3D_NAMESPACE::equal(A.roll, B.roll)      &&
    MATH3D_NAMESPACE::equal(A.pitch, B.pitch)    &&
    MATH3D_NAMESPACE::equal(A.yaw, B.yaw);
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::EulerAngles<T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::EulerAngles<T>& B)
{
    return
    MATH3D_NAMESPACE::notEqual(A.roll, B.roll)      ||
    MATH3D_NAMESPACE::notEqual(A.pitch, B.pitch)    ||
    MATH3D_NAMESPACE::notEqual(A.yaw, B.yaw);
}