#pragma once

#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>
#include <CGM/Modules/Transformations/3D/Types/Axis.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>

using namespace std;
using namespace CGM;

#define CGM_PRINT(what) std::cout << "\n\n" << what << std::endl;

namespace cgm_xyz_xform_tests_data::rotate
{
    const auto angle = 0.383972; // 22 deg
    const auto angles = Vector<3,double> {+0.383972, +0.523599, -0.296706}; // 22, 30, -17 deg
    const auto axis = CGM_XFORM3D::Axis<double>
    (
        Vector<3,double>{+1.119520, -0.163025, -0.759512},
        Vector<3,double>{0.339356, 0.888266, 0.309551}
    );

    const auto pivot = CGM_XFORM3D::Pivot<double>   // R: {28, 16, 9} in deg
    (
        Vector<3,double>{+0.94943, +0.15037, -0.27564},
        Vector<3,double>{-0.01031, +0.89232, +0.45129},
        Vector<3,double>{+0.31382, -0.42562, +0.84874},
        Vector<3,double>{+0.40000, -0.30000, +0.20000}
    );

    const auto orient = CGM_XYZ::orientationMatrix  // R: {12, 0, 28} in deg
    (
        Vector<3,double>{+0.88295, -0.45921, +0.09761},
        Vector<3,double>{+0.46947, +0.86365, -0.18358},
        Vector<3,double>{+0.00000, +0.20791, +0.97815}
    );

    const auto space = CGM_XYZ::spaceMatrix
    (
        orient,
        Vector<3,double>{+0.25000, +1.20000, -1.30000}
    );

    const auto vec = Vector<3,double>{+0.25000, +1.20000, -1.30000};
}