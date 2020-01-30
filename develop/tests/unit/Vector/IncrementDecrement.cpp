

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Vector/Vector.hpp>
#include <Math3D/Core/Structs/Vector/Operators.hpp>


using namespace std;
using Vec = Vector<3>;

/* ####################################################################################### */
/* Increment */
/* ####################################################################################### */

TEST(Vector_IncrementDecrement, PreIncrement)
{
    Vec input {1,2,3};
    Vec expec {2,3,4};
    ++input;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_IncrementDecrement, PostIncrement)
{
    Vec input {1,2,3};
    Vec expec {2,3,4};
    input++;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* ####################################################################################### */
/* Decrement */
/* ####################################################################################### */

TEST(Vector_IncrementDecrement, PreDecrement)
{
    Vec input {1,2,3};
    Vec expec {0,1,2};
    --input;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_IncrementDecrement, PostDecrement)
{
    Vec input {1,2,3};
    Vec expec {0,1,2};
    input--;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}