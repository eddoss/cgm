#pragma once


#include <gtest/gtest.h>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/functions/vector.hpp>
#include <cgm/modules/core/functions/matrix.hpp>
#include <cgm/modules/cartesian/3d/functions/utils.hpp>
#include <cgm/modules/cartesian/3d/functions/orientation.hpp>
#include <cgm/modules/transformations/3d/types/enums.hpp>
#include <cgm/modules/transformations/3d/types/ray.hpp>
#include <cgm/modules/transformations/3d/types/pivot.hpp>
#include <cgm/modules/transformations/3d/types/transforms.hpp>
#include <cgm/modules/primitives/functions/angles.hpp>


using namespace std;

namespace cgm_xyz_xform_tests_data
{
    static CGM::Transforms<double>
    get(CGM::ETransformOrder order=CGM::ETransformOrder::SRT)
    {
        // Pivot rotated on {28, 16, 9} deg and translated in {0.4, -0.3, 0.2}.

        CGM::Transforms<double> values {};
        values.translation      = {+0.5, -1.4, +2.3};
        values.scale            = {+1.4, +2.1, +0.3};
        values.rotation         = {CGM::radians(22.0), CGM::radians(30.0), CGM::radians(-17.0)};
        values.uniformScale     = values.scale.x;
        values.transformOrder   = order;
        values.rotationOrder    = CGM::ERotationOrder::XYZ;
        values.pivot            = CGM::Pivot<double>
        (
            CGM::Vector<3,double>{+0.94943, +0.15037, -0.27564},
            CGM::Vector<3,double>{-0.01031, +0.89232, +0.45129},
            CGM::Vector<3,double>{+0.31382, -0.42562, +0.84874},
            CGM::Vector<3,double>{+0.40000, -0.30000, +0.20000}
        );

        return values;
    }

    const auto axis = CGM::Ray<double>
    (
        get().pivot.axes.x,
        get().pivot.position
    );

    // Rotated {12, 0, 28} deg
    // Position {0.25, 1.2, -1.3}
    const auto space = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+0.88295, +0.46947, +0.00000},
        CGM::Vector<3,double>{-0.45921, +0.86365, +0.20791},
        CGM::Vector<3,double>{+0.09761, -0.18358, +0.97815},
        CGM::Vector<3,double>{+0.25000, +1.20000, -1.30000}
    );

    const auto orientation = CGM::orientationMatrix(space);
    const auto vector = CGM::Vector<3,double>{+0.25000, +1.20000, -1.30000};
    const auto normal = CGM::Vector<3,double> {+0.453188, +0.200645, +0.868540};
    const auto origin = CGM::Vector<3,double> {+0.400000, -0.300000, +0.200000};
    const auto ior = 0.25;
    const auto mat3 = CGM::orientationMatrix
    (
        CGM::Vector<3,double>{+0.48990, +0.33640, +1.47840},
        CGM::Vector<3,double>{+0.28284, +0.88704, -1.14645},
        CGM::Vector<3,double>{-0.56569, +0.73485, +0.70711}
    );
    const auto mat4 = CGM::spaceMatrix
    (
        CGM::Vector<3,double>{+0.48990, +0.33640, +1.47840},
        CGM::Vector<3,double>{+0.28284, +0.88704, -1.14645},
        CGM::Vector<3,double>{-0.56569, +0.73485, +0.70711},
        CGM::Vector<3,double>{+0.30000, -1.20000, +1.00000}
    );
}