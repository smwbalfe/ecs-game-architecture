//
// Created by shriller44 on 9/22/22.
//

#ifndef TEST_SYSTEMMANAGER_H
#define TEST_SYSTEMMANAGER_H
#pragma once

#include <vector>
#include "GameContext.h"
#include "Scenes/Scene.h"
#include "Systems/System.h"
#include "Systems/AnimationHandler.h"
#include "Systems/Movement.h"
#include "Systems/Render.h"

class SystemManager {

public:
    SystemManager(Scene* scene, GameContext* context);
    void update(float dt);
    void handleEvent(const EntityEvent& event);
    void setScene(Scene* newScene);
    Scene* getScene();
    void render();
    GameContext* getContext();
private:
    std::map<std::string, System*> systems_;
    Scene* currentScene;
    GameContext* context_;
};


#endif //TEST_SYSTEMMANAGER_H
