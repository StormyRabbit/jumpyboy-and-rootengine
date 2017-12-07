//
// Created by lasse on 11/24/17.
//

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <sstream>
#include "GameEngine.h"
#include "System.h"
#include "Timer.h"

namespace rootengine {

    GameEngine::~GameEngine() {
        delete player;
        delete activeWorld;
        delete lvlMgr;
        delete hud;
    }

    void GameEngine::setLvlMgr(LevelManager *lvlMgr) {
        GameEngine::lvlMgr = lvlMgr;
    }

    void GameEngine::setHUD(HUD *hud) {
        GameEngine::hud = hud;
    }

    void GameEngine::run() {
        std::string IMG_PATH = "assets/sprites/bg_castle.png";
        SDL_Texture *bgImg = IMG_LoadTexture(sys.getRenderer(), IMG_PATH.c_str());

        SDL_RenderCopy(sys.getRenderer(), bgImg, nullptr, nullptr);
        Sprite* bottom = EnvironmentSprite::getInstance(0, 500, 1200, 100, "assets/sprites/Tiles/grassMid.png");
        Timer* fpsTimer = Timer::getInstance();
        Timer* capTimer = Timer::getInstance();
        HUDSprite* fpsCounter = HUDSprite::getInstance(0,0,150,20, "FPS");
        int countedFrames = 0;
        fpsTimer->start();
        std::stringstream fpsText;
        while (running) {
            capTimer->start();
            SDL_RenderClear(sys.getRenderer());
            SDL_RenderCopy(sys.getRenderer(), bgImg, nullptr, nullptr);
            activeWorld->drawWorld();
            hud->draw();
            bottom->draw();
            SDL_Event event;
            player->checkState();

            /* För varje varv i loopen, efter att ha kontrollerat om det finns några
             * användargenererade händelser och i så fall ha tagit hand om dem, ska man gå igenom alla installerade
             * Sprite-objekt och anropa en medlemsfunktion (ofta kallas en sådan medlemsfunktion tick)
             * som uppdaterar deras tillstånd (t.ex. ändrar positionen om objektet rör sig o.s.v.).
             * Denna metod bör ta som argument något som ger Sprite-objekten åtkomst till omvärlden, så att de kan
             * interagera med omvärlden (t.ex. samligen av andra Sprite-objekt eller själva GameEngine-objektet).
             * Det är meningen att tillämpningar (de specifika spelen) ska kunna överskugga
             * denna medlemsfunktion i sina egna subklasser till Sprite eller dess subklasser. */
            while (SDL_PollEvent(&event)) {
                if(event.type)
                    switch (event.type) {
                        case SDL_QUIT:
                            running = false;
                            break;
                        default: // OM SPELAREVENT
                            activeWorld->executeEvent(event);
                    } // switch end
            } // while Poll
            // TODO: MAKE WORK
            float avgFPS = countedFrames / (fpsTimer->getTicks() / 1000.f);
            fpsText.str("");
            fpsText << "AVG FPS: " << avgFPS;
            std::string fpsString = fpsText.str().c_str();
            fpsCounter->setText(fpsString);
            fpsCounter->draw();
            ++countedFrames;
            int frameTicks = capTimer->getTicks();
            if( frameTicks < tickRate) {
                SDL_Delay( tickRate - frameTicks); // TODO: updatera till Uint32
            }
            SDL_RenderPresent(sys.getRenderer());
        } // while running
    }

    void GameEngine::setPlayer(Player *player) {
        GameEngine::player = player; // TODO: remove när world->draw är implementerat
        activeWorld->setPlayer(player);
    }

    GameEngine *GameEngine::getInstance() {
        return new GameEngine();
    }

    void GameEngine::createWorld() {
        activeWorld = World::getInstance();
    }

    void GameEngine::setFPS(int fps, int ticksPerFrame) {
        screenFPS = fps;
        tickRate = ticksPerFrame / fps;
    }
}
/* ObserverPattern */



