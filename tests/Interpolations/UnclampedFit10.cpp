

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Interpolations/Functions/Numbers.hpp>


using namespace std;

TEST(Interpolations_UnclampedFit10, NMin_less_NMax)
{
    const auto nmin = -1.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = 27.0f;
        const auto r = CGM::ufit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 3.0f;
        const auto r = CGM::ufit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.0f;
        const auto e = -9.0f;
        const auto r = CGM::ufit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_UnclampedFit10, NMin_greater_NMax)
{
    const auto nmin = 10.0f;
    const auto nmax = 7.0f;

    {
        const auto v = -2.5f;
        const auto e = -0.5f;
        const auto r = CGM::ufit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 0.5f;
        const auto e = 8.5f;
        const auto r = CGM::ufit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
    {
        const auto v = 2.0f;
        const auto e = 13.0f;
        const auto r = CGM::ufit10(v, nmin, nmax);

        ASSERT_FLOAT_EQ(r, e);
    }
}