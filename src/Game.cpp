#include "Game.h"
#include "System.h"
#include <SDL2/SDL.h>
#include "Snake.h"

//#define FPS 60

namespace SpriteGame {

    void Game::add(Snake* c) {
		sprites.push_back(c);
	}

	void Game::addSnake(Snake* s){
		snake = s;
		sprites.push_back(s);
	}

	void Game::run() {
		bool quit = false;
		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
					case SDL_QUIT: quit = true; break;
					case SDL_KEYDOWN:
						switch(eve.key.keysym.sym){
							case SDLK_RIGHT: snake->keyRight(); break;
							case SDLK_LEFT: snake->keyLeft(); break;
							case SDLK_UP: snake->keyUp(); break;
							case SDLK_DOWN: snake->keyDown(); break;
						}
						break;
				} // switch
			} // inre while
		
			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			for (Snake* c : sprites)
				c->draw();
			SDL_RenderPresent(sys.get_ren());

		} //yttre while

	}

	Game::~Game()
	{
	}

}


/*
bool goOn = true;
const int tickIntervall = 1000 /FPS;
while(goOn){
			Uint32 nextTick = SDL_GetTicks() + tickIntervall;
}
int delay = nextTick - SDL_GetTicks();
			if(delay > 0){
				SDL_Delay(delay);
			}

*/