

#include "Input.hpp"
#include <CGM/Modules/Transformations/3D/Functions/Transform.hpp>


using namespace std;
using namespace CGM;

TEST(Transformations_Transform, Vector)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::transformed(cgm_test::vector, cgm_test::transform::get(ETransformOrder::SRT));
        const auto expect = Vector<3,double>{+2.76894, -0.43228, +1.36117};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::transformed(cgm_test::vector, cgm_test::transform::get(ETransformOrder::STR));
        const auto expect = Vector<3,double>{+2.46529, -0.84830, -0.09881};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::transformed(cgm_test::vector, cgm_test::transform::get(ETransformOrder::RST));
        const auto expect = Vector<3,double>{+1.46125, +1.50507, +2.62802};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::transformed(cgm_test::vector, cgm_test::transform::get(ETransformOrder::RTS));
        const auto expect = Vector<3,double>{+1.52635, -0.27851, +0.13780};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::transformed(cgm_test::vector, cgm_test::transform::get(ETransformOrder::TSR));
        const auto expect = Vector<3,double>{+0.58881, -1.64312, -2.38653};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::transformed(cgm_test::vector, cgm_test::transform::get(ETransformOrder::TRS));
        const auto expect = Vector<3,double>{+1.50091, -2.75058, -1.66519};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Transform, Matrix3)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::SRT));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+1.77181, +0.98431, -0.71973},
                Vector<3,double>{+0.79955, +1.74089, +1.84060},
                Vector<3,double>{+0.39641, +0.21304, +0.88038}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::STR));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+1.77181, +0.98431, -0.71973},
                Vector<3,double>{+0.79955, +1.74089, +1.84060},
                Vector<3,double>{+0.39641, +0.21304, +0.88038}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::RST));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+1.75566, +0.52078, -0.51638},
                Vector<3,double>{-0.04422, +2.53156, +1.38211},
                Vector<3,double>{+0.62995, -0.56671, -0.04900}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::RTS));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+1.75566, +0.52078, -0.51638},
                Vector<3,double>{-0.04422, +2.53156, +1.38211},
                Vector<3,double>{+0.62995, -0.56671, -0.04900}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::TSR));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+1.77181, +0.98431, -0.71973},
                Vector<3,double>{+0.79955, +1.74089, +1.84060},
                Vector<3,double>{+0.39641, +0.21304, +0.88038}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::TRS));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+1.75566, +0.52078, -0.51638},
                Vector<3,double>{-0.04422, +2.53156, +1.38211},
                Vector<3,double>{+0.62995, -0.56671, -0.04900}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::SRT));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+1.064486, -0.178029, -1.544259},
                Vector<3,double>{+0.037521, +2.414990, +0.062452},
                Vector<3,double>{-0.280460, +1.306320, +1.451641}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::STR));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.452372, +0.772967, -1.607359},
                Vector<3,double>{-0.832001, +1.967266, +1.000411},
                Vector<3,double>{-0.221421, +0.536952, +1.837263}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::RST));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+1.064486, -0.178029, -1.544259},
                Vector<3,double>{+0.037521, +2.414990, +0.062452},
                Vector<3,double>{-0.280460, +1.306320, +1.451641}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::RTS));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.452372, +0.772967, -1.607359},
                Vector<3,double>{-0.832001, +1.967266, +1.000411},
                Vector<3,double>{-0.221421, +0.536952, +1.837263}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::TSR));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+1.064486, -0.178029, -1.544259},
                Vector<3,double>{+0.037521, +2.414990, +0.062452},
                Vector<3,double>{-0.280460, +1.306320, +1.451641}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::transform::get(ETransformOrder::TRS));
            const auto expect = CGM_XYZ::orientationMatrix
            (
                Vector<3,double>{+0.452372, +0.772967, -1.607359},
                Vector<3,double>{-0.832001, +1.967266, +1.000411},
                Vector<3,double>{-0.221421, +0.536952, +1.837263}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Transform, Matrix4)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::transform::get(ETransformOrder::SRT));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+1.77181, +0.98431, -0.71973},
                Vector<3,double>{+0.79955, +1.74089, +1.84060},
                Vector<3,double>{+0.39641, +0.21304, +0.88038},
                Vector<3,double>{+2.76894, -0.43228, +1.36117}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::transform::get(ETransformOrder::STR));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+1.77181, +0.98431, -0.71973},
                Vector<3,double>{+0.79955, +1.74089, +1.84060},
                Vector<3,double>{+0.39641, +0.21304, +0.88038},
                Vector<3,double>{+2.46529, -0.84830, -0.09881}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::transform::get(ETransformOrder::RST));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+1.75566, +0.52078, -0.51638},
                Vector<3,double>{-0.04422, +2.53156, +1.38211},
                Vector<3,double>{+0.62995, -0.56671, -0.04900},
                Vector<3,double>{+1.46125, +1.50507, +2.62802}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::transform::get(ETransformOrder::RTS));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+1.75566, +0.52078, -0.51638},
                Vector<3,double>{-0.04422, +2.53156, +1.38211},
                Vector<3,double>{+0.62995, -0.56671, -0.04900},
                Vector<3,double>{+1.52635, -0.27851, +0.13780}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::transform::get(ETransformOrder::TSR));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+1.77181, +0.98431, -0.71973},
                Vector<3,double>{+0.79955, +1.74089, +1.84060},
                Vector<3,double>{+0.39641, +0.21304, +0.88038},
                Vector<3,double>{+0.58881, -1.64312, -2.38653}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::transform::get(ETransformOrder::TRS));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+1.75566, +0.52078, -0.51638},
                Vector<3,double>{-0.04422, +2.53156, +1.38211},
                Vector<3,double>{+0.62995, -0.56671, -0.04900},
                Vector<3,double>{+1.50091, -2.75058, -1.66519}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::transform::get(ETransformOrder::SRT));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.913601, +0.914414, -1.345494},
                Vector<3,double>{+0.501631, +2.144260, +1.466869},
                Vector<3,double>{+0.348654, +0.524318, +1.335242},
                Vector<3,double>{+2.649072, -0.243389, +0.253458}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::transform::get(ETransformOrder::STR));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.913601, +0.914414, -1.345494},
                Vector<3,double>{+0.501631, +2.144260, +1.466869},
                Vector<3,double>{+0.348654, +0.524318, +1.335242},
                Vector<3,double>{+2.429494, -0.477217, -1.261113}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::transform::get(ETransformOrder::RST));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+1.682103, +0.312585, -1.229075},
                Vector<3,double>{-0.478418, +2.327744, +1.466313},
                Vector<3,double>{+0.572174, +0.216841, +0.228380},
                Vector<3,double>{+2.002954, +0.113882, +0.428093}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::transform::get(ETransformOrder::RTS));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+1.682103, +0.312585, -1.229075},
                Vector<3,double>{-0.478418, +2.327744, +1.466313},
                Vector<3,double>{+0.572174, +0.216841, +0.228380},
                Vector<3,double>{+2.636437, -0.938846, -2.378561}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::transform::get(ETransformOrder::TSR));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+0.913601, +0.914414, -1.345494},
                Vector<3,double>{+0.501631, +2.144260, +1.466869},
                Vector<3,double>{+0.348654, +0.524318, +1.335242},
                Vector<3,double>{+0.914348, -1.624685, -3.664130}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM3D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::transform::get(ETransformOrder::TRS));
            const auto expect = CGM_XYZ::spaceMatrix
            (
                Vector<3,double>{+1.682103, +0.312585, -1.229075},
                Vector<3,double>{-0.478418, +2.327744, +1.466313},
                Vector<3,double>{+0.572174, +0.216841, +0.228380},
                Vector<3,double>{+3.573177, -2.754808, -4.656141}
            );
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations_Transform, XFormMatrix)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM_XFORM3D::transformMatrix(cgm_test::transform::get(ETransformOrder::SRT));
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.23595, +1.44958, +0.55398},
            Vector<3,double>{+0.09045, +1.92652, +0.57034},
            Vector<3,double>{-1.39478, +1.09013, +1.24382},
            Vector<3,double>{+1.44063, -2.02528, +2.01868}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::transformMatrix(cgm_test::transform::get(ETransformOrder::STR));
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.23595, +1.44958, +0.55398},
            Vector<3,double>{+0.09045, +1.92652, +0.57034},
            Vector<3,double>{-1.39478, +1.09013, +1.24382},
            Vector<3,double>{+1.13699, -2.44130, +0.55870}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::transformMatrix(cgm_test::transform::get(ETransformOrder::RST));
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.63196, +0.67040, +0.60699},
            Vector<3,double>{-0.75802, +2.53491, -0.02799},
            Vector<3,double>{-1.09540, +0.96024, +0.23943},
            Vector<3,double>{+1.03787, -1.38371, +2.06084}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::transformMatrix(cgm_test::transform::get(ETransformOrder::RTS));
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.63196, +0.67040, +0.60699},
            Vector<3,double>{-0.75802, +2.53491, -0.02799},
            Vector<3,double>{-1.09540, +0.96024, +0.23943},
            Vector<3,double>{+1.10297, -3.16729, -0.42938}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::transformMatrix(cgm_test::transform::get(ETransformOrder::TSR));
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.23595, +1.44958, +0.55398},
            Vector<3,double>{+0.09045, +1.92652, +0.57034},
            Vector<3,double>{-1.39478, +1.09013, +1.24382},
            Vector<3,double>{-0.73950, -3.23612, -1.72902}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM3D::transformMatrix(cgm_test::transform::get(ETransformOrder::TRS));
        const auto expect = CGM_XYZ::spaceMatrix
        (
            Vector<3,double>{+1.63196, +0.67040, +0.60699},
            Vector<3,double>{-0.75802, +2.53491, -0.02799},
            Vector<3,double>{-1.09540, +0.96024, +0.23943},
            Vector<3,double>{+1.07754, -5.63936, -2.23237}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}