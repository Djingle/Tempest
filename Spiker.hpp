#ifndef SPIKER_HPP
#define SPIKER_HPP
#include "Enemy.hpp"

class Spiker : public Enemy{
    private :
        int destination_; // lane to the right or left where the Spiker is going
        int direction_; // 0 if not moving, 1 if moving right, -1 if moving left
        float angle_;
    public :
        /**
         * @brief Construct a new Spiker object
         * 
         * @param lane_id 
         * @param depth 
         * @param terrain 
         */
        Spiker(int lane_id, float depth,const Level& terrain);
        /**
         * @brief Destroy the Flipper object
         * 
         */
        virtual ~Spiker();
      
        /**
         * @brief update the position and the angle of the spiker
         * 
         * @param terrain 
         */
        void update(const Level& terrain);
        /**
         * @brief render the spiker
         * 
         * @param renderer 
         */
        void render(SDL_Renderer* renderer);
       
        /**
         * @brief Get the vertices of the spiker
         * 
         * @return mesh 
         */
        mesh get_vertices() const override { return vertices_; }
};

#endif
