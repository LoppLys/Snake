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
	private:
		std::vector<Sprite*> sprites;
		Sprite* character;
	};
}
#endif