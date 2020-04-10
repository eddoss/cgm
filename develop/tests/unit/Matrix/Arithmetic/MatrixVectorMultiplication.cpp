

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Matrix/Operators.hpp>


using namespace MATH3D_NAMESPACE;
using namespace std;

using Vec2 = Vector<2,int>;
using Vec3 = Vector<3,int>;
using Vec4 = Vector<4,int>;
using Vec5 = Vector<5,int>;

using Mat12 = Matrix<1,2,int>;
using Mat13 = Matrix<1,3,int>;
using Mat14 = Matrix<1,4,int>;
using Mat15 = Matrix<1,5,int>;
using Mat21 = Matrix<2,1,int>;
using Mat22 = Matrix<2,2,int>;
using Mat23 = Matrix<2,3,int>;
using Mat24 = Matrix<2,4,int>;
using Mat25 = Matrix<2,5,int>;
using Mat31 = Matrix<3,1,int>;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;
using Mat35 = Matrix<3,5,int>;
using Mat41 = Matrix<4,1,int>;
using Mat42 = Matrix<4,2,int>;
using Mat43 = Matrix<4,3,int>;
using Mat44 = Matrix<4,4,int>;
using Mat45 = Matrix<4,5,int>;
using Mat51 = Matrix<5,1,int>;
using Mat55 = Matrix<5,5,int>;

/* ####################################################################################### */
/* Vector to matrix: 2D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec2__x__Mat21)
{
    Vec2 v = {2, 5};

    Mat21 m
    {
        3,
        4
    };

    ASSERT_TRUE((v*m) == 26);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__x__Mat22)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__x__Mat23)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__x__Mat24)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__x__Mat25)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__x__Mat21)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__x__Mat22)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__x__Mat23)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__x__Mat24)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec2__x__Mat25)
{

}

/* ####################################################################################### */
/* Vector to matrix: 3D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec3__x__Mat31)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__x__Mat32)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__x__Mat33)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__x__Mat34)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__x__Mat35)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__x__Mat31)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__x__Mat32)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__x__Mat33)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__x__Mat34)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec3__x__Mat35)
{

}

/* ####################################################################################### */
/* Vector to matrix: 4D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec4__x__Mat41)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__x__Mat42)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__x__Mat43)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__x__Mat44)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__x__Mat45)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__x__Mat41)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__x__Mat42)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__x__Mat43)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__x__Mat44)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec4__x__Mat45)
{

}

/* ####################################################################################### */
/* Vector to matrix: 4+D vector */
/* ####################################################################################### */

TEST(Matrix_MatrixVectorMultiplication, Vec5__x__Mat51)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__x__Mat52)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__x__Mat53)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__x__Mat54)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__x__Mat55)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__x__Mat51)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__x__Mat52)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__x__Mat53)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__x__Mat54)
{

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixVectorMultiplication, Vec5__x__Mat55)
{

}