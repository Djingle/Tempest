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
        Lane(const vertex center,const float scale,const vertex f_right, const vertex f_left);
        // Lane(const Lane& lane);
        void set_active(bool is_active);

        bool get_active() const {return is_active_;} 
        const vertex& get_f_left() const {return f_left_;}
        const vertex& get_f_right() const {return f_right_;}
        const vertex& get_b_left() const {return b_left_;}
        const vertex& get_b_right() const {return b_right_;}
        vertex get_mid() const {return {(f_left_.first+f_right_.first)/2.0, (f_left_.second+f_right_.second)/2.0};}
        float get_angle() const {return v_angle({f_left_.first-1, f_left_.second}, f_left_, f_right_);}
        float get_width() const {return v_distance(f_left_, f_right_);}
        
        void render(SDL_Renderer* renderer) const;
        void clean();
        friend std::ostream& operator<<(std::ostream& os, const Lane& lane);
};
#endif
