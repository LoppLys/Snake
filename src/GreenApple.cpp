#include "GreenApple.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Sprite.h"
#include "Snake.h"
namespace SpriteGame {

    GreenApple::GreenApple(int x, int y, int w, int h): Powerup(x,y,w,h, "./resources/images/green_apple.png"){
            
            
    }

    GreenApple::~GreenApple(){
    
    }

    void GreenApple::draw(){
        Sprite::draw();
    }

    void GreenApple::tick(){
        Powerup::tick();
    }

    void GreenApple::impact(Sprite * s){
        if(dynamic_cast<Snake*>(s)){
            ((Snake*) s)->setSpeed(4);
        }
    }
  
}