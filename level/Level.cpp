//
// Created by lasse on 11/24/17.
//

#include <iostream>
#include "Level.h"
namespace rootengine {
    Level::Level(std::vector<EnvironmentSprite *> &collEnvironment, std::vector<EnvironmentSprite *> &nonCollEnvironment,
                 std::vector<Enemy *> &enemyCollection) {
        Level::collEnvironment = collEnvironment;
        Level::nonCollEnvironment = nonCollEnvironment;
        Level::enemyCollection = enemyCollection;
    }


    void Level::updateEnemies() {
        for(Enemy* enemy : enemyCollection) {}
    }

    bool Level::isLevelComplete() {
        for(Enemy* enemy : enemyCollection) {
            bool alive;
            if(!alive) {
                return false;
            }
        }
        return true;
    }

    void Level::drawLevel() {
        if(background != nullptr)
            background->draw();

        for(EnvironmentSprite* es : nonCollEnvironment)
            es->draw();
        for(EnvironmentSprite* es : collEnvironment)
            es->draw();

        for(Enemy* enemy : enemyCollection) {
            // enemy->draw();
        }
    }

    Level *Level::getInstance(std::vector<EnvironmentSprite *> &collEnvironment,
                              std::vector<EnvironmentSprite *> &nonCollEnvironment,
                              std::vector<Enemy *> &enemyCollection) {
        return new Level(collEnvironment, nonCollEnvironment, enemyCollection);
    }

    Level::Level(std::vector<EnvironmentSprite *> &collEnvironment,
                 std::vector<EnvironmentSprite *> &nonCollEnvironment) {
        Level::collEnvironment = collEnvironment;
        Level::nonCollEnvironment = nonCollEnvironment;
    }

    Level *Level::getEnemeyFreeLevel(std::vector<EnvironmentSprite *> &collEnvironment,
                                     std::vector<EnvironmentSprite *> &nonCollEnvironment) {
        return new Level(collEnvironment, nonCollEnvironment);
    }

    void Level::setBackGround(EnvironmentSprite *bgSprite) {
        background = bgSprite;
    }

    Level::~Level() {
        for(EnvironmentSprite *es : collEnvironment)
            delete es;
        for(EnvironmentSprite *es : nonCollEnvironment)
            delete es;
        for(Enemy *enemy : enemyCollection)
            delete enemy;
        delete background;
    }
}