//
//  main.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#include <memory>
#include "Sphere.hpp"
#include "Simulation.hpp"

int main(int argc, const char * argv[])
{
    std::unique_ptr<Simulation> simulation = std::make_unique<Simulation>();

    //Applying default listener
    simulation->addListener(std::make_shared<Listener>());

    //Creating sphere and adding it to the simulation
    std::shared_ptr<Sphere> sphere = std::make_shared<Sphere>(5);
    sphere->getTransform()->position->z = 6;
    simulation->addEntity(sphere);

    //Applying start force to the simulation
    std::shared_ptr<Force> force = std::make_shared<Force>(7000, 5000, 0);
    sphere->applyForce(force);

    simulation->start();

    return 0;
}
