//
//  World.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#include <Distance.hpp>
#include "World.hpp"

World::World()
{
    _boundaries = std::make_shared<Boundaries>(100);
}

World::World(Boundaries& boundaries)
{
    _boundaries = std::make_shared<Boundaries>(boundaries);
}

void World::update(double deltaTime)
{
    for (auto & entity : _entities)
    {
        if(_boundaries->isPointWithin(*entity->getTransform()->position))
        {
            Vector reaction = _boundaries->collisionReaction(*entity);
            entity->applyReaction(reaction);
        }

        entity->update(deltaTime);
    }
}

std::vector<std::shared_ptr<Entity>> &World::getEntities()
{
    return _entities;
}

void World::addEntity(std::shared_ptr<Entity> entity)
{
    _entities.push_back(entity);
}

std::shared_ptr<Boundaries> &World::getBoundries()
{
    return _boundaries;
}
