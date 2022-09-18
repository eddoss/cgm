

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/functions/vector.hpp>
#include <cgm/modules/transformations/3d/functions/refract.hpp>
#include "input.hpp"


using namespace std;

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

TEST(Transformations3D_Refraction, Vector_DefaultPlane)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    {
        const auto result = CGM::refracted<CGM_PLANE_XY>(cgm_test::vector, cgm_test::ior);
        const auto expect = CGM::Vector<3,double>{ +0.062500, +0.300000, -1.021335 };
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM::refracted<CGM_PLANE_YZ>(cgm_test::vector, cgm_test::ior);
        const auto expect = CGM::Vector<3,double>{ -0.970261, +0.300000, -0.325000 };
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
    {
        const auto result = CGM::refracted<CGM_PLANE_ZX>(cgm_test::vector, cgm_test::ior);
        const auto expect = CGM::Vector<3,double>{ +0.062500, -1.013657, -0.325000 };
        ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations3D_Refraction, Vector_PlaneNormal)
{
    namespace cgm_test = cgm_xyz_xform_tests_data;

    const auto result = CGM::refracted(cgm_test::vector, cgm_test::normal, cgm_test::ior);
    const auto expect = CGM::Vector<3,double>{ -0.297188, +0.140751, -1.014347 };
    ASSERT_TRUE(CGM::eq(result, expect, 0.00001));
}