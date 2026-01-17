#include <iostream>
#include "Item.h"
#include "Character.h"
Item::Item(std::string name, std::string description, ItemType type, int value, int weight): name{name}, description{description},type{type}, value{value}, weight{weight}{}

void Item::Display() const {
    std::cout << type << " " << name << " (" << value << " Gold)\n";
    std::cout << weight << "kg\n";
    std::cout << "   " << description << "\n";
}

Weapon::Weapon(std::string name, std::string description, int value, int weight, int atkBonus): Item(name,description,ItemType::WEAPON,value,weight), atkBonus{atkBonus} {}

void Weapon::Use(Character &target) {
    std::cout << "⚔️  " << name << " 장착! (ATK +" << atkBonus << ")\n";
    target.AddAtk(atkBonus);
}

Armor::Armor(std::string name, std::string description, int value, int weight, int defBonus): Item(name,description,ItemType::ARMOR,value,weight), defBonus{defBonus} {}

void Armor::Use(Character &target) {
    std::cout << "🛡️  " << name << " 장착! (DEF +" << defBonus << ")\n";
    target.AddDef(defBonus);
}

Potion::Potion(std::string name, std::string description, int value, int weight, int hp, int mp): Item(name,description,ItemType::POTION,value,weight), healAmount{hp}, mpAmount{mp} {}

void Potion::Use(Character &target) {
    std::cout << "🧪 " << name << " 사용! (HP +" << healAmount 
              << ", MP +" << mpAmount << ")\n";
    target.HealHp(healAmount);
    target.HealMp(mpAmount);
}