#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include <SDL2/SDL.h>

//namespace SpriteGame{
class Sprite {
public:
    virtual void move(int x, int y){}
    SDL_Rect getRect() const { return rect; }
//virtual void tick() = 0;
private:
    std::string name;
protected:
    Sprite(int x, int y, int w, int h);
    //: //rect { x,y,w,h} {}
    SDL_Rect rect; 

};
//}

#endif