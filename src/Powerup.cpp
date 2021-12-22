#include <SDL2/SDL.h>
#include <iostream>
#include "Sprite.h"
#include "Powerup.h"
#include "RedApple.h"
#include "Snake.h"
#include "Bomb.h"
#include "System.h"
#include "GreenApple.h"


#define FPS 80
namespace SpriteGame {
    Powerup::Powerup(int x, int y, int w, int h, std::string imageLocation): Sprite(x, y, w, h, IMG_Load(imageLocation.c_str())){
        //imageLocation.c_str()
    }

   /* void Powerup::add(int start_x, int start_y){
        Powerup* r = new GreenApple(start_x, start_y,20,20);
        
    }
    */

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

    void Powerup::draw(){
        Sprite::draw();
    }

   /* void Powerup::collide(Sprite *s){
        //std::cout << "hej" << std::endl;
        //Snake::speed = 6;
        //SDL_RenderClear(sys.get_ren());
        //new Powerup(30, 30, 20, 20);
        
    }
    */
    
  
}