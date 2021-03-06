//
// Created by lasse on 11/28/17.
//

#include "System.h"
namespace rootengine {
    SDL_Renderer *System::getRenderer() const {
        return ren;
    }

    TTF_Font* System::getFont() const {
        return mainFont;
    }

    System::System() {
        System::init();
        System::createWindow(1200, 600, "Root engine testing");
        System::createRenderer();
        System::createFont("assets/fonts/Roboto-Regular.ttf", 50);
    }

    System::~System() {
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }

    void System::init() {
        if (SDL_Init(SDL_INIT_VIDEO) == -1) {
            std::cerr << "SDL_init-fel" << SDL_GetError() << std::endl;
            exit(-1);
        }
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags)) {
            std::cerr << "SDL_imig_init-fel:" << SDL_GetError() << std::endl;
            exit(-1);
        }
        if (TTF_Init() == -1) {
            std::cerr << "SDL_TTF err:" << SDL_GetError() << std::endl;
            exit(-1);
        }
    }

    void System::createWindow(int width, int height, std::string name) {
        win = SDL_CreateWindow(name.c_str(),
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               width, height, SDL_WINDOW_SHOWN);
        if (win == nullptr) {
            std::cerr << "window error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            exit(-1);
        }
    }

    void System::createFont(std::string path, int size) {
        mainFont = TTF_OpenFont(path.c_str(), size);
    }

    void System::createRenderer() {
        ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
        if (ren == nullptr) {
            std::cerr << "render error: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(win);
            SDL_Quit();
            exit(-1);
        }
    }
    System sys;
}
