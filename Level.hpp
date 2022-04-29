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
        /**
         * @brief Get the number of lanes
         * 
         * @return int 
         */
        inline int get_nb_lanes() const { return lanes_.size(); }
        /**
         * @brief Get the i'th lane
         * 
         * @param i 
         * @return const Lane& 
         */
        inline const Lane& get_lane(unsigned int i) const { return lanes_[i]; }
        /**
         * @brief get if the level is circular
         * 
         * @return true 
         * @return false 
         */
        inline const bool& is_circular() const { return circular_; }
        /**
         * @brief Get the vanishing point
         * 
         * @return const vertex& 
         */
        inline const vertex& get_center() const { return center_; }
        /**
         * @brief Get the angle difference between two lanes
         * 
         * @param l1 
         * @param l2 
         * @param direction 
         * @return float 
         */
        float get_angle_diff(int l1, int l2, int direction) const;
        /**
         * @brief creates level with given parameters
         * 
         * @param lvl 
         * @param height 
         */
        void init(unsigned int lvl,int height);
        /**
         * @brief update the selected lane
         * 
         * @param player_pos 
         */
        void update(unsigned int player_pos);
        /**
         * @brief iterate through all lanes and render them
         * 
         * @param renderer 
         */
        void render(SDL_Renderer* renderer);
};

#endif