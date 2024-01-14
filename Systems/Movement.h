//
// Created by shriller44 on 9/22/22.
//

#ifndef TEST_MOVEMENT_H
#define TEST_MOVEMENT_H
#pragma once

#include <iostream>
#include "Systems/System.h"
#include <entt/entity/registry.hpp>
#include "Components/Position.h"
#include "constants/EntityEvents.h"
#include "SystemManager.h"

class Movement: public System {

public:
    explicit Movement(SystemManager* sysMgr);

    void update(float dt) override;

    void handleEvent(const EntityEvent& event) override;
private:
    SystemManager* sysMgr_;
};


#endif //TEST_MOVEMENT_H
