#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Sprite.h"
#include "System.h"
#include "Snake.h"

namespace SpriteGame {
    class Game{
    public:
    
        Game(Sprite * c);
        void add(Sprite* s);
        void run();
        ~Game();
        void spawn ();
        void gameOver();
        bool outOfBounds();
        void checkCollision(Sprite *);
        void playSound(Mix_Chunk*, int);
        void renderPoints(int);
        void renderBackground();

    private:
        std::vector<Sprite*> sprites;
        Sprite* character;
        SDL_Surface* txtSurface;
        SDL_Texture* txtTexture;
        SDL_Surface* backgroundSurface;
        SDL_Texture* backgroundTexture;
        const char* score;
        int points;

    };
}
#endif