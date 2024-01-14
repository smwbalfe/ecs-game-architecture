//
// Created by shriller44 on 9/18/22.
//

#ifndef TEST_TEXTUREMANAGER_H
#define TEST_TEXTUREMANAGER_H

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <memory>
#include <iostream>

struct SDL_Texture_Deleter {
    void operator()(SDL_Texture* surface) {
        SDL_DestroyTexture(surface);
    }
};

class TextureManager {

public:
    bool loadTexture(const std::string& filename, const std::string& texID, SDL_Renderer* pRenderer);

   std::shared_ptr<SDL_Texture>& getTexture(const std::string& texID);

private:
    std::map<std::string , std::shared_ptr<SDL_Texture>> textureMap_;
    std::map<int, SDL_Rect> test;
};

#endif //TEST_TEXTUREMANAGER_H
