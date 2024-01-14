//
// Created by shriller44 on 9/23/22.
//

#ifndef TEST_ANIMATIONHANDLER_H
#define TEST_ANIMATIONHANDLER_H
#pragma once

#include "System.h"
#include "constants/EntityEvents.h"
#include "Components/Texture.h"
#include <entt/entity/registry.hpp>
#include "SystemManager.h"
#include <iostream>


class Animation : public System{

public:
    explicit Animation(SystemManager *sysMgr);

    void update(float dt) override;

    void handleEvent(const EntityEvent& event) override;

private:
    SystemManager* sysMgr_;
    float df {0};
};


#endif //TEST_ANIMATIONHANDLER_H
