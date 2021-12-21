#include "Bomb.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Sprite.h"
#include "Snake.h"
namespace SpriteGame {

    Bomb::Bomb(int x, int y, int w, int h): Powerup(x,y,w,h){
            bomb = IMG_Load("./resources/images/bomb.png");
	        texture = SDL_CreateTextureFromSurface(sys.get_ren(),bomb);
            
    }

    Bomb::~Bomb(){
        SDL_FreeSurface(bomb);
	    SDL_DestroyTexture(texture);
    }

    void Bomb::draw(){
        SDL_RenderCopy(sys.get_ren(),texture,NULL, &getRect());
    }

    void Bomb::impact(Sprite * s){
        if(dynamic_cast<Snake*>(s)){
            //static_cast<Snake*>(s)
            ((Snake*) s)->removeBody();
        }
    }
  


}