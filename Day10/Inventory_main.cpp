#include <iostream>
#include <memory>
#include "Inventory.h"

int main() {
    std::cout << "=== 인벤토리 생성 ===\n";
    Inventory& inv = Inventory::GetInstance(50.0f);
    
    std::cout << "\n=== 아이템 생성 ===\n";
    auto sword = std::make_shared<Weapon>("철검", 5.0f, 100, 20);
    auto bow = std::make_shared<Weapon>("활", 3.0f, 80, 15);
    auto potion1 = std::make_shared<Potion>("체력 물약", 0.5f, 20, 50);
    auto potion2 = std::make_shared<Potion>("마나 물약", 0.5f, 30, 30);
    
    std::cout << "\n=== 아이템 추가 ===\n";
    inv.AddItem(sword);
    inv.AddItem(bow);
    inv.AddItem(potion1);
    inv.AddItem(potion2);
    
    std::cout << "\n=== 인벤토리 목록 ===\n";
    inv.DisplayItems();
    
    std::cout << "\n=== 가치순 정렬 ===\n";
    inv.SortByValue();
    inv.DisplayItems();
    
    std::cout << "\n=== 아이템 사용 ===\n";
    inv.UseItem("체력 물약");
    
    std::cout << "\n=== 사용 후 목록 ===\n";
    inv.DisplayItems();
    
    std::cout << "\n=== 총 가치 ===\n";
    std::cout << "총 가치: " << inv.GetTotalValue() << " 골드\n";
    std::cout << "현재 무게: " << inv.GetCurrentWeight() << "/" << inv.GetMaxWeight() << "\n";
    
    return 0;
}
