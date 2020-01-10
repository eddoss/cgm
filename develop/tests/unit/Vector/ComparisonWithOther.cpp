

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Vectors/Vector.hpp>


using namespace std;
using Vec = Vector<3>;

TEST(Vector_ComparisonWithOther, Equal_PositiveTest)
{
    Vec input {1,2,3};
    Vec other {1,2,3};

    ASSERT_TRUE(input == other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, Equal_NegativeTest)
{
    Vec input {1,2,3};
    Vec other {1,2,4};

    ASSERT_FALSE(input == other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, NotEqual_PositiveTest)
{
    Vec input {1,2,3};
    Vec other {1,2,4};

    ASSERT_TRUE(input != other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, NotEqual_NegativeTest)
{
    Vec input {1,2,3};
    Vec other {1,2,3};

    ASSERT_FALSE(input != other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, Less_PositiveTest)
{
    Vec input {1,2,3};
    Vec other {2,3,4};

    ASSERT_TRUE(input < other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, Less_NegativeTest)
{
    Vec input {1,2,3};
    Vec other {1,3,4};

    ASSERT_FALSE(other < input);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, LessThan_PositiveTest)
{
    Vec input {1,2,3};
    Vec other {1,2,4};

    ASSERT_TRUE(input <= other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, LessThan_NegativeTest)
{
    Vec input {1,2,3};
    Vec other {1,2,4};

    ASSERT_FALSE(other <= input);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, Greater_PositiveTest)
{
    Vec input {2,3,4};
    Vec other {1,2,3};

    ASSERT_TRUE(input > other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, Greater_NegativeTest)
{
    Vec input {2,3,4};
    Vec other {1,2,3};

    ASSERT_FALSE(other > input);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, GreaterOrEqual_PositiveTest)
{
    Vec input {2,3,4};
    Vec other {1,3,4};

    ASSERT_TRUE(input >= other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, GreaterOrEqual_NegativeTest)
{
    Vec input {2,3,4};
    Vec other {1,3,4};

    ASSERT_FALSE(other >= input);
}
