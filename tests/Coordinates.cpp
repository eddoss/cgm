

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Operators/Vector.hpp>
#include <CGM/Coordinates/Functions/Converters.hpp>
#include <CGM/Coordinates/Operators.hpp>


using namespace std;

TEST(Coordinates, Spherical_Cartesian)
{
    auto cartesian_in   = CGM_COORD::cartesian(0.562206, 0.686596, 0.460989);
    auto spherical      = CGM_COORD::spherical(cartesian_in);
    auto cartesian_out  = CGM_COORD::cartesian(spherical);

    ASSERT_TRUE(cartesian_in == cartesian_out);
}

/* --------------------------------------------------------------------------------------- */

TEST(Coordinates, Cylindrical_Cartesian)
{
    auto cartesian_in   = CGM_COORD::cartesian(0.562206, 0.686596, 0.460989);
    auto cylindrical    = CGM_COORD::cylindrical(cartesian_in);
    auto cartesian_out  = CGM_COORD::cartesian(cylindrical);

    ASSERT_TRUE(cartesian_in == cartesian_out);
}

/* --------------------------------------------------------------------------------------- */

TEST(Coordinates, Cylindrical_Spherical)
{
    auto spherical_in   = CGM_COORD::Spherical(0.562206, 0.686596, 0.460989);
    auto cylindrical    = CGM_COORD::cylindrical(spherical_in);
    auto spherical_out  = CGM_COORD::spherical(cylindrical);

    ASSERT_TRUE(spherical_in == spherical_out);
}