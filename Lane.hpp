#ifndef Lane_hpp
#define Lane_hpp
#include <vector>
#include <iostream>
#include <SDL.h>
#include "utils.hpp"

class Lane {
    private:
        bool is_active_;
        const vertex f_left_;
        const vertex f_right_;
        const vertex b_left_;
        const vertex b_right_;
        vertex u; // Vecteur b_left_, b_right_ normalisé
        vertex v; // Vecteur vers le centre
    public:
        Lane(const vertex f_left, const vertex f_right, const vertex b_left, const vertex b_right);
        Lane(const vertex center,const vertex f_right, const vertex f_left);
        void set_active(bool is_active);

        inline bool get_active() const {return is_active_;} 
        inline const vertex& get_f_left() const {return f_left_;}
        inline const vertex& get_f_right() const {return f_right_;}
        inline const vertex& get_b_left() const {return b_left_;}
        inline const vertex& get_b_right() const {return b_right_;}
        inline const vertex& get_u() const {return u;}
        inline const vertex& get_v() const {return v;}
        inline vertex get_mid() const {return {(f_left_.first+f_right_.first)/2.0, (f_left_.second+f_right_.second)/2.0};}
        
        void render(SDL_Renderer* renderer) const;
        void clean();
        friend std::ostream& operator<<(std::ostream& os, const Lane& lane);
};
#endif