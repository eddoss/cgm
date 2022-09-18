

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/operators/vector.hpp>


using namespace std;

TEST(Vector_ComparisonWithScalar, Equal)
{
    {
        CGM::Vector<2,int>::value_type v = 2;
        CGM::Vector<2,int> eql(v);
        CGM::Vector<2,int> neq(v + 1);
        ASSERT_TRUE(eql == v);
        ASSERT_FALSE(neq == v);
    }

    /* -------------- */

    {
        CGM::Vector<3,int>::value_type v = 2;
        CGM::Vector<3,int> eql(v);
        CGM::Vector<3,int> neq(v + 1);
        ASSERT_TRUE(eql == v);
        ASSERT_FALSE(neq == v);
    }

    /* -------------- */

    {
        CGM::Vector<4,int>::value_type v = 2;
        CGM::Vector<4,int> eql(v);
        CGM::Vector<4,int> neq(v + 1);
        ASSERT_TRUE(eql == v);
        ASSERT_FALSE(neq == v);
    }

    /* -------------- */

    {
        CGM::Vector<5,int>::value_type v = 2;
        CGM::Vector<5,int> eql(v);
        CGM::Vector<5,int> neq(v + 1);
        ASSERT_TRUE(eql == v);
        ASSERT_FALSE(neq == v);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, NonEqual)
{
    {
        CGM::Vector<2,int>::value_type v = 2;
        CGM::Vector<2,int> eql(v);
        CGM::Vector<2,int> neq(v + 1);
        ASSERT_TRUE(neq != v);
        ASSERT_FALSE(eql != v);
    }

    /* -------------- */

    {
        CGM::Vector<3,int>::value_type v = 2;
        CGM::Vector<3,int> eql(v);
        CGM::Vector<3,int> neq(v + 1);
        ASSERT_TRUE(neq != v);
        ASSERT_FALSE(eql != v);
    }

    /* -------------- */

    {
        CGM::Vector<4,int>::value_type v = 2;
        CGM::Vector<4,int> eql(v);
        CGM::Vector<4,int> neq(v + 1);
        ASSERT_TRUE(neq != v);
        ASSERT_FALSE(eql != v);
    }

    /* -------------- */

    {
        CGM::Vector<5,int>::value_type v = 2;
        CGM::Vector<5,int> eql(v);
        CGM::Vector<5,int> neq(v + 1);
        ASSERT_TRUE(neq != v);
        ASSERT_FALSE(eql != v);
    }
}
