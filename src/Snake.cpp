#include "Sprite.h"
#include "Snake.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "GreenApple.h"

namespace SpriteGame {

Snake::Snake (int x, int y, int w, int h): Sprite(x,y,w,h, IMG_Load("./resources/images/left_snake.png")){ 
	direction = -1;
	addBodyPart();
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

void Snake::draw(){ // tick() istället
	Sprite::draw();
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
	if(!body.empty()){
		for(int i = 0; i < (int)body.size(); i++){
			switch(direction){
				case 0: // Up
					body.at(i)->getRect().y = getRect().y + (body.at(i)->getRect().h * (i+1)) +body.at(i)->getRect().h/2;
					body.at(i)->getRect().x = getRect().x + 4;
					body.at(i)->draw();
		 			break;
				case 1: // down
					body.at(i)->getRect().y = getRect().y - (body.at(i)->getRect().h * (i+1));
					body.at(i)->getRect().x = getRect().x + 4;
					body.at(i)->draw();
		 			break;
				case 2: // Left
					body.at(i)->getRect().x = getRect().x + (body.at(i)->getRect().h * (i+1)) + body.at(i)->getRect().h/2;
					body.at(i)->getRect().y = getRect().y + 4;
					body.at(i)->draw();
					break;
				case 3: // Right
					body.at(i)->getRect().x = getRect().x - (body.at(i)->getRect().h * (i+1));
					body.at(i)->getRect().y = getRect().y + 4;
					body.at(i)->draw();
					break;
					}
				}
	}
}

void Snake::addBodyPart(){
	SnakeBody * b = new SnakeBody(getRect().x,getRect().y,12,12);
	body.push_back(b);
}

void Snake::collide(Sprite *s){
	if(dynamic_cast<Powerup*>(s)){
		s->impact(this);
	}
}


}