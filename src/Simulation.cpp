//
//  Simulation.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#include "Simulation.hpp"

Simulation::Simulation()
{
    _world = std::make_shared<World>();
}

void Simulation::setWorld(std::shared_ptr<World> &world)
{
    this->_world = world;
}

void Simulation::start()
{
    _running = true;

    clock_t t = clock();

    double tt = 0;

    while (_running) {

        _world->update(float(clock() - t) / CLOCKS_PER_SEC);
        tt += float(clock() - t) / CLOCKS_PER_SEC;
        t = clock();

        for (int i = 0; i < _listeners.size(); i++)
        {
            _listeners.at(i)->call();
        }
    }
}

void Simulation::stop()
{
    _running = false;
}

void Simulation::addListener(std::shared_ptr<Listener> listener)
{
    listener->setWorld(_world);
    _listeners.push_back(listener);
}

void Simulation::addEntity(std::shared_ptr<Entity> entity)
{
    _world->addEntity(entity);
}
