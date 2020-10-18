

#include "Functions.hpp"


CGM_NAMESPACE_BEGIN

template<EGraphicsApi API, typename T>
constexpr Matrix<4,4,T>
ndc(T fov, T aspect, T near, T far)
{
    const T nearPlaneHeight = number<T>(2) * near * std::tan(fov * 0.5f);
    const T nearPlaneWidth = nearPlaneHeight * aspect;
    const T cubeWidth = number<T>(2);
    const T cubeHeight = number<T>(2);
    const T cubeDepthMax = number<T>(1);

    T cubeDepthMin = number<T>(-1);

    if constexpr (API == EGraphicsApi::DirectX)
    {
        cubeDepthMin = number<T>(0);
    }

    return ndc<CGM::E3D::X, CGM::E3D::Y, CGM::E3D::Z, CGM::EHandedness::Left>
    (
        nearPlaneWidth,
        nearPlaneHeight,
        near,
        far,
        cubeWidth,
        cubeHeight,
        cubeDepthMin,
        cubeDepthMax
    );
}

/* --------------------------------------------------------------------------------------- */

template<CGM::E3D Right, CGM::E3D Up, CGM::E3D Forward, EHandedness Handedness, typename T>
constexpr Matrix<4,4,T>
ndc(T nearPlaneWidth, T nearPlaneHeight, T nearPlaneDist, T farPlaneDist, T cubeWidth, T cubeHeight, T cubeDepthMin, T cubeDepthMax)
{
    constexpr CGM_XYZ::Config cfg {};

    auto mat = Matrix<4,4,T>(zero<T>);

    {
        const auto frustumLen = farPlaneDist - nearPlaneDist;
        const auto right = CGM_COORD::cartesian(zero<T>, cubeWidth * nearPlaneDist / nearPlaneWidth, zero<T>);
        const auto up = CGM_COORD::cartesian(cubeHeight * nearPlaneDist / nearPlaneHeight, zero<T>, zero<T>);
        const auto forward = CGM_COORD::cartesian(zero<T>, zero<T>, (farPlaneDist * cubeDepthMax - nearPlaneDist * cubeDepthMin) / frustumLen);

        CGM_XYZ::setRight(mat, right);
        CGM_XYZ::setUp(mat, up);
        CGM_XYZ::setForward(mat, forward);

    #ifdef CGM_CFG_MATRIX_POSTMULT
        mat(3, static_cast<size_t>(cfg.forward)) = number<T>(1);
        mat(static_cast<size_t>(cfg.forward), 3) = nearPlaneDist * farPlaneDist * (cubeDepthMin - cubeDepthMax) / frustumLen;
    #else
        mat(static_cast<size_t>(cfg.forward), 3) = number<T>(1);
        mat(3, static_cast<size_t>(cfg.forward)) = nearPlaneDist * farPlaneDist * (cubeDepthMin - cubeDepthMax) / frustumLen;
    #endif
    }

    if constexpr (cfg.right != Right || cfg.up != Up || cfg.forward != Forward || cfg.handedness != Handedness)
    {
        Vector<4,T> r(zero<T>);
        Vector<4,T> u(zero<T>);
        Vector<4,T> f(zero<T>);

        u.get< static_cast<E4D>(cfg.up)>() = number<T>(1);

        if constexpr (cfg.handedness != Handedness)
        {
            r.get<static_cast<E4D>(cfg.right)>() = number<T>(-1);
            f.get<static_cast<E4D>(cfg.forward)>() = number<T>(-1);
        }
        else
        {
            r.get<static_cast<E4D>(cfg.right)>() = number<T>(1);
            f.get<static_cast<E4D>(cfg.forward)>() = number<T>(1);
        }

        Matrix<4,4,T> remapper(zero<T>);

    #ifdef CGM_CFG_MATRIX_POSTMULT
        remapper.setRow(static_cast<size_t>(Right), r);
        remapper.setRow(static_cast<size_t>(Up), u);
        remapper.setRow(static_cast<size_t>(Forward), f);
    #else
        remapper.setColumn(static_cast<size_t>(Right), r);
        remapper.setColumn(static_cast<size_t>(Up), u);
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