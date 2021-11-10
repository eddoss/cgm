

#include "Orthographic.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr enable_if_floating<T, Vector<2,T>>
orthographicViewport(T aspect, T scale)
{
    const auto h = val<T>(2) * scale;
    const auto w = h * aspect;

    return {w,h};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr enable_if_floating<T, Ray<T>>
orthographicRay(const Vector<2,T>& point, T aspect, T scale, const Matrix<4,4,T>& projectorSpace)
{
    const auto offsetR = CGM::right(projectorSpace) * fit11(point.x, -aspect * scale, aspect * scale);
    const auto offsetU = CGM::up(projectorSpace) * fit11(point.y, -scale, scale);

    auto ray = CGM::Ray<T>{};
    ray.direction = CGM::forward(projectorSpace);

    if constexpr (CGM_CONFIG.handedness == EHandedness::Right)
    {
        ray.position = offsetR + offsetU - CGM::position(projectorSpace);
    }
    else
    {
        ray.position = offsetR + offsetU + CGM::forward(projectorSpace);
    }

    return ray;
}

/* --------------------------------------------------------------------------------------- */

template<EGraphicsApi API, typename T>
constexpr enable_if_floating<T, Matrix<4,4,T>>
orthographic(T aspect, T scale, T near, T far)
{
    const auto viewport = orthographicViewport(aspect, scale);

    if constexpr (API == EGraphicsApi::DirectX)
    {
        return orthographic<CGM::E3D::X, CGM::E3D::Y, CGM::E3D::Z, CGM::EHandedness::Left>
        (
            viewport.x, viewport.y, near, far, val<T>(2), val<T>(2), val<T>(0), val<T>(1)
        );
    }
    else
    {
        return orthographic<CGM::E3D::X, CGM::E3D::Y, CGM::E3D::Z, CGM::EHandedness::Left>
        (
            viewport.x, viewport.y, near, far, val<T>(2), val<T>(2), val<T>(-1), val<T>(1)
        );
    }
}

/* --------------------------------------------------------------------------------------- */

template<CGM::E3D Right, CGM::E3D Up, CGM::E3D Forward, EHandedness Handedness, typename T>
constexpr enable_if_floating<T, Matrix<4,4,T>>
orthographic(T w, T h, T n, T f, T cw, T ch, T cmn, T cmx)
{
    auto mat = Matrix<4,4,T>(val<T>(0));

    {
        const auto R = CGM_COORD::cartesian(val<T>(0), cw / w, val<T>(0));
        const auto U = CGM_COORD::cartesian(ch / h, val<T>(0), val<T>(0));

        CGM::setUp(mat, U);
        CGM::setRight(mat, R);

        if constexpr (Handedness == CGM_CONFIG.handedness)
        {
            const auto F = CGM_COORD::cartesian(val<T>(0), val<T>(0), (cmx - cmn) / (f - n));
            const auto P = CGM_COORD::cartesian(val<T>(0), val<T>(0), (f * cmx - n * cmn) / (f - n));

            CGM::setForward(mat, F);
            CGM::setPosition(mat, P);
        }
        else
        {
            const auto F = CGM_COORD::cartesian(val<T>(0), val<T>(0), (cmx - cmn) / (n - f));
            const auto P = CGM_COORD::cartesian(val<T>(0), val<T>(0), (f * cmx - n * cmn) / (n - f));

            CGM::setForward(mat, F);
            CGM::setPosition(mat, P);
        }

        mat(3,3) = val<T>(1);
    }

    if constexpr (CGM_CONFIG.right != Right || CGM_CONFIG.up != Up || CGM_CONFIG.forward != Forward)
    {
        const auto R = CGM_COORD::cartesian(T(0), T(1), T(0), T(0));
        const auto U = CGM_COORD::cartesian(T(1), T(0), T(0), T(0));
        const auto F = CGM_COORD::cartesian(T(0), T(0), T(1), T(0));

        auto remapper = Matrix<4,4,T>(val<T>(0));

    #ifdef CGM_CFG_MATRIX_POSTMULT
        remapper.setRow(static_cast<size_t>(Up), U);
        remapper.setRow(static_cast<size_t>(Right), R);
        remapper.setRow(static_cast<size_t>(Forward), F);
    #else
        remapper.setColumn(static_cast<size_t>(Up), U);
        remapper.setColumn(static_cast<size_t>(Right), R);
        remapper.setColumn(static_cast<size_t>(Forward), F);
    #endif

        remapper(3,3) = val<T>(1);

    #ifdef CGM_CFG_MATRIX_POSTMULT
        mat = remapper * mat;
    #else
        mat = mat * remapper;
    #endif
    }

    return mat;
}

CGM_NAMESPACE_END