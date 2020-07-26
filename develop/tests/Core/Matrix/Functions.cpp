

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>


using namespace MATH3D_NAMESPACE;
using namespace std;

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
using Mat54 = Matrix<5,4,int>;
using Mat55 = Matrix<5,5,int>;


template <typename T>
struct Bas
{
    Matrix<4,4,T> f;
    Vector<3,T> position() { return {*this(0,3), *this(1,3), *this(2,3),};}
};

TEST(Matrix_Functions, Transpose)
{
//    Matrix<4,4,double> space
//    {
//        +0.996772, +0.069409, -0.040354, +4.000000,
//        -0.040354, +0.867639, +0.495554, +7.000000,
//        +0.069409, -0.492325, +0.867639, +2.000000,
//        +0.000000, +0.000000, +0.000000, +1.000000
//    };
//
//    Matrix<3,3,double> orientation
//    {
//        +0.996772, +0.069409, -0.040354,
//        -0.040354, +0.867639, +0.495554,
//        +0.069409, -0.492325, +0.867639
//    };
//
//    auto s = sizeof(Bas<float>);
//
//    auto is = inverseForce(space);
//    auto ts = transposed(space);
//    auto io = inverseForce(orientation);
//    auto to = transposed(orientation);
//    std::cout << is << std::endl;
//    std::cout << ts << std::endl;
//    std::cout << io << std::endl;
//    std::cout << to << std::endl;

    {
        Mat22 a
        {
            1, 2,
            3, 4
        };
        Mat22 b
        {
            1, 3,
            2, 4
        };

        transpose(a);

        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        Mat33 a
        {
            1, 2, 3,
            4, 3, 2,
            6, 7, 3
        };
        Mat33 b
        {
            1, 4, 6,
            2, 3, 7,
            3, 2, 3
        };

        transpose(a);

        ASSERT_TRUE(a == b);
    }

    /* -------------- */

    {
        Mat44 a
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 4
        };
        Mat44 b
        {
            1, 3, 3, 1,
            2, 2, 4, 2,
            3, 1, 3, 3,
            4, 2, 2, 4
        };

        transpose(a);

        ASSERT_TRUE(a == b);
    }

   /* -------------- */

    {
        Mat55 a
        {
            1, 2, 2, 3, 4,
            1, 3, 2, 3, 4,
            2, 0, 1, 7, 4,
            3, 2, 2, 9, 4,
            1, 3, 3, 0, 1
        };
        Mat55 b
        {
            1, 1, 2, 3, 1,
            2, 3, 0, 2, 3,
            2, 2, 1, 2, 3,
            3, 3, 7, 9, 0,
            4, 4, 4, 4, 1
        };

        transpose(a);

        ASSERT_TRUE(a == b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Transposed)
{
    {
        Mat12 a
        {
            1, 2
        };
        Mat21 b
        {
            1,
            2
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        Mat13 a
        {
            1, 2, 3
        };
        Mat31 b
        {
            1,
            2,
            3
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        Mat14 a
        {
            1, 2, 3, 4
        };
        Mat41 b
        {
            1,
            2,
            3,
            4
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        Mat21 a
        {
            1,
            2
        };
        Mat12 b
        {
            1,2
        };

        ASSERT_TRUE(transposed(a) == b);
    }

        /* -------------- */

    {
        Mat31 a
        {
            1,
            2,
            3
        };
        Mat13 b
        {
            1, 2, 3
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        Mat41 a
        {
            1,
            2,
            3,
            4
        };
        Mat14 b
        {
            1,2,3,4
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        Mat23 a
        {
            3, 5, 1,
            8, 4, 7
        };
        Mat32 b
        {
            3, 8,
            5, 4,
            1, 7
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        Mat24 a
        {
            1, 2, 3, 5,
            4, 3, 2, 8
        };
        Mat42 b
        {
            1, 4,
            2, 3,
            3, 2,
            5, 8
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        Mat32 a
        {
            1, 2,
            3, 4,
            3, 2
        };
        Mat23 b
        {
            1, 3, 3,
            2, 4, 2
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        Mat34 a
        {
            1, 2, 5, 4,
            4, 8, 2, 1,
            2, 9, 2, 5
        };
        Mat43 b
        {
            1, 4, 2,
            2, 8, 9,
            5, 2, 2,
            4, 1, 5
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        Mat42 a
        {
            1, 2,
            5, 4,
            4, 8,
            2, 1
        };
        Mat24 b
        {
            1, 5, 4, 2,
            2, 4, 8, 1
        };

        ASSERT_TRUE(transposed(a) == b);
    }

    /* -------------- */

    {
        Mat43 a
        {
            1, 2, 2,
            3, 4, 3,
            3, 2, 1,
            7, 2, 8
        };
        Mat34 b
        {
            1, 3, 3, 7,
            2, 4, 2, 2,
            2, 3, 1, 8
        };

        ASSERT_TRUE(transposed(a) == b);
    }


    /* -------------- */

    {
        Mat45 a
        {
            1,2,2,7,8,
            3,4,3,4,9,
            3,2,1,3,1,
            7,2,8,7,8
        };
        Mat54 b
        {
            1,3,3,7,
            2,4,2,2,
            2,3,1,8,
            7,4,3,7,
            8,9,1,8
        };

        ASSERT_TRUE(transposed(a) == b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Determinant)
{
    {
        Mat22 a
        {
            1, 2,
            3, 4
        };

        ASSERT_TRUE(determinant(a) == -2);
    }

    /* -------------- */

    {
        Mat33 a
        {
            1, 2, 3,
            4, 3, 2,
            6, 7, 3
        };

        ASSERT_TRUE(determinant(a) == 25);
    }

    /* -------------- */

    {
        Mat44 a
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 4
        };

        ASSERT_TRUE(determinant(a) == 0);
    }

//   /* -------------- */
//
//    {
//        Mat55 a
//        {
//            1, 2, 2, 3, 4,
//            1, 3, 2, 3, 4,
//            2, 0, 1, 7, 4,
//            3, 2, 2, 9, 4,
//            1, 3, 3, 0, 1
//        };
//
//        ASSERT_TRUE(determinant(a), 4);
//    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Cofactors)
{
    {
        Mat22 a
        {
            1, 2,
            3, 4
        };
        Mat22 b
        {
            4, -3,
            -2, 1
        };

        ASSERT_TRUE(cofactors(a) == b);
    }

    /* -------------- */

    {
        Mat33 a
        {
            1, 2, 3,
            4, 3, 2,
            6, 7, 3
        };
        Mat33 b
        {
            -5, 0, 10,
            15, -15, 5,
            -5, 10, -5
        };

        ASSERT_TRUE(cofactors(a) == b);
    }

    /* -------------- */

    {
        Mat44 a
        {
            2,8,1,7,
            5,3,5,9,
            0,2,1,6,
            4,8,3,2
        };
        Mat44 b
        {
            154,-4,-220,38,
            98,-36,-48,20,
            -287,43,272,-6,
            -119,47,170,-44
        };

        ASSERT_TRUE(cofactors(a) == b);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Inverse)
{
    {
        Matrix<2,2,double> mat
        {
            1, 2,
            3, 4
        };

        Matrix<2,2,double> inv
        {
            -2, 1,
            1.5, -0.5
        };

        {
            auto res = mat;
            bool suc = invert(res);
            ASSERT_TRUE(equal(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            bool suc = false;
            res = inverse(res, suc);
            ASSERT_TRUE(equal(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            invertForce(res);
            ASSERT_TRUE(equal(res, inv, 0.001));
        }

        {
            auto res = mat;
            res = inverseForce(res);
            ASSERT_TRUE(equal(res, inv, 0.001));
        }
    }

    /* -------------- */

    {
        Matrix<3,3,double> mat
        {
            1, 2, 3,
            4, 3, 2,
            6, 7, 3
        };

        Matrix<3,3,double> inv
        {
            -0.2, 0.6, -0.2,
            0, -0.6, 0.4,
            0.4, 0.2, -0.2
        };

        {
            auto res = mat;
            bool suc = invert(res);
            ASSERT_TRUE(equal(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            bool suc = false;
            res = inverse(res, suc);
            ASSERT_TRUE(equal(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            invertForce(res);
            ASSERT_TRUE(equal(res, inv, 0.001));
        }

        {
            auto res = mat;
            res = inverseForce(res);
            ASSERT_TRUE(equal(res, inv, 0.001));
        }
    }

    /* -------------- */

    {
        Matrix<4,4,double> mat
        {
            1, 2, 3, 4,
            3, 2, 1, 2,
            3, 4, 3, 2,
            1, 2, 3, 2
        };
        Matrix<4,4,double> inv
        {
            -0.5, 0.75, -0.5, 0.75,
            0.5, -0.75, 1.0, -1.25,
            -0.5, 0.25, -0.5, 1.25,
            0.5, 0.0, 0.0f, -0.5
        };

        {
            auto res = mat;
            bool suc = invert(res);
            ASSERT_TRUE(equal(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            bool suc = false;
            res = inverse(res, suc);
            ASSERT_TRUE(equal(res, inv, 0.001) && suc);
        }

        {
            auto res = mat;
            invertForce(res);
            ASSERT_TRUE(equal(res, inv, 0.001));
        }

        {
            auto res = mat;
            res = inverseForce(res);
            ASSERT_TRUE(equal(res, inv, 0.001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Trace)
{
    {
        Mat22 mat
        {
            2, 0,
            0, 3
        };

        ASSERT_TRUE(trace(mat) == 5);
    }

    /* -------------- */

    {
        Mat33 mat
        {
            2, 0, 0,
            0, 3, 0,
            0, 0, 1
        };

        ASSERT_TRUE(trace(mat) == 6);
    }

    /* -------------- */

    {
        Mat44 mat
        {
            1, 0, 0, 0,
            0, 2, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 4
        };

        ASSERT_TRUE(trace(mat) == 8);
    }

    /* -------------- */

    {
        Mat55 mat
        {
            1, 0, 0, 0, 0,
            0, 2, 0, 0, 0,
            0, 0, 4, 0, 0,
            0, 0, 0, 5, 0,
            0, 0, 0, 0, 1
        };

        ASSERT_TRUE(trace(mat) == 13);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Symmetric)
{
    {
        Mat22 mat
        {
            1, 2,
            2, 1
        };

        ASSERT_TRUE(symmetric(mat));

        mat =
        {
            1,2,
            3,4
        };

        ASSERT_FALSE(symmetric(mat));
    }

    /* -------------- */

    {
        Mat33 mat
        {
            1, 2, 3,
            2, 1, 0,
            3, 0, 3
        };

        ASSERT_TRUE(symmetric(mat));

        mat =
        {
            1, 2, 3,
            2, 1, 2,
            3, 5, 3
        };

        ASSERT_FALSE(symmetric(mat));
    }

    /* -------------- */

    {
        Mat44 mat
        {
            1, 2, 3, 4,
            2, 1, 0, 2,
            3, 0, 3, 2,
            4, 2, 2, 3
        };

        ASSERT_TRUE(symmetric(mat));

        mat =
        {
            1, 2, 3, 4,
            4, 1, 0, 2,
            3, 0, 3, 2,
            4, 2, 2, 3
        };

        ASSERT_FALSE(symmetric(mat));
    }

    /* -------------- */

    {
        Mat55 mat
        {
            1, 2, 3, 4, 2,
            2, 1, 0, 2, 3,
            3, 0, 3, 2, 5,
            4, 2, 2, 3, 2,
            2, 3, 5, 2, 2
        };

        ASSERT_TRUE(symmetric(mat));

        mat =
        {
            1, 2, 3, 4, 2,
            2, 1, 0, 2, 3,
            3, 4, 3, 2, 5,
            4, 2, 2, 3, 2,
            2, 3, 5, 2, 2
        };

        ASSERT_FALSE(symmetric(mat));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Antisymmetric)
{
    Mat33 mat
    {
        0, -2, 4,
        2, 0, -3,
        -4, 3, 0
    };

    ASSERT_TRUE(antisymmetric(mat));

    mat =
    {
        1, 2, 3,
        2, 1, 0,
        3, 0, 4
    };

    ASSERT_FALSE(antisymmetric(mat));
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Diagonal)
{
    {
        Mat22 mat
        {
            3, 0,
            0, 2
        };

        ASSERT_TRUE(diagonal(mat));
        ASSERT_FALSE(diagonal(Mat22(2)));
    }

    /* -------------- */

    {
        Mat33 mat
        {
            2, 0, 0,
            0, 2, 0,
            0, 0, 4
        };

        ASSERT_TRUE(diagonal(mat));
        ASSERT_FALSE(diagonal(Mat33(2)));
    }

    /* -------------- */

    {
        Mat44 mat
        {
            2, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 2, 0,
            0, 0, 0, 1
        };

        ASSERT_TRUE(diagonal(mat));
        ASSERT_FALSE(diagonal(Mat44(2)));
    }

    /* -------------- */

    {
        Mat55 mat
        {
            4, 0, 0, 0, 0,
            0, 5, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 1, 0,
            0, 0, 0, 0, 1
        };

        ASSERT_TRUE(diagonal(mat));
        ASSERT_FALSE(diagonal(Mat55(2)));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Orthogonal)
{
    {
        Matrix<2,2,double> mat
        {
            0.958072, -0.286529,
            0.286529, 0.958072
        };

        ASSERT_TRUE(orthogonal(mat, 0.0001));
        ASSERT_FALSE(orthogonal(Matrix<2,2,double>(2.0), 0.0001));
    }

    /* -------------- */

    {
        Matrix<3,3,double> mat
        {
            0.589794, -0.57689, 0.565102,
            0.180624, 0.776281, 0.603956,
            -0.787094, -0.254139, 0.562046
        };

        ASSERT_TRUE(orthogonal(mat, 0.0001));
        ASSERT_FALSE(orthogonal(Matrix<2,2,double>(2.0), 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Functions, Identity)
{
    {
        Mat22 ident
        {
            1, 0,
            0, 1
        };

        auto exp = identity<2,int>();

        ASSERT_TRUE(exp == ident);
    }

    /* -------------- */

    {
        Mat33 ident
        {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };

        auto exp = identity<3,int>();

        ASSERT_TRUE(exp == ident);
    }

    /* -------------- */

    {
        Mat44 ident
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        auto exp = identity<4,int>();

        ASSERT_TRUE(exp == ident);
    }

    /* -------------- */

    {
        Mat55 ident
        {
            1, 0, 0, 0, 0,
            0, 1, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 1, 0,
            0, 0, 0, 0, 1
        };

        auto exp = identity<5,int>();

        ASSERT_TRUE(exp == ident);
    }
}
