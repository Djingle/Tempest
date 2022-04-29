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
         * @brief Get the nb lanes object
         * 
         * @return int 
         */
        inline int get_nb_lanes() const { return lanes_.size(); }
        /**
         * @brief Get the lane object
         * 
         * @param i 
         * @return const Lane& 
         */
        inline const Lane& get_lane(unsigned int i) const { return lanes_[i]; }
        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        inline const bool& is_circular() const { return circular_; }
        /**
         * @brief Get the center object
         * 
         * @return const vertex& 
         */
        inline const vertex& get_center() const { return center_; }
        /**
         * @brief Get the angle diff object
         * 
         * @param l1 
         * @param l2 
         * @param direction 
         * @return float 
         */
        float get_angle_diff(int l1, int l2, int direction) const;
        /**
         * @brief 
         * 
         * @param lvl 
         * @param height 
         */
        void init(unsigned int lvl,int height);
        /**
         * @brief 
         * 
         * @param lvl 
         */
        void load(unsigned int lvl);
        /**
         * @brief 
         * 
         * @param player_pos 
         */
        void update(unsigned int player_pos);
        /**
         * @brief 
         * 
         * @param renderer 
         */
        void render(SDL_Renderer* renderer);
        /**
         * @brief 
         * 
         */
        void clean();
};

#endif