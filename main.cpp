//
// Created by shriller44 on 9/29/22.
//

#include "Game.h"
#include "Scenes/MainScene.h"
#include "EntityTags.h"
#include "Components/Network.h"

int main(){

    int x = 2;
    int& x_alias = x;
    int& y = x_alias;
    x_alias = &y;
    // Create a game object
    auto game = std::make_unique<Game>();
    auto s1 = std::make_unique<MainScene>("test", game->getContext());

    if(game->init(s1.get(), "windowname", 50, 50, 640, 480)){

        auto& texManager = game->GetTextureManager();

        texManager.loadTexture("../assets/spelunky_shop.png", "map", game->getContext()->renderer_);
        texManager.loadTexture("../assets/anim.png", "player", game->getContext()->renderer_);

        s1->createEntity<Map>("../assets/map.txt", "map",texManager , 16,16);
        s1->createEntity<Player>(50, 50, 64, 64, texManager->getTexture("player"));
        s1->createEntity<Player>(300, 300, 64,64, texManager->getTexture("player"));

        while (game->isRunning()){
            Game::processEvents();

            game->Update();
            game->Render();
        }
    }

}