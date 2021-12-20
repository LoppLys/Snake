#include <SDL2/SDL.h>
#include <iostream>
#include "Sprite.h"
#include "Powerup.h"
#include "RedApple.h"
#include "Snake.h"
#include "Bomb.h"


#define FPS 80
namespace SpriteGame {
    //Powerup::Powerup(int x, int y, int w, int h, int p_time) : Sprite(x, y, w, h), popup_time(p_time){
    Powerup::Powerup(int x, int y, int w, int h) : Sprite(x, y, w, h){
        
    }

   /* void Powerup::add(int start_x, int start_y){
        Powerup* r = new Bomb(start_x, start_y,20,20);
        r->draw();
    }

        
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
    
    }
  
}