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
         * @brief Set the active object
         * 
         * @param is_active 
         */
        void set_active(bool is_active);
        /**
         * @brief Get the active object
         * 
         * @return true 
         * @return false 
         */
        bool get_active() const {return is_active_;} 
        /**
         * @brief Get the f left object
         * 
         * @return const vertex& 
         */
        const vertex& get_f_left() const {return f_left_;}
        /**
         * @brief Get the f right object
         * 
         * @return const vertex& 
         */
        const vertex& get_f_right() const {return f_right_;}
        /**
         * @brief Get the b left object
         * 
         * @return const vertex& 
         */
        const vertex& get_b_left() const {return b_left_;}
        /**
         * @brief Get the b right object
         * 
         * @return const vertex& 
         */
        const vertex& get_b_right() const {return b_right_;}
        /**
         * @brief Get the mid object
         * 
         * @return vertex 
         */
        vertex get_mid() const {return {(f_left_.first+f_right_.first)/2.0, (f_left_.second+f_right_.second)/2.0};}
        /**
         * @brief Get the angle object
         * 
         * @return float 
         */
        float get_angle() const {return v_angle({f_left_.first+1, f_left_.second}, f_left_, f_right_);}
        /**
         * @brief Get the width object
         * 
         * @return float 
         */
        float get_width() const {return v_distance(f_left_, f_right_);}
        /**
         * @brief 
         * 
         * @param renderer 
         */
        void render(SDL_Renderer* renderer) const;
        /**
         * @brief 
         * 
         */
        void clean();
};
#endif
