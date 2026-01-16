#ifndef MAGICIAN_H
#define MAGICIAN_H

#include <iostream>
#include "Character.h"

enum class Element {
    None,
    Fire,
    Ice,
    Light
};

class Magician : public Character {
    private :
        Element curElement = Element::None;

    public :
        Magician(std::string name, int level);
        void SetElement(std::string element);
        void UseSkill(Character &target) override;
        std::string GetClass() const override {return "마법사";};
        void Attack(Character &target) override;
        void CalStat(int level) override;
};

#endif