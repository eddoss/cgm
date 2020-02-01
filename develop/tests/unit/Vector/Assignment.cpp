

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Vector/Vector.hpp>


using namespace std;
using Vec = Vector<3>;

TEST(Vector_Assignment, Assignment_Scalar)
{
    Vec::value_type scalar = 4;
    Vec input {1,2,3};
    input = scalar;

    ASSERT_EQ(input[0], scalar);
    ASSERT_EQ(input[1], scalar);
    ASSERT_EQ(input[2], scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Assignment, Assignment_Other)
{
    Vec input {1,2,3};
    Vec other {4,5,6};
    input = other;

    ASSERT_EQ(input[0], other[0]);
    ASSERT_EQ(input[1], other[1]);
    ASSERT_EQ(input[2], other[2]);
}
