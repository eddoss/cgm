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
#include <CGM/Modules/Core/Functions/IO.hpp>


using namespace std;
using namespace CGM;
#define CGM_PRINT(what) std::cout << "\n\n" << what << std::endl;
#define CGM_PRINT_BASIS(b) \
    std::cout << "\n\n" << CGM_XYZ::x(b) << std::endl; \
    std::cout << CGM_XYZ::y(b) << std::endl; \
    std::cout << CGM_XYZ::z(b) << std::endl; \
    std::cout << CGM_XYZ::position(b) << std::endl;
namespace cgm_xyz_xform_tests_data
{
    // Direction - X axes from 'pivot'
    // Position - from 'pivot' position
    const auto axis = CGM_XFORM3D::Axis<double>
    (
        Vector<3,double>{+0.40000, -0.30000, +0.20000},
        Vector<3,double>{+0.94943, +0.15037, -0.27564}
    );

    // Rotated on {28, 16, 9} deg
    // Translated in {0.4, -0.3, 0.2}
    const auto pivot = CGM_XFORM3D::Pivot<double>
    (
        Vector<3,double>{+0.94943, +0.15037, -0.27564},
        Vector<3,double>{-0.01031, +0.89232, +0.45129},
        Vector<3,double>{+0.31382, -0.42562, +0.84874},
        Vector<3,double>{+0.40000, -0.30000, +0.20000}
    );

    // Rotated {12, 0, 28} deg
    const auto orientation = CGM_XYZ::orientationMatrix
    (
        Vector<3,double>{+0.88295, +0.46947, +0.00000},
        Vector<3,double>{-0.45921, +0.86365, +0.20791},
        Vector<3,double>{+0.09761, -0.18358, +0.97815}
    );

    // Orientation from 'orientation'
    // Position {0.25, 1.2, -1.3}
    const auto space = CGM_XYZ::spaceMatrix
    (
        orientation,
        Vector<3,double>{+0.25000, +1.20000, -1.30000}
    );

    const auto vector = Vector<3,double>{+0.25000, +1.20000, -1.30000};

    namespace rotate
    {
        const auto value = 0.383972; // 22 deg
        const auto values = Vector<3,double> {+0.383972, +0.523599, -0.296706}; // 22, 30, -17 deg
    }

    namespace scale
    {
        const auto value = -0.7;
        const auto values = Vector<3,double> {-0.7, 2.1, 0.3};
    }

    namespace reflect
    {
        const auto normal = Vector<3,double> {+0.453188, +0.200645, +0.868540};
        const auto origin = Vector<3,double> {+0.400000, -0.300000, +0.200000};
    }
}