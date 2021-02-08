cmake_minimum_required(VERSION 3.17)
project(SFEngine)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(thirdparty/googletest)

set(sources
        src/World.cpp
        src/World.hpp
        src/Utils/Distance.cpp
        src/Utils/Distance.hpp
        src/Utils/Vector.cpp
        src/Utils/Vector.hpp
        src/Forces/AirFriction.cpp
        src/Forces/AirFriction.hpp
        src/Forces/Force.cpp
        src/Forces/Force.hpp
        src/Forces/Friction.cpp
        src/Forces/Friction.hpp
        src/Materials/Material.hpp
        src/Materials/Material.cpp
        src/Forces/Gravity.cpp
        src/Forces/Gravity.hpp
        src/Entities/Entity.cpp
        src/Entities/Entity.hpp
        src/Entities/Sphere.cpp
        src/Entities/Sphere.hpp
        src/Entities/Transform.cpp
        src/Entities/Transform.hpp
        src/Simulation.cpp
        src/Simulation.hpp
        src/Utils/Boundaries.cpp
        src/Utils/Boundaries.h
        src/Listeners/Listener.h
        src/Listeners/Listener.cpp
        src/Listeners/Listener.cpp
        src/Listeners/Listener.h
        )


set(includes src/Environments src/Utils src/Forces src/Materials src/Entities src/Listeners src)

include_directories(${includes})

add_executable(SFEngine src/main.cpp ${sources})
add_executable(ForceTests tests/ForceTests.cpp ${sources})
add_executable(CollisionTests tests/CollisionTests.cpp ${sources})

target_link_libraries(SFEngine gtest_main)
target_link_libraries(ForceTests gtest_main)
target_link_libraries(CollisionTests gtest_main)