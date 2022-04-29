#ifndef FLIPPER_HPP
#define FLIPPER_HPP
#include "Enemy.hpp"

class Flipper : public Enemy
{
    private :
        bool is_shooting_;
        int destination_; // lane to the right or left where the Flipper is going
        int direction_; // 0 if not moving, 1 if moving right, -1 if moving left
        float angle_;
    public :
        /**
         * @brief Construct a new Flipper object
         * 
         * @param lane_id 
         * @param depth 
         * @param terrain 
         */
        Flipper(int lane_id, float depth,const Level& terrain);
        /**
         * @brief Destroy the Flipper object
         * 
         */
        virtual ~Flipper();
        /**
         * @brief move the flipper to the next lane
         * 
         * @param terrain 
         */
        void move_right(const Level& terrain);
        /**
         * @brief move the flipper to the previous lane
         * 
         * @param terrain 
         */
        void move_left(const Level& terrain);
        /**
         * @brief update the position and the angle of the flipper
         * 
         * @param terrain 
         */
        void update(const Level& terrain);
        /**
         * @brief render the flipper
         * 
         * @param renderer 
         */
        void render(SDL_Renderer* renderer);
        /**
         * @brief Set if the flipper is shooting
         * 
         * @param is_shooting 
         */
        void set_is_shooting(bool is_shooting) { is_shooting_ = is_shooting; }
        /**
         * @brief Get if the flipper is shooting
         * 
         * @return true 
         * @return false 
         */
        const bool& get_is_shooting() const { return is_shooting_; }
        /**
         * @brief Get the vertices of the flipper
         * 
         * @return mesh 
         */
        mesh get_vertices() const override { return vertices_; }
};

#endif
