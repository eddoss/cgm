

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Vectors/Vector.hpp>


using namespace std;
using Vec = Vector<3>;

TEST(Vector_ComparisonWithScalar, Equal_PositiveTest)
{
    Vec::value_type scalar {2};
    Vec input {scalar, scalar, scalar};
    ASSERT_TRUE(input == scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, Equal_NegativeTest)
{
    Vec::value_type scalar {2};
    Vec input {scalar, scalar, 1};

    ASSERT_FALSE(input == scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, NotEqual_PositiveTest)
{
    Vec::value_type scalar {2};
    Vec input {scalar, scalar, 1};

    ASSERT_TRUE(input != scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, NotEqual_NegativeTest)
{
    Vec::value_type scalar {2};
    Vec input {scalar, scalar, scalar};

    ASSERT_FALSE(input != scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, Less_PositiveTest)
{
    Vec::value_type scalar {2};
    Vec input {1, 1, 1};

    ASSERT_TRUE(input < scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, Less_NegativeTest)
{
    Vec::value_type scalar {2};
    Vec input {scalar+1, scalar+1, scalar+1};

    ASSERT_FALSE(input < scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, LessThan_PositiveTest)
{
    Vec::value_type scalar {2};
    Vec input {scalar, scalar, scalar};

    ASSERT_TRUE(input <= scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, LessThan_NegativeTest)
{
    Vec::value_type scalar {2};
    Vec input {scalar, scalar, scalar + 1};

    ASSERT_FALSE(input <= scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, Greater_PositiveTest)
{
    Vec::value_type scalar {2};
    Vec input {scalar+1, scalar+1, scalar+1};

    ASSERT_TRUE(input > scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, Greater_NegativeTest)
{
    Vec::value_type scalar {2};
    Vec input {scalar-1, scalar-1, scalar-1};

    ASSERT_FALSE(input > scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, GreaterOrEqual_PositiveTest)
{
    Vec::value_type scalar {2};
    Vec input {scalar, scalar, scalar+1};

    ASSERT_TRUE(input >= scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, GreaterOrEqual_NegativeTest)
{
    Vec::value_type scalar {2};
    Vec input {scalar, scalar, scalar-1};

    ASSERT_FALSE(input >= scalar);
}
