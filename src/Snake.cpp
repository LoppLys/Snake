#include "Sprite.h"
#include "Snake.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "GreenApple.h"

namespace SpriteGame {

Snake::Snake (int x, int y, int w, int h): Sprite(x,y,w,h){ 

    snake_head = IMG_Load("./resources/images/left_snake.png");
	texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_head);
	direction = -1;
	addBodyPart();
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
	SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
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
	
	//s->collide();
	//GreenApple *g = static_cast<GreenApple*>(s);
	//GREEN APPLE: works
	//speed = 6;
	// 
	/* RED APPLE: (does not work)
	SnakeBody * b = new SnakeBody(getRect().x + 100, getRect().y + 100, 20, 20); //(vector.size()*20),(getRect().y + (vector.size()*20),20,20);
	addBodyPart(b);
	*/
	
	/* BOMB:
		body.clear(); // har inte kollat om den här fungerar eftersom att tilläggen av kroppsdel inte fungerar än
	*/
	/* ROTTEN APPLE:
		body.pop_back();
	*/

}


}