#include "Game.h"
#include <SDL2/SDL.h>
#include "System.h"

namespace SpriteGame {

    void Game::add(Sprite* c) {
		sprites.push_back(c);
	}

	void Game::run() {
		bool quit = false;
		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_KeyCode(SDLK_LEFT):
					for (Sprite* c : sprites)
						c->keyLeft(eve);
					break;
				case SDL_KeyCode (SDLK_RIGHT):
					for (Sprite* c : sprites)
						c->keyRight(eve);
					break;
				case SDL_KEYDOWN:
					for (Sprite* c : sprites)
						c->keyDown(eve);
					break;
				case SDL_KEYUP:
					for (Sprite* c : sprites)
						c->keyUp(eve);
					break;
				} // switch
			} // inre while
			SDL_SetRenderDrawColor(system.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(system.get_ren());
			for (Sprite* c : sprites)
				c->draw();
			SDL_RenderPresent(system.get_ren());

		} //yttre while

	}

	Game::~Game()
	{
	}

}