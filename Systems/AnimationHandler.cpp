//
// Created by shriller44 on 9/23/22.
//

#include "AnimationHandler.h"

Animation::Animation(SystemManager *sysMgr) : sysMgr_{sysMgr}{}

void Animation::update(float dt) {
    df += dt * 10.0f;
    auto view = sysMgr_->getScene()->getReg().view<Texture>();
    for (auto [entity, texture]: view.each()){
        texture.frame = int(df) % 7;
    }
};

void Animation::handleEvent(const EntityEvent& event){}