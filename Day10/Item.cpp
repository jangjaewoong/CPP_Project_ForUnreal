#include <iostream>
#include "Item.h"

Item::Item(std::string name, float weight, int value) 
    : name{name}, weight{weight}, value{value} {}

Item::~Item() {
    std::cout << "Item 소멸\n";
}

void Item::Display() const {
    std::cout << "- " << name 
              << " (무게: " << weight << "kg, 가치: " << value << "골드)";
}

Weapon::Weapon(std::string name, float weight, int value, int atk) : Item(name, weight, value), atk{atk}{}

Weapon::~Weapon(){
    std::cout<<"Weapon  소멸 \n";
}

void Weapon::Use() {
    std::cout<<name<<"을(를) 장착하였습니다!\n";
}
void Weapon::Display() const {
    Item::Display();
    std::cout << " [공격력: " << atk << "]\n";
}
void Weapon::Upgrade() {
    std::cout<<name<<"을(를) 강화하였습니다!\n";
    atk += 10;
}


Potion::Potion(std::string name, float weight, int value, int healAmount) : Item(name, weight, value), healAmount{healAmount}{}

Potion::~Potion(){
    std::cout<<"Potion 소멸 \n";
}

void Potion::Use() {
    std::cout << name << "을(를) 사용하여 " << healAmount << " 회복!\n";
}

void Potion::Display() const {
    Item::Display();
    std::cout << " [회복: " << healAmount << "]\n";
}

