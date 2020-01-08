

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrices/Matrix.hpp>


using namespace std;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;
using Mat44 = Matrix<4,4,int>;

/* ####################################################################################### */
/* Default iterators */
/* ####################################################################################### */

TEST(Matrix_Subiterators, Plus)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44,
    };

    auto rect = Mat44::SubRect {{1,1},{3,3}};
    auto exrows = Mat44::ExcludedSubRows {};
    auto excols = Mat44::ExcludedSubColumns {2};

    auto b = input.beginSub(rect, exrows, excols);
    auto e = input.endSub(rect, exrows, excols);
//
    std::cout << std::endl;
    std::cout << "END = " << e.subRow() << "  " << e.subColumn() << std::endl;
    for ( ; b != e; ++b)
    {
        std::cout << *b << std::endl;
    }
}
//
///* --------------------------------------------------------------------------------------- */
//
//TEST(Matrix_Subiterators, Minus)
//{
//    Matrix<3,3,int> input
//    {
//        1, 2, 3,
//        4, 5, 6,
//        7, 8, 9
//    };
//
//    auto it_02 = input.end() - 3;
//    auto it_12 = input.end() - 2;
//    auto it_22 = input.end() - 1;
//
//    ASSERT_EQ(*it_02, 3);
//    ASSERT_EQ(*it_12, 6);
//    ASSERT_EQ(*it_22, 9);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//TEST(Matrix_Subiterators, PreIncrement)
//{
//    Matrix<3,3,int> input
//    {
//        1, 2, 3,
//        4, 5, 6,
//        7, 8, 9
//    };
//
//    auto it = input.begin();
//
//    ASSERT_EQ(*it, 1);
//    ASSERT_EQ(*(++it), 4);
//    ASSERT_EQ(*(++it), 7);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//TEST(Matrix_Subiterators, PostIncrement)
//{
//    Matrix<3,3,int> input
//    {
//        1, 2, 3,
//        4, 5, 6,
//        7, 8, 9
//    };
//
//    auto it = input.begin();
//
//    ASSERT_EQ(*(it++), 1);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//TEST(Matrix_Subiterators, PreDecrement)
//{
//    Matrix<3,3,int> input
//    {
//        1, 2, 3,
//        4, 5, 6,
//        7, 8, 9
//    };
//
//    auto it = input.end();
//
//    ASSERT_EQ(*(--it), 9);
//    ASSERT_EQ(*(--it), 6);
//    ASSERT_EQ(*(--it), 3);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//TEST(Matrix_Subiterators, PostDecrement)
//{
//    Matrix<3,3,int> input
//    {
//        1, 2, 3,
//        4, 5, 6,
//        7, 8, 9
//    };
//
//    ASSERT_EQ((input.begin()), input.begin());
//}
//
///* --------------------------------------------------------------------------------------- */
//
//TEST(Matrix_Subiterators, RowsColumns_FirstComponent)
//{
//    Matrix<3,3,int> input
//    {
//        1, 2, 3,
//        4, 5, 6,
//        7, 8, 9
//    };
//    auto it {input.begin()};
//    ASSERT_EQ(it.row(), 0);
//    ASSERT_EQ(it.column(), 0);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//TEST(Matrix_Subiterators, RowsColumns_MidComponent)
//{
//    Matrix<3,3,int> input
//    {
//        1, 2, 3,
//        4, 5, 6,
//        7, 8, 9
//    };
//    auto it {input.begin() + 5};
//    ASSERT_EQ(it.row(), 2);
//    ASSERT_EQ(it.column(), 1);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//TEST(Matrix_Subiterators, RowsColumns_LastComponent)
//{
//    Matrix<3,3,int> input
//    {
//        1, 2, 3,
//        4, 5, 6,
//        7, 8, 9
//    };
//    auto it {input.begin() + Matrix<3,3,int>::size-1};
//    ASSERT_EQ(it.row(), 2);
//    ASSERT_EQ(it.column(), 2);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//TEST(Matrix_Subiterators, Difference)
//{
//    Matrix<3,3,int> input
//    {
//        1, 2, 3,
//        4, 5, 6,
//        7, 8, 9
//    };
//
//    auto a      {input.begin()};
//    auto b      {input.begin() + 3};
//    auto diff   {a - b};
//
//    ASSERT_EQ(diff, 3);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//TEST(Matrix_Subiterators, Reverse)
//{
//    Matrix<2,2,int> input
//    {
//        1, 2,
//        4, 5
//    };
//
//    auto it_11 = input.rbegin();
//    auto it_10 = input.rbegin() + 1;
//    auto it_01 = input.rbegin() + 2;
//    auto it_00 = input.rbegin() + 3;
//
//    ASSERT_EQ(*it_00, 1);
//    ASSERT_EQ(*it_01, 4);
//    ASSERT_EQ(*it_10, 2);
//    ASSERT_EQ(*it_11, 5);
//}