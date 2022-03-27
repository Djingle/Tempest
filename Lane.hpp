#ifndef Lane_hpp
#define Lane_hpp
#include <vector>
#include <iostream>
#include <SDL.h>
using vertex = std::pair<float, float>;

class Lane {
    private:
        bool is_active_;
        const vertex &f_right_;
        const vertex &f_left_;
        const vertex &b_left_;
        const vertex &b_right_;
    public:
        Lane(const vertex& f_right, const vertex& f_left, const vertex& b_left, const vertex& b_right);
        void set_active(bool is_active);
        void render(SDL_Renderer* renderer) const;
        void clean();
        friend std::ostream& operator<<(std::ostream& os, const Lane& lane);
};
#endif