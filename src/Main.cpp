#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_mixer.h> 
#include <SDL2/SDL_ttf.h>
#include "Snake.h"
#include "SnakeBody.h"
#include "Game.h"
#include "System.h"
#include <iostream>
#include <string>


using namespace SpriteGame;
using namespace std;

int main(int argc, char** argv) {
    Game game;
    
    Snake* snake = new Snake(263,153,20,20);
    game.addSnake(snake);
    game.add(new SnakeBody(snake->getRect().x,snake->getRect().y,20,20));
    game.run();

    return 0;
}