#include "Sprite.h"
#include "Snake.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace SpriteGame {

Snake::Snake (int x, int y, int w, int h): Sprite(x,y,w,h){

    snake_head = IMG_Load("./resources/images/snake.jpg");
    
}







}