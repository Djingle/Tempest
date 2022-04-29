#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SDL.h>
#include "Level.hpp"

class Object
{
    protected :
        int lane_id_;
        float depth_;
        mesh vertices_;
        mesh v_template_;
    
    public :
        Object(int lane_id, float depth, mesh vertices);
        virtual ~Object() = default;

        void init(const Level& terrain) {vertices_= get_pos(terrain);}
        virtual void render(SDL_Renderer* renderer);
        // void update();
        void clean();

        int get_lane_id() const { return lane_id_; }
        float get_depth() const { return depth_; }
        mesh get_pos(const Level& terrain) const;
        float get_angle(const Level& terrain) const;
        virtual mesh get_vertices() const {return vertices_;}
};

#endif
