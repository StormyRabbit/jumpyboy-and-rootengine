//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PHYSICSSPRITE_H
#define PROG3_PHYSICSSPRITE_H

#include <SDL_image.h>
#include <vector>
#include <string>
#include <map>
#include "../collision/CollisionStrategy.h"
#include "Sprite.h"

namespace rootengine{
    typedef std::map<std::string, std::string> sMapType;
    typedef std::map<std::string, std::vector<SDL_Rect>> fMapType;
    class PhysicsSprite : public Sprite {
    public:
        void draw() const;
        void animatedTextureChange(std::string keyToMap);
        void setIsDrawable(bool draw);
        SDL_Rect getCurrentFrame();
        std::string getCurrentSprite();
        bool checkIfOnGround();
        void setResetHeight(int height);
        void setResetWidth(int width);
        void setCollisionStrategy(class CollisionStrategy* collStrategy);
        CollisionStrategy* getCollisionStrategy();
        virtual void tick();
        SDL_Point getNormalizedValue(int x, int y);
        int getResetHeight();
        void setOnGround(bool isOnGround);
        void setOnGroundBorder(bool isBorder);
        bool checkIfOnGroundBorder();
        bool getAlphaValue(int x, int y);
        ~PhysicsSprite() override;
    protected:
        PhysicsSprite(int xPos,int yPos,int width,int height, sMapType sprites, fMapType frames);
        int frame = 0;
    private:
        bool isDrawable = true;
        SDL_Surface *surface = nullptr;
        SDL_Texture* texture = nullptr;
        std::vector<SDL_Rect> framePositions;
        std::map<std::string, std::string> spriteMap;
        std::map<std::string, std::vector<SDL_Rect>> framesMap;
        CollisionStrategy* collStrategy = nullptr;
        std::string currentStateKey;
        int resetHeight;
        int resetWidth;
        bool onGround = false;
        void updateSize();
    };
}


#endif //PROG3_PHYSICSSPRITE_H
