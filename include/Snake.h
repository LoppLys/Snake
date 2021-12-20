#ifndef SNAKE_H
#define SNAKE_H

#include "Sprite.h"
#include <SDL2/SDL.h> 
#include <vector>
#include "SnakeBody.h"


namespace SpriteGame {

class Snake : public Sprite {
public:
//static Snake* getInstance(int x, int y, int w, int h);
void keyUp();
void keyDown();
void keyLeft();
void keyRight();
void draw();
void collide(){};
Snake(int x, int y, int w, int h);
void addBodyPart(SnakeBody* b);
SDL_Surface* getSnake(){return snake_head;}
//SDL_Surface* getSurface(){return snake_head;} //Den här används nog inte
~Snake();

//protected:
private:
SDL_Surface* snake_head;
SDL_Texture* texture;
int direction;
std::vector<SnakeBody *> body;


};

}

#endif