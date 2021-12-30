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
            removeSprite(this);
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
    
    

        /*
        int x = 90, y = 90;
        Powerup* r;
        r->onScreen = false;
        while(!r->onScreen){
            Uint32 tickInterval = 1000 / FPS;
            Uint32 nextTick = SDL_GetTicks() + tickInterval;
            r = new RedApple(x, y, 20, 20);
            r->draw();
            x += 20;
            y += 15;
            int delay = nextTick - SDL_GetTicks();
            if(delay > 0){
                SDL_Delay(delay);
            }
            r->onScreen = true;
        }
        */
    

    Powerup::~Powerup(){
        
    }

}