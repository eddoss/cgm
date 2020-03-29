

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrix/Matrix.hpp>


using namespace MATH3D_NAMESPACE;

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

TEST(Matrix_ColumnDirIterator, Plus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.beginColumnDir() + 1;
    auto it1 = input.beginColumnDir() + 2;
    auto it2 = input.beginColumnDir() + 3;

    ASSERT_TRUE(*it0 == 4);
    ASSERT_TRUE(*it1 == 7);
    ASSERT_TRUE(*it2 == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Minus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.endColumnDir() - 1;
    auto it1 = input.endColumnDir() - 2;
    auto it2 = input.endColumnDir() - 3;

    ASSERT_TRUE(*it0 == 9);
    ASSERT_TRUE(*it1 == 6);
    ASSERT_TRUE(*it2 == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, PreIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginColumnDir();

    ASSERT_TRUE(*(++it) == 4);
    ASSERT_TRUE(*(++it) == 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, PostIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginColumnDir();
    it++;

    ASSERT_TRUE(*(it++) == 4);
    ASSERT_TRUE(*(it++) == 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, PreDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endColumnDir();

    ASSERT_TRUE(*(--it) == 9);
    ASSERT_TRUE(*(--it) == 6);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, PostDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endColumnDir();
    it--;

    ASSERT_TRUE(*(it--) == 9);
    ASSERT_TRUE(*(it--) == 6);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, RowsColumns_FirstComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.beginColumnDir()};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, RowsColumns_MidComponent)
{
    Mat24 input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.beginColumnDir() + 5};

    ASSERT_TRUE(*it == 7);
    ASSERT_TRUE(it.row() == 1);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, RowsColumns_LastComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.beginColumnDir() + Mat33::size-1};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Difference)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto a {input.beginColumnDir()};
    auto b {input.beginColumnDir() + 3};

    ASSERT_TRUE(b-a == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_Equal)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto same_a = input.beginColumnDir();
    auto b = input.beginColumnDir() + 1;

    ASSERT_TRUE(a == same_a);
    ASSERT_FALSE(a == b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_NotEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto same_a = input.beginColumnDir();
    auto b = input.beginColumnDir() + 1;

    ASSERT_TRUE(a != b);
    ASSERT_FALSE(a != same_a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_Less)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto b = input.beginColumnDir() + 1;

    ASSERT_TRUE(a < b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_LessOrEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto b = input.beginColumnDir();

    ASSERT_TRUE(a <= b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_Greater)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto b = input.beginColumnDir() + 1;

    ASSERT_TRUE(b > a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Comparison_GreaterOrEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginColumnDir();
    auto b = input.beginColumnDir();

    ASSERT_TRUE(b >= a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Reverse)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbeginColumnDir();
    auto b = input.rbeginColumnDir() + 1;
    auto c = input.rbeginColumnDir() + 2;
    auto d = input.rbeginColumnDir() + 3;

    ASSERT_TRUE(*a == 5);
    ASSERT_TRUE(*b == 2);
    ASSERT_TRUE(*c == 4);
    ASSERT_TRUE(*d == 1);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_ColumnDirIterator, Exception_Dereference)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir();
        auto val = *it;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't dereference out of range matrix iterator.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_PreIncrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = ++input.endColumnDir();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_PostIncrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir()++;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_PlusEqual)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir();
        it += 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_Plus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir();
        it = it + 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_PreDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = --input.beginColumnDir();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_PostDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumnDir()--;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_MinusEqual)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumnDir();
        it -= 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_Minus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumnDir();
        it = it - 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_Row)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir();
        auto val = it.row();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't get row from matrix iterator (out of range).");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnDirIterator, Exception_Column)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumnDir();
        auto val = it.column();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't get column from matrix iterator (out of range).");
    }
}

#endif