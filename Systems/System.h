//
// Created by shriller44 on 9/21/22.
//

#ifndef TEST_SYSTEM_H
#define TEST_SYSTEM_H

#include "constants/EntityEvents.h"
#include "entt/entity/registry.hpp"

class System {
public:
    System() = default;
    virtual void update(float dt) = 0;
    virtual void handleEvent(const EntityEvent& event) = 0;
};


#endif //TEST_SYSTEM_H
