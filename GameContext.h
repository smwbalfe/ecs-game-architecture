//
// Created by shriller44 on 9/20/22.
//

#ifndef TEST_GAMECONTEXT_H
#define TEST_GAMECONTEXT_H
#pragma once

#include <SDL2/SDL.h>
#include "ResourceManagers/TextureManager.h"
#include "Game.h"

class SystemManager;

struct GameContext {

    struct sys_dtor {
        void operator()(SystemManager* sys) const{
            free(sys);
        }
    };

    GameContext();

    std::unique_ptr<SDL_Window> window_;
    std::unique_ptr<SDL_Renderer, Game::SDLRendererDestroyer> renderer_;
    std::unique_ptr<TextureManager> textureManager_ {};
    std::unique_ptr<SystemManager, sys_dtor> systemManager_ {};

};

#endif //TEST_GAMECONTEXT_H
