#ifndef Terrain_hpp
#define Terrain_hpp
#include "Lane.hpp"
#include <vector>

class Terrain {
    private:
        std::vector<Lane> lanes_;
        unsigned int player_pos_; // The Lane the player is on

    public:
        Terrain(unsigned int player_pos, std::vector<Lane> lanes);
        void update();
        void render(SDL_Renderer* renderer);
        void clean();

};

#endif