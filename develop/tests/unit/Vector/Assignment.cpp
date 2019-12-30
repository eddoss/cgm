

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Vector.hpp>


using namespace std;
using Vec = Vector<3>;

TEST(Vector_Assignment, Assignment_Scalar)
{
    Vec::value_type scalar = 4;
    Vec input {1,2,3};
    input = scalar;

    for (const auto& val : input) ASSERT_EQ(val, scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Assignment, Assignment_Other)
{
    Vec input {1,2,3};
    Vec other {4,5,6};
    input = other;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], other[i]);
}
