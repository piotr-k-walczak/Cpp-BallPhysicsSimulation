//
//  Distance.hpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 25/12/2020.
//

#ifndef Distance_hpp
#define Distance_hpp

#include <memory>
#include "Vector.hpp"

class Distance
{
public:
    static double calc(Vector& pointA, Vector& pointB);
};

#endif /* Distance_hpp */
