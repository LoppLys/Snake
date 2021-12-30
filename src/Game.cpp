//spelmotorklass
#include "Game.h"
#include "System.h"
#include "Snake.h"
#include "Powerup.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define FPS 60

namespace SpriteGame {

	Game::Game(Sprite * c){
		character = c; //setting initial sprite to become the main character of game
		add(c);
	}

    void Game::add(Sprite* c) {
		sprites.push_back(c);
	}

	void Game::run() {
	playSound(sys.get_backSound(),-1);
	score = "Current score ";// + character->getSize();
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
					}
					break;
				} // switch
			} // inre while
			delay = nextTick - SDL_GetTicks();
			if(delay > 0){
				SDL_Delay(delay);
			}
			
			SDL_SetRenderDrawColor(sys.get_ren(), 255, 200, 255, 255);
			SDL_RenderClear(sys.get_ren());
			
			for (Sprite* s : sprites){
				s->tick();
				if(outOfBounds()){
					quit = true;
				}
				checkCollision(s);
			}
			
			RenderText(score);
			Spawn(nextTick,delay);
			SDL_RenderPresent(sys.get_ren());
			SDL_DestroyTexture(txtTexture);

		} //yttre while

	}

	Game::~Game(){}

	void Game::Spawn(int nextTick, int delay){
		if(nextTick%10 < 3 && delay%10 == 5 ){
				int x = rand() % 600;
				int y = rand() % 100;
				int s = rand() % 5;
                Powerup* p = nullptr;
                sprites.push_back(p->add(x,y,s));
    	}
	}

	void Game::RenderText(const char* text){
		SDL_Color txtColor = {0,0,0};
		txtSurface= TTF_RenderText_Solid(sys.get_font(),text,txtColor);
		txtTexture = SDL_CreateTextureFromSurface(sys.get_ren(), txtSurface);
		SDL_Rect txtRect = {450,10, txtSurface->w,txtSurface->h};
		SDL_RenderCopy(sys.get_ren(),txtTexture, NULL , &txtRect);
		SDL_FreeSurface(txtSurface);
		
	}
	void Game::playSound(Mix_Chunk* sound, int i){
		int channel = Mix_PlayChannel(-1,sound,i);
		if(channel == -1){
			std::cout << "No sound" << std::endl;
		}
		Mix_Volume(channel,50);
	}

	bool Game::outOfBounds(){
		
		if(character->getRect().x < -20 || character->getRect().x > 650 || character->getRect().y < -20 || character->getRect().y > 450){
			return true;
		} else
			return false;
	}

	void Game::checkCollision(Sprite * s){
		if(character != s && SDL_HasIntersection(&character->getRect(), &s->getRect()) ){
			playSound(sys.get_soundEffect(),0);
			character->collide(s);
			auto iter = find(sprites.begin(), sprites.end(), s);
			sprites.erase(iter);
		}
	}
	
	void Game::gameOver(){
		
	}

}
