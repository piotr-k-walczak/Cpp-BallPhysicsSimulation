//
//  Sphere.hpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include "Entity.hpp"
#include "Distance.hpp"
#include <math.h>

class Sphere : public Entity {
public:
    Sphere();
    Sphere(int radius);
    
    bool isPointWithin(Vector& point) override;
    double distanceToEdge(Vector& point) override;
    double distanceToCenter(Vector& point) override;
    std::shared_ptr<Vector> closestPoint(Vector& point) override;
    double distanceOfFurthestPoint() override;

    double calcMass() override;
    double calcCrossSectionalArea() override;
    double calcVolume() override;

protected:
    double _radius;
};

#endif /* Sphere_hpp */
