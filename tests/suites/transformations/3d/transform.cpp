

#include "input.hpp"
#include <cgm/modules/transformations/3d/functions/transform.hpp>


using namespace std;

TEST(Transformations3D_Transform, Vector)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM::transformed(cgm_test::vector, cgm_test::get(CGM::ETransformOrder::SRT));
        const auto expect = CGM::Vector<3,double>{+2.76894, -0.43228, +1.36117};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::vector, cgm_test::get(CGM::ETransformOrder::STR));
        const auto expect = CGM::Vector<3,double>{+2.46529, -0.84830, -0.09881};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::vector, cgm_test::get(CGM::ETransformOrder::RST));
        const auto expect = CGM::Vector<3,double>{+1.46125, +1.50507, +2.62802};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::vector, cgm_test::get(CGM::ETransformOrder::RTS));
        const auto expect = CGM::Vector<3,double>{+1.52635, -0.27851, +0.13780};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::vector, cgm_test::get(CGM::ETransformOrder::TSR));
        const auto expect = CGM::Vector<3,double>{+0.58881, -1.64312, -2.38653};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::vector, cgm_test::get(CGM::ETransformOrder::TRS));
        const auto expect = CGM::Vector<3,double>{+1.50091, -2.75058, -1.66519};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Transform, Matrix3)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM::transformed(cgm_test::orientation, cgm_test::get(CGM::ETransformOrder::SRT));
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+1.77181, +0.98431, -0.71973},
            CGM::Vector<3,double>{+0.79955, +1.74089, +1.84060},
            CGM::Vector<3,double>{+0.39641, +0.21304, +0.88038}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::orientation, cgm_test::get(CGM::ETransformOrder::STR));
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+1.77181, +0.98431, -0.71973},
            CGM::Vector<3,double>{+0.79955, +1.74089, +1.84060},
            CGM::Vector<3,double>{+0.39641, +0.21304, +0.88038}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::orientation, cgm_test::get(CGM::ETransformOrder::RST));
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+1.75566, +0.52078, -0.51638},
            CGM::Vector<3,double>{-0.04422, +2.53156, +1.38211},
            CGM::Vector<3,double>{+0.62995, -0.56671, -0.04900}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::orientation, cgm_test::get(CGM::ETransformOrder::RTS));
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+1.75566, +0.52078, -0.51638},
            CGM::Vector<3,double>{-0.04422, +2.53156, +1.38211},
            CGM::Vector<3,double>{+0.62995, -0.56671, -0.04900}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::orientation, cgm_test::get(CGM::ETransformOrder::TSR));
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+1.77181, +0.98431, -0.71973},
            CGM::Vector<3,double>{+0.79955, +1.74089, +1.84060},
            CGM::Vector<3,double>{+0.39641, +0.21304, +0.88038}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::orientation, cgm_test::get(CGM::ETransformOrder::TRS));
        const auto expect = CGM::orientationMatrix
        (
            CGM::Vector<3,double>{+1.75566, +0.52078, -0.51638},
            CGM::Vector<3,double>{-0.04422, +2.53156, +1.38211},
            CGM::Vector<3,double>{+0.62995, -0.56671, -0.04900}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Transform, Matrix4)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM::transformed(cgm_test::space, cgm_test::get(CGM::ETransformOrder::SRT));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.77181, +0.98431, -0.71973},
            CGM::Vector<3,double>{+0.79955, +1.74089, +1.84060},
            CGM::Vector<3,double>{+0.39641, +0.21304, +0.88038},
            CGM::Vector<3,double>{+2.76894, -0.43228, +1.36117}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::space, cgm_test::get(CGM::ETransformOrder::STR));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.77181, +0.98431, -0.71973},
            CGM::Vector<3,double>{+0.79955, +1.74089, +1.84060},
            CGM::Vector<3,double>{+0.39641, +0.21304, +0.88038},
            CGM::Vector<3,double>{+2.46529, -0.84830, -0.09881}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::space, cgm_test::get(CGM::ETransformOrder::RST));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.75566, +0.52078, -0.51638},
            CGM::Vector<3,double>{-0.04422, +2.53156, +1.38211},
            CGM::Vector<3,double>{+0.62995, -0.56671, -0.04900},
            CGM::Vector<3,double>{+1.46125, +1.50507, +2.62802}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::space, cgm_test::get(CGM::ETransformOrder::RTS));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.75566, +0.52078, -0.51638},
            CGM::Vector<3,double>{-0.04422, +2.53156, +1.38211},
            CGM::Vector<3,double>{+0.62995, -0.56671, -0.04900},
            CGM::Vector<3,double>{+1.52635, -0.27851, +0.13780}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::space, cgm_test::get(CGM::ETransformOrder::TSR));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.77181, +0.98431, -0.71973},
            CGM::Vector<3,double>{+0.79955, +1.74089, +1.84060},
            CGM::Vector<3,double>{+0.39641, +0.21304, +0.88038},
            CGM::Vector<3,double>{+0.58881, -1.64312, -2.38653}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformed(cgm_test::space, cgm_test::get(CGM::ETransformOrder::TRS));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.75566, +0.52078, -0.51638},
            CGM::Vector<3,double>{-0.04422, +2.53156, +1.38211},
            CGM::Vector<3,double>{+0.62995, -0.56671, -0.04900},
            CGM::Vector<3,double>{+1.50091, -2.75058, -1.66519}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Transform, XFormMatrix)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM::transformMatrix(cgm_test::get(CGM::ETransformOrder::SRT));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.23595, +1.44958, +0.55398},
            CGM::Vector<3,double>{+0.09045, +1.92652, +0.57034},
            CGM::Vector<3,double>{-1.39478, +1.09013, +1.24382},
            CGM::Vector<3,double>{+1.44063, -2.02528, +2.01868}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformMatrix(cgm_test::get(CGM::ETransformOrder::STR));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.23595, +1.44958, +0.55398},
            CGM::Vector<3,double>{+0.09045, +1.92652, +0.57034},
            CGM::Vector<3,double>{-1.39478, +1.09013, +1.24382},
            CGM::Vector<3,double>{+1.13699, -2.44130, +0.55870}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformMatrix(cgm_test::get(CGM::ETransformOrder::RST));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.63196, +0.67040, +0.60699},
            CGM::Vector<3,double>{-0.75802, +2.53491, -0.02799},
            CGM::Vector<3,double>{-1.09540, +0.96024, +0.23943},
            CGM::Vector<3,double>{+1.03787, -1.38371, +2.06084}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformMatrix(cgm_test::get(CGM::ETransformOrder::RTS));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.63196, +0.67040, +0.60699},
            CGM::Vector<3,double>{-0.75802, +2.53491, -0.02799},
            CGM::Vector<3,double>{-1.09540, +0.96024, +0.23943},
            CGM::Vector<3,double>{+1.10297, -3.16729, -0.42938}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformMatrix(cgm_test::get(CGM::ETransformOrder::TSR));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.23595, +1.44958, +0.55398},
            CGM::Vector<3,double>{+0.09045, +1.92652, +0.57034},
            CGM::Vector<3,double>{-1.39478, +1.09013, +1.24382},
            CGM::Vector<3,double>{-0.73950, -3.23612, -1.72902}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM::transformMatrix(cgm_test::get(CGM::ETransformOrder::TRS));
        const auto expect = CGM::spaceMatrix
        (
            CGM::Vector<3,double>{+1.63196, +0.67040, +0.60699},
            CGM::Vector<3,double>{-0.75802, +2.53491, -0.02799},
            CGM::Vector<3,double>{-1.09540, +0.96024, +0.23943},
            CGM::Vector<3,double>{+1.07754, -5.63936, -2.23237}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}