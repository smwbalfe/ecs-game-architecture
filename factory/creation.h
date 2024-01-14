//
// Created by shriller44 on 9/19/22.
//

#ifndef TEST_CREATION_H
#define TEST_CREATION_H

#include <iostream>
#include "Components/Position.h"
#include "Components/Texture.h"
#include "Components/TileMap.h"
#include "ResourceManagers/TextureManager.h"

#include <fstream>

/*
template<typename Component,typename... args>
void addComponent(entt::registry& reg_, const entt::entity& entity, args&&... params){
    reg_.emplace<Component>(entity, std::forward<args>(params)...);
}
*/

namespace shrillerEngine {
    inline entt::entity createPlayer(entt::registry &reg, int x, int y, int width, int height, std::shared_ptr<SDL_Texture> tex) {
        auto entity = reg.create();
        reg.emplace<Position>(entity, x, y);
        reg.emplace<Texture>(entity, std::move(tex), width, height, 1, 1);
        return entity;
    }

    inline entt::entity createTile(entt::registry &reg, std::shared_ptr<SDL_Texture> tex, int height, int width, int row, int frame) {
        auto entity = reg.create();
        reg.emplace<Texture>(entity, tex, height, width, row, frame);
    }

    inline entt::entity createMap(entt::registry& reg, const std::string& map, const std::string& mapTex,TextureManager* texManager, int tileWidth, int tileHeight){

        /*
        std::ifstream file{map};
        std::string tileLocation;
        int x;
        int y;
        while(std::getline(file, tileLocation, ' ')){
            auto target = std::stoi(tileLocation);
            std::cout << target << std::endl;
            int counter {};
            for (int i = 0 ; i < 4 ; ++i){
                for (int j = 0; j < 5; ++j){
                    std::cout << "counter: " << counter << " target: " << target << std::endl;
                    if (counter == target){
                        x = i + 1;
                        y = j + 1;
                        break;
                    }
                    ++counter;
                }
                if (counter == target){
                    break;
                }
            }
            std::cout << "x | y : " << x << " | " << y << "\n";
        }
        */

        auto entity = reg.create();

        std::vector<Tile> tiles;

        for (int i = 0; i < 40; ++i){
            for (int j = 0 ; j < 30; ++j){
                Tile tile {texManager->getTexture(mapTex), {tileWidth * i,tileWidth * j}, 0,1};
                tiles.emplace_back(tile);
            }
        }

        reg.emplace<TileMap>(entity, tiles);

        return entity;
    }
}
#endif //TEST_CREATION_H
