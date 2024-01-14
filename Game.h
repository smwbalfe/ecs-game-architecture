//
// Created by shriller44 on 9/18/22.
//

#ifndef TEST_GAME_H
#define TEST_GAME_H

#include <map>

#include <SDL2/SDL.h>
#include "ResourceManagers/TextureManager.h"
#include "GameContext.h"
#include "Scenes/MainScene.h"

inline constexpr float TARGET_RATE = 1/60.0f;

class Game {
public:

    struct SDLRendererDestroyer
    {
        void operator()(SDL_Renderer * w) const
        {
            SDL_DestroyRenderer(w);
        }
    };

    struct SDLWindowDestroyer
    {
        void operator()(SDL_Window * w) const
        {
            SDL_DestroyWindow(w);
        }
    };

    struct WindowDimensions {
        int32_t height_;
        int32_t width_;
    };

    Game();

    bool init(MainScene* s, std::string_view windowName, int xPos, int yPos, int width, int height);

    void Render();

    void Update();

    ~Game();

    static void processEvents();
    [[nodiscard]] bool isRunning() const;
    const TextureManager& GetTextureManager() const;
    const SDL_Renderer& GetRenderer() const;

private:
    WindowDimensions window_dims_;
    std::unique_ptr<GameContext>  context_;
    std::unique_ptr<MainScene> currentScene_;
    std::unique_ptr<SDL_Window, SDLWindowDestroyer> window_;
    std::shared_ptr<SDL_Renderer> renderer_{};
    bool running_;
    uint32_t lastUpdate;
    float elapsedTime;
};


#endif //TEST_GAME_H
