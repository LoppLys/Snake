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
	//SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
	//std::cout << "draw " << direction << std::endl;
	SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
	if(!body.empty()){
		for(SnakeBody* b: body){
		switch (direction){
			case 0: 
			getRect().y-=speed; ;
			b->getRect().y = getRect().y;
			b->getRect().y += b->getRect().h - 7;
			b->getRect().x = getRect().x;
			b->draw();
		 	break;
			case 1: 
			getRect().y+=speed;
			b->getRect().y = getRect().y;
			b->getRect().y -= b->getRect().h -7;
			b->getRect().x = getRect().x;
			b->draw();
		 	break;
			case 2: 
			getRect().x-=speed;
			b->getRect().x = getRect().x;
			b->getRect().x += b->getRect().h -7;
			b->getRect().y = getRect().y;
			b->draw();
			break;
			case 3: 
			getRect().x+=speed; 
			b->getRect().x = getRect().x;
			b->getRect().x -= b->getRect().h -7;
			b->getRect().y = getRect().y;
			b->draw();
			break;
		}
	}
	}else{ //Needed this else statement because if not the snake did not move when all bodies were lost
		switch (direction){
			case 0: 
			getRect().y-=speed; ;
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
}

void Snake::addBodyPart(){
	SnakeBody * b = new SnakeBody(getRect().x,getRect().y,20,20);
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