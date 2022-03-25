#ifndef Character_hpp
#define Character_hpp
#include "Lane.hpp"

class Character {
    private:
        unsigned char nb_lives_;
        unsigned int score_;
        const Lane& position_; //Just a ref to the terrain so that a character can know all the lanes?
        unsigned int terrain_pos_;
    public:
        inline unsigned char getNbLives() const { return nb_lives_; }
        inline unsigned int getScore() const { return score_; }
        inline const Lane& getPosition() const { return position_; }
        void render(SDL_Renderer* renderer);
        void update();
        void clean();
};
#endif