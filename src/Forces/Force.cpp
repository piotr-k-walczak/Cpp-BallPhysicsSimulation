//
//  Force.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#include "Force.hpp"

Force::Force():Force(0,0,0){}

Force::Force(double x, double y, double z)
{
    _enviromental = false;
    _duration = _durationLeft = 0.1;
    _value = std::make_shared<Vector>(x, y, z);
}

Force::Force(std::vector<std::shared_ptr<Force>>& forces):Force()
{
    _forces = forces;
}

std::shared_ptr<Vector> Force::getValue(Transform& transform)
{
    if (!_forces.empty())
    {
        calculateResultantForce(_forces, transform);
    }
    return _value;
}

bool Force::reduce(double deltaTime)
{
    if(_enviromental) return false;
    _durationLeft -= deltaTime;
    return _durationLeft <= 0;
}

void Force::calculateResultantForce(std::vector<std::shared_ptr<Force>>& forces, Transform& transform) {
    *_value = Vector(0, 0, 0);
    for(auto & force : forces){
        *_value += *force->getValue(transform);
    }
}
