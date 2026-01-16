#include <iostream>
#include <memory>
#include "Character.h"
#include "Warrior.h"
#include "Magician.h"
#include <windows.h>

void PrintTestHeader(const std::string& testName) {
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "테스트: " << testName << "\n";
    std::cout << std::string(50, '=') << "\n";
}

void TestWarrior() {
    PrintTestHeader("전사 클래스 테스트");
    
    Warrior warrior("테스트전사", 1);
    Warrior dummy("더미", 1);
    
    std::cout << "\n[1] 초기 상태 확인\n";
    warrior.DisplayStatus();
    
    std::cout << "\n[2] 일반 공격 테스트\n";
    warrior.Attack(dummy);
    
    std::cout << "\n[3] 스킬 사용 테스트 (강타)\n";
    warrior.UseSkill(dummy);
    
    std::cout << "\n[4] 분노 게이지 확인 (3번 공격)\n";
    warrior.Attack(dummy);
    warrior.Attack(dummy);
    
    std::cout << "\n[5] 분노 버프 사용 테스트\n";
    warrior.RageBuff();
    
    std::cout << "\n[6] 분노 버프 적용된 공격\n";
    warrior.Attack(dummy);
    warrior.Attack(dummy);
    
    std::cout << "\n[7] HP/MP 회복 테스트\n";
    warrior.HealHp(50);
    warrior.HealMp(20);
    
    std::cout << "\n[8] 골드 획득/사용 테스트\n";
    warrior.AddGold(100);
    warrior.SpendGold(50);
    
    std::cout << "\n[9] 경험치 획득 및 레벨업 테스트\n";
    warrior.GainExp(100);
    
    std::cout << "\n[10] 레벨업 후 스탯 확인\n";
    warrior.DisplayStatus();
    
    std::cout << "\n[11] 데미지 입고 사망 테스트\n";
    warrior.TakeDamage(500);
    
    std::cout << "\n[12] 사망 상태에서 행동 시도\n";
    warrior.Attack(dummy);
    warrior.UseSkill(dummy);
    
    std::cout << "\n[13] 부활 테스트\n";
    warrior.Revive();
    warrior.DisplayStatus();
}

void TestMagician() {
    PrintTestHeader("마법사 클래스 테스트");
    
    Magician magician("테스트마법사", 1);
    Magician dummy("더미마법사", 1);
    
    std::cout << "\n[1] 초기 상태 확인\n";
    magician.DisplayStatus();
    
    std::cout << "\n[2] 무속성 공격 테스트\n";
    magician.Attack(dummy);
    
    std::cout << "\n[3] 화염 속성 설정 및 공격\n";
    magician.SetElement("화염");
    magician.Attack(dummy);
    
    std::cout << "\n[4] 냉기 속성 설정 및 공격 (스턴)\n";
    magician.SetElement("냉기");
    magician.Attack(dummy);
    
    std::cout << "\n[5] 스턴 상태 확인 (행동 불가)\n";
    dummy.Attack(magician);
    
    std::cout << "\n[6] 스턴 해제 후 행동\n";
    dummy.Attack(magician);
    
    std::cout << "\n[7] 전기 속성 설정 및 공격 (방어 무시)\n";
    magician.SetElement("전기");
    magician.Attack(dummy);
    
    std::cout << "\n[8] 스킬 사용 테스트 (삼원소 파괴술식)\n";
    magician.UseSkill(dummy);
    
    std::cout << "\n[9] 마나 부족 상태 테스트\n";
    magician.Attack(dummy);
    magician.Attack(dummy);
    magician.Attack(dummy);
    magician.Attack(dummy);
    std::cout << "현재 MP: " << magician.GetMp() << "\n";
    magician.Attack(dummy);  // 마나 부족으로 무속성으로 변경
    
    std::cout << "\n[10] 레벨업 및 스탯 확인\n";
    magician.GainExp(200);
    magician.DisplayStatus();
}

void TestCombat() {
    PrintTestHeader("전투 시스템 테스트");
    
    Warrior warrior("전사", 3);
    Magician magician("마법사", 3);
    
    std::cout << "\n[1] 양측 초기 상태\n";
    warrior.DisplayStatus();
    magician.DisplayStatus();
    
    std::cout << "\n[2] 3턴 전투 시뮬레이션\n";
    for(int i = 1; i <= 3; i++) {
        std::cout << "\n--- 턴 " << i << " ---\n";
        std::cout << "전사의 공격:\n";
        warrior.Attack(magician);
        
        if(magician.GetAlive()) {
            std::cout << "\n마법사의 반격:\n";
            if(i == 1) {
                magician.SetElement("화염");
            }
            magician.Attack(warrior);
        }
    }
    
    std::cout << "\n[3] 전투 후 상태\n";
    warrior.DisplayStatus();
    magician.DisplayStatus();
}

