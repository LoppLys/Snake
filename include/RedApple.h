#ifndef REDAPPLE_H
#define REDAPPLE_H

#include "Powerup.h"
namespace SpriteGame{

class RedApple : public Powerup{
public:
    RedApple(int x, int y, int w, int h);
    void draw();
    ~RedApple();
    //Impact on snake: Increase body by 1 unit

private:
    SDL_Surface* red_apple;
    SDL_Texture* texture;
}; 

}

#endif