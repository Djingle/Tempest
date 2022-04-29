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
        /**
         * @brief Construct a new HUD object
         * 
         */
        HUD();
        /**
         * @brief Destroy the HUD object
         * 
         */
        ~HUD();
        /**
         * @brief 
         * 
         * @param renderer 
         */
        void init(SDL_Renderer* renderer);
        /**
         * @brief 
         * 
         * @param score 
         * @param nb_lives 
         * @param lvl 
         */
        void render(int score,int nb_lives,int lvl);
        
};
#endif