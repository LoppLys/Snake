#include "Snake.h"
#include "Sprite.h"
#include "SnakeBody.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

namespace SpriteGame {

    SnakeBody::SnakeBody(int x, int y, int w, int h): Sprite(x,y,w,h, IMG_Load("./resources/images/SnakeBody.png")){
    
    }

    SnakeBody::~SnakeBody(){
        
    }    

    void SnakeBody::tick(){
    Sprite::draw();
    }

	void SnakeBody::follow(int x,int y, int i, int direction){ 
		tick();
		switch(direction){
				case 0: // Up
					getRect().y = y + (getRect().h * (i+1)) +getRect().h/2;
					getRect().x = x + 4;
		 			break;
				case 1: // down
					getRect().y = y - (getRect().h * (i+1));
					getRect().x = x + 4;
		 			break;
				case 2: // Left
                    getRect().x = x + (getRect().h * (i+1)) + getRect().h/2;
					getRect().y = y + 4;
					break;
				case 3: // Right
					getRect().x = x - (getRect().h * (i+1));
					getRect().y = y + 4;
					break;
					}
   /* void SnakeBody::follow(int x,int y, std::vector<SnakeBody *> body, std::size_t place, int direction){
		if(place < body.size()){
			body[place]->getRect().x = x;
			body[place]->getRect().y = y;
			body[place]->tick();
			switch (direction)
			{
			case 0: //up
				follow(getRect().x + 4, getRect().y + (getRect().h * (place+1)) + getRect().h/2, body, place + 1, direction);
				break;
			case 1: //down
				follow(getRect().x + 4, getRect().y - (getRect().h * (place+1)) + getRect().h/2, body,  place + 1, direction);
				break;
			case 2: //left
				follow(getRect().x + (getRect().h * (place+1)) + getRect().h/2, getRect().y + 4, body,  place + 1, direction);
				break;
			case 3:
				follow(getRect().x - (getRect().h * (place+1)), getRect().y + 4, body, place + 1, direction);
				break;
			default:
				break;
			}
		}*/
					
				
    }


  
}