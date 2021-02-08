//
//  Friction.hpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#ifndef Friction_hpp
#define Friction_hpp

#include "Force.hpp"

class Friction: public Force
{
public:
    Friction();
    Friction(double x, double y, double z);

    std::shared_ptr<Vector> getValue(Transform& transform);
};


#endif /* Friction_hpp */
