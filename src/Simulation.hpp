//
//  Simulation.hpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#ifndef Simulation_hpp
#define Simulation_hpp

#include <memory>
#include "World.hpp"
#include "Listener.h"

class Simulation {
public:
    Simulation();

    void start();
    void stop();
    void addListener(std::shared_ptr<Listener> listener);
    void addEntity(std::shared_ptr<Entity> entity);
    void setWorld(std::shared_ptr<World>& world);

private:
    bool _running = false;
    std::shared_ptr<World> _world;
    std::vector<std::shared_ptr<Listener>> _listeners;
};

#endif /* Simulation_hpp */
