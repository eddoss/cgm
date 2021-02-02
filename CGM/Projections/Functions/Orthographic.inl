

#include "Orthographic.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr Vector<2,T>
orthographicViewport(T aspect, T scale)
{
    const auto h = val<T>(2) * scale;
    const auto w = h * aspect;

    return {w,h};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM::Ray<T>
orthographicRay(const Vector<2,T>& point, T aspect, T scale, const Matrix<4,4,T>& projectorSpace)
{
    const auto r_offset = CGM::right(projectorSpace) * fit11(point.x, -aspect * scale, aspect * scale);
    const auto u_offset = CGM::up(projectorSpace) * fit11(point.y, -scale, scale);

    auto ray = CGM::Ray<T>{};
    ray.direction = CGM::forward(projectorSpace);

    if constexpr (CGM_CONFIG.handedness == EHandedness::Right)
    {
        ray.position = CGM::position(projectorSpace) - r_offset + u_offset;
    }
    else
    {
        ray.position = CGM::position(projectorSpace) + r_offset + u_offset;
    }

    return ray;
}

/* --------------------------------------------------------------------------------------- */

template<EGraphicsApi API, typename T>
constexpr Matrix<4,4,T>
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
constexpr Matrix<4,4,T>
orthographic(T w, T h, T n, T f, T cw, T ch, T cmn, T cmx)
{
    auto mat = Matrix<4,4,T>(val<T>(0));

    {
        const auto l = f - n;

        const auto R = CGM_COORD::cartesian(val<T>(0), cw / w, val<T>(0));
        const auto U = CGM_COORD::cartesian(ch / h, val<T>(0), val<T>(0));
        const auto F = CGM_COORD::cartesian(val<T>(0), val<T>(0), (cmx - cmn) / l);
        const auto P = CGM_COORD::cartesian(val<T>(0), val<T>(0), (f * cmn - n * cmx) / l);

        CGM::setUp(mat, U);
        CGM::setForward(mat, F);
        CGM::setPosition(mat, P);
        mat(3,3) = val<T>(1);

        if constexpr (Handedness == CGM_CONFIG.handedness)
        {
            CGM::setRight(mat, R);
        }
        else
        {
            CGM::setRight(mat, -R);
        }
    }

    if constexpr (CGM_CONFIG.right != Right || CGM_CONFIG.up != Up || CGM_CONFIG.forward != Forward)
    {
        Vector<4,T> R(val<T>(0));
        Vector<4,T> U(val<T>(0));
        Vector<4,T> F(val<T>(0));

        U.template get<CGM_CONFIG.up>() = val<T>(1);
        R.template get<CGM_CONFIG.right>() = val<T>(1);
        F.template get<CGM_CONFIG.forward>() = val<T>(1);

        Matrix<4,4,T> remapper(val<T>(0));

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