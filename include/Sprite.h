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
    SDL_Rect& getRect() { return rect; }
    virtual void collide(Sprite*s){}
    virtual void impact(Sprite *) = 0;
    void removeSprite(Sprite * s);
    SDL_Surface* getSurface(){return surface;}
    void setSurface(SDL_Surface* this_surface){surface = this_surface;}
    void setImage(std::string image){setSurface(IMG_Load(image.c_str()));}
    SDL_Texture* getTexture(){return texture;}
    void setTexture(SDL_Surface* new_surface){texture = SDL_CreateTextureFromSurface(sys.get_ren(), new_surface);}
    

private:
    SDL_Rect rect; 
    SDL_Surface* surface; 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(sys.get_ren(), surface);
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite&) = delete;

protected:
    Sprite(int x, int y, int w, int h, SDL_Surface* surface);
};
}
 
#endif