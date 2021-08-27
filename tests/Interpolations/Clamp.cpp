

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Interpolations/Functions/Clamp.hpp>


using namespace std;

TEST(Interpolations_Clamp, A_less_B)
{
    const int a = 2;
    const int b = 4;

    {
        const int v = -1;
        const int e = a;
        const int r = CGM::clamp(v, a, b);

        ASSERT_EQ(r, e);
    }
    {
        const int v = 3;
        const int e = v;
        const int r = CGM::clamp(v, a, b);

        ASSERT_EQ(r, e);
    }
    {
        const int v = 5;
        const int e = b;
        const int r = CGM::clamp(v, a, b);

        ASSERT_EQ(r, e);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Interpolations_Clamp, A_greater_B)
{
    const int a = 4;
    const int b = 2;

    {
        const int v = -1;
        const int e = b;
        const int r = CGM::clamp(v, a, b);

        ASSERT_EQ(r, e);
    }
    {
        const int v = 3;
        const int e = v;
        const int r = CGM::clamp(v, a, b);

        ASSERT_EQ(r, e);
    }
    {
        const int v = 5;
        const int e = a;
        const int r = CGM::clamp(v, a, b);

        ASSERT_EQ(r, e);
    }
}