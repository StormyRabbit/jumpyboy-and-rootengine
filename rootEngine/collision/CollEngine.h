//
// Created by lasse on 12/29/17.
//

#ifndef PROG3_COLLENGINE_H
#define PROG3_COLLENGINE_H

#include "../sprite/PhysicsSprite.h"
#include <cmath>
namespace rootengine {
    class CollEngine {
    public:
        void playerCollision(PhysicsSprite *, std::vector<PhysicsSprite *> physObjects);
        void EnemyCollision(PhysicsSprite *, std::vector<PhysicsSprite *> physObjects);

        static CollEngine *getInstance();
    protected:
        CollEngine() = default;

    private:
        void handleCollision(PhysicsSprite *, PhysicsSprite *, SDL_Rect &);
        bool pixelCollition(PhysicsSprite *, PhysicsSprite *, SDL_Rect &);
        bool rectCollision(PhysicsSprite *aObject, PhysicsSprite *otherObject);
    };
}

#endif //PROG3_COLLENGINE_H
