#include <iostream>
#include <memory>
#include <string>  // 추가!
#ifdef _WIN32
#include <windows.h>
#endif
#include "Warrior.h"
#include "Magician.h"
#include "Item.h"
#include "Inventory.h"

int main() {
    // 한글 출력 설정 (Windows만)
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif
    
    std::cout << "===== 인벤토리 시스템 테스트 =====\n\n";
    
    Warrior hero("용사", 1);
    
    // 1. 아이템 추가 테스트
    std::cout << "1. 아이템 추가\n";
    hero.GetInventory().AddItem(std::make_unique<Weapon>("검", "기본 검", 50, 3, 10));
    hero.GetInventory().AddItem(std::make_unique<Armor>("갑옷", "기본 갑옷", 80, 5, 15));
    hero.GetInventory().AddItem(std::make_unique<Potion>("물약", "HP 회복", 20, 1, 50, 0));
    hero.GetInventory().AddItem(std::make_unique<Potion>("마나 물약", "MP 회복", 30, 1, 0, 30));
    hero.GetInventory().AddItem(std::make_unique<Weapon>("도끼", "강력한 도끼", 100, 7, 25));
    hero.GetInventory().AddItem(std::make_unique<Potion>("고급 물약", "완전 회복", 100, 2, 100, 50));
    
    // 2. 인벤토리 출력
    std::cout << "\n";
    hero.GetInventory().DisplayInventory();
    
    // 3. 캐릭터 상태 확인
    std::cout << "\n2. 현재 캐릭터 상태\n";
    hero.DisplayStatus();
    
    // 4. 아이템 사용 테스트
    std::cout << "\n3. 아이템 사용 테스트\n";
    std::cout << "--- 데미지 입히기 ---\n";
    hero.TakeDamage(50);
    hero.DisplayStatus();
    
    std::cout << "\n--- 물약 사용 (인덱스 2) ---\n";
    hero.GetInventory().UseItem(2, hero);  // 물약 사용
    hero.DisplayStatus();
    
    std::cout << "\n--- 인벤토리 확인 (물약 소모됨) ---\n";
    hero.GetInventory().DisplayInventory();
    
    // 5. 무기 장착 테스트
    std::cout << "\n4. 무기 장착 테스트\n";
    std::cout << "--- 검 장착 (인덱스 0) ---\n";
    hero.GetInventory().UseItem(0, hero);  // 검 장착
    hero.DisplayStatus();
    
    // 6. 정렬 테스트
    std::cout << "\n5. 정렬 테스트\n";
    std::cout << "--- 타입별 정렬 ---\n";
    hero.GetInventory().SortByType();
    hero.GetInventory().DisplayInventory();
    
    std::cout << "\n--- 가격순 정렬 ---\n";
    hero.GetInventory().SortByValue();
    hero.GetInventory().DisplayInventory();
    
    // 7. 특정 타입 검색
    std::cout << "\n6. 무기 아이템만 조회\n";
    std::vector<int> weaponIndices = hero.GetInventory().FindItemsByType(ItemType::WEAPON);
    if (weaponIndices.empty()) {
        std::cout << "무기 아이템이 없습니다.\n";
    } else {
        std::cout << "무기 아이템 목록:\n";
        for (int idx : weaponIndices) {
            std::cout << "  - 인덱스 [" << idx << "]: " 
                     << hero.GetInventory().GetItem(idx)->GetName() << "\n";
        }
    }
    
    // 8. 포션만 검색
    std::cout << "\n7. 포션 아이템만 조회\n";
    std::vector<int> potionIndices = hero.GetInventory().FindItemsByType(ItemType::POTION);
    if (potionIndices.empty()) {
        std::cout << "포션 아이템이 없습니다.\n";
    } else {
        std::cout << "포션 아이템 목록:\n";
        for (int idx : potionIndices) {
            std::cout << "  - 인덱스 [" << idx << "]: " 
                     << hero.GetInventory().GetItem(idx)->GetName() << "\n";
        }
    }
    
    // 9. 인벤토리 가득 채우기 테스트
    std::cout << "\n8. 인벤토리 제한 테스트\n";
    std::cout << "현재 슬롯: " << hero.GetInventory().GetItemCount() << "/20\n";
    
    // 많은 아이템 추가 시도
    for (int i = 0; i < 20; ++i) {
        std::string itemName = "물약" + std::to_string(i);  // 수정!
        bool added = hero.GetInventory().AddItem(
            std::make_unique<Potion>(itemName, "테스트 물약", 10, 1, 10, 10)
        );
        if (!added) {
            std::cout << "더 이상 추가할 수 없습니다!\n";
            break;
        }
    }
    
    hero.GetInventory().DisplayInventory();
    
    // 10. 무게 제한 테스트
    std::cout << "\n9. 무게 제한 테스트\n";
    std::cout << "현재 무게: " << hero.GetInventory().GetCurrentWeight() << "/100kg\n";
    std::cout << "--- 무거운 아이템 추가 시도 ---\n";
    hero.GetInventory().AddItem(std::make_unique<Armor>("초중갑옷", "엄청 무거움", 500, 150, 100));
    
    // 11. 아이템 제거 테스트
    std::cout << "\n10. 아이템 제거 테스트\n";
    std::unique_ptr<Item> removed = hero.GetInventory().RemoveItem(0);
    if (removed) {
        std::cout << "제거된 아이템: " << removed->GetName() << "\n";
    }
    hero.GetInventory().DisplayInventory();
    
    std::cout << "\n===== 테스트 완료 =====\n";
    
    return 0;
}