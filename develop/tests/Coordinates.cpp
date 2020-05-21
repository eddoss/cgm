

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Coordinates/Functions.hpp>
#include <Math3D/Coordinates/Operators.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Coordinates, Spherical_Cartesian)
{
    auto cartesian_in   = coord::cartesian(0.562206, 0.686596, 0.460989);
    auto spherical      = coord::spherical(cartesian_in);
    auto cartesian_out  = coord::cartesian(spherical);

    ASSERT_TRUE(cartesian_in == cartesian_out);
}

/* --------------------------------------------------------------------------------------- */

TEST(Coordinates, Cylindrical_Cartesian)
{
    auto cartesian_in   = coord::cartesian(0.562206, 0.686596, 0.460989);
    auto cylindrical    = coord::cylindrical(cartesian_in);
    auto cartesian_out  = coord::cartesian(cylindrical);

    ASSERT_TRUE(cartesian_in == cartesian_out);
}

/* --------------------------------------------------------------------------------------- */

TEST(Coordinates, Cylindrical_Spherical)
{
    auto spherical_in   = coord::Spherical(0.562206, 0.686596, 0.460989);
    auto cylindrical    = coord::cylindrical(spherical_in);
    auto spherical_out  = coord::spherical(cylindrical);

    ASSERT_TRUE(spherical_in == spherical_out);
}