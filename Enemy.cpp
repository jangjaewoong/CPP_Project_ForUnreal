#include <iostream>
#include "Enemy.h"
#include "Player.h"

int Enemy::totalEnemies = 0;
Enemy::Enemy(std::string name="None", int level=1) : name{name}, level{level}{
    maxHp = 50*level;
    hp = maxHp;
    atk = 3*level;
    def = 2*level;
    isAlive = true;
    totalEnemies++;
}

Enemy::~Enemy(){
    totalEnemies--;
}

void Enemy::Attack(Player& target){
    target.takeDamage(atk);
}

void Enemy::takeDamage(int damage){
     hp -= damage;
    if(hp<=0){
        isAlive = false;
        std::cout<<name<<"은 죽었습니다\n";
        return;
    }
    std::cout<<name<<"은 "<<damage<<"의 피해를 입었습니다!\n";
    std::cout<<name<<"의 남은 체력 : "<<hp<<"\n";
}

void Enemy::displayStatus() const{
    std::cout<<"이름 : "<<name<<"\n";
    std::cout<<"레벨 : "<<level<<"LV\n";
    std::cout<<"체력 : ["<<hp<<"/"<<maxHp<<"]\n";
    std::cout<<"공격력 : "<<atk<<"\n";
    std::cout<<"방어력 : "<<def<<"\n"; 
}

int Enemy::getTotalEnemies(){
    return totalEnemies;
}