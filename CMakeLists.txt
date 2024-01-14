cmake_minimum_required(VERSION 3.23)
project(test)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

message(STATUS "foo include dir: ${SDL2_INCLUDE_DIRS})")

add_executable(test Scenes/MainScene.cpp Scenes/MainScene.h Components/Position.h Game.cpp Game.h ResourceManagers/TextureManager.cpp ResourceManagers/TextureManager.h Components/Texture.h Components/PlayerType.h factory/creation.h Systems/System.cpp Systems/System.h Systems/Movement.cpp Systems/Movement.h Systems/SystemManager.cpp Systems/SystemManager.h constants/EntityEvents.h Systems/Render.cpp Systems/Render.h Systems/AnimationHandler.cpp Systems/AnimationHandler.h Scenes/Scene.cpp Scenes/Scene.h include.h GameContext.cpp Components/TileMap.h main.cpp EntityTags.h Components/Network.h )

target_include_directories(test PUBLIC /home/shriller44/dev/cpp/sdks/entt/src ./)
target_link_libraries(test ${SDL2_LIBRARIES} SDL2_image)
