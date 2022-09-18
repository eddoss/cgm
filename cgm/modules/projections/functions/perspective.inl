

#include "perspective.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
perspectiveViewport(T fov, T aspect, T offset)
{
    const T h = T(2) * offset * std::tan(fov * T(0.5));
    const T w = h * aspect;

    return {w,h};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
perspectiveRay(const Vector<2,T>& point, T fov, T aspect, const Matrix<4,4,T>& projectorSpace)
{
    const T h = std::tan(fov * T(0.5));
    const T w = h * aspect;

    const auto offsetR = CGM::right(projectorSpace) * fit11(point.x, -w, w);
    const auto offsetU = CGM::up(projectorSpace) * fit11(point.y, -h, h);

    auto ray = CGM::Ray<T>{};
    ray.position = CGM::position(projectorSpace);

    if constexpr (CGM_CONFIG.handedness == EHandedness::Right)
    {
        ray.direction = CGM::normalized(offsetR + offsetU - CGM::forward(projectorSpace));
    }
    else
    {
        ray.direction = CGM::normalized(offsetR + offsetU + CGM::forward(projectorSpace));
    }

    return ray;
}

/* --------------------------------------------------------------------------------------- */

template<EGraphicsApi API, typename T>
constexpr enable_if_floating<T, Matrix<4,4,T>>
perspective(T fov, T aspect, T near, T far)
{
    auto viewport = perspectiveViewport(fov, aspect, near);
    auto ndcBound = Vector<4,T> {T(2), T(2), T(-1), T(1)};

    if constexpr (API == EGraphicsApi::DirectX)
    {
        ndcBound.z = T(0);
    }

    return perspective<CGM::E3D::X, CGM::E3D::Y, CGM::E3D::Z, CGM::EHandedness::Left>
    (
        viewport.x, viewport.y, near, far, ndcBound.x, ndcBound.y, ndcBound.z, ndcBound.w
    );
}

/* --------------------------------------------------------------------------------------- */

template<CGM::E3D Right, CGM::E3D Up, CGM::E3D Forward, EHandedness Handedness, typename T>
constexpr enable_if_floating<T, Matrix<4,4,T>>
perspective(T w, T h, T n, T f, T cw, T ch, T cmn, T cmx)
{
    auto mat = Matrix<4,4,T>(T(0));

    {
        const auto R = CGM_COORD::cartesian(T(0), cw * n / w, T(0));
        const auto U = CGM_COORD::cartesian(ch * n / h, T(0), T(0));

        CGM::setUp(mat, U);
        CGM::setRight(mat, R);

        if constexpr (Handedness == CGM_CONFIG.handedness)
        {
            const auto F = CGM_COORD::cartesian(T(0), T(0), (f * cmx - n * cmn) / (f - n));
            const auto P = CGM_COORD::cartesian(T(0), T(0), n * f * (cmn - cmx) / (f - n));
            const auto H = CGM_COORD::cartesian(T(0), T(0), T(1));

            CGM::setForward(mat, F);
            CGM::setPosition(mat, P);
            CGM::setHomogeneous(mat, H);
        }
        else
        {
            const auto F = CGM_COORD::cartesian(T(0), T(0), (f * cmx - n * cmn) / (n - f));
            const auto P = CGM_COORD::cartesian(T(0), T(0), n * f * (cmx - cmn) / (n - f));
            const auto H = CGM_COORD::cartesian(T(0), T(0), T(-1));

            CGM::setForward(mat, F);
            CGM::setPosition(mat, P);
            CGM::setHomogeneous(mat, H);
        }
    }

    if constexpr (CGM_CONFIG.right != Right || CGM_CONFIG.up != Up || CGM_CONFIG.forward != Forward)
    {
        const auto R = CGM_COORD::cartesian(T(0), T(1), T(0), T(0));
        const auto U = CGM_COORD::cartesian(T(1), T(0), T(0), T(0));
        const auto F = CGM_COORD::cartesian(T(0), T(0), T(1), T(0));

        auto remapper = Matrix<4,4,T>(T(0));

    #ifdef CGM_CFG_MATRIX_POSTMULT
        remapper.setRow(static_cast<size_t>(Up), U);
        remapper.setRow(static_cast<size_t>(Right), R);
        remapper.setRow(static_cast<size_t>(Forward), F);
    #else
        remapper.setColumn(static_cast<size_t>(Up), U);
        remapper.setColumn(static_cast<size_t>(Right), R);
        remapper.setColumn(static_cast<size_t>(Forward), F);
    #endif

        remapper(3,3) = T(1);

    #ifdef CGM_CFG_MATRIX_POSTMULT
        mat = remapper * mat;
    #else
        mat = mat * remapper;
    #endif
    }

    return mat;
}

CGM_NAMESPACE_END