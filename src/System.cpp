#include "System.h"
#include <iostream>
#include<SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace SpriteGame{

    System::System(){
    SDL_Init(SDL_INIT_EVERYTHING);
    if (TTF_Init() == -1){
        exit(-1);
    }
    font = TTF_OpenFont("./resources/fonts/verdana.ttf",18); 
    win = SDL_CreateWindow("SpriteGame",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400,0);
    ren = SDL_CreateRenderer(win,-1,0);
    
    
   

    }

    System::~System(){

        TTF_CloseFont(font);
        TTF_Quit();
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }

    SDL_Renderer* System::get_ren() const {
		return ren;
	}

	TTF_Font* System::get_font() const {
		return font;
	}
	System sys; 
}