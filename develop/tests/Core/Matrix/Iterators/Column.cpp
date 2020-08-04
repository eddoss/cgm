

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Matrix.hpp>


using namespace CGM;

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

TEST(Matrix_ColumnIterator, Plus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Mat33::size_type column = 2;
    auto it_02 = input.beginColumn(column);
    auto it_12 = input.beginColumn(column) + 1;
    auto it_22 = input.beginColumn(column) + 2;

    ASSERT_TRUE(*it_02 == 3);
    ASSERT_TRUE(*it_12 == 6);
    ASSERT_TRUE(*it_22 == 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Minus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;
    auto it_22 = input.endColumn(column) - 1;
    auto it_12 = input.endColumn(column) - 2;
    auto it_02 = input.endColumn(column) - 3;

    ASSERT_TRUE(*it_02 == 3);
    ASSERT_TRUE(*it_12 == 6);
    ASSERT_TRUE(*it_22 == 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PreIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;
    auto it_02 = input.beginColumn(column);

    ASSERT_TRUE(*it_02 == 3);
    ASSERT_TRUE(*(++it_02) == 6);
    ASSERT_TRUE(*(++it_02) == 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PostIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;
    auto it_02 = input.beginColumn(column);

    ASSERT_TRUE(*(it_02++) == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PreDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Mat33::size_type column = 2;
    auto it_22 = input.endColumn(column);

    ASSERT_TRUE(*(--it_22) == 9);
    ASSERT_TRUE(*(--it_22) == 6);
    ASSERT_TRUE(*(--it_22) == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PostDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    ASSERT_TRUE((input.endColumn(1))-- == input.endColumn(1));
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Difference)
{
    Mat34 input
    {
        1, 2, 3, 6,
        4, 5, 6, 8,
        7, 8, 9, 5
    };

    auto a = input.beginColumn(0) + 0;     // (0,0)
    auto b = input.beginColumn(0) + 2;     // (2,0)
    ASSERT_TRUE(a - b == -2);
    ASSERT_TRUE(b - a == 2);

    a = input.beginColumn(0) + 0;          // (0,0)
    b = input.beginColumn(1) + 2;          // (2,1)
    ASSERT_TRUE(a - b == -2);
    ASSERT_TRUE(b - a == 2);

    a = input.beginColumn(0) + 1;          // (1,0)
    b = input.beginColumn(2) + 2;          // (2,2)
    ASSERT_TRUE(a - b == -1);
    ASSERT_TRUE(b - a == 1);
}



/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Reverse)
{
    Mat34 input
    {
        1, 2, 3, 6,
        4, 5, 6, 8,
        7, 8, 9, 5
    };

    auto a = input.rbeginColumn(1) + 0;
    auto b = input.rbeginColumn(1) + 1;
    auto c = input.rbeginColumn(1) + 2;

    ASSERT_TRUE(*a == 8);
    ASSERT_TRUE(*b == 5);
    ASSERT_TRUE(*c == 2);
}


/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Reverse_Differece)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbeginColumn(1);
    auto b = input.rbeginColumn(1) + 1;

    ASSERT_TRUE(a - b == -1);
    ASSERT_TRUE(b - a == 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Reverse_RowsColumns_FirstComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbeginColumn(0) + 2};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Reverse_RowsColumns_MidComponent)
{
    Mat24 input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.rbeginColumn(2) + 1};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Reverse_RowsColumns_LastComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbeginColumn(2)};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_ColumnIterator, Exception_Dereference)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1);
        auto val = *it;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't dereference out of range matrix iterator.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_PreIncrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = ++input.endColumn(1);
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_PostIncrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1)++;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_PlusEqual)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1);
        it += 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_Plus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1);
        it = it + 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_PreDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = --input.beginColumn(1);
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_PostDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumn(1)--;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_MinusEqual)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumn(1);
        it -= 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_Minus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginColumn(1);
        it = it - 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_Row)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1);
        auto val = it.row();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get row from matrix iterator (out of range).");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Exception_Column)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endColumn(1);
        auto val = it.column();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get column from matrix iterator (out of range).");
    }
}

#endif