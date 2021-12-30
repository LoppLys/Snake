#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

namespace SpriteGame{

    class System
    {
        public:
        System();
        ~System();
        SDL_Renderer* get_ren() const;
        TTF_Font* get_font() const;
        Mix_Chunk* get_backSound() const;
        Mix_Chunk* get_soundEffect() const;
        private:
        SDL_Window* win;
        SDL_Renderer* ren;
        TTF_Font* font;
        Mix_Chunk* backSound;
        Mix_Chunk* soundEffect;


    };

    extern System sys;


}

#endif