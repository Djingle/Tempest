#include "Lane.hpp"
#include "Game.hpp"
#include <cmath>

Lane::Lane(const vertex center,const float scale, const vertex f_left, const vertex f_right) :
    is_active_{false},
    f_left_{f_left},
    f_right_{f_right},
    b_left_{v_homothety(f_left,center,scale)},
    b_right_{v_homothety(f_right,center,scale)}{}

void Lane::render(SDL_Renderer* renderer) const{
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    // Draw front and back lines in blue
    SDL_RenderDrawLineF(renderer, f_left_.first, f_left_.second, f_right_.first, f_right_.second);
    SDL_RenderDrawLineF(renderer, b_left_.first, b_left_.second, b_right_.first, b_right_.second);

    // Draw side lines, in yellow if active, blue else
    if (is_active_) SDL_SetRenderDrawColor(renderer, 245, 236, 66, 255);
    else SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderDrawLineF(renderer, f_left_.first, f_left_.second, b_left_.first, b_left_.second);
    SDL_RenderDrawLineF(renderer, f_right_.first, f_right_.second, b_right_.first, b_right_.second);
} 

