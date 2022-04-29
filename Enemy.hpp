#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Object.hpp"


class Enemy : public Object
{
    private :
        static int enemy_count_;
        int value_;
    public :
        /**
         * @brief Construct a new Enemy object
         * 
         * @param lane_id 
         * @param depth 
         * @param vertices 
         * @param value 
         */
        Enemy(int lane_id, float depth, mesh vertices, int value);
        /**
         * @brief Destroy the Enemy object
         * 
         */
        virtual ~Enemy();
        /**
         * @brief update the enemy
         * 
         */
        virtual void update();
        /**
         * @brief Get the number of ennemies
         * 
         * @return const int& 
         */
        static const int& get_enemy_count() { return enemy_count_; }
        /**
         * @brief Get the value of the enemy for the score
         * 
         * @return const int& 
         */
        const int& get_value() const { return value_; }
};


#endif
