#include "Sprite.h"
#include "Snake.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace SpriteGame {

Snake::Snake (int x, int y, int w, int h): Sprite(x,y,w,h){ 

    snake_head = IMG_Load("./resources/images/left_snake.png");
	texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_head);
	direction = -1;
	SnakeBody * b = new SnakeBody(x,y,w,h);
	addBodyPart(b);

}

Snake::~Snake(){
	SDL_FreeSurface(snake_head);
	SDL_DestroyTexture(texture);
}

/*Snake* Snake::getInstance(int x, int y, int w, int h) {
		return new Snake(x, y, w, h);
	}*/

void Snake::keyUp(){
	std::cout << "up key pushed"  << std::endl;
	snake_head = IMG_Load("./resources/images/up_snake.png");
	texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_head);
	direction = 4;
}

void Snake::keyDown(){
	std::cout << "down key pushed"  << std::endl;
	snake_head = IMG_Load("./resources/images/down_snake.png");
	texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_head);
	direction = 1;
}
void Snake::keyLeft(){
	std::cout << "left key pushed"  << std::endl;
	snake_head = IMG_Load("./resources/images/left_snake.png");
	texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_head);
	direction = 2;
}

void Snake::keyRight(){
	std::cout << "right key pushed"  << std::endl;
	snake_head = IMG_Load("./resources/images/right_snake.png");
	texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_head);
	direction = 3;
	
}

/*int Snake::getDirection(){
	std::cout << "getDirection  " << direction << std::endl;
	return *direction;
}*/

void Snake::draw(){
	//SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
	std::cout << "draw " << direction << std::endl;
	SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
	switch (direction){
		case 4: getRect().y--; break;
		case 1: getRect().y++; break;
		case 2: getRect().x--; break;
		case 3: getRect().x++; break;
	}
}

void Snake::addBodyPart(SnakeBody* bodyPart){
	body.push_back(bodyPart);
}

}