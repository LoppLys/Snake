//
//  sdl2_second
//  

#include <iostream>
#include <string>

// Alla dessa SDL inkluderingsfiler används inte i detta testprogram.
// Bifogas endast för test av SDL installation! 

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_mixer.h> 
#include <SDL2/SDL_ttf.h>
#include "Snake.h"

// Paths to resource folders. Change to your own path!
// Absolut Path(Second choice)
//std::string resPath = "/Users/kjellna/dev/cpp21/sdl2_first/resources/";
// Relative Path(First Choice)
//std::string resPath = "../../resources/";
// Nedan om resurskatalogen ligger i '/build/debug/'
std::string resPath = "./resources/";

//#define FPS 60


/*int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
	{
		std::cout << "Error SDL2 Initialization : " << SDL_GetError();
		return EXIT_FAILURE;
	}

	if (TTF_Init() < 0)
	{
		std::cout << "Error SDL_ttf Initialization : " << SDL_GetError();
		return EXIT_FAILURE;
	}
	
	SDL_Window* window 		= SDL_CreateWindow("Window", 100, 100, 800, 600, 0);
	SDL_Renderer* renderer 	= SDL_CreateRenderer(window, -1, 0);

	SDL_Surface* bg_sur = IMG_Load( (resPath + "images/bg.jpg").c_str() );
	

	//TODO gör bilden mindre!
	SDL_Texture* bg_tex = SDL_CreateTextureFromSurface(renderer, bg_sur);
	
	SDL_FreeSurface(bg_sur);

	std::cout << "Avsluta programmet genom \"quit\" från fönstrets meny eller genom att stänga fönstret!" << std::endl;

	// Loop till dess att programmet avslutas!
	bool running = true;
	while (running) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				running = false;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bg_tex, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	// Städa innan programmet avslutas!

	SDL_DestroyTexture(bg_tex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	TTF_Quit();
	SDL_Quit();
	
	return EXIT_SUCCESS;
}*/