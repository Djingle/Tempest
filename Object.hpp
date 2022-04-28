#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SDL.h>
#include "Level.hpp"

class Object
{
    protected :
        int lane_id_;
        float depth_;
        static const mesh vertices_;
        const Level& level_;
    
    public :
        Object(int lane_id, float depth, const Level& level);
        virtual ~Object() = default;

        virtual void render(SDL_Renderer* renderer, const Level& terrain) = 0;
        virtual void update() = 0;
        virtual void clean() = 0;

        int get_lane_id() const { return lane_id_; }
        float get_depth() const { return depth_; }
        float get_angle() const;
        vertex get_pos() const;
        virtual mesh get_vertices() const {return vertices_;}
};

#endif