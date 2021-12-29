//Spelklass
#ifndef SNAKE_H
#define SNAKE_H

#include "Sprite.h"
#include <SDL2/SDL.h> 
#include <vector>
#include "SnakeBody.h"


namespace SpriteGame {

class Snake : public Sprite {
public:
//static Snake* getInstance(int x, int y, int w, int h);

void keyUp();
void keyDown();
void keyLeft();
void keyRight();
void draw(){};
void tick();
void collide(Sprite *s);
void impact(Sprite *){}
Snake(int x, int y, int w, int h);
void addBodyPart();
//SDL_Surface* getSnake(){return snake_head;}
//SDL_Surface* getSurface(){return snake_head;} //Den här används nog inte
void setSpeed(int s){speed = s;}
int getSpeed(){return speed;}
int getSize(){return body.size();}
void removeBody(){body.clear();}
void removeOneBodyPart(){body.pop_back();}
int& getDirection(){return direction;}
~Snake();

//protected:
private:
int speed = 1;
int direction = -1;
std::vector<SnakeBody *> body;


};

}

#endif