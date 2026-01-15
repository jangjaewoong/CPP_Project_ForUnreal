#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>
#include "Item.h"

class Inventory {
    private :
        std::vector<Item> items;
        float maxWeight;
        static std::unique_ptr<Inventory> inven_Instance;
        Inventory(float maxWeight = 100.0f) : maxWeight(maxWeight) {}
    public :
        Inventory(const Inventory&) = delete;
        Inventory& operator=(const Inventory&) = delete;
        static Inventory& getInstance();
        void AddItem(const Item& item);
        void DisplayAll() const;
        void DisplayByCategory(std::string category) const;

        void SortByValue();
        void SortByWeight();
        void SortByName();

        void RemoveByCategory(std::string category);
        void RemoveByValue(int minValue);

        int GetTotalValue() const;
        float GetTotalWeight() const;
        int CountByCategory(std::string category) const;

        Item* FindMostValuable();
        Item* FindLightest();
};




#endif 