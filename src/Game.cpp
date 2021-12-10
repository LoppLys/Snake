#include "Game.h"
#include "System.h"
#include <SDL2/SDL.h>
#include "Snake.h"

namespace SpriteGame {

    void Game::add(Snake* c) {
		sprites.push_back(c);
	}

	void Game::addSnake(Snake* s){
		sprites.push_back(s);
	}

	void Game::run() {
		bool quit = false;
		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
					case SDL_QUIT: quit = true; break;
					/*case SDL_KeyCode(SDLK_LEFT):
						snake->keyLeft();
						break;
					for (Snake* c : sprites)
						c->keyLeft();
					break;
					
				
					case SDL_KeyCode(SDLK_RIGHT):
					for (Sprite* c : sprites)
						c->keyRight(eve);
					break;
					*/
				
					case SDL_KEYDOWN:
						snake->keyDown();
					break;
					/*for (Sprite* c : sprites)
						c->keyDown(eve);
					break;
					*/
					case SDL_KEYUP: 
						snake->keyUp();
					break;
					default: 
					break;
					//for (Snake* c : sprites)
					//	c->keyUp();
					//break;
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