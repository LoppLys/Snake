#include "RottenApple.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Sprite.h"
#include "Snake.h"
namespace SpriteGame {

    RottenApple::RottenApple(int x, int y, int w, int h): Powerup(x,y,w,h, "./resources/images/rotten_apple.png"){
            
            
    }

    RottenApple::~RottenApple(){
      
    }

    void RottenApple::draw(){
        Sprite::draw();
    }

    void RottenApple::tick(){
        Powerup::tick();
    }


    void RottenApple::impact(Sprite * s){
        if(dynamic_cast<Snake*>(s)){
            ((Snake*) s)->setSpeed(2);
            ((Snake*) s)->removeOneBodyPart();
        }
    }

}