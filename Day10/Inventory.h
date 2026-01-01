#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <memory>
#include "Item.h"
class Inventory {
    private :
        std::vector<std::shared_ptr<Item>> items;
        float maxWeight;
        float currentWeight;
        static std::unique_ptr<Inventory> instance;
        Inventory(float maxWeight);
    
    public :
        static Inventory& GetInstance(float maxWeight = 100.0f);
        void AddItem(std::shared_ptr<Item> item);
        void RemoveItem(std::string name);
        void UseItem(std::string name);
        void SortByWeight();
        
        void SortByValue();
        void DisplayItems() const;
        int GetTotalValue();
        float GetCurrentWeight() const { return currentWeight; }
        float GetMaxWeight() const { return maxWeight; }

};

#endif