

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Interpolations/Functions/Fit.hpp>


using namespace std;

TEST(Interpolations_Fit10, NMin_less_NMax)
{
    const auto nmin = -1.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = 7.0f;
        const auto r = CGM::fit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.25f;
        const auto e = 5.0f;
        const auto r = CGM::fit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.0f;
        const auto e = -1.0f;
        const auto r = CGM::fit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_Fit10, NMin_greater_NMax)
{
    const auto nmin = 10.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = nmax;
        const auto r = CGM::fit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 8.5f;
        const auto r = CGM::fit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.0f;
        const auto e = nmin;
        const auto r = CGM::fit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}