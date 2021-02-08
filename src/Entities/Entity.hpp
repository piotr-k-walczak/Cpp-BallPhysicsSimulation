//
//  Entity.hpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <memory>
#include <vector>
#include <iostream>
#include "Force.hpp"
#include "Transform.hpp"
#include "Material.hpp"
#include "Entity.hpp"
#include "Force.hpp"
#include "Vector.hpp"
#include "Gravity.hpp"
#include "AirFriction.hpp"

class Entity {
public:
    Entity();

    void update(double deltaTime);
    void applyForce(std::shared_ptr<Force> force);
    void applyReaction(Vector &reaction);

    virtual bool isPointWithin(Vector& point) = 0;
    virtual double distanceToEdge(Vector& point) = 0;
    virtual double distanceToCenter(Vector& point) = 0;
    virtual std::shared_ptr<Vector> closestPoint(Vector& point) = 0;
    virtual double distanceOfFurthestPoint() = 0;

    virtual double calcMass() = 0;
    virtual double calcCrossSectionalArea() = 0;
    virtual double calcVolume() = 0;

    void setMass(double mass);
    void setVolume(double volume);
    void setCrossSectionalArea(double volume);

    double getMass() const;
    double getCrossSectionalArea() const;
    double getVolume() const;

    std::shared_ptr<Transform> getTransform();

protected:
    void updateSpeed(Force& force, double deltaTime);
    void updatePosition(Force& force, double deltaTime);
    void updateForces(double deltaTime);

    bool _moveable;
    std::shared_ptr<Transform> _transform;
    std::shared_ptr<Material> _material;
    std::vector<std::shared_ptr<Force>> _applyingForces;
};

#endif /* Entity_hpp */
