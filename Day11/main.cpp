#include <iostream>
#include "Leaderboard.h"
#include <windows.h>  // 추가!
#include "AchievementSystem.h"

int main() {
    SetConsoleOutputCP(65001);  // UTF-8 출력
    SetConsoleCP(65001);        // UTF-8 입력
    system("chcp 65001 > nul"); // 콘솔 코드페이지 변경
    std::cout << "========================================\n";
    std::cout << "    게임 리더보드 & 업적 시스템\n";
    std::cout << "========================================\n\n";
    
    // ===== 리더보드 시스템 =====
    std::cout << "=== 리더보드 시작 ===\n";
    Leaderboard& board = Leaderboard::LeaderBoard_GetInstance();
    
    std::cout << "\n=== 플레이어 추가 ===\n";
    board.AddPlayer("Alice");
    board.AddPlayer("Bob");
    board.AddPlayer("Charlie");
    board.AddPlayer("David");
    board.AddPlayer("Eve");
    
    std::cout << "\n=== 점수 업데이트 ===\n";
    board.UpdateScore("Alice", 100);
    board.UpdateScore("Bob", 150);
    board.UpdateScore("Charlie", 80);
    board.UpdateScore("David", 120);
    board.UpdateScore("Eve", 90);
    
    std::cout << "\n=== 전체 플레이어 목록 ===\n";
    board.DisplayAllPlayers();
    
    std::cout << "\n=== Top 3 리더보드 ===\n";
    board.DisplayTopN(3);
    
    std::cout << "\n=== 개별 순위 조회 ===\n";
    std::cout << "Alice 순위: " << board.GetPlayerRank("Alice") << "위\n";
    std::cout << "Bob 순위: " << board.GetPlayerRank("Bob") << "위\n";
    std::cout << "Charlie 순위: " << board.GetPlayerRank("Charlie") << "위\n";
    
    std::cout << "\n=== Alice 추가 점수 획득 ===\n";
    board.UpdateScore("Alice", 60);
    
    std::cout << "\n=== 업데이트 후 Top 3 ===\n";
    board.DisplayTopN(3);
    std::cout << "Alice 순위: " << board.GetPlayerRank("Alice") << "위\n";
    
    std::cout << "\n=== 플레이어 제거 테스트 ===\n";
    board.RemovePlayer("Eve");
    board.DisplayAllPlayers();
    
    // ===== 업적 시스템 =====
    std::cout << "\n========================================\n";
    std::cout << "=== 업적 시스템 시작 ===\n";
    AchievementSystem& achSystem = AchievementSystem::AchievementSystem_GetInstance();
    
    std::cout << "\n=== 업적 등록 ===\n";
    achSystem.AddAchievement("첫 승리");
    achSystem.AddAchievement("연속 10승");
    achSystem.AddAchievement("레벨 10 달성");
    achSystem.AddAchievement("완벽한 게임");
    achSystem.AddAchievement("전설의 시작");
    
    std::cout << "\n=== 전체 업적 목록 ===\n";
    achSystem.DisplayAllAchievements();
    
    std::cout << "\n=== 업적 해제 ===\n";
    achSystem.UnlockAchievement("Alice", "첫 승리");
    achSystem.UnlockAchievement("Alice", "레벨 10 달성");
    achSystem.UnlockAchievement("Alice", "전설의 시작");
    
    achSystem.UnlockAchievement("Bob", "첫 승리");
    achSystem.UnlockAchievement("Bob", "연속 10승");
    
    achSystem.UnlockAchievement("Charlie", "첫 승리");
    
    std::cout << "\n=== 중복 해제 시도 ===\n";
    achSystem.UnlockAchievement("Alice", "첫 승리");
    
    std::cout << "\n=== 존재하지 않는 업적 ===\n";
    achSystem.UnlockAchievement("Alice", "없는 업적");
    
    std::cout << "\n=== 플레이어별 업적 확인 ===\n";
    achSystem.DisplayAchievements("Alice");
    achSystem.DisplayAchievements("Bob");
    achSystem.DisplayAchievements("Charlie");
    achSystem.DisplayAchievements("David");
    
    std::cout << "\n=== 업적 보유 확인 ===\n";
    if(achSystem.HasAchievement("Alice", "전설의 시작")) {
        std::cout << "✅ Alice는 '전설의 시작' 업적을 보유하고 있습니다!\n";
    }
    
    if(!achSystem.HasAchievement("Bob", "전설의 시작")) {
        std::cout << "❌ Bob은 '전설의 시작' 업적이 없습니다.\n";
    }
    
    std::cout << "\n=== 업적 개수 비교 ===\n";
    auto aliceAchs = achSystem.GetPlayerAchievements("Alice");
    auto bobAchs = achSystem.GetPlayerAchievements("Bob");
    
    std::cout << "Alice 업적 개수: " << aliceAchs.size() << "개\n";
    std::cout << "Bob 업적 개수: " << bobAchs.size() << "개\n";
    
    if(aliceAchs.size() > bobAchs.size()) {
        std::cout << "🏆 Alice가 더 많은 업적을 보유하고 있습니다!\n";
    }
    
    std::cout << "\n========================================\n";
    std::cout << "    프로그램 종료\n";
    std::cout << "========================================\n";
    
    return 0;
}