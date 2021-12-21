#ifndef GREENAPPLE_H
#define GREENAPPLE_H

#include "Powerup.h"

namespace SpriteGame{

class GreenApple : public Powerup{
public:
    GreenApple(int x, int y, int w, int h);
    void draw();
    void impact(Sprite *);
    ~GreenApple();

    //Impact on snake: Increase speed - for a short period of time
private:
    SDL_Surface* green_apple;
    SDL_Texture* texture;

};

}

#endif