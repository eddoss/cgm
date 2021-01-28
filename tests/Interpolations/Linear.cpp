

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Interpolations/Functions/Numbers.hpp>


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