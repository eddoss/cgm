#pragma once


#include <gtest/gtest.h>
#include <CGM/detail/Modules/Core/Types/Vector.hpp>
#include <CGM/detail/Modules/Core/Types/Matrix.hpp>
#include <CGM/detail/Modules/Core/Functions/Vector.hpp>
#include <CGM/detail/Modules/Core/Functions/Matrix.hpp>
#include <CGM/detail/Modules/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/detail/Modules/Cartesian/3D/Functions/Orientation.hpp>
#include <CGM/detail/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/detail/Modules/Transformations/3D/Types/ArbitraryAxis.hpp>
#include <CGM/detail/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/detail/Modules/Transformations/3D/Types/Transforms.hpp>


using namespace std;
using namespace CGM;

namespace cgm_xyz_xform_tests_data
{
    static CGM_XFORM3D::Transforms<double>
    get(ETransformOrder order=ETransformOrder::SRT)
    {
        // Pivot rotated on {28, 16, 9} deg and translated in {0.4, -0.3, 0.2}.

        CGM_XFORM3D::Transforms<double> values {};
        values.translation      = {+0.5, -1.4, +2.3};
        values.scale            = {+1.4, +2.1, +0.3};
        values.rotation         = CGM::radians(Vector<3,double>{22.0, 30.0, -17.0});
        values.uniformScale     = values.scale.x;
        values.transformOrder   = order;
        values.rotationOrder    = CGM_XFORM3D::ERotationOrder::XYZ;
        values.pivot            = CGM_XFORM3D::Pivot<double>
        (
            Vector<3,double>{+0.94943, +0.15037, -0.27564},
            Vector<3,double>{-0.01031, +0.89232, +0.45129},
            Vector<3,double>{+0.31382, -0.42562, +0.84874},
            Vector<3,double>{+0.40000, -0.30000, +0.20000}
        );

        return values;
    }

    const auto axis = CGM_XFORM3D::ArbitraryAxis<double>
    (
        get().pivot.axes.x,
        get().pivot.position
    );

    // Rotated {12, 0, 28} deg
    // Position {0.25, 1.2, -1.3}
    const auto space = CGM_XYZ::spaceMatrix
    (
        Vector<3,double>{+0.88295, +0.46947, +0.00000},
        Vector<3,double>{-0.45921, +0.86365, +0.20791},
        Vector<3,double>{+0.09761, -0.18358, +0.97815},
        Vector<3,double>{+0.25000, +1.20000, -1.30000}
    );

    const auto orientation = CGM_XYZ::orientationMatrix(space);
    const auto vector = Vector<3,double>{+0.25000, +1.20000, -1.30000};
    const auto normal = Vector<3,double> {+0.453188, +0.200645, +0.868540};
    const auto origin = Vector<3,double> {+0.400000, -0.300000, +0.200000};
    const auto ior = 0.25;
    const auto mat3 = CGM_XYZ::orientationMatrix
    (
        Vector<3,double>{+0.48990, +0.33640, +1.47840},
        Vector<3,double>{+0.28284, +0.88704, -1.14645},
        Vector<3,double>{-0.56569, +0.73485, +0.70711}
    );
    const auto mat4 = CGM_XYZ::spaceMatrix
    (
        Vector<3,double>{+0.48990, +0.33640, +1.47840},
        Vector<3,double>{+0.28284, +0.88704, -1.14645},
        Vector<3,double>{-0.56569, +0.73485, +0.70711},
        Vector<3,double>{+0.30000, -1.20000, +1.00000}
    );
}