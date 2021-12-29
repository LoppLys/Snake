//Spelklass
#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "Sprite.h"
#include <vector>

namespace SpriteGame {

class SnakeBody : public Sprite {

public:
void keyUp(){};
void keyDown(){};
void keyLeft(){};
void keyRight(){};
void collide(){};
void tick();
void impact(Sprite *){}
void follow(int,int, int,int);
//void follow(int,int, std::vector<SnakeBody*>, std::size_t, int);
SnakeBody(int x, int y, int h, int w);
~SnakeBody();


private:
int direction = -1;
int speed = 1;
};

}

#endif