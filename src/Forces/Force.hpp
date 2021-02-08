//
//  Force.hpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#ifndef Force_hpp
#define Force_hpp

#include "Vector.hpp"
#include "Transform.hpp"
#include <vector>

class Force {
public:
    Force();
    Force(double x, double y, double z);
    explicit Force(std::vector<std::shared_ptr<Force>>& forces);

    virtual std::shared_ptr<Vector> getValue(Transform& transform);
    bool reduce(double deltaTime);
    
protected:
    void calculateResultantForce(std::vector<std::shared_ptr<Force>>& forces, Transform& transform);

    bool _enviromental;
    double _duration;
    double _durationLeft;

    std::shared_ptr<Vector> _value;
    std::vector<std::shared_ptr<Force>> _forces;
};

#endif /* Force_hpp */
