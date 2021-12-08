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
    
    Snake* snake = Snake::getInstance(100,100,100,100);
    game.add(snake);
    game.run();

    return 0;
}