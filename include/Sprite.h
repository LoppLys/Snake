#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include <SDL2/SDL.h>

namespace SpriteGame{
class Sprite {
public:
    virtual ~Sprite(); 
    virtual void move(int x, int y){}
	virtual void draw() = 0;
    SDL_Rect& getRect() { return rect; }

private:
    SDL_Rect rect; 
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite&) = delete;
protected:
    Sprite(int x, int y, int w, int h);
};
}

#endif