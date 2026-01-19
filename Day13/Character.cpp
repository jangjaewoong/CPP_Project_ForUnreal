#include <iostream>
#include "Character.h"

Character::Character(std::string name, int level) : name{name}, level{level}, gold{100}, exp{0}, alive{true}, isStunned{false}, inventory(20,30) {
    maxHp = 100 + (level - 1) * 20;
    hp = maxHp;
    maxMp = 50 + (level - 1) * 10;
    mp = maxMp;
    atk = 10 + (level - 1) * 5;
    def = 5 + (level - 1) * 2;
    std::cout << "▶ 새로운 캐릭터 [" << name << "]이(가) 생성되었습니다.\n";
}

void Character::LevelUp(){
    level++;
    std::cout << "\n========================================" << std::endl;
    std::cout << "★ LEVEL UP! [" << level - 1 << "] -> [" << level << "] ★" << std::endl;
    std::cout << "========================================\n" << std::endl;
    CalStat(level);
}


void Character::HealHp(int amount){
    if(CheckToBehave()){
        if(alive){
            int prevHp = hp;
            hp += amount;
            if(maxHp<hp) hp = maxHp;
            std::cout << "♥ [체력 회복] " << prevHp << " -> " << hp << " (+" << amount << ")\n";
        } else {
            std::cout << "☠ " << name << "은(는) 사망 상태라 회복할 수 없습니다!\n";
        }
    } else {
        std::cout<<"행동 불능 상태입니다!\n";
    }
    
}

void Character::HealMp(int amount){
    if(CheckToBehave()){
        if(alive){
            int prevMp = mp;
            mp += amount;
            std::cout << "♣ [마나 회복] " << prevMp << " -> " << mp << " (+" << amount << ")\n";
        } else {
            std::cout << "☠ " << name << "은(는) 사망 상태라 마나를 회복할 수 없습니다!\n";
        }
    } else{
        std::cout<<"행동 불능 상태입니다!\n\n";
    }

}

void Character::TakeDamage(int damage){
    if(alive){
        hp -= damage;
        std::cout << "↔ [" << name << "]이(가) " << damage << "의 피해를 입었습니다! (남은 HP: " << (hp > 0 ? hp : 0) << ")\n";
        if(hp <= 0) {
            hp = 0;
            alive = false;
            std::cout << "☠ !!! [" << name << "]이(가) 쓰러졌습니다 !!!\n";
        }
    } else {
        std::cout<<"이미 죽었습니다! 공격을 그만두십시오\n";
    }
}

void Character::GainExp(int amount){
    std::cout << "◈ 경험치를 " << amount << " 얻었습니다.\n";
    exp+=amount;
    int expMax = level*100;
    while(exp>=expMax){
        LevelUp();
        exp-=expMax;
        expMax = level*100;
    }
}

void Character::AddGold(int amount){
    gold += amount;
    std::cout << "💰 골드를 " << amount << "G 획득했습니다. (현재: " << gold << "G)\n";
}

void Character::SpendGold(int amount){
    if(gold < amount) {
        std::cout << "❌ 골드가 부족합니다! (필요: " << amount << "G / 보유: " << gold << "G)\n";
        return;
    }
    gold -= amount;
    std::cout << "💸 골드를 " << amount << "G 사용했습니다. (남은 골드: " << gold << "G)\n";
}

void Character::Revive(){
    alive = true;
    hp = maxHp/2;
    mp = maxMp/2;
    std::cout << "😇 [" << name << "]이(가) 신의 가호로 부활했습니다! (HP 50%/MP 50% 회복)\n";
}

void Character::DisplayStatus() const{
    std::cout << "\n┌────────────────────────────────────────" << std::endl;
    std::cout << "│ [ " << GetClass() << " : " << name << " ]" << std::endl;
    std::cout << "├────────────────────────────────────────" << std::endl;
    
    std::cout << "│ 레벨: " << level;
    if (!alive) {
        std::cout << " (상태: 사망 ☠)";
    } else {
        std::cout << " (상태: 정상)";
    }
    std::cout << std::endl;

    std::cout << "│ 체력(HP): " << hp << " / " << maxHp << std::endl;
    std::cout << "│ 마나(MP): " << mp << " / " << maxMp << std::endl;

    std::cout << "│ 공격력: " << atk << " | 방어력: " << def << std::endl;

    int expMax = level * 100;
    double expPercent = (maxHp > 0) ? ((double)exp / expMax * 100.0) : 0.0;
    std::cout << "│ 경험치: " << exp << " / " << expMax << " [" << expPercent << "%]" << std::endl;
    std::cout << "│ 소지금: " << gold << " G" << std::endl;
    
    std::cout << "└────────────────────────────────────────" << std::endl;
}

bool Character::CheckToBehave() {
    if(isStunned){
        SetStunned(false);
        return false;
    }
    return true;
}

void Character::TakeOffWeapon(Weapon &weapon){
    int curAtk = atk;
    atk -= weapon.GetAtkBonus();
    std::cout<<weapon.GetName()<<"을(를) 장착 해제했습니다\n";
    std::cout<<"공격력 : "<<curAtk<<"=>"<<atk<<"\n";
}

void Character::TakeOffArmor(Armor &armor){
    int curDef = def;
    def -= armor.GetDefBonus();
    std::cout<<armor.GetName()<<"을(를) 장착 해제했습니다\n";
    std::cout<<"방어력 : "<<curDef<<"=>"<<def<<"\n";
}