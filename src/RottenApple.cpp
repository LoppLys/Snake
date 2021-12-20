#include "RottenApple.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Sprite.h"
namespace SpriteGame {

    RottenApple::RottenApple(int x, int y, int w, int h): Powerup(x,y,w,h){
            rotten_apple = IMG_Load("./resources/images/rotten_apple.png");
	        texture = SDL_CreateTextureFromSurface(sys.get_ren(),rotten_apple);
            
    }

    RottenApple::~RottenApple(){
        SDL_FreeSurface(rotten_apple);
	    SDL_DestroyTexture(texture);
    }

    void RottenApple::draw(){
        SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
    }
  
}