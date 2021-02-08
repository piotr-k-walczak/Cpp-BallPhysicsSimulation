//
//  Gravity.hpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#ifndef Gravity_hpp
#define Gravity_hpp

#include "Force.hpp"

class Gravity: public Force
{
public:
    Gravity();

    std::shared_ptr<Vector> getValue(Transform& transform);
};

#endif /* Gravity_hpp */
