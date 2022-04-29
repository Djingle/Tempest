#ifndef Lane_hpp
#define Lane_hpp
#include <vector>
#include <iostream>
#include <SDL.h>
#include "utils.hpp"

class Lane {
    private:
        bool is_active_;
        vertex f_left_;
        vertex f_right_;
        vertex b_left_;
        vertex b_right_;
    public:
        /**
         * @brief Construct a new Lane object
         * 
         * @param center 
         * @param scale 
         * @param f_right 
         * @param f_left 
         */
        Lane(const vertex center,const float scale,const vertex f_right, const vertex f_left);
        /**
         * @brief Set if player is on the lane
         * 
         * @param is_active 
         */
        void set_active(bool is_active){is_active_ = is_active;};
        /**
         * @brief get if player is on the lane
         * 
         * @return true 
         * @return false 
         */
        bool get_active() const {return is_active_;} 
        /**
         * @brief Get the front left vertex of lane
         * 
         * @return const vertex& 
         */
        const vertex& get_f_left() const {return f_left_;}
        /**
         * @brief Get the front right vertex of lane
         * 
         * @return const vertex& 
         */
        const vertex& get_f_right() const {return f_right_;}
        /**
         * @brief Get the back left vertex of lane
         * 
         * @return const vertex& 
         */
        const vertex& get_b_left() const {return b_left_;}
        /**
         * @brief Get the back right vertex of lane
         * 
         * @return const vertex& 
         */
        const vertex& get_b_right() const {return b_right_;}
        /**
         * @brief Get the middle point between front left and front right
         * 
         * @return vertex 
         */
        vertex get_mid() const {return {(f_left_.first+f_right_.first)/2.0, (f_left_.second+f_right_.second)/2.0};}
        /**
         * @brief Get the angle
         * 
         * @return float 
         */
        float get_angle() const {return v_angle({f_left_.first+1, f_left_.second}, f_left_, f_right_);}
        /**
         * @brief Get the width of the lane
         * 
         * @return float 
         */
        float get_width() const {return v_distance(f_left_, f_right_);}
        /**
         * @brief render the lane on the screen in blue if not selected, yellow if selected
         * 
         * @param renderer 
         */
        void render(SDL_Renderer* renderer) const;

};
#endif
