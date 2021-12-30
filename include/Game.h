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
		void Spawn (int, int);
		void RenderText(const char*);
		void gameOver();
		bool outOfBounds();
		void checkCollision(Sprite *);
		void playSound(Mix_Chunk*, int);
		
	private:
		std::vector<Sprite*> sprites;
		Sprite* character;
		SDL_Surface* txtSurface;
		SDL_Texture * txtTexture;
		const char* score;
		
	};
}
#endif