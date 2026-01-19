#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Inventory.h"

Inventory::Inventory(int maxSlots, int maxWeight) 
    : maxSlots{maxSlots}, maxWeight{maxWeight}, currentWeight{0} {
    items.reserve(maxSlots);
}

bool Inventory::AddItem(std::unique_ptr<Item> item){
    if(items.size()>=maxSlots){
        std::cout<<"아이템이 가득 찼습니다!\n";
        return false;
    }
    if(currentWeight>=maxWeight){
        std::cout<<"중량이 초과되었습니다!"<<currentWeight-maxWeight<<"kg";
        return false;
    }
    currentWeight += item->GetWeight();
    std::cout << "✅ [" << item->GetName() << "]을(를) 인벤토리에 추가했습니다.\n";
    items.push_back(std::move(item));
    return true;
}

std::unique_ptr<Item> Inventory::RemoveItem(int index){
    if(index<0 || index>=items.size()) {
        std::cout<<"잘못된 접근입니다\n";
        return nullptr;
    }
    currentWeight -= items[index]->GetWeight();
    std::unique_ptr<Item> removedItem = std::move(items[index]);
    items.erase(items.begin()+index);
    std::cout << "📤 [" << removedItem->GetName() << "]을(를) 인벤토리에서 제거했습니다.\n";
    return removedItem;
}

void Inventory::UseItem(int index, Character &target){
    if (index < 0 || index >= items.size()) {
        std::cout << "❌ 잘못된 인덱스입니다!\n";
        return;
    }

    Item* item = items[index].get();

    if(item->GetItemType()==ItemType::POTION){
        item->Use(target);
        RemoveItem(index);
    } else {
        item->Use(target);
    }
}

void Inventory::DisplayInventory() const {
    std::cout << "\n╔════════════════════════════════════════════╗\n";
    std::cout << "║            📦 인벤토리                      ║\n";
    std::cout << "╠════════════════════════════════════════════╣\n";
    std::cout << "║ 슬롯: " << items.size() << "/" << maxSlots 
              << " | 무게: " << currentWeight << "/" << maxWeight << "kg      ║\n";
    std::cout << "╠════════════════════════════════════════════╣\n";
    
    if (items.empty()) {
        std::cout << "║  (비어있음)                                 ║\n";
    } else {
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << "║ [" << i << "] ";
            
            // 아이템 타입 아이콘
            switch(items[i]->GetItemType()) {
                case ItemType::WEAPON: std::cout << "⚔️ "; break;
                case ItemType::ARMOR:  std::cout << "🛡️ "; break;
                case ItemType::POTION: std::cout << "🧪 "; break;
                case ItemType::QUEST:  std::cout << "📜 "; break;
            }
            
            std::cout << items[i]->GetName() 
                      << " (" << items[i]->GetWeight() << "kg, "
                      << items[i]->GetValue() << "G)";
            
            // 특수 능력치 표시
            if (auto* weapon = dynamic_cast<Weapon*>(items[i].get())) {
                std::cout << " [ATK+" << weapon->GetAtkBonus() << "]";
            } else if (auto* armor = dynamic_cast<Armor*>(items[i].get())) {
                std::cout << " [DEF+" << armor->GetDefBonus() << "]";
            } else if (auto* potion = dynamic_cast<Potion*>(items[i].get())) {
                std::cout << " [HP+" << potion->GetHealAmount() 
                          << " MP+" << potion->GetMpAmount() << "]";
            }
            std::cout << "\n";
        }
    }
    
    std::cout << "╚════════════════════════════════════════════╝\n";
}

Item* Inventory::GetItem(int index) const {
    if(index>=0 && index<items.size()){
        return items[index].get();
    }
    return nullptr;
}

bool Inventory::IsFull() const {
    return items.size()>=maxSlots;
}

bool Inventory::IsOverWeight(int addWeight) const {
    return currentWeight + addWeight > maxWeight;
}

void Inventory::SortByType() {
    std::sort(items.begin(), items.end(), 
    [](const std::unique_ptr<Item> &item1,const std::unique_ptr<Item> &item2){return item1->GetItemType() > item2->GetItemType();});
    std::cout << "✅ 타입별로 정렬했습니다.\n";
}

void Inventory::SortByValue(){
    std::sort(items.begin(), items.end(), 
    [](const std::unique_ptr<Item> &item1,const std::unique_ptr<Item> &item2){return item1->GetValue() > item2->GetValue();});
    std::cout << "✅ 타입별로 정렬했습니다.\n";
}

std::vector<int> Inventory::FindItemsByType(ItemType type) const {
    std::vector<int> indices;
    for(size_t i = 0; i<items.size(); i++){
        if(items[i]->GetItemType()==type){
            indices.push_back(i);
        }
    }
    return indices;
}