#ifndef HUD_HPP
#define HUD_HPP
class HUD {
    private :
        int score;
        int nb_lives;
        int highscore;
    public :
        HUD();
        ~HUD();
        void setScore(int score);
        void setNbLives(int nb_lives);
        void setHighscore(int highscore);
        int getScore();
        int getNbLives();
        int getHighscore();
        void render(SDL_Renderer* renderer) const;
        
};
#endif