#ifndef BOMB_H
#define BOMB_H
#include "Powerup.h"

namespace SpriteGame{

class Bomb : public Powerup{
public:
    Bomb(int x, int y, int w, int h);
    void draw(){};
    void impact(Sprite *);
    void tick();
    ~Bomb();
    void collide(){};
    

private:

};
}


#endif