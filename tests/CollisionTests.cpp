//
// Created by Piotr Walczak on 05/02/2021.
//
#include <iostream>
#include "gtest/gtest.h"
#include "Sphere.hpp"
#include "Boundaries.h"

TEST(boundaries_tests, sphere_within_boundaries)
{
    Boundaries boundaries(100);
    Sphere sphere;
    ASSERT_TRUE(boundaries.isPointWithin(*sphere.getTransform()->position));
}