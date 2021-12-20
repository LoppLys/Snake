#ifndef BOMB_H
#define BOMB_H
#include "Powerup.h"

namespace SpriteGame{

class Bomb : public Powerup{
public:
    Bomb(int x, int y, int w, int h);
    void draw();
    ~Bomb();
    //Impact on snake: Decrease body by half

private:
    SDL_Surface* bomb;
    SDL_Texture* texture;
};
}


#endif