#include <SDL2/SDL.h>
#include <iostream>
#include "Sprite.h"
#include "Powerup.h"
#include "RedApple.h"
#include "Snake.h"
#include "Bomb.h"
#include "System.h"
#include "GreenApple.h"
#include"RottenApple.h"


#define FPS 80
namespace SpriteGame {
    Powerup::Powerup(int x, int y, int w, int h, std::string imageLocation): Sprite(x, y, w, h, IMG_Load(imageLocation.c_str())){

    }

    void Powerup::tick(){
         Sprite::draw();
		counter++;
		if (getRect().x >= 600 || getRect().x < 0){
            setActive();
        }
		else if (counter % 10 == 0){

			getRect().x+= 4;//hastighet
        }
    }

    Sprite* Powerup::add(int x, int y, int s){
        Powerup* r; 
        
        switch (s){
			case 0: 
			 r = new GreenApple(x, y, 20, 20);
		 	break;
			case 1: 
            case 2:
             r = new RedApple(x, y, 20, 20);
		 	break;
			case 3: 
			 r = new Bomb(x, y, 20, 20);
			break;
			case 4: 
			 r = new RottenApple(x, y, 20, 20);
			break;
		}
        return r;
    }
    
    
}