#include <iostream>
#include "GameManager.h"


void GameManager::ShowGameStats(){
    std::cout<<"플레이어 수 : "<<Player::getTotalPlayers()<<std::endl;
    std::cout<<"적 수 : "<<Enemy::getTotalEnemies()<<std::endl; 
}

void GameManager::FullHeal(Player &p){
    p.hp = p.maxHp;
    std::cout<<p.name<<"이 완전히 회복되었다!"<<std::endl;
}

void GameManager::KillEnemy(Enemy &e){
    e.hp = 0;
    std::cout<<e.name<<"이 쓰러졌다!"<<std::endl;
}

void GameManager::DebugPrint(const Player &p){
    p.displayStatus();
}