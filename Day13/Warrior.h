#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>
#include "Character.h"

class Warrior : public Character {
    private :
        int rage;
        static int rageDuration;
    public :
        Warrior(std::string name, int level);
        void UseSkill(Character &target) override;
        void RageBuff();
        std::string GetClass() const override {return "전사";};
        void Attack(Character &target) override;
        void CalStat(int level) override;
};


#endif