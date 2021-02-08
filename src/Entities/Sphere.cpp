//
//  Sphere.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#include "Sphere.hpp"

Sphere::Sphere():Sphere(1) {}

Sphere::Sphere(int radius):Entity()
{
    _radius = radius;
    _transform->dragCoefficiency = 0.47;
}

bool Sphere::isPointWithin(Vector& point)
{
    return Distance::calc(*_transform->position, point) <= _radius;
}

double Sphere::distanceToCenter(Vector& point)
{
    return Distance::calc(*_transform->position, point);
}

double Sphere::distanceToEdge(Vector& point)
{
    return Distance::calc(*_transform->position, point) - _radius;
}

std::shared_ptr<Vector> Sphere::closestPoint(Vector& point)
{
    return std::make_shared<Vector>();
}

double Sphere::calcVolume() {
    _transform->volume = 4 / 3 * M_PI * pow(_radius, 3);
    return _transform->volume;
}

double Sphere::calcMass(){
    _transform->mass = _transform->volume;
    return _transform->mass;
}

double Sphere::calcCrossSectionalArea()
{
    _transform->crossSectionalArea = M_PI * pow(_radius, 2);
    return _transform->crossSectionalArea;
}

double Sphere::distanceOfFurthestPoint()
{
    return _radius;
}
