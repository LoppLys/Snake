#include "System.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

namespace SpriteGame{

    System::System(){
    SDL_Init(SDL_INIT_EVERYTHING);
    if (TTF_Init() == -1){
        exit(-1);
    }
    if(Mix_OpenAudio( 22050,AUDIO_S16SYS,2,4096) !=0){
       exit(-1);
    }
    font = TTF_OpenFont("./resources/fonts/verdana.ttf",18); 
    backSound = Mix_LoadWAV("./resources/sounds/background-loop-001.wav");
    soundEffect = Mix_LoadWAV("./resources/sounds/eating-sound-effect.wav");
    win = SDL_CreateWindow("SpriteGame",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400,0);
    ren = SDL_CreateRenderer(win,-1,0);
    

   

    }

    System::~System(){

        Mix_FreeChunk(backSound);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
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

    Mix_Chunk* System::get_backSound() const{
        return backSound;
    }

    Mix_Chunk* System::get_soundEffect() const{
        return soundEffect;
    }

	System sys; 
}