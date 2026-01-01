#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Inventory.h"

std::unique_ptr<Inventory> Inventory::instance = nullptr;

Inventory& Inventory::GetInstance(float maxWeight) {
    if(!instance) {
        instance.reset(new Inventory(maxWeight));
        std::cout << "인벤토리 생성됨! (최대 무게: " << maxWeight << "kg)\n";
    }
    return *instance; 
}

Inventory::Inventory(float maxWeight): maxWeight{maxWeight}, currentWeight{0}{}

void Inventory::AddItem(std::shared_ptr<Item> item) {
    if(currentWeight + item->GetWeight() > maxWeight) {
        std::cout << "인벤토리가 가득 찼습니다! (" 
                  << item->GetWeight() << "kg 초과)\n";
        return;
    }
    
    items.push_back(item);
    currentWeight += item->GetWeight();
    std::cout << item->GetName() << "을(를) 획득! ("
              << currentWeight << "/" << maxWeight << "kg)\n";
}

void Inventory::RemoveItem(std::string name) {
    for(auto it = items.begin(); it != items.end(); ) {
        if((*it)->GetName() == name) {
            currentWeight -= (*it)->GetWeight();  // 무게 감소!
            std::cout << name << "을(를) 제거했습니다!\n";
            it = items.erase(it);  // erase는 다음 iterator 반환
            return;  // 찾았으면 종료
        } else {
            ++it;
        }
    }
    std::cout << name << "을(를) 찾을 수 없습니다!\n";
}

void Inventory::UseItem(std::string name) {
    for(auto it = items.begin(); it != items.end(); ) {
        if((*it)->GetName() == name) {
            (*it)->Use();
            currentWeight -= (*it)->GetWeight();
            std::cout << name << "을(를) 사용하고 제거했습니다!\n";
            it = items.erase(it);
            return;
        } else {
            ++it;
        }
    }
    std::cout << name << "을(를) 찾을 수 없습니다!\n";
}

void Inventory::DisplayItems() const {
    if(items.empty()) {
        std::cout << "인벤토리가 비어있습니다.\n";
        return;
    }
    
    std::cout << "=== 인벤토리 (" << items.size() << "개) ===\n";
    int index = 1;
    for(const auto& item : items) {
        std::cout << "[" << index++ << "] ";
        item->Display();
    }
}

int Inventory::GetTotalValue() {
    int totalValue = 0;
    for(auto it = items.begin(); it!=items.end(); it++){
        totalValue += (*it)->GetValue();  
    }
    return totalValue;
}

void Inventory::SortByValue() {
    std::sort(items.begin(), items.end(), 
        [](const std::shared_ptr<Item>& a, const std::shared_ptr<Item>& b) {
            return a->GetValue() > b->GetValue();  // 내림차순
        });
    std::cout << "가치순으로 정렬했습니다!\n";
}

void Inventory::SortByWeight() {
    std::sort(items.begin(), items.end(),
        [](const std::shared_ptr<Item>& a, const std::shared_ptr<Item>& b) {
            return a->GetWeight() < b->GetWeight();  // 오름차순
        });
    std::cout << "무게순으로 정렬했습니다!\n";
}

