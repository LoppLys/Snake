#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_mixer.h> 
#include <SDL2/SDL_ttf.h>
#include "Snake.h"
#include "Game.h"
#include "System.h"
#include <iostream>
#include <string>

using namespace SpriteGame;
using namespace std;

int main(int argc, char** argv) {

    Game game;
    
    Snake* snake = Snake::getInstance(20,20,20,20);
    game.addSnake(snake);
    game.run();

    return 0;
}