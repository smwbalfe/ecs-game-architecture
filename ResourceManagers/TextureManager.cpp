//
// Created by shriller44 on 9/18/22.
//

#include "TextureManager.h"

bool TextureManager::loadTexture(const std::string &filename, const std::string &texID, SDL_Renderer *pRenderer) {
    SDL_Surface* pTempSurface = IMG_Load(filename.c_str());


    if (pTempSurface == nullptr) { return false; }

    std::shared_ptr<SDL_Texture> pTexture(SDL_CreateTextureFromSurface(pRenderer, pTempSurface), SDL_Texture_Deleter{});

    SDL_FreeSurface(pTempSurface);

    if (pTexture != nullptr){
        textureMap_[texID] = std::move(pTexture);
        return true;
    }

    std::cout << "texture failed to load" << std::endl;
    return false;
}

std::shared_ptr<SDL_Texture>& TextureManager::getTexture(const std::string& texID) { return textureMap_[texID]; }