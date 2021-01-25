

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Core/Operators/Vector.hpp>


using namespace std;

TEST(Vector_ComparisonWithOther, Equal)
{
    {
        CGM::Vector<2,int> vec { 2, 4 };
        CGM::Vector<2,int> eql { 2, 4 };
        CGM::Vector<2,int> neq { 1, 2 };
        ASSERT_TRUE(vec == eql);
        ASSERT_FALSE(vec == neq);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 3, 6, 9 };
        CGM::Vector<3,int> eql { 3, 6, 9 };
        CGM::Vector<3,int> neq { 1, 2, 3 };
        ASSERT_TRUE(vec == eql);
        ASSERT_FALSE(vec == neq);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 2, 4, 6, 8 };
        CGM::Vector<4,int> eql { 2, 4, 6, 8 };
        CGM::Vector<4,int> neq { 1, 2, 3, 4 };
        ASSERT_TRUE(vec == eql);
        ASSERT_FALSE(vec == neq);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 2, 4, 6, 8, 10 };
        CGM::Vector<5,int> eql { 2, 4, 6, 8, 10 };
        CGM::Vector<5,int> neq { 1, 2, 3, 4, 5 };
        ASSERT_TRUE(vec == eql);
        ASSERT_FALSE(vec == neq);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, NonEqual)
{
    {
        CGM::Vector<2,int> vec { 2, 4 };
        CGM::Vector<2,int> eql { 2, 4 };
        CGM::Vector<2,int> neq { 1, 2 };
        ASSERT_TRUE(vec != neq);
        ASSERT_FALSE(vec != eql);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 3, 6, 9 };
        CGM::Vector<3,int> eql { 3, 6, 9 };
        CGM::Vector<3,int> neq { 1, 2, 3 };
        ASSERT_TRUE(vec != neq);
        ASSERT_FALSE(vec != eql);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 2, 4, 6, 8 };
        CGM::Vector<4,int> eql { 2, 4, 6, 8 };
        CGM::Vector<4,int> neq { 1, 2, 3, 4 };
        ASSERT_TRUE(vec != neq);
        ASSERT_FALSE(vec != eql);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 2, 4, 6, 8, 10 };
        CGM::Vector<5,int> eql { 2, 4, 6, 8, 10 };
        CGM::Vector<5,int> neq { 1, 2, 3, 4, 5 };
        ASSERT_TRUE(vec != neq);
        ASSERT_FALSE(vec != eql);
    }
}
