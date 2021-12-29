#include "Sprite.h" 
#include <iostream>
#include <SDL2/SDL.h>



namespace SpriteGame{

    Sprite::Sprite(int x, int y, int w, int h, SDL_Surface* surface) :rect{x, y, w, h}, surface(surface){
       // texture = SDL_CreateTextureFromSurface(sys.get_ren(), surface);
        
    }

    Sprite::~Sprite(){
      SDL_FreeSurface(surface);
	    SDL_DestroyTexture(texture);
    }
    
    void Sprite::removeSprite(Sprite* s){
      
    }

    void Sprite::draw(){
     SDL_RenderCopy(sys.get_ren(),texture, NULL, &getRect());
     
    }

    
}