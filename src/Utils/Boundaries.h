//
// Created by Piotr Walczak on 30/12/2020.
//

#ifndef SIMPLEPHYSICSENGINE_BOUNDARIES_H
#define SIMPLEPHYSICSENGINE_BOUNDARIES_H

#include <utility>
#include "Vector.hpp"
#include <math.h>
#include <Transform.hpp>
#include <Sphere.hpp>

struct Boundaries
{
    Boundaries();
    Boundaries(double d);
    Boundaries(std::pair<double, double> x, std::pair<double, double> y, std::pair<double, double> z);

    bool isPointWithin(Vector& point) const;
    Vector collisionReaction(Entity& entity);

    std::pair<double, double> x;
    std::pair<double, double> y;
    std::pair<double, double> z;
};


#endif //SIMPLEPHYSICSENGINE_BOUNDARIES_H
