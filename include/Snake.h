//Spelklass
#ifndef SNAKE_H
#define SNAKE_H

#include "Sprite.h"
#include <vector>
#include "SnakeBody.h"


namespace SpriteGame {

class Snake : public Sprite {
public:

void keyUp();
void keyDown();
void keyLeft();
void keyRight();
void draw(){};
void tick();
int collide(Sprite *s);
void impact(Sprite *){}
Snake(int x, int y, int w, int h);
void addBodyPart();
void setSpeed(int s){speed = s;}
void removeBody(){body.clear();}
void removeOneBodyPart();
~Snake(){};

private:
int speed = 2;
int direction = -1;
std::vector<SnakeBody *> body;


};

}

#endif