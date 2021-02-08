//
//  Gravity.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#include "Gravity.hpp"

Gravity::Gravity():Force()
{
    _enviromental = true;
}

std::shared_ptr<Vector> Gravity::getValue(Transform& transform)
{
    return std::make_shared<Vector>(0, 0, -9.80665);
}