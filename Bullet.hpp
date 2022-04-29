#ifndef BULLET_HPP
#define BULLET_HPP
#include "Object.hpp"

class Bullet : public Object {
    private:
        static int bullet_count_;
        bool direction_; // true = fired by player, false = fired by enemy
    public:
        /**
         * @brief Construct a new Bullet object
         * 
         * @param lane_id 
         * @param depth 
         * @param direction 
         * @param terrain 
         */
        Bullet(int lane_id, float depth, bool direction,const Level& terrain);
        /**
         * @brief Construct a new Bullet object
         * 
         * @param bullet 
         */
        Bullet(const Bullet& bullet);
        /**
         * @brief Destroy the Bullet object
         * 
         */
        virtual ~Bullet();
        /**
         * @brief update the position of the bullet
         * 
         * @param level 
         */
        void update(const Level& level);
        /**
         * @brief render the bullet (override the render method of the Object class because it uses points instead of lines)
         * 
         * @param renderer 
         */
        void render(SDL_Renderer* renderer);
        /**
         * @brief Get the number of bullets
         * 
         * @return const int& 
         */
        static const int& get_bullet_count() { return bullet_count_; }
        /**
         * @brief Get the direction of the bullet (from player or from ennemies)
         * 
         * @return true 
         * @return false 
         */
        const bool& get_direction() const { return direction_; }
};

#endif
