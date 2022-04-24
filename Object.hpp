#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SDL.h>
#include "Lane.hpp"

class Object
{
    protected :
        int lane_id_;
        float depth_;
    
    public :
        Object(int lane_id, float depth);
        virtual void render(SDL_Renderer* renderer, const Lane& lane) = 0;
        virtual void update() = 0;
        virtual void clean() = 0;
        inline int get_lane_id() const { return lane_id_; }
};

#endif