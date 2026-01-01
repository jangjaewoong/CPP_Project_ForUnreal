#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
class Player;
class GameManager;

class Enemy {
    private :
        std::string name;
        int level;
        int hp, maxHp;
        int atk,def;
        bool isAlive;
        static int totalEnemies;
        

    public:
        Enemy(std::string name, int level);
        ~Enemy();
        void Attack(Player& target);
        void takeDamage(int damage);
        void displayStatus() const;
        static int getTotalEnemies();
        friend class GameManager;
};
#endif