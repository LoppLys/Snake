//spelmotorklass
#include "Game.h"
#include "System.h"
#include "Snake.h"
#include "Powerup.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
	score = "Current score ";
	points = 0;
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
			SDL_RenderClear(sys.get_ren());
			renderBackground();
			
			for (Sprite* s : sprites){
				s->tick();
				
				if(outOfBounds()){
					quit = true;
				}
				checkCollision(s);
				if(!s->IsActive()){
					auto iter = find(sprites.begin(), sprites.end(), s);
					sprites.erase(iter);
					delete s;
				}
			}
			renderPoints(points);
			if(rand() % 70 == 2){
				spawn();
			}
			
			SDL_RenderPresent(sys.get_ren());
			SDL_DestroyTexture(txtTexture);
			SDL_DestroyTexture(backgroundTexture);

		} //yttre while

	}

	Game::~Game(){}

	void Game::renderBackground(){
	backgroundSurface = IMG_Load("./resources/images/background.jpg");
    backgroundTexture = SDL_CreateTextureFromSurface(sys.get_ren(), backgroundSurface); 
	SDL_Rect backRect = {0,0,backgroundSurface->w, backgroundSurface->h };
	SDL_RenderCopy(sys.get_ren(),backgroundTexture, NULL , &backRect);
    SDL_FreeSurface(backgroundSurface);
	}

	void Game::spawn(){
		int x = rand() % 300;
		int y = rand() % 200;
		int s = rand() % 5;
        Powerup* p = nullptr;
        sprites.push_back(p->add(x,y,s));
    	
	}

	void Game::renderPoints(int points){
		std::string pointsStr = "Score " + std::to_string(points);
		SDL_Color color = { 255,255,255 };
		txtSurface =
			TTF_RenderText_Solid(sys.get_font(), pointsStr.c_str(), color);
		txtTexture = SDL_CreateTextureFromSurface(sys.get_ren(), txtSurface);
		SDL_Rect pointsRect = { 450,10,txtSurface->w, txtSurface->h };
		SDL_RenderCopy(sys.get_ren(),txtTexture, NULL , &pointsRect);
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
			int i = character->collide(s);
			auto iter = find(sprites.begin(), sprites.end(), s);
			sprites.erase(iter);
			delete s;
			points += i;
		}
	}

	void Game::gameOver(){
		std::cout << "Your score " << points << std::endl;
	}
	

}