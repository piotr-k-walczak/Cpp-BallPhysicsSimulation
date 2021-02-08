//
// Created by Piotr Walczak on 10/01/2021.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Sphere.hpp"
#include "Boundaries.h"

TEST(force_tests, position_change_in_1_interval)
{
    Sphere sphere;
    sphere.update(1.0);

    Vector vector(0, 0, -9.80665 / 2);

    Vector pos = *(sphere.getTransform()->position);
    ASSERT_EQ(vector.x, pos.x);
    ASSERT_EQ(vector.y, pos.y);
    ASSERT_EQ(vector.z, pos.z);
}

TEST(force_tests, speed_change_in_1_interval)
{
    Sphere sphere;
    sphere.update(1.0);

    Vector vector(0, 0, -9.80665);

    Vector pos = *(sphere.getTransform()->speed);
    ASSERT_EQ(vector.x, pos.x);
    ASSERT_EQ(vector.y, pos.y);
    ASSERT_EQ(vector.z, pos.z);
}

TEST(force_tests, air_friction_direction)
{
    Sphere sphere;
    sphere.getTransform()->speed->z = 100;
    sphere.getTransform()->speed->y = -100;
    sphere.getTransform()->speed->x = 100;

    AirFriction airFriction;
    std::shared_ptr<Vector> value = airFriction.getValue(*sphere.getTransform());

    ASSERT_TRUE(value->x < 0);
    ASSERT_TRUE(value->y > 0);
    ASSERT_TRUE(value->z < 0);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}