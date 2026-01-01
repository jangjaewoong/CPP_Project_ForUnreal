#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
    protected :
        std::string name;
        float weight;
        int value;
    
    public :
        Item(std::string name, float weight, int value);
        virtual ~Item();
        virtual void Use() = 0;
        virtual void Display() const;

        std::string GetName() const { return name; }  
        float GetWeight() const { return weight; }
        int GetValue() const { return value; }
};

class Weapon : public Item {
    private :
        int atk;
    
    public :
        Weapon(std::string name, float weight, int value, int atk);
        ~Weapon();
        void Use() override;
        void Display() const override;
        void Upgrade();
};

class Potion : public Item {
    private : 
        int healAmount;
    public :
        Potion(std::string name, float weight, int value, int healAmount);
        ~Potion();
        void Use() override;
        void Display() const override;
        
        int GetHealAmount() const { return healAmount; }
};
#endif