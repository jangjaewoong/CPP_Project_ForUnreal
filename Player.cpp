#include <iostream>
#include "Player.h"


int Player::totalPlayers = 0;

Player::Player(std::string name="None", int level=1) : name{name}, level{level}{
    maxHp = 50*level;
    hp = maxHp;
    maxMp = 30*level;
    mp = maxMp;
    atk = 5*level;
    def = 3*level;
    isAlive = true;
    totalPlayers++;
}

Player::~Player(){
    totalPlayers--;
}

void Player::takeDamage(int damage){
    hp -= damage;
    if(hp<=0){
        isAlive = false;
        std::cout<<"당신은 죽었습니다\n";
        return;
    }
    std::cout<<"당신은 "<<damage<<"의 피해를 입었습니다!\n";
    std::cout<<"남은 체력 : "<<hp<<"\n";
}

void Player::Heal(int amount){
     if(amount<0 || mp<amount) {
        std::cout<<"회복할 수 없습니다!\n";
        return;
    }
    hp += amount;
    mp -= amount;
    if(hp>0){
        isAlive = true;
        if(hp>maxHp) hp = maxHp;
    }
    std::cout<<"당신은 "<<amount<<"만큼 회복했습니다!\n";
    std::cout<<"남은 체력 : "<<hp<<"\n";
    std::cout<<"남은 마나 : "<<mp<<"\n";
}

void Player::levelUp(){
    level+=1;
    maxHp = level*50;
    maxMp = level*30;
    hp = maxHp;
    mp = maxMp;
    atk = level*5;
    def = level*3;
    isAlive = true;
}

void Player::displayStatus() const {
    std::cout<<"이름 : "<<name<<"\n";
    std::cout<<"레벨 : "<<level<<"LV\n";
    std::cout<<"체력 : ["<<hp<<"/"<<maxHp<<"]\n";
    std::cout<<"마나 : ["<<mp<<"/"<<maxMp<<"]\n";
    std::cout<<"공격력 : "<<atk<<"\n";
    std::cout<<"방어력 : "<<def<<"\n"; 
}

int Player::getTotalPlayers(){
    return totalPlayers;
}