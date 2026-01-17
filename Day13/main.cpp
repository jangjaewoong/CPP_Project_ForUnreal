#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include "Warrior.h"
#include "Magician.h"
#include "Item.h"

using namespace std;

int main() {
    // 한글 출력 설정 (Windows만)
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif
    
    cout << "===== Item 기능 테스트 =====\n\n";
    
    // 1. 캐릭터 생성
    cout << "1. 캐릭터 생성\n";
    Warrior warrior("전사", 5);
    Magician mage("마법사", 5);
    
    // 2. 아이템 생성
    cout << "\n2. 아이템 생성\n";
    Weapon sword("강철 검", "튼튼한 강철로 만든 검", 100, 5, 20);
    Armor armor("철 갑옷", "무거운 철 갑옷", 80, 10, 15);
    Potion potion("고급 물약", "체력과 마나를 회복", 50, 1, 30, 20);
    
    // 3. Display 함수 테스트
    cout << "\n3. Display 함수 테스트\n";
    sword.Display();
    cout << endl;
    armor.Display();
    cout << endl;
    potion.Display();
    
    // 4. Getter 함수 테스트
    cout << "\n4. Getter 함수 테스트\n";
    cout << "검 이름: " << sword.GetName() << endl;
    cout << "검 설명: " << sword.GetDescription() << endl;
    cout << "검 가격: " << sword.GetValue() << " Gold" << endl;
    cout << "검 무게: " << sword.GetWeight() << " kg" << endl;
    cout << "검 공격력 보너스: " << sword.GetAtkBonus() << endl;
    
    cout << "\n갑옷 방어력 보너스: " << armor.GetDefBonus() << endl;
    cout << "물약 HP 회복량: " << potion.GetHealAmount() << endl;
    cout << "물약 MP 회복량: " << potion.GetMpAmount() << endl;
    
    // 5. 무기 장착 테스트
    cout << "\n5. 무기 장착 테스트\n";
    cout << "--- 장착 전 ---\n";
    warrior.DisplayStatus();
    
    cout << "\n--- 무기 장착 ---\n";
    sword.Use(warrior);
    warrior.DisplayStatus();
    
    // 6. 방어구 장착 테스트
    cout << "\n6. 방어구 장착 테스트\n";
    armor.Use(warrior);
    warrior.DisplayStatus();
    
    // 7. 전투 및 데미지
    cout << "\n7. 전투 테스트\n";
    warrior.Attack(mage);
    warrior.DisplayStatus();
    mage.DisplayStatus();
    
    // 8. 포션 사용 테스트
    cout << "\n8. 포션 사용 테스트\n";
    warrior.TakeDamage(50);
    cout << "\n데미지 입은 후:\n";
    warrior.DisplayStatus();
    
    cout << "\n물약 사용:\n";
    potion.Use(warrior);
    warrior.DisplayStatus();
    
    // 9. 장비 해제 테스트
    cout << "\n9. 장비 해제 테스트\n";
    warrior.TakeOffWeapon(sword);
    warrior.TakeOffArmor(armor);
    warrior.DisplayStatus();
    
    // 10. 여러 아이템 생성 및 사용
    cout << "\n10. 추가 아이템 테스트\n";
    Weapon axe("전투 도끼", "강력한 도끼", 150, 8, 30);
    Armor shield("방패", "튼튼한 나무 방패", 60, 5, 10);
    Potion megaPotion("메가 물약", "완전 회복", 100, 1, 100, 100);
    
    axe.Use(mage);
    shield.Use(mage);
    mage.DisplayStatus();
    
    mage.TakeDamage(80);
    megaPotion.Use(mage);
    mage.DisplayStatus();
    
    cout << "\n===== 테스트 완료 =====\n";
    
    return 0;
}