#include "Sprite.h"
#include "Snake.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace SpriteGame {

Snake::Snake (int x, int y, int w, int h): Sprite(x,y,w,h){ 

    snake_head = IMG_Load("./resources/images/Mindre_snake.png");
	texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_head);
	snakeRect = {0,0, snake_head->w, snake_head -> h};
    
}
Snake::~Snake(){
	SDL_FreeSurface(snake_head);
	SDL_DestroyTexture(texture);
}

Snake* Snake::getInstance(int x, int y, int w, int h) {
		return new Snake(x, y, w, h);
	}

void Snake::keyUp(){
	std::cout << "up key pushed"  << std::endl;
	snakeRect.y--;
}

void Snake::keyDown(){
	std::cout << "down key pushed"  << std::endl;
	snakeRect.y++;
}
void Snake::keyLeft(){
	std::cout << "left key pushed"  << std::endl;
	snakeRect.x--;
}

void Snake::keyRight(){
	std::cout << "right key pushed"  << std::endl;
	snakeRect.x++;
}

void Snake::draw() const{
	//SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
	SDL_RenderCopy(sys.get_ren(),texture,NULL, &snakeRect);
}

}