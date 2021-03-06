//
// Created by lasse on 11/16/17.
//
#include "rootEngine/System/GameEngine.h"
#include "jumpyBoy/enemy/FlyingEnemy.h"
#include "jumpyBoy/enemy/WalkingEnemy.h"
#include "jumpyBoy/player/Player.h"
#include "jumpyBoy/hud/HUD.h"
#include "jumpyBoy/player/KeyBindings.h"
#include "jumpyBoy/CollisionStrategies/PlayerCollBehavior.h"
#include "jumpyBoy/CollisionStrategies/GroundBehavior.h"
#include "jumpyBoy/CollisionStrategies/FlyingEnemyBehavior.h"
#include "jumpyBoy/enemy/EnemyFactory.h"
#include "jumpyBoy/player/PlayerFactory.h"
#include "jumpyBoy/LevelFactory/LevelFactory.h"
#include "rootEngine/sprite/TextInputSprite.h"

int main(int, char **) {
    auto* ge = rootengine::GameEngine::getInstance();
    typedef jumpyboy::LevelFactory getLvl;
    ge->addLvl(getLvl::firstLvl());
    ge->addLvl(getLvl::secondLvl());
    jumpyboy::Player *player = jumpyboy::PlayerFactory::player();
    ge->setHUD(jumpyboy::HUD::getInstance(player));
    jumpyboy::KeyBindings::bindKeybindings(ge, player);
    ge->setPlayer(player);
    ge->setFPS(60);
    auto* ti = rootengine::TextInputSprite::getInstance(300,200,500, 20, "Please enter name: ");
    ge->run();
    return 0;
}


