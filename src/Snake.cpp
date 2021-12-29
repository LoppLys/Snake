#include "Sprite.h"
#include "Snake.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "GreenApple.h"

namespace SpriteGame {

Snake::Snake (int x, int y, int w, int h): Sprite(x,y,w,h, IMG_Load("./resources/images/left_snake.png")){ 

}

Snake::~Snake(){}

void Snake::keyUp(){
	std::cout << "up key pushed"  << std::endl;
	if(direction != 1){
		direction = 0;
		setSurface(IMG_Load("./resources/images/up_snake.png"));
		setTexture(getSurface());
	}
	
	
}

void Snake::keyDown(){
	std::cout << "down key pushed"  << std::endl;
	if(direction != 0){
	direction = 1;
	setSurface(IMG_Load("./resources/images/down_snake.png"));
	setTexture(getSurface());
	}
	
	
	
}
void Snake::keyLeft(){
	std::cout << "left key pushed"  << std::endl;
	if(direction != 3){
	direction = 2;
	setSurface(IMG_Load("./resources/images/left_snake.png"));
	setTexture(getSurface());
	}
}

void Snake::keyRight(){
	std::cout << "right key pushed"  << std::endl;
	if(direction != 2){
	direction = 3;
	setSurface(IMG_Load("./resources/images/right_snake.png"));
	setTexture(getSurface());
	}
	
}

void Snake::tick(){ // tick() istället
	Sprite::draw();
	for(std::size_t i = 0; i != body.size();i++){
			body[i]->follow(getRect().x,getRect().y,i, direction);
			
		}
	switch (direction){
			case 0: 
			getRect().y-=speed; 
		 	break;
			case 1: 
			getRect().y+=speed;
		 	break;
			case 2: 
			getRect().x-=speed;
			break;
			case 3: 
			getRect().x+=speed; 
			break;
		}
		
}


void Snake::addBodyPart(){
	if(!body.empty()){
	SnakeBody * b = new SnakeBody(body.back()->getRect().x+12,body.back()->getRect().y+12,12,12);
	body.push_back(b);}
	else{
	SnakeBody * b = new SnakeBody(getRect().x+12,getRect().y+12,12,12);
	body.push_back(b);
	}
	
}

void Snake::collide(Sprite *s){
	if(dynamic_cast<Powerup*>(s)){
		s->impact(this);
	}
}

void Snake::removeOneBodyPart(){
	if(!body.empty()){
		body.pop_back();
	}
}


}