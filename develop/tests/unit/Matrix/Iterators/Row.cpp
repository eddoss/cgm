

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

TEST(Matrix_RowIterator, Plus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it_02 = input.beginRow(0) + 2;
    auto it_12 = input.beginRow(1) + 2;
    auto it_22 = input.beginRow(2) + 2;

    ASSERT_EQ(*it_02, 3);
    ASSERT_EQ(*it_12, 6);
    ASSERT_EQ(*it_22, 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Minus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    auto it_01 = input.endRow(0) - 1;
    auto it_10 = input.endRow(1) - 2;
    auto it_20 = input.endRow(2) - 2;

    ASSERT_EQ(*it_01, 2);
    ASSERT_EQ(*it_10, 4);
    ASSERT_EQ(*it_20, 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, PreIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginRow(1);

    ASSERT_EQ(*it, 4);
    ASSERT_EQ(*(++it), 5);
    ASSERT_EQ(*(++it), 6);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, PostIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginRow(0);

    ASSERT_EQ(*(it++), 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, PreDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    auto it = input.endRow(2);

    ASSERT_EQ(*(--it), 8);
    ASSERT_EQ(*(--it), 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, PostDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    ASSERT_EQ((input.endRow(1))--, input.endRow(1));
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Difference)
{
    Mat34 input
    {
        1, 2, 3, 6,
        4, 5, 6, 8,
        7, 8, 9, 5
    };

    auto a = input.beginRow(0) + 0;     // (0,0)
    auto b = input.beginRow(0) + 2;     // (0,2)
    ASSERT_EQ(a - b, -2);
    ASSERT_EQ(b - a, 2);

    a = input.beginRow(0) + 0;          // (0,0)
    b = input.beginRow(1) + 3;          // (1,3)
    ASSERT_EQ(a - b, -3);
    ASSERT_EQ(b - a, 3);

    a = input.beginRow(0) + 1;          // (0,1)
    b = input.beginRow(2) + 3;          // (2,3)
    ASSERT_EQ(a - b, -2);
    ASSERT_EQ(b - a, 2);
}


/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Reverse)
{
    Mat34 input
    {
        1, 2, 3, 6,
        4, 5, 6, 8,
        7, 8, 9, 5
    };

    auto it_00 = input.rbeginRow(1) + 3;
    auto it_01 = input.rbeginRow(1) + 2;
    auto it_02 = input.rbeginRow(1) + 1;
    auto it_03 = input.rbeginRow(1);

    ASSERT_EQ(*it_00, 4);
    ASSERT_EQ(*it_01, 5);
    ASSERT_EQ(*it_02, 6);
    ASSERT_EQ(*it_03, 8);
}


/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Reverse_Differece)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbeginRow(1);
    auto b = input.rbeginRow(1) + 1;

    ASSERT_EQ(a - b, -1);
    ASSERT_EQ(b - a, 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Reverse_RowsColumns_FirstComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbeginRow(2) + 2};

    ASSERT_EQ(it.row(), 2);
    ASSERT_EQ(it.column(), 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Reverse_RowsColumns_MidComponent)
{
    Mat24 input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.rbeginRow(1) + 2};

    ASSERT_EQ(it.row(), 1);
    ASSERT_EQ(it.column(), 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Reverse_RowsColumns_LastComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbeginRow(2)};

    ASSERT_EQ(it.row(), 2);
    ASSERT_EQ(it.column(), 2);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_RowIterator, Exception_Dereference)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1);
        auto val = *it;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't dereference out of range matrix iterator.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_PreIncrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = ++input.endRow(1);
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_PostIncrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1)++;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_PlusEqual)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1);
        it += 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_Plus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1);
        it = it + 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_PreDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = --input.beginRow(1);
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_PostDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRow(1)--;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_MinusEqual)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRow(1);
        it -= 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_Minus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginRow(1);
        it = it - 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_Row)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1);
        auto val = it.row();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't get row from matrix iterator (out of range).");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowIterator, Exception_Column)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endRow(1);
        auto val = it.column();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't get column from matrix iterator (out of range).");
    }
}

#endif