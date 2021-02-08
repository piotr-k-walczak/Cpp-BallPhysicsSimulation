//
//  World.hpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#ifndef World_hpp
#define World_hpp

#include "Entity.hpp"
#include "Vector.hpp"
#include "Boundaries.h"
#include <vector>
#include <memory>

class World {
public:
    World();

    World(Boundaries &boundaries);

    void update(double deltaTime);

    void addEntity(std::shared_ptr<Entity> entity);

    std::shared_ptr<Boundaries> &getBoundries();

    std::vector<std::shared_ptr<Entity>> &getEntities();

private:
    void updateEntity(double deltaTime);

    std::shared_ptr<Boundaries> _boundaries;

    std::vector<std::shared_ptr<Entity>> _entities;
};

#endif /* Space_hpp */
