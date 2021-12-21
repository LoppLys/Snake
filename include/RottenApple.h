#ifndef ROTTENAPPLE_H
#define ROTTENAPPLE_H
#include "Powerup.h"

namespace SpriteGame{

class RottenApple : public Powerup{
public:
    RottenApple(int x, int y, int w, int h);
    void draw();
    void impact(Sprite *);
    ~RottenApple();
    //Impact on snake: Decrease body by 1 unit

private:
    SDL_Surface* rotten_apple;
    SDL_Texture* texture;

};

}

#endif