#include "Bomb.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Sprite.h"
#include "Snake.h"
namespace SpriteGame {

    Bomb::Bomb(int x, int y, int w, int h): Powerup(x,y,w,h, "./resources/images/bomb.png"){
           
            
    }

    Bomb::~Bomb(){
        
    }

    void Bomb::draw(){
        Sprite::draw();
    }

    void Bomb::impact(Sprite * s){
        if(dynamic_cast<Snake*>(s)){
            //static_cast<Snake*>(s)
            ((Snake*) s)->removeBody();
        }
    }
  


}