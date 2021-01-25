

#include "Input.hpp"
#include <CGM/Transformations/2D/Functions/Refract.hpp>


using namespace std;

TEST(Transformations2D_Refraction, Vector_PlaneNormal)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    const auto result = CGM_XFORM2D::refracted(cgm_test::vector, cgm_test::normal, cgm_test::ior);
    const auto expect = CGM::Vector<2,double>{ -0.526735, -0.868306 };
    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}