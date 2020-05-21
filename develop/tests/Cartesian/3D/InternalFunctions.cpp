

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Core/Operators/Quaternion.hpp>
#include <private/Math3D/Cartesian/3D/InternalUtils.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

TEST(Cartesian_3D_InternalFunctions, get_basis_x)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.965926, 0.149429, 0.149429, 0.149429};

    auto value3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(quat);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec3 {2,4,5};
    Vector<3,double> expec4 {2,4,5};
#else
    Vector<3,double> expec3 {2,3,0};
    Vector<3,double> expec4 {2,3,0};
#endif
    Vector<3,double> expecQ {0.910683, 0.333334, -0.244017};

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, get_basis_y)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.965926, 0.149429, 0.149429, 0.149429};

    auto value3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(quat);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec3 {3,6,7};
    Vector<3,double> expec4 {3,6,7};
#else
    Vector<3,double> expec3 {4,6,9};
    Vector<3,double> expec4 {4,6,9};
#endif
    Vector<3,double> expecQ {-0.244017, 0.910683, 0.333334};

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, get_basis_z)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.965926, 0.149429, 0.149429, 0.149429};

    auto value3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(quat);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec3 {0,9,8};
    Vector<3,double> expec4 {0,9,8};
#else
    Vector<3,double> expec3 {5,7,8};
    Vector<3,double> expec4 {5,7,8};
#endif
    Vector<3,double> expecQ {0.333334, -0.244017, 0.910683};

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, set_basis_axes_x_y_z)
{
    Vector<3,int> x {2,4,5};
    Vector<3,int> y {3,6,7};
    Vector<3,int> z {0,9,8};

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<3,3,int> expec3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,int> expec4
    {
        2, 4, 5, 0,
        3, 6, 7, 0,
        0, 9, 8, 0,
        0, 0, 0, 0
    };
#else
    Matrix<3,3,int> expec3
    {
        2, 3, 0,
        4, 6, 9,
        5, 7, 8
    };

    Matrix<4,4,int> expec4
    {
        2, 3, 0, 0,
        4, 6, 9, 0,
        5, 7, 8, 0,
        0, 0, 0, 0
    };
#endif

    Matrix<3,3,int> mat3(0);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_x(mat3, x);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_y(mat3, y);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_z(mat3, z);

    Matrix<4,4,int> mat4(0);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_x(mat4, x);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_y(mat4, y);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_z(mat4, z);

    ASSERT_TRUE(mat3 == expec3);
    ASSERT_TRUE(mat4 == expec4);
}

/* ####################################################################################### */
/* Up, Right, Forward axes */
/* ####################################################################################### */

