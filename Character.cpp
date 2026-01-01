#include <iostream>
#include "Character.h"

Character::Character(std::string name, int hp, int mp, int atk): name{name}, attackPower{atk}{
    this->maxHp = hp;
    this->hp = maxHp;
    this->maxMp = mp;
    this->mp = maxMp;
}

Character::~Character() {
    std::cout << "Character destroyed\n";
}

void Character::TakeDamage(int damage){
    hp -= damage;
    if(hp<=0) std::cout<<name<<"은 쓰러졌다!\n";
}

void Character::DisplayStatus() const {
    std::cout<<"이름 : "<<name<<"\n";
    std::cout<<"체력 : ["<<hp<<"/"<<maxHp<<"]\n";
    std::cout<<"마나 : ["<<mp<<"/"<<maxMp<<"]\n";
    std::cout<<"공격력 : "<<attackPower<<"\n";
}

Warrior::Warrior(std::string name): Character(name,150,50,20){
    defense = 15;
}

void Warrior::Attack() const {
    std::cout<<"강력한 검 공격!\n";
}

void Warrior::UseSkill() const {
    std::cout<<"방패 막기! (방어력 2배)\n";
}

Mage::Mage(std::string name): Character(name,80,150,10){
    magicpower = 30;
}

void Mage::Attack() const {
    std::cout<<"마법 공격!\n";
}

void Mage::UseSkill() const {
    std::cout<<"파이어볼!\n";
}

Archer::Archer(std::string name): Character(name,100,80,15){
    criticalChance = 30;
}

void Archer::Attack() const {
    std::cout<<"화살 공격!\n";
}

void Archer::UseSkill() const {
    std::cout<<"연속 사격!\n";
}