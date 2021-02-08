//
//  AirFriction.hpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#ifndef AirFriction_hpp
#define AirFriction_hpp

#include "Force.hpp"

class AirFriction: public Force
{
public:
    AirFriction();

    const double AIR_DENSITY = 1.225;

    std::shared_ptr<Vector> getValue(Transform& transform);

private:
    double calcForceOnAxis(Transform &transform, double speed);
};


#endif /* AirFriction_hpp */