TEST(Cartesian_3D_InternalFunctions, get_basis_up)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.965926, 0.149429, 0.149429, 0.149429};

    auto value3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_up(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_up(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_up(quat);

#ifdef MATH3D_CARTESIAN_UP_X
    auto expec3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(quat);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    auto expec3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(quat);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    auto expec3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, get_basis_right)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.965926, 0.149429, 0.149429, 0.149429};

    auto value3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_right(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_right(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_right(quat);

#ifdef MATH3D_CARTESIAN_RIGHT_X
    auto expec3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(quat);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    auto expec3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(quat);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    auto expec3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, get_basis_forward)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.965926, 0.149429, 0.149429, 0.149429};

    auto value3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_forward(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_forward(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_forward(quat);

#ifdef MATH3D_CARTESIAN_FORWARD_X
    auto expec3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(quat);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    auto expec3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(quat);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    auto expec3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(mat3);
    auto expec4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(mat4);
    auto expecQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(quat);
#endif

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, get_basis_down)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.965926, 0.149429, 0.149429, 0.149429};

    auto value3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_down(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_down(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_down(quat);

    auto expec3 = -MATH3D_XYZ_NAMESPACE::_internal_get_basis_up(mat3);
    auto expec4 = -MATH3D_XYZ_NAMESPACE::_internal_get_basis_up(mat4);
    auto expecQ = -MATH3D_XYZ_NAMESPACE::_internal_get_basis_up(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, get_basis_left)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.965926, 0.149429, 0.149429, 0.149429};

    auto value3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_left(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_left(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_left(quat);

    auto expec3 = -MATH3D_XYZ_NAMESPACE::_internal_get_basis_right(mat3);
    auto expec4 = -MATH3D_XYZ_NAMESPACE::_internal_get_basis_right(mat4);
    auto expecQ = -MATH3D_XYZ_NAMESPACE::_internal_get_basis_right(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, get_basis_backward)
{
    Matrix<3,3,double> mat3
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    Matrix<4,4,double> mat4
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.965926, 0.149429, 0.149429, 0.149429};

    auto value3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_backward(mat3);
    auto value4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_backward(mat4);
    auto valueQ = MATH3D_XYZ_NAMESPACE::_internal_get_basis_backward(quat);

    auto expec3 = -MATH3D_XYZ_NAMESPACE::_internal_get_basis_forward(mat3);
    auto expec4 = -MATH3D_XYZ_NAMESPACE::_internal_get_basis_forward(mat4);
    auto expecQ = -MATH3D_XYZ_NAMESPACE::_internal_get_basis_forward(quat);

    ASSERT_TRUE(value3 == expec3);
    ASSERT_TRUE(value4 == expec4);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(valueQ, expecQ, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, set_basis_axes_up_right_forward)
{
    Vector<3,int> u {4,6,9};
    Vector<3,int> r {2,3,0};
    Vector<3,int> f {5,7,8};

#ifdef MATH3D_CARTESIAN_UP_X
    auto x = u;
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    auto y = u;
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    auto z = u;
#endif

// ------------------------------

#ifdef MATH3D_CARTESIAN_RIGHT_X
    auto x = r;
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    auto y = r;
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    auto z = r;
#endif

// ------------------------------

#ifdef MATH3D_CARTESIAN_FORWARD_X
    auto x = f;
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    auto y = f;
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    auto z = f;
#endif

    Matrix<3,3,int> mat3;
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_up(mat3, u);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_right(mat3, r);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_forward(mat3, f);

    Matrix<4,4,int> mat4;
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_up(mat4, u);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_right(mat4, r);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_forward(mat4, f);

    Vector<3,int> X3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(mat3);
    Vector<3,int> Y3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(mat3);
    Vector<3,int> Z3 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(mat3);

    Vector<3,int> X4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_x(mat4);
    Vector<3,int> Y4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_y(mat4);
    Vector<3,int> Z4 = MATH3D_XYZ_NAMESPACE::_internal_get_basis_z(mat4);

    ASSERT_TRUE(X3 == x && X4 == x);
    ASSERT_TRUE(Y3 == y && Y4 == y);
    ASSERT_TRUE(Z3 == z && Z4 == z);
}

/* ####################################################################################### */
/* Basis components */
/* ####################################################################################### */

TEST(Cartesian_3D_InternalFunctions, get_basis_position)
{
    Matrix<4,4,int> mat
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    auto value = MATH3D_XYZ_NAMESPACE::_internal_get_basis_position(mat);
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    auto expec = Vector<3,int>{1,3,2};
#else
    auto expec = Vector<3,int>{4,7,1};
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, set_basis_position)
{
    Matrix<4,4,int> mat
    {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    MATH3D_XYZ_NAMESPACE::_internal_set_basis_position(mat, {2,3,4});

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<4,4,int> expec
    {
        1, 0, 0, 2,
        0, 1, 0, 3,
        0, 0, 1, 4,
        0, 0, 0, 1
    };
#else
    Matrix<4,4,int> expec
    {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        2, 3, 4, 1
    };
#endif

    ASSERT_TRUE(mat == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, get_orientation_matrix3x3_from_matrix4x4)
{
    Matrix<4,4,int> mat
    {
        2, 4, 5, 1,
        3, 6, 7, 3,
        0, 9, 8, 2,
        4, 7, 1, 5
    };

    Matrix<3,3,int> expec
    {
        2, 4, 5,
        3, 6, 7,
        0, 9, 8
    };

    auto res = MATH3D_XYZ_NAMESPACE::_internal_get_orientation_matrix3x3_from_matrix4x4(mat);

    ASSERT_TRUE(res == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, set_orientation_matrix3x3_to_matrix4x4)
{
    {
        Matrix<4,4,int> mat
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        Matrix<3,3,int> orient
        {
            2, 4, 5,
            3, 6, 7,
            0, 9, 8
        };

        Matrix<4,4,int> expec
        {
            2, 4, 5, 0,
            3, 6, 7, 0,
            0, 9, 8, 0,
            0, 0, 0, 1
        };

        MATH3D_XYZ_NAMESPACE::_internal_set_orientation_matrix3x3_to_matrix4x4(mat, orient);

        ASSERT_TRUE(mat == expec);
    }

    {
        Matrix<4,4,int> mat
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        Vector<3,int> x {1,2,3};
        Vector<3,int> y {4,5,6};
        Vector<3,int> z {7,8,9};

        MATH3D_XYZ_NAMESPACE::_internal_set_orientation_matrix3x3_to_matrix4x4(mat, x, y, z);

        Matrix<4,4,int> expec
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        MATH3D_XYZ_NAMESPACE::_internal_set_basis_x(expec, x);
        MATH3D_XYZ_NAMESPACE::_internal_set_basis_y(expec, y);
        MATH3D_XYZ_NAMESPACE::_internal_set_basis_z(expec, z);

        ASSERT_TRUE(mat == expec);
    }
}

/* ####################################################################################### */
/* Quaternion <-> Matrix converters */
/* ####################################################################################### */

TEST(Cartesian_3D_InternalFunctions, convert_xyz_to_quaternion)
{
    Vector<3,double> x {0.910683, 0.333334, -0.244017};
    Vector<3,double> y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> z {0.333334, -0.244017, 0.910683};

    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> expec {0.965926, 0.149429, 0.149429, 0.149429};

    auto res = MATH3D_XYZ_NAMESPACE::_internal_convert_xyz_to_quaternion(x,y,z);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(res, expec, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, convert_quaternion_to_matrix)
{
    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.965926, 0.149429, 0.149429, 0.149429};

    Vector<3,double> x {0.910683, 0.333334, -0.244017};
    Vector<3,double> y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> z {0.333334, -0.244017, 0.910683};

    Matrix<3,3,double> expec(0.0);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_x(expec, x);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_y(expec, y);
    MATH3D_XYZ_NAMESPACE::_internal_set_basis_z(expec, z);

    auto res = MATH3D_XYZ_NAMESPACE::_internal_convert_quaternion_to_matrix3x3(quat);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(res, expec, 0.0001));
}