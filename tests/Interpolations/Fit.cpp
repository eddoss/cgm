

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Interpolations/Functions/Fit.hpp>


using namespace std;

TEST(Interpolations_Fit, OMin_less_OMax_and_NMin_less_NMax)
{
    const auto omin = 2.0f;
    const auto omax = 4.0f;
    const auto nmin = -1.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = nmin;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.5f;
        const auto e = 1.0f;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 5.0f;
        const auto e = nmax;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_Fit, OMin_greater_OMax_and_NMin_less_NMax)
{
    const auto omin = 8.0f;
    const auto omax = 2.0f;
    const auto nmin = -1.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = nmax;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 6.5f;
        const auto e = 1.0f;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 9.0f;
        const auto e = nmin;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_Fit, OMin_less_OMax_and_NMin_greater_NMax)
{
    const auto omin = 2.0f;
    const auto omax = 8.0f;
    const auto nmin = 7.0f;
    const auto nmax = 1.0f;

    {
        const auto v = -2.5f;
        const auto e = nmin;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 6.5f;
        const auto e = 2.5f;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 9.0f;
        const auto e = nmax;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_Fit, OMin_greater_OMax_and_NMin_greater_NMax)
{
    const auto omin = 8.0f;
    const auto omax = 2.0f;
    const auto nmin = 7.0f;
    const auto nmax = 1.0f;

    {
        const auto v = -2.5f;
        const auto e = nmax;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 6.5f;
        const auto e = 5.5f;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 9.0f;
        const auto e = nmin;
        const auto r = CGM::fit(v, omin, omax, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}