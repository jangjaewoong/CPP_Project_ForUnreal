#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>
#include "Inventory.h"

std::unique_ptr<Inventory> Inventory::inven_Instance = nullptr;

Inventory& Inventory::getInstance(){
    if (!inven_Instance) {
        inven_Instance.reset(new Inventory(100.0f)); 
        std::cout << "인벤토리 생성!\n";
    }
    return *inven_Instance;
}

void Inventory::AddItem(const Item& item){
    float current_Weight = GetTotalWeight();
    if(maxWeight<current_Weight+item.GetWeight()) {
        std::cout<<"가방이 가득 찼습니다!\n";
        return;
    }
    items.push_back(item);
    maxWeight += item.GetWeight();
    std::cout << "✅ " << item.GetName() << " 추가됨\n";
}

void Inventory::DisplayAll() const {
    if(items.size()==0) {
        std::cout<<"인벤토리가 비어있습니다!\n";
        return;
    }
    std::cout<<"----------인벤토리----------\n";
    for(Item item : items){
        item.Display();
    }
}

void Inventory::DisplayByCategory(std::string category) const {
    std::cout<<"----------"<<category<<"----------\n";
    for(Item item : items){
        if(item.GetCategory()==category){
            item.Display();
        }
    }
}

void Inventory::SortByValue() {
    std::sort(items.begin(), items.end(), 
    [](Item item1, Item item2){return item1.GetValue()>item2.GetValue();});
    std::cout<<"가치 기준으로 정렬 완료!\n";
}

void Inventory::SortByWeight() {
    std::sort(items.begin(), items.end(), 
    [](Item item1, Item item2){return item1.GetWeight()>item2.GetWeight();});
    std::cout<<"무게 기준으로 정렬 완료!\n";
}


void Inventory::SortByName() {
    std::sort(items.begin(), items.end(), 
    [](Item item1, Item item2){return item1.GetName()>item2.GetName();});
    std::cout<<"이름 기준으로 정렬 완료!\n";
}

void Inventory::RemoveByCategory(std::string category){
    auto remove = std::remove_if(items.begin(), items.end(), 
    [&category](Item item){ return item.GetCategory()==category;});
    items.erase(remove,items.end());
    std::cout<<category<<"에 해당하는 아이템 삭제 완료!\n";
}

void Inventory::RemoveByValue(int minValue){
    auto remove = std::remove_if(items.begin(), items.end(), 
    [&minValue](Item item){ return item.GetValue()<minValue;});
    items.erase(remove,items.end());
    std::cout<<minValue<<"보다 싼 아이템 삭제 완료!\n";
}

int Inventory::GetTotalValue() const {
    int Value_Sum = std::accumulate(items.begin(), items.end(), 0,
    [](int sum, Item item){return sum+item.GetValue();});
    return Value_Sum;
}
float Inventory::GetTotalWeight() const {
    float Weight_Sum =std::accumulate(items.begin(), items.end(), 0,
    [](int sum, Item item){return sum+item.GetWeight();});
    return Weight_Sum;
}

int Inventory::CountByCategory(std::string category) const{
    int count = std::count_if(items.begin(), items.end(),
    [&category](Item item){return item.GetCategory()==category;});
    return count;
}

Item* Inventory::FindMostValuable() {
    auto it = std::max_element(items.begin(), items.end(), 
    [](Item item1, Item item2){ return item1.GetValue()<item2.GetValue();});
    return &(*it);
}

Item* Inventory::FindLightest() {
    auto it = std::max_element(items.begin(), items.end(), 
    [](Item item1, Item item2){ return item1.GetWeight()>item2.GetWeight();});
    return &(*it);
}