#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Sprite.h"
#include "System.h"
#include "Snake.h"

namespace SpriteGame {
    class Game{
    public:
        // add apples during runtime
        Game(Sprite * c);
        void add(Sprite* s);
        void run();
        ~Game();
        void spawn (int, int);
        void gameOver();
        bool outOfBounds();
        void checkCollision(Sprite *);
        void playSound(Mix_Chunk*, int);
        void renderPoints(int);

    private:
        std::vector<Sprite*> sprites;
        Sprite* character;
        SDL_Surface* txtSurface;
        SDL_Texture* txtTexture;
        const char* score;
        int points;

    };
}
#endif