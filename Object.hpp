#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SDL.h>
#include "Level.hpp"

class Object{
    protected :
        int lane_id_;
        float depth_;
        mesh vertices_;
        mesh v_template_;
    
    public :
        /**
         * @brief Construct a new Object object
         * 
         * @param lane_id 
         * @param depth 
         * @param vertices 
         */
        Object(int lane_id, float depth, mesh vertices);
        /**
         * @brief Destroy the Object object
         * 
         */
        virtual ~Object() = default;
        /**
         * @brief init the object with its vertices position
         * 
         * @param terrain 
         */
        void init(const Level& terrain) {vertices_= get_pos(terrain);}
        /**
         * @brief render the object
         * 
         * @param renderer 
         */
        virtual void render(SDL_Renderer* renderer);
        /**
         * @brief Get the lane id of the object
         * 
         * @return int 
         */
        int get_lane_id() const { return lane_id_; }
        /**
         * @brief Get the depth object
         * 
         * @return float 
         */
        float get_depth() const { return depth_; }
        /**
         * @brief Get the good position of the object
         * 
         * @param terrain 
         * @return mesh 
         */
        mesh get_pos(const Level& terrain) const;
        /**
         * @brief Get the angle
         * 
         * @param terrain 
         * @return float 
         */
        float get_angle(const Level& terrain) const;
        /**
         * @brief Get the vertices of the object
         * 
         * @return mesh 
         */
        virtual mesh get_vertices() const {return vertices_;}
};

#endif
