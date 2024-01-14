//
// Created by shriller44 on 9/18/22.
//

#ifndef TEST_TEXTURE_H
#define TEST_TEXTURE_H

#include <cstdint>
#include <SDL2/SDL.h>

struct Texture {
    std::shared_ptr<SDL_Texture> texture;

    int width;
    int height;

    int row;
    int frame;
};

#endif //TEST_TEXTURE_H
