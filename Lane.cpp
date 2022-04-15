#include "Lane.hpp"
#include "Game.hpp"

Lane::Lane(const vertex f_left, const vertex f_right, const vertex b_left, const vertex b_right) :
    is_active_{false},
    f_left_{f_left},
    f_right_{f_right},
    b_left_{b_left},
    b_right_{b_right}
{ std::cout << "New lane : (" << f_left.first << ";" << f_left.second << ") (" << f_right.first << ";" << f_right.second << ") (" << b_left.first << ";" << b_left.second << ") (" << b_right.first << "; " << b_right.second << ")" << std::endl; }

void Lane::set_active(bool is_active)
{
    is_active_ = is_active;
}

void Lane::render(SDL_Renderer* renderer) const
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
    // Draw front and back lines in blue
    SDL_RenderDrawLineF(renderer, f_left_.first, f_left_.second, f_right_.first, f_right_.second);
    SDL_RenderDrawLineF(renderer, b_left_.first, b_left_.second, b_right_.first, b_right_.second);

    // Draw side lines, in yellow if active, blue else
    if (is_active_) SDL_SetRenderDrawColor(renderer, 245, 236, 66, 0);
    else SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
    SDL_RenderDrawLineF(renderer, f_left_.first, f_left_.second, b_left_.first, b_left_.second);
    SDL_RenderDrawLineF(renderer, f_right_.first, f_right_.second, b_right_.first, b_right_.second);
} 

void Lane::clean()
{

}

std::ostream& operator<<(std::ostream& os, const Lane& lane)
{
    os << "FrontRight : (" << std::to_string(lane.f_right_.first) << "," << std::to_string(lane.f_right_.second) << ")" << std::endl;
    os << "FrontLeft : (" << std::to_string(lane.f_left_.first) << "," << std::to_string(lane.f_left_.second) << ")" << std::endl;
    os << "BackLeft : (" << std::to_string(lane.b_left_.first) << "," << std::to_string(lane.b_left_.second) << ")" << std::endl;
    os << "BackRight : (" << std::to_string(lane.b_right_.first) << "," << std::to_string(lane.b_right_.second) << ")" << std::endl;
    return os;
}