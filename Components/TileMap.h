//
// Created by shriller44 on 9/29/22.
//

#ifndef TEST_TILEMAP_H
#define TEST_TILEMAP_H

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "Components/Position.h"

struct Tile {
    std::shared_ptr<SDL_Texture> texture;
    Position position;
    uint32_t x;
    uint32_t y;
};

struct TileMap {
    std::vector<Tile> tiles;
};

#endif //TEST_TILEMAP_H
