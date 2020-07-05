

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Quaternion.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>


using namespace MATH3D_NAMESPACE;

using namespace std;

TEST(Quaternion_Functions, Dot)
{
    Quaternion<float> a {6.947f, 6.123f, 8.154f, 3.350f};
    Quaternion<float> b {5.936f, 9.405f, 1.050f, 2.622f};

    float dtp = dot(a,b);
    float exp = 116.179f;

    ASSERT_TRUE(equal(dtp,exp,0.01f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Conjugate)
{
    Quaternion<float> a {6.f, 5.f, 8.f, 3.f};
    Quaternion<float> b {6.f, -5.f, -8.f, -3.f};

    ASSERT_TRUE(conjugate(a) == b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Conjugated)
{
    Quaternion<float> a {6.f, 5.f, 8.f, 3.f};
    Quaternion<float> b {6.f, -5.f, -8.f, -3.f};

    ASSERT_TRUE(conjugated(a) == b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Length)
{
    Quaternion<float> q {9.487f, 9.632f, 1.152f, 1.088f};
    float len = length(q);
    float exp = 13.612f;

    ASSERT_TRUE(equal(len,exp,0.001f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Norm)
{
    Quaternion<float> q {9.678f, 1.690f, 8.336f, 2.821f};

    float len = norm(q);
    float exp = 173.973f;

    ASSERT_TRUE(equal(len,exp,0.01f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Normalize)
{
    Quaternion<double> qtr {4.043, 5.403, 2.650, 8.516};
    Quaternion<double> nrm {0.362, 0.483, 0.237, 0.761};

    {
        auto res = qtr;
        auto suc = normalize(res);
        ASSERT_TRUE(equal(res, nrm, 0.001) && suc);
    }

    {
        auto res = qtr;
        bool suc = false;
        res = normalized(res, suc);
        ASSERT_TRUE(equal(res, nrm, 0.001) && suc);
    }

    {
        auto res = qtr;
        normalizeForce(res);
        ASSERT_TRUE(equal(res, nrm, 0.001));
    }

    {
        auto res = qtr;
        res = normalizedForce(res);
        ASSERT_TRUE(equal(res, nrm, 0.001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Inverse)
{
    Quaternion<double> qtr {1.22, 4.34, 5.11, 12.7};
    Quaternion<double> inv {0.0058731,-0.0208929,-0.0245997,-0.0611382};

    {
        auto res = qtr;
        invert(res);
        ASSERT_TRUE(equal(res, inv, 0.001));
    }

    {
        auto res = qtr;
        bool success = false;
        res = inverse(res, success);
        ASSERT_TRUE(equal(res, inv, 0.001));
    }

    {
        auto res = qtr;
        invertForce(res);
        ASSERT_TRUE(equal(res, inv, 0.001));
    }

    {
        auto res = qtr;
        res = inverseForce(res);
        ASSERT_TRUE(equal(res, inv, 0.001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Orient)
{
    Quaternion<double> quat {-0.140680, 0.968583, 0.175850, 0.105510};
    Vector<3,double> vec {1.0, 0.0, 0.0};

    Vector<3,double> exp {0.915888, 0.310964, 0.253868};

    orient(vec, quat);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(vec, exp, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Angle)
{
    Quaternion<float> a {1.22f, 4.34f, 5.11f, 3.74f};
    Quaternion<float> b {0.25f, 2.16f, 1.45f, 2.47f};

    normalize(a);
    normalize(b);

    float ang = angle(a,b);

    ASSERT_TRUE(equal(ang, 0.6855f, 0.0001f));
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Functions, Identity)
{
    Quaternion<float> idn = identity<float>();
    Quaternion<float> exp = {1.0f, 0.f, 0.f, 0.f};

    ASSERT_TRUE(idn.s == exp.s);
    ASSERT_TRUE(idn.x == exp.x);
    ASSERT_TRUE(idn.y == exp.y);
    ASSERT_TRUE(idn.z == exp.z);
}