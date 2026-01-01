#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Character {
    protected :
        std::string name;
        int hp, maxHp;
        int mp, maxMp;
        int attackPower;

    public :
        Character(std::string name, int hp, int mp, int atk);
        virtual ~Character();
        virtual void Attack() const = 0;
        virtual void UseSkill() const = 0;
        void TakeDamage(int damage);
        void DisplayStatus() const;
        
};

class Warrior : public Character {
    private :
        int defense;
    public :
        Warrior(std::string name);
        virtual void Attack() const override;
        virtual void UseSkill() const override;
};

class Mage : public Character {
    private :
        int magicpower;
    public :
        Mage(std::string name);
        virtual void Attack() const override;
        virtual void UseSkill() const override;
};

class Archer : public Character {
    private :
        int criticalChance;
    public :
        Archer(std::string name);
        virtual void Attack() const override;
        virtual void UseSkill() const override;
};
#endif