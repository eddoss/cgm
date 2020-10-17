

#include "Functions.hpp"


CGM_NAMESPACE_BEGIN

template<CGM_XYZ::EAxes Right, CGM_XYZ::EAxes Up, CGM_XYZ::EAxes Forward, CGM::EHandedness Handedness, typename T>
constexpr Matrix<4,4,T>
ndc(T nearPlaneWidth, T nearPlaneHeight, T nearPlaneDist, T farPlaneDist, T cubeWidth, T cubeHeight, T cubeDepthMin, T cubeDepthMax)
{
    auto mat = Matrix<4,4,T>(zero<T>);
    constexpr CGM_XYZ::Config cfg {};

    {
        auto depthNegation = number<T>(1);

        if constexpr (Handedness == EHandedness::Left)
        {
        #ifdef CGM_CFG_LHS
            depthNegation = number<T>(1);
        #endif
        }
        else
        {
        #ifdef CGM_CFG_RHS
            depthNegation = number<T>(1);
        #endif
        }

        const auto frustumDepth = nearPlaneDist - farPlaneDist;
        const auto r = CGM_COORD::cartesian(zero<T>, cubeWidth * nearPlaneDist / nearPlaneWidth, zero<T>);
        const auto u = CGM_COORD::cartesian(cubeHeight * nearPlaneDist / nearPlaneHeight, zero<T>, zero<T>);
        const auto f = CGM_COORD::cartesian(zero<T>, zero<T>, nearPlaneDist * farPlaneDist * (cubeDepthMin + cubeDepthMax) / frustumDepth);
        const auto h = CGM_COORD::cartesian(zero<T>, zero<T>, depthNegation);

        CGM_XYZ::setRight(mat, r);
        CGM_XYZ::setUp(mat, u);
        CGM_XYZ::setForward(mat, f);
        CGM_XYZ::setHomogeneous(mat, h);
    }

    if constexpr (cfg.right != Right || cfg.up != Up || cfg.forward != Forward)
    {
        Vector<4,T> r (zero<T>);
        Vector<4,T> u (zero<T>);
        Vector<4,T> f (zero<T>);

        if constexpr (cfg.right == CGM_XYZ::EAxes::X) r.x = number<T>(1);
        if constexpr (cfg.right == CGM_XYZ::EAxes::Y) r.y = number<T>(1);
        if constexpr (cfg.right == CGM_XYZ::EAxes::Z) r.z = number<T>(1);

        if constexpr (cfg.up == CGM_XYZ::EAxes::X) u.x = number<T>(1);
        if constexpr (cfg.up == CGM_XYZ::EAxes::Y) u.y = number<T>(1);
        if constexpr (cfg.up == CGM_XYZ::EAxes::Z) u.z = number<T>(1);

        if constexpr (cfg.forward == CGM_XYZ::EAxes::X) f.x = number<T>(1);
        if constexpr (cfg.forward == CGM_XYZ::EAxes::Y) f.y = number<T>(1);
        if constexpr (cfg.forward == CGM_XYZ::EAxes::Z) f.z = number<T>(1);

        Matrix<4,4,T> remapper(zero<T>);

    #ifdef CGM_CFG_MATRIX_POSTMULT
        if constexpr (Right == CGM_XYZ::EAxes::X) remapper.setRow(0, r);
        if constexpr (Right == CGM_XYZ::EAxes::Y) remapper.setRow(1, r);
        if constexpr (Right == CGM_XYZ::EAxes::Z) remapper.setRow(2, r);

        if constexpr (Up == CGM_XYZ::EAxes::X) remapper.setRow(0, u);
        if constexpr (Up == CGM_XYZ::EAxes::Y) remapper.setRow(1, u);
        if constexpr (Up == CGM_XYZ::EAxes::Z) remapper.setRow(2, u);

        if constexpr (Forward == CGM_XYZ::EAxes::X) remapper.setRow(0, f);
        if constexpr (Forward == CGM_XYZ::EAxes::Y) remapper.setRow(1, f);
        if constexpr (Forward == CGM_XYZ::EAxes::Z) remapper.setRow(2, f);
    #else
        if constexpr (Right == CGM_XYZ::EAxes::X) remapper.setColumn(0, r);
        if constexpr (Right == CGM_XYZ::EAxes::Y) remapper.setColumn(1, r);
        if constexpr (Right == CGM_XYZ::EAxes::Z) remapper.setColumn(2, r);

        if constexpr (Up == CGM_XYZ::EAxes::X) remapper.setColumn(0, u);
        if constexpr (Up == CGM_XYZ::EAxes::Y) remapper.setColumn(1, u);
        if constexpr (Up == CGM_XYZ::EAxes::Z) remapper.setColumn(2, u);

        if constexpr (Forward == CGM_XYZ::EAxes::X) remapper.setColumn(0, f);
        if constexpr (Forward == CGM_XYZ::EAxes::Y) remapper.setColumn(1, f);
        if constexpr (Forward == CGM_XYZ::EAxes::Z) remapper.setColumn(2, f);
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
ndc(T fov, T aspect, T near, T far, EGraphicsApi api)
{
    const T nearPlaneHeight = number<T>(2) * near * std::tan(fov * 0.5f);
    const T nearPlaneWidth = nearPlaneHeight * aspect;
    const T cubeWidth = number<T>(2);
    const T cubeHeight = number<T>(2);
    const T cubeDepthMax = number<T>(1);

    T cubeDepthMin = number<T>(-1);

    if (api == EGraphicsApi::DirectX)
    {
        cubeDepthMin = number<T>(0);
    }

    return ndc
    <
        CGM_XYZ::EAxes::X,
        CGM_XYZ::EAxes::Y,
        CGM_XYZ::EAxes::Z,
        CGM::EHandedness::Left
    >
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

CGM_NAMESPACE_END