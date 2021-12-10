#ifndef SNAKE_H
#define SNAKE_H

#include "Sprite.h"
#include <SDL2/SDL.h> 

namespace SpriteGame {

class Snake : public Sprite {
public:
static Snake* getInstance(int x, int y, int w, int h);
void keyUp();
void keyDown();
void keyLeft();
void keyRight();
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