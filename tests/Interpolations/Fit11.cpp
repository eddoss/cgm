

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Interpolations/Functions/Numbers.hpp>


using namespace std;

TEST(Interpolations_Fit11, NMin_less_NMax)
{
    const auto nmin = -1.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = nmin;
        const auto r = CGM::fit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 5.0f;
        const auto r = CGM::fit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.0f;
        const auto e = nmax;
        const auto r = CGM::fit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_Fit11, NMin_greater_NMax)
{
    const auto nmin = 10.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = nmin;
        const auto r = CGM::fit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 7.75f;
        const auto r = CGM::fit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.0f;
        const auto e = nmax;
        const auto r = CGM::fit11(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}
