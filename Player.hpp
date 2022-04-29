#ifndef Player_hpp
#define Player_hpp
#include "Object.hpp"
#include "Level.hpp"
#include "Bullet.hpp"
/**
 * @brief 
 * 
 */
class Player: public Object {
        int nb_lives_;
        int score_;
        bool is_shooting_;
        int direction_; // 0: nothing, 1: right, -1: left
        static mesh v_template_;
    public:
        /**
         * @brief Construct a new Player object
         * 
         * @param player 
         */
        Player(const Player& player);
        /**
         * @brief Construct a new Player object
         * 
         * @param terrain 
         */
        Player(const Level& terrain);
        /**
         * @brief Construct a new Player object
         * 
         */
        Player();
        /**
         * @brief Destroy the Player object
         * 
         */
        virtual ~Player(){};
        /**
         * @brief 
         * 
         * @param terrain 
         */
        void move_right(const Level& terrain);
        /**
         * @brief 
         * 
         * @param terrain 
         */
        void move_left(const Level& terrain);
        /**
         * @brief 
         * 
         */
        void shoot();
        /**
         * @brief Get the score object
         * 
         * @return int 
         */
        inline int get_score() const {return score_;};
        /**
         * @brief Get the nb lives object
         * 
         * @return int 
         */
        inline int get_nb_lives() const {return nb_lives_;};
        /**
         * @brief Set the nb lives object
         * 
         * @param nb_lives 
         */
        void set_nb_lives(int nb_lives) {nb_lives_ = nb_lives;};
        /**
         * @brief 
         * 
         * @param terrain 
         */
        void update(const Level& terrain);
        /**
         * @brief Set the is shooting object
         * 
         * @param is_shooting 
         */
        void set_is_shooting(bool is_shooting) { is_shooting_ = is_shooting; }
        /**
         * @brief Get the is shooting object
         * 
         * @return true 
         * @return false 
         */
        const bool& get_is_shooting() const { return is_shooting_; }
        /**
         * @brief Set the score object
         * 
         * @param score 
         */
        void set_score(int score) { score_ = score; }
};
#endif