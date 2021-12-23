#include "RedApple.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include "Sprite.h"
#include "Snake.h"
namespace SpriteGame {

    RedApple::RedApple(int x, int y, int w, int h): Powerup(x,y,w,h, "./resources/images/red_apple.png"){
        
    }

    RedApple::~RedApple(){
        
    }

    void RedApple::tick(){
        Powerup::tick();
    }

    void RedApple::draw(){
        Sprite::draw();
    }

  

    void RedApple::impact(Sprite *s){
        if(dynamic_cast<Snake*>(s)){
            //static_cast<Snake*>(s)
            ((Snake*) s)->addBodyPart();
        }
    }
  
}