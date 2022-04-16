#ifndef Terrain_hpp
#define Terrain_hpp
#include "Lane.hpp"
#include <vector>

class Terrain {
    private:
        std::vector<Lane> lanes_;
        unsigned int player_pos_; // The Lane the player is on
        bool circular_;
    public:
        Terrain(unsigned int lvl);

        inline int get_nb_lanes() const { return lanes_.size(); }
        inline const Lane& get_lane(unsigned int i) const { return lanes_[i]; }

        inline const bool& is_circular() const { return circular_; }
        void load(unsigned int lvl);
        void update(unsigned int player_pos);
        void render(SDL_Renderer* renderer);
        void clean();
};

#endif