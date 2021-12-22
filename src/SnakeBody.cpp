#include "Snake.h"
#include "Sprite.h"
#include "SnakeBody.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace SpriteGame {

    SnakeBody::SnakeBody(int x, int y, int w, int h): Sprite(x,y,w,h, IMG_Load("./resources/images/SnakeBody.png")){
    
    }

    SnakeBody::~SnakeBody(){
        
    }



  
}