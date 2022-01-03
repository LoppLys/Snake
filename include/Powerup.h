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
    Sprite* add(int x, int y, int s);
    void keyUp(){};
    void keyDown(){};
    void keyLeft(){};
    void keyRight(){};
    void tick();
    void remove();
    virtual void impact(Sprite *){};
    void draw(){};
    virtual int collide(Sprite *){return 0;};
    ~Powerup();


private:
    int counter = 0;

};



}

#endif