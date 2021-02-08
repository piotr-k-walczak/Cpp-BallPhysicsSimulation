//
//  Distance.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 25/12/2020.
//

#include "Distance.hpp"
#include <math.h>

double Distance::calc(Vector& pointA, Vector& pointB)
{
    return sqrt(pow(pointB.x - pointA.x, 2)
                + pow(pointB.y - pointA.y, 2)
                + pow(pointB.z - pointA.z, 2));
}
