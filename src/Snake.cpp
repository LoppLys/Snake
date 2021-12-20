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

void Snake::keyUp(){
	std::cout << "up key pushed"  << std::endl;
	if(direction != 1){
		direction = 0;
		snake_head = IMG_Load("./resources/images/up_snake.png");
		texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_head);
	}
	
	
}

void Snake::keyDown(){
	std::cout << "down key pushed"  << std::endl;
	if(direction != 0){
	direction = 1;
	snake_head = IMG_Load("./resources/images/down_snake.png");
	texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_head);
	}
	
	
	
}
void Snake::keyLeft(){
	std::cout << "left key pushed"  << std::endl;
	if(direction != 3){
	direction = 2;
	snake_head = IMG_Load("./resources/images/left_snake.png");
	texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_head);}
	
}

void Snake::keyRight(){
	std::cout << "right key pushed"  << std::endl;
	if(direction != 2){
	direction = 3;
	snake_head = IMG_Load("./resources/images/right_snake.png");
	texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_head);
	}
	
}

void Snake::draw(){
	//SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
	//std::cout << "draw " << direction << std::endl;
	SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
	for(SnakeBody* b: body){
	switch (direction){
		case 0: 
		getRect().y-- ;
		b->getRect().y = getRect().y;
		b->getRect().y += b->getRect().h - 7;
		b->getRect().x = getRect().x;
		b->draw();
		 break;
		case 1: 
		getRect().y++;
		b->getRect().y = getRect().y;
		b->getRect().y -= b->getRect().h -7;
		b->getRect().x = getRect().x;
		b->draw();
		 break;
		case 2: 
		getRect().x--;
		b->getRect().x = getRect().x;
		b->getRect().x += b->getRect().h -7;
		b->getRect().y = getRect().y;
		b->draw();
		break;
		case 3: 
		getRect().x++; 
		b->getRect().x = getRect().x;
		b->getRect().x -= b->getRect().h -7;
		b->getRect().y = getRect().y;
		b->draw();
		break;
	}
}
}

void Snake::addBodyPart(SnakeBody* bodyPart){
	body.push_back(bodyPart);
}



}