#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include <SDL2/SDL.h>

namespace SpriteGame{
class Sprite {
public:
    virtual ~Sprite();
    virtual void move(int x, int y){}
    virtual void keyRight(const SDL_Event&) {}
	virtual void keyLeft(const SDL_Event&) {}
	virtual void keyDown(const SDL_Event&) {}
	virtual void keyUp(const SDL_Event&) {}
	virtual void draw() const = 0;
    SDL_Rect getRect() const { return rect; }
//virtual void tick() = 0;
private:
    SDL_Rect rect; 
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite&) = delete;
protected:
    Sprite(int x, int y, int w, int h);
};
}

#endif