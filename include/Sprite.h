//spelmotorklass
#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "System.h"


namespace SpriteGame{ 
class Sprite {
public:
    virtual void keyUp() = 0;
    virtual void keyDown() = 0;
    virtual void keyLeft() = 0;
    virtual void keyRight() = 0;
    virtual ~Sprite(); 
	virtual void draw(); 
    virtual void tick() = 0;
    bool IsActive(){return Active;};
    void setActive(){Active = false; };
    SDL_Rect& getRect() { return rect; }
    virtual int collide(Sprite*s){return 0;}
    virtual void impact(Sprite *) = 0;
    SDL_Surface* getSurface(){return surface;}
    void setSurface(SDL_Surface* this_surface){surface = this_surface;}
    SDL_Texture* getTexture(){return texture;}
    void setTexture(SDL_Surface* new_surface){texture = SDL_CreateTextureFromSurface(sys.get_ren(), new_surface);}
    Sprite(const Sprite& other) = delete;
    const Sprite* operator=(Sprite*) = delete;
    

private:
    SDL_Rect rect; 
    SDL_Surface* surface; 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(sys.get_ren(), surface);
    bool Active = true;
    

protected:
    Sprite(int x, int y, int w, int h, SDL_Surface* surface);
};
}
 
#endif