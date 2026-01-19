#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <memory>
#include "Item.h"
#include "Inventory.h"
class Character {
    protected :
        std::string name;
        int level;
        int hp, maxHp;
        int mp, maxMp;
        int atk;
        int def;
        int gold;
        int exp;
        bool alive;
        bool isStunned;
        Inventory inventory;
    public :
        Character(std::string name, int level);
        virtual ~Character() = default;
        virtual void UseSkill(Character &target) = 0;
        virtual std::string GetClass() const = 0;
        virtual void Attack(Character &target) = 0;
        virtual void CalStat(int level) = 0;

        void LevelUp();
        void TakeDamage(int damage);
        void HealHp(int amount);
        void HealMp(int amount);
        void GainExp(int amount);
        void AddGold(int amount);
        void SpendGold(int amount);
        
        void Revive();
        void DisplayStatus() const;
        bool CheckToBehave() ;
        void TakeOffWeapon(Weapon &weapon);
        void TakeOffArmor(Armor &armor);

        std::string GetName() const {return name;};
        int GetLevel() const {return level;};
        int GetHp() const {return hp;};
        int GetMaxHp() const { return maxHp;};
        int GetMp() const {return mp;};
        int GetMaxMp() const {return maxMp;};
        int GetAtk() const {return atk;};
        int GetDef() const {return def;};
        int GetGold() const {return gold;};
        int GetExp() const {return exp;};
        int GetAlive() const {return alive;};
        bool GetStunned() const {return isStunned;};
        void SetStunned(bool state) {isStunned = state;};
        void AddAtk(int amount) {atk += (amount<0)?0:amount;};
        void AddDef(int amount) {def += (amount<0)?0:amount;};
        Inventory& GetInventory() { return inventory; }
        const Inventory& GetInventory() const { return inventory; }
};      

#endif