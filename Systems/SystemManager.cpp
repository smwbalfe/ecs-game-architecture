//
// Created by shriller44 on 9/22/22.
//

#include "SystemManager.h"

SystemManager::SystemManager(Scene* scene, GameContext* context): currentScene(scene), context_{context}{
    //systems_.emplace("animation", new Animation{this});
    systems_.emplace("movement", new Movement{this});
    systems_.emplace("render", new Render{this});
}

void SystemManager::update(float dt) {

    // For each 'system' we call its update function
    for (auto [name, system]: systems_){
        system->update(dt);
    }
}

void SystemManager::handleEvent(const EntityEvent& event){
    for (auto [name, system]: systems_){
        system->handleEvent(event);
    }
}

void SystemManager::setScene(Scene* newScene) {
    currentScene = newScene;
}

Scene* SystemManager::getScene(){
    return currentScene;
}

GameContext* SystemManager::getContext() { return context_; }

void SystemManager::render() {
    dynamic_cast<Render*>(systems_["render"])->RenderMap();
    dynamic_cast<Render*>(systems_["render"])->render();
}