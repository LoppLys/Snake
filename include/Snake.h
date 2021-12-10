#ifndef SNAKE_H
#define SNAKE_H

#include "Sprite.h"
#include <SDL2/SDL.h>

namespace SpriteGame {

class Snake : public Sprite {
public:
static Snake* getInstance(int x, int y, int w, int h);
void keyUp(int x, int y);
void keyDown(int x, int y);
void keyLeft(int x, int y);
void keyRight(int x, int y);
void draw() const;
SDL_Surface* getSurface(){return snake_head;}
~Snake();
protected:
Snake(int x, int y, int w, int h);
private:
SDL_Surface* snake_head;
SDL_Texture* texture;


};

}

#endif