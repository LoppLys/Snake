#ifndef ROTTENAPPLE_H
#define ROTTENAPPLE_H
#include "Powerup.h"

namespace SpriteGame{

class RottenApple : public Powerup{
public:
    RottenApple(int x, int y, int w, int h);
    void draw();
    void impact(Sprite *);
    void tick(){}
    ~RottenApple();
    //Impact on snake: Decrease body by 1 unit

private:
 

};

}

#endif