//spelklass
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
#include "Bomb.h"
#include "RedApple.h"
#include "Powerup.h"
#include "GreenApple.h"
#include "RottenApple.h"


using namespace SpriteGame;
using namespace std;

int main(int argc, char** argv) {
    
    
    Sprite* character = new Snake(263,153,20,20);
    Game game(character);
    Powerup* p = new RedApple(120, 100, 20, 20);
    Powerup* p1 = new GreenApple(200, 200, 20, 20);
    Powerup* p2 = new RottenApple(230, 50, 20, 20);
    Powerup* p3 = new Bomb(290, 300, 20, 20);
    game.add(p);
    game.add(p1);
    game.add(p2);
    game.add(p3);
    game.run();


    return 0;
}