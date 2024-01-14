//
// Created by shriller44 on 9/18/22.
//

#include "MainScene.h"

MainScene::MainScene(std::string name, GameContext* context): name_{std::move(name)}, context_{context}{
    addKeyCode(SDLK_UP, EntityEvent::MOVE_UP);
    addKeyCode(SDLK_RIGHT, EntityEvent::MOVE_RIGHT);
    addKeyCode(SDLK_LEFT, EntityEvent::MOVE_LEFT);
    addKeyCode(SDLK_DOWN, EntityEvent::MOVE_DOWN);
}

void MainScene::draw() {
    context_->systemManager_->render();
}

void MainScene::update(float dt)  {
    handleEvents();
    context_->systemManager_->update(dt);
}

void MainScene::handleEvents(){
    auto state = SDL_GetKeyboardState(nullptr);
    for (auto& [code, action]: keyMap_){
        auto scancode = SDL_GetScancodeFromKey(code);
        if (state[scancode]) {
            context_->systemManager_->handleEvent(action);
        }
    }
}

bool MainScene::addKeyCode(SDL_KeyCode kc, const EntityEvent& event){
    if (keyMap_.contains(kc)) return false;
    keyMap_[kc] = event;
    return true;
}

entt::registry& MainScene::getReg() {  return reg_; }

MainScene::~MainScene() = default;