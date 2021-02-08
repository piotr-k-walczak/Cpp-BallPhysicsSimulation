//
// Created by Piotr Walczak on 10/01/2021.
//

#ifndef SIMPLEPHYSICSENGINE_LISTENER_H
#define SIMPLEPHYSICSENGINE_LISTENER_H

#include <memory>
#include "World.hpp"
#include <iostream>

class Listener {
public:
    Listener();

    void setWorld(std::shared_ptr<World>& world);

    void call();
private:
    std::shared_ptr<World> _world;
};


#endif //SIMPLEPHYSICSENGINE_LISTENER_H
