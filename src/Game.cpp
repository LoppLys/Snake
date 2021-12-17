#include "Game.h"
#include "System.h"
#include <SDL2/SDL.h>
#include "Snake.h"

#define FPS 60

namespace SpriteGame {

    void Game::add(Sprite* c) {
		sprites.push_back(c);
	}

	void Game::run() {
    const int tickIntervall = 1000 /FPS;
    int delay;

		bool quit = false;
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tickIntervall;
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
					case SDL_QUIT: quit = true; break;
					case SDL_KEYDOWN:
					for(Sprite * s: sprites){
						switch(eve.key.keysym.sym){
							case SDLK_RIGHT: s->keyRight(); break;
							case SDLK_LEFT: s->keyLeft(); break;
							case SDLK_UP: s->keyUp(); break;
							case SDLK_DOWN: s->keyDown(); break;
						}
						if(s->getRect().x < 0 || s->getRect().x > 600 || s->getRect().y < 0 || s->getRect().y > 400){
							quit = true;}
					}
					break;
				} // switch
			} // inre while
			delay = nextTick - SDL_GetTicks();
			if(delay > 0){
				SDL_Delay(delay);
			}
			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			for (Sprite* c : sprites)
				c->draw();

			SDL_RenderPresent(sys.get_ren());

		} //yttre while

	}

	Game::~Game()
	{
	}

}

