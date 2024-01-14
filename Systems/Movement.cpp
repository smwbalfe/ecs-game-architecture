//
// Created by shriller44 on 9/22/22.
//

#include "Movement.h"

Movement::Movement(SystemManager* sysMgr): sysMgr_{sysMgr}{};

void Movement::update(float dt){ }

void Movement::handleEvent(const EntityEvent& event)  {
    auto view = sysMgr_->getScene()->getReg().view<Position>();
    for (auto [entity, position]: view.each()) {
        switch (event) {
            case EntityEvent::MOVE_LEFT:
                position.x -= 1;
                break;
            case EntityEvent::MOVE_RIGHT:
                position.x += 1;
                break;
            case EntityEvent::MOVE_UP:
                position.y -= 1;
                break;
            case EntityEvent::MOVE_DOWN:
                position.y += 1;
                break;
        }
    }
}
