#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include <SDL2/SDL.h>


namespace SpriteGame{ 
class Sprite {
public:
    virtual void keyUp() = 0;
    virtual void keyDown() = 0;
    virtual void keyLeft() = 0;
    virtual void keyRight() = 0;
    virtual ~Sprite(); 
    //virtual void move(int x, int y){}
	virtual void draw() = 0;
    SDL_Rect& getRect() { return rect; }
    virtual void collide(Sprite*s){delete s;}

private:
    SDL_Rect rect; 
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite&) = delete;
protected:
    Sprite(int x, int y, int w, int h);
};
}
 
#endif