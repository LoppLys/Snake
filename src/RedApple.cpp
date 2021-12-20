#include "RedApple.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Sprite.h"
namespace SpriteGame {

    RedApple::RedApple(int x, int y, int w, int h): Powerup(x,y,w,h){
            red_apple = IMG_Load("./resources/images/red_apple.png");
	        texture = SDL_CreateTextureFromSurface(sys.get_ren(),red_apple);
            
    }

    RedApple::~RedApple(){
        SDL_FreeSurface(red_apple);
	    SDL_DestroyTexture(texture);
    }

    void RedApple::draw(){
        SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
    }
  
}