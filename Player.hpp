#ifndef Character_hpp
#define Character_hpp

class Character {
    private:
        unsigned char nb_lives_;
        unsigned int score_;
        Vertex* position_;
    public:
        inline unsigned char getNbLives() const { return nb_lives_; }
        inline unsigned int getScore() const { return score_; }
        inline Vertex* getPosition() const { return position_; }

}
#endif