#include <iostream>
#include "Warrior.h"

int Warrior::rageDuration = 0;

Warrior::Warrior(std::string name, int level):Character(name,level), rage{0}{
    maxHp += 50;
    hp = maxHp;
    maxMp -= 20;
    mp = maxMp;
    atk += 2;
    def += 5;
}

void Warrior::UseSkill(Character &target) {
    if(CheckToBehave()){
        if(GetAlive()){
            if(GetMp()>=15){
            mp-=15;
            std::cout<<"강타를 사용했다!\n"; 
            int damage = GetAtk()*3-target.GetDef(); 
            if(damage<0) damage = 0; 
            target.TakeDamage(damage);
            } else {
                std::cout<<"마나가 부족합니다\n";
            }
        } else {
            std::cout<<"사망상태라 스킬을 사용할 수 없습니다\n";
        }
    } else {
        std::cout<<"행동 불능 상태입니다!\n";
    }
}

void Warrior::Attack(Character &target){
    if(CheckToBehave()){
        if(GetAlive()){
            std::cout<<GetName()<<"이 "<<target.GetName()<<"을 공격했다!\n";
            int damage;
            if(rageDuration>0){
                damage = GetAtk()*2 - target.GetDef();
            } else {
                damage = GetAtk() - target.GetDef();
            }
            if(damage<0) damage = 0;
            target.TakeDamage(damage);
            if(rageDuration==0) rage++;
            if(rage>3) rage = 3;
            rageDuration--;
        } else {
            std::cout<<"사망상태라 공격할 수 없습니다\n";
        }
    } else {
        std::cout<<"행동 불능 상태입니다!\n";
    }
}

void Warrior::RageBuff(){
    if(CheckToBehave()){
        if(rage==0) {
            std::cout<<"분노가 부족합니다!\n";
        } else {
            rageDuration = rage;
            rage = 0;
            std::cout<<"분노 버프 사용!"<<rageDuration<<"번의 공격이 강화됩니다!\n";
        }
    } else {
        std::cout<<"행동 불능 상태입니다!\n";
    }
}
void Warrior::CalStat(int level){
    maxHp = 150 + (level - 1) * 30;
    hp = maxHp;
    maxMp = 30 + (level - 1) * 5;
    mp = maxMp;
    atk = 12 + (level - 1) * 3;
    def = 10 + (level - 1) * 5;
}