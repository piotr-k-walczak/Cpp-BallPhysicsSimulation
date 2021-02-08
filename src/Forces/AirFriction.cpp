//
//  AirFriction.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#include <iostream>
#include "AirFriction.hpp"

AirFriction::AirFriction():Force()
{
    _enviromental = true;
}


std::shared_ptr<Vector> AirFriction::getValue(Transform &transform)
{
    _value->x = calcForceOnAxis(transform, transform.speed->x);
    _value->y = calcForceOnAxis(transform, transform.speed->y);
    _value->z = calcForceOnAxis(transform, transform.speed->z);
    return _value;
}

double AirFriction::calcForceOnAxis(Transform &transform, double speed)
{
    int sign = 1;
    if(speed < 0)
        sign = -1;
    sign *= -1;
    return AIR_DENSITY * pow(speed, 2) * transform.dragCoefficiency * transform.crossSectionalArea * sign;
}

