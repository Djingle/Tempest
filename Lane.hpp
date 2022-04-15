#ifndef Lane_hpp
#define Lane_hpp
#include <vector>
#include <iostream>
#include <SDL.h>
using vertex = std::pair<float, float>;

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
        void set_active(bool is_active);
        inline bool get_active() const {return is_active_;} 
        void render(SDL_Renderer* renderer) const;
        void clean();
        friend std::ostream& operator<<(std::ostream& os, const Lane& lane);
};
#endif