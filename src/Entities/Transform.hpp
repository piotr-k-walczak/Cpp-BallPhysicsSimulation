//
//  Transform.hpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#ifndef Transform_hpp
#define Transform_hpp

#include "Utils/Vector.hpp"
#include <memory>

struct Transform {
    Transform();
    Transform(Transform& other);
    Transform(Vector& position, Vector& rotation);
    
    std::shared_ptr<Vector> position;
    std::shared_ptr<Vector> rotation;
    std::shared_ptr<Vector> speed;

    double mass;
    double crossSectionalArea;
    double volume;
    double dragCoefficiency;
};

#endif /* Transform_hpp */
