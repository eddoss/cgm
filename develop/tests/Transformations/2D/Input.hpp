#pragma once


#include <gtest/gtest.h>
#include <CGM/detail/Modules/Core/Types/Vector.hpp>
#include <CGM/detail/Modules/Core/Types/Matrix.hpp>
#include <CGM/detail/Modules/Core/Functions/Vector.hpp>
#include <CGM/detail/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Orientation.hpp>
#include <CGM/Modules/Transformations/2D/Types/ArbitraryAxis.hpp>
#include <CGM/Modules/Transformations/2D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/2D/Types/Transforms.hpp>
#include <CGM/detail/Modules/Core/Functions/IO.hpp>

using namespace std;
using namespace CGM;

#define CGM_PRINT(what) std::cout << "\n\n" << what << std::endl;
#define CGM_PRINT_BASIS(b) \
    std::cout << "\n\n" << CGM_XY::x(b) << ","  << std::endl; \
    std::cout << CGM_XY::y(b) << "," << std::endl; \
    std::cout << CGM_XY::position(b) << std::endl;
namespace cgm_xy_xform_tests_data
{
    static CGM_XFORM2D::Transforms<double>
    get(ETransformOrder order=ETransformOrder::SRT)
    {
        // Pivot rotated on {28, 16, 9} deg and translated in {0.4, -0.3, 0.2}.

        CGM_XFORM2D::Transforms<double> values {};
        values.translation      = {+0.5, -1.4};
        values.scale            = {+1.4, +2.1};
        values.rotation         = CGM::radians(22.0);
        values.uniformScale     = values.scale.x;
        values.transformOrder   = order;
        values.pivot            = CGM_XFORM2D::Pivot<double>
        (
            Vector<2,double>{+0.88295, +0.46947},
            Vector<2,double>{-0.46947, +0.88295},
            Vector<2,double>{+0.40000, -0.30000}
        );

        return values;
    }

    const auto axis = CGM_XFORM2D::ArbitraryAxis<double>
    (
        get().pivot.axes.x,
        get().pivot.position
    );

    // Rotated 28 deg
    // Position {0.25, 1.2}
    const auto space = CGM_XY::spaceMatrix
    (
        Vector<2,double>{+0.88295, +0.46947},
        Vector<2,double>{-0.46947, +0.88295},
        Vector<2,double>{+0.25000, +1.20000}
    );
    const auto orientation = CGM_XY::orientationMatrix(space);
    const auto vector = Vector<2,double> {+0.250000, +1.200000};
    const auto normal = Vector<2,double> {+0.450318, +0.892868};
    const auto origin = Vector<2,double> {+0.300000, -0.130000};
    const auto ior = 0.25;

    const auto mat2 = CGM_XY::orientationMatrix
    (
        Vector<2,double>{+0.88295, +0.46947},
        Vector<2,double>{-0.46947, +0.88295}
    );

    const auto mat3 = CGM_XY::spaceMatrix
    (
        Vector<2,double>{+0.88295, +0.46947},
        Vector<2,double>{-0.46947, +0.88295},
        Vector<2,double>{+0.40000, -0.30000}
    );
}