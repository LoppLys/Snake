#include "Sprite.h"
#include "SnakeBody.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace SpriteGame {

    SnakeBody::SnakeBody(int x, int y, int w, int h): Snake(x,y,w,h){
            snake_body= IMG_Load("./resources/images/SnakeBody.png");
	        texture = SDL_CreateTextureFromSurface(sys.get_ren(),snake_body);
            
    }

    SnakeBody::~SnakeBody(){
        SDL_FreeSurface(snake_body);
	    SDL_DestroyTexture(texture);
    }

    void SnakeBody::draw(){
        std::cout << Snake::getDirection() << std::endl;
        SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
        switch (Snake::getDirection()){
		case 0: getRect().y--; break;
		case 1: getRect().y++; break;
		case 2: getRect().x--; break;
		case 3: getRect().x++; break;

	}
        
    }
  
}