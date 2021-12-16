#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "Snake.h"
#include <SDL2/SDL.h> 

namespace SpriteGame {

class SnakeBody : public Snake {

public:
SnakeBody(int x, int y, int h, int w);
~SnakeBody();
void draw();

private:
SDL_Surface* snake_body;
SDL_Texture* texture;

};

}

#endif