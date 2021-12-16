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
		void addSnake(Snake* sn);
		void add(Sprite* s);
		Snake* getSnake() {return snake;}

		void run();
		~Game();
	private:
		std::vector<Sprite*> sprites;
		Snake* snake;
	};
}
#endif