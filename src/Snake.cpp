#include "Sprite.h"
#include "Snake.h"
#include <SDL2/SDL.h>

namespace SpriteGame {

Snake::Snake (int x, int y, int w, int h): Sprite(x,y,w,h){

    snake_head = SDL_LoadBMP("./resources/images/snake.bmp");
    
}





}