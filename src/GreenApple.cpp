#include "GreenApple.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Sprite.h"
#include "Snake.h"
namespace SpriteGame {

    GreenApple::GreenApple(int x, int y, int w, int h): Powerup(x,y,w,h){
            green_apple = IMG_Load("./resources/images/green_apple.png");
	        texture = SDL_CreateTextureFromSurface(sys.get_ren(),green_apple);
            
    }

    GreenApple::~GreenApple(){
        SDL_FreeSurface(green_apple);
	    SDL_DestroyTexture(texture);
    }

    void GreenApple::draw(){
        SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
    }

    void GreenApple::impact(Sprite * s){
        if(dynamic_cast<Snake*>(s)){
            //static_cast<Snake*>(s)
            ((Snake*) s)->setSpeed(4);
        }
    }
  
}