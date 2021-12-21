#ifndef POWERUP_H
#define POWERUP_H

#include <SDL2/SDL.h>
#include "Sprite.h"

namespace SpriteGame{
class Powerup : public Sprite{
public:
    Powerup(int x, int y, int w, int h);
    void add(int, int);
    void keyUp(){};
    void keyDown(){};
    void keyLeft(){};
    void keyRight(){};
    //virtual void remove();
    //virtual void impact();
    void draw();
    void collide(Sprite *s);
    ~Powerup();

private:
   // int popup_time;
  // bool onScreen;
};
}

#endif