void TestEdgeCases() {
    PrintTestHeader("예외 상황 테스트");
    
    Warrior warrior("테스트", 1);
    Warrior dummy("더미", 1);
    
    std::cout << "\n[1] 골드 부족 상태에서 구매 시도\n";
    warrior.SpendGold(200);
    
    std::cout << "\n[2] 마나 부족 상태에서 스킬 사용\n";
    warrior.UseSkill(dummy);
    warrior.UseSkill(dummy);
    warrior.UseSkill(dummy);
    warrior.UseSkill(dummy);
    
    std::cout << "\n[3] 분노 없이 분노 버프 사용\n";
    Warrior newWarrior("새전사", 1);
    newWarrior.RageBuff();
    
    std::cout << "\n[4] HP 최대치 초과 회복 시도\n";
    warrior.HealHp(1000);
    std::cout << "현재 HP: " << warrior.GetHp() << " / " << warrior.GetMaxHp() << "\n";
    
    std::cout << "\n[5] 음수 데미지 테스트 (방어력이 공격력보다 높을 때)\n";
    Warrior weakAttacker("약한공격자", 1);
    Warrior strongDefender("강한방어자", 10);
    weakAttacker.Attack(strongDefender);
    
    std::cout << "\n[6] 연속 레벨업 테스트\n";
    warrior.GainExp(500);
}

void TestGetters() {
    PrintTestHeader("Getter 함수 테스트");
    
    Warrior warrior("테스트전사", 5);
    
    std::cout << "\n[Getter 함수들 출력]\n";
    std::cout << "이름: " << warrior.GetName() << "\n";
    std::cout << "직업: " << warrior.GetClass() << "\n";
    std::cout << "레벨: " << warrior.GetLevel() << "\n";
    std::cout << "체력: " << warrior.GetHp() << " / " << warrior.GetMaxHp() << "\n";
    std::cout << "마나: " << warrior.GetMp() << " / " << warrior.GetMaxMp() << "\n";
    std::cout << "공격력: " << warrior.GetAtk() << "\n";
    std::cout << "방어력: " << warrior.GetDef() << "\n";
    std::cout << "골드: " << warrior.GetGold() << "\n";
    std::cout << "경험치: " << warrior.GetExp() << "\n";
    std::cout << "생존 여부: " << (warrior.GetAlive() ? "생존" : "사망") << "\n";
    std::cout << "스턴 여부: " << (warrior.GetStunned() ? "스턴" : "정상") << "\n";
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    std::cout << "╔═══════════════════════════════════════════════════╗\n";
    std::cout << "║     캐릭터 클래스 기능 테스트 프로그램            ║\n";
    std::cout << "╚═══════════════════════════════════════════════════╝\n";
    
    int choice;
    do {
        std::cout << "\n\n[ 테스트 메뉴 ]\n";
        std::cout << "1. 전사 클래스 전체 테스트\n";
        std::cout << "2. 마법사 클래스 전체 테스트\n";
        std::cout << "3. 전투 시스템 테스트\n";
        std::cout << "4. 예외 상황 테스트\n";
        std::cout << "5. Getter 함수 테스트\n";
        std::cout << "6. 모든 테스트 실행\n";
        std::cout << "0. 종료\n";
        std::cout << ">> 선택: ";
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                TestWarrior();
                break;
            case 2:
                TestMagician();
                break;
            case 3:
                TestCombat();
                break;
            case 4:
                TestEdgeCases();
                break;
            case 5:
                TestGetters();
                break;
            case 6:
                TestWarrior();
                TestMagician();
                TestCombat();
                TestEdgeCases();
                TestGetters();
                std::cout << "\n\n";
                std::cout << "╔═══════════════════════════════════════════════════╗\n";
                std::cout << "║           모든 테스트가 완료되었습니다!           ║\n";
                std::cout << "╚═══════════════════════════════════════════════════╝\n";
                break;
            case 0:
                std::cout << "프로그램을 종료합니다.\n";
                break;
            default:
                std::cout << "❌ 잘못된 선택입니다.\n";
        }
        
    } while(choice != 0);
    
    return 0;
}