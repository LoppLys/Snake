//Spelklass
#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "Sprite.h"

namespace SpriteGame {

class SnakeBody : public Sprite {

public:
void keyUp(){};
void keyDown(){};
void keyLeft(){};
void keyRight(){};
void collide(){};
void impact(Sprite *){}
SnakeBody(int x, int y, int h, int w);
~SnakeBody();


private:

};

}

#endif