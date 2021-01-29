

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Interpolations/Functions/FitUnclamped.hpp>


using namespace std;

TEST(Interpolations_UnclampedFit01, NMin_less_NMax)
{
    const auto nmin = -1.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = -21.0f;
        const auto r = CGM::ufit01(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 3.0f;
        const auto r = CGM::ufit01(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 9.0f;
        const auto e = 71.0f;
        const auto r = CGM::ufit01(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_UnclampedFit01, NMin_greater_NMax)
{
    const auto nmin = 10.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = 17.5f;
        const auto r = CGM::ufit01(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 8.5f;
        const auto r = CGM::ufit01(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.0f;
        const auto e = 4.0f;
        const auto r = CGM::ufit01(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}