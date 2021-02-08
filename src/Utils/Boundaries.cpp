//
// Created by Piotr Walczak on 30/12/2020.
//

#include <iostream>
#include "Boundaries.h"

Boundaries::Boundaries():Boundaries(0) {}

Boundaries::Boundaries(double d):Boundaries(
        std::pair<double, double>(-d, d),
        std::pair<double, double>(-d, d),
        std::pair<double, double>(0, d)) {}

Boundaries::Boundaries(std::pair<double, double> x, std::pair<double, double> y, std::pair<double, double> z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

bool Boundaries::isPointWithin(Vector& point) const
{
    return x.first <= point.x <= x.second && y.first <= point.y <= y.second && z.first <= point.z <= z.second;
}

Vector Boundaries::collisionReaction(Entity &entity)
{
    Vector vector(1,1,1);
    std::shared_ptr<Vector> position = entity.getTransform()->position;
    std::shared_ptr<Vector> speed = entity.getTransform()->speed;
    if((speed->x > 0 && position->x + entity.distanceOfFurthestPoint() >= x.second) || (speed->x < 0 && position->x - entity.distanceOfFurthestPoint() <= x.first))
    {
        vector.x = -1;
    }
    if((speed->y > 0 && position->y + entity.distanceOfFurthestPoint() >= y.second) || (speed->y < 0 && position->y - entity.distanceOfFurthestPoint() <= y.first))
    {
        vector.y = -1;
    }
    if((speed->z > 0 && position->z + entity.distanceOfFurthestPoint() >= z.second) || (speed->z < 0 && position->z - entity.distanceOfFurthestPoint() <= z.first))
    {
        vector.z = -1;
    }
    return vector;
}