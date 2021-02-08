//
//  Entity.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#include "Entity.hpp"

Entity::Entity() {

    _moveable = true;

    _material = std::make_shared<Material>();
    _transform = std::make_shared<Transform>();

    applyForce(std::make_shared<Gravity>());
    applyForce(std::make_shared<AirFriction>());
}

void Entity::update(double deltaTime)
{
    if(_moveable)
    {
        Force resultantForce = Force(_applyingForces);
        updatePosition(resultantForce, deltaTime);
        updateSpeed(resultantForce, deltaTime);
        updateForces(deltaTime);
    }
}

void Entity::updateSpeed(Force& force, double deltaTime)
{
    *_transform->speed += *force.getValue(*_transform) / _transform->mass * deltaTime;
}

void Entity::updatePosition(Force& force, double deltaTime)
{
    *_transform->position += (*_transform->speed + (*force.getValue(*_transform) / _transform->mass / 2 * deltaTime)) * deltaTime;
}

void Entity::updateForces(double deltaTime)
{
    auto it = _applyingForces.begin();

    while(it != _applyingForces.end())
    {
        if((*it)->reduce(deltaTime))
        {
            it = _applyingForces.erase(it);
        }
        else ++it;
    }
}

void Entity::applyForce(std::shared_ptr<Force> force)
{
    _applyingForces.push_back(force);
}

double Entity::getMass() const
{
    return _transform->mass;
}

double Entity::getCrossSectionalArea() const
{
    return _transform->crossSectionalArea;
}

double Entity::getVolume() const
{
    return _transform->volume;
}

std::shared_ptr<Transform> Entity::getTransform()
{
    return _transform;
}

void Entity::setMass(double mass)
{
    _transform->mass = mass;
}

void Entity::setVolume(double volume)
{
    _transform->volume = volume;
}

void Entity::setCrossSectionalArea(double cross)
{
    _transform->crossSectionalArea = cross;
}

void Entity::applyReaction(Vector& reaction)
{
    *_transform->speed *= reaction;
}

