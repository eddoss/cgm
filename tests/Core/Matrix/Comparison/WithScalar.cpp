

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Core/Operators/Matrix.hpp>


using namespace CGM;

using namespace std;
using Mat12 = Matrix<1,2,int>;
using Mat13 = Matrix<1,3,int>;
using Mat14 = Matrix<1,4,int>;
using Mat15 = Matrix<1,5,int>;
using Mat21 = Matrix<2,1,int>;
using Mat22 = Matrix<2,2,int>;
using Mat23 = Matrix<2,3,int>;
using Mat24 = Matrix<2,4,int>;
using Mat25 = Matrix<2,5,int>;
using Mat31 = Matrix<3,1,int>;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;
using Mat35 = Matrix<3,5,int>;
using Mat41 = Matrix<4,1,int>;
using Mat42 = Matrix<4,2,int>;
using Mat43 = Matrix<4,3,int>;
using Mat44 = Matrix<4,4,int>;
using Mat45 = Matrix<4,5,int>;
using Mat51 = Matrix<5,1,int>;
using Mat55 = Matrix<5,5,int>;

TEST(Matrix_ComparisonWithScalar, Equal_PositiveTest)
{
    {
        auto x {Mat12::value_type(2)};
        Mat12 a(x);

        ASSERT_TRUE(a==x);;
    }

    {
        auto x {Mat13::value_type(2)};
        Mat13 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat14::value_type(2)};
        Mat14 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat15::value_type(2)};
        Mat15 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat21::value_type(2)};
        Mat21 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat22::value_type(2)};
        Mat22 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat23::value_type(2)};
        Mat23 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat24::value_type(2)};
        Mat24 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat25::value_type(2)};
        Mat25 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat31::value_type(2)};
        Mat31 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat32::value_type(2)};
        Mat32 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat33::value_type(2)};
        Mat33 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat34::value_type(2)};
        Mat34 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat35::value_type(2)};
        Mat35 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat41::value_type(2)};
        Mat41 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat42::value_type(2)};
        Mat42 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat43::value_type(2)};
        Mat43 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat44::value_type(2)};
        Mat44 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat45::value_type(2)};
        Mat45 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat51::value_type(2)};
        Mat51 a(x);

        ASSERT_TRUE(a==x);
    }

    {
        auto x {Mat55::value_type(2)};
        Mat55 a(x);

        ASSERT_TRUE(a==x);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, Equal_NegativeTest)
{
    {
        auto x {Mat12::value_type(2)};
        Mat12 a(x+1);

        ASSERT_FALSE(a==x);;
    }

    {
        auto x {Mat13::value_type(2)};
        Mat13 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat14::value_type(2)};
        Mat14 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat15::value_type(2)};
        Mat15 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat21::value_type(2)};
        Mat21 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat22::value_type(2)};
        Mat22 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat23::value_type(2)};
        Mat23 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat24::value_type(2)};
        Mat24 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat25::value_type(2)};
        Mat25 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat31::value_type(2)};
        Mat31 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat32::value_type(2)};
        Mat32 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat33::value_type(2)};
        Mat33 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat34::value_type(2)};
        Mat34 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat35::value_type(2)};
        Mat35 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat41::value_type(2)};
        Mat41 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat42::value_type(2)};
        Mat42 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat43::value_type(2)};
        Mat43 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat44::value_type(2)};
        Mat44 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat45::value_type(2)};
        Mat45 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat51::value_type(2)};
        Mat51 a(x+1);

        ASSERT_FALSE(a==x);
    }

    {
        auto x {Mat55::value_type(2)};
        Mat55 a(x+1);

        ASSERT_FALSE(a==x);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, NotEqual_PositiveTest)
{
    {
        auto x {Mat12::value_type(2)};
        Mat12 a(x+1);

        ASSERT_TRUE(a!=x);;
    }

    {
        auto x {Mat13::value_type(2)};
        Mat13 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat14::value_type(2)};
        Mat14 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat15::value_type(2)};
        Mat15 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat21::value_type(2)};
        Mat21 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat22::value_type(2)};
        Mat22 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat23::value_type(2)};
        Mat23 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat24::value_type(2)};
        Mat24 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat25::value_type(2)};
        Mat25 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat31::value_type(2)};
        Mat31 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat32::value_type(2)};
        Mat32 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat33::value_type(2)};
        Mat33 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat34::value_type(2)};
        Mat34 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat35::value_type(2)};
        Mat35 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat41::value_type(2)};
        Mat41 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat42::value_type(2)};
        Mat42 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat43::value_type(2)};
        Mat43 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat44::value_type(2)};
        Mat44 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat45::value_type(2)};
        Mat45 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat51::value_type(2)};
        Mat51 a(x+1);

        ASSERT_TRUE(a!=x);
    }

    {
        auto x {Mat55::value_type(2)};
        Mat55 a(x+1);

        ASSERT_TRUE(a!=x);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, NotEqual_NegativeTest)
{
    {
        auto x {Mat12::value_type(2)};
        Mat12 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat13::value_type(2)};
        Mat13 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat14::value_type(2)};
        Mat14 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat15::value_type(2)};
        Mat15 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat21::value_type(2)};
        Mat21 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat22::value_type(2)};
        Mat22 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat23::value_type(2)};
        Mat23 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat24::value_type(2)};
        Mat24 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat25::value_type(2)};
        Mat25 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat31::value_type(2)};
        Mat31 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat32::value_type(2)};
        Mat32 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat33::value_type(2)};
        Mat33 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat34::value_type(2)};
        Mat34 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat35::value_type(2)};
        Mat35 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat41::value_type(2)};
        Mat41 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat42::value_type(2)};
        Mat42 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat43::value_type(2)};
        Mat43 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat44::value_type(2)};
        Mat44 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat45::value_type(2)};
        Mat45 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat51::value_type(2)};
        Mat51 a(x);

        ASSERT_FALSE(a!=x);
    }

    {
        auto x {Mat55::value_type(2)};
        Mat55 a(x);

        ASSERT_FALSE(a!=x);
    }
}
