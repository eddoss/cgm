

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Common.hpp>
#include <CGM/detail/Cartesian/3D/Types/Quaternion.hpp>
#include <CGM/detail/Core/Functions/Vector.hpp>
#include <CGM/detail/Cartesian/3D/Functions/Quaternion.hpp>


using namespace CGM;

using namespace std;

TEST(Cartesian_3D_Functions_Quaternion, Dot)
{
    CGM_XYZ::Quaternion<float> a {6.947f, 6.123f, 8.154f, 3.350f};
    CGM_XYZ::Quaternion<float> b {5.936f, 9.405f, 1.050f, 2.622f};

    float dtp = dot(a,b);
    float exp = 116.179f;

    ASSERT_TRUE(eq(dtp,exp,0.01f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Quaternion, Conjugate)
{
    CGM_XYZ::Quaternion<float> a {6.f, 5.f, 8.f, 3.f};
    CGM_XYZ::Quaternion<float> b {-6.f, -5.f, -8.f, 3.f};

    ASSERT_TRUE(conjugate(a) == b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Quaternion, Length)
{
    CGM_XYZ::Quaternion<float> q {9.632f, 1.152f, 1.088f, 9.487f};
    float len = length(q);
    float exp = 13.612f;

    ASSERT_TRUE(eq(len,exp,0.001f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Quaternion, Norm)
{
    CGM_XYZ::Quaternion<float> q {1.690f, 8.336f, 2.821f, 9.678f};

    float len = norm(q);
    float exp = 173.973f;

    ASSERT_TRUE(eq(len,exp,0.01f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Quaternion, Normalize)
{
    CGM_XYZ::Quaternion<double> qtr {5.403, 2.650, 8.516, 4.043};
    CGM_XYZ::Quaternion<double> nrm {0.483, 0.237, 0.761, 0.362};

    {
        auto res = qtr;
        auto suc = normalize(res);
        ASSERT_TRUE(eq(res, nrm, 0.001) && suc);
    }

    {
        auto res = qtr;
        bool suc = false;
        res = normalized(res, suc);
        ASSERT_TRUE(eq(res, nrm, 0.001) && suc);
    }

    {
        auto res = qtr;
        normalizeForce(res);
        ASSERT_TRUE(eq(res, nrm, 0.001));
    }

    {
        auto res = qtr;
        res = normalizedForce(res);
        ASSERT_TRUE(eq(res, nrm, 0.001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Quaternion, Inverse)
{
    CGM_XYZ::Quaternion<double> qtr {4.34, 5.11, 12.7, 1.22};
    CGM_XYZ::Quaternion<double> inv {-0.0208929, -0.0245997, -0.0611382, 0.0058731};

    {
        auto res = qtr;
        invert(res);
        ASSERT_TRUE(eq(res, inv, 0.001));
    }

    {
        auto res = qtr;
        bool success = false;
        res = inverse(res, success);
        ASSERT_TRUE(eq(res, inv, 0.001));
    }

    {
        auto res = qtr;
        invertForce(res);
        ASSERT_TRUE(eq(res, inv, 0.001));
    }

    {
        auto res = qtr;
        res = inverseForce(res);
        ASSERT_TRUE(eq(res, inv, 0.001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Quaternion, Orient)
{
    CGM_XYZ::Quaternion<double> quat {0.968583, 0.175850, 0.105510, -0.140680};
    Vector<3,double> vec {1.0, 0.0, 0.0};

    Vector<3,double> result = oriented(vec, quat);
#ifdef CGM_LEFT_HANDED
    Vector<3,double> expect {0.915889 , 0.310964 , 0.253868 };
#else
    Vector<3,double> expect {0.915888, 0.370337, 0.154913};
#endif
    //ASSERT_TRUE(CGM::equal(result, expect, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Quaternion, Angle)
{
    CGM_XYZ::Quaternion<float> a {4.34f, 5.11f, 3.74f, 1.22f};
    CGM_XYZ::Quaternion<float> b {2.16f, 1.45f, 2.47f, 0.25f};

    normalize(a);
    normalize(b);

    float ang = angle(a,b);

    ASSERT_TRUE(eq(ang, 0.6855f, 0.0001f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Quaternion, Identity)
{
    CGM_XYZ::Quaternion<float> idn = CGM_XYZ::identity<float>();
    CGM_XYZ::Quaternion<float> exp = {0.f, 1.0f};

    ASSERT_TRUE(idn.vector.x == exp.vector.x);
    ASSERT_TRUE(idn.vector.y == exp.vector.y);
    ASSERT_TRUE(idn.vector.z == exp.vector.z);
    ASSERT_TRUE(idn.scalar == exp.scalar);
}