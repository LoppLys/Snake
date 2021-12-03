//#ifndef SNAKE_H
//#define SNAKE_H

#include "Sprite.h"
#include <SDL2/SDL.h>

namespace SpriteGame {

class Snake : public Sprite {
public:
void keyUp(int x, int y);
void keyDown(int x, int y);
void keyLeft(int x, int y);
void keyRight(int x, int y);
Snake(int x, int y, int w, int h) : Sprite  (x, y, w, h){}
SDL_Surface* snake_head;

private:



};

}

//#endif