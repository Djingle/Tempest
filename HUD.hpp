#ifndef HUD_HPP
#define HUD_HPP
#include <SDL.h>
#include "Player.hpp"
#include "utils.hpp"
class HUD {
    private :
        SDL_Texture* texture_;
        SDL_Renderer* renderer_;
        SDL_Rect dst_;
    public :
        HUD();
        ~HUD();
        void init(SDL_Renderer* renderer);
        void render(int score,int nb_lives,int lvl);
        
};
#endif