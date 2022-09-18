

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/interpolations/functions/interps.hpp>


using namespace std;

TEST(Interpolations, Linear)
{
    const auto min = -1.0f;
    const auto max = 7.0f;

    {
        const auto v = -0.25f;
        const auto e = -3.0f;
        const auto r = CGM::lerp(min, max, v);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 3.0f;
        const auto r = CGM::lerp(min, max, v);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 1.25f;
        const auto e = 9.0f;
        const auto r = CGM::lerp(min, max, v);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations, Billinear)
{
    const auto A0 = 2.0f;
    const auto A1 = 5.0f;
    const auto B0 = 3.0f;
    const auto B1 = 8.0f;

    const auto u = 0.25f;
    const auto v = 0.35f;
    const auto e = 3.275f;
    const auto r = CGM::bilerp(A0, A1, B0, B1, u, v);

    ASSERT_FLOAT_EQ(r, e);
}


/* --------------------------------------------------------------------------------------- */

TEST(Interpolations, Spherical)
{

    const auto a = CGM::Quaternion<double>{-0.540327, 0.005888, 0.645047, 0.540302};
    const auto b = CGM::Quaternion<double>{-0.273366, -0.611370, -0.127001, 0.731689};
    const auto bias = 0.25;

    const auto e = CGM::Quaternion<double>{-0.528142, -0.181124, 0.492597, 0.667539};
    const auto r = CGM::slerp(a, b, bias);

    ASSERT_TRUE(CGM::eq(r, e, 0.001));
}