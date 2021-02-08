//
//  Friction.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#include "Friction.hpp"

Friction::Friction():Force() {}

std::shared_ptr<Vector> Friction::getValue(Transform &transform)
{
    return Force::getValue(transform);
}

Friction::Friction(double x, double y, double z) {}
