#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
class Player {
    private :
        std::string name;
        int score;
        int level;
    public :
        Player();
        Player(std::string name);  // 이름만 받는 생성자 추가!
        Player(std::string name, int score, int level);
        
        std::string GetName() const { return name; };
        int GetScore() const { return score;};
        int GetLevel() const { return level; };

        void AddScore(int score);
        void LevelUp();
        void Display() const ;
};


#endif