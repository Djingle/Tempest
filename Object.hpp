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
        /**
         * @brief Construct a new Object object
         * 
         * @param lane_id 
         * @param depth 
         * @param vertices 
         */
        Object(int lane_id, float depth, mesh vertices);
        virtual ~Object() = default;
        /**
         * @brief 
         * 
         * @param terrain 
         */
        void init(const Level& terrain) {vertices_= get_pos(terrain);}
        /**
         * @brief 
         * 
         * @param terrain 
         */
        void apply_template(const Level& terrain);
        /**
         * @brief 
         * 
         * @param renderer 
         */
        virtual void render(SDL_Renderer* renderer);
        // void update();
        /**
         * @brief 
         * 
         */
        void clean();

        int get_lane_id() const { return lane_id_; }
        /**
         * @brief Get the depth object
         * 
         * @return float 
         */
        float get_depth() const { return depth_; }
        /**
         * @brief Get the pos object
         * 
         * @param terrain 
         * @return mesh 
         */
        mesh get_pos(const Level& terrain) const;
        /**
         * @brief Get the angle object
         * 
         * @param terrain 
         * @return float 
         */
        float get_angle(const Level& terrain) const;
        /**
         * @brief Get the vertices object
         * 
         * @return mesh 
         */
        virtual mesh get_vertices() const {return vertices_;}
};

#endif
