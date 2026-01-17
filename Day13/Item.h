#ifndef ITEM_H
#define ITEM_H

#include <iostream>
class Character;
enum class ItemType {
    WEAPON,
    ARMOR,
    POTION,
    QUEST
};

inline std::ostream& operator<<(std::ostream& os, const ItemType& type) {
    switch (type) {
        case ItemType::WEAPON: os << "WEAPON"; break;
        case ItemType::ARMOR:  os << "ARMOR";  break;
        case ItemType::POTION: os << "POTION"; break;
        case ItemType::QUEST:  os << "QUEST";  break;
        default:               os << "UNKNOWN"; break;
    }
    return os;
}
class Item {
    protected :
        std::string name;
        std::string description;
        ItemType type;
        int value;
        int weight;
    public :
        Item(std::string name, std::string description, ItemType type, int value, int weight);
        virtual  ~Item() = default;

        virtual void Use(Character &target) = 0;
        
        void Display() const;
        std::string GetName() const {return name;};
        std::string GetDescription() const {return description;};
        ItemType GetItemType() const {return type;};
        int GetValue() const {return value;};
        int GetWeight() const {return weight;};
        
};

class Weapon : public Item{
    private :
        int atkBonus;
    public :
        Weapon(std::string name, std::string description, int value, int weight, int atkBonus);
        void Use(Character &target) override;
        int GetAtkBonus() const {return atkBonus;};
};

class Armor : public Item{
    private :
        int defBonus;
    public :
        Armor(std::string name, std::string description, int value, int weight, int defBonus);
        void Use(Character &target) override;
        int GetDefBonus() const {return defBonus;};
};

class Potion : public Item {
private:
    int healAmount;
    int mpAmount;
    
public:
    Potion(std::string name, std::string description, int value, int weight, int hp, int mp);
    void Use(Character &target) override;
    int GetHealAmount() const { return healAmount; }
    int GetMpAmount() const { return mpAmount; }
};

#endif 