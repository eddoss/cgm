

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/interpolations/functions/fit_unclamped.hpp>


using namespace std;

TEST(Interpolations_UnclampedFit11, NMin_less_NMax)
{
    const auto nmin = -1.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = -7.0f;
        const auto r = CGM::ufit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 5.0f;
        const auto r = CGM::ufit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.0f;
        const auto e = 11.0f;
        const auto r = CGM::ufit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_UnclampedFit11, NMin_greater_NMax)
{
    const auto nmin = 10.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = 12.25f;
        const auto r = CGM::ufit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 7.75f;
        const auto r = CGM::ufit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.0f;
        const auto e = 5.5f;
        const auto r = CGM::ufit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}