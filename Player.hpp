#ifndef Player_hpp
#define Player_hpp
#include "Object.hpp"
#include "Level.hpp"


class Player: public Object {
    private:
        int nb_lives_;
        int score_;
    public:
        Player(const Level& level);
        virtual ~Player(){};
        void render(SDL_Renderer* renderer) override;
        void update() override {}
        void clean() override {}
        void move_right(const Level& terrain);
        void move_left(const Level& terrain);
        void shoot();
        inline int get_score() const {return score_;};
        inline int get_nb_lives() const {return nb_lives_;};
};

#endif