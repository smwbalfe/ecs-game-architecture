//
// Created by shriller44 on 9/22/22.
//

#include "Render.h"

Render::Render(SystemManager *sysMgr) : sysMgr_{sysMgr}{}

void Render::render(){

    auto view = sysMgr_->getScene()->getReg().view<Position, Texture>();

    for (auto [entity, position, texture]: view.each()){

        SDL_Rect srcRect;
        SDL_Rect destRect;
        srcRect.x = texture.width * texture.frame;
        srcRect.y = texture.height * (texture.row - 1);
        srcRect.w = destRect.w = texture.width;
        srcRect.h = destRect.h = texture.height;
        destRect.x = position.x;
        destRect.y = position.y;

        SDL_RenderCopy(sysMgr_->getContext()->renderer_, texture.texture.get(), &srcRect, &destRect);
    }
}

void Render::RenderMap(){
    auto viewMap = sysMgr_->getScene()->getReg().view<TileMap>();

    for (auto [entity, map]: viewMap.each()){
        for (auto& tile: map.tiles){
            SDL_Rect srcRect;
            SDL_Rect destRect;
            srcRect.x = 16 * tile.x;
            srcRect.y = 16 * (tile.y - 1);
            srcRect.w = destRect.w = 16;
            srcRect.h = destRect.h = 16;
            destRect.x = tile.position.x;
            destRect.y = tile.position.y;

            SDL_RenderCopy(sysMgr_->getContext()->renderer_, tile.texture.get(), &srcRect, &destRect);
        }
    }
}

void Render::update(float dt) {};

void Render::handleEvent(const EntityEvent& event) {}