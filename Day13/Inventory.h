#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include <iostream>
#include "Item.h"

class Inventory {
    private :
        std::vector<std::unique_ptr<Item>> items;
        int maxSlots;
        int maxWeight;
        int currentWeight;

    public :
        Inventory(int maxSlots = 20, int maxWeight = 100);
        bool AddItem(std::unique_ptr<Item> item);
        std::unique_ptr<Item> RemoveItem(int index);
        void UseItem(int index, Character& target);
        void DisplayInventory() const;
        Item* GetItem(int index) const;
        int GetItemCount() const {return items.size();};
        int GetCurrentWeight() const {return currentWeight;};
        bool IsFull() const;
        bool IsOverWeight(int addWeight) const;
        void SortByType();
        void SortByValue();

        std::vector<int> FindItemsByType(ItemType type) const;
    };      
#endif