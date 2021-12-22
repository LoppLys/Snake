//Spelmotorklass
#ifndef POWERUP_H
#define POWERUP_H

#include <SDL2/SDL.h>
#include "Sprite.h"
#include <string>

namespace SpriteGame{
class Powerup : public Sprite{

public:
    Powerup(int x, int y, int w, int h, std::string imageLocation);
    void add(int, int);
    void keyUp(){};
    void keyDown(){};
    void keyLeft(){};
    void keyRight(){};
    //virtual void remove();
    virtual void impact(Sprite *){};
    void draw();
    virtual void collide(Sprite *s){};
    ~Powerup();
    //virtual void setImageLocation(SDL_Surface* image){imageLocation = image;}

private:
   // int popup_time;
  // bool onScreen;

};



}

#endif