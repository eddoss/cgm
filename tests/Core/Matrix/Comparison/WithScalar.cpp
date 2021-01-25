

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Core/Operators/Matrix.hpp>


using namespace std;

TEST(Matrix_ComparisonWithScalar, Equal_PositiveTest)
{
    {
        auto x {CGM::Matrix<1,2,int>::value_type(2)};
        CGM::Matrix<1,2,int> a(x);

        ASSERT_TRUE(a==x);;
    }

    {
        auto x {CGM::Matrix<1,3,int>::value_type(2)};
        CGM::Matrix<1,3,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<1,4,int>::value_type(2)};
        CGM::Matrix<1,4,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<1,5,int>::value_type(2)};
        CGM::Matrix<1,5,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<2,1,int>::value_type(2)};
        CGM::Matrix<2,1,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<2,2,int>::value_type(2)};
        CGM::Matrix<2,2,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<2,3,int>::value_type(2)};
        CGM::Matrix<2,3,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<2,4,int>::value_type(2)};
        CGM::Matrix<2,4,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<2,5,int>::value_type(2)};
        CGM::Matrix<2,5,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<3,1,int>::value_type(2)};
        CGM::Matrix<3,1,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<3,2,int>::value_type(2)};
        CGM::Matrix<3,2,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<3,3,int>::value_type(2)};
        CGM::Matrix<3,3,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<3,4,int>::value_type(2)};
        CGM::Matrix<3,4,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<3,5,int>::value_type(2)};
        CGM::Matrix<3,5,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<4,1,int>::value_type(2)};
        CGM::Matrix<4,1,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<4,2,int>::value_type(2)};
        CGM::Matrix<4,2,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<4,3,int>::value_type(2)};
        CGM::Matrix<4,3,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<4,4,int>::value_type(2)};
        CGM::Matrix<4,4,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<4,5,int>::value_type(2)};
        CGM::Matrix<4,5,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<5,1,int>::value_type(2)};
        CGM::Matrix<5,1,int> a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {CGM::Matrix<5,5,int>::value_type(2)};
        CGM::Matrix<5,5,int> a(x);

        ASSERT_TRUE(a==x);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, Equal_NegativeTest)
{
    {
        auto x {CGM::Matrix<1,2,int>::value_type(2)};
        CGM::Matrix<1,2,int> a(x+1);

        ASSERT_FALSE(a==x);;
    }

    {
        auto x {CGM::Matrix<1,3,int>::value_type(2)};
        CGM::Matrix<1,3,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<1,4,int>::value_type(2)};
        CGM::Matrix<1,4,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<1,5,int>::value_type(2)};
        CGM::Matrix<1,5,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<2,1,int>::value_type(2)};
        CGM::Matrix<2,1,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<2,2,int>::value_type(2)};
        CGM::Matrix<2,2,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<2,3,int>::value_type(2)};
        CGM::Matrix<2,3,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<2,4,int>::value_type(2)};
        CGM::Matrix<2,4,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<2,5,int>::value_type(2)};
        CGM::Matrix<2,5,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<3,1,int>::value_type(2)};
        CGM::Matrix<3,1,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<3,2,int>::value_type(2)};
        CGM::Matrix<3,2,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<3,3,int>::value_type(2)};
        CGM::Matrix<3,3,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<3,4,int>::value_type(2)};
        CGM::Matrix<3,4,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<3,5,int>::value_type(2)};
        CGM::Matrix<3,5,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<4,1,int>::value_type(2)};
        CGM::Matrix<4,1,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<4,2,int>::value_type(2)};
        CGM::Matrix<4,2,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<4,3,int>::value_type(2)};
        CGM::Matrix<4,3,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<4,4,int>::value_type(2)};
        CGM::Matrix<4,4,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<4,5,int>::value_type(2)};
        CGM::Matrix<4,5,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<5,1,int>::value_type(2)};
        CGM::Matrix<5,1,int> a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {CGM::Matrix<5,5,int>::value_type(2)};
        CGM::Matrix<5,5,int> a(x+1);

        ASSERT_FALSE(a==x);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, NotEqual_PositiveTest)
{
    {
        auto x {CGM::Matrix<1,2,int>::value_type(2)};
        CGM::Matrix<1,2,int> a(x+1);

        ASSERT_TRUE(a!=x);;
    }

    {
        auto x {CGM::Matrix<1,3,int>::value_type(2)};
        CGM::Matrix<1,3,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<1,4,int>::value_type(2)};
        CGM::Matrix<1,4,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<1,5,int>::value_type(2)};
        CGM::Matrix<1,5,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<2,1,int>::value_type(2)};
        CGM::Matrix<2,1,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<2,2,int>::value_type(2)};
        CGM::Matrix<2,2,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<2,3,int>::value_type(2)};
        CGM::Matrix<2,3,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<2,4,int>::value_type(2)};
        CGM::Matrix<2,4,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<2,5,int>::value_type(2)};
        CGM::Matrix<2,5,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<3,1,int>::value_type(2)};
        CGM::Matrix<3,1,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<3,2,int>::value_type(2)};
        CGM::Matrix<3,2,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<3,3,int>::value_type(2)};
        CGM::Matrix<3,3,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<3,4,int>::value_type(2)};
        CGM::Matrix<3,4,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<3,5,int>::value_type(2)};
        CGM::Matrix<3,5,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<4,1,int>::value_type(2)};
        CGM::Matrix<4,1,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<4,2,int>::value_type(2)};
        CGM::Matrix<4,2,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<4,3,int>::value_type(2)};
        CGM::Matrix<4,3,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<4,4,int>::value_type(2)};
        CGM::Matrix<4,4,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<4,5,int>::value_type(2)};
        CGM::Matrix<4,5,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<5,1,int>::value_type(2)};
        CGM::Matrix<5,1,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {CGM::Matrix<5,5,int>::value_type(2)};
        CGM::Matrix<5,5,int> a(x+1);

        ASSERT_TRUE(a!=x);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, NotEqual_NegativeTest)
{
    {
        auto x {CGM::Matrix<1,2,int>::value_type(2)};
        CGM::Matrix<1,2,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<1,3,int>::value_type(2)};
        CGM::Matrix<1,3,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<1,4,int>::value_type(2)};
        CGM::Matrix<1,4,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<1,5,int>::value_type(2)};
        CGM::Matrix<1,5,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<2,1,int>::value_type(2)};
        CGM::Matrix<2,1,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<2,2,int>::value_type(2)};
        CGM::Matrix<2,2,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<2,3,int>::value_type(2)};
        CGM::Matrix<2,3,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<2,4,int>::value_type(2)};
        CGM::Matrix<2,4,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<2,5,int>::value_type(2)};
        CGM::Matrix<2,5,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<3,1,int>::value_type(2)};
        CGM::Matrix<3,1,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<3,2,int>::value_type(2)};
        CGM::Matrix<3,2,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<3,3,int>::value_type(2)};
        CGM::Matrix<3,3,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<3,4,int>::value_type(2)};
        CGM::Matrix<3,4,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<3,5,int>::value_type(2)};
        CGM::Matrix<3,5,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<4,1,int>::value_type(2)};
        CGM::Matrix<4,1,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<4,2,int>::value_type(2)};
        CGM::Matrix<4,2,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<4,3,int>::value_type(2)};
        CGM::Matrix<4,3,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<4,4,int>::value_type(2)};
        CGM::Matrix<4,4,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<4,5,int>::value_type(2)};
        CGM::Matrix<4,5,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<5,1,int>::value_type(2)};
        CGM::Matrix<5,1,int> a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {CGM::Matrix<5,5,int>::value_type(2)};
        CGM::Matrix<5,5,int> a(x);

        ASSERT_FALSE(a!=x);
    }
}
