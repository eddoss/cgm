

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/interpolations/functions/fit_unclamped.hpp>


using namespace std;

TEST(Interpolations_UnclampedFit, OMin_less_OMax_and_NMin_less_NMax)
{
    const auto omin = 2.0f;
    const auto omax = 4.0f;
    const auto nmin = -1.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = -19.0f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = -7.0f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.0f;
        const auto e = -1.0f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_UnclampedFit, OMin_greater_OMax_and_NMin_less_NMax)
{
    const auto omin = 8.0f;
    const auto omax = 2.0f;
    const auto nmin = -1.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = 13.0f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 9.0f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.0f;
        const auto e = 7.0f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_UnclampedFit, OMin_less_OMax_and_NMin_greater_NMax)
{
    const auto omin = 2.0f;
    const auto omax = 8.0f;
    const auto nmin = 7.0f;
    const auto nmax = 1.0f;

    {
        const auto v = -2.5f;
        const auto e = 11.5f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 8.5f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 9.0f;
        const auto e = 0.0f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_UnclampedFit, OMin_greater_OMax_and_NMin_greater_NMax)
{
    const auto omin = 8.0f;
    const auto omax = 2.0f;
    const auto nmin = 7.0f;
    const auto nmax = 1.0f;

    {
        const auto v = -2.5f;
        const auto e = -3.5f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = -0.5f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 9.0f;
        const auto e = 8.0f;
        const auto r = CGM::ufit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}