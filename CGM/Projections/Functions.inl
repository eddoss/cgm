

#include "Functions.hpp"


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
constexpr CGM_FORCEINLINE Vector<3,T>
perspectiveRay(const Vector<2,T>& point, T fov, T aspect, const Matrix<4,4,T>& projectorSpace)
{
    const T h = std::tan(fov * number<T>(0.5));
    const T w = h * aspect;

    const auto r_offset = CGM_XYZ::right(projectorSpace) * fit11(point.x, -w, w);
    const auto u_offset = CGM_XYZ::up(projectorSpace) * fit11(point.y, -h, h);
    if constexpr (CGM_CONFIG.handedness == EHandedness::Right)
    {
        return normalized(CGM_XYZ::forward(projectorSpace) + u_offset - r_offset);
    }
    else
    {
        return normalized(CGM_XYZ::forward(projectorSpace) + u_offset + r_offset);
    }
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
perspective(T nearPlaneWidth, T nearPlaneHeight, T nearPlaneDist, T farPlaneDist, T cubeWidth, T cubeHeight, T cubeDepthMin, T cubeDepthMax)
{
    auto mat = Matrix<4,4,T>(zero<T>);

    {
        const auto frustumLen = farPlaneDist - nearPlaneDist;
        const auto right = CGM_COORD::cartesian(zero<T>, cubeWidth * nearPlaneDist / nearPlaneWidth, zero<T>);
        const auto up = CGM_COORD::cartesian(cubeHeight * nearPlaneDist / nearPlaneHeight, zero<T>, zero<T>);
        const auto forward = CGM_COORD::cartesian(zero<T>, zero<T>, (farPlaneDist * cubeDepthMax - nearPlaneDist * cubeDepthMin) / frustumLen);

        if constexpr (Handedness == CGM_CONFIG.handedness)
        {
            CGM_XYZ::setRight(mat, right);
        }
        else
        {
            CGM_XYZ::setRight(mat, -right);
        }
        CGM_XYZ::setUp(mat, up);
        CGM_XYZ::setForward(mat, forward);

    #ifdef CGM_CFG_MATRIX_POSTMULT
        mat(3, static_cast<size_t>(CGM_CONFIG.forward)) = number<T>(1);
        mat(static_cast<size_t>(CGM_CONFIG.forward), 3) = nearPlaneDist * farPlaneDist * (cubeDepthMin - cubeDepthMax) / frustumLen;
    #else
        mat(static_cast<size_t>(CGM_CONFIG.forward), 3) = number<T>(1);
        mat(3, static_cast<size_t>(CGM_CONFIG.forward)) = nearPlaneDist * farPlaneDist * (cubeDepthMin - cubeDepthMax) / frustumLen;
    #endif
    }

    if constexpr (CGM_CONFIG.right != Right || CGM_CONFIG.up != Up || CGM_CONFIG.forward != Forward)
    {
        Vector<4,T> r(zero<T>);
        Vector<4,T> u(zero<T>);
        Vector<4,T> f(zero<T>);

        u.get<static_cast<E4D>(CGM_CONFIG.up)>() = number<T>(1);
        r.get<static_cast<E4D>(CGM_CONFIG.right)>() = number<T>(1);
        f.get<static_cast<E4D>(CGM_CONFIG.forward)>() = number<T>(1);

        Matrix<4,4,T> remapper(zero<T>);

    #ifdef CGM_CFG_MATRIX_POSTMULT
        remapper.setRow(static_cast<size_t>(Up), u);
        remapper.setRow(static_cast<size_t>(Right), r);
        remapper.setRow(static_cast<size_t>(Forward), f);
    #else
        remapper.setColumn(static_cast<size_t>(Up), u);
        remapper.setColumn(static_cast<size_t>(Right), r);
        remapper.setColumn(static_cast<size_t>(Forward), f);
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