//
// Created by shriller44 on 9/18/22.
//

#ifndef TESTGAME_SCENE_H
#define TESTGAME_SCENE_H

#include "Systems/Render.h"
#include "GameContext.h"
#include <optional>
#include "factory/creation.h"
#include "EntityTags.h"

class MainScene : public Scene {

public:
    explicit MainScene(std::string name, GameContext* context);

    ~MainScene() override;

    void draw() override;

    void update(float dt) override;

    void handleEvents();

    template<typename et , typename... args>
    std::optional<entt::entity> createEntity(args&&... params){

        if constexpr (std::is_same_v<et, Player>){
            return shrillerEngine::createPlayer(reg_, std::forward<args>(params)...);
        }
        else if (std::is_same_v<et, Map>){
            return shrillerEngine::createMap(reg_, std::forward<args>(params)...);
        }

        return std::nullopt;
    }

    bool addKeyCode(SDL_KeyCode kc, const EntityEvent& event);

    entt::registry& getReg() override;

private:
    GameContext* context_;
    std::string name_;
    entt::registry reg_;
    std::map<SDL_KeyCode, EntityEvent> keyMap_;
};


#endif //TESTGAME_SCENE_H
