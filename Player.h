#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
class GameManager;

class Player {
    private:
        std::string name;
        int hp, maxHp;
        int mp, maxMp;
        int atk, def;
        int level;
        bool isAlive;
        static int totalPlayers;

       
    public:
        Player(std::string name, int level);
        ~Player();
        void takeDamage(int damage);
        void Heal(int amount);
        void levelUp();
        void displayStatus() const;
        static int getTotalPlayers();
        friend class GameManager;

};


#endif