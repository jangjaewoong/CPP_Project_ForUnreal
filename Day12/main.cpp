#include <iostream>
#include <windows.h>
#include "Inventory.h"

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    std::cout << "========================================\n";
    std::cout << "    고급 인벤토리 시스템 (STL 알고리즘)\n";
    std::cout << "========================================\n\n";
    
    Inventory& inv = Inventory::getInstance();
    
    std::cout << "=== 아이템 추가 ===\n";
    inv.AddItem(Item("장검", 100, 5.0f, "Weapon"));
    inv.AddItem(Item("체력 포션", 50, 0.5f, "Potion"));
    inv.AddItem(Item("마나 포션", 50, 0.5f, "Potion"));
    inv.AddItem(Item("철갑옷", 200, 15.0f, "Armor"));
    inv.AddItem(Item("단검", 60, 2.0f, "Weapon"));
    inv.AddItem(Item("독 포션", 80, 0.3f, "Potion"));
    inv.AddItem(Item("가죽 갑옷", 120, 8.0f, "Armor"));
    inv.AddItem(Item("활", 90, 3.0f, "Weapon"));
    
    std::cout << "\n=== 전체 아이템 ===\n";
    inv.DisplayAll();
    
    std::cout << "\n=== 무기만 보기 ===\n";
    inv.DisplayByCategory("Weapon");
    
    std::cout << "\n=== 포션만 보기 ===\n";
    inv.DisplayByCategory("Potion");
    
    std::cout << "\n=== 통계 ===\n";
    std::cout << "💰 총 가치: " << inv.GetTotalValue() << "\n";
    std::cout << "⚖️  총 무게: " << inv.GetTotalWeight() << " / 100.0\n";
    std::cout << "🧪 포션 개수: " << inv.CountByCategory("Potion") << "개\n";
    std::cout << "⚔️  무기 개수: " << inv.CountByCategory("Weapon") << "개\n";
    std::cout << "🛡️  방어구 개수: " << inv.CountByCategory("Armor") << "개\n";
    
    std::cout << "\n=== 가치순 정렬 (높은 순) ===\n";
    inv.SortByValue();
    inv.DisplayAll();
    
    std::cout << "\n=== 무게순 정렬 (가벼운 순) ===\n";
    inv.SortByWeight();
    inv.DisplayAll();
    
    std::cout << "\n=== 이름순 정렬 ===\n";
    inv.SortByName();
    inv.DisplayAll();
    
    std::cout << "\n=== 최고 가치 아이템 찾기 ===\n";
    Item* valuable = inv.FindMostValuable();
    if(valuable) {
        std::cout << "🏆 가장 비싼 아이템:\n";
        valuable->Display();
    }
    
    std::cout << "\n=== 가장 가벼운 아이템 찾기 ===\n";
    Item* lightest = inv.FindLightest();
    if(lightest) {
        std::cout << "🪶 가장 가벼운 아이템:\n";
        lightest->Display();
    }
    
    std::cout << "\n=== 포션 카테고리 모두 제거 ===\n";
    inv.RemoveByCategory("Potion");
    inv.DisplayAll();
    
    std::cout << "\n=== 가치 100 미만 제거 ===\n";
    inv.RemoveByValue(100);
    inv.DisplayAll();
    
    std::cout << "\n=== 최종 통계 ===\n";
    std::cout << "💰 총 가치: " << inv.GetTotalValue() << "\n";
    std::cout << "⚖️  총 무게: " << inv.GetTotalWeight() << "\n";
    std::cout << "📦 아이템 수: " << inv.CountByCategory("Weapon") 
              + inv.CountByCategory("Armor") 
              + inv.CountByCategory("Potion") << "개\n";
    
    std::cout << "\n========================================\n";
    std::cout << "    프로그램 종료\n";
    std::cout << "========================================\n";
    
    return 0;
}