

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Core/Operators/Vector.hpp>


using namespace std;


TEST(Vector_Getters, XY)
{
    {
        CGM::Vector<3,int> vec {2,3,4};
        CGM::Vector<2,int> exp {2,3};
        CGM::Vector<2,int> res = vec.xy();

        ASSERT_TRUE(res == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec {2,3,4,5};
        CGM::Vector<2,int> exp {2,3};
        CGM::Vector<2,int> res = vec.xy();

        ASSERT_TRUE(res == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Getters, XYZ)
{
    {
        CGM::Vector<4,int> vec {2,3,4,5};
        CGM::Vector<3,int> exp {2,3,4};
        CGM::Vector<3,int> res = vec.xyz();

        ASSERT_TRUE(res == exp);
    }
}