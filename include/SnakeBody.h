#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "Sprite.h"
#include <SDL2/SDL.h> 

namespace SpriteGame {

class SnakeBody : public Sprite {
friend class Snake;
public:
void keyUp(){};
void keyDown(){};
void keyLeft(){};
void keyRight(){};
void collide(){};
void impact(Sprite *){}
SnakeBody(int x, int y, int h, int w);
~SnakeBody();
void draw();

private:
SDL_Surface* snake_body;
SDL_Texture* texture;

};

}

#endif