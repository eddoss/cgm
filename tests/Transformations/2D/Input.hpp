#pragma once


#include <gtest/gtest.h>
#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Core/Functions/Matrix.hpp>
#include <CGM/Cartesian/2D/Functions/Utils.hpp>
#include <CGM/Cartesian/2D/Functions/Orientation.hpp>
#include <CGM/Transformations/2D/Types/ArbitraryAxis.hpp>
#include <CGM/Transformations/2D/Types/Pivot.hpp>
#include <CGM/Transformations/2D/Types/Transforms.hpp>
#include <CGM/Core/Functions/IO.hpp>

using namespace std;

#define CGM_PRINT(what) std::cout << "\n\n" << what << std::endl;
#define CGM_PRINT_BASIS(b) \
    std::cout << "\n\n" << CGM_XY::x(b) << ","  << std::endl; \
    std::cout << CGM_XY::y(b) << "," << std::endl; \
    std::cout << CGM_XY::position(b) << std::endl;
namespace cgm_xy_xform_tests_data
{
    static CGM_XFORM2D::Transforms<double>
    get(CGM::ETransformOrder order=CGM::ETransformOrder::SRT)
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
            CGM::Vector<2,double>{+0.88295, +0.46947},
            CGM::Vector<2,double>{-0.46947, +0.88295},
            CGM::Vector<2,double>{+0.40000, -0.30000}
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
        CGM::Vector<2,double>{+0.88295, +0.46947},
        CGM::Vector<2,double>{-0.46947, +0.88295},
        CGM::Vector<2,double>{+0.25000, +1.20000}
    );
    const auto orientation = CGM_XY::orientationMatrix(space);
    const auto vector = CGM::Vector<2,double> {+0.250000, +1.200000};
    const auto normal = CGM::Vector<2,double> {+0.450318, +0.892868};
    const auto origin = CGM::Vector<2,double> {+0.300000, -0.130000};
    const auto ior = 0.25;

    const auto mat2 = CGM_XY::orientationMatrix
    (
        CGM::Vector<2,double>{+0.88295, +0.46947},
        CGM::Vector<2,double>{-0.46947, +0.88295}
    );

    const auto mat3 = CGM_XY::spaceMatrix
    (
        CGM::Vector<2,double>{+0.88295, +0.46947},
        CGM::Vector<2,double>{-0.46947, +0.88295},
        CGM::Vector<2,double>{+0.40000, -0.30000}
    );
}