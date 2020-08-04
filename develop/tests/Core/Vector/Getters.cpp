

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>


using namespace std;
using namespace CGM;

using Vec2 = Vector<2,float>;
using Vec3 = Vector<3,float>;
using Vec4 = Vector<4,float>;
using Vec5 = Vector<5,float>;


TEST(Vector_Getters, XY)
{
    {
        Vector<3,int> vec {2,3,4};
        Vector<2,int> exp {2,3};
        Vector<2,int> res = vec.xy();

        ASSERT_TRUE(res == exp);
    }

    /* -------------- */

    {
        Vector<4,int> vec {2,3,4,5};
        Vector<2,int> exp {2,3};
        Vector<2,int> res = vec.xy();

        ASSERT_TRUE(res == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Getters, XYZ)
{
    {
        Vector<4,int> vec {2,3,4,5};
        Vector<3,int> exp {2,3,4};
        Vector<3,int> res = vec.xyz();

        ASSERT_TRUE(res == exp);
    }
}