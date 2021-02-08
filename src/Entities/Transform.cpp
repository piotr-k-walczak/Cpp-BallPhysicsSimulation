//
//  Transform.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#include "Transform.hpp"

Transform::Transform()
{
    mass = 1;
    volume = 1;
    crossSectionalArea = 1;
    dragCoefficiency = 1;

    position = std::make_shared<Vector>();
    rotation = std::make_shared<Vector>();
    speed = std::make_shared<Vector>();
}

Transform::Transform(Vector& position, Vector& rotation)
{
    this->position = std::make_shared<Vector>(position);
    this->rotation = std::make_shared<Vector>(rotation);
    this->speed = std::make_shared<Vector>();
}

Transform::Transform(Transform &other):Transform(*other.position, *other.rotation) {}

