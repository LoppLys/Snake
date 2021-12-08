#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Sprite.h"

namespace SpriteGame {

	class Game{
	public:
        // add apples during runtime
		void add(Sprite* s);
		void run();
		~Game();
	private:
		std::vector<Sprite*> sprites;
	};
}
#endif