#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "Lane.hpp"
#include <vector>

class Level {
    private:
        std::vector<Lane> lanes_;
        unsigned int player_pos_; // The Lane the player is on
        bool circular_;
        vertex center_;
    public:
        inline int get_nb_lanes() const { return lanes_.size(); }
        inline const Lane& get_lane(unsigned int i) const { return lanes_[i]; }
        inline const bool& is_circular() const { return circular_; }
        inline const vertex& get_center() const { return center_; }
        float get_angle_diff(int l1, int l2, int direction) const;
        void init(unsigned int lvl,int height);
        void load(unsigned int lvl);
        void update(unsigned int player_pos);
        void render(SDL_Renderer* renderer);
        void clean();
};

#endif