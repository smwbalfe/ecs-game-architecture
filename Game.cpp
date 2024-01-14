//
// Created by shriller44 on 9/18/22.
//

#include "Game.h"

Game::Game(): currentScene_{nullptr}, context_{ new GameContext{}} {}

bool Game::init(std::unique_ptr<MainScene> main_scene, const std::string& windowName, int xPos, int yPos, int width, int height){

    bool returnStatus { false };

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "init successful" << std::endl;
        auto window_flags = static_cast<SDL_WindowFlags>((SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI));
        window_ = std::unique_ptr<SDL_Window,SDLWindowDestroyer>(SDL_CreateWindow(windowName.c_str(), xPos, yPos, width, height, window_flags));
        window_dims_ = WindowDimensions {.height_ = height, .width_ = width};
        if (window_ != nullptr){
            renderer_ = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(window_.get(), -1, 0) , [](SDL_Renderer* renderer){SDL_DestroyRenderer(renderer);});
            if (renderer_ != nullptr){
                std::cout << "renderer creation success\n";
                std::cout << "init success\n";
                running_ = true;
                currentScene_ = main_scene;
                context_->textureManager_ = std::make_unique<TextureManager>();
                context_->renderer_ = renderer_;
                context_->systemManager_ = std::unique_ptr<SystemManager, GameContext::sys_dtor>(new SystemManager {currentScene_, context_});
                return true;
            }
            else {std::cout << "renderer init failed\n";}
        } else {std::cout << "window init failed\n";}
    } else {std::cout << "sdl init failed\n";}
    return false;
}

void Game::Render(){
    SDL_RenderClear(renderer_.get());
    currentScene_->draw();
    SDL_RenderPresent(renderer_.get());
}

void Game::Update(){
    Uint32 time = SDL_GetTicks();
    float dt = static_cast<float>(time-lastUpdate) / 1000.0f;
    elapsedTime += dt;
    while(elapsedTime > TARGET_RATE){
        elapsedTime -= TARGET_RATE;
        currentScene_->update(dt);
    }
    lastUpdate = time;
}

[[nodiscard]] bool Game::isRunning() const { return running_; }


const TextureManager& Game::GetTextureManager() const {
    return *context_->textureManager_;
}



void Game::processEvents(){
    SDL_Event event;
    if (SDL_PollEvent(&event)){
        switch(event.type) {
            case SDL_QUIT: {
                std::cout << "quitting" << std::endl;
                SDL_Quit();
            }
        }
    }
}

Game::~Game(){
    SDL_Quit();
}