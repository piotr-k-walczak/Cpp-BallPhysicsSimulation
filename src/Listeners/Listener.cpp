//
// Created by Piotr Walczak on 10/01/2021.
//

#include "Listener.h"

Listener::Listener() {}

void Listener::setWorld(std::shared_ptr<World>& world)
{
    _world = world;
}

void Listener::call()
{
    for(auto & entity : _world->getEntities())
    {
        std::cout << "\nEntity" << std::endl;
        std::cout << "Pos X: " << entity->getTransform()->position->x << std::endl;
        std::cout << "Pos Y: " << entity->getTransform()->position->y << std::endl;
        std::cout << "Pos Z: " << entity->getTransform()->position->z << std::endl;
        std::cout << "Speed X: " << entity->getTransform()->speed->x << std::endl;
        std::cout << "Speed Y: " << entity->getTransform()->speed->y << std::endl;
        std::cout << "Speed Z: " << entity->getTransform()->speed->z << std::endl;
    }
}
