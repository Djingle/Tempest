#ifndef Character_hpp
#define Character_hpp
#include "Lane.hpp"

class Character {
    protected:
        unsigned char nb_lives_;
        unsigned int score_;
        unsigned int lane_id_; //Just a ref to the terrain so that a character can know all the lanes?
    public:
        Character(unsigned int nb_lives, unsigned int score, unsigned int lane_id);
        inline unsigned char get_nbLives() const { return nb_lives_; }
        inline unsigned int get_score() const { return score_; }
        inline unsigned int get_lane_id() const { return lane_id_; }
        void render(SDL_Renderer* renderer);
        void update();
        void clean();
};
#endif