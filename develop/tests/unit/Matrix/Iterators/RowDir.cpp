

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrix/Matrix.hpp>


using namespace std;
using Mat22 = Matrix<2,2,int>;
using Mat23 = Matrix<2,3,int>;
using Mat24 = Matrix<2,4,int>;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;
using Mat42 = Matrix<4,2,int>;
using Mat43 = Matrix<4,3,int>;
using Mat44 = Matrix<4,4,int>;
using Mat55 = Matrix<5,5,int>;

/* ####################################################################################### */
/* Default iterators */
/* ####################################################################################### */

TEST(Matrix_RowDirIterator, Plus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.beginRowDir() + 1;
    auto it1 = input.beginRowDir() + 2;
    auto it2 = input.beginRowDir() + 3;

    ASSERT_EQ(*it0, 2);
    ASSERT_EQ(*it1, 3);
    ASSERT_EQ(*it2, 4);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Minus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.endRowDir() - 1;
    auto it1 = input.endRowDir() - 2;
    auto it2 = input.endRowDir() - 3;

    ASSERT_EQ(*it0, 9);
    ASSERT_EQ(*it1, 8);
    ASSERT_EQ(*it2, 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, PreIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginRowDir();

    ASSERT_EQ(*(++it), 2);
    ASSERT_EQ(*(++it), 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, PostIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginRowDir();
    it++;

    ASSERT_EQ(*(it++), 2);
    ASSERT_EQ(*(it++), 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, PreDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endRowDir();

    ASSERT_EQ(*(--it), 9);
    ASSERT_EQ(*(--it), 8);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, PostDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endRowDir();
    it--;

    ASSERT_EQ(*(it--), 9);
    ASSERT_EQ(*(it--), 8);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, RowsColumns_FirstComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.beginRowDir()};

    ASSERT_EQ(it.row(), 0);
    ASSERT_EQ(it.column(), 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, RowsColumns_MidComponent)
{
    Mat24 input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.beginRowDir() + 5};

    ASSERT_EQ(*it, 6);
    ASSERT_EQ(it.row(), 1);
    ASSERT_EQ(it.column(), 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, RowsColumns_LastComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.beginRowDir() + Mat33::size-1};

    ASSERT_EQ(it.row(), 2);
    ASSERT_EQ(it.column(), 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Difference)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto a {input.beginRowDir()};
    auto b {input.beginRowDir() + 3};

    ASSERT_EQ(a-b, -3);
    ASSERT_EQ(b-a, 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_Equal)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto same_a = input.beginRowDir();
    auto b = input.beginRowDir() + 1;

    ASSERT_TRUE(a == same_a);
    ASSERT_FALSE(a == b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_NotEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto same_a = input.beginRowDir();
    auto b = input.beginRowDir() + 1;

    ASSERT_TRUE(a != b);
    ASSERT_FALSE(a != same_a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_Less)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto b = input.beginRowDir() + 1;

    ASSERT_TRUE(a < b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_LessOrEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto b = input.beginRowDir();

    ASSERT_TRUE(a <= b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_Greater)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto b = input.beginRowDir() + 1;

    ASSERT_TRUE(b > a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Comparison_GreaterOrEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginRowDir();
    auto b = input.beginRowDir();

    ASSERT_TRUE(b >= a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Reverse)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbeginRowDir();
    auto b = input.rbeginRowDir() + 1;
    auto c = input.rbeginRowDir() + 2;
    auto d = input.rbeginRowDir() + 3;

    ASSERT_EQ(*a, 5);
    ASSERT_EQ(*b, 4);
    ASSERT_EQ(*c, 2);
    ASSERT_EQ(*d, 1);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_RowDirIterator, Exception_Dereference)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir();
        auto val = *it;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't dereference out of range matrix iterator.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_PreIncrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = ++input.endRowDir();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_PostIncrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir()++;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_PlusEqual)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir();
        it += 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_Plus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir();
        it = it + 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_PreDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = --input.beginRowDir();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_PostDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRowDir()--;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_MinusEqual)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRowDir();
        it -= 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_Minus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRowDir();
        it = it - 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_Row)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir();
        auto val = it.row();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't get row from matrix iterator (out of range).");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowDirIterator, Exception_Column)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRowDir();
        auto val = it.column();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't get column from matrix iterator (out of range).");
    }
}

#endif