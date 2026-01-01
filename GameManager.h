#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "Enemy.h"
class GameManager {
    public :
        static void ShowGameStats();
        void FullHeal(Player &p);
        void KillEnemy(Enemy &e);
        void DebugPrint(const Player &p);
};

#endif