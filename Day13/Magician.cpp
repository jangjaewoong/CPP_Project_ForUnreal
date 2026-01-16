#include <iostream>
#include "Magician.h"

Magician::Magician(std::string name, int level) : Character(name, level){
    maxHp-= 30;
    hp = maxHp;
    maxMp += 90;
    mp = maxMp;
    atk += 8;
    def += 2;
}

void Magician::SetElement(std::string element){
    Element newElement;
    if(element=="전기"){
        newElement = Element::Light;
    } else if(element=="냉기"){
        newElement = Element::Ice;
    } else if (element=="화염"){
        newElement = Element::Fire;
    }
    curElement = newElement;
}
void Magician::UseSkill(Character &target){
    if(CheckToBehave()){
        if(GetAlive()){
            if(GetMp()>=50){
                mp-=50; 
                std::cout<<"삼원소 파괴술식을 시전했다\n";
                int damage = GetAtk()*4 - target.GetDef();
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

void Magician::Attack(Character &target){
    if(CheckToBehave()){
        if(mp<30) {
            std::cout<<"마나가 부족해 속성이 사라집니다!\n";
            curElement = Element::None;
        }
        switch (curElement){
            int damage;
            case Element::Fire:
                damage = GetAtk()*2-target.GetDef();
                std::cout<<"화염 속성으로 추가 피해를 입힙니다!\n";
                target.TakeDamage(damage);
                mp-=30;
                break;
            case Element::Ice:
                damage = GetAtk() - target.GetDef();
                std::cout<<target.GetName()<<"이 빙결 공격으로 한턴간 멈춥니다!\n";
                target.TakeDamage(damage);
                mp-=30;
                target.SetStunned(true);
                break;
            case Element::Light:
                damage = GetAtk() - target.GetDef()/2;
                std::cout<<"빛 속성이 방어력을 무시합니다!\n";
                target.TakeDamage(damage);
                mp-=30;
                break;
            default :
                damage = GetAtk() - target.GetDef();
                std::cout<<"무속성 공격!\n";
                target.TakeDamage(damage);
                break;
        }
    } else {
        std::cout<<"행동 불능 상태입니다a!\n";
    }
    
}

void Magician::CalStat(int level){
    maxHp = 70 + (level - 1) * 15;
    hp = maxHp;
    maxMp = 90 + (level - 1) * 25;
    mp = maxMp;
    atk = 18 + (level - 1) * 5;
    def = 7 + (level - 1) * 2;
}