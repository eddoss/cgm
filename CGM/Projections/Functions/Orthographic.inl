

#include "Orthographic.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr Vector<2,T>
orthographicViewport(T aspect, T scale)
{
    const auto h = number<T>(2) * scale;
    const auto w = h * aspect;

    return {w,h};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_XYZ::Ray<T>
orthographicRay(const Vector<2,T>& point, T aspect, T scale, const Matrix<4,4,T>& projectorSpace)
{
    const auto r_offset = CGM_XYZ::right(projectorSpace) * fit11(point.x, -aspect * scale, aspect * scale);
    const auto u_offset = CGM_XYZ::up(projectorSpace) * fit11(point.y, -scale, scale);

    auto ray = CGM_XYZ::Ray<T>{};
    ray.direction = CGM_XYZ::forward(projectorSpace);

    if constexpr (CGM_CONFIG.handedness == EHandedness::Right)
    {
        ray.position = CGM_XYZ::position(projectorSpace) - r_offset + u_offset;
    }
    else
    {
        ray.position = CGM_XYZ::position(projectorSpace) + r_offset + u_offset;
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
            viewport.x, viewport.y, near, far, number<T>(2), number<T>(2), number<T>(0), number<T>(1)
        );
    }
    else
    {
        return orthographic<CGM::E3D::X, CGM::E3D::Y, CGM::E3D::Z, CGM::EHandedness::Left>
        (
            viewport.x, viewport.y, near, far, number<T>(2), number<T>(2), number<T>(-1), number<T>(1)
        );
    }
}

/* --------------------------------------------------------------------------------------- */

template<CGM::E3D Right, CGM::E3D Up, CGM::E3D Forward, EHandedness Handedness, typename T>
constexpr Matrix<4,4,T>
orthographic(T w, T h, T n, T f, T cw, T ch, T cmn, T cmx)
{
    auto mat = Matrix<4,4,T>(zero<T>);

    {
        const auto l = f - n;

        const auto R = CGM_COORD::cartesian(zero<T>, cw / w, zero<T>);
        const auto U = CGM_COORD::cartesian(ch / h, zero<T>, zero<T>);
        const auto F = CGM_COORD::cartesian(zero<T>, zero<T>, (cmx - cmn) / l);
        const auto P = CGM_COORD::cartesian(zero<T>, zero<T>, (f * cmn - n * cmx) / l);

        CGM_XYZ::setUp(mat, U);
        CGM_XYZ::setForward(mat, F);
        CGM_XYZ::setPosition(mat, P);
        mat(3,3) = number<T>(1);

        if constexpr (Handedness == CGM_CONFIG.handedness)
        {
            CGM_XYZ::setRight(mat, R);
        }
        else
        {
            CGM_XYZ::setRight(mat, -R);
        }
    }

    if constexpr (CGM_CONFIG.right != Right || CGM_CONFIG.up != Up || CGM_CONFIG.forward != Forward)
    {
        Vector<4,T> R(zero<T>);
        Vector<4,T> U(zero<T>);
        Vector<4,T> F(zero<T>);

        U.get<CGM_CONFIG.up>() = number<T>(1);
        R.get<CGM_CONFIG.right>() = number<T>(1);
        F.get<CGM_CONFIG.forward>() = number<T>(1);

        Matrix<4,4,T> remapper(zero<T>);

    #ifdef CGM_CFG_MATRIX_POSTMULT
        remapper.setRow(static_cast<size_t>(Up), U);
        remapper.setRow(static_cast<size_t>(Right), R);
        remapper.setRow(static_cast<size_t>(Forward), F);
    #else
        remapper.setColumn(static_cast<size_t>(Up), U);
        remapper.setColumn(static_cast<size_t>(Right), R);
        remapper.setColumn(static_cast<size_t>(Forward), F);
    #endif

        remapper(3,3) = number<T>(1);

    #ifdef CGM_CFG_MATRIX_POSTMULT
        mat = remapper * mat;
    #else
        mat = mat * remapper;
    #endif
    }

    return mat;
}

CGM_NAMESPACE_END