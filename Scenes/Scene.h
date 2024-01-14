//
// Created by shriller44 on 9/24/22.
//

#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include "entt/entity/registry.hpp"

class Scene {
public:
    Scene() = default;
    virtual ~Scene() = default;
    virtual void draw() = 0;
    virtual void update(float dt) = 0;
    virtual entt::registry& getReg() = 0;
};


#endif //TEST_SCENE_H
