

#include "Perspective.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
perspectiveViewport(T fov, T aspect, T offset)
{
    const T h = number<T>(2) * offset * std::tan(fov * number<T>(0.5));
    const T w = h * aspect;

    return {w,h};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE CGM::Ray<T>
perspectiveRay(const Vector<2,T>& point, T fov, T aspect, const Matrix<4,4,T>& projectorSpace)
{
    const T h = std::tan(fov * number<T>(0.5));
    const T w = h * aspect;

    const auto r_offset = CGM::right(projectorSpace) * fit11(point.x, -w, w);
    const auto u_offset = CGM::up(projectorSpace) * fit11(point.y, -h, h);

    auto ray = CGM::Ray<T>{};
    ray.position = CGM::position(projectorSpace);

    if constexpr (CGM_CONFIG.handedness == EHandedness::Right)
    {
        ray.direction = normalized(CGM::forward(projectorSpace) + u_offset - r_offset);
    }
    else
    {
        ray.direction = normalized(CGM::forward(projectorSpace) + u_offset + r_offset);
    }

    return ray;
}

/* --------------------------------------------------------------------------------------- */

template<EGraphicsApi API, typename T>
constexpr Matrix<4,4,T>
perspective(T fov, T aspect, T near, T far)
{
    auto viewport = perspectiveViewport(fov, aspect, near);
    auto ndcBound = Vector<4,T> {number<T>(2), number<T>(2), number<T>(-1), number<T>(1)};

    if constexpr (API == EGraphicsApi::DirectX)
    {
        ndcBound.z = number<T>(0);
    }

    return perspective<CGM::E3D::X, CGM::E3D::Y, CGM::E3D::Z, CGM::EHandedness::Left>
    (
        viewport.x, viewport.y, near, far, ndcBound.x, ndcBound.y, ndcBound.z, ndcBound.w
    );
}

/* --------------------------------------------------------------------------------------- */

template<CGM::E3D Right, CGM::E3D Up, CGM::E3D Forward, EHandedness Handedness, typename T>
constexpr Matrix<4,4,T>
perspective(T w, T h, T n, T f, T cw, T ch, T cmn, T cmx)
{
    auto mat = Matrix<4,4,T>(zero<T>);

    {
        const auto l = f - n;
        const auto R = CGM_COORD::cartesian(zero<T>, cw * n / w, zero<T>);
        const auto U = CGM_COORD::cartesian(ch * n / h, zero<T>, zero<T>);
        const auto F = CGM_COORD::cartesian(zero<T>, zero<T>, (f * cmx - n * cmn) / l);
        const auto P = CGM_COORD::cartesian(zero<T>, zero<T>, n * f * (cmn - cmx) / l);
        const auto H = CGM_COORD::cartesian(zero<T>, zero<T>, number<T>(1));

        CGM::setUp(mat, U);
        CGM::setForward(mat, F);
        CGM::setPosition(mat, P);
        CGM::setHomogeneous(mat, H);

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
        Vector<4,T> R(zero<T>);
        Vector<4,T> U(zero<T>);
        Vector<4,T> F(zero<T>);

        U.template get<CGM_CONFIG.up>() = number<T>(1);
        R.template get<CGM_CONFIG.right>() = number<T>(1);
        F.template get<CGM_CONFIG.forward>() = number<T>(1);

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