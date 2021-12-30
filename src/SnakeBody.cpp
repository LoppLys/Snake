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

    }


  
}