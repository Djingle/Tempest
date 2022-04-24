#ifndef Character_hpp
#define Character_hpp
#include "Lane.hpp"
#include "Object.hpp"

class Character : public Object {
    protected:
        unsigned int nb_lives_;
        unsigned int score_;
    public:
        Character(unsigned int nb_lives, unsigned int score, int lane_id, float depth);
        inline unsigned int get_nbLives() const { return nb_lives_; }
        inline unsigned int get_score() const { return score_; }
        //void update() {};
        void render(SDL_Renderer* renderer) {};
        void clean() {};
};
#endif