//
// Created by shriller44 on 9/22/22.
//

#ifndef TEST_RENDER_H
#define TEST_RENDER_H
#pragma once

#include "System.h"
#include "SystemManager.h"
#include "entt/entity/registry.hpp"
#include "Components/Position.h"
#include "Components/Texture.h"
#include "Components/TileMap.h"

class Render : public System {
public:
    explicit Render(SystemManager *sysMgr);
    void update(float dt) override;
    void render();
    void handleEvent(const EntityEvent& event) override;
    void RenderMap();

private:
    SystemManager* sysMgr_;
};


#endif //TEST_RENDER_H
