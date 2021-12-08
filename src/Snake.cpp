#include "Sprite.h"
#include "Snake.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace SpriteGame {

Snake::Snake (int x, int y, int w, int h): Sprite(x,y,w,h){

    snake_head = IMG_Load("./resources/images/snake.jpg");
    
}
Snake::~Snake(){
	SDL_FreeSurface(snake_head);
}

Snake* Snake::getInstance(int x, int y, int w, int h) {
		return new Snake(x, y, w, h);
	}

void Snake::keyUp(int x, int y){
	std::cout << "up key pushed"  << std::endl;
}
void Snake::keyDown(int x, int y){
	std::cout << "down key pushed"  << std::endl;
}
void Snake::keyLeft(int x, int y){
	std::cout << "left key pushed"  << std::endl;
}
void Snake::keyRight(int x, int y){
	std::cout << "right key pushed"  << std::endl;
}
void Snake::draw() const{
	std::cout << "draw function"  << std::endl;
}

